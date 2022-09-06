// tielianzi.c
 
#include <weapon.h>
 
inherit THROWING;
 
void create()
{
	set_name("铁莲子", ({ "tie lianzi", "lianzi", "zi" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "精铁打制的莲子状暗器。\n");
		set("value",100);
		set("unit", "把");
		set("base_unit", "粒");
		set("base_weight", 1);
		set("base_value", 1);
		set("damage", 5);	//Here the damage=int_throwing, added by King
	}
	set_amount(10);
	init_throwing(5);
	setup();
}
int query_autoload() { return 1; }