// yunlong-jian.c 云龙剑
inherit SKILL;
mapping *action = ({
([  "action":"\n$N使一式「"+YEL+"悠悠顺自然"+NOR+"」，手中$w嗡嗡微振，幻成一条白光刺向$n的$l",
    "force" : 120,
    "lvl" : 0,
    "skill_name" : YEL "悠悠顺自然" NOR,
    "damage_type":  "刺伤"
]),
([  "action":"\n$N错步上前，使出「"+MAG+"春染一片绿"+NOR+"」，剑意若有若无，$w淡淡地向$n的$l挥去",
    "force" : 140,
    "lvl" : 8,
    "skill_name" : MAG "来去若梦行" NOR,
    "damage_type":  "割伤"
]),
([  "action":"\n$N一式「"+WHT+"志当存高远"+NOR+"」，纵身飘开数尺，运发剑气，手中$w遥摇指向$n的$l",
    "force" : 160,
    "lvl" : 15,
    "skill_name" : WHT "志当存高远" NOR,
    "damage_type":  "刺伤"
]),
([  "action":"$N纵身轻轻跃起，一式「"+HIR+"表里俱澄澈"+NOR+"」，剑光如水，一泻千里，洒向$n全身",
    "force" : 180,
    "lvl" : 20,
    "skill_name" : HIR "表里俱澄澈" NOR,
    "damage_type":  "割伤"
]),
([  "action":"$N手中$w中宫直进，一式「"+BLU+"随风潜入夜"+NOR+"」，无声无息地对准$n的$l刺出一剑",
    "force" : 220,
    "lvl" : 30,
    "skill_name" : BLU "随风潜入夜" NOR,
    "damage_type":  "刺伤"
]),
([  "action":"$N手中$w一沉，一式「"+HIB+"润物细无声"+NOR+"」，无声无息地滑向$n的$l",
    "force" : 250,
    "lvl" : 40,
    "skill_name" : HIB "润物细无声" NOR,
    "damage_type":  "割伤"
]),
([  "action":"\n$N手中$w斜指苍天，剑芒吞吐，一式「"+WHT+"河山万木春"+NOR+"」，对准$n的$l斜斜击出",
    "force" : 280,
    "lvl" : 50,
    "skill_name" : WHT "云龙听梵音" NOR,
    "damage_type":  "刺伤"
]),
([  "action":"$N左指凌空虚点，右手$w逼出丈许雪亮剑芒，一式「"+RED+"万里一点红"+NOR+"」刺向$n的$l",
    "force" : 320,
    "lvl" : 60,
    "skill_name" : RED "万里一点红" NOR,
    "damage_type":  "刺伤"
]),
([  "action":"$N合掌跌坐，一式「"+HIM+"我心化云龙"+NOR+"」，$w自怀中跃出，如疾电般射向$n的$l",
    "force" : 380,
    "lvl" : 70,
    "skill_name" : HIM "我心化云龙" NOR,
    "damage_type":  "刺伤"
]),
([  "action":"\n$N呼的一声拔地而起，一式「"+HIG+"日月与同辉"+NOR+"」，$w幻出万道光影，将$n团团围住",
    "force" : 420,
    "lvl" : 80,
    "skill_name" : HIG "日月与同辉" NOR,
    "damage_type":  "内伤"
]),
([  "action":"$N随风轻轻飘落，一式「"+GRN+"清风知我意"+NOR+"」，手中$w平指，缓缓拍向$n脸颊",
    "force" : 450,
    "lvl" : 90,
    "skill_name" : GRN "清风知我意" NOR,
    "damage_type":  "内伤"
]),
([  "action" : "$N剑尖微颤作龙吟，一招「"+HIW+"高处不胜寒"+NOR+"」，切骨剑气如飓风般裹向$n全身",
    "force" : 500,
    "lvl" : 100,
    "skill_name" : HIW "高处不胜寒" NOR,
    "damage_type":  "内伤"
]),
([  "action" : "$N募的使一招「"+MAG+"红叶舞秋山"+NOR+"」，顿时剑光中几朵血花洒向$n全身",
    "force" : 500,
    "lvl" : 110,
    "skill_name" : MAG "红叶舞秋山" NOR,
    "damage_type":  "内伤"
]),
});
int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }
int practice_level(){   return 110;  }
int valid_learn(object me)
{
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "sword")
    if (!objectp(weapon = me->query_temp("secondary_weapon"))
    || (string)weapon->query("skill_type") != "sword")
        return notify_fail("你必须先找把剑才能学剑法。\n");
    if ((int)me->query("max_neili") < 200)
        return notify_fail("你的内力不够。\n");
    if ((int)me->query_skill("yunlong-xinfa", 1) < 20)
        return notify_fail("你的云龙心法火候太浅。\n");
    if ((int)me->query_skill("force", 1) < 40)
        return notify_fail("你的基本内功火候太浅。\n");
    if (me->query_skill("sword", 1) <=me->query_skill("yunlong-jian", 1))
        return notify_fail("你的基础不够，无法领会更高深的技巧。\n");
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
    mapping a_action;
    int i, level;
    level   = (int) me->query_skill("yunlong-jian",1);
    for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action=action[NewRandom(i, 20, level/5)];
                       break;
                 }
    a_action["dodge"]  = 0-level/2;
    a_action["parry"]  = 0-level/3;
    a_action["attack"]  = level/2;
    a_action["damage"] = level/2;
    return a_action;
}

int practice_skill(object me)
{
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "sword")
    if (!objectp(weapon = me->query_temp("secondary_weapon"))
    || (string)weapon->query("skill_type") != "sword")
        return notify_fail("你使用的武器不对。\n");
    if ((int)me->query("qi") < 50)
        return notify_fail("你的体力不够练云龙剑法。\n");
    me->receive_damage("qi", 25);
    return 1;
}
string perform_action_file(string action)
{
    return __DIR__"yunlong-jian/" + action;
}
