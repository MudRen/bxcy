inherit ITEM;


void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name("仙丹", ({"huanhun dan", "dan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "颗");
                set("long", "这是一颗由阿飞亲手练制药丸，用来奖励有贡献的玩家。\n");
        }
}
int do_eat(string arg)
{
        if (!id(arg))
             return notify_fail("你要吃什么药？\n");
 else{
       this_player()->add("combat_exp",50000);
       this_player()->add("potential",50000);
message_vision("$N吃下一颗仙丹，只觉得自己又变利害了一些 !\n", this_player());
        destruct(this_object());
        return 1;
        }
}

int query_autoload() { return 1; }
