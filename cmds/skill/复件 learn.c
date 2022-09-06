// learn.c
#pragma save_binary
#include <skill.h>
inherit F_CLEAN_UP;
string *reject_msg = ({
	"˵������̫�����ˣ�����ô�ҵ���\n",
	"�����ܳ�����һ����˵������̣�����ô�ҵ���\n",
	"Ц��˵��������Ц�ˣ��������С�������ʸ�ָ�㡹��ʲô��\n",
});
void create() { seteuid(getuid()); }
int main(object me, string arg)
{
        string skill, teacher, skill_name;
	object ob;
	int master_skill, my_skill, gin_cost, grade, my_combat_exp;
     reset_eval_cost();
	if (me->is_busy())
		return notify_fail("��������æ���ء�\n");
	if(!arg || arg=="?" || arg=="/?")
		return notify_fail("ָ���ʽ��learn <ĳ��> <����>\tlearn <����> from <ĳ��>\n");
	if ((sscanf(arg, "%s from %s", skill,teacher)!=2 ))
		if ((sscanf(arg, "%s %s", teacher, skill)!=2 ))
			return notify_fail("ָ���ʽ��learn <ĳ��> <����>\tlearn <����> from <ĳ��>\n");
	if( me->is_fighting() )
		return notify_fail("����ĥǹ������������\n");
	if( !(ob = present(teacher, environment(me))) || !ob->is_character())
		return notify_fail("��Ҫ��˭��̣�\n");
	if( ob==me )
		return notify_fail("��....�������һ���Լ�������˵��\n");
	if( skill == "taixuan-gong" )
                 return notify_fail("�������ֻ������\n");	
	if( !living(ob) )
		return notify_fail("��....����Ȱ�" + ob->name() + "Ū����˵��\n");
	if( !me->is_apprentice_of(ob) && !(ob->recognize_apprentice(me)) )
		if (me->query("marry")!=ob->query("id") || ob->query("marry")!=me->query("id"))
		return	notify_fail( ob ->name() + reject_msg[random(sizeof(reject_msg))] );
	if( !master_skill = ob->query_skill(skill, 1) )
		return notify_fail("���������±����ұ���ѧ�ˡ�\n");
	if (ob->is_fighting())
		return notify_fail("ʦ��æ��������ˣ�û������Ү��\n");
	my_skill = me->query_skill(skill, 1);
	if (ob->prevent_learn(me,my_skill))
		return notify_fail(ob->name() + "��Ը���������ܡ�\n");
	if( my_skill >= master_skill )
		return notify_fail("�������ĳ̶��Ѿ�������ʦ���ˡ�\n");
	if( !SKILL_D(skill)->valid_learn(me) ) return SKILL_D(skill)->valid_learn(me);
	gin_cost = 150 / (int)me->query_int() + 1;
	if( !my_skill ) {
		gin_cost *= 2;
		me->set_skill(skill,0);
	}
	if( (int)me->query("learned_points") >= (int)me->query("potential") )
		return notify_fail("���Ǳ���Ѿ����ӵ������ˣ�û�а취�ٳɳ��ˡ�\n");
	printf("����%s����йء�%s�������ʡ�\n", ob->name(), to_chinese(skill));
	if( ob->query("env/no_teach") )
		return notify_fail("����" + ob->name() + "���ڲ���׼���ش�������⡣\n");
	tell_object(ob, sprintf("%s��������йء�%s�������⡣\n",
		me->name(), to_chinese(skill)));
	if( (int)ob->query("jing") > gin_cost/5 + 1 )
	{
		if( userp(ob) ) ob->receive_damage("jing", gin_cost/5 + 1);
		else	ob->receive_damage("jing", gin_cost/10+1);
	}
	else
	{
		write("����" + ob->name() + "��Ȼ̫���ˣ�û�а취����ʲ�ᡣ\n");
		tell_object(ob, "������̫���ˣ�û�а취��" + me->name() + "��\n");
		return 1;
	}
		
	my_combat_exp = (int)me->query("combat_exp");
	if(my_combat_exp < 10000)
		grade = 1;
	else if(my_combat_exp < 80000)
		grade = 3;
	else if(my_combat_exp < 500000)
		grade = 7;
	else
		grade = 13;
	if ( grade < 1 )
		grade = 1;
	if((int)me->query("jing") > gin_cost )
	{
		if( (string)SKILL_D(skill)->type()=="martial"
		&&	my_skill * my_skill * my_skill / 10 > (int)me->query("combat_exp") ) {
			printf("Ҳ����ȱ��ʵս���飬���%s�Ļش������޷���ᡣ\n", ob->name() );
		}
		else
		{
			if(skill_name = SKILL_D(skill)->query_skill_name(my_skill))
				printf("������%s��ָ�����ԡ�%s����һ���ƺ���Щ�ĵá�\n", ob->name(),
					skill_name);
			else
				printf("������%s��ָ�����ƺ���Щ�ĵá�\n", ob->name());
			me->add("learned_points", 1);
			me->improve_skill(skill, grade * (10 + random((int)me->query_int() - 9)));
		}
	}
	else
	{
		gin_cost = me->query("jing");
		write("�����̫���ˣ����ʲôҲû��ѧ����\n");
	}
	me->receive_damage("jing", gin_cost );
	return 1;
}
int help(object me)
{
        write(@HELP
ָ���ʽ : learn <ĳ��> <����>
 
���ָ������������������й�ĳһ�ּ��ܵ��������⣬��Ȼ������̵Ķ�������
����ϵ�����������ߣ����㾭�����ַ�ʽѧϰ�����ļ���Ҳ�����ܸ��������
�̵��ˣ�Ȼ����Ϊ����ѧϰ��ʽ�൱�һ�֡�����Ĵ��С������ѧϰ����˵����Ϥ
һ���¼������ķ�����
����ѧϰҲ��Ҫ����һЩ�����������ĵľ��������Լ�������ѧϰ����������йء�
�������ָ�� : teach, apprentice, practice, skills, study
HELP
        );
        return 1;
}
