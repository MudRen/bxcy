// xuan-cloth.c
//
#include <armor.h>
inherit CLOTH;
void create()
{
        set_name("����", ({ "cloth" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
            set("shaolin",1);
                set("material", "cloth");
        set("armor_prop/intelligence", 3000);
                set("armor_prop/armor", 50);
        }
        setup();
}

int query_autoload() { return 1; }