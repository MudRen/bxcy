
#include <weapon.h>
inherit WHIP;
void create()
{
        set_name("长鞭", ({ "whip" }) );
        set_weight(800);
                set("flag",2);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "条");
                set("long", "这是一条牛皮做的长鞭，十分结实。\n");
                set("value", 300);
		set("material", "leather");
                set("wield_msg", "$N抽出一条$n，握在手中。\n");
                set("unwield_msg", "$N放下手中的$n绑在腰间。\n");
        }
        init_whip(15,2);
        setup();
}
int query_autoload() { return 1; }