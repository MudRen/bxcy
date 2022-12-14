//adai-quanfa.c 黯然消魂掌
// By Kayin @ CuteRabbit Studio 99-4-16 16:22 new

inherit SKILL;
#include <ansi.h>
mapping *action = ({
([	"action" : "$N两眼直勾勾的盯着$n,一式"HIM"「流口水啊,流口水」"NOR"，向$n迅速击出。",
	"force" : 200,
	"attack":this_player()->query_skill("adai-quanfa",1),
	"dodge" : (int)this_player()->query_skill("dodge"),
	"damage" : (int)this_player()->query("age")*10,
	"lvl" : 0,
	"skill_name" : "直勾勾",
	"damage_type" : "内伤"
]),
([	"action" : "$N一式"HIM"「啊哦,啊哦」"NOR"，向$n迅速击出",
	"force" : 1200,
	"dodge" : (int)this_player()->query_skill("dodge"),
	"attack":this_player()->query_skill("adai-quanfa",1),
	"damage" : (int)this_player()->query("age")*20,
	"lvl" : 100,
	"skill_name" : "啊哦,啊哦",
           "damage_type" : "瘀伤"
]),
([	"action" : "$N一式"HIM"「哎呦,哎呦」"NOR"，向$n迅速击出",
	"force" : 1300,
	"dodge" : (int)this_player()->query_skill("dodge"),
	"attack":this_player()->query_skill("adai-quanfa",1),
	"damage" : (int)this_player()->query("age")*21,
	"lvl" : 110,
	"skill_name" : "哎呦,哎呦",
           "damage_type" : "内伤"
]),
([	"action" : "$N一式"HIM"「来啊,来啊」"NOR"，向$n迅速击出",
	"force" : 1400,
	"dodge" : (int)this_player()->query_skill("dodge"),
	"attack":this_player()->query_skill("adai-quanfa",1),
	"damage" : (int)this_player()->query("age")*22,
	"lvl" : 120,
	"skill_name" : "来啊,来啊",
           "damage_type" : "瘀伤"
]),
([	"action" : "$N一式"HIM"「不要啊,不要啊」"NOR"，向$n迅速击出",
	"force" : 1500,
	"dodge" : (int)this_player()->query_skill("dodge"),
	"attack":this_player()->query_skill("adai-quanfa",1),
	"damage" : (int)this_player()->query("age")*23,
	"lvl" : 130,
	"skill_name" : "不要啊,不要啊",
           "damage_type" : "内伤"
]),
([	"action" : "$N一式"HIM"「坏死了,坏死了」"NOR"，向$n迅速击出",
	"force" : 1600,
	"dodge" : (int)this_player()->query_skill("dodge"),
	"attack":this_player()->query_skill("adai-quanfa",1),
	"damage" : (int)this_player()->query("age")*24,
	"lvl" : 140,
	"skill_name" : "坏死了,坏死了",
           "damage_type" : "瘀伤"
]),
([	"action" : "$N一式"HIM"「不跟你玩了」"NOR"，向$n迅速击出",
	"force" : 1700,
	"dodge" : (int)this_player()->query_skill("dodge"),
	"attack":this_player()->query_skill("adai-quanfa",1),
	"damage" : (int)this_player()->query("age")*25,
	"lvl" : 150,
	"skill_name" : "不跟你玩了",
           "damage_type" : "内伤"
]),
([	"action" : "$N一式"HIM"「死光了,死光了」"NOR"，向$n迅速击出",
	"force" : 1800,
	"dodge" : (int)this_player()->query_skill("dodge"),
	"attack":this_player()->query_skill("adai-quanfa",1),
	"damage" : (int)this_player()->query("age")*26,
	"lvl" : 160,
	"skill_name" : "去死吧",
           "damage_type" : "点穴"
]),
});

int valid_enable(string usage) { return usage=="unarmed" || usage=="parry"; }

int valid_combine(string combo) { return combo=="adai-quanfa"; }

int valid_learn(object me)
{
	if(!me->query("couple/have_couple")) 
		return notify_fail("你还没有所爱的人，不能领会其中的精要！\n");
if (me->query_skill("adai-quanfa", 1) >= 300)
return notify_fail("高深的黯然消魂掌需自己勤加修习领悟。\n");
	if (me->query("gender") != "男性") 
                return notify_fail("你体会不到男人思念一个人的心情。\n");
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练黯然消魂掌必须空手。\n");
if ((int)me->query("max_neili") < 30000)	
		return notify_fail("你的内力太弱，无法练黯然消魂掌。\n");
	if ((int)me->query_str()< 40)
		return notify_fail("你的臂力太弱，无法练黯然消魂掌。\n");	
	return 1;
}

mapping query_action(object me, object weapon)
{
	int i, level;
	level = (int) me->query_skill("adai-quanfa",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 50, level)];
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 30)
		return notify_fail("你的体力太低了。\n");
if (me->query_skill("unarmed", 1) <= me->query_skill("adai-quanfa",1))
return notify_fail("你的基础不够，无法练习黯然消魂掌。\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("你的内力不够练黯然消魂掌。\n");
	me->receive_damage("qi", 25);
	me->add("neili", -30);
	return 1;
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
	if( damage_bonus < 100 ) return 0;

	if( damage_bonus/2 > victim->query_str() ) {
		victim->receive_wound("qi", (damage_bonus - 100) / 2 );
		return HIR "只听到“哦..哦”的两声，"+ victim->name()+"身体软软的倒了下去！\n" NOR;
	}
}
string perform_action_file(string action)
{
	return __DIR__"adai-quanfa/" + action;
}
