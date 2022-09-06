// 判官笔

#include <weapon.h>
inherit PEN;

void create()
{
	set_name("判官笔", ({ "panguanbi","pen" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "对");
		set("long", "这是一柄普通的精钢剑，一般的剑客都配带此剑。\n");
		set("value", 1500);
		set("material", "steel");
		set("wield_msg", "$N「唰」的一声抽出一对$n握在手中。\n");
//		set("unwield_msg", "$N将手中的$n插回剑鞘。\n");
	}
	init_pen(25);
	setup();
}
int query_autoload() { return 1; }