// lingyun.c

#include <ansi.h>
#include <armor.h>

inherit BOOTS;

void create()
{
set_name(YEL"凌云靴"NOR, ({ "lingyun xue","lingyun", "xue" }) 
);
set_weight(800);
if( clonep() )
set_default_object(__FILE__);
else {
set("material", "leather");
set("unit", "双");
set("long", "这是一双用凤羽做成的靴子，光滑柔韧，据说有轻身培元的效果。\n");	
set("value", 10000000);	
set("no_sell",1);
set("armor_prop/dodge", 50);
set("armor_prop/karma", 7);
set("armor_prop/constitution", 5);
set("armor_prop/intelligence", 3);
set("armor_prop/dexterity", 5);
set("armor_prop/personality", 3);
set("armor_prop/armor", 500);
set("wear_msg", CYN "$N穿上一双$n,"CYN"脚底眩出一道"HIM"七彩光华，"HIB"$N顿觉"HIC"全身一轻，"HIY"似欲"GRN"乘风而去。\n" NOR);	
set("remove_msg", GRN "华光顿敛，$N把$n轻轻地脱了下来。\n" NOR);	
}
setup();
}
int query_autoload() { return 1; }	
