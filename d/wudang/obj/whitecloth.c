// white-robe.c 白色道袍
// By wyz
#include <armor.h>
inherit CLOTH;
void create()
{
    set_name( HIW "白衫" NOR, ({"cloth"}) );
    set_weight(4500);
    if( clonep() )
       set_default_object(__FILE__);
    else {
        set("unit", "件");
        set("long", "这是件素雅洁净的白色长衫。\n");
        set("material", "cloth");
        set("armor_prop/armor", 3);
    }
    setup();
}

int query_autoload() { return 1; }