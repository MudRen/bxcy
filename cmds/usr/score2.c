// score.c
#include <ansi.h>
#include <combat.h>
#include <mudlib.h>
inherit F_CLEAN_UP;
//string *gift_ranking = ({"����֮ѡ","�µ�", "����", "�е�", "����", "�ϵ�",
//  "����֮ѡ"});
string bar_string = "��������������������������������������������������";
string blank_string = "��������������������������������������������������";
//string bar_string = "�������������������������������������������������";
//string blank_string= "�񡪡���������������������������������������������";
string display_attr(int gift, int value);
string status_color(int current, int max);
string date_string(int date);
string tribar_graph(int val, int eff, int max, string color);
string cntime(int time)
{
    mixed t;

    if (time<1) time=1;
   t=localtime(time);
    return sprintf("%d��%d��%d��%dʱ%d��%d��",t[5],t[4]+1,t[3],t[2],t[1],t[0]);
}

void create() { seteuid(ROOT_UID); }
string age_string(int time)
{
        int day, hour, min, sec;
        sec = time % 60;
        time /= 60;
        min = time % 60;
        time /= 60;
        hour = time % 24;
        time /= 24;
        day = time;
        return (day?sprintf("%d��",day):"") +(hour?sprintf("%dʱ",hour):"") + sprintf("%d��",min);
}

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
    object ob;
    mapping prepare;
    string line, skill_type;
    object weapon;
    int attack_points, dodge_points, parry_points,time;
    seteuid(getuid(me));
    if(!arg)
        ob = me;
    else if (wizardp(me) || me->query("id")=="afei") {
        ob = present(arg, environment(me));
        if (!ob) ob = find_player(arg);
        if (!ob) ob = find_living(arg);
        if (!ob || !me->visible(ob)) return notify_fail("��Ҫ�쿴˭��״̬��\n");
    } else
        return notify_fail("ֻ����ʦ�ܲ쿴���˵�״̬��\n");
    if (!ob->is_character()) return notify_fail("��������ǲ��ǻ��\n");
    line = sprintf( BOLD "%s" NOR "%s\n\n", RANK_D->query_rank(ob), ob->short(1) );
    time=(int)ob->query("birthday")?(int)ob->query("birthday"):time()-ob->query("age")*86400;
    line += sprintf(" %s��һ%s%s���%s%s��%s����\n\n",
        ob==me?"��":ob->name(1),
        ob->query("unit"),
        chinese_number(ob->query("age")), 
        ob->query("gender"),
        ob->query("race"),
        ob==me?CHINESE_D->chinese_date(time):cntime(time));
    if (me!=ob || wizardp(me)){
        line += sprintf(" ������[%s] ���ԣ�[%s] ���ǣ�[%s] ����[%s] ��ò��[%s] ��Ե��[%s]\n\n", 
            display_attr(ob->query("str"), ob->query_str()),
            display_attr(ob->query("int"), ob->query_int()),
            display_attr(ob->query("con"), ob->query_con()),
            display_attr(ob->query("dex"), ob->query_dex()),
            display_attr(ob->query("per"), ob->query_per()),
            display_attr(ob->query("kar"), ob->query_kar()));
    }else{
        line += sprintf(" ������[%s] ���ԣ�[%s] ���ǣ�[%s] ����[%s]\n\n", 
            display_attr(ob->query("str"), ob->query_str()),
            display_attr(ob->query("int"), ob->query_int()),
            display_attr(ob->query("con"), ob->query_con()),
            display_attr(ob->query("dex"), ob->query_dex()));
    }
    if( mapp(ob->query("family"))) {
        if( ob->query("family/master_name") )
            line = sprintf("%s %s��ʦ����%s��\n\n",
                line, ob==me?"��":ob->name(1),ob->query("family/master_name") );
    }
    if( mapp(ob->query("couple")) ) {
            line = sprintf("%s %s��%s��%s��\n\n",
                line, ob==me?"��":ob->name(1),ob->query("couple/couple_gender"), ob->query("couple/couple_name") );
    }
    line += " <��>  " + tribar_graph(ob->query("jing"), ob->query("eff_jing"), ob->query("max_jing"), GRN) + "\n";
    line += " <��>  " + tribar_graph(ob->query("qi"), ob->query("eff_qi"), ob->query("max_qi"), HIR) + "\n";
    prepare = ob->query_skill_prepare();
    if( objectp(weapon = ob->query_temp("weapon")) )
        skill_type = weapon->query("skill_type");
    else skill_type = "unarmed";

    attack_points = COMBAT_D->skill_power(ob, skill_type, SKILL_USAGE_ATTACK);
    parry_points = COMBAT_D->skill_power(ob, "parry", SKILL_USAGE_DEFENSE);
    dodge_points = COMBAT_D->skill_power(ob, "dodge", SKILL_USAGE_DEFENSE);
    parry_points = weapon? parry_points: (parry_points/10);
    line += sprintf("\n ս�������� " HIW "%d (+%d)" NOR "\t\tս�������� " HIW "%d (+%d)\n\n" NOR,
        attack_points + 1, ob->query_temp("apply/damage"),
        (dodge_points>parry_points?dodge_points:parry_points) + 1, ob->query_temp("apply/armor"));
    line += " ʳ�" + tribar_graph(ob->query("food"), ob->max_food_capacity(), ob->max_food_capacity(), YEL) + "\n";
    line += " ��ˮ��" + tribar_graph(ob->query("water"), ob->max_water_capacity(), ob->max_water_capacity(), WHT) + "\n\n";
    line += sprintf("\n %s��ĿǰΪֹ�ܹ�ɱ�� %d ����������� %d ����������ҡ�\n\n",ob==me?"��":ob->name(1),ob->query("MKS") + ob->query("PKS"), ob->query("PKS"));
    if (me!=ob || wizardp(me) )
    line += sprintf("\n %s��ĿǰΪֹ���� %d �Σ����б�ɱ %d �Ρ�\n\n",ob==me?"��":ob->name(1),ob->query("DIED"), ob->query("PKD"));
    line += sprintf(" %s  ���� " RED "%d\n" NOR, ob->query("shen")>0?"��":"��", ob->query("shen")>0?ob->query("shen"):-ob->query("shen") );
    line += sprintf(" Ǳ    �ܣ� " HIY "%d (%d%%)\n" NOR,
        (int)ob->query("potential") - (int)ob->query("learned_points"),
        (1 + (int)ob->query("learned_points")) * 100 / (1 + (int)ob->query("potential")) );
    line += sprintf(" ʵս���飺 " HIM "%d\n\n" NOR, ob->query("combat_exp") );
    line += sprintf(BOLD+" %s�Ѿ���"+CHINESE_MUD_NAME+"��ܶ���%s������ѽ��\n\n"+NOR,ob==me?"��":ob->name(1),age_string(ob->query("mud_age")));
    write(line);
    return 1;
}
string display_attr(int gift, int value)
{
    if( value > gift ) return sprintf( HIY "%3d" NOR, value );
    else if( value < gift ) return sprintf( WHT "%3d" NOR, value );
    else return sprintf("%3d", value);
}
string status_color(int current, int max)
{
    int percent;
    if( max ) percent = current * 100 / max;
    else percent = 100;
    if( percent > 100 ) return HIC;
    if( percent >= 90 ) return HIG;
    if( percent >= 60 ) return HIY;
    if( percent >= 30 ) return YEL;
    if( percent >= 10 ) return HIR;
    return RED;
}
string tribar_graph(int val, int eff, int max, string color)
{
    return color + bar_string[0..(val*25/max)*2-1]
        + ((eff > val) ? blank_string[(val*25/max)*2..(eff*25/max)*2-1] : "") + NOR;
}
int help(object me)
{
    write(@HELP
ָ���ʽ : score
           score <��������>                   (��ʦר��)
���ָ�������ʾ��(��)��ָ������(������)�Ļ������ϡ�
�������ϵ��趨����� 'help setup'��
see also : hp
HELP
    );
    return 1;
}

