inherit ITEM;
void init()
{
add_action("do_eat", "eat");
}
void create()
{
set_name("����������", ({"liqi wan", "dan"}));
if (clonep())
set_default_object(__FILE__);
else {
set("unit", "��");
set("value", 1000000);
set("long", "����һ�źں�����ҩ�衣\n");
}
}
int do_eat(string arg)
{
if (!id(arg))
return notify_fail("��Ҫ��ʲôҩ��\n");
else{
this_player()->set("shen",0);
message_vision("$N����һ��������,����������ˬ����ࡣ\n", this_player());
destruct(this_object());
return 1;
}
}
