// gangjian.c

#include <weapon.h>
inherit BLADE;

void create()
{
	set_name("��ͨذ��", ({ "dagger", "bishou" }));
	set_weight(6000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ����ͨ��Сذ�ס�����������˱ȽϺ��ʡ�\n");
		set("value", 2000);
		set("material", "steel");
		set("wield_msg", "$N�Ӷ����ͳ�һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n�Żᶵ�\n");
	}
        init_blade(10);
	setup();
}
int query_autoload() { return 1; }