// cai by -wyz
inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name(  "千島汁雞球" , ({"ball"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", WHT "这是一碟香喷喷的粵菜。\n" NOR);
                set("unit", "碟");
                set("value", 150);
                set("food_remaining", 3);
                set("food_supply", 60);
                set("eat_msg", "$N夹起一个$n，咬了一口,只觉的松脆无比。\n");
        }
}

