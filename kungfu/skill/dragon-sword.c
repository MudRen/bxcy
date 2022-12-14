// mingwang-jian.c 九天龙吟剑
// Designed by secret(秘密)
//
inherit SKILL;
mapping *action = ({
([      "action" : ""+HIG+"$N长叹一声,面上的悲意愈浓.一招「深渊之龙」,手中$w泛起一片光影,把$n困在其中。"+NOR+" ",
        "skill_name" : HIC "不动" NOR,
        "force" : 100,
        "lvl" : 0,
        "damage_type" : "刺伤",
]),
 ([      "action" : ""+HIG+"$N神情突然间变地十分落索,一式「囚龙伏井」,手中$w似乎漫不经心斜斜刺向$n的$l  "+NOR+" ",
        "skill_name" : HIM "起手出剑" NOR,
        "force" : 140,
        "lvl" : 8,
        "damage_type" : "刺伤",
]),
([      "action" : ""+HIG+"$N似是御风而行,足不沾地地徒然滑进七尺,剑光洌洌向$n的右脚削去,正是「游龙戏水」 "+NOR+"",
        "skill_name" : HIY "山崩" NOR,
        "force" : 180,
        "lvl" : 16,
        "damage_type" : "割伤",
]),
([      "action" : ""+HIG+"$N脚踏中宫，$w一招「青龙吐珠」迅疾无比地直取$n的後心 "+NOR+"",
        "skill_name" : HIG "千旋转" NOR,
        "force" : 220,
        "lvl" : 24,
        "damage_type" : "刺伤",
]),
([      "action" : ""+HIG+"$N呵呵一笑,一招「二龙换日」,身影豁然间一分为二,两道剑光虚虚实实,直逼$n的$l"+NOR+"",
        "skill_name" : MAG "降魔舞" NOR,
        "force" : 250,
        "lvl" : 32,
        "damage_type" : "刺伤",
]),
([      "action" : ""+HIG+"$N身形腾空而起，一个鹞子翻身，双手握剑俯冲下来。使出最后一招「汇龙一击」$w挟带着尖锐的风声直刺$n头顶的百会穴"+NOR+" ",
        "skill_name" : HIW "鹤舞" NOR,
        "force" : 280,
        "lvl" : 40,
        "damage_type" : "刺伤",
]),
([      "action" : ""+HIG+"$N一招「龙翔九天」,身形拔地而起.空中矫若游龙,手里$w化作一条银龙刺向$n後心"+NOR+"  ",
        "skill_name" : YEL "龙"BLU"腾" NOR,
        "force" : 300,
        "lvl" : 48,
        "damage_type" : "刺伤",
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }
int practice_level(){   return 80;  }
//int valid_combine(string combo) { return combo=="xue-dao"; }
int valid_learn(object me)
{
    if ((int)me->query("max_neili") < 100)
        return notify_fail("你的内力不够。\n");
    if (me->query_skill("sword", 1) <=me->query_skill("mingwang-jian", 1))
        return notify_fail("你的基础不够，无法领会更高深的技巧。\n");
   if ((int)me->query_skill("longxiang", 1) < 20)
        return notify_fail("你的龙象般若功火候太浅。\n");
    else if ((int)me->query_skill("xiaowuxiang", 1) < 20)
        return notify_fail("你的小无相功火候太浅。\n");
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
    mapping a_action;
    level   = (int) me->query_skill("dragon-sword",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action = action[NewRandom(i, 20, level/5)];
                        break;
                }
    a_action["dodge"]  = 0-level/3;
    a_action["parry"]  = 0-random(level/3);
    a_action["attack"]  = level/3;
    a_action["damage"] = level;
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
        return notify_fail("你的体力不够，练不了不动明王剑。\n");
    me->receive_damage("qi", 25);
    return 1;
}
