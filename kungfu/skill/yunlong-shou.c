// yunlongshou.c -云龙手
inherit SKILL;
mapping *action = ({
([  "action" : "$N一式「"+GRN+"草木皆兵"+NOR+"」，十指伸缩，虚虚实实地袭向$n的全身要穴",
    "force" : 200,
    "lvl" : 0,
    "skill_name" : GRN "草木皆兵" NOR,
        "damage_type" : "抓伤"
]),
([  "action" : "在呼呼风声中，$N使一招「"+RED+"捕风捉影"+NOR+"」，双手如钩如戢，插向$n的$l",
    "force" : 250,
    "lvl"   : 20,
    "skill_name" : RED "捕风捉影" NOR ,     
    "damage_type" : "刺伤"
]),
([  "action" : "$N双拳挥舞，一式「"+HIY+"浮云去来"+NOR+"」，两手环扣，拢成圈状，猛击$n的下颌",
    "force" : 250,
    "lvl" : 30,
    "skill_name" : HIY "浮云去来" NOR,
        "damage_type" : "内伤"
]),
([  "action" : "$N双手平伸，十指微微上下抖动，一招「"+HIG+"十指乾坤"+NOR+"」打向$n的$l",
    "force" : 300,
    "lvl"   : 40,
    "skill_name" : HIG "十指乾坤" NOR ,     
    "damage_type" : "内伤"
]),
([  "action" : "$N左手护胸，腋下含空，右手五指如钩，一招「"+HIW+"抱残守缺"+NOR+"」插向$n的顶门",
    "force" : 260,
    "lvl"   : 50,
    "skill_name" : HIW "抱残守缺" NOR ,     
    "damage_type" : "内伤"
]),
([  "action" : "$N右腿斜插$n二腿之间，一招「"+HIB+"掏虚抢珠"+NOR+"」，上手取目，下手反勾$n的裆部",
    "force" : 300,
    "lvl"   : 60,
    "skill_name" : HIB "掏虚抢珠" NOR ,     
    "damage_type" : "内伤"
]),
([  "action" : "$N一手虚指$n的剑诀，一招「"+MAG+"空手入刃"+NOR+"」，劈空抓向$n手中的兵刃",
    "force" : 350,
    "lvl"   : 70,
    "skill_name" : MAG "空手入刃" NOR ,     
    "damage_type" : "抓伤"
]),
([  "action" : "$N左手指向$n胸前的五道大穴，右手斜指太阳穴，一招「"+YEL+"降龙伏虎"+NOR+"」使$n进退两难",
    "force" : 400,
    "lvl"   : 80,
    "skill_name" : YEL "降龙伏虎" NOR ,     
    "damage_type" : "内伤"
]),
([  "action" : "$N一手顶天成爪，一手指地，一招「"+HIG+"拨云见日"+NOR+"」,劲气笼罩$n的全身",
    "force" : 420,
    "lvl"   : 90,
    "skill_name" : HIG "拨云见日" NOR,      
    "damage_type" : "内伤"
]),
([  "action" : "$N一式「"+WHT+"如烟往事"+NOR+"」，拳招若隐若现，若有若无，缓缓地拍向$n的丹田",
    "force" : 460,
    "lvl" : 95,
    "skill_name" : WHT "如烟往事" NOR,
        "damage_type" : "内伤"
]),
([  "action" : "$N随意挥洒，使一式「"+HIW+"我心依旧"+NOR+"」，掌心微红,徐徐拍向$n的$l",
    "force" : 490,
    "lvl" : 100,
    "skills_name" : HIW "我心依旧" NOR,
        "damage_type" : "内伤"
]),
});
int valid_enable(string usage) { return usage=="unarmed" ||  usage=="parry"; }
int practice_level(){   return 100;  }
int valid_combine(string combo) { return combo=="yunlong-zhua"; }
int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("练云龙手必须空手。\n");
    if ((int)me->query_skill("yunlong-shengong", 1) < 50)
        return notify_fail("你的云龙神功火候不够，无法学云龙手。\n");
    if ((int)me->query_skill("force", 1) < 50)
        return notify_fail("你的基本内功火候不够，无法学云龙手。\n");
    if ((int)me->query("max_neili") < 250)
        return notify_fail("你的内力太弱，无法练云龙手。\n");
    if ((int)me->query_skill("unarmed",1) <30)
        return notify_fail("你的基本手法火候不够，无法学云龙手。\n");
    if (2*(int)me->query_skill("yunlong-xinfa",1) <(int)me->query_skill("yunlong-shou",1))
        return notify_fail("你的云龙心法火候不够，无法继续学云龙手。\n");
    if (me->query_skill("unarmed", 1) <=me->query_skill("yunlong-shou", 1))
        return notify_fail("你的基础不够，无法领会更高深的技巧。\n");
    return 1;
}
string query_skill_name(int level)
{
    int i;
    for(i = sizeof(action); i > 0; i--)
        if(level >= action[i-1]["lvl"])
            return action[i-1]["skill_name"];
}
mapping query_action(object me, object weapon)
{
    mapping a_action;
    int i, level;
    level   = (int) me->query_skill("yunlong-shou",1);
    for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action=action[NewRandom(i, 20, level/5)];
                       break;
                 }
    a_action["dodge"]  = 0-level;
    a_action["attack"]  = level/2;
    a_action["damage"] = level;
    return a_action;
}

int practice_skill(object me)
{
    if ((int)me->query("qi") < 30)
        return notify_fail("你的体力太低了。\n");
    if ((int)me->query("neili") < 20)
        return notify_fail("你的内力不够练云龙手。\n");
    me->receive_damage("qi", 30);
    me->add("neili", -10);
    return 1;
}
string perform_action_file(string action)
{
    return __DIR__"yunlong-shou/" + action;
}
