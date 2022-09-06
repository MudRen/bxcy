// actionavailable.c

#include <ansi.h>
#include <weapon.h>
#include <login.h>
inherit F_CLEAN_UP;

int room_path(object, object);
int user_path(object, object);

int main(object me, string arg)
{
	object ob, *inv;
	string win,*ids;

        if (sscanf(arg, "%s,%s", arg, win) != 2) 
                return 0;
                
	switch (win)
	{
		case "0" :
			ob=present(arg,environment(me));
			if(!objectp(ob)) {
				inv=all_inventory(environment(me));
				for(int i = 0; i<sizeof(inv); i++) {
					if(inv[i]==me) continue;
					if(ids=inv[i]->query_temp("apply/id"))
					for(int j=0;j<sizeof(ids);j++) {
						if(ids[j]==arg)
						ob=inv[i];
					}
				}
			}
			room_path(me,ob);
			break;
		case "1" :
			ob=present(arg,me);
			user_path(me,ob);
			break;
	}
	return 1;
}

int room_path(object me, object ob)
{
	mapping skills,meskills;
	object *inv;
	string *str,id,*ids,name,tmp;
	int i,my_skill;

	if(!objectp(ob)) return 1;
	
	if(stringp(tmp=ob->query_menu(me,0)))//��������ܽ��Ͳ˵�����ֱ�ӷ��ز˵�
	{
		write(tmp);
		return 1;
	}
	

	if(!ob->query("apply/id")) id=ob->query("id");
	else {
		ids=ob->query_temp("apply/id");
		id=ids[sizeof(ids)-1];
	}

//	if(ob->query_temp("apply/name")) name=ob->query_temp("apply/name");
	tmp=TMI("mbegin "+ob->name(1)+";"+id)+TMI("mitem �۲�$U;look "+id);
	if(living(ob))
	{
		if(interactive(ob))
		{
			tmp+=TMI("mitem ����$U...;tell "+id+" ...")+TMI("mitem ��$U����...;whisper "+id+" ...");
			if(id==me->query_temp("reply"))
				write(TMI("mitem �ش�$U...;reply ..."));
		}

		tmp+=(me->query_leader()==ob)?TMI("mitem ֹͣ����$U;follow none"):TMI("mitem ����$U;follow "+id);
		if(!environment(me)->query("no_fight"))
		{
			tmp+=TMI("mitem ��$U�д�;fight "+id);
			if ((int)ob->query("age") > 17 || !interactive(ob))
				tmp+=TMI("mitem ����$U;hit "+id)+TMI("mitem ɱ��$U;kill "+id)+TMI("mitem ͵Ϯ$U;touxi "+id)+TMI("mitem ͵$U��...;steal ... from "+id);
		}
		if(ob->query("inquiry")) {
			str=keys(ob->query("inquiry"));
			for(i=0; i<sizeof(str); i++)
				tmp+=TMI("mitem ��$U��������"+str[i]+"����Ϣ;ask "+id+" about "+str[i]+"");
		}
		tmp+=TMI("mitem ��$U...����;give ... to "+id );
		if(me->query("family/family_name") == "ؤ��" ) {
			if ( me->query_skill("checking",1) >= 10 )
				tmp+=TMI("mitem ��̽...�ļ���;check ...");
			if(ob->query("family/family_name") != "ؤ��" )
				tmp+=TMI("mitem ����$U��...;beg ... from "+id);
		}
		if(ob->query("vendor_goods")) {
			tmp+=TMI("mitem ��ѯ$U���۵Ķ���;list");
			tmp+=TMI("mitem ��$U��...;buy ...");
		}
		if(ob->query("dealer")=="pawn") {
			if(!ob->query("vendor_goods")) {
				tmp+=TMI("mitem ��ѯ$U���۵Ķ���;list");
				tmp+=TMI("mitem ��$U��...;buy ...");
			}
			tmp+=TMI("mitem ����...;value ...");
			tmp+=TMI("mitem ��...��$U;sell ...");
			tmp+=TMI("mitem �䵱...��$U;pawn ...");
			if(me->query("pawns"))
				tmp+=TMI("mitem �����Ʒ...;redeem ...");
		}
		if(ob->query("dealer")=="bank") {
			tmp+=TMI("mitem �һ�����;convert ...");
			tmp+=TMI("mitem ��Ǯ;deposit ...");
			if(me->query("money")) {
				tmp+=TMI("mitem ��ѯ���;check");
				tmp+=TMI("mitem ȡǮ;withdraw ...");
			}
		}
		if(me->query("family/master_name")!=ob->name(1)) {
			if(ob->is_master())
				tmp+=TMI("mitem ��$UΪʦ;bai "+id);
		} else {
			tmp+=TMI("mitem ��ʦ��$U��ͷ;bai "+id);
			tmp+=TMI("mitem ��ѯʦ��$U����;skills "+id);
			if(ob->query_skills() && me->query("jing")>=1
				&& (int)me->query("potential")>(int)me->query("learned_points")) {
				skills=ob->query_skills();
				str=keys(skills);
				for(i=0; i<sizeof(str); i++) {
					if(me->query_skills()) {
						meskills=me->query_skills();
						my_skill = me->query_skill(str[i], 1);
						if( (string)SKILL_D(str[i])->type()=="martial"
							&& my_skill*my_skill*my_skill/10>(int)me->query("combat_exp") )
							continue;
						if(skills[str[i]]>my_skill && str[i]!="idle")
							tmp+=TMI("mitem ѧϰ"+to_chinese(str[i])+";learn "+id+" "+str[i]+" ...");
					} else
					tmp+=TMI("mitem ѧϰ"+to_chinese(str[i])+";learn "+id+" "+str[i]+" ...");
				}
			}
		}
	} else {
		if(!ob->query("no_get"))
			tmp+=TMI("mitem ��$U������;get "+id);
		if(ob->is_container()) {
			inv = all_inventory(ob);
			if(sizeof(inv)) {
				tmp+=TMI("mitem ��$U��Ķ������ó���;get all from "+id);
				tmp+=TMI("mitem ��$U���ó�...;get ... from "+id);
			}
			tmp+=TMI("mitem ��...װ��$U��;put ... in "+id);
		}
		if(id=="board") {
			tmp+=TMI("mitem ���µ�����;read new");
			tmp+=TMI("mitem ����...������;read ...");
			tmp+=TMI("mitem д�µ�����;post ...");
			tmp+=TMI("mitem ɾ������...;discard ...");
		}
	}
	tmp+=TMI("mendd");
	tell_object(me,tmp);
	return 1;
}

