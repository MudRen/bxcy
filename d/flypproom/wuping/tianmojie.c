// shou zhuo.c

#include <armor.h>
#include <ansi.h>

inherit FINGER;

void create()
{
set_name(HIB "天魔戒" NOR, ({ "tianmo ring", "ring" }));
set("long", "这就是传说中的天魔戒，戒身墨黑，散发出淡淡的蓝光！一阵阵强烈的杀气从里面不断传出，你拿在手上总觉得哪里不对劲。\n");
set("weight", 400);
if (clonep())
set_default_object(__FILE__);
else {
set("material", "gold");
set("unit", "只");
set("armor_prop/personality", 5);
set("armor_prop/karma", 5);
set("armor_prop/intelligence", 5);
set("armor_prop/unarmed", 100);
//set("armor_prop/armor_vs_force", 10);	
set("value", 5000000);
set("no_get",1);
set("wear_msg", GRN "$N右手食指向天空一指，"HIR"登时杀气冲天，"HIW"风云变色，雷电交加,"NOR"一只墨黑的$n已然在手" NOR);
set("remove_msg", GRN "$N脱下$n ，如获释重，长长的叹了口气...。" NOR);
set("armor_prop/armor", 1000);
}
setup();
}
int query_autoload() { return 1; }
