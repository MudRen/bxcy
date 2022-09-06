inherit ITEM;
void init()
{
    add_action("do_eat", "eat");
}
void create()
{
    set_name("雪参玉蟾丹", ({"yuchan dan", "dan"}));
    if (clonep())
        set_default_object(__FILE__);
    else {
        set("unit", "丸");
        set("long", "\n这是高丽进贡的灵药，服后解毒疗伤，灵验非凡。\n");
        set("value", 10000);
    }
    setup();
}
int do_eat(string arg)
{
    object me = this_player();
    if (!id(arg))
        return notify_fail("你要吃什么？\n");
    me->set("jing",me->query("max_jing"));
    me->set("eff_jing",me->query("max_jing"));
    me->set("eff_qi",me->query("max_qi"));
    me->set("qi",me->query("max_qi"));
    message_vision(HIW "$N吃下一粒雪参玉蟾丹，只觉一股浩荡真气直涌上来，
    急忙盘膝而坐，闭目运功...\n" NOR, me);
    destruct(this_object());
    return 1;
}
int query_autoload() { return 1; }