// pink_cloth.c

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
	set_name(HIW "百褶罗裙" NOR, ({ "hiw cloth", "cloth" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "这件白色的绸衫上面绣着几朵百合花，闻起来还有一股淡香。\n");
		set("unit", "件");
		set("material", "cloth");
		set("armor_prop/armor", 1);
		set("armor_prop/personality", 3);
		set("female_only", 1);
	}
	setup();
}

