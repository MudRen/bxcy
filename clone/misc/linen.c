// linen.c

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name(WHT "?ֲ???" NOR, ({ "linen" }) );
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "cloth");
		set("unit", "??");
		set("value", 40);
		set("armor_prop/armor", 2);
	}
	setup();
}
int query_autoload() { return 1; }