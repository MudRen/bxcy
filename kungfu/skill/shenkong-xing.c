//
// shenkong-xing.c 身空行
//
inherit SKILL;
string *dodge_msg = ({
"$n使出一招「"+HIW+"心空"+NOR+"」，身体向侧后飘去 \n",
"$n使出一招「"+HIG+"誓言空"+NOR+"」，双足一点，跃至数丈之外 \n",
"$n使出一招「"+HIY+"莲空"+NOR+"」，身形一变，滑至$N身后 \n",
"$n大吼一声，使出一招「"+HIM+"大安空"+NOR+"」，从$N头顶越过 \n",
"$n使出一招「"+HIB+"佛空"+NOR+"」，如轻鸿般飘去，瞬间又闪至$N面前 \n",
"$n使出一招「"+HIC+"金刚空"+NOR+"」，顿时$N周围都是$n的身影 \n",
});
int practice_level(){   return 60;  }
int valid_enable(string usage)
{
    return usage == "dodge";
}
int valid_learn(object me)
{
    if (me->query_skill("dodge", 1) <=me->query_skill("shenkong-xing", 1))
        return notify_fail("你的基础不够，无法领会更高深的技巧。\n");
    return 1;
}
string query_dodge_msg(string limb,object me)
{
        me->set_temp("fight/dodge",me->query_skill("shaolin-shenfa",1)/2);
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
    if( (int)me->query("qi") < 40 )
        return notify_fail("你的体力太差了，不能练习身空行。\n");
    me->receive_damage("qi", 20);
    return 1;
}
