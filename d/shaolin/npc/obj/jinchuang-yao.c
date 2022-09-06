// jinchuang.c 金创药
inherit ITEM;
void setup()
{}
void init()
{
	add_action("do_eat", "eat");
}
void create()
{
	set_name("金创药", ({"jinchuang yao", "jin", "jinchuang","yao"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "包");
		set("long", "这是一包武林人士必备的金创药。\n");
		set("value", 5000);
	}
	setup();
}
int do_eat(string arg)
{
	int max_qi,eff_qi;
	if (!id(arg))
		return notify_fail("你要吃什么药？\n");
	max_qi=this_player()->query("max_qi");
	eff_qi=this_player()->query("eff_qi");
	if (eff_qi == max_qi)
		return notify_fail("你现在不需要用金创药。\n");
	else {
		if (eff_qi+max_qi/4>max_qi)	max_qi-=eff_qi;
		else max_qi /= 4;
		this_player()->receive_curing("qi", max_qi);
		message_vision("$N吃下一包金创药，气色看起来好多了。\n", this_player());
		destruct(this_object());
		return 1;
	}
}
int query_autoload() { return 1; }