// lingzhi.c 千年灵芝
//星星(lywin)2000/4/22

#include <ansi.h>
inherit ITEM;

void setup()
{}

void init()
{
        add_action("do_eat", "kai");

}
void create()
{
        set_name(HIR"飞飞飞飞机"NOR, ({"sos"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
    set("no_give","每个人只有一个，你都这么大方！\n");
    set("value", 0);
set("no_steal",1);
set("no_beg",1);
    set("no_put",1);
    set("no_get","每个人只有一个，不要这么贪心！\n");
    set("no_drop","这么珍贵的东西你也扔？！\n");

                set("unit", "架");
                set("long", "飞飞飞飞机是海洋屠人场专机,想死的大侠，您可以来开(kai)他\n");
                set("no_give", 1);
		set("value", 0);
	}
	setup();
}

int do_eat(string arg)
{
if (this_player()->query("combat_exp") <100000)
  return notify_fail("只有经验大于100000才能进入！\n");
	if (!id(arg))
        return notify_fail("你要开什么？\n");
        this_player()->move("/d/pk/pk/entry");

	this_player()->add("combat_exp", 500);
	this_player()->add("potential",200);
        message_vision("$N坐上了一架飞飞飞飞机，飞到了屠人场，并获得了出场费的奖励\n", this_player());
	destruct(this_object());
	return 1;
}

void owner_is_killed()
{
	destruct(this_object());
}
