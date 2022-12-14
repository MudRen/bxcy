// youlong-shenfa.c 游龙身法
// written by Xiang

inherit SKILL;

string *dodge_msg = ({
	"只见$n一招「龙翔九天」，右脚轻轻点地，身体「嗖」的向上笔直地纵起
丈余，躲过了$N这一招。\n",
	"$n一个「龙游四海」，双臂一张，行云流水般向后纵出，避开了$N的凌厉
攻势。\n",
	"$n使出「翩若惊鸿」，身形不住闪动,终于躲过$N的攻击\n",
        "$n使出「神龙无影」,$N眼前一花，已不见$n踪影\n"
});

int valid_enable(string usage) { return (usage == "dodge") || (usage == "move"); }

int valid_learn(object me) { 
if ((int)me->query_skill("honghua-shengong",1)<300)
return notify_fail("你的红花神功火候不够，无法学游龙身法。\n");
return 1;	
}
string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("qi") < 40 )
                return notify_fail("你的体力太差了，不能练游龙身法。\n");
        me->receive_damage("qi", 30);
        return 1;
}

