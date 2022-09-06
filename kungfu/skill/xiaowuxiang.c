//
// xiaowuxiang.c 小无相功
// by secret
// 1997-1-16
//
inherit FORCE;
int valid_enable(string usage) { return usage == "force"; }
int valid_learn(object me)
{
    mapping skl;
    string *sname;
    int i = (int)me->query_skill("xiaowuxiang", 1);
    int t = 1, j;
    for (j = 1; j < i / 10; j++) t*= 2;
    if (((string)me->query("class") != "bonze") && i > 29)
        return notify_fail("你不是僧人，学不了高深的小无相功。\n");
    if ((int)me->query_skill("force", 1) < 10)
        return notify_fail("你的基本内功火候不足，不能学小无相功。\n");
    if ( me->query("gender") == "无性" && i > 49)
        return notify_fail("你无根无性，阴阳不调，难以领会高深的小无相功。\n");
    if (me->query_skill("force",1)<=i)
        return notify_fail("你的基本内功基础不够，再学下去会走火入魔的。\n");
    skl = me->query_skills();
    sname  = keys(skl);
    for (i=0;i<sizeof(skl);i++){
//            if (sname[i]=="hunyuan-yiqi") continue;	
        if (sname[i]=="longxiang") continue;
        if (sname[i]=="xiaowuxiang") continue;
        if (sname[i]=="yijing-force") continue;
            if( SKILL_D(sname[i])->valid_enable("force") )
        return notify_fail("你不先散了别派内功，怎能学小无相功。\n");
    }
    return 1;
}
int practice_skill(object me)
{
    return notify_fail("小无相功只能用学(learn)的来增加熟练度。\n");
}
string exert_function_file(string func)
{
    return __DIR__"xiaowuxiang/" + func;
}
