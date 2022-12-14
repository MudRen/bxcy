// COMMAND score.c
// Create by qingren@刀剑笑
// Last modified by kittt@刀剑笑 Jan.27.2000

#include <ansi.h>
#include <combat.h>

inherit F_CLEAN_UP;

string bar_string = "■■■■■■■■■■■■■■■■■";
string sub_string = "▏▏▏▏▎▍▌▋▊▏▏▏▏▏▏▏▉";
string blk_string =   "                                  ";
string blank_string = "□□□□□□□□□□□□□□□□□";

string display_attr(int gift, int value);
string tribar_graph(int val, int eff, int max, string color);
string fill_blank(string type);
string fill_money(string type);

string remove_ansi(string str)
{
	int i;
	string *color = ({ BLK, RED, GRN, YEL, BLU, MAG, CYN, WHT,
			HIR, HIG, HIY, HIB, HIM, HIC, HIW,
			HBRED, HBGRN, HBYEL, HBBLU, HBMAG, HBCYN, HBWHT,
			BBLK, BRED, BYEL, BBLU, BMAG, BCYN,
			NOR, BOLD });
			
	if( !str || !stringp(str) ) return 0;
	i = sizeof(color);
	while( i-- ) {
		str = replace_string(str, color[i], "");
	}
	return str;
}

void create() { seteuid(ROOT_UID); }
int main(object me, string arg)
{
	object ob;
	mapping my;
	string line ,temp ,skill_type;
	object weapon;
	int attack_points, dodge_points, parry_points;

	seteuid(getuid(me));
	if(!arg)
		ob = me;
	else
		ob = present(arg, environment(me));
	if (wizardp(me)) {
		if (!ob) ob = find_player(arg);
		if (!ob) ob = find_living(arg);
		if (!ob) return notify_fail("你要察看谁的状态？\n");
	} else if (ob != me)
		return notify_fail("只有巫师能察看别人的状态。\n");
	my = ob->query_entire_dbase();
     line = "\n┏━━━━━━"HIW"【"HIY"豪侠晚歌"HIW"您的档案】"NOR"━━━━┳━━━━━━━━━━━━━━━━━━┓\n";

	line += sprintf("┃头    衔：  %s              ┃%s           %s┃\n",
			RANK_D->query_rank(ob),
			HIW"天    赋："NOR,
         	"资质：「"+display_attr(my["spi"], ob->query_spi())+"」");
       line += sprintf("┃身    份：  %s" + fill_blank(remove_ansi(my["title"])) + "┃%s      %s┃\n",
                        my["title"]?my["title"]:"无",
                        "膂力：「"+display_attr(my["str"], ob->query_str())+"」",
                        "悟性：「"+display_attr(my["int"], ob->query_int())+"」");
	temp = my["nickname"]?my["nickname"]:"无";
		line += sprintf("┃绰    号：  「%s」" + fill_blank(remove_ansi("「"+temp+"」")) + "┃%s      %s┃\n",
				temp,
                      "根骨：「"+display_attr(my["con"], ob->query_con())+"」",
			    "身法：「"+display_attr(my["dex"], ob->query_dex())+"」");
	temp = (my["color"]?my["color"]:"")+my["name"]+NOR+"("+capitalize(my["id"])+")";
	line += sprintf("┃姓    名：  %s" + fill_blank(remove_ansi(temp)) + "┗━━━━━━━━━━━━━━━━━━┫\n",temp);                

	ob->update_age();
	temp = chinese_number(my["age"])+"岁"+(my["month"]?chinese_number(my["month"])+"个月":"");
	line += sprintf("┃年    龄：  %s" + fill_blank(temp) + "生辰八字：  %-26s┃\n", temp, CHINESE_D->chinese_date((my["birthday"] - 14*365*24*60) * 60));

	temp = ob->query("family/family_name")?my["family"]["family_name"]:"无";
	temp += ob->query("family/master_name")?my["family"]["master_name"]:"";
	
	line += sprintf("┃性    别：  %s" + fill_blank(my["gender"]) + "师    父：  %-26s         ┃\n", my["gender"],temp+NOR);

	if(!my["degree"]) temp = "没有";
		else temp = "〖"+my["degree"]+"〗";
	line += sprintf("┃学    位：  %s" + fill_money(remove_ansi(temp))+"┃\n",temp);

	if (my["divorce"]) temp = "离异";
	else temp = "未婚";
        if( mapp(my["couple"]) ) {
                if (ob->query("couple/couple_name"))
			temp = "你的"+(my["gender"]=="女性"?"丈夫":"妻子")+"是"
		+my["couple"]["couple_name"]+"("+capitalize(my["couple"]["couple_id"])+")";
	};
		if( ob->query_temp("marry") ) 
			temp = "你的"+ ( my["gender"]=="女性"?"未婚夫":"未婚妻" )+"是"+ob->query_temp("marry")->name(1);

	line += sprintf("┃婚姻状况：  %s" + fill_blank(temp) , temp);
	line += "精神" + tribar_graph(my["jing"], my["eff_jing"], my["max_jing"], HIY)+ "┃\n";

	temp = my["jiebai_name"]?my["jiebai_name"]:"无";
	line += sprintf("┃结拜玩家：  %s" + fill_blank(temp),temp ); 		
	line += "气血" + tribar_graph(my["qi"], my["eff_qi"], my["max_qi"], HIR) + "┃\n";

	temp = my["MKS"]+my["PKS"]?HIR+chinese_number(my["MKS"] + my["PKS"])+"位"+NOR :"你到目前为止还没杀过人";
	line += sprintf("┃总共杀人：  %s" + fill_blank(remove_ansi(temp)), temp);
	line += "精力" + tribar_graph  (my["jingli"], my["eff_jingli"], my["eff_jingli"],    HIG) + "┃\n";
	
	temp = my["PKS"]?HIB+chinese_number(my["PKS"])+"位"+NOR:"没有";
	line += sprintf("┃ＰＫ玩家：  %s" + fill_blank(remove_ansi(temp)), temp);
	line += "内力" + tribar_graph(my["neili"], my["max_neili"], my["max_neili"], HIB) + "┃\n";
	
	line += sprintf("┃%-10s%-26d" NOR, my["shen"] < 0?HIB"戾    气：  ":HIC"正    气：  ", (my["shen"] < 0?-1:1)*my["shen"]);
	line += "食物" + tribar_graph(my["food"], ob->max_food_capacity(), ob->max_food_capacity(), HIM) + "┃\n";
	
	temp =  my["death_count"]?chinese_number(my["death_count"])+"次":"无";
	line += sprintf("┃死亡次数：  %s" + fill_blank(temp), temp);
	line += "饮水" + tribar_graph(my["water"], ob->max_water_capacity(), ob->max_water_capacity(), HIC) + "┃\n";

	line += sprintf("┃%-10s%-26d"NOR, "江湖阅历：  "HIY,my["combat_exp"]);
	line += "潜能" + tribar_graph(my["potential"], my["max_pot"], my["max_pot"], HIW) + "┃\n";

	temp="";
	temp += my["balance"]/10000? chinese_number(my["balance"]/10000)+"两"HIY"黄金"NOR:"";
	temp += my["balance"]/100-my["balance"]/10000*100? chinese_number(my["balance"]/100-my["balance"]/10000*100)+"两"HIW"白银"NOR:"";
	temp += my["balance"]-my["balance"]/10000*10000-(my["balance"]/100-my["balance"]/10000*100)*100?chinese_number(my["balance"]-my["balance"]/10000*10000-(my["balance"]/100-my["balance"]/10000*100)*100)+"文"HIG"铜钱"NOR:"";

	if (my["balance"]<=0) temp = "你目前在钱庄里没有存款。";

	line += sprintf("┃钱庄存款：  %s" + fill_money(remove_ansi(temp))+"┃\n",temp);

	line += "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
	
	if (wizardp(me)) {
		line += HIY" 隐含属性 (WIZ不得随便向玩家透漏)：\n"NOR;
		line += sprintf("  容貌「"HIY"%s"NOR"」      福缘「"HIY"%s"NOR"」      纯朴「"HIY"%s"NOR"」\n",
			chinese_number(ob->query_per()),
			chinese_number(ob->query_kar()),
			chinese_number(my["pur"]));
		if(objectp(weapon = ob->query_temp("weapon")) ) skill_type = weapon->query("skill_type");
		else {
			mapping prepare = ob->query_skill_prepare();
			
			if (!sizeof(prepare)) skill_type = "unarmed";
			else skill_type = keys(prepare)[0];
		}
		
		attack_points = COMBAT_D->skill_power(ob, skill_type, SKILL_USAGE_ATTACK);
		parry_points = COMBAT_D->skill_power(ob, "parry", SKILL_USAGE_DEFENSE);
		dodge_points = COMBAT_D->skill_power(ob, "dodge", SKILL_USAGE_DEFENSE);
		line += sprintf("  攻击 " HIW "%d(+%d)" NOR " 躲闪 " HIW "%d" NOR " 防御 " HIW "%d(+%d)\n" NOR,
				attack_points/100, ob->query_temp("apply/damage"),
				dodge_points/100,
				parry_points/100, ob->query_temp("apply/armor"));
		if (!(my["mud_age"]/3600)) 
		{ }
		else {
			temp  = "官府("+(my["gf_job"]?my["gf_job"]:"无")+")";
			temp += "  慕容("+(my["mr_job"]?my["mr_job"]:"无")+")";
			temp += " 天地会("+(my["tiandihui/join"]?my["tiandihui/job"]:"无")+")";
			temp += "  明教("+(my["mingjiao_job"]?my["mingjiao_job"]:"无")+")";
			line += sprintf("  任务数量(次)："+temp+"\n");
			temp = (string)((int)my["combat_exp"]/(((int)my["mud_age"])/3600));
			line += sprintf("  每小时获得经验："+temp+"\n");
		}
	}
	write(line);
	return 1;
}

