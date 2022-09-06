//potential dan.c
#include <ansi.h>
inherit ITEM;
void setup()
{}
void init()
{
        add_action("do_eat", "eat");
}
void create()
{
        set_name(NOR"潜能丹"NOR, ({"potential dan", "dan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "颗");
                set("long", "这是一颗黑白两色的潜能丹，经天神isle精心练制，
有瞬间提升潜能之效。\n");
                set("value", 250000);
        }
        setup();
}

int do_eat(string arg)
{
        object me = this_player();
        if (!id(arg))
        return notify_fail("你要吃什么？\n");
        me->add("potential",500);
        if (me->query("potential")>500000)
        return notify_fail("你的潜能太多了,显然,潜能丹对你已无作用!");
        message_vision(HIR"$N吃下一颗潜能丹,$N的潜质提升了！\n"NOR,me);
        destruct(this_object());
        return 1;
}
