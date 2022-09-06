// m_bian.c
#include <ansi.h>
#include <weapon.h>
inherit M_WEAPON;
int do_hui(object weapon);
void create()
{
        object me;
        string w_name,w_id,w_or;
        me = this_player();

        set_name( HIR "火" NOR HIY "龙" NOR HIB "鞭" NOR, ({ "huolong bian", "bian" }) );
        set_weight(150000);
                set("flag",2);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "条");
                set("long", "这是一条由火龙筋和雪蚕丝绞成的长鞭，把柄为千年寒玉雕镌而成。\n");
                set("material", "leather");
                set("wield_msg", HIY "半空中忽然传来阵阵清越的龙吟和尖锐的鬼啸之声............\n"
HIC "一" HIR "红" HIC "一" HIW"白" HIC "两条巨龙相互绞扭，忽兀落在$N的手中,一声霹雳，巨龙化作一条长鞭。\n" NOR);
                set("unwield_msg", HIC "一阵霹雳之声过后，$N手中的$n" HIC "忽然不见了。\n" NOR);
        }
//读入数据
        w_name=me->query("weapon/name");
        w_id = me->query("weapon/id");
        w_or = me->query("weapon/or");
        set("no_get",1);
        set("no_drop",1);
set("no_put",1);
        init_whip(1000,2);
        setup();
}
void init()
{
     if (this_player()!=environment()) return;
     add_action("do_hui","hui");
}
void create()
{   
    object me;
    string w_name,w_id,w_or;
    me = this_player();
//读入数据
    w_name=me->query("weapon/name");
    w_id = me->query("weapon/id");
    w_or = me->query("weapon/or");
    set("unit", "柄");   
    set("no_get",1);
    set("no_drop",1);
    setup();
}   
int do_hui(string weapon)
{   
    string w_name;
    object me;
    me=this_player();
    w_name=me->query("weapon/id");
    if( !weapon || w_name!=weapon)
        return notify_fail("你要摧毁什么?\n");
    message_vision(HIR "你大喝一声，一手擎鞭，一手猛的一扯。结果啪的一声爆响"
            +this_object()->name()+HIR+"断为两截!\n" NOR,me);
    me->delete("weapon");   
    me->save();
    destruct( this_object() );
    return 1;
}

