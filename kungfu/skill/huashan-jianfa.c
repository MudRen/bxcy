// huashan-jianfa.c 华山剑法
inherit SKILL;
#include <combat.h>

mapping *action = ({
([  "action" : "$N一招「"+YEL+"白云出岫"+NOR+"」，手中$w点向$n的$l",
    "damage" : 20,
    "damage_type" : "刺伤"
]),
([  "action" : "$N使出「"+RED+"有凤来仪"+NOR+"」，$w闪烁不定，刺向$n的$l",
    "damage" : 25,
    "damage_type" : "刺伤"
]),
([  "action" : "$N一招「"+MAG+"天绅倒悬"+NOR+"」，$w自上而下划出一个大弧，向$n劈砍下去",
    "damage" : 30,
    "damage_type" : "刺伤"
]),
([  "action" : "$N向前跨上一步，手中$w使出「"+BLU+"白虹贯日"+NOR+"」直刺$n的$l",
    "damage" : 35,
    "damage_type" : "刺伤"
]),
([      "action" : "$N手中的$w一晃，使出「"+HIM+"苍松迎客"+NOR+"」直刺$n的$l",
        "damage" : 50,
        "damage_type" : "刺伤"
]),
});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }
int valid_learn(object me)
{
    if ((int)me->query("max_neili") < 100)
        return notify_fail("你的内力不够。\n");
    if ((int)me->query_skill("zixia-shengong", 1) < 20)
        return notify_fail("你的华山内功火候太浅。\n");
    if (me->query_skill("sword", 1) <=me->query_skill("huashan-jianfa", 1))
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
        return notify_fail("你的体力不够练华山剑法。\n");
    me->receive_damage("qi", 30);
    return 1;
}
string perform_action_file(string action)
{
    return __DIR__"huashan-jianfa/" + action;
}

void do_interlink(object me, object victim)
{
    int skill1,skill2,j;
    string second_skill;
    if (me->query_temp("secondary_weapon")) return;
    second_skill = me->query_skill_mapped("unarmed");
    if (!second_skill || second_skill!="huashan-zhangfa" )   return;
    skill1=me->query_skill("huashan-jianfa", 1);
    skill2=me->query_skill("huashan-zhangfa", 1);
    if (random(skill1)>100 && random(skill2)>100){
    message_vision(HIY "\n$N使出华山派绝技「剑掌五连环」，身法陡然加快！\n\n" NOR,me);
    for (j=0;j<5;j++)
       if ((me->is_fighting(victim) || victim->is_fighting(me)) && victim->query("qi")>0 ){
         if (environment(me) == environment(victim)){
              if (j%2==0)
                    COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
              else{
                    me->set_temp("secondly_weapon",1);
                    COMBAT_D->do_attack(me, victim, 0, TYPE_QUICK);
                    me->delete_temp("secondly_weapon");
              }
         }
       }else break;
    }
}

