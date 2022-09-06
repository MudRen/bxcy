// jinchuang.c ��ҩ
inherit ITEM;
void setup()
{}
void init()
{
	add_action("do_eat", "eat");
}
void create()
{
	set_name("��ҩ", ({"jinchuang yao", "jin", "jinchuang","yao"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ��������ʿ�ر��Ľ�ҩ��\n");
		set("value", 5000);
	}
	setup();
}
int do_eat(string arg)
{
	int max_qi,eff_qi;
	if (!id(arg))
		return notify_fail("��Ҫ��ʲôҩ��\n");
	max_qi=this_player()->query("max_qi");
	eff_qi=this_player()->query("eff_qi");
	if (eff_qi == max_qi)
		return notify_fail("�����ڲ���Ҫ�ý�ҩ��\n");
	else {
		if (eff_qi+max_qi/4>max_qi)	max_qi-=eff_qi;
		else max_qi /= 4;
		this_player()->receive_curing("qi", max_qi);
		message_vision("$N����һ����ҩ����ɫ�������ö��ˡ�\n", this_player());
		destruct(this_object());
		return 1;
	}
}
int query_autoload() { return 1; }