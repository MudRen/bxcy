// daocaoren.c
inherit ITEM;

void create()
{
        set_name("稻草人", ({"daocao ren", "ren"}));
        set_weight(700);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一个用稻草扎成的稻草人。\n");
                set("unit", "个");
                set("value", 10);
        }
}

int query_autoload() { return 1; }