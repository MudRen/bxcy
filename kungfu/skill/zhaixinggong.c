// zhaixinggong.c based on xiaoyaoyou.c
inherit SKILL;
string *dodge_msg = ({
    "$n一个「"+MAG+"天外摘星"+NOR+"」，跃起数尺，躲过了$N这一招。\n",
    "$n身形向后一纵，使出一招「"+CYN+"飘然出尘"+NOR+"」，避过了$N的攻击。\n",
    "$n使出「"+HIM+"天狼涉水"+NOR+"」，恰好躲过了$N的攻势。\n",
       "$n身随意转，一招「"+YEL+"斗转星移"+NOR+"」，倏地往一旁挪开了三尺，避过了这一招。\n",
       "$n足不点地，使出「"+MAG+"流星赶月"+NOR+"」，往旁窜开数尺，躲了开去。\n",
       "$n一招「"+WHT+"织女穿梭"+NOR+"」，姿态美妙地躲了开去。\n"
});
int practice_level(){   return 60;  }
int valid_enable(string usage) 
{ 
    return (usage == "dodge") ; 
}
int valid_learn(object me)
{ 
    if (me->query_skill("dodge", 1) <=me->query_skill("zhaixinggong", 1))
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
                return notify_fail("你的体力太差了，不能练摘星功。\n");
    if (me->query_skill("zhaixinggong", 1) < 30)
            me->receive_damage("qi", 10);
    else if (me->query_skill("zhaixinggong", 1) < 60)
        me->receive_damage("qi", 20);
    else 
        me->receive_damage("qi", 30);
        return 1;
}
