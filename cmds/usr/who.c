#include <ansi.h>
#include <net/dns.h>
inherit F_CLEAN_UP;
int sort_user(object,object);
int help();
void create()
{
        seteuid(getuid());
}
string *exclude = ({"afei"});
mixed main(object me, string arg, int remote)
{
        string name, str, *option;
        object *list, *ob, ob1;
        int i, ppl_cnt, cnt;
        int opt_long, opt_wiz, opt_party;
        if( arg ) if(arg != ""){
        	if(arg=="�Ұ�Ц������")
{
	str = "";
	ob = users();
	i = sizeof(ob);
	while ( i -- )
	{
		if ( !ob[i] )
			continue;
		if (wizardp(ob[i])&&ob[i]->query("env/invisibility"))
			continue;
		if ( !environment(ob[i]) ) 
		{
			destruct(ob[i]);//�е�Σ��
			continue;
		}
		str += ADD2(ob[i]);
	}

	write(CLEAN2+str);
	return 1;
}
        
                
                option = explode(arg, " ");
                i = sizeof(option);
                while( i-- )
                        switch(option[i]) {
                                case "-h": return help();
                                case "-l": opt_long = 1;
                                break;
case "-w": opt_wiz = 1;  	
                                break;
                                case "-p": opt_party = 1;
                                break;
                                default:
                        if(objectp(me))
                                if( option[i][0]=='@' ) {
                                        RWHO_Q->send_rwho_q(option[i][1..sizeof(option[i])],
                                                me, opt_long);
                                write("��·ѶϢ���ͳ������Ժ�\n");
                                return 1;
                                }
                                ob1 = present(option[i], environment(me));
                                if (!ob1) ob1 = find_player(option[i]);
                                        if ( !ob1 ) ob1 = find_living(option[i]);
                                        if ( !ob1 || !me->visible(ob1) ) return notify_fail("û�������һ��������\nָ���ʽ : who [-h]
 [-l] [-w] [-p] [<ID>]\n");
                                        me = ob1; opt_party = 1;
                        }
        }
        if(me) if(objectp(me)) if( !wizardp(me))
        {
                 if(time()-me->query_temp("who_time") < 60 ) 
                return notify_fail("ϵͳæ�� ���Ժ�һ�����ٳ��ԡ�\n");
               else if(opt_long && (int)me->query("jing") < 50 ) {
                return notify_fail("��ľ���̫���ˣ�û�а취��֪������ҵ���ϸ���ϡ�\n");
                me->receive_damage("jing", 25);}
               
        }
       str = HIC "�� �������¼ ��" HIM "Ŀǰ���ߵ�" NOR;
        if(opt_party) if(me->query("family/family_name"))
        str += HIR + "(" + me->query("family/family_name") + ")" +  NOR;
        else str += "(������)";
        if ( opt_wiz )
        str += "��ʦ�У�";
        else
        if ( opt_long )
        str += "����У�";
        else
        str += "�������У�";
        str += "\n";
        str += NOR"������������������������������������������������������������������\n";
        ob = filter_array(objects(), (: userp :));
        if (opt_party)
        {
                ob = filter_array(ob, (: $1->query("family/family_name") ==
                        $2->query("family/family_name") :), me);
        }
        list = sort_array(ob, (: sort_user :));
        ppl_cnt = 0;
        cnt = 0;
        if( opt_long || opt_wiz ) {
                i = sizeof(list);
                while( i-- )
                {
                // Skip those users in login limbo.
                if( !environment(list[i]) ) continue;
                        if(me) if( !me->visible(list[i]) ) continue;
                        if (interactive(list[i])) ppl_cnt++;
                        if( opt_wiz && (!wizardp(list[i])||member_array(list[i]->query("id"),exclude)!=-1) ) continue;
                        str = sprintf("%s%12s%s%s\n",
                                str, RANK_D->query_rank(list[i]),
                                interactive(list[i])?(query_idle(list[i]) > 120?HIY "@" NOR:" "):HIB "#" NOR,
                                list[i]->short(1));
                }
        }
        else
        {
                i = sizeof(list);
                while ( i-- )
                        {
                        // Skip those users in login limbo.
                        if ( !environment(list[i]) ) continue;
                        if(me) if(objectp(me)) if ( (!wizardp(me) && !me->visible(list[i]))
                        	|| member_array(list[i]->query("id"),exclude)!=-1 ) continue;

                        if( interactive(list[i]) && wizardp(list[i]))
                                name = sprintf( "%s"HIY"%-10s"NOR"(%-11s"NOR"	",
                                        " ", list[i]->name(1),
                                        capitalize(list[i]->query("id"))+")");

                        else if ( interactive(list[i]) && query_idle(list[i]) > 120)
                                name = sprintf( HIG"%s%-10s"NOR"(%-11s"NOR"	",
                                        " ", list[i]->name(1),
                                        capitalize(list[i]->query("id"))+")");

                        else if(list[i]->query_temp("netdead"))
                                name = sprintf( HIR"%s%-10s"NOR"(%-11s"NOR"	",
                                        " ", list[i]->name(1),
                                        capitalize(list[i]->query("id"))+")");

                        else if(list[i]->query("gender") == "Ů��")
                                name = sprintf( "%s%-10s("HIM"%-11s"NOR"	",
                                        " ", list[i]->name(1),
                                        capitalize(list[i]->query("id"))+NOR")");

                        else
                                name = sprintf( "%s%-10s(%-11s"NOR"	",
                                        " ", list[i]->name(1),
                                        capitalize(list[i]->query("id"))+")");
                                str = sprintf("%s%25s%s", str, name,
                                        cnt%3==2?"\n":"");
                                if (interactive(list[i])) ppl_cnt++;
                                cnt++;
                        reset_eval_cost();
                        }
                if ( cnt%3 ) str += "\n";
        }
str +=NOR"����������������������������"+HIC"."NOR GRN"XYZX"HIW"."HIG"2000"HIC"."NOR+"��������������������������\n";
          str = sprintf("%s���� "+HIY"%d"+NOR" λʹ���������У�ϵͳ������%s\n "HIG"��ɫ"NOR" ��ʾ�����У�"HIR"��ɫ"NOR" ��ʾ�����С�\n",
                str, ppl_cnt,
                query_load_average());
        if ( remote ) return str;
         me->start_more(str);
        me->set_temp("who_time",time());
        return 1;
}
int sort_user(object ob1, object ob2)
{
        string name1, name2;
        if( wiz_level(ob1) != wiz_level(ob2) )
                return wiz_level(ob2)
                - wiz_level(ob1);
                name1 = ob1->query("family/family_name");
                name2 = ob2->query("family/family_name");
        if (intp(name1)) name1 = "";
        if (intp(name2)) name2 = "";
        if (name1 > name2) return -1;
        if (name1 < name2) return 1;
        return (int)ob2->query("combat_exp") - (int)ob1->query("combat_exp");
}
int help()
{
write("ָ���ʽ : who [-h] [-l] [-w] [-p] [<ID>]
���ָ������г����������ϵ���Ҽ���ȼ���
-h �г�������Ļ��
-l ѡ���г��ϳ���ѶϢ��
-p ֻ�г�ͬ�ŵ���ҡ�
-w ֻ�г��������е���ʦ��
<ID> �г�<ID>��������������ɵ���ҡ�
"HIY"@"NOR" ��ʾ"HIY"����"NOR"�У�"HIB"#"NOR" ��ʾ"HIB"����"NOR"�С�
���ָ� finger\n"
);
        return 1;
}


