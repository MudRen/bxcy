
#include <weapon.h>
inherit SWORD;
int query_autoload(){return 0;}
void create()
{
	set_name("������", ({ "hudie sword", "sword" }));
	set_weight(6000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ������һ���Ĺֽ�,��������ԼԼ�к����ڷ���! \n");
		set("value", 0);
		set("material", "steel");
		set("wield_msg", "$N���һ��,$n���������ʶ���,���ĵĻ�����һ�ֺ��������š�\n");
		set("unwield_msg", "$N�����е�$n�����Ĳ�ؽ��ʡ�\n");
	}
	init_sword(-300,2);
	setup();
}
