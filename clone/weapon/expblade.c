// expblade.c 负攻击刀
// Wenwu 2003.8.25
#include <weapon.h>	
inherit BLADE;   	
void create()	
{	
set_name("风云刀", ({ "fengyun dao","blade","fengyun", "dao" }));	
set_weight(5000);	
if (clonep())	
set_default_object(__FILE__);	
else {	
set("unit", "柄");              	
set("long", "这是一柄攻击力为负数的刀，江湖人士通常都是用它来刷经验。\n");                      	
set("value", 0);	
set("material", "steel");	
}	
init_blade(-500,2);                      	
setup();	
}	
