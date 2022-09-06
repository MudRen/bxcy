// actionavailable.c
//FIX AKAI 2006
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
	string *str,id,*ids,tmp;
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
			tmp+=TMI("mitem ��$U��...;buy (��ƷID)...");
		}
		/////AKAI�����������̵�LIST������жϷ����������Ʒ����˵��Ϳ��Է�������ɣ���
		if(ob->query("dealer")=="pawn") {
			if(!ob->query("vendor_goods")) {
				tmp+=TMI("mitem ��ѯ$U���۵Ķ���;list");
				tmp+=TMI("mitem ��$U��...;buy (��ƷID)...");
			}
			tmp+=TMI("mitem ����...;value ...");
			tmp+=TMI("mitem ��...��$U;sell ...");
			tmp+=TMI("mitem �䵱...��$U;pawn ...");
			if(me->query("pawns"))
				tmp+=TMI("mitem �����Ʒ...;redeem ...");
		}
		if(ob->query("dealer")=="bank")
             {
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
							tmp+=TMI("mitem ѧϰ"+to_chinese(str[i])+";learn "+str[i]+" at 1 from "+id+"");
					} else
					tmp+=TMI("mitem ѧϰ"+to_chinese(str[i])+";learn "+str[i]+" at 1 from "+id+"");
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
	    //ADD AKAI 2006 ����˵��͵�����Ʒ������
	    /***********************************************************************************
	    *    if(id=="zhu banxian")/////////id����TOMUD�����ĵ��������ID���������ж�ID�Ƿ���
	    *                          ////////////////����ɵ�ID��
        *       tmp+=TMI("mitem �����ɱ��Ѱ������;quest");////tmpΪ��Ҫ���ظ�TOMUD���ַ���������
        *      ���һ���˵���Ĵ������tmp�ַ���������������һ������������˵���ӹ��̣���
	    *    ������ǵ���������ߵ��ϵ�����Ʒ�Ĳ˵���
	    *    �����������Ʒ�ľͲ��ܷ����� ��Ӧ�÷�����ĺ�����///���¿�
	    *
	    *
	    *
	    ************************************************************************************/

   ////�����м����������²˵�//////////AKAI
     if(id=="zhu banxian")//��Ӱ�������
    tmp+=TMI("mitem �����ɱ��Ѱ������;quest");
    if("post officer"==id) //�����������
     tmp+=TMI("mitem ��������;quest");
     if("qian yankai"==id)//Ǯׯ
     {
      tmp+=TMI("mitem ��Ǯ;deposit ...");
      tmp+=TMI("mitem ��N���ƽ�;deposit ... gold");
      tmp+=TMI("mitem ��N������;deposit ... silver");
      tmp+=TMI("mitem �һ�Ǯ��;convert ...");
      tmp+=TMI("mitem ȡ5���ƽ�;withdraw 5 gold");
      tmp+=TMI("mitem ȡ10���ƽ�;withdraw 10 gold");
      tmp+=TMI("mitem ȡ50���ƽ�;withdraw 50 gold");
      tmp+=TMI("mitem ȡ100���ƽ�;withdraw 100 gold");
      tmp+=TMI("mitem ȡ1000���ƽ�;withdraw 1000 gold");
      tmp+=TMI("mitem ȡǮ;withdraw ...");
      tmp+=TMI("mitem ��ѯ���;check");
     }

     if("tang nan"==id)//����
     {
      tmp+=TMI("mitem ������Ʒ;value ��ƷID...");
      tmp+=TMI("mitem ����Ʒ;sell ��ƷID...");
      tmp+=TMI("mitem �䵱��Ʒ;pawn  ��ƷID...");
      tmp+=TMI("mitem �����Ʒ;redeem ��ƷID...");
      tmp+=TMI("mitem ����Ʒ;buy ��ƷID...");
      tmp+=TMI("mitem ��Ѱ��Ʒ�۸�;list");
     }
     	if(strsrch(id,"bingqi jia",-1)!=-1)//������
	{
	   tmp+=TMI("mitem �÷��׽�;na fenglei jian from jia");
	   tmp+=TMI("mitem �÷���;na fenghuo gun from jia");
	   tmp+=TMI("mitem �÷��Ƶ�;na fengyun dao from jia");
    }
  		if(strsrch(id,"table",-1)!=-1)  //�輸����������
	tmp+=TMI("mitem ��$U�ϵ���������;pick gift");


  /////////////////////////////////////////////AKAI
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
	//��Ʒadd akai 2006  ���������Ʒʹ�ò˵��ĵط� ////////
	/*****************************************************************************
	*    if(strsrch(id,"sleepbag",-1)!=-1)  //˯�������˯���Ĳ˵�
	*         tmp+=TMI("mitem ���$U˯��;sleep");
	*
	*
	*
	*
	*
	*
	*
	*
	*
	*****************************************************************************/
	//////////////////////////////////////�����м��������������Ʒ�Ĳ˵�����////BEGIN
    if(strsrch(id,"sleepbag",-1)!=-1)  //˯��
	tmp+=TMI("mitem ���$U˯��;sleep");
	if(strsrch(id,"mian ju",-1)!=-1)//����
	tmp+=TMI("mitem ������߱��ĳ��;pretend ����ID...");
	
	
	

	
    /////////////////////////////////////////////AKAI//////////////////////END
	if(ob->query("skill"))
		tmp+=TMI("mitem ��$U;study "+id);
	if(objectp(ob)){
	tmp+=TMI("mitem ����$U;auction "+id+" for ... gold");
	tmp+=TMI("mitem ����������Ʒ;auction 1 add ... gold");
}
	tmp+=TMI("mendd");
	tell_object(me,tmp);
	return 1;
}

