#include <ansi.h>
#include <weapon.h>
 inherit HAMMER;
void create()
{
      set_name( HIW "����" NOR,({ "tie lun" ,"lun" ,"tielun" }));
    set_weight(5000);
    if (clonep())
        set_default_object(__FILE__);
    else {
        set("unit", "��");
                set("long",HIW "����һ�����������ķ���\n" NOR);
        set("value", 10000);
        set("material", "iron");
        set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
     set("unwield_msg","$N�����е�$n�Ż����䡣\n");
    }
    init_hammer(100,2);
    setup();
}
int query_autoload() { return 1; }