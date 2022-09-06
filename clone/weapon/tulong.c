//tulong.c

#include <weapon.h>

inherit BLADE;

void create()
{
set_name(HIW HIY"屠龙刀"NOR, ({ "tulong dao", "blade","tulong","dao" }) );	
set_weight(15000);
if( clonep() )
set_default_object(__FILE__);
else {
set("unit", "把");
set("weapon_prop/strength", 25);
set("weapon_prop/karma", 10);
set("weapon_prop/dodge", 100);
set("weapon_prop/blade", 100);
set("weapon_prop/constitution", 5); 
set("value", 5000000);	
set("material", "iron");
set("long", "传说中的屠龙宝刀，刀身不时透出阵阵杀气让人泛寒。\n" );
set("wield_msg",HIB"一道寒光闪过，$N已将$n"+HIB"握在手中，周围顿时杀气弥漫令人窒息，你不禁机伶伶的打个寒战。"NOR+"\n"NOR);	
set("unwield_msg", YEL"$N将$n"+YEL"回归鞘内，华光敛尽，你顿感压力大减不禁暗暗松了口气。"NOR+"\n"NOR);
}
init_blade(500,1);	
setup();
}
int query_autoload() { return 1; }	
