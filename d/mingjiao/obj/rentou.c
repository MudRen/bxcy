// rentou.c

#include <ansi.h>

inherit ITEM;

void setup()
{}
void create()
{
        set_name(RED"圆真的人头"NOR, ({"ren tou", "tou"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("value", 0);
        }
        setup();
}


