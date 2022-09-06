 
//#include <npc.h>

//inherit F_VILLAGER;
inherit F_VENDOR;
inherit NPC;
int on_service = 0;

void create()
{
	set_name("小郦", ({ "xiao li", "li" }) );
        set("gender", "女性" );
        set("age", 18);
        set_temp("apply/attack", 25);
        set_temp("apply/defense", 25);
        set("combat_exp", 2000);
        set("mingwang", 10);
        set("str", 5);
        set("kar", 10);
        set("con", 8);
        set("int", 5);
        set("attitude", "friendly");
	set("long",
		"她是小静的妹妹，一个约十几岁的小姑娘，正忙进忙出帮小静做家务，\n"
		);
	set("chat_chance", 4);
	set("merchandise", ([
		"/u/caac/obj/tea": 50,
		"/u/caac/obj/dianxin": 50,
	]));

	setup();
}

void init()
{
	::init();
	add_action("do_vendor_list", "list");
}


/*int accept_fight(object ob)
{
	do_chat("小郦了个鬼脸，说道：客人要打架的话，我可不是对手　\n");
	return 0;
}*/

mixed affirm_merchandise(object customer, string item_name)
{
	if( on_service == 1)
		return notify_fail("小郦正忙著招呼其他客人，请你等一会儿　\n");
	//return ::affirm_merchandise(customer, item_name);
}

private void handover(object customer, mixed item)
{
	on_service = 0;
	if( !customer || environment(customer)!=environment() ) {
		command("say 咦？刚刚那位客倌人呢？怎麽人不见了 ...");
		say("小郦把端出来的" + item->name() + "又端了回去　\n");
		return;
	}
	command("say 您的" + item->name() + "来啦！");
	message_vision("$N把刚从厨房端出来的" + item->name()
		+ "送到$n面前　\n", this_object(), customer);
	//::deliver_merchandise(customer, item);
}

void deliver_merchandise(object customer, mixed item)
{
	command("say " + item->name() + "是吧？马上来！");
	say("小郦一边跑向厨房，一边喊道：" + item->name() + "一份！嘻嘻！\n");
	on_service = 1;
	//do_chat((: handover, customer, item :));
}
