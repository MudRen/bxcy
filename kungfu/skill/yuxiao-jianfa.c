// yuxiao-jianfa
// by victori
inherit SKILL;
mapping *action = ({
([      "action":"$N怀抱$w，跨前一步身形微沉左膝略曲，剑势如匹的攻向$n，正是一招「"+RED+"百鸟朝凰"+NOR+"」。",
        "force" : 120,
        "dodge" : -10,
        "damage": 20,
        "lvl" : 0,
        "skill_name" : "百鸟朝凰",
        "damage_type":  "刺伤"
]),
([      "action":"$N横过$w一式「"+CYN+"垄玉吹萧"+NOR+"」横切$n的颈部，攻势奇幻之极。",
        "force" : 140,
        "dodge" : -10,
        "damage": 30,
        "lvl" : 9,
        "skill_name" : "垄玉吹萧",
        "damage_type":  "割伤"
]),
([      "action":"$N脚下踏着八卦方位，$w以一式「"+YEL+"清羽之音"+NOR+"」中宫直进，势如破竹攻向$n胸口。",
        "force" : 160,
        "dodge" : 5,
        "damage": 40,
        "lvl" : 18,
        "skill_name" : "清羽之音",
        "damage_type":  "刺伤"
]),
([      "action":"$N手中$w去势弱有若无般挑向$n右肩，却是一招「"+BLK+"一音奚奚"+NOR+"」。",
        "force" : 180,
        "dodge" : 10,
        "damage": 55,
        "lvl" : 27,
        "skill_name" : "一音奚奚",
        "damage_type":  "刺伤"
]),
([      "action":"$N手中$w一抖正是一式「"+GRN+"昆岗凤鸣"+NOR+"」，只见那剑势忽高忽低，愈变愈奇刺向$n。",
        "force" : 220,
        "dodge" : 15,
        "damage": 60,
        "lvl" : 36,
        "skill_name" : "昆岗凤鸣",
        "damage_type":  "刺伤"
]),
([      "action":"只见$N身形一晃$w使出「"+BLU+"萧史乘龙"+NOR+"」如形随影的攻向$n后背。",
        "force" : 260,
        "dodge" : 5,
        "damage": 65,
        "lvl" : 44,
        "skill_name" : "萧史乘龙",
        "damage_type":  "刺伤"
]),
([      "action":"$N使出「"+MAG+"巴山夜雨"+NOR+"」迅速的抖动手中$w幻化出无数个光点，剑势如同暴风骤雨般的攻向$n。",
        "force" : 320,
        "dodge" : 5,
        "damage": 70,
        "lvl" : 52,
        "skill_name" : "巴山夜雨",
        "damage_type":  "刺伤"
]),
([      "action":"$N一声长叹使出「"+RED+"曲终人散"+NOR+"」，长袖一挥只见$w从重重袖影中飞出，点向$n的咽喉要害，随及身形飘然离去。",
        "force" : 380,
        "dodge" : 5,
        "damage": 80,
        "lvl" : 60,
        "skill_name" : "曲终人散",
        "damage_type":  "刺伤"
]),
});
int valid_enable(string usage) { return (usage == "sword") || (usage == "parry")
; }
int valid_learn(object me)
{
    if (((int)me->query("max_neili") < 1000) ||
        ((int)me->query_skill("bibo-shengong", 1) < 100) ||
        !(me->query("couple/have_couple")))
       return notify_fail("黄药师说道: 玉箫剑法，只付有缘。你不是性情中人。\n");
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
       return notify_fail("你使用的武器不对。\n");
    if ((int)me->query("qi") < 50)
       return notify_fail("你的体力不够练玉箫剑法。\n");
    me->receive_damage("qi", 30);
    return 1;
}
string perform_action_file(string action)
{
    return __DIR__"yuxiao-jianfa/" + action;
}
