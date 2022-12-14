// Room: /d/shaolin/damodong.c
// Date: YZC 96/01/19
inherit ROOM;
void create()
{
    set("short", "达摩洞");
    set("long", @LONG
这里是达摩古洞。五百年前南天竺僧人菩提达摩来到少林寺，见
此风水宝地，就住下来广罗弟子，传授禅宗，开创少林寺佛教禅宗千
年不败之基。达摩祖师常在此面壁悟道，一坐十年，壁间隐隐似仍可
看到他面壁时的打坐姿态。除地上的几块竹片外，洞中空无一物。
LONG
    );
    set("exits", ([
        "out" : __DIR__"qfdian",
    ]));
    set("objects",([
        "d/shaolin/obj/book-bamboo" : 1,
        CLASS_D("shaolin") + "/damo" : 1,
    ]));
    setup();
}
void init()
{
    object me = this_player();
    if ((int)me->query_temp("bamboo/count") == 14 
    &&  (int)me->query_skill("dodge", 1) >= 30 
    &&  (int)me->query_skill("dodge", 1) <= 100 
    &&  present("bamboo", me) )
    {
        me->receive_damage("jing", 20);
        me->improve_skill("dodge", me->query_int());
        me->delete_temp("bamboo/count");
    }
        add_action("do_mianbi","面壁"); 
        add_action("do_mianbi","mianbi");   
}
int do_mianbi()
{
    object me = this_player();
    int buddhism=me->query_skill("buddhism");
    if (me->is_busy()) return notify_fail("你面对着达摩洞後半边的石壁跌坐静思......\n");
    if (me->is_fighting()) return notify_fail("你现在能坐下来面壁么？\n");
    if (buddhism>200)
    message_vision("$N面对着达摩洞後半边的石壁跌坐静思，良久，似有所悟。\n", me);
    else{
    message_vision("$N面对着达摩洞後半边的石壁跌坐静思，良久，累得腰酸腿痛。\n", me);
    return 1;
    }
    
    me->start_busy(3);
   if (me->query("shen")>0){
    if (me->query("shen")-buddhism*2<0)
    me->set("shen",0);
    else
    me->add("shen",-buddhism*2);
  }else{
    if (me->query("shen")+buddhism*2<0)
    me->set("shen",0);
    else
    me->add("shen",buddhism*2);
  }
    return 1;
}

