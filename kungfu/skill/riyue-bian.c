// riyue-bian.c 日月鞭法
#include <ansi.h>
inherit SKILL;
mapping *action = ({
([  "action":       "$N端坐不动，一招「"+RED+"裂石式"+NOR+"」，手中$w抖得笔直，对准$n的胸腹要害连刺数鞭",
    "lvl" : 0,
    "skill_name" : RED "裂石式" NOR,
    "damage_type":  "刺伤"
]),
([  "action":       "$N身形一转，一招「"+RED+"断川式"+NOR+"」，手中$w如矫龙般腾空一卷，猛地向$n劈头打下",
    "lvl" : 36,
    "skill_name" : RED "断川式" NOR,
    "damage_type":  "刺伤"
]),
([  "action":       "$N力贯鞭梢，一招「"+HIW+"破云式"+NOR+"」，手中$w舞出满天鞭影，排山倒海般扫向$n全身",
    "lvl" : 89,
    "skill_name" : HIW "破云式" NOR,
    "damage_type":  "刺伤"
]),
([  "action":       "$N力贯鞭梢，一招「"+HIW+"分海式"+NOR+"」，手中$w舞出满天鞭影，排山倒海般扫向$n全身",
    "lvl" : 112,
    "skill_name" : HIW "分海式" NOR,
    "damage_type":  "刺伤"
]),
([  "action":       "$N力贯鞭梢，一招「"+BLU+"裂空式"+NOR+"」，手中$w舞出满天鞭影，排山倒海般扫向$n全身",
    "lvl" : 135,
    "skill_name" : BLU "裂空式" NOR,
    "damage_type":  "刺伤"
]),
([  "action":       "$N力贯鞭梢，一招「"+BLU+"佛光普照"+NOR+"」，手中$w舞出满天鞭影，排山倒海般扫向$n全身",
    "lvl" : 158,
    "skill_name":  BLU "佛光普照" NOR,
    "damage_type":  "刺伤"
]),
([  "action":       "$N力贯鞭梢，一招「"+YEL+"金刚伏魔"+NOR+"」，手中$w舞出满天鞭影，排山倒海般扫向$n全身",
    "lvl" : 210,
    "skill_name" : YEL "金刚伏魔" NOR,
    "damage_type":  "刺伤"
]),
([  "action":       "$N力贯鞭梢，一招「"+HIR+"佛法无边"+NOR+"」，手中$w舞出满天鞭影，排山倒海般扫向$n全身",
    "lvl" : 260,
    "skill_name" : HIR "佛法无边" NOR,
    "damage_type":  "刺伤"
]),
});
int valid_enable(string usage) { return (usage == "whip") || (usage == "parry"); }
int practice_level(){   return 260;  }
int valid_learn(object me)
{
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "whip")
    if (!objectp(weapon = me->query_temp("secondary_weapon"))
    || (string)weapon->query("skill_type") != "whip")
        return notify_fail("你必须先找一条鞭子才能练鞭法。\n");

    if( (int)me->query("max_neili") < 500 )
        return notify_fail("你的内力不足，没有办法练日月鞭法, 多练些内力再来吧。\n");
    if (me->query_skill("whip", 1) <=me->query_skill("riyue-bian", 1))
        return notify_fail("你的基础不够，无法领会更高深的技巧。\n");

    if ((int)me->query_skill("hunyuan-yiqi", 1) < 50)
    if ((int)me->query_skill("yijing-force", 1) < 50)
    if ((int)me->query_skill("jiuyang-shengong", 1) < 50)
    if ((int)me->query_skill("buddhism-force", 1) < 50)
    if ((int)me->query_skill("taiji-shengong", 1) < 50)
        return notify_fail("你的禅宗气功火候不够，无法学日月鞭法。\n");
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
    level   = (int) me->query_skill("riyue-bian", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action = action[NewRandom(i, 20, level/5)];
                        break;
                }
    a_action["dodge"]  = 0-level*3;
    a_action["parry"]  = 0-level*2;
    a_action["attack"]  = level*2;
    a_action["damage"] = level;
    return a_action;

}
int practice_skill(object me)
{
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "whip")
    if (!objectp(weapon = me->query_temp("secondary_weapon"))
    || (string)weapon->query("skill_type") != "whip")
        return notify_fail("你使用的武器不对。\n");
    if ((int)me->query("qi") < 50)
        return notify_fail("你的体力不够练日月鞭法。\n");
    me->receive_damage("qi", 45);
    return 1;
}
string perform_action_file(string action)
{
    if ( this_player()->query_skill("riyue-bian", 1) >= 50 )
        return __DIR__"riyue-bian/" + action;
}
