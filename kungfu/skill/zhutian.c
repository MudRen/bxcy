// written by cuer
inherit SKILL;
string *dodge_msg = ({
	"ֻ��$nһ�С�������������������������ϱ�ֱ��Ʈ�����࣬�����$N��һ�С�\n",
	"$nһ�������ͷ��������һ������󻬳�����֮Զ���ܿ���$N���������ơ�\n",
	"$nʹ������ع���������һ����һ��Ư���Ŀշ���Ʈ���ڵء�\n",
        "$nһ����Ц��ʹ�����������,�����أ���ӰƮ��������������$N���������ơ�\n",
        "$n��ȻһЦ��ʹ����ӥצ�ɡ�������Ʈ�����ɣ�ʹ$N�Ĺ�������ˡ�\n",
        "$nһ����Х��һ�С����¿ۡ���������𣬱ܹ�$N�Ĺ�����������$N�ı���\n",
});
int valid_enable(string usage) { return (usage == "dodge") || (usage == "move"); }
int valid_learn(object me) 
{ 
  if (me->query("class")!="bonze" && (int)me->query_skill("zhutian",1) >99 )
                return notify_fail("�����㲻�Ƿ������ˣ�����������������ŵĸ����书��\n");
  return 1; 
}
string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}
int practice_skill(object me)
{       
        if (me->query("class")!="bonze" && (int)me->query_skill("zhutian",1) >99 )
                return notify_fail("�����㲻�Ƿ������ˣ�����������������ŵĸ����书��\n");
        if( (int)me->query("qi") < 40 )
                return notify_fail("�������̫���ˣ����������컯����\n");
        me->receive_damage("qi", 30);
        return 1;
}
