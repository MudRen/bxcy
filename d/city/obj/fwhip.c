
#include <weapon.h>
inherit WHIP;
void create()
{
        set_name(HIG "������" NOR, ({ "whip" }) );
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ����֦���ɵĳ��ޣ�ʮ�ֽ�ʵ��\n");
                set("value", 300);
		set("weapon_prop/dodge",15);
		set("weapon_prop/damage",15);
		set("material", "leather");
                set("wield_msg", "$N���һ��$n���������С�\n");
                set("unwield_msg", "$N�������е�$n�������䡣\n");
        }
        init_whip(15,2);
        setup();
}
int query_autoload() { return 1; }