
#include <weapon.h>
inherit SWORD;
int query_autoload(){return 0;}
void create()
{
	set_name("蝴蝶剑", ({ "hudie sword", "sword" }));
	set_weight(6000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "这是一柄蝴蝶一样的怪剑,上面隐隐约约有蝴蝶在飞舞! \n");
		set("value", 0);
		set("material", "steel");
		set("wield_msg", "$N轻哼一声,$n自手中呤呤而出,幽幽的还带着一种蝴蝶的优雅。\n");
		set("unwield_msg", "$N将手中的$n慢慢的插回剑鞘。\n");
	}
	init_sword(-300,2);
	setup();
}
