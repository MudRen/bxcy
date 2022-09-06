// qimeigun.c 齐眉棍
// added bye host nov,24

#include <weapon.h>
inherit STAFF;

void create()
{
        set_name("齐眉棍" , ({ "qimeigun" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "根");
                set("long", "这是一根公门中的一种武器。\n");
		set("value", 1500);
		set("rigidity",100);
            set("material", "steel");
		set("wield_msg", "$N抽出一根$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回腰间。\n");
	}
  	init_staff(25);
	setup();
}
int query_autoload() { return 1; }