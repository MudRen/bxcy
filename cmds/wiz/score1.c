// COMMAND score.c
// Create by qingren@����Ц
// Last modified by kittt@����Ц Jan.27.2000

#include <ansi.h>
#include <combat.h>

inherit F_CLEAN_UP;

string bar_string = "����������������������������������";
string sub_string = "����������������������������������";
string blk_string =   "                                  ";
string blank_string = "����������������������������������";

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
		if (!ob) return notify_fail("��Ҫ�쿴˭��״̬��\n");
	} else if (ob != me)
		return notify_fail("ֻ����ʦ�ܲ쿴���˵�״̬��\n");
	my = ob->query_entire_dbase();
     line = "\n��������������"HIW"��"HIY"�������"HIW"���ĵ�����"NOR"���������ש�������������������������������������\n";

	line += sprintf("��ͷ    �Σ�  %s              ��%s           %s��\n",
			RANK_D->query_rank(ob),
			HIW"��    ����"NOR,
         	"���ʣ���"+display_attr(my["spi"], ob->query_spi())+"��");
       line += sprintf("����    �ݣ�  %s" + fill_blank(remove_ansi(my["title"])) + "��%s      %s��\n",
                        my["title"]?my["title"]:"��",
                        "��������"+display_attr(my["str"], ob->query_str())+"��",
                        "���ԣ���"+display_attr(my["int"], ob->query_int())+"��");
	temp = my["nickname"]?my["nickname"]:"��";
		line += sprintf("����    �ţ�  ��%s��" + fill_blank(remove_ansi("��"+temp+"��")) + "��%s      %s��\n",
				temp,
                      "���ǣ���"+display_attr(my["con"], ob->query_con())+"��",
			    "������"+display_attr(my["dex"], ob->query_dex())+"��");
	temp = (my["color"]?my["color"]:"")+my["name"]+NOR+"("+capitalize(my["id"])+")";
	line += sprintf("����    ����  %s" + fill_blank(remove_ansi(temp)) + "����������������������������������������\n",temp);                

	ob->update_age();
	temp = chinese_number(my["age"])+"��"+(my["month"]?chinese_number(my["month"])+"����":"");
	line += sprintf("����    �䣺  %s" + fill_blank(temp) + "�������֣�  %-26s��\n", temp, CHINESE_D->chinese_date((my["birthday"] - 14*365*24*60) * 60));

	temp = ob->query("family/family_name")?my["family"]["family_name"]:"��";
	temp += ob->query("family/master_name")?my["family"]["master_name"]:"";
	
	line += sprintf("����    ��  %s" + fill_blank(my["gender"]) + "ʦ    ����  %-26s         ��\n", my["gender"],temp+NOR);

	if(!my["degree"]) temp = "û��";
		else temp = "��"+my["degree"]+"��";
	line += sprintf("��ѧ    λ��  %s" + fill_money(remove_ansi(temp))+"��\n",temp);

	if (my["divorce"]) temp = "����";
	else temp = "δ��";
        if( mapp(my["couple"]) ) {
                if (ob->query("couple/couple_name"))
			temp = "���"+(my["gender"]=="Ů��"?"�ɷ�":"����")+"��"
		+my["couple"]["couple_name"]+"("+capitalize(my["couple"]["couple_id"])+")";
	};
		if( ob->query_temp("marry") ) 
			temp = "���"+ ( my["gender"]=="Ů��"?"δ���":"δ����" )+"��"+ob->query_temp("marry")->name(1);

	line += sprintf("������״����  %s" + fill_blank(temp) , temp);
	line += "����" + tribar_graph(my["jing"], my["eff_jing"], my["max_jing"], HIY)+ "��\n";

	temp = my["jiebai_name"]?my["jiebai_name"]:"��";
	line += sprintf("�������ң�  %s" + fill_blank(temp),temp ); 		
	line += "��Ѫ" + tribar_graph(my["qi"], my["eff_qi"], my["max_qi"], HIR) + "��\n";

	temp = my["MKS"]+my["PKS"]?HIR+chinese_number(my["MKS"] + my["PKS"])+"λ"+NOR :"�㵽ĿǰΪֹ��ûɱ����";
	line += sprintf("���ܹ�ɱ�ˣ�  %s" + fill_blank(remove_ansi(temp)), temp);
	line += "����" + tribar_graph  (my["jingli"], my["eff_jingli"], my["eff_jingli"],    HIG) + "��\n";
	
	temp = my["PKS"]?HIB+chinese_number(my["PKS"])+"λ"+NOR:"û��";
	line += sprintf("���У���ң�  %s" + fill_blank(remove_ansi(temp)), temp);
	line += "����" + tribar_graph(my["neili"], my["max_neili"], my["max_neili"], HIB) + "��\n";
	
	line += sprintf("��%-10s%-26d" NOR, my["shen"] < 0?HIB"��    ����  ":HIC"��    ����  ", (my["shen"] < 0?-1:1)*my["shen"]);
	line += "ʳ��" + tribar_graph(my["food"], ob->max_food_capacity(), ob->max_food_capacity(), HIM) + "��\n";
	
	temp =  my["death_count"]?chinese_number(my["death_count"])+"��":"��";
	line += sprintf("������������  %s" + fill_blank(temp), temp);
	line += "��ˮ" + tribar_graph(my["water"], ob->max_water_capacity(), ob->max_water_capacity(), HIC) + "��\n";

	line += sprintf("��%-10s%-26d"NOR, "����������  "HIY,my["combat_exp"]);
	line += "Ǳ��" + tribar_graph(my["potential"], my["max_pot"], my["max_pot"], HIW) + "��\n";

	temp="";
	temp += my["balance"]/10000? chinese_number(my["balance"]/10000)+"��"HIY"�ƽ�"NOR:"";
	temp += my["balance"]/100-my["balance"]/10000*100? chinese_number(my["balance"]/100-my["balance"]/10000*100)+"��"HIW"����"NOR:"";
	temp += my["balance"]-my["balance"]/10000*10000-(my["balance"]/100-my["balance"]/10000*100)*100?chinese_number(my["balance"]-my["balance"]/10000*10000-(my["balance"]/100-my["balance"]/10000*100)*100)+"��"HIG"ͭǮ"NOR:"";

	if (my["balance"]<=0) temp = "��Ŀǰ��Ǯׯ��û�д�";

	line += sprintf("��Ǯׯ��  %s" + fill_money(remove_ansi(temp))+"��\n",temp);

	line += "��������������������������������������������������������������������������������\n";
	
	if (wizardp(me)) {
		line += HIY" �������� (WIZ������������͸©)��\n"NOR;
		line += sprintf("  ��ò��"HIY"%s"NOR"��      ��Ե��"HIY"%s"NOR"��      ���ӡ�"HIY"%s"NOR"��\n",
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
		line += sprintf("  ���� " HIW "%d(+%d)" NOR " ���� " HIW "%d" NOR " ���� " HIW "%d(+%d)\n" NOR,
				attack_points/100, ob->query_temp("apply/damage"),
				dodge_points/100,
				parry_points/100, ob->query_temp("apply/armor"));
		if (!(my["mud_age"]/3600)) 
		{ }
		else {
			temp  = "�ٸ�("+(my["gf_job"]?my["gf_job"]:"��")+")";
			temp += "  Ľ��("+(my["mr_job"]?my["mr_job"]:"��")+")";
			temp += " ��ػ�("+(my["tiandihui/join"]?my["tiandihui/job"]:"��")+")";
			temp += "  ����("+(my["mingjiao_job"]?my["mingjiao_job"]:"��")+")";
			line += sprintf("  ��������(��)��"+temp+"\n");
			temp = (string)((int)my["combat_exp"]/(((int)my["mud_age"])/3600));
			line += sprintf("  ÿСʱ��þ��飺"+temp+"\n");
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
ָ���ʽ : score
           score <��������>            (��ʦר��)

���ָ�������ʾ���ָ������(��NPC)�Ļ������ϡ�

see also : hp
HELP
);
return 1;
}