string display_attr(int gift, int value)
{
	string str;
	if (value > gift) str = HIY;
	else if (value < gift) str = CYN;
	return str + value + NOR + "/" + gift;
}

string fill_blank(string type)
{
	string bak;
	int i, j;

	bak="";
	i=strlen(type);
	for (j=0; j<26-i; j++ )
		bak+=" ";
	return bak;
}

string fill_money(string type)
{
	string bak;
	int i, j;

	bak="";
	i=strlen(type);
	for (j=0; j<64-i; j++ )
		bak+=" ";
	return bak;
}

string tribar_graph(int val, int eff, int max, string color)
{
	int sub,i,j;
	
	if (eff < val) eff = val;
	if (max < eff) max = eff;
	if (!max) return "                                  ";
	sub = val * 17 / max;
	color += bar_string[0..sub*2-1] + BMAG;
	sub = val * 136 / max;
	sub %= 8;
	sub += sub;
	if (sub) color += sub_string[sub-2..sub-1];
	if (sub) sub = 2;
	color += blk_string[val*17/max*2+sub..eff*17/max*2-1]+NOR;
	i = strlen(remove_ansi(color));
	for (j=0;j < 34 - i ; j++)
		color +=" ";
	return sprintf("%-34s",color);
}

int help(object me)
{
write(@HELP
指令格式 : score
           score <对象名称>            (巫师专用)

这个指令可以显示你或指定对象(含NPC)的基本资料。

see also : hp
HELP
);
return 1;
}
