//bye enter

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
	set_name(HIY"金蛇剑"NOR, ({ "jinshe jian", "jian" }));
        set_weight(50000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "这是一柄金蛇郎君夏雪宜赖之成名的金蛇剑。\n"+
                            "只见那剑形状甚为古怪，整柄剑就如是一条蛇\n"+
                            "盘曲而成，蛇尾勾成剑尖，蛇舌伸出分叉，是\n"+
                            "以剑尖竟是两叉。这剑金光灿烂，握在手中甚\n"+
                            "沉重，看来竟是黄金混合了其他五金所铸，剑\n"+
                            "身上一道血痕，发出碧油油的暗光，甚是诡异。\n");
		set("value", 1000000);
		set("material", "steel");
		set("weapon_prop/strength", 10);
		set("wield_msg", HIR "只听「铮」的一声，"HIY"金蛇剑"NOR""HIR"脱鞘飞出，自行跃入$N掌中。
剑刃微微摇晃，剑上碧绿的血痕映着灯光，似一条活蛇不住扭动身子。\n" NOR);
		set("unwield_msg", HIR ""HIY"金蛇剑"NOR""HIR"自$N掌中飞起，在空中划了个怪异的弧线，「唰」地跃入剑鞘。\n" NOR);
	}
        init_sword(400,2);
	setup();
}
int query_autoload() { return 1; }