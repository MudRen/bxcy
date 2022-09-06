#include <ansi.h>;
inherit SKILL;
string  *msg = ({
BLU"$N���۸�����ĿԶ���������鸡����ǰ�Ż�������ȫ����������ѧ�и�
�����޲��Ǻϡ�$n��һ���ɣ�������Ϊ$N�������ơ�"NOR,
BLU"$Nһ��[ �ľ����� ]��С�����������ͬʱ�ؿ�����������ٿ�ص���ӭ��
$n��˫ȭ��"NOR,
BLU"$Nһʽ[ ������� ]��̧ͷ���죬��$n��������������������һ������
��ͷ���տ��ĳ�������б�£��������ɻ��Σ���ɢ����£ס$nȫ��"NOR,
BLU"$NͻȻ�����붯��һʽ[ �������� ]�������䣬˫��ͷ���������ر�����
��������ʽ��������һ���������ˡ�"NOR,
BLU"$Nһʽ[ �����ˮ ]����������Ʈ����������ˮ������ȴ����֮��������
���ż�ǧ����ɳһ�㣬��������ɱ����ֱ��$n��$l��"NOR,
BLU"$N��Ӱ��ת������Ȱ��ǰ����˲��˲�ң�һʽ[ �ǻ��չ� ]�Ʒ�����
$n��$l��"NOR,
BLU"$N��̾һ������ɣƣ�����������أ�ȴ��һ��[ �������� ]���յ�$nȫ
������֮�ʣ�����ֱ�����Ŵ�Ѩ��"NOR,
BLU"$N��Ŀ��Ȼ����ֱ֫ͦ���������ۣ�����[ ��ʬ���� ]�㣬���۽��ȣ���
նֱ��$n��$l��"NOR,
BLU"$Nһʽ[ ӹ������ ]�����ִ��أ�һ�߻��ײ�ֹ������ȴҲ��ٿ�����Ƶ�
�����������㱩��$n�ĺ��ġ�"NOR,
BLU"$NͻȻͷ�½��ϣ��������ӣ������������У��ִ����У������ֹ���˫��
����δ����˫�ֻ������������$n�����̡�"NOR,
BLU"$N��Ȼ��Ц��ֹ�����ֵ߿�������Ц���䣬$n���������䶯�����Գ���
���$N��һ�ȹ���$n��$l��"NOR,
BLU"ȴ��$N����������˫�ֺ�ʮ��Ĭ�̾��ģ��������Ƴ��ְ�������У�ƾ��
����$n,�������ˣ��޷�Ӳ�ӡ�"NOR,
});

int valid_enable(string usage)
{
	return usage == "unarmed" || usage == "parry";
}
mapping query_action(object me)
{
	return ([
		"action":msg[random(sizeof(msg))],
		"damage":(random(4)+1)*100,
		"damage_type":random(2)?"����":"����",
		"dodge":200,
		"force":450
	]);
}

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("����Ȼ�����Ʊ�����֡�\n");
	if (me->query_skill_mapped("force") != "yunu-xinjing")
		return notify_fail("����Ȼ�����Ʊ�������Ů�ľ���ϡ�\n");
	if ((int)me->query_skill("yunu-xinjing", 1) < 100)
		return notify_fail("�����Ů�ľ���򲻹����޷�����Ȼ�����ơ�\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������̫�����޷�����Ȼ�����ơ�\n");
	return 1;
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 30)
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("���������������Ȼ�����ơ�\n");
	me->receive_damage("qi", 30);
	me->add("neili", -10);
	return 1;
}
