// wenwu 2003.9.12
// qiankun baojia.c	
#include <armor.h>
#include <ansi.h>	
inherit ARMOR;	
void create()	
{	
set_name(HIC "乾"YEL"坤"HIM"宝甲" NOR,({ "qiankun baojia","baojia","armor", }) ); 	
set_weight(1000);	
if( clonep() )	
set_default_object(__FILE__);	
else	
{	
set("unit", "件");	
set("long", "一件玄奇的软甲,据说是天地间灵气凝结而成,。\n");	
set("material", "copper");	
set("value",0);	
set("no_get", "这样东西不能离开那儿。\n");	
set("no_drop", "这样东西不能离开你。\n");                           	
set("armor_prop/armor", 500);	
set("armor_prop/dodge", 100);	
set("armor_prop/force", 100);	
set("armor_prop/unarmed", 100);	
set("armor_prop/sword", 100);	
set("armor_prop/blade", 100);	
set("armor_prop/parry", 100);	
set("wear_msg", YEL "$N双手一抖，一件玄黄色软甲迎风展开轻飘飘地落在了$N的肩上,"GRN"$N的身影在$n"GRN"天蓝色云气里变得模糊不清。\n" NOR);	
set("remove_msg", YEL "$N凝神聚气伸手凭空一挥，$n"YEL"如风般飘起落入$N手中,$N的身形逐渐变得清晰。\n" NOR);	
}	
setup();	
}	
int query_autoload() { return 1; }	
