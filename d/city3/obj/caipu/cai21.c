// cai by -wyz
inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name( "��֦�r��", ({"china cai", "lychee"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", WHT "����һ��������Ļ��ˡ�\n" NOR);
                set("unit", "��");
                set("value", 150);
                set("food_remaining", 3);
                set("food_supply", 60);
        }
}

