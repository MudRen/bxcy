// damo-jian.c 达摩剑
inherit SKILL;
mapping *action = ({
([  "action":"$N使一式「"+MAG+"万事随缘往"+NOR+"」，手中$w嗡嗡微振，幻成一条疾光刺向$n的$l",
    "force" : 120,
    "lvl" : 0,
    "skill_name" : MAG "万事随缘往" NOR,
    "damage_type":  "刺伤"
]),
([  "action":"$N错步上前，使出「"+HIB+"来去若梦行"+NOR+"」，剑意若有若无，$w淡淡地向$n的$l挥去",
    "force" : 140,
    "lvl" : 9,
    "skill_name" : HIB "来去若梦行" NOR,
    "damage_type":  "割伤"
]),
([  "action":"$N一式「"+HIG+"浮世沧桑远"+NOR+"」，纵身飘开数尺，运发剑气，手中$w遥摇指向$n的$l",
    "force" : 160,
    "lvl" : 18,
    "skill_name" : HIG "浮世沧桑远" NOR,
    "damage_type":  "割伤"
]),
([  "action":"$N纵身轻轻跃起，一式「"+WHT+"轮回法舟轻"+NOR+"」，剑光如轮疾转，霍霍斩向$n的$l",
    "force" : 180,
    "lvl" : 27,
    "skill_name" : WHT "轮回法舟轻" NOR,
    "damage_type":  "割伤"
]),
([  "action":"$N手中$w中宫直进，一式「"+RED+"水月通禅寂"+NOR+"」，无声无息地对准$n的$l刺出一剑",
    "force" : 220,
    "lvl" : 36,
    "skill_name" : RED "水月通禅寂" NOR,
    "damage_type":  "刺伤"
]),
([  "action":"$N手中$w斜指苍天，剑芒吞吐，一式「"+MAG+"鱼龙听梵音"+NOR+"」，对准$n的$l斜斜击出",
    "force" : 260,
    "lvl" : 44,
    "skill_name" : MAG "鱼龙听梵音" NOR,
    "damage_type":  "刺伤"
]),
([  "action":"$N左指凌空虚点，右手$w逼出丈许雪亮剑芒，一式「"+HIR+"千里一苇去"+NOR+"」刺向$n的$l",
    "force" : 320,
    "lvl" : 52,
    "skill_name" : HIR "千里一苇去" NOR,
    "damage_type":  "刺伤"
]),
([  "action":"$N合掌跌坐，一式「"+YEL+"禅心顿自明"+NOR+"」，$w自怀中跃出，如疾电般射向$n的胸口",
    "force" : 380,
    "lvl" : 60,
    "skill_name" : YEL "禅心顿自明" NOR,
    "damage_type":  "刺伤"
]),
});
int practice_level(){   return 60;  }
int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }
int valid_combine(string combo) { return combo=="xiuluo-dao"; }
int valid_learn(object me)
{
    if ((int)me->query("max_neili") < 150)
        return notify_fail("你的内力不够。\n");
    if (me->query_skill("sword", 1) <=me->query_skill("damo-jian", 1))
        return notify_fail("你的基础不够，无法领会更高深的技巧。\n");
    if ((int)me->query_skill("hunyuan-yiqi", 1) < 20)
    if ((int)me->query_skill("yijing-force", 1) < 20)
    if ((int)me->query_skill("jiuyang-shengong", 1) < 20)
    if ((int)me->query_skill("taiji-shengong", 1) < 20)
        return notify_fail("你的禅宗气功火候不够，无法学达摩剑。\n");

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
        level   = (int) me->query_skill("damo-jian",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action=action[NewRandom(i, 20, level/5)];
                       break;
                 }
    a_action["dodge"]  = 0-level/2;
    a_action["parry"]  = 0-level/2;
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
        return notify_fail("你的体力不够练达摩剑。\n");
    me->receive_damage("qi", 25);
    return 1;
}
string perform_action_file(string action)
{
    return __DIR__"damo-jian/" + action;
}
