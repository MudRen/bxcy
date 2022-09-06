//xuantie-jianfa.c 玄铁剑法  	
inherit SKILL;
#include <ansi.h>	
mapping *action = ({
([      "action" : "$N一招"HIW" 杞人忧天 "NOR"抬头向天，浑若不见，呼的一剑向自己头顶空空提起，剑光斜下，化成弧形，凌厉落下落向$n的$l。",
"force" : 10,	
        "attack":this_player()->query_skill("xuantie-jianfa",1),
        "dodge" : (int)this_player()->query_skill("dodge"),
        "damage" : (int)this_player()->query("age")*10,
        "lvl" : 0,
        "skill_name" : "杞人忧天",
        "damage_type" : "砍伤"
]),
([      "action" : "$N一招"HIG" 无中生有 "NOR"剑体下垂，无半点防御姿式，突然间手足齐动，上步近身，一道剑光划向$n.",
        "attack":this_player()->query_skill("xuantie-jianfa",1),
        "dodge" : (int)this_player()->query_skill("dodge"),
        "force" : 30,
        "damage" : (int)this_player()->query("age")*11,
        "lvl" : 10,
        "skill_name" : "无中生有",
        "damage_type" : "划伤"
]),
([      "action" : "$N一招"HIB" 拖泥带水 "NOR"剑光云袖飘动，宛若流水，飞沙走石剑光直刺$n的咽喉。",
        "force" : 40,
        "dodge" : (int)this_player()->query_skill("dodge"),
        "attack":this_player()->query_skill("xuantie-jianfa",1),
        "damage" : (int)this_player()->query("age")*12,
        "lvl" : 20,
        "skill_name" : "拖泥带水",
        "damage_type" : "刺伤"
]),

([      "action" : "$N一招"HIY" 力不从心 "NOR"含胸收腹，头缓缓低下，脚步沉重的迈向$n,剑光由下至上斜劈$n的软肋。",
        "force" : 50,
        "damage" : (int)this_player()->query("age")*13,
        "dodge" : (int)this_player()->query_skill("dodge"),
        "attack":this_player()->query_skill("xuantie-jiafa",1),
        "lvl" : 30,
        "skill_name" : "力不从心",
    "damage_type" : "劈伤"
]),
([      "action" : "$N一招"HIR" 行尸走肉 "NOR"发出一剑。这一剑发出时恍恍惚惚，隐隐约约，若有若无的刺向$n的前心",
        "force" : 60,
        "damage" : (int)this_player()->query("age")*14,
        "attack":this_player()->query_skill("xuantie-jianfa",1),
        "dodge" : (int)this_player()->query_skill("dodge"),
        "lvl" : 40,
        "skill_name" : "行尸走肉",
        "damage_type" : "刺伤"
]),
([      "action" : "$N持剑平托，一招"HIM" 庸人自扰 "NOR"没精打采的扫向$n的$l.",
        "force" : 70,
        "dodge" : (int)this_player()->query_skill("dodge"),
        "attack":this_player()->query_skill("xuantie-jianfa",1),
        "damage" : (int)this_player()->query("age")*15,
        "lvl" : 50,
        "skill_name" : "庸人自扰",
            "damage_type" : "砍伤"
]),
([      "action" : "$N一招"RED" 倒行逆施 "NOR"突然纵起丈余，头下脚上，倒过身子，一剑刺向$n的$l",
        "force" : 80,
        "attack":this_player()->query_skill("xuantie-jianfa",1),
        "dodge" : (int)this_player()->query_skill("dodge"),
        "damage" : (int)this_player()->query("age")*16,
        "lvl" : 60,
        "skill_name" : "倒行逆施",
        "damage_type" : "刺伤"
]),
([      "action" : "$N一招"YEL" 玄冰落月 "NOR"凝目远眺，突然剑光如一弯新月班落向$n的头顶。",
        "force" : 90,
        "attack":this_player()->query_skill("xuanxie-jianfa",1),
        "dodge" : (int)this_player()->query_skill("dodge"),
        "damage" : (int)this_player()->query("age")*17,
        "lvl" : 70,
        "skill_name" : "玄冰落月",
           "damage_type" : "砍伤"
]),
([      "action" : "$N一招"BLU" 暗云藏星 "NOR"脚下虚浮，有如几天不吃不睡后的脚步朗舱的袭到$n的身旁，剑光一道刺向$n的前心。",
        "force" : 100,
        "dodge" : (int)this_player()->query_skill("dodge"),
        "attack":this_player()->query_skill("xuantie-jianfa",1),
        "damage" : (int)this_player()->query("age")*18,
        "lvl" : 80,
        "skill_name" : "暗云藏星",
           "damage_type" : "刺伤"
]),
([      "action" : "$N一招"HIC" 徘徊空谷 "NOR"左掌右剑，虚虚实实的剑光刺向$n的$l。",
        "force" : 110,
        "dodge" : (int)this_player()->query_skill("dodge"),
        "attack":this_player()->query_skill("xuantie-jiafa",1),
        "damage" : (int)this_player()->query("age")*19,
        "lvl" : 90,
        "skill_name" : "徘徊空谷",
           "damage_type" : "刺伤"
]),
});
int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }
int valid_learn(object me)
{
    if ((int)me->query("max_neili") < 100)
        return notify_fail("你的内力不够。\n");
if ((int)me->query_skill("yunu-xinjing", 1) <250 && (int)me->query_skill("yunv-xinfa", 1) <250)                 	
return notify_fail("你的内功火候太浅。\n");	
if ((int)me->query_skill("xuantie-jianfa", 1) >350)       	
return notify_fail("师傅只能教你到这，以后靠你自己勤加练习了。\n");     	
if (me->query_skill("sword", 1) <=me->query_skill("xuantie-jianfa", 1)) 	
return notify_fail("你的基础不够，无法领会更高深的技巧。\n");    	
    return 1;
}
mapping query_action(object me, object weapon)
{
    mapping a_action;
    a_action = action[random(sizeof(action))];
    a_action["dodge"]=me->query_skill("sword")/2;
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
        return notify_fail("你的体力不够练玄铁剑法。\n");
    me->receive_damage("qi", 30);
    return 1;
}
string perform_action_file(string action)
{
return __DIR__"xuantie-jianfa/" + action;
}
