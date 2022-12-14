// yueying-wubu.c  月影舞步
inherit SKILL;
string *dodge_msg = ({
"$n身形一晃，纤腰一扭，一招「"+MAG+"星河鹭起"+NOR+"」，弹地而起。\n",
"$n一招「"+HIR+"歌尽桃花扇底风"+NOR+"」，$N只觉眼前一花，不见了$n的身影。\n",
"$n一招「"+BLU+"扫尽浮云风不定"+NOR+"」，身形微晃，有惊无险地避开了$N这一招。\n",
"只见$n身子向后一翻，一招「"+RED+"缥渺孤鸿影"+NOR+"」，后荡而起，掠向一旁。\n" ,
"$n一招「"+GRN+"起舞弄清影"+NOR+"」，长袖翻飞，躲过$N这一招。\n",
"却见$n「"+HIW+"万顷江田一鹭飞"+NOR+"」，冲天而起，一波三折，端是美观。\n",
"可是$n一个「"+BLU+"流水落花春去也"+NOR+"」，侧身一让，$N这一招扑了个空。\n",
"只见$n一招「"+HIW+"月轮穿沼水无痕"+NOR+"」，倒掠身形，凌空两个翻转，退出两丈开外。\n",
"$n息气上升，意存玉枕，一招「"+HIB+"月在青天影在波"+NOR+"」，身子飘然而起。\n",
});
int practice_level(){   return 90;  }
int valid_enable(string usage) { return (usage == "dodge"); }
int valid_learn(object me)
{
    if (me->query_skill("dodge", 1) <=me->query_skill("yueying-wubu", 1))
        return notify_fail("你的基础不够，无法领会更高深的技巧。\n");
    return 1;
}
string query_dodge_msg(string limb,object me)
{
        me->set_temp("fight/dodge",me->query_skill("yueying-wubu",1)/2);
        return dodge_msg[random(sizeof(dodge_msg))];
}
int practice_skill(object me)
{
    if( (int)me->query("qi") < 45 )
        return notify_fail("你的体力太差了，不能练月隐舞步。\n");
    me->receive_damage("qi", 35);
    return 1;
}
