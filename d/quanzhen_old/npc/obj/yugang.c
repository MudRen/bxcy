#include <weapon.h>
inherit WHIP;
void create()
{
        set_name("鱼杆", ({ "yu gan", "bian" }) );
        set_weight(800);
                set("flag",2);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "杆");
                set("long", "这是一杆用青竹竿和蚕丝做成的鱼杆。\n");
                set("value", 300);
                set("material", "leather");
                set("wield_msg", "$N抽出一杆$n，握在手中。\n");
                set("unwield_msg", "$N把手中的$n插到腰后。\n");
        }
        init_whip(15,2);
        setup();
}

int query_autoload() { return 1; }