int user_path(object me, object ob)
{
	mapping prop;
	string id,tmp;

	if(!objectp(ob)) return 1;
	
	if(stringp(tmp=ob->query_menu(me,1)))//��������ܽ��Ͳ˵�����ֱ�ӷ��ز˵�
	{
		write(tmp);
		return 1;
	}
	
	id=ob->query("id");
	tmp=TMI("mbegin "+ob->name(1)+";"+id)+TMI("mitem �۲�$U;look "+id);

	if(!ob->query("no_drop"))
		tmp+=TMI("mitem ����$U;drop "+id);

	if(!ob->query("no_give"))
		tmp+=TMI("mitem ��$U��...;give "+id+" to ...");

	if(ob->query("liquid")) {
		if(ob->query("liquid/remaining"))
			tmp+=TMI("mitem ��$U;drink "+id);
		if(environment(me)->query("resource/water"))
			tmp+=TMI("mitem ��$Uװ��ˮ;fill "+id);
	}
	
	if(ob->query("food_remaining"))
		tmp+=TMI("mitem ��$U;eat "+id);
		
	if(ob->is_container()) {
		tmp+=TMI("mitem ��$U��Ķ������ó���;get all from "+id);
		tmp+=TMI("mitem ��$U���ó�...;get ... from "+id);
		tmp+=TMI("mitem ��...װ��$U��;put ... in "+id);
	}
	if(mapp(prop=ob->query("armor_prop"))&& stringp(ob->query("armor_type")) ) {
		if(!ob->query("equipped"))
			tmp+=TMI("mitem ����$U;wear "+id);
		else
			tmp+=TMI("mitem ����$U;remove "+id);
	}

	if(mapp(prop=ob->query("weapon_prop")) && stringp(ob->query("skill_type"))) {
		if(!ob->query("equipped"))
			tmp+=TMI("mitem װ��$U;wield "+id);
		else
			tmp+=TMI("mitem ���װ��$U;unwield "+id);
	}

	if(ob->query("skill"))
		tmp+=TMI("mitem ��$U;study "+id);
	tmp+=TMI("mendd");
	tell_object(me,tmp);
	return 1;
}

