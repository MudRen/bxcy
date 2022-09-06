// bojuan-xia.c
inherit ITEM;
void create()
{
    set_name("帛卷", ({ "bo juan", "bo", "juan" }));
    set_weight(50);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "卷");
        set("long",
            "这是一卷帛卷，里面写着 ：\n"
            "庄子“逍遥游”有云：穷发之北有冥海者，天池也。有鱼焉，其广数千里。。。。\n");
        set("value", 500);
        set("material", "silk");
        }
}
void init()
{
    if( this_player() == environment() )
    {
    add_action("do_study", "study");
    add_action("do_study", "du");
    }
}
int do_study(string arg)
{
    mapping skl;
    string *sname;

    int i; int t;int nf;int j;int nh;int ts;int skl_level;
    object me = this_player();

    i = (int)me->query_skill("xiaowuxiang", 1);
    t = 1, j;
    for (j = 1; j < i / 10; j++) t*= 2;

    if (!arg || !id(arg))
        return notify_fail("你要读什么？\n");
    if (me->is_busy()) return notify_fail("你现在正忙着呢。\n");

    if (!me->query_temp("duxiaowu") ) { 
        set("skill", ([
            "name": "beiming-shengong", // name of the skill
            "exp_required": 0,  // minimum combat experience required
            "jing_cost":    10, // jing cost every time study this
            "difficulty":   20, // the base int to learn this skill
            "max_skill":    19  // the maximum level you can learn
        ]) );
    if (me->query("family/family_name")!="逍遥派") { 
        tell_object(me,"想学更高深的北冥神功，必须加入我逍遥派。\n"); 
        return 1;
        }
    if ( me->is_fighter()) return notify_fail("战斗中无法阅读新知！\n");
    if ( (int)me->query_skill("beiming-shengong",1) >= 20 
    && (int)me->query_skill("beiming-shengong",1) <= 100 )
    {
        me->receive_damage("jing", 20);
        me->improve_skill("beiming-shengong", (me->query_skill("beiming-shengong")
    +me->query_int()));
        message_vision("$N正在专心研读北冥神功心法。\n", me);
        return 1;
        }
    } else {
    if ((int)me->query_skill("force", 1) < 10)
        return notify_fail("你的基本内功火候不足，不能学小无相功。\n");
    if ( me->query("gender") == "无性" && i > 49)
        return notify_fail("你无根无性，阴阳不调，难以领会高深的小无相功。\n");
    if (me->query_skill("force",1)<=i)
        return notify_fail("你的基本内功基础不够，再学下去会走火入魔的。\n");
    if (i<= 404)
        return notify_fail("你的小无相功基础不够，再学下去会走火入魔的。\n");
    nf = (int)me->query_skill("force", 1);
    nh = (int)me->query_skill("xiaowuxiang", 1);
    skl = me->query_skills();
    sname  = keys(skl);
    for (i=0;i<sizeof(skl);i++){
        if (sname[i]=="hunyuan-yiqi") continue;
        if (sname[i]=="longxiang") continue;
        if (sname[i]=="xiaowuxiang") continue;
        if (sname[i]=="yijing-force") continue;
            if( SKILL_D(sname[i])->valid_enable("force") )
        return notify_fail("你不先散了别派内功，怎能学小无相功。\n");
    }
    if ( me->is_fighter()){
        tell_object(me,"战斗中无法阅读新知！\n");
        return 1;
    }
    if (me->query("jing")>20){
            me->receive_damage("jing", 20);
if (nh*3<nf)
               me->improve_skill("xiaowuxiang", (me->query_skill("xiaowuxiang")+me->query_int()));
     }
    message_vision("$N正在专心研读逍遥派心法。\n", me);
    return 1;
    }
    return 0;
}

int query_autoload() { return 1; }
