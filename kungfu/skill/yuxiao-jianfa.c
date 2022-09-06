// yuxiao-jianfa
// by victori
inherit SKILL;
mapping *action = ({
([      "action":"$N����$w����ǰһ������΢����ϥ������������ƥ�Ĺ���$n������һ�С�"+RED+"���񳯻�"+NOR+"����",
        "force" : 120,
        "dodge" : -10,
        "damage": 20,
        "lvl" : 0,
        "skill_name" : "���񳯻�",
        "damage_type":  "����"
]),
([      "action":"$N���$wһʽ��"+CYN+"¢����"+NOR+"������$n�ľ������������֮����",
        "force" : 140,
        "dodge" : -10,
        "damage": 30,
        "lvl" : 9,
        "skill_name" : "¢����",
        "damage_type":  "����"
]),
([      "action":"$N����̤�Ű��Է�λ��$w��һʽ��"+YEL+"����֮��"+NOR+"���й�ֱ��������������$n�ؿڡ�",
        "force" : 160,
        "dodge" : 5,
        "damage": 40,
        "lvl" : 18,
        "skill_name" : "����֮��",
        "damage_type":  "����"
]),
([      "action":"$N����$wȥ���������ް�����$n�Ҽ磬ȴ��һ�С�"+BLK+"һ������"+NOR+"����",
        "force" : 180,
        "dodge" : 10,
        "damage": 55,
        "lvl" : 27,
        "skill_name" : "һ������",
        "damage_type":  "����"
]),
([      "action":"$N����$wһ������һʽ��"+GRN+"���ڷ���"+NOR+"����ֻ���ǽ��ƺ��ߺ��ͣ������������$n��",
        "force" : 220,
        "dodge" : 15,
        "damage": 60,
        "lvl" : 36,
        "skill_name" : "���ڷ���",
        "damage_type":  "����"
]),
([      "action":"ֻ��$N����һ��$wʹ����"+BLU+"��ʷ����"+NOR+"��������Ӱ�Ĺ���$n�󱳡�",
        "force" : 260,
        "dodge" : 5,
        "damage": 65,
        "lvl" : 44,
        "skill_name" : "��ʷ����",
        "damage_type":  "����"
]),
([      "action":"$Nʹ����"+MAG+"��ɽҹ��"+NOR+"��Ѹ�ٵĶ�������$w�û�����������㣬������ͬ���������Ĺ���$n��",
        "force" : 320,
        "dodge" : 5,
        "damage": 70,
        "lvl" : 52,
        "skill_name" : "��ɽҹ��",
        "damage_type":  "����"
]),
([      "action":"$Nһ����̾ʹ����"+RED+"������ɢ"+NOR+"��������һ��ֻ��$w��������Ӱ�зɳ�������$n���ʺ�Ҫ�����漰����ƮȻ��ȥ��",
        "force" : 380,
        "dodge" : 5,
        "damage": 80,
        "lvl" : 60,
        "skill_name" : "������ɢ",
        "damage_type":  "����"
]),
});
int valid_enable(string usage) { return (usage == "sword") || (usage == "parry")
; }
int valid_learn(object me)
{
    if (((int)me->query("max_neili") < 1000) ||
        ((int)me->query_skill("bibo-shengong", 1) < 100) ||
        !(me->query("couple/have_couple")))
       return notify_fail("��ҩʦ˵��: ���｣����ֻ����Ե���㲻���������ˡ�\n");
    return 1;
}
mapping query_action(object me, object weapon)
{
    int i, level;
    level   = (int) me->query_skill("yuxiao-jianfa",1);
    for(i = sizeof(action); i > 0; i--)
    if(level > action[i-1]["lvl"])
        return action[NewRandom(i, 20, level/5)];
}
int practice_skill(object me)
{
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "sword")
       return notify_fail("��ʹ�õ��������ԡ�\n");
    if ((int)me->query("qi") < 50)
       return notify_fail("����������������｣����\n");
    me->receive_damage("qi", 30);
    return 1;
}
string perform_action_file(string action)
{
    return __DIR__"yuxiao-jianfa/" + action;
}
