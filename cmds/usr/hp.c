#include <ansi.h>
inherit F_CLEAN_UP;
string status_color(int current, int max);
int potential_lv(int exp);
int main(object me, string arg)
{
        object ob;
        mapping my;
//         seteuid(getuid(me));
         seteuid(getuid());
        if(!arg) ob = me;
        else if (wizardp(me)) { ob = present(arg, environment(me));
             if (!ob) ob = find_player(arg);
             if (!ob) ob = find_living(arg);
        if (!ob) return notify_fail("��Ҫ�쿴˭��״̬��\n");
        } else return notify_fail("ֻ����ʦ�ſ��Բ쿴���˵�״̬��\n");
        my = ob->query_entire_dbase();
    printf("\n������%s ("HIG"%s"NOR")\n"NOR,ob->name(),capitalize(ob->query("id")));
    printf(NOR WHT"������������������������������������������������������������\n"NOR);
    printf(HIR"����Ѫ��%s%6d/%6d %s(%3d%%)"NOR,status_color(my["qi"],my["eff_qi"]),my["qi"],my["eff_qi"],
                status_color(my["eff_qi"],my["max_qi"]),my["eff_qi"]*100/my["max_qi"]);
    printf(HIR"  ��������%s%6d/%6d (+%3d)\n" NOR,status_color(my["neili"], my["max_neili"]), my["neili"], my["max_neili"],my["jiali"]);
    printf(HIR"������%s%6d/%6d %s(%3d%%)"NOR,status_color(my["jing"],my["eff_jing"]),my["jing"],
                my["eff_jing"],status_color(my["eff_jing"],my["max_jing"]),my["eff_jing"]*100/my["max_jing"]);
    printf(HIR"  ��������%s%6d/%6d (+%3d)\n"NOR,status_color(my["jingli"],my["max_jingli"]),
                 my["jingli"],my["max_jingli"],my["jiajing"]);
    printf(CYN"��ʳ�%s%6d/%6d [%3d%%]"NOR,status_color(my["food"], ob->max_food_capacity()),
        my["food"], ob->max_food_capacity(),my["food"]*100/ob->max_food_capacity());
    printf(CYN"  ��Ǳ�ܡ�%s%6d/%6d\n"NOR,HIY,(int)ob->query("potential") - (int)ob->query("learned_points"),potential_lv(my["combat_exp"]));
    printf(CYN"����ˮ��%s%6d/%6d [%3d%%]"NOR,status_color(my["water"], ob->max_water_capacity()),
        my["water"], ob->max_water_capacity(),my["water"]*100/ob->max_water_capacity());
    printf(CYN"  �����顽   %s%d\n"NOR,HIM,my["combat_exp"] );
    printf(NOR WHT"������������������������������������������������������������\n"NOR);
        return 1;
}
string status_color(int current, int max)
{
        int percent;
        if( max>0 ) percent = current * 100 / max;
        else percent = 100;
        if( percent > 100 ) return HIC;
        if( percent >= 90 ) return HIG;
        if( percent >= 60 ) return HIY;
        if( percent >= 30 ) return YEL;
        if( percent >= 10 ) return HIR;
        return RED;
}
int potential_lv(int exp)
{
        int grade;
        grade = 100 + exp / 500;
        return grade;
}

int help(object me)
{
        write(@HELP
ָ���ʽ : hp
           hp <��������>                   (��ʦר��)
 
���ָ�������ʾ��(��)��ָ������(������)�ľ�, ��, ����ֵ��
 
see also : score
HELP
    );
    return 1;
}

