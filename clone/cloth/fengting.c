// hat.c example belt

#include <ansi.h>

inherit EQUIP;

void create()
{
set_name( HIY "风霆云巾" NOR, ({ "fengting yunjin","fengting","yunjing","hat" }) );
set_weight(1000);
if( clonep() )
set_default_object(__FILE__);
else {
set("unit", "顶");
set("value", 5000000);
set("material", "cloth");
set("armor_type", "head");
set("armor_prop/personality", 3);
set("armor_prop/karma", 10);
set("armor_prop/armor", 100);
set("armor_prop/dodge", 30);
set("wear_msg","$N戴上一顶$n。\n");
set("remove_msg","$N将$n脱了下来。\n");
}
}
int query_autoload() { return 1; }	
