// /clone/misc/xin.c
// WENWU   2003/8/1
#include <ansi.h>
#define XIN_NAME "信"	
inherit ITEM;
void create()
{
set_name(HIM + XIN_NAME + NOR, ({"xin"}));      	
set_weight(200);
if (clonep())
set_default_object(__FILE__);
else {
set("unit", "封");
set("long","这是一封龙云梦写给妻子冰雁的信,看起来似乎像情书.拆(chai)开来看看?");	
set("value", 0);
set("no_give",1);
set("no_get",1);
set("no_put",1);
set("no_drop",1);
}
setup();
}	
