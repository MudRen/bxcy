// pixie-jian.c 辟邪剑法
// Jay 4/5/96
inherit SKILL;

#include <combat.h>

string *dodge_msg = ({
        "突然之间，白影急幌，$n向后滑出丈余，立时又回到了原地，躲过了$N这一招。\n",
        "$n身形飘忽，有如鬼魅，转了几转，移步到$N的身后，躲过了$N这一招。\n",
        "$N只觉眼前一花，似乎见到$n身形一幌，但随即又见$n回到原地，却似从未离开。\n",
});
// 双方均有武器
string *weapon_vs_weapon_msg = ({
        "只听见「锵」一声，被$p用手中$i轻轻荡开了。\n",
        "$n右手伸出，在$N手腕上迅速无比的一按，$N的$w险些击中自己小腹。\n",
        "不退反进，$n手中$i迅速无比地刺向$N胸口，随即回手拨开$w。\n",
        "但是$n身子一侧，紧跟着用手中$i把$w拨开。\n",
});
// 攻击方无武器,招架方有武器
string *unarmed_vs_weapon_msg = ({
        "$n手臂回转，在$N手肘下一推，顺势闪到一旁。\n",
        "$n手中$i突然指向$N的左眼，$N慌忙闪避。\n",
});


mapping *action = ({
([      "action":"蓦地里$N猱身而上，蹿到$n的身后，$w捅向$n的$l，又跃回原地",
        "force" : 80,
        "lvl" : 0,
        "skill_name" : "猱身而上",
        "damage_type":  "刺伤"
]),
([      "action":"$N突然间招法一变，$w忽伸忽缩，招式诡奇绝伦。$n惊骇之中方寸大乱",
        "force" : 80,
        "lvl" : 55,
        "skill_name" : "招法一变",
        "damage_type":  "刺伤"
]),
([      "action":"$N身形飘忽，有如鬼魅，转了几转，移步到$n的左侧，$w已经向$l递去。",
        "force" : 90,
        "lvl" : 80,
        "skill_name" : "有如鬼魅",
        "damage_type":  "刺伤"
]),
([      "action":"$N一声冷笑，蓦地里疾冲上前，一瞬之间，与$n相距已不到一尺，$w随即递出",
        "force" : 140,
        "lvl" : 100,
        "skill_name" : "疾冲上前",
        "damage_type":  "刺伤"
]),
([      "action":"$N喝道：“好！”，便即拔出$w，反手刺向$n的$l，跟着转身离去",
        "force" : 80,
        "lvl" : 140,
        "skill_name" : "反手刺出",
        "damage_type":  "刺伤"
]),
([      "action":"$N向后疾退，$n紧追两步，一晃间$N闪到$n面前，手中$w直指$n的$l",
        "force" : 60,
        "lvl" : 250,
        "skill_name" : "向后疾退",
        "damage_type":  "刺伤"
]),
([      "action":"$N蓦地冲到$n面前，手中$w直刺$n右眼！$n慌忙招架，不想$N的$w突然转向$n的$l",
        "force" : 200,
        "lvl" : 300,
        "skill_name" : "直刺右眼",
        "damage_type":  "刺伤"
]),
([      "action":"$N飞身跃起，$n抬眼一望，但见得$N从天直落而下，手中$w刺向$n的$l",
        "force" : 340,
        "lvl" : 350,
        "skill_name" : "飞身跃起",
        "damage_type":  "刺伤"
]),
([      "action":"$N腰枝一摆，$n眼前仿佛突然出现了七八个$N，七八只$w一起刺向$n",
        "force" : 380,
        "lvl" : 400,
        "skill_name" : "腰枝一摆",
        "damage_type":  "刺伤"
]),
});

int valid_enable(string usage) 
{ 
    return usage == "sword" || usage == "dodge" || usage == "parry"; 
}
string query_parry_msg(object me,object weapon)
{
    string msg;
    object my_weapon;

    if (!(my_weapon=me->query_temp("weapon"))){
        if (!(my_weapon=me->query_temp("secondary_weapon")))
          return "";
     }else{
        if (!valid_enable(my_weapon->query("skill_type"))){
            if (!(my_weapon=me->query_temp("secondary_weapon")))
                  return "";
            else            
                if (!valid_enable(my_weapon->query("skill_type")))
                  return "";
        }
    }
    if (weapon)
        msg=weapon_vs_weapon_msg[random(sizeof(weapon_vs_weapon_msg))];
    else
        msg=unarmed_vs_weapon_msg[random(sizeof(unarmed_vs_weapon_msg))];
    msg=replace_string( msg, "$i", my_weapon->name() );
    return msg;
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
    level   = (int) me->query_skill("pixie-jian", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action = action[NewRandom(i, 20, level/5)];
                        break;
                }
    a_action["dodge"]  = 0-level*3;
    a_action["parry"]  = 0-level*3;
    a_action["attack"]  = level*2;
    a_action["damage"] = level;
    if (me->query_temp("action_flag"))
       me->set_temp("action_msg","紧跟着");
    return a_action;

}
string query_dodge_msg(string limb,object me)
{
      me->set_temp("fight/dodge",3*me->query_skill("pixie-jian",1));
    return dodge_msg[random(sizeof(dodge_msg))];
}
int valid_learn(object me)
{
        return notify_fail("辟邪剑法只能通过研习《葵花宝典》来学习。\n");
}

// 辟邪剑法的特殊攻击
void do_interlink(object me, object victim)
{
    int skill,i,j;
    object *enemy;
    
    skill=me->query_skill("pixie-jian", 1);
    if (skill>60){
        enemy=me->query_enemy();
        if (!sizeof(enemy)) return;
// 对所有敌人均自动进行攻击
        for (i=0;i<sizeof(enemy);i++){
            for (j=0;j<(skill/(30*sizeof(enemy)));j++)
                if ((me->is_fighting(enemy[i]) || enemy[i]->is_fighting(me)) && enemy[i]->query("qi")>0 ){
                    if (environment(me) == environment(enemy[i]))
                     {
                   me->add_temp("str",skill/10);
                   me->add_temp("dex",skill/10);
                        COMBAT_D->do_attack(me, enemy[i], me->query_temp("weapon"), TYPE_REGULAR);
                     }
                }else break;
        }
         me->delete_temp("str");
         me->delete_temp("dex");
    }
}

