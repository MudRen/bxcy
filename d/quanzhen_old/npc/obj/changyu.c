// changyu.c
#include <weapon.h>
inherit ITEM;

void create()
{
        set_name("鲳鱼", ({ "chang yu", "yu" }) );
        set_weight(100);
                set("flag",2);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "条");
                set("long", "这是一条从江里钓上来的鲳鱼。\n");
                set("value", 30000);
                set("material", "leather");
        }
        setup();
}

int query_autoload() { return 1; }