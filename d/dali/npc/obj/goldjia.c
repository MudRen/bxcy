// tiejia.c ����
//

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("[1;33m�ƽ��[2;37;0m", ({ "armor" }) );
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "steel");
		set("value", 2000);
                set("armor_prop/armor", 100);
        }
        setup();
}
int query_autoload() { return 1; }
