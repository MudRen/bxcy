// taiji-quan.c 太极拳
// 增加不同技能级别相应的学习和能使出的招数名, by ReyGod, in 12/17/1996
//      query_skill_name() and query_action()
inherit SKILL;
mapping *action = ({
([  "action" : "$N使一招「"+YEL+"揽雀尾"+NOR+"」，双手划了个半圈，按向$n的$l",
    "force" : 100,
    "skill_name" : YEL "揽雀尾" NOR,
    "lvl" : 0,
    "damage_type" : "瘀伤"
]),
([  "action" : "$N使一招「"+RED+"单鞭"+NOR+"」，右手收置肋下，左手向外挥出，劈向$n的$l",
    "force" : 120,
    "skill_name" : RED "单鞭" NOR,
    "lvl" : 5,
    "damage_type" : "瘀伤"
]),
([  "action" : "$N左手回收，右手由钩变掌，由右向左，使一招「"+HIB+"提手上式"+NOR+"」，向$n的$l打去",
    "force" : 140,
    "skill_name" : HIB "提手上式" NOR,
    "lvl" : 10,
    "damage_type" : "瘀伤"
]),
([  "action" : "$N双手划弧，右手向上，左手向下，使一招「"+WHT+"白鹤亮翅"+NOR+"」，分击$n的面门和$l",
    "force" : 160,
    "skill_name" : WHT "白鹤亮翅" NOR,
    "lvl" : 15,
    "damage_type" : "瘀伤"
]),
([  "action" : "$N左手由胸前向下，身体微转，划了一个大圈，使一招「"+HIR+"搂膝拗步"+NOR+"」，击向$n的$l",
    "force" : 180,
    "skill_name" : HIR "搂膝拗步" NOR,
    "lvl" : 20,
    "damage_type" : "瘀伤"
]),
([  "action" : "$N左手由下上挑，右手内合，使一招「"+HIG+"手挥琵琶"+NOR+"」，向$n的$l打去",
    "force" : 200,
    "skill_name" : HIG "手挥琵琶" NOR,
    "lvl" : 25,
    "damage_type" : "瘀伤"
]),
([  "action" : "$N左手变掌横于胸前，右拳由肘下穿出，一招「"+HIY+"肘底看锤"+NOR+"」，锤向$n的$l",
    "force" : 220,
    "skill_name" : HIY "肘底看锤" NOR,
    "lvl" : 30,
    "damage_type" : "瘀伤"
]),
([  "action" : "$N左脚前踏半步，右手使一招「"+HIB+"海底针"+NOR+"」，指由下向$n的$l戳去",
    "force" : 240,
    "skill_name" : HIB "海底针" NOR,
    "lvl" : 35,
    "damage_type" : "瘀伤"
]),
([  "action" : "$N一招「"+HIM+"闪通臂"+NOR+"」，左脚一个弓箭步，右手上举向外撇出，向$n的$l挥去",
    "force" : 260,
    "skill_name" : HIM "闪通臂" NOR,
    "lvl" : 40,
    "damage_type" : "瘀伤"
]),
([  "action" : "$N两手由相对，转而向左上右下分别挥出，右手使一招「"+HIC+"斜飞式"+NOR+"」，挥向$n的$l",
    "force" : 280,
    "skill_name" : HIC "斜飞式" NOR,
    "lvl" : 45,
    "damage_type" : "瘀伤"
]),
([  "action" : "$N左手虚按，右手使一招「"+HIW+"白蛇吐信"+NOR+"」，向$n的$l插去",
    "force" : 300,
    "skill_name" : HIW "白蛇吐信" NOR,
    "lvl" : 50,
    "damage_type" : "瘀伤"
]),
([  "action" : "$N双手握拳，向前向后划弧，一招「"+BLK+"双峰贯耳"+NOR+"」打向$n的$l",
    "force" : 320,
    "skill_name" : BLK "双风贯耳" NOR,
    "lvl" : 55,
    "damage_type" : "瘀伤"
]),
([  "action" : "$N左手虚划，右手一记「"+RED+"勾裆锤"+NOR+"」击向$n的裆部",
    "force" : 340,
    "skill_name" : RED "指裆锤" NOR,
    "lvl" : 60,
    "damage_type" : "瘀伤"
]),
([  "action" : "$N施出「"+GRN+"伏虎式"+NOR+"」，右手击向$n的$l，左手攻向$n的裆部",
    "force" : 360,
    "skill_name" : GRN "伏虎式" NOR,
    "lvl" : 65,
    "damage_type" : "瘀伤"
]),
([  "action" : "$N由臂带手，在面前缓缓划过，使一招「"+YEL+"云手"+NOR+"」，挥向$n的$l",
    "force" : 380,
    "skill_name" : YEL "云手" NOR,
    "lvl" : 70,
    "damage_type" : "瘀伤"
]),
([  "action" : "$N左腿收起，右手使一招「"+BLU+"金鸡独立"+NOR+"」，向$n的$l击去",
    "force" : 400,
    "skill_name" : BLU "金鸡独立" NOR,
    "lvl" : 75,
    "damage_type" : "瘀伤"
]),
([  "action" : "$N右手由钩变掌，双手掌心向上，右掌向前推出一招「"+MAG+"高探马"+NOR+"」",
    "force" : 420,
    "skill_name" : MAG "高探马" NOR,
    "lvl" : 80,
    "damage_type" : "瘀伤"
]),
([  "action" : "$N右手使一式招「"+CYN+"玉女穿梭"+NOR+"」，扑身向$n的$l插去",
    "force" : 440,
    "skill_name" : CYN "玉女穿梭" NOR,
    "lvl" : 85,
    "damage_type" : "瘀伤"
]),
([  "action" : "$N右手经腹前经左肋向前撇出，使一招「"+WHT+"反身撇锤"+NOR+"」，向$n的$l锤去",
    "force" : 460,
    "skill_name" : WHT "反身撇锤" NOR,
    "lvl" : 90,
    "damage_type" : "瘀伤"
]),
([  "action" : "$N左手虚按，右腿使一招「"+HIR+"转身蹬腿"+NOR+"」，向$n的$l踢去",
    "force" : 480,
    "skill_name" : HIR "反身蹬腿" NOR,
    "lvl" : 95,
    "damage_type" : "瘀伤"
]),
([  "action" : "$N左手向上划弧拦出，右手使一招「"+HIG+"搬拦锤"+NOR+"」，向$n的$l锤去",
    "force" : 500,
    "skill_name" : HIG "白蛇吐信" NOR,
    "lvl" : 100,
    "damage_type" : "瘀伤"
]),
([  "action" : "$N使一招「"+HIY+"栽锤"+NOR+"」，左手搂左膝，右手向下锤向$n的$l",
    "force" : 520,
    "skill_name" : HIY "栽锤" NOR,
    "lvl" : 110,
    "damage_type" : "瘀伤"
]),
([  "action" : "$N双手先抱成球状，忽地分开右手上左手下，一招「"+HIB+"野马分鬃"+NOR+"」，向$n的$l和面门打去",
    "force" : 480,
    "skill_name" : HIB "野马分鬃" NOR,
    "lvl" : 120,
    "damage_type" : "瘀伤"
]),
([  "action" : "$N左手由胸前向下，右臂微曲，使一招「"+HIM+"抱虎归山"+NOR+"」，向$n的$l推去",
    "force" : 500,
    "skill_name" : HIM "抱虎归山" NOR,
    "lvl" : 130,
    "damage_type" : "瘀伤"
]),
([  "action" : "$N双手经下腹划弧交于胸前，成十字状，一式「"+HIC+"十字手"+NOR+"」，向$n的$l打去",
    "force" : 520,
    "skill_name" : HIC "十字手" NOR,
    "lvl" : 140,
    "damage_type" : "瘀伤"
]),
([  "action" : "$N左脚踏一个虚步，双手交叉成十字拳，一招「"+HIW+"进步七星"+NOR+"」，向$n的$l锤去",
    "force" : 540,
    "skill_name" : HIW "进步七星" NOR,
    "lvl" : 150,
    "damage_type" : "瘀伤"
]),
([  "action" : "$N身体向后腾出，左手略直，右臂微曲，使一招「"+BLK+"倒撵猴"+NOR+"」，向$n的$l和面门打去",
    "force" : 560,
    "skill_name" : BLK "倒撵猴" NOR,
    "lvl" : 160,
    "damage_type" : "瘀伤"
]),
([  "action" : "$N双手伸开，以腰为轴，整个上身划出一个大圆弧，\n一招「"+RED+"转身摆莲"+NOR+"」，将$n浑身上下都笼罩在重重掌影之中",
    "force" : 580,
    "skill_name" : RED "转身摆莲" NOR,
    "lvl" : 170,
    "damage_type" : "瘀伤"
]),
([  "action" : "$N双手握拳，右手缓缓收至耳际，左手缓缓向前推出，\n拳意如箭，一招「"+GRN+"弯弓射虎"+NOR+"」，直奔$n心窝而去",
    "force" : 600,
    "skill_name" : GRN "弯弓射虎" NOR,
    "lvl" : 180,
    "damage_type" : "瘀伤"
]),
([  "action" : "$N双手在胸前翻掌，由腹部向前向上推出，一招「"+YEL+"如封似闭"+NOR+"」，一股劲风直逼$n",
    "force" : 620,
    "skill_name" : YEL "如封似闭" NOR,
    "lvl" : 200,
    "damage_type" : "瘀伤"
]),
});
int valid_enable(string usage) { return usage=="unarmed" || usage=="parry"; }
int practice_level(){   return 200;  }
int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("练太极拳必须空手。\n");
    if ((int)me->query_skill("taiji-shengong", 1) <= me->query_skill("taiji-quan", 1))
        return notify_fail("你的太极神功火候不够，无法学太极拳。\n");
    if ((int)me->query("max_neili") < 100)
        return notify_fail("你的内力太弱，无法练太极拳。\n");
    if (me->query_skill("unarmed", 1) <=me->query_skill("taiji-quan", 1))
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
    level   = (int) me->query_skill("taiji-quan", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action = action[NewRandom(i, 5, level/5)];
                        break;
                }
    a_action["dodge"]  = 0-level/3;
    a_action["parry"]  = 0-level/3;
    a_action["attack"]  = level/3;
    a_action["damage"] = level/2;
    return a_action;

}
int practice_skill(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("练太极拳必须空手。\n");
    if ((int)me->query("qi") < 30)
        return notify_fail("你的体力太低了。\n");
    if ((int)me->query("neili") < 20)
        return notify_fail("你的内力不够练太极拳。\n");
    me->receive_damage("qi", 25);
    me->add("neili", -10);
    return 1;
}
string perform_action_file(string action)
{
    return __DIR__"taiji-quan/" + action;
}
