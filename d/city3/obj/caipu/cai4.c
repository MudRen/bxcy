// cai by -wyz
inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name(  "小龙粉蒸牛肉" , ({ "powder" }));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", WHT "这是一碟香喷喷的四川名菜。\n" NOR);
                set("unit", "碟");
                set("value", 150);
                set("food_remaining", 3);
                set("food_supply", 60);
                set("eat_msg", "$N颤手颤脚地夹起一块$n，咬了一口，差点把自己的舌头也吞了下去。\n");
        }
}

