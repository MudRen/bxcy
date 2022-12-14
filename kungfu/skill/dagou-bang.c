// dagou-bang.c
inherit SKILL;
mapping *action = ({
([  "action": "$N使出一招「"+BLK+"棒打双犬"+NOR+"」，手中$w化作两道青光砸向$n的$l",
    "force" : 50,
    "lvl" : 1,
    "damage_type": "挫伤"
]),
([  "action": "$N手中$w左右晃动，一招「"+RED+"拨草寻蛇"+NOR+"」向$n的$l攻去",
    "force" : 100,
    "lvl" : 33,
    "damage_type": "挫伤"
]),
([  "action": "$N举起$w，居高临下使一招「"+GRN+"打草惊蛇"+NOR+"」敲向$n的$l",
    "force" : 180,
    "lvl" : 66,
    "damage_type": "挫伤"
]),
([  "action": "$N施出「"+YEL+"拨狗朝天"+NOR+"」，$w由下往上向$n撩去",
    "force" : 250,
    "lvl" : 100,
    "damage_type": "挫伤"
]),
});
int practice_level(){   return 100;  }
int valid_enable(string usage) { return (usage == "club") || (usage == "parry"); }
int valid_learn(object me)
{
    if ((int)me->query("max_neili") < 100)
        return notify_fail("你的内力不够。\n");
if ((int)me->query_skill("huntian-qigong",1) < 500 )                 
return notify_fail("你的内功修为不够,无法领悟打狗棒法的精要。\n");	
if ((int)me->query_skill("dagou-bang",1) >= 450 )    			
return notify_fail("师傅只能教你到这，以后靠自己多加练习体会。\n");		
    if (me->query_skill("club", 1) <=me->query_skill("dagou-bang", 1))
        return notify_fail("你的基础不够，无法领会更高深的技巧。\n");
    else
    return 1;
}
mapping query_action(object me, object weapon)
{
    mapping a_action;
    int level=me->query_skill("dagou-bang",1);
    if ((int)me->query_temp("wugou")>0)
        return (["action": BOLD ""+HIC+"玉竹杖"+NOR+"指向$n"+BOLD+"的$l" NOR,
                 "dodge": -3*random(level),
                 "damage": level,
                 "damage_type":"挫伤",
                ]);
    a_action = action[random(sizeof(action))];
    a_action["dodge"]  = 0-level;
    a_action["damage"] = level;
    return a_action;
}
 int practice_skill(object me)
 {
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "club")
    if (!objectp(weapon = me->query_temp("secondary_weapon"))
    || (string)weapon->query("skill_type") != "club")
        return notify_fail("你使用的武器不对。\n");
    if ((int)me->query("qi") < 50)
        return notify_fail("你的体力不够练打狗棒法。\n");
    me->receive_damage("qi", 40);
    return 1;
 }

void do_interlink(object me, object victim)
{
    int skill,skill2,i,j;
    object *enemy,weapon=me->query_temp("weapon");
    string all_enemy;
    
    if (!weapon) return;
    skill=me->query_skill("dagou-bang", 1);
    skill2=me->query_skill("huntian-qigong", 1);
    if (random(skill)>500&&random(skill2)>500&&
    	me->query_skill_mapped("force") == "huntian-qigong"&&
    	(string)weapon->query("id") == "yuzhu zhang"&&
    	me->query("neili") > 20000&&
    	me->query("family/family_name") == "丐帮"
    	){
        enemy=me->query_enemy();
        if (!sizeof(enemy)) return;
        if (sizeof(enemy)==1 && enemy[i]->query("eff_qi")<0 ) return;
        all_enemy=enemy[0]->name();
        for (i=1;i<sizeof(enemy);i++)
            all_enemy+=("、"+enemy[i]->name());
        message_vision(HIG+"$N眼中射出一道青芒，手中玉竹杖使出「天下无狗」，劈天盖地般攻向"+all_enemy+"。\n\n" NOR,me);
        me->set_temp("wugou",1);
        for (i=0;i<sizeof(enemy);i++){
            for (j=0;j<(skill/(80*sizeof(enemy)));j++)
                if ((me->is_fighting(enemy[i]) || enemy[i]->is_fighting(me)) && enemy[i]->query("eff_qi")>0 ){
                    if (environment(me) == environment(enemy[i]))
                     {
                        COMBAT_D->do_attack(me, enemy[i], me->query_temp("weapon"), 0);
                     }
                }else break;
        }
    me->delete_temp("wugou");
    me->add("neili",-random(4500)-500);
    }
}

string perform_action_file(string action){	return __DIR__"dagou-bang/" + action;}
