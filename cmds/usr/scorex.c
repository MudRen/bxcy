// score.c
#include <ansi.h>
#include <combat.h>
#include <mudlib.h>
inherit F_CLEAN_UP;
//string *gift_ranking = ({"下下之选","下等", "中下", "中等", "中上", "上等",
//  "上上之选"});
string bar_string = "■■■■■■■■■■■■■■■■■■■■■■■■■";
string blank_string = "□□□□□□□□□□□□□□□□□□□□□□□□□";
//string bar_string = "●〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓";
//string blank_string= "●————————————————————————";
string display_attr(int gift, int value);
string status_color(int current, int max);
string date_string(int date);
string tribar_graph(int val, int eff, int max, string color);
string cntime(int time)
{
    mixed t;

    if (time<1) time=1;
   t=localtime(time);
    return sprintf("%d年%d月%d日%d时%d分%d秒",t[5],t[4]+1,t[3],t[2],t[1],t[0]);
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
        return (day?sprintf("%d日",day):"") +(hour?sprintf("%d时",hour):"") + sprintf("%d分",min);
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
    int *attack_points,time;
    int pp,dp,sp;
    seteuid(getuid(me));
    if(!arg)
        ob = me;
    else if (wizardp(me) || me->query("id")=="afei") {
        ob = present(arg, environment(me));
        if (!ob) ob = find_player(arg);
        if (!ob) ob = find_living(arg);
        if (!ob || !me->visible(ob)) return notify_fail("你要察看谁的状态？\n");
    } else
        return notify_fail("只有巫师能察看别人的状态。\n");
    if (!ob->is_character()) return notify_fail("看清楚，那不是活物！\n");
    line = sprintf( BOLD "%s" NOR "%s\n\n", RANK_D->query_rank(ob), ob->short(1) );
    time=(int)ob->query("birthday")?(int)ob->query("birthday"):time()-ob->query("age")*86400;
    line += sprintf(" %s是一%s%s岁的%s%s，%s生。\n\n",
        ob==me?"你":ob->name(1),
        ob->query("unit"),
        chinese_number(ob->query("age")), 
        ob->query("gender"),
        ob->query("race"),
        ob==me?CHINESE_D->chinese_date(time):cntime(time));
    if (me!=ob || wizardp(me)){
        line += sprintf(" 膂力：[%s] 悟性：[%s] 根骨：[%s] 身法：[%s] 容貌：[%s] 福缘：[%s]\n\n", 
            display_attr(ob->query("str"), ob->query_str()),
            display_attr(ob->query("int"), ob->query_int()),
            display_attr(ob->query("con"), ob->query_con()),
            display_attr(ob->query("dex"), ob->query_dex()),
            display_attr(ob->query("per"), ob->query_per()),
            display_attr(ob->query("kar"), ob->query_kar()));
    }else{
        line += sprintf(" 膂力：[%s] 悟性：[%s] 根骨：[%s] 身法：[%s]\n\n", 
            display_attr(ob->query("str"), ob->query_str()),
            display_attr(ob->query("int"), ob->query_int()),
            display_attr(ob->query("con"), ob->query_con()),
            display_attr(ob->query("dex"), ob->query_dex()));
    }
    if( mapp(ob->query("family"))) {
        if( ob->query("family/master_name") )
            line = sprintf("%s %s的师父是%s。\n\n",
                line, ob==me?"你":ob->name(1),ob->query("family/master_name") );
    }
    if( mapp(ob->query("couple")) ) {
            line = sprintf("%s %s的%s是%s。\n\n",
                line, ob==me?"你":ob->name(1),ob->query("couple/couple_gender"), ob->query("couple/couple_name") );
    }
    line += " <精>  " + tribar_graph(ob->query("jing"), ob->query("eff_jing"), ob->query("max_jing"), GRN) + "\n";
    line += " <气>  " + tribar_graph(ob->query("qi"), ob->query("eff_qi"), ob->query("max_qi"), HIR) + "\n";
    prepare = ob->query_skill_prepare();
    if( objectp(weapon = ob->query_temp("weapon")) )
        skill_type = weapon->query("skill_type");
    else skill_type = "unarmed";

    attack_points = convert(COMBAT_D->skill_power(ob, skill_type, SKILL_USAGE_ATTACK));
    pp = COMBAT_D->skill_power(ob, "parry", SKILL_USAGE_DEFENSE);
    pp = weapon? pp: (pp/10);
    dp = COMBAT_D->skill_power(ob, "dodge", SKILL_USAGE_DEFENSE);
    sp = dp>pp?dp:pp;
    line += sprintf("\n 战斗攻击力 " HIW "%s (+%d)" NOR "\t\t战斗防御力 " HIW "%s (+%d)\n\n" NOR,
        process(addd(mul(attack_points,convert(10)),convert(1))) , ob->query_temp("apply/damage"),
        process(addd(mul(convert(sp),convert(10)),convert(1))) , ob->query_temp("apply/armor"));
    line += " 食物：" + tribar_graph(ob->query("food"), ob->max_food_capacity(), ob->max_food_capacity(), YEL) + "\n";
    line += " 饮水：" + tribar_graph(ob->query("water"), ob->max_water_capacity(), ob->max_water_capacity(), WHT) + "\n\n";
    line += sprintf("\n %s到目前为止总共杀了 %d 个生物，其中有 %d 个是其他玩家。\n\n",ob==me?"你":ob->name(1),ob->query("MKS") + ob->query("PKS"), ob->query("PKS"));
    if (me!=ob || wizardp(me) )
    line += sprintf("\n %s到目前为止死亡 %d 次，其中被杀 %d 次。\n\n",ob==me?"你":ob->name(1),ob->query("DIED"), ob->query("PKD"));
    line += sprintf(" %s  　神： " RED "%d\n" NOR, ob->query("shen")>0?"正":"负", ob->query("shen")>0?ob->query("shen"):-ob->query("shen") );
    line += sprintf(" 潜    能： " HIY "%d (%d%%)\n" NOR,
        (int)ob->query("potential") - (int)ob->query("learned_points"),
        (1 + (int)ob->query("learned_points")) * 100 / (1 + (int)ob->query("potential")) );
    line += sprintf(" 实战经验： " HIM "%d\n\n" NOR, ob->query("combat_exp") );
    line += sprintf(BOLD+" %s已经在"+CHINESE_MUD_NAME+"里奋斗了%s，加油呀！\n\n"+NOR,ob==me?"你":ob->name(1),age_string(ob->query("mud_age")));
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
指令格式 : score
           score <对象名称>                   (巫师专用)
这个指令可以显示你(你)或指定对象(含怪物)的基本资料。
基本资料的设定请参阅 'help setup'。
see also : hp
HELP
    );
    return 1;
}

