// enable.c
#include <ansi.h>
inherit F_CLEAN_UP;
mapping valid_types = ([
        "unarmed":      "ȭ��",
        "sword":        "����",
        "hammer":       "����",
        "blade":        "����",
        "stick":        "����",
        "axe":          "����",
        "staff":        "�ȷ�",
        "club" :    "����",
        "throwing":     "����",
        "force":        "�ڹ�",
        "parry":        "�м�",
        "dodge":        "�Ṧ",
        "taoism":       "��ѧ�ķ�",
        "whip":     "�޷�",
]);
object find_player(string target)
{
        int i;
        object *str;
        str=users();
        for (i=0;i<sizeof(str);i++)
                if (str[i]->query("id")==target)
                        return str[i];
        return 0;
}
int main(object me, string arg)
{
        mapping map;
        string *skill, ski, map_to,str;
        int i, modify;
        object ob;
        seteuid(getuid());
        str="";
        if( !arg ||arg=="" ) {
                map = me->query_skill_map();
                if( !mapp(map) || sizeof(map)==0 )
                map=(([ ]));
                skill = keys(valid_types);
                for (i=0; i<sizeof(skill); i++) {
                        if( undefinedp(valid_types[skill[i]]) ) {
                                map_delete(map, skill[i]);
                                continue;
                        }
                        if( !me->query_skill(skill[i]) ) continue;
                        modify = me->query_temp("apply/" + skill[i]);
                        str+=sprintf("  %-20s�� %-20s  ��Ч�ȼ���%s%3d\n" NOR, 
                                valid_types[skill[i]] + " (" + skill[i] + ")",
                                undefinedp(map[skill[i]]) ? "��" : to_chinese(map[skill[i]]),
                                (modify==0 ? "" : (modify>0 ? HIC : HIR)),
                                me->query_skill(skill[i]));
                }
                if (str=="")
                        return notify_fail("��Ŀǰû���κ����⼼�ܡ�\n");
                if (arg!="")    write("��������Ŀǰʹ���е����⼼�ܡ�\n");
                write(str);
                return 1;
        }
        if( arg=="?" ) {
                write("�����ǿ���ʹ�����⼼�ܵ����ࣺ\n");
                skill = sort_array(keys(valid_types), (: strcmp :) );
                for(i=0; i<sizeof(skill); i++) {
                        printf("  %s (%s)\n", valid_types[skill[i]], skill[i] );
                }
                return 1;
        }
        if( wizardp(me) && arg ) {
                ob = find_player(arg);
                if( !ob ) ob = find_living(arg);
                if( !ob ) ob = present(arg, environment(me));
                if (ob) {
                        write(ob->short()+"Ŀǰʹ���е����⼼�ܣ�\n");
                        return main(ob,"");
                }
        }
        if( sscanf(arg, "%s %s", ski, map_to)!=2 )
                return notify_fail("ָ���ʽ��enable[<��������> <��������>|none]\n");
        if( undefinedp(valid_types[ski]) )
                return notify_fail("û������������࣬�� enable ? ���Բ鿴����Щ���ࡣ\n");
        if (map_to == me->query_skill_mapped(ski) )
                return notify_fail("���Ѿ�װ�����ˡ�\n");

        if( map_to == "none" ) {
            if ((me->query_temp("powerup") || me->query_temp("exercise_cost")) && ski=="force" && stringp(me->query_skill_mapped("force"))){
                me->set_temp("exercise_cost",-1);
                write(RED "�����Ż����ڹ���ͻȻ������֫��ľ���ֽű��䡣\n��Ȼ����Ϣ���ܻص����\n"NOR);
                if (me->query("max_neili")>100)
                        me->add("max_neili",-100);
                else    me->delete("max_neili");
                me->unconcious();
                return 1;
            }
                me->map_skill(ski);
                me->reset_action();
                write("Ok.\n");
                return 1;
        } else if( map_to==ski ) {
                write("��" + to_chinese(ski) + "��������" + valid_types[ski] + "�Ļ���������Ҫ enable��\n");
                return 1;
        }
        if( !me->query_skill(map_to, 1) )
                return notify_fail("�㲻�����ּ��ܡ�\n");
        if( !SKILL_D(map_to)->valid_enable(ski) )
                return notify_fail("������ܲ��ܵ���������;��\n");
        if ((me->query_temp("powerup") || me->query_temp("exercise_cost") || me->query_temp("protect")) && ski=="force"){
                me->set_temp("exercise_cost",-1);
 
                write(RED "�������һ���ڹ���ͻȻ������֫��ľ���ֽű��䡣\n��Ȼ����Ϣ���ܻص����\n"NOR);
                if (me->query("max_neili")>100)
                        me->add("max_neili",-100);
                else    me->delete("max_neili");
                me->unconcious();
                return 1;
        }
        me->map_skill(ski, map_to);
        me->reset_action();
        write("Ok.\n");
        
        if( ski=="taoism" ) {
                write("�������һ�ַ���ϵ�������������¶�����\n");
                me->set("jingli", 0);
                me->receive_damage("jing", 0);
        } 
        else if( ski=="force" ) {
                write("�������һ���ڹ��������������¶�����\n");
                me->set("neili", 0);
                me->receive_damage("qi", 0);
        }
        return 1;
}
int help(object me)
{
        write(@HELP
ָ���ʽ : enable [<��������> <��������> | none]
           enable ?
���ָ������ָ����Ҫ�õļ��ܣ���ָ����������ͼ������ơ�������Ӳ�
�������ʾ���������༰��Ŀǰ��ʹ�õļ������� �������һ�������г�
������ʹ�����⼼�ܵļ������ࡣ
 
HELP
        );
        return 1;
}
