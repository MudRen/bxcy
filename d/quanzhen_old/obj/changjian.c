// changjian.txt



#include <weapon.h>

inherit SWORD;



void create()

{

        set_name("长剑", ({ "chang jian", "sword" }));

        set_weight(6000);

        if (clonep())

                set_default_object(__FILE__);

        else {

                set("unit", "柄");

                set("long", "这是一柄普普通通的长剑，。\n");

                set("value", 2000);

                set("material", "steel");

                set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");

                set("unwield_msg", "$N将手中的$n插回剑鞘。\n");

        }

        init_sword(30);

        setup();

}
