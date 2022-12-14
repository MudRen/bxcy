// canhe-zhi.c 参合指
#include <ansi.h>;
inherit SKILL;
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});



mapping *action = ({
([      "action" : "$N劲风激荡，双指错落搭置，一招"+(order[random(13)])+"「目不识丁」"NOR"凶狠地向$n的$l插去",
        "force" : 100,
        "dodge" : 5,
        "damage": 10,
		"lvl" : 0,
		"weapon" : "指风",
        "skill_name" : "目不识丁",
        "damage_type" : "刺伤"
]),
([      "action" : "$N大吼一声，十指上下分飞，一招"+(order[random(13)])+"「画龙点睛」"NOR"，双指直取$n的$l",
        "force" : 130,
        "dodge" : 8,
		"damage": 15,
		"weapon" : "指风",
        "lvl" : 20,
        "skill_name" : "画龙点睛",
        "damage_type" : "刺伤"
]),
([      "action" : "$N十指互错，虚幻虚实，一招"+(order[random(13)])+"「扑朔迷离」"NOR"，前后左右，瞬息间向$n攻出了六招",
        "force" : 170,
        "dodge" : 5,
		"damage": 20,
		"weapon" : "指风",
        "lvl" : 40,
        "skill_name" : "扑朔迷离",
        "damage_type" : "刺伤",
]),
([      "action" : "$N身行腾空而起，一招"+(order[random(13)])+"「受宠若惊」"NOR"，来势奇快，向$n的$l猛插下去",
        "force" : 200,
        "dodge" : 0,
        "damage": 25,
		"weapon" : "指风",
		"lvl" : 60,
        "skill_name" : "受宠若惊",
        "damage_type" : "刺伤"
]),
([      "action" : "$N身行一闪，若有若无捱到$n身前，一招"+(order[random(13)])+"「滔滔不绝」"NOR"，插向$n的$l",
        "force" : 220,
        "dodge" : 15,
		"damage": 30,
		"weapon" : "指风",
        "lvl" : 70,
        "skill_name" : "滔滔不绝",
        "damage_type" : "刺伤"
]),
([      "action" : "$N一招"+(order[random(13)])+"「退避三舍」"NOR"，右手一拳击出，左掌化指，一掌一指凌空击向$n的$l",
        "force" : 300,
        "dodge" : 20,
        "lvl" : 80,
        "skill_name" : "退避三舍",
        "damage_type" : "内伤"
]),
([      "action" : "$N双掌化指，指中带掌，双手齐推，一招"+(order[random(13)])+"「卧薪尝胆」"NOR"，一股排山倒海的内力，直扑$n$l",
        "force" : 360,
        "dodge" : -5,
        "lvl" : 90,
        "skill_name" : "卧薪尝胆",
        "damage_type" : "内伤"
]),
([      "action" : "$N突然身行急转，一招"+(order[random(13)])+"「相煎何急」"NOR"，十指飞舞，霎时之间将$n四面八方都裹住了",
        "force" : 420,
        "dodge" : -15,
        "lvl" : 100,
        "skill_name" : "相煎何急",
        "damage_type" : "震伤"
]),
});

int valid_combine(string combo)  
{
         object me = this_player();
         mapping myfam = (mapping)me->query("family");
         if ( myfam["master_name"] == "慕容博")
                 return combo=="xingyi-zhang";
}
int valid_enable(string usage) { return usage=="finger" || usage=="parry" || usage=="unarmed"; }	


int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练参合指必须空手。\n");
        if ((int)me->query_skill("shenyuan-gong", 1) < 15)
                return notify_fail("你的神元功火候不够，无法学参合指。\n");
        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力太弱，无法练参合指。\n");
        return 1;
}

string query_skill_name(int level)
{
        int i = sizeof(action);

        while (i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
        if (random(me->query_dex()) >= 25 && me->query_skill("canhe-zhi",1) > 200 &&
             me->query_skill("parry",1) > 80 
             && random(10)>5
             ) {
                me->add("neili", -30);
                return ([
                "action": HIY "$N默运神元神功，指风轻飘飘地点向$n，一股内劲无声无息的绕向$n周身大穴！"NOR,
                "force": 550,
                "dodge": 35,
                "damage": 535,
                "damage_type": "内伤"]);
        }
        if (random(me->query_dex()) >= 30 && me->query_skill("canhe-zhi",1)> 200 &&
                me->query_skill("parry",1) > 120 
                && random(10)>5){
                me->add("qi",-30);            
                me->add("neili", -50);
                return ([
                "action": HIY "$N指风犀利，似一道无形剑气，将$n笼罩于内！$n只见眼前剑光闪动，茫然不知所措。"NOR,
                "force": 580,
                "dodge": 45,
                "damage": 535,
                "damage_type": "刺伤"]);
        }
        level   = (int) me->query_skill("canhe-zhi",1);
        for(i = sizeof(action); i > 0; i--)
        if(level > action[i-1]["lvl"])
        return action[NewRandom(i, 20, level/5)];
}
int practice_skill(object me)
{
        int lvl = me->query_skill("canhe-zhi", 1);
        int i = sizeof(action);
        mapping learned = me->query_learned();

        if (!mapp(learned)) learned = ([]);
        if (!learned["canhe-zhi"])
                while (i--) if (lvl == action[i]["lvl"]) return 0;

        if ((int)me->query("jing") < 30)
                return notify_fail("你的精力太低了。\n");
        if ((int)me->query("neili") < 10)
                return notify_fail("你的内力不够练参合指。\n");
        me->receive_damage("jing", 20);
        me->add("neili", -10);
		return 1;
}
string perform_action_file(string action)
{
        return __DIR__"canhe-zhi/" + action;
}
