// yunu-jiafa 玉女素心剑
// Modify By csy 98/12
inherit SKILL;

#include <combat.h>


mapping *action = ({
([      "action" : "$N击高而下，一式「雁行斜击」，腾身下击，剑尖直点$n头部",
        "force" : 130,
        "dodge" : 50,
        "damage" : 40,
        "parry" : 15,
        "lvl" : 0,
        "skill_name" : "雁行斜击",
        "damage_type" : "刺伤"
]),
([      "action" : "$N踏前数步，左手遥指，右手$w使一式「浪迹天涯」直劈$n的右肋",
        "force" : 155,
        "dodge" : 45,
        "damage" : 65,
        "parry" : 20,
        "lvl" : 10,
        "skill_name" : "浪迹天涯",
        "damage_type" : "刺伤"
]),
([      "action" : "$N一招「花前月下」，$w颤动如鲜花招展风中，来回挥削",
        "force" : 200,
        "dodge" : 40,
        "damage" : 80,
        "parry" : 10,
        "lvl" : 20,
        "skill_name" : "花前月下",
        "damage_type" : "刺伤"
]),
([      "action" : "$N剑尖上翻，竟然指向自己的樱唇，一招「清饮小酌」，宛若举杯自饮
一般，横扫$n的$l",
        "force" : 235,
        "dodge" : 35,
        "damage" : 85,
        "parry" : 15,
        "lvl" : 30,
        "skill_name" : "清饮小酌",
        "damage_type" : "刺伤"
]),
([      "action" : "$N使出「抚琴按箫」，$w自横脐前，做抚琴状，随即剑出中宫，平削$n的$l",
        "force" : 260,
        "dodge" : 30,
        "damage" : 90,
        "parry" : 5,
        "lvl" : 40,
        "skill_name" : "抚琴按箫",
        "damage_type" : "刺伤"
]),
([      "action" : "$N横剑斜削，微微二颤，一招「彩笔画眉」，构成帘下梳妆之状，一脸娇羞，
$w却丝毫未有停留，逼向$n的$l",
        "force" : 275,
        "dodge" : 25,
        "damage" : 95,
        "parry" : 20,
        "lvl" : 50,
        "skill_name" : "彩笔画眉",
        "damage_type" : "刺伤"
]),
([      "action" : "$N一招「举案齐眉」，双手齐握剑柄，举剑上挑，直划$n的档部",
        "force" : 290,
        "dodge" : 20,
        "damage" : 100,
        "parry" : 25,
        "lvl" : 70,
        "skill_name" : "举案齐眉",
        "damage_type" : "刺伤"
]),
([      "action" : "$N向前急进两步，一招「木兰回射」，蓦地里挺剑反手向背后刺出，直刺$n
的胸口",
        "force" : 305,
        "dodge" : 15,
        "damage" : 105,
        "parry" : 20,
        "lvl" : 90,
        "skill_name" : "木兰回射",
        "damage_type" : "刺伤"
]),
([  "action" : "$N一招「分花拂柳」，$w似左实右，似右实左，虚实莫辩，点向$n的喉头",
        "force" : 350,
        "dodge" : 10,
        "damage" : 110,
        "parry" : 15,
        "lvl" : 110,
        "skill_name" : "分花拂柳",
        "damage_type" : "刺伤"
]),
([  "action" : "$N眼角尽是笑意，眉目含情，一招「如影相随」，人似清风影随$n周身，身形
飘飘中剑光熠熠生辉，",
        "force" : 375,
        "dodge" : 15,
        "damage" : 120,
        "parry" : 20,
        "lvl" : 130,
        "skill_name" : "如影相随",
        "damage_type" : "刺伤"
]),
});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力不够。\n");
if (me->query_skill("yunu-jianfa", 1) >= me->query_skill("quanzhen-jianfa",1))
return notify_fail("你的全真剑法修为不够。\n");	
if (me->query_skill("yunu-jianfa", 1) >= me->query_skill("meinu-quanfa",1))
return notify_fail("你的美女拳法修为不够。\n");	
if (me->query_skill("yunu-jianfa", 1) >= me->query_skill("sword",1))
return notify_fail("你的基础不够，无法领会更高深的技巧。\n");
if (me->query_skill("yunu-jianfa", 1) >= me->query_skill("yunu-xinjing",1))
                return notify_fail("你的玉女心经功力不够。\n");
        return 1;
}

string query_skill_name(int level)
{
        int i = sizeof(action);

        while (i--)
                if(level > action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
mapping a_action;
        level   = (int) me->query_skill("yunu-jianfa",1);
        for(i = sizeof(action); i > 0; i--)
if(level > action[i-1]["lvl"]){
a_action = action[NewRandom(i, 20, level/5)];
break;
}
return a_action;
}

int practice_skill(object me)
{
     return notify_fail("玉女剑法只能靠学习(learn)来提高。\n");

}

string perform_action_file(string action)
{
        return __DIR__"yunu-jianfa/" + action;
}

void do_interlink(object me, object victim)
{
    int skill,i,j;
    object *enemy;
    
skill=me->query_skill("yunu-jianfa", 1);	
if (skill>=250 &&  me->query_skill("yunu-xinjing",1)>=250 && me->query("neili")>200)       {	
        enemy=me->query_enemy();
        if (!sizeof(enemy)) return;
message_vision(BOLD+"\n\n$N默运古墓心法，心如止水，使出『"+HIC+"玉女素心"+NOR+"』剑法。" NOR,me);
        for (i=0;i<sizeof(enemy);i++){
for (j=0;j<((int)((skill-250)/30+5)/sizeof(enemy));j++)	
                if ((me->is_fighting(enemy[i]) || enemy[i]->is_fighting(me)) && enemy[i]->query("qi")>0 ){
                    if (environment(me) == environment(enemy[i]))
                     {
                   me->add_temp("str",skill/10);
                   me->add_temp("dex",skill/10);
me->add("neili", -10);	
me->set_temp("action_msg","紧接着");
						COMBAT_D->do_attack(me, enemy[i], me->query_temp("weapon"), TYPE_REGULAR);
                     }
                }else break;
        }
         me->delete_temp("str");
         me->delete_temp("dex");
    }
}
