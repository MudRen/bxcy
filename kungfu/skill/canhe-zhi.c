// canhe-zhi.c �κ�ָ
#include <ansi.h>;
inherit SKILL;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});



mapping *action = ({
([      "action" : "$N���缤����˫ָ������ã�һ��"+(order[random(13)])+"��Ŀ��ʶ����"NOR"�׺ݵ���$n��$l��ȥ",
        "force" : 100,
        "dodge" : 5,
        "damage": 10,
		"lvl" : 0,
		"weapon" : "ָ��",
        "skill_name" : "Ŀ��ʶ��",
        "damage_type" : "����"
]),
([      "action" : "$N���һ����ʮָ���·ַɣ�һ��"+(order[random(13)])+"�������㾦��"NOR"��˫ֱָȡ$n��$l",
        "force" : 130,
        "dodge" : 8,
		"damage": 15,
		"weapon" : "ָ��",
        "lvl" : 20,
        "skill_name" : "�����㾦",
        "damage_type" : "����"
]),
([      "action" : "$Nʮָ���������ʵ��һ��"+(order[random(13)])+"����˷���롹"NOR"��ǰ�����ң�˲Ϣ����$n����������",
        "force" : 170,
        "dodge" : 5,
		"damage": 20,
		"weapon" : "ָ��",
        "lvl" : 40,
        "skill_name" : "��˷����",
        "damage_type" : "����",
]),
([      "action" : "$N�����ڿն���һ��"+(order[random(13)])+"���ܳ�������"NOR"��������죬��$n��$l�Ͳ���ȥ",
        "force" : 200,
        "dodge" : 0,
        "damage": 25,
		"weapon" : "ָ��",
		"lvl" : 60,
        "skill_name" : "�ܳ�����",
        "damage_type" : "����"
]),
([      "action" : "$N����һ�������������ߵ�$n��ǰ��һ��"+(order[random(13)])+"�����ϲ�����"NOR"������$n��$l",
        "force" : 220,
        "dodge" : 15,
		"damage": 30,
		"weapon" : "ָ��",
        "lvl" : 70,
        "skill_name" : "���ϲ���",
        "damage_type" : "����"
]),
([      "action" : "$Nһ��"+(order[random(13)])+"���˱����᡹"NOR"������һȭ���������ƻ�ָ��һ��һָ��ջ���$n��$l",
        "force" : 300,
        "dodge" : 20,
        "lvl" : 80,
        "skill_name" : "�˱�����",
        "damage_type" : "����"
]),
([      "action" : "$N˫�ƻ�ָ��ָ�д��ƣ�˫�����ƣ�һ��"+(order[random(13)])+"����н������"NOR"��һ����ɽ������������ֱ��$n$l",
        "force" : 360,
        "dodge" : -5,
        "lvl" : 90,
        "skill_name" : "��н����",
        "damage_type" : "����"
]),
([      "action" : "$NͻȻ���м�ת��һ��"+(order[random(13)])+"�����μ���"NOR"��ʮָ���裬��ʱ֮�佫$n����˷�����ס��",
        "force" : 420,
        "dodge" : -15,
        "lvl" : 100,
        "skill_name" : "���μ�",
        "damage_type" : "����"
]),
});

int valid_combine(string combo)  
{
         object me = this_player();
         mapping myfam = (mapping)me->query("family");
         if ( myfam["master_name"] == "Ľ�ݲ�")
                 return combo=="xingyi-zhang";
}
int valid_enable(string usage) { return usage=="finger" || usage=="parry" || usage=="unarmed"; }	


int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("���κ�ָ������֡�\n");
        if ((int)me->query_skill("shenyuan-gong", 1) < 15)
                return notify_fail("�����Ԫ����򲻹����޷�ѧ�κ�ָ��\n");
        if ((int)me->query("max_neili") < 100)
                return notify_fail("�������̫�����޷����κ�ָ��\n");
        return 1;
}

string query_skill_name(int level)
{
        int i = sizeof(action);

        while (i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
        if (random(me->query_dex()) >= 25 && me->query_skill("canhe-zhi",1) > 200 &&
             me->query_skill("parry",1) > 80 
             && random(10)>5
             ) {
                me->add("neili", -30);
                return ([
                "action": HIY "$NĬ����Ԫ�񹦣�ָ����ƮƮ�ص���$n��һ���ھ�������Ϣ������$n�����Ѩ��"NOR,
                "force": 550,
                "dodge": 35,
                "damage": 535,
                "damage_type": "����"]);
        }
        if (random(me->query_dex()) >= 30 && me->query_skill("canhe-zhi",1)> 200 &&
                me->query_skill("parry",1) > 120 
                && random(10)>5){
                me->add("qi",-30);            
                me->add("neili", -50);
                return ([
                "action": HIY "$Nָ��Ϭ������һ�����ν�������$n�������ڣ�$nֻ����ǰ����������ãȻ��֪���롣"NOR,
                "force": 580,
                "dodge": 45,
                "damage": 535,
                "damage_type": "����"]);
        }
        level   = (int) me->query_skill("canhe-zhi",1);
        for(i = sizeof(action); i > 0; i--)
        if(level > action[i-1]["lvl"])
        return action[NewRandom(i, 20, level/5)];
}
int practice_skill(object me)
{
        int lvl = me->query_skill("canhe-zhi", 1);
        int i = sizeof(action);
        mapping learned = me->query_learned();

        if (!mapp(learned)) learned = ([]);
        if (!learned["canhe-zhi"])
                while (i--) if (lvl == action[i]["lvl"]) return 0;

        if ((int)me->query("jing") < 30)
                return notify_fail("��ľ���̫���ˡ�\n");
        if ((int)me->query("neili") < 10)
                return notify_fail("��������������κ�ָ��\n");
        me->receive_damage("jing", 20);
        me->add("neili", -10);
		return 1;
}
string perform_action_file(string action)
{
        return __DIR__"canhe-zhi/" + action;
}
