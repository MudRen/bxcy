// expsword.c 零攻击剑法
// Wenwu 2003.8.25
#include <weapon.h>	
inherit SWORD;	
void create()	
{	
set_name("风雷剑", ({ "fenglei jian","sword","fenglei", "jian" }));
set_weight(5000);	
if (clonep())	
set_default_object(__FILE__);	
else {	
set("unit", "把");	
set("long", "这是一把攻击力为负数的剑，江湖人士通常都是用它来刷经验。\n");      	
set("value", 0);	
set("material", "steel");	
}	
init_sword(-500,2);             	
setup();	
}	
