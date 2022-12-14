// jiuyang-shengong.c

#include <ansi.h>
inherit FORCE;

mapping *action = ({

        ([      "action":
"$N使出一招「"CYN"三"HIC"重天地混元"NOR"」，左手聚出一团混元真气击向$n的$l",
                "force":                300,
                "damage_type":  "瘀伤"

        ]),

        ([      "action":
"$N使出一招「"YEL"五"HIC"重天地混元"NOR"」，右手聚出一团混元真气击向$n的$l",
                "force":                500,
                "damage_type":  "瘀伤"

        ]),

        ([      "action":
"$N使出一招「"HIR"七"HIC"重天地混元"NOR"」，双手由掌变拳，聚出一团混元真气击向$n的$l",
                "force":                700,
                "damage_type":  "瘀伤"
        ]),

        ([      "action":
"$N使出一招「"HIW"风"HIB"雷"HIY"震"HIC"九州"NOR"」，全身腾空而起，化作一团混元真气击向$n的$l",
                "force":                1000,
                "damage_type":  "瘀伤"
        ]),

});

mixed hit_ob(object me, object victim, int damage_bonus)
{
	object ob = victim->query_temp("armor/finger");
	string msg;
    if( damage_bonus < 100 ) return 0;
	if( random(3*(me->query_skill("jiuyang-shengong",1))) > (damage_bonus ))
	{
		msg = HIR "$N的九阳神功摧毁了$n的真元！！！！\n" NOR;
		if(objectp(ob))
		{
			if(ob->query("id") == "tianmo ring")
			{
				damage_bonus = damage_bonus / 2;
				msg = HIR "$n对方的tianmojian削弱了$N九阳神功的伤害！！！！\n" NOR;
			}
		}
		victim->receive_wound("qi", (damage_bonus ));
		victim->receive_wound("jing", (damage_bonus ));
		victim->add("neili", -(int)me->query("jiali"));
		return msg;
        }
}

int valid_enable(string usage)
{
        return  usage=="unarmed" ||
                usage=="parry"||
                usage=="force";

}

int valid_learn(object me)
{
    mapping skl;
    string *sname;
    int i;
    int lvl = (int)me->query_skill("jiuyang-shengong", 1);
    if ( me->query("gender") == "无性" && lvl > 49)
        return notify_fail("你无根无性，阴阳不调，难以领会高深的九阳神功。\n");
    if ( me->query("gender") != "男性")
        return notify_fail("九阳神功需要阳刚之气，不适合你学。\n");
    if ((int)me->query_skill("force", 1) < 30)
        return notify_fail("你的基本内功火候还不够，无法领会九阳神功。\n");
    if (me->query_skill("force",1)<=lvl)
        return notify_fail("你的基本内功基础不够，再学下去会走火入魔的。\n");
    skl = me->query_skills();
    sname  = keys(skl);
    for (i=0;i<sizeof(skl);i++){
        if (sname[i]=="hunyuan-yiqi") continue;
        if (sname[i]=="yijing-force") continue;
        if (sname[i]=="jiuyang-shengong") continue;
        if (sname[i]=="taiji-shengong") continue;
            if( SKILL_D(sname[i])->valid_enable("force") )
        return notify_fail("你不先散了别派内功，怎能学九阳神功？！\n");
    }
    return 1;
}

int practice_skill(object me)
{
        return notify_fail("九阳神功只能用学的，或是从运用(exert)中增加熟练度。\n");
}

int effective_level() { return 21; }

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

string *parry_msg = ({

        "$n衣衫澎湃，内力汩汩，$N根本不可近身。\n",
        "$n长袖一甩，一股大力将$N送出丈外。\n",
        "$n施展出「九阳无我」，轻描淡写的化解了$N的攻势。\n",
});

string query_parry_msg(object me,object weapon)
{
            return parry_msg[random(sizeof(parry_msg))];
}

string exert_function_file(string func)
{
        return __DIR__"jiuyang-shengong/" + func;
}


