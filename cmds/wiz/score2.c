//score.c 
//copied from xyj2000
#include <ansi.h>
#include <combat.h>
#include <mudlib.h>

inherit F_CLEAN_UP;

string display_attr(int gift, int value);
string status_color(int current, int max);
string date_string(int date);
string tribar_graph(int val, int eff, int max, string bcolor, string fcolor, string dcolor);

void create() { seteuid(ROOT_UID); }

int main(object me, string arg)
{
        object ob;
        mapping my;
        string line, str, skill_type, *marks;
        object weapon;
        int i, attack_points, dodge_points, parry_points;
// int obstacles,dntg;  

        seteuid(getuid(me));
        if(!arg)

                ob = me;
        else if (wizardp(me)) {
                ob = present(arg, environment(me));
                if (!ob) ob = find_player(arg);
                if (!ob) ob = find_living(arg);
                if (!ob) return notify_fail("你要察看谁的状态？\n");
        } else
                return notify_fail("只有巫师能察看别人的状态。\n");

        my = ob->query_entire_dbase();
        write(NOR YEL"≡≡≡≡≡≡≡≡≡≡"HIG"个"NOR YEL"≡≡"HIG"人"NOR YEL"≡≡"HIG"档"NOR YEL"≡≡"HIG"案"NOR YEL"≡≡≡≡≡≡≡≡≡≡\n"NOR);
        write("你现在的头衔 : "+RANK_D->query_rank(ob)+"\n");
        write("你现在的职称 : "+ob->short(1)+"\n");
        line = NOR YEL"≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡\n"NOR;
        str = "";
        if( mapp(my["family"]) ) {
                if( my["family"]["master_name"] ) str =my["family"]["family_name"]+HIC+my["family"]["master_name"];
        }
        if( mapp(my["marks"]) ) {
                marks = keys( my["marks"] );
                for( i = 0; i < sizeof(marks); i ++ ) {
                        if( str != "" ) str += "、";
                        str += marks[i];

                }
        }

        line += sprintf( " 年龄：[%s%-4s%s]         生日：[%s%-24s%s]\n",
                 HIC, chinese_number(ob->query("age")), NOR,
                 HIC, CHINESE_D->chinese_date(((int)ob->query("birthday") -14*365*24*60) * 60), NOR );

        line += sprintf( " 性别：[%s%-4s%s]         体重：[%s%-4s公斤%s]  门派：[%s%-6s%s]\n\n",
                 HIC, ob->query("gender"), NOR,
                 HIC, chinese_number((int)ob->query_weight()/1000), NOR,
                 HIC, ob->query("family/family_name")?ob->query("family/family_name"):"普通百姓", NOR );
        if (ob->query("couple/couple_name") != 0) line += sprintf(" 婚姻状况：" HIG"伴侣：%-11s"NOR,ob->query("couple/couple_name"));
        else line += sprintf(" 婚姻状况：" MAG"未婚\t\t\t"NOR);
        if( str != "" ) line
 += sprintf( " 师承：[%-20s%s]\n\n",str, NOR );
        else line+="["CYN"还未曾拜师学艺"NOR"]\n";      
        
        if( objectp(weapon = ob->query_temp("weapon")) )
                skill_type = weapon->query("skill_type");
        else
                skill_type = "unarmed";

       attack_points = COMBAT_D->skill_power(ob, skill_type, SKILL_USAGE_ATTACK);
        parry_points = COMBAT_D->skill_power(ob, skill_type, SKILL_USAGE_DEFENSE);
        dodge_points = COMBAT_D->skill_power(ob, "dodge", SKILL_USAGE_DEFENSE);

       line += sprintf( " 体格：[%s %4s %s]  ",
                 NOR, display_attr(my["str"], ob->query_str()), NOR );
        if( my["eff_jing"] <my["max_jing"] ) str = HIR+"生病";
        else if( my["jing"]*100 / my["max_jing"]>=70 ) str = HIG + "饱满";
        else if( my["jing"]*100 / my["max_jing"]>=40 ) str = HIR + "疲倦";
        else str = HIB + "很累";
        line += "〖"HIR"精神"NOR"〗  " + tribar_graph(my["jing"], my["eff_jing"], my["max_jing"], NOR, HIR ,HIW)
                + sprintf( "  [%4s%s]\n", str,NOR);
        line += sprintf( " 根骨：[%s %4s %s]  ",
                NOR, display_attr(my["con"], ob->query_con()), NOR );
        if( my["eff_qi"] <my["max_qi"] ) str = HIR+"伤残";
        else if( my["qi"]*100 / my["max_qi"]>=70 ) str = HIG + "充沛";
        else if( my["qi"]*100 / my["max_qi"]>=40 ) str = HIR + "受伤";
        else str = HIB + "重伤";
        line += "〖"HIR"气血"NOR"〗  " + tribar_graph(my["qi"], my["eff_qi"], my["max_qi"], NOR, HIR ,HIW)
                + sprintf( "  [%4s%s]\n",str,NOR);
        
        
        if( my["food"] * 100 / ob->max_food_capacity() >= 90 ) str = HIG+"很饱";
        else if( my["food"] * 100 / ob->max_food_capacity() >= 50 ) str = HIC+"正常";
        else if( my["food"] * 100 / ob->max_food_capacity() >= 20 ) str = HIR+"缺食";
        else str = HIB + "饥饿";
        
        line += sprintf( " 悟性：[%s %4s %s]  ",
                NOR, display_attr(my["int"], ob->query_int()), NOR );
        line += "〖"HIC"食物"NOR"〗：" + tribar_graph(my["food"], ob->max_food_capacity(),
                ob->max_food_capacity(), NOR, HIC ,HIR)
                + sprintf( "  [%4s%s]\n", str, NOR );        
        line += sprintf( " 身法：[%s %4s %s]  ",
                NOR, display_attr(my["spi"], ob->query_dex()), NOR );

        if( my["water"] * 100 / ob->max_water_capacity() > 60 ) str = HIG + "正常";
        else if( my["water"] * 100 / ob->max_water_capacity() > 30 ) str = HIR + "缺水";
        else str = HIB + "饥渴";

        line += "〖"HIC"饮水"NOR"〗：" + tribar_graph(my["water"], ob->max_water_capacity(),
                ob->max_water_capacity(), NOR, HIC ,HIR)
                + sprintf( "  [%4s%s]\n",  str, NOR );
        line += sprintf( " 容貌：[%s %4s %s]  ",
                NOR, wizardp(ob)?display_attr(my["per"], ob->query_per()):"隐藏", NOR );
        
        line += "〖"HIW"死亡"NOR"〗：" 
                + sprintf( "杀害玩家：%s%d%s 位,杀死敌人：%s%d%s 名\n",  HIR, my["PKS"], NOR,
                HIW, my["MKS"], NOR);
        
        
  

        line += sprintf( " 福缘：[%s %4s %s]  ",
                NOR, wizardp(ob)?display_attr(my["kar"], ob->query_kar()):"隐藏", NOR );
        if((int)ob->query("balance"))
        line+= "〖"HIY"存款"NOR"〗："+MONEY_D->money_str((int)ob->query("balance"))+"\n\n";
        else line+="〖"HIY"存款"NOR"〗："+HIW"没有任何存款"NOR+"\n\n";
      if(wizardp(this_player())) 
        line += sprintf(" 战斗攻击力 " HIW "%d (+%d)" NOR "\t\t战斗防御力 " HIW "%d (+%d)\n\n" NOR,
        attack_points/100 + 1, ob->query_temp("apply/damage"),
                (dodge_points + (weapon? parry_points: 
                (parry_points/10)))/100 + 1, ob->query_temp("apply/armor"));
        else line+=sprintf(" 兵器伤害力： ["HIR"%d"NOR"]" NOR "\t\t盔甲保护力： ["HIG"%d"NOR"]\n\n" NOR,
        ob->query_temp("apply/damage"),
        ob->query_temp("apply/armor"));
/*        obstacles = ob->query("qujing/number");
        if(obstacles)
                line += sprintf(RED" 江湖风雨"NOR"：你已经历了"RED"%s"NOR"次劫难。\n", chinese_number(obstacles));
                else line += RED" 豪侠晚歌"NOR"：你还未曾踏上征途\n";
        dntg = ob->query("dntg/number");
             if (dntg == 0) line += " "RED"豪侠晚歌"NOR"：你还未曾涉入江湖\n";
             else line+= RED" 豪侠晚歌"NOR"：你在豪侠晚歌已过"HIR+chinese_number(dntg)+NOR"关。\n";
        if(ob->query("kill/pkgain") ) 
        { 
                line +=sprintf(" ＰＫ经验增加： %s  \n", COMBAT_D->chinese_daoxing(ob->query("kill/pkgain")));
                if(!ob->query("kill/pklose") && !ob->query("kill/nkgain") ) line+="\n";
        }
        if(ob->query("kill/nkgain") ) 
        {
                line +=sprintf(" ＮＫ经验增加： %s\n", COMBAT_D->chinese_daoxing(ob->query("kill/nkgain")));
        }

        line += sprintf(" 武学境界：[%s]\n",
                 RANK_D->describe_exp(ob->query("combat_exp")) );
        line += sprintf(" 内力修为：[%s]\n",
                 RANK_D->describe_neili(ob->query("max_neili")) );
*/
        line += YEL"≡≡≡≡≡≡≡≡≡≡ "GRN"豪侠晚歌"YEL" ≡≡≡≡≡≡≡≡≡≡≡\n"NOR;
 line += sprintf(WHT+" 为争夺武林盟主%s已经历了"HIR"%s"WHT" 的岁月。 \n\n"+NOR,ob==me?"你":ob->name(1),FINGER_D->age_string( (int)ob->query("mud_age")));

        write(line+BBLK);
        return 1;
}

string display_attr(int gift, int value)
{
        if( value > gift ) return sprintf( HIY "%4d", value );
        else if( value < gift ) return sprintf( HIC "%4d", value );
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

string tribar_graph(int val, int eff, int max, string bcolor, string fcolor, string dcolor)
{
        string ret;
        int i, n, eff_n, max_n = 10;

        if( max == 0 ) max = 1;
        n = val * 100 / max / 10;
        eff_n = eff * 100 / max / 10;

        if( n < 0 ) n = 0;
        if( eff_n < 0 ) eff_n = 0;
        if( n > max_n ) n = max_n;
        if( eff_n > max_n ) eff_n = max_n;

        ret = NOR  + bcolor + fcolor ;
        for( i = 0 ; i < max_n; i ++ ) {
                if( i > eff_n ) ret += dcolor;
                if( i < n )  ret += "━";
                else ret += HIW"━"NOR;
        }
        ret += fcolor + NOR ;
        return ret;
}
int help(object me)
{
        write(@HELP
指令格式：score
          score <对象名称>      （巫师专用）

显示自己或者指定对象（含怪物）的基本资料。此指令可以“sc”代替。

相关讯息：hp
HELP
        );

        return 1;
}
