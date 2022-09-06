// medicine: xuelian.c
// Jay 3/18/96
inherit ITEM;
void setup()
{}
void init()
{
        add_action("do_eat", "eat");
}
void create()
{
        set_name("天山雪莲", ({"xuelian", "lian", "lotus"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "株");
                set("long", "这是一支只有在寒冷的地方才能生长的雪莲。\n");
                set("value", 100);
        }
        setup();
}
int do_eat(string arg)
{
    if (!id(arg))
    return notify_fail("你要吃什么？\n");
    this_player()->set("eff_qi", this_player()->query("max_qi"));
    this_player()->set("eff_jing", this_player()->query("max_jing"));
        message_vision("$N服下一株雪莲,顿觉精力百倍!\n", this_player());
    destruct(this_object());
    return 1;
}

int query_autoload() { return 1; }