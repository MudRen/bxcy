

// score.c
// Hzgg@HXQXZ
#include <ansi.h>
#include <combat.h>
#include <mudlib.h>
inherit F_CLEAN_UP;
string display_attr(int gift, int value);
string bar_string = "��������������������������������";
string blank_string = "��������������������������������";
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
                 if (!ob) return notify_fail("��Ҫ�쿴˭��״̬��\n");
                 if( !ob->is_character() || ob->is_corpse() )
                         return notify_fail("�㲻����" + ob->query("name") + "��״̬���뿴�ɣ���\n");
 } else if (me->query("id")!="snow")
                 return notify_fail("ֻ����ʦ�ܲ쿴���˵�״̬��\n");
         balance = (int)me->query("money")+(int)me->query("more_money")*10000*10000;
         my = ob->query_entire_dbase();
         my_str = display_attr(my["str"], ob->query_str());
         my_con = display_attr(my["con"], ob->query_con());
         my_int = display_attr(my["int"], ob->query_int());
         my_dex = display_attr(my["dex"], ob->query_dex());
         my_kar = display_attr(my["kar"], ob->query_kar());
         my_per = display_attr(my["per"], ob->query_per());
         killer = ob->query("kill/killer_die") ? " [" + ob->query("kill/killer_name") + "] ֮��":"�㻹û����ɱ��";
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
         master = ob->query("family")?my["family"]["master_name"]:"Ŀǰ��û��" ;
         couple = mapp(my["couple"])?(my["couple"]["have_couple"]?my["couple"]["couple_name"]:"Ŀǰ��û��"):"Ŀǰ��û��";
         line = "\n������������"+HIW"�����˵�����"NOR"���������� "+MAG"\t\t"+"    �츳"NOR"\n";
         line += sprintf("%-32s��%s\n",
         "��",
         CYN"       ������["NOR+my_str+CYN"]     ���ԣ�["NOR+my_int+CYN"] "NOR
         );
         line += sprintf("%s%-17s     ��%s\n",
         "�� ͷ  �� :    ",RANK_D->query_rank(ob),
         CYN"       ���ǣ�["NOR+my_con+CYN"]     ����["NOR+my_dex+CYN"]"NOR
         );
        if( wizardp(me) || (int)ob->query("age") >= 18 ) 
         line += sprintf("%s%-16s��%s\n",
         "����������:     ",ob->name(),       

         CYN"       ��Ե��["NOR+my_kar+CYN"]     ��ò��["NOR+my_per+CYN"]"NOR);
        else
         line += sprintf("%s%-16s��%s\n",
         "����������:     ",ob->name(),       
         CYN"       ��Ե��[???]     ��ò��[???]"NOR);

         line += sprintf("%s%-16s%39s\n",
         "��Ӣ������:     ",ob->query("id"),"��������������������������������������������" );
         if( ob->query("title") )
         { 
            if( ob->query("degree") )
            {  
                 line += sprintf("%s%-58s",
                 "�� ��  ν :     ",ob->query("degree")+ob->query("title"));
                 for (i=0,cc_len=check_cc(ob->query("degree")+ob->query("title"));i<cc_len;i++)
                 {
                      line += sprintf("%s"," ");
                 }
                 line += sprintf("%s","��\n");
            }
            else
            {
                 line += sprintf("%s%-58s",
                 "�� ��  ν :     ",ob->query("title"));
                 for (i=0,cc_len=check_cc(ob->query("title"));i<cc_len;i++)
                 {
                     line += sprintf("%s"," ");
                 }
                 line += sprintf("%s","��\n");
            }
           } 
         if( ob->query("nickname") )
         {
                 line += sprintf("%s%-58s",
                 "����ı��:     ",ob->query("nickname")
                 );

                 for (i=0,cc_len=check_cc(ob->query("nickname"));i<cc_len;i++) {
                         line += sprintf("%s"," ");
                 }
                 line += sprintf("%s","��\n");
         }

        if (userp(ob))
         line += sprintf("%s%-19s%s%-28s��\n",
         "�� ��  �� :     ",chinese_number(ob->query("age"))+"��"

         +chinese_number((ob->query("mud_age")-(ob->query("age")-14)*86400)/7200+1)+"��","������� ��",
         CHINESE_D->chinese_date(((int)ob->query("birthday") - 14*365*24*60*60) )
         );
        else 
         line += sprintf("%s%-19s%s%-28s��\n",
         "�� ��  �� :     ",chinese_number(ob->query("age"))+"��","������� ��",
         CHINESE_D->chinese_date(((int)ob->query("birthday") - 14*365*24*60*60))
         );
         
         line += sprintf("%s%-19s%12s%-26s��\n",
         "�� ��  �� ��    ", ob->query("gender"),
         "Ǯׯ��� ��  ",MONEY_D->money_str(balance));
         line += sprintf("%s%-35s%s%-26s��\n",
                 "���㹲ɱ�� ��   ",HIR+(my["MKS"] + my["PKS"])+NOR+" ��",
                 "���ʦ�� ��  ",master
                 );
         line += sprintf("%s%-35s%s%-26s��\n",
                "���㹲ɱ�� ��   ",HIC+my["PKS"]+NOR+" �����",
   
              "���"+(ob->query("gender")=="����"?"����":"�Ϲ�")+" ��  ",couple  
         );
         line += sprintf("%s%-35s%s"HIR"%-37s"NOR"��\n",
                 "���㹲���� ��   ",HIB+ob->query("DIED")+NOR + " ��",
                 "���������ɱ�� �� ",HIR+chinese_number(ob->query("PKD"))+NOR+" ��",

                 );                      
         line += sprintf("%s"HIW"%-19s"NOR"%s%-46s��\n",
                 "���� �� �� ��   ",
                 attack_points/50+1+" (+"+ob->query_temp("apply/damage")+")",
                  "ʳ�� ��",tribar_graph(my["food"], ob->max_food_capacity(),ob->max_food_capacity(),YEL)
                );
         line += sprintf("%s"HIC"%-19s"NOR"%s%-46s��\n",
                "���������� ��   ",dodge_points/50+1+"","��ˮ ��",
                tribar_graph(my["water"], ob->max_water_capacity(), ob->max_water_capacity(),CYN)
                );
         line += sprintf("%s"HIW"%-19s"NOR"%s%-46s��\n",
                 "���� �� �� ��   ",
                 (dodge_points + (weapon? parry_points: (parry_points/10)))/50 + 1+" (+"+ob->query_temp("apply/armor")+")",
                 "<��> ��",tribar_graph(my["jing"], my["eff_jing"], my["max_jing"],GRN)
                 );
         line += sprintf("%s"HIC"%-19s"NOR"%s%-45s��\n",
                "���м����� ��   ",parry_points/50+1+"","<��> ��",
                tribar_graph(my["qi"], my["eff_qi"], my["max_qi"], HIR)
                );
        if (ob->query("shen") ==0)
         line += sprintf("%s"RED"%-13s"NOR"%s"HIM"%-13s"NOR"%s"HIY"%-12s"NOR"��\n",
         "��   ��   ��    ",ob->query("shen")+"","ʵս���� ��",ob->query("combat_exp")+"",
         "Ǳ  �� ��",(int)ob->query("potential") - (int)ob->query("learned_points")+
         " ("+(1 + (int)ob->query("learned_points")) * 100 / (1 + (int)ob->query("potential"))+"%)",
         ); 
        else
        if (ob->query("shen") >0)
         line += sprintf("%s"RED"%-13s"NOR"%s"HIM"%-13s"NOR"%s"HIY"%-12s"NOR"��\n",
         "�� �� ��  ��    ",ob->query("shen")+"","ʵս���� ��",ob->query("combat_exp")+"",
         "Ǳ  �� ��",(int)ob->query("potential") - (int)ob->query("learned_points")+
         " ("+(1 + (int)ob->query("learned_points")) * 100 / (1 + (int)ob->query("potential"))+"%)",
         );
        else
         line += sprintf("%s"RED"%-13s"NOR"%s"HIM"%-13s"NOR"%s"HIY"%-12s"NOR"��\n",
         "�� �� ��  ��    ",ob->query("shen")+"","ʵս���� ��",ob->query("combat_exp")+"",
         "Ǳ  �� ��",(int)ob->query("potential") - (int)ob->query("learned_points")+
         " ("+(1 + (int)ob->query("learned_points")) * 100 / (1 + (int)ob->query("potential"))+"%)",
         );
         line
 += sprintf("%s"RED"%-13s"NOR"%s"HIM"%-13s"NOR"%s"HIY"%-12s"NOR"��\n",
                "���ۺ����� ��   ",ob->query("score")+"",
                "�������� ��",display_attr(my["weiwang"],ob->query("weiwang")),
                "����ֵ ��",display_attr(my["meili"],ob->query("meili"))
         );
         line +="����������������������������������������������������������������������������\n"NOR;


        line += sprintf(WHT+" %s��"+HIG+CHINESE_MUD_NAME+NOR+"�����Ϸʱ����:"+BLINK+HIY"%s \n\n"+NOR,ob==me?"��":ob->name(1),FINGER_D->age_string( (int)ob->query("mud_age")));
         
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
