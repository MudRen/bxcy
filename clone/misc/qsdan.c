inherit ITEM;
void init()
{
add_action("do_eat", "eat");
}
void create()
{
set_name("清心镇气丸", ({"liqi wan", "dan"}));
if (clonep())
set_default_object(__FILE__);
else {
set("unit", "颗");
set("value", 1000000);
set("long", "这是一颗黑呼呼的药丸。\n");
}
}
int do_eat(string arg)
{
if (!id(arg))
return notify_fail("你要吃什么药？\n");
else{
this_player()->set("shen",0);
message_vision("$N吃下一颗理气丸,觉得心里清爽了许多。\n", this_player());
destruct(this_object());
return 1;
}
}
