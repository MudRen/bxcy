
#include <weapon.h>
inherit STAFF;
void create()
{
     set_name("禅杖", ({ "chan zhang","zhang"}));
        set_weight(3000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long", "这是一根铁铸禅杖，轻重合宜。\n");
                set("value", 200);
                set("material", "steel");
                set("wield_msg", "$N抽出一根$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插回腰间。\n");
        set("shaolin",1);
        }
        init_staff(15,1);
        setup();
}
int query_autoload() { return 1; }