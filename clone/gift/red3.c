// lingzhi.c 千年灵芝
//星星(lywin)2000/4/22

#include <ansi.h>
inherit ITEM;

void setup()
{}

void init()
{
        add_action("do_eat", "eat");

}
void create()
{
        set_name(HIR"缺德居士"NOR, ({"damenly"}));
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

                set("unit", "头");
                set("long", "缺德居士是海洋第一的恶人，您可以吃了他来解解气\n");
		set("value", 0);
	}
	setup();
}

int do_eat(string arg)
{
	if (!id(arg))
        return notify_fail("你要吃什么？\n");
        this_player()->start_busy(50);

        this_player()->add("potential",2000);
        message_vision("$N吃了一头缺德居士，结果被他的臭气熏得动弹不得，还好获得了2000的灵气(pot)\n", this_player());
	destruct(this_object());
	return 1;
}

void owner_is_killed()
{
	destruct(this_object());
}
