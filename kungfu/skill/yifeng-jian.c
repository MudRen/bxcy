// yifeng-jian.c 移风剑法

inherit SKILL;

mapping *action = ({
([      "action":"$N使一式「花随风移」，手中$w嗡嗡微振，幻成一无数花瓣刺向$n的$l",
        "force" : 30,
        "dodge" : 10,
        "damage": 100,
        "lvl" : 0,
        "skill_name" : "花随风移",
        "damage_type":  "刺伤"
]),
([      "action":"$N移步上前，使出「雨花纷飞」，剑气围绕，$w淡淡地向$n的$l挥去",
        "force" : 40,
        "dodge" : 10,
        "damage": 150,
        "lvl" : 9,
        "skill_name" : "雨花纷飞",
        "damage_type":  "割伤"
]),
([      "action":"$N一式「花起剑落」，纵身飘开数尺，运发剑气，手中$w遥遥飞向$n的$l",
        "force" : 60,
        "dodge" : 50,
        "damage" : 200,
        "lvl" : 18,
        "skill_name" : "花起剑落",
        "damage_type":  "割伤"
]),
([      "action":"$N纵身轻轻跃起，一式「紫花飞舞」，剑光化为紫色，飘向$n的$l",
        "force" : 80,
        "dodge" : 90,
        "damage": 250,
        "lvl" : 27,
        "skill_name" : "紫花飞舞",
        "damage_type":  "割伤"
]),
([      "action":"$N手中$w中宫直进，一式「花开花谢」，无声无息地对准$n的$l刺出一剑",
        "force" : 100,
        "dodge" : 120,
        "damage": 300,
        "lvl" : 36,
        "skill_name" : "花开花谢",
        "damage_type":  "刺伤"
]),
([      "action":"$N手中$w斜指苍天，剑芒吞吐，一式「飞花落叶」，对准$n的$l斜斜击出",
        "force" : 110,
        "dodge" : 150,
        "damage": 350,
        "lvl" : 44,
        "skill_name" : "飞花落叶",
        "damage_type":  "刺伤"
]),
([      "action":"$N左指凌空虚点，右手$w逼出丈许雪亮剑芒，一式「春回大地」刺向$n的$l",
        "force" : 120,
        "dodge" : 200,
        "damage": 400,
        "lvl" : 52,
        "skill_name" : "春回大地",
        "damage_type":  "刺伤"
]),
([      "action":"狂风大起,只见花瓣到处飞舞,突然无数花瓣割向$n,$n顿时鲜血直喷",
        "force" : 180,
        "dodge" : 250,
        "damage": 900,
        "lvl" : 150,
        "skill_name" : "移风起栖云飞扬",
        "damage_type":  "刺伤"
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }

int valid_learn(object me)
{
    if ( me->query("gender") != "女性")
       return notify_fail("相传移风剑法乃女娲所创,从无男子练习!\n");
        if ((int)me->query("max_neili") < 500)
                return notify_fail("你的内力不够。\n");
        if ((int)me->query_skill("mingyu-shengong", 1) < 120)
                return notify_fail("你的冥雨神功火候太浅。\n");
if ((int)me->query_skill("yifeng-jian", 1) >= (int)me->query_skill("sword",1))	
return notify_fail("你的基础不够.\n");	
        return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level   = (int) me->query_skill("yifeng-jian",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;
        if ( me->query("gender") != "女性")
        return notify_fail("相传移风剑法乃女娲所创,从无男子练习!\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");
        if ((int)me->query_skill("mingyu-shengong", 1) < 420)
                return notify_fail("你的冥雨神功火候太浅。\n");
        if ((int)me->query("qi") < 50)
                return notify_fail("你的体力不够练移风剑法。\n");
        me->receive_damage("qi", 25);
        return 1;
}
string perform_action_file(string action)
{
        return __DIR__"yifeng-jian/" + action;
}

