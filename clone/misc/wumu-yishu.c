// Obj: /d/ruzhou/npc/obj/marry-book.c 结婚须知
#include <ansi.h>

inherit ITEM;

void init()
{
        add_action("do_read", "fan");
}

void create()
{
set_name("《武穆遗书》", ({ "wumu yishu", "yishu","book"}));	
	set("weight", 600);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("value", 500);
		set("material", "paper");
set("long", "相传这本书为岳飞所著，书中记载了他多年用兵征战的经验，以及他一身之绝世武功。你可以翻阅(fan)它。\n");
	}
	setup();
}

int do_read(string arg)
{
if (!arg||(arg!="wumu yishu"&&arg!="yishu"))	
        return notify_fail("你没有这本书，乱翻口袋干什么？\n");
    this_player()->start_more(read_file("/d/nanyang/marry"));
    return 1;
}

int query_autoload() { return 1; }
