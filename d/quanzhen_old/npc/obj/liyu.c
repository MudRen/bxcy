// liyu.c
#include <weapon.h>
inherit ITEM;

void create()
{
        set_name("鲤鱼", ({ "li yu", "yu" }) );
        set_weight(100);
                set("flag",2);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "条");
                set("long", "这是一条从江里钓上来的鲤鱼。\n");
                set("value", 3000);
                set("material", "leather");
        }
        setup();
}

int query_autoload() { return 1; }