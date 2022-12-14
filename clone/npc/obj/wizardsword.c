// longsword.c 长剑
#include <weapon.h>
inherit SWORD;
void create()
{
    set_name(MAG "天神之剑" NOR, ({ "sword", "jian" }));
    set_weight(9000);
    if (clonep())
        set_default_object(__FILE__);
    else {
        set("unit", "柄");
        set("long", "这是一柄天神之剑。听说是天神用来自杀的东东。\n");
        set("no_sell",1);
        set("material", "steel");
        set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。$N刹那间双目尽赤。一副想杀人的样子\n");
        set("unwield_msg", "$N将手中的$n插回剑鞘。\n");
    }
    init_sword(200,2);
    setup();
}
void init()
{
    add_action("do_kill","kill");
}
int do_kill(string arg)
{
    object me,obj;
    if (!this_object()->query("equipped")) return 0;
    me=this_player();
    if (!userp(me) )
        return 0;
    if (!arg)   return 0;
    if(!objectp(obj = present(arg, environment(me))))
        return notify_fail("这里没有这个人。\n");
    if (userp(obj) ){
        message_vision("\n$N对著$n喝道：「" 
        + RANK_D->query_rude(obj) + "！今日不是你死就是我活！」\n\n", me, obj);
        tell_object(obj, HIR "如果你要和" + me->name() 
            + "性命相搏，请你也对这个人下一次 kill 指令。\n" NOR);
        tell_object( me,
        HIR "\n\n你决定要自杀了，如果四十秒内不後悔，就真的永别了。\n\n\n" NOR);
        CHANNEL_D->do_channel(this_object(),"rumor",me->name() + "决定要自杀了。");
        me->start_busy(40);
        call_out("slow_suicide",5,me,40);
        return 1;
    }
}
protected int slow_suicide(object me,int sec)
{
    if (!me)    return 0;
    sec-=5;
    if (sec>1){
        tell_object(me, RED "\n\n\n你还有"+YEL+chinese_number(sec)+"秒"+RED+"的时间可以後悔。\t\t"+HIW+"如果你後悔了，请马上退出(quit)游戏。\n\n\n" NOR);
        call_out("slow_suicide",5,me,sec);
    }else   call_out("do_suicide",1,me);
    return 1;
}
int do_suicide(object me)
{
    object link_ob;
    if (!me)    return 0;
    link_ob = me->query_temp("link_ob");
    if( !link_ob ) return 0;
    seteuid(ROOT_UID);
    write("好吧，永别了:)。\n");
    tell_room(environment(me), me->name() +"自杀了，以後你再也看不到这个人了。\n", ({me}));
    me->save();
    destruct(me);
    return 0;
}
int query_autoload() { return 1; }