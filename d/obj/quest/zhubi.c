inherit ITEM;
#include <task.h>
#include <ansi.h>
void create()
{
        set_name("????", ({"Zhu bi", "bi"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "?????Ǳ???????\n");
                set("unit", "ֻ");
               set("owner_name","?쵤??");
               set("owner_id","zhu danchen");
        }
}
