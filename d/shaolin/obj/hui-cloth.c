// hui-cloth.c
//
#include <armor.h>
inherit CLOTH;
void create()
{
        set_name("�಼�������", ({ "jia sha", "cloth" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
            set("shaolin",1);
            set("material", "cloth");
                set("armor_prop/armor", 8);
        }
        setup();
}
int query_autoload() { return 1; }