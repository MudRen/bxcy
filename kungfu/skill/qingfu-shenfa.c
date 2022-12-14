// qingfu-shenfa.c 青蝠身法
// pal 1997.05.26
inherit SKILL;
string *dodge_msg = ({
    "只见$n一招「"+RED+"福满乾坤"+NOR+"」，身形陡然纵起，躲过了$N这一招。\n",
    "$n一式「"+YEL+"五蝠献寿"+NOR+"」，身形晃动，向一旁飘出，避开了$N这一招。。\n"
    "$n使出「"+BLU+"洞天福地"+NOR+"」，一个空心筋斗向后翻出，避开了$N的凌厉攻势。\n",
    "$n一招「"+HIW+"云龙百蝠"+NOR+"」，身随意转，$N只觉眼前一花，$n已绕至$N的身后。\n",
});
int practice_level(){   return 60;  }
int valid_enable(string usage)
{
    return usage == "dodge";
}
int valid_learn(object me)
{
    if (me->query_skill("dodge", 1) <=me->query_skill("qingfu-shenfa", 1))
        return notify_fail("你的基础不够，无法领会更高深的技巧。\n");
    return 1;
}
string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}
int practice_skill(object me)
{
        if( (int)me->query("qi") < 40 )
                return notify_fail("你的体力太差了，不能练青蝠身法。\n");
        me->receive_damage("qi", 30);
        return 1;
}
