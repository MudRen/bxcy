

// score.c
// Hzgg@HXQXZ
#include <ansi.h>
#include <combat.h>
#include <mudlib.h>
inherit F_CLEAN_UP;
string display_attr(int gift, int value);
string bar_string = "■■■■■■■■■■■■■■■■";
string blank_string = "□□□□□□□□□□□□□□□□";
string none_string = "                                  ";
string display_attr(int gift, int value);
string tribar_graph(int val, int eff, int max, string color);
int check_cc(string str);
void create() { seteuid(ROOT_UID); }
int main(object me, string arg)
{
         string line,my_str,my_dex,my_con,my_int,my_kar,my_per,skill_type,master,couple,killer;
         mapping my,pmap;
         object ob, weapon;
         int i, cc_len, attack_points, dodge_points, parry_points,balance;
//         seteuid(getuid(me));
         seteuid(getuid());
         if(!arg)
                 ob = me;
         else if (wizardp(me)) {
                 ob = present(arg, environment(me));
                 if (!ob) ob = find_player(arg);
                 if (!ob) ob = find_living(arg);
                 if (!ob) return notify_fail("你要察看谁的状态？\n");
                 if( !ob->is_character() || ob->is_corpse() )
                         return notify_fail("你不会连" + ob->query("name") + "的状态都想看吧？。\n");
 } else if (me->query("id")!="snow")
                 return notify_fail("只有巫师能察看别人的状态。\n");
         balance = (int)me->query("money")+(int)me->query("more_money")*10000*10000;
         my = ob->query_entire_dbase();
         my_str = display_attr(my["str"], ob->query_str());
         my_con = display_attr(my["con"], ob->query_con());
         my_int = display_attr(my["int"], ob->query_int());
         my_dex = display_attr(my["dex"], ob->query_dex());
         my_kar = display_attr(my["kar"], ob->query_kar());
         my_per = display_attr(my["per"], ob->query_per());
         killer = ob->query("kill/killer_die") ? " [" + ob->query("kill/killer_name") + "] 之手":"你还没被人杀过";
         pmap = me->query_skill_prepare();
         if( objectp(weapon = me->query_temp("weapon")) )
                skill_type = weapon->query("skill_type");
         else if ( sizeof(pmap) == 0) skill_type = "unarmed";
         else if ( sizeof(pmap) == 1) skill_type = (keys(pmap))[0];
         else if ( sizeof(pmap) == 2) 
                 {
                         if ( (keys(pmap))[0] >= (keys(pmap))[1] )
                                 skill_type = (keys(pmap))[0];
                         else skill_type = (keys(pmap))[1];
                 }
         attack_points = COMBAT_D->skill_power(ob, skill_type, SKILL_USAGE_ATTACK);
         parry_points = COMBAT_D->skill_power(ob, skill_type, SKILL_USAGE_DEFENSE);
         dodge_points = COMBAT_D->skill_power(ob, "dodge", SKILL_USAGE_DEFENSE);
         master = ob->query("family")?my["family"]["master_name"]:"目前还没有" ;
         couple = mapp(my["couple"])?(my["couple"]["have_couple"]?my["couple"]["couple_name"]:"目前还没有"):"目前还没有";
         line = "\n┏━━━━━"+HIW"【个人档案】"NOR"━━━━┓ "+MAG"\t\t"+"    天赋"NOR"\n";
         line += sprintf("%-32s┃%s\n",
         "┃",
         CYN"       膂力：["NOR+my_str+CYN"]     悟性：["NOR+my_int+CYN"] "NOR
         );
         line += sprintf("%s%-17s     ┃%s\n",
         "┃ 头  衔 :    ",RANK_D->query_rank(ob),
         CYN"       根骨：["NOR+my_con+CYN"]     身法：["NOR+my_dex+CYN"]"NOR
         );
        if( wizardp(me) || (int)ob->query("age") >= 18 ) 
         line += sprintf("%s%-16s┃%s\n",
         "┃中文姓名:     ",ob->name(),       

         CYN"       福缘：["NOR+my_kar+CYN"]     容貌：["NOR+my_per+CYN"]"NOR);
        else
         line += sprintf("%s%-16s┃%s\n",
         "┃中文姓名:     ",ob->name(),       
         CYN"       福缘：[???]     容貌：[???]"NOR);

         line += sprintf("%s%-16s%39s\n",
         "┃英文姓名:     ",ob->query("id"),"┗━━━━━━━━━━━━━━━━━━━━┓" );
         if( ob->query("title") )
         { 
            if( ob->query("degree") )
            {  
                 line += sprintf("%s%-58s",
                 "┃ 称  谓 :     ",ob->query("degree")+ob->query("title"));
                 for (i=0,cc_len=check_cc(ob->query("degree")+ob->query("title"));i<cc_len;i++)
                 {
                      line += sprintf("%s"," ");
                 }
                 line += sprintf("%s","┃\n");
            }
            else
            {
                 line += sprintf("%s%-58s",
                 "┃ 称  谓 :     ",ob->query("title"));
                 for (i=0,cc_len=check_cc(ob->query("title"));i<cc_len;i++)
                 {
                     line += sprintf("%s"," ");
                 }
                 line += sprintf("%s","┃\n");
            }
           } 
         if( ob->query("nickname") )
         {
                 line += sprintf("%s%-58s",
                 "┃你的别称:     ",ob->query("nickname")
                 );

                 for (i=0,cc_len=check_cc(ob->query("nickname"));i<cc_len;i++) {
                         line += sprintf("%s"," ");
                 }
                 line += sprintf("%s","┃\n");
         }

        if (userp(ob))
         line += sprintf("%s%-19s%s%-28s┃\n",
         "┃ 年  龄 :     ",chinese_number(ob->query("age"))+"岁"

         +chinese_number((ob->query("mud_age")-(ob->query("age")-14)*86400)/7200+1)+"月","你的生辰 ：",
         CHINESE_D->chinese_date(((int)ob->query("birthday") - 14*365*24*60*60) )
         );
        else 
         line += sprintf("%s%-19s%s%-28s┃\n",
         "┃ 年  龄 :     ",chinese_number(ob->query("age"))+"岁","你的生辰 ：",
         CHINESE_D->chinese_date(((int)ob->query("birthday") - 14*365*24*60*60))
         );
         
         line += sprintf("%s%-19s%12s%-26s┃\n",
         "┃ 性  别 ：    ", ob->query("gender"),
         "钱庄存款 ：  ",MONEY_D->money_str(balance));
         line += sprintf("%s%-35s%s%-26s┃\n",
                 "┃你共杀生 ：   ",HIR+(my["MKS"] + my["PKS"])+NOR+" 次",
                 "你的师傅 ：  ",master
                 );
         line += sprintf("%s%-35s%s%-26s┃\n",
                "┃你共杀了 ：   ",HIC+my["PKS"]+NOR+" 个玩家",
   
              "你的"+(ob->query("gender")=="男性"?"老婆":"老公")+" ：  ",couple  
         );
         line += sprintf("%s%-35s%s"HIR"%-37s"NOR"┃\n",
                 "┃你共死亡 ：   ",HIB+ob->query("DIED")+NOR + " 次",
                 "被其他玩家杀了 ： ",HIR+chinese_number(ob->query("PKD"))+NOR+" 次",

                 );                      
         line += sprintf("%s"HIW"%-19s"NOR"%s%-46s┃\n",
                 "┃攻 击 力 ：   ",
                 attack_points/50+1+" (+"+ob->query_temp("apply/damage")+")",
                  "食物 ：",tribar_graph(my["food"], ob->max_food_capacity(),ob->max_food_capacity(),YEL)
                );
         line += sprintf("%s"HIC"%-19s"NOR"%s%-46s┃\n",
                "┃躲闪能力 ：   ",dodge_points/50+1+"","饮水 ：",
                tribar_graph(my["water"], ob->max_water_capacity(), ob->max_water_capacity(),CYN)
                );
         line += sprintf("%s"HIW"%-19s"NOR"%s%-46s┃\n",
                 "┃防 御 力 ：   ",
                 (dodge_points + (weapon? parry_points: (parry_points/10)))/50 + 1+" (+"+ob->query_temp("apply/armor")+")",
                 "<精> ：",tribar_graph(my["jing"], my["eff_jing"], my["max_jing"],GRN)
                 );
         line += sprintf("%s"HIC"%-19s"NOR"%s%-45s┃\n",
                "┃招架能力 ：   ",parry_points/50+1+"","<气> ：",
                tribar_graph(my["qi"], my["eff_qi"], my["max_qi"], HIR)
                );
        if (ob->query("shen") ==0)
         line += sprintf("%s"RED"%-13s"NOR"%s"HIM"%-13s"NOR"%s"HIY"%-12s"NOR"┃\n",
         "┃   神   ：    ",ob->query("shen")+"","实战经验 ：",ob->query("combat_exp")+"",
         "潜  能 ：",(int)ob->query("potential") - (int)ob->query("learned_points")+
         " ("+(1 + (int)ob->query("learned_points")) * 100 / (1 + (int)ob->query("potential"))+"%)",
         ); 
        else
        if (ob->query("shen") >0)
         line += sprintf("%s"RED"%-13s"NOR"%s"HIM"%-13s"NOR"%s"HIY"%-12s"NOR"┃\n",
         "┃ 正 神  ：    ",ob->query("shen")+"","实战经验 ：",ob->query("combat_exp")+"",
         "潜  能 ：",(int)ob->query("potential") - (int)ob->query("learned_points")+
         " ("+(1 + (int)ob->query("learned_points")) * 100 / (1 + (int)ob->query("potential"))+"%)",
         );
        else
         line += sprintf("%s"RED"%-13s"NOR"%s"HIM"%-13s"NOR"%s"HIY"%-12s"NOR"┃\n",
         "┃ 负 神  ：    ",ob->query("shen")+"","实战经验 ：",ob->query("combat_exp")+"",
         "潜  能 ：",(int)ob->query("potential") - (int)ob->query("learned_points")+
         " ("+(1 + (int)ob->query("learned_points")) * 100 / (1 + (int)ob->query("potential"))+"%)",
         );
         line
 += sprintf("%s"RED"%-13s"NOR"%s"HIM"%-13s"NOR"%s"HIY"%-12s"NOR"┃\n",
                "┃综合评价 ：   ",ob->query("score")+"",
                "江湖威望 ：",display_attr(my["weiwang"],ob->query("weiwang")),
                "魅力值 ：",display_attr(my["meili"],ob->query("meili"))
         );
         line +="┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n"NOR;


        line += sprintf(WHT+" %s在"+HIG+CHINESE_MUD_NAME+NOR+"里的游戏时间是:"+BLINK+HIY"%s \n\n"+NOR,ob==me?"你":ob->name(1),FINGER_D->age_string( (int)ob->query("mud_age")));
         
          line+=sprintf("\n");
          write(line);
         return 1;
}
string display_attr(int gift, int value)
{
         if( value > gift ) return sprintf( HIY "%3d" NOR, value );
         else if( value < gift ) return sprintf( CYN "%3d" NOR, value );
         else return sprintf("%3d", value);
 }

string tribar_graph(int val, int eff, int max, string color)
{
         return color + bar_string[0..(val*16/max)*2-1]
                 + ((eff > val) ? blank_string[(val*16/max)*2..(eff*16/max)*2-1] : "")
                 + ((max > eff) ? none_string[(eff*16/max)*2..31] : "") +NOR;
}
int check_cc(string str)
{
         int i, nn_len;
         for (nn_len=0,i=0;i<strlen(str);i++) {
                 if (str[i]==27)
                 {
                         for (;str[i]!=109;i++)
                         {
                                 nn_len++;
                         }
                         nn_len++;
                 }
         }
         return nn_len;
}
