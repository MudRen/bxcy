// cloth.c
//

#include <armor.h>

inherit CLOTH;
#include <ansi.h>
void create()
{
        set_name("????ɢ??ȹ", ({ "silver skirt" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "??");
                set("long", "һ?????ߵ???׺????????ȹ\n");
                set("material", "cloth");
                set("value", 10000);
                set("armor_prop/armor", 3);
        }
        setup();
}
int query_autoload() { return 1; }