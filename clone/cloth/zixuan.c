// zixuan pifeng.c

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
set_name(MAG"紫璇披风"NOR, ({ "zixuan pifeng", "zixuan","pifeng" }));
set_weight(2000);
if (clonep())
set_default_object(__FILE__);
else {
set("long", "传说中神奇的披风。\n");
set("material", "cloth");
set("unit", "件");
set("no_sell",1);
set("armor_prop/personality", 5);
set("armor_prop/karma", 5);
set("armor_prop/intelligence", 3);
set("armor_prop/dodge", 100);
//set("armor_prop/armor_vs_force", 10);	
set("value", 10000000);
set("wear_msg", CYN "只闻霹雳乍响，平空漫出一股七彩云雾,$N伸手一指云气中陡然现出一件霞光万道的$n，$n"CYN"轻轻地落在$N肩上。\n"	
HIM"瞬时间天地风云色变，雷电交加，呈现出一片萧杀之气。\n" NOR);
set("remove_msg", GRN "$N双肩一抖，$n幻化成一片霞雾逐渐消失不见。\n" NOR);
set("armor_prop/armor", 1000);
}
setup();
}
int query_autoload() { return 1; }
