#include <weapon.h>
inherit WHIP;
void create()
{
        set_name("���", ({ "yu gan", "bian" }) );
        set_weight(800);
                set("flag",2);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ��������ͺͲ�˿���ɵ���ˡ�\n");
                set("value", 300);
                set("material", "leather");
                set("wield_msg", "$N���һ��$n���������С�\n");
                set("unwield_msg", "$N�����е�$n�嵽����\n");
        }
        init_whip(15,2);
        setup();
}

int query_autoload() { return 1; }