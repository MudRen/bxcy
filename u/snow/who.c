
/// who.c
// From ES2

#include <ansi.h>
#include <net/dns.h>

inherit F_CLEAN_UP;

mapping party=([
        "emei":    "������",
        "murong":  "����Ľ��",
        "gumu":    "��Ĺ��",
        "xueshan": "����",
        "mingjiao":"����",
        "shaolin": "������",
        "taohua":  "�һ���",
        "tianlong":"������",
        "xingxiu": "������",
        "gaibing": "ؤ��",
        "wudang":  "�䵱��",
        "shashou": "ɱ��¥",
        "kunlun":  "������",
        "huashan": "��ɽ��",
        "baituo":  "����ɽ��",
        "honghua": "�컨��",
        "kunlun":  "������",
        "quanzhen":"ȫ���",
        "riyue":   "�������",
        "yunlong": "������",
        "dali":    "��������",
        "wudu": "�嶾��",
        "xiaoyao": "��ң��",
]);

int sort_user(object,object);

void create() { seteuid(getuid()); }

string opt_party;

mixed main(object me, string arg, int remote)
{
        string str, *option, fname = "";
        object *list, *ob;
        int i, ppl_cnt, cnt, count, wcnt = 0;
        int opt_long, opt_id, opt_wiz;

        opt_party = "(null)";
        if( arg ) {
                option = explode(arg, " ");
                option -= ({ "" });
                i = sizeof(option);
                while( i-- )
                        switch(option[i]) {
                                case "-l": opt_long = 1; break;
                                case "-i": opt_id = 1; break;
                                case "-w": opt_wiz = 1; break;
                                case "-f":
                                case "-p": opt_party = me->query("family/family_name"); break;
                                default:

*/
                                        if (option[i][0] == '-' && !undefinedp(party[option[i][1..<1]]))
                                                opt_party = party[option[i][1..<1]];
                                        else return notify_fail("ָ���ʽ��who [-l|-i|-w|-p|-shaolin..wudang..mingjiao.....]\n");
                        }
        }

        if( opt_long && !wizardp(me)) {
                if( (int)me->query("jing") < 50 )
                        return notify_fail("��ľ���̫���ˣ�û�а취��֪������ҵ���ϸ���ϡ�\n");
                me->receive_damage("jing", 50);
        }

      str = HIR "��" +HIY" �������¼ "NOR+ HIR "��\n"NOR;
        str += YEL"��������������������������������������������������������������������������������������\n"NOR;
        ob = filter_array(objects(), (: userp :));
        if (opt_party != "(null)")
                ob = filter_array(ob, (: $1->query("family/family_name") ==
                        opt_party :));
        list = sort_array(ob, (: sort_user :));
        ppl_cnt = 0;
        cnt = 0;
        if( opt_long || opt_wiz ) {
                i = sizeof(list);
                while( i-- ) {
                        // Skip those users in login limbo.
                        if( !environment(list[i]) ) continue;
                        if( !me->visible(list[i]) ) continue;
            if( opt_wiz && !wiz_level(list[i]) ) continue;
                        if (interactive(list[i])) ppl_cnt++;
                        else cnt++;
                        str = sprintf("%s%12s%s%s%s\n",
                                str,
                                RANK_D->query_rank(list[i]),
                                interactive(list[i])?(query_idle(list[i]) > 120?HIM "+" NOR:" "):HIG "*" NOR,
                                list[i]->short(1),
				interactive(list[i])?(query_idle(list[i]) > 120?HIM "<����"+ chinese_number(query_idle(list[i])/60) + "����>" NOR:" "):" "                                
                        );
                }
        } else {
                i = sizeof(list);
                count = 0;
                while( i-- ) {
                        // Skip those users in login limbo.
                        if( !environment(list[i]) ) continue;
                        if( !me->visible(list[i]) ) continue;
                        if (!wiz_level(list[i]) && fname != list[i]->query("family/family_name")) {
                            fname = list[i]->query("family/family_name");
                            if (count % (opt_id?4:8)) str += "\n";
                            str += sprintf(HIY "%-10s" NOR, (fname?fname:"��ͨ����") + "��");
                            count = 1;
                        }
                        if (!wcnt && wiz_level(list[i])) {
                            if (count % (opt_id?4:8)) str += "\n";
                            str += sprintf(HIY "%-10s" NOR, "��ʦ��");
                            wcnt = 1;
                            count = 1;
                        }
                        if (!(count % (opt_id?4:8))) {
                                count++;
                                str += "          ";
                        }
                        str = sprintf("%s%s%-"+(opt_id?19:9)+"s"NOR"%s",
                                str,
                                interactive(list[i]) ? (query_idle(list[i]) > 120 ? HIM "+" : " ") : HIG "*",
                                list[i]->name(1) + (opt_id ? "("+capitalize(list[i]->query("id"))+")" : ""),
                                ++count % (opt_id?4:8) ? "" : "\n"
                        );
                        if (interactive(list[i])) ppl_cnt++;
                        else cnt++;
                }
                if( count % (opt_id?4:8) ) str += "\n";
        }
        str += YEL"��������������������������������������������������������������������������������������\n"NOR;
        str = sprintf("%s�� %d λ��������У�%d λ��Ҷ����У�ϵͳ������%s\n* ��ʾ������  + ��ʾ������", str, ppl_cnt,
                cnt, query_load_average());


        me->start_more(str);
        return 1;
}

int sort_user(object ob1, object ob2)
{
        string name1, name2;

        reset_eval_cost();
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

int help(object me)
{
write(@HELP
ָ���ʽ : who [-l|-i|-w|-p|-������]

���ָ������г����������ϵ���Ҽ���ȼ���

-l ѡ���г��ϳ���ѶϢ��
-i ֻ�г���ҵ�Ӣ�Ĵ��š�
-p ֻ�г�ͬ�ŵ���ҡ�
-w ֻ�г��������е���ʦ��
��������
        emei:     ������,
        murong:   ����Ľ��,
        gumu:     ��Ĺ��,
        xueshan:  ѩɽ��,
        mingjiao: ����,
        shaolin:  ������,
        taohua:   �һ���,
        tianlong: ������,
        xingxiu:  ������,
        gaibing:  ؤ��,
        wudang:   �䵱��,
        kunlun:   ������,
        huashan:  ��ɽ��,
        baituo:   ����ɽ��,
        honghua:  �컨��,
        kunlun:   ������,
        quanzhen: ȫ���,
        riyue:    �������,
        yunlong:  ������,
        dali:     ��������,
        wudu:  �嶾��,
        xiaoyao:  ��ң��,
���ָ� finger
HELP
        );
        return 1;
}
