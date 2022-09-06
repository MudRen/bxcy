#include <weapon.h>

inherit SWORD;
#include <ansi.h>

void create()
{
set_name(GRN"龙吟古剑"NOR, ({ "longyin jian", "jian","longyin", "sword" }) );
set_weight(8000);
if( clonep() )
set_default_object(__FILE__);
else {
set("weapon_prop/karma", 5);
set("weapon_prop/intelligence", 5);
set("weapon_prop/strength", 10);
set("unit", "把");
set("value", 10000000);	
set("material", "steel");
set("long", "这是一把龙形宝剑，剑柄刻有一条昂首长吟的青龙，旁注“龙吟”两字，据说是一神龙所化。\n");
set("wield_msg", HIC"天际忽然传来阵阵清越的龙吟声............\n"
HIG"半空中现出一条青光蒙蒙的巨龙，盘旋两匝化作一柄古剑落入$N的手中。\n"NOR);
set("unwield_msg", HIC "一条青色神龙腾空跃起，$N手中的$n" HIC"忽然消失不见。\n"NOR);
} 

init_sword(500,2);	
setup();
}
int query_autoload() { return 1; }
