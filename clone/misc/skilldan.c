inherit ITEM;
void init()
{
add_action("do_eat", "eat");
}
void create()
{
set_name("�ɵ�", ({"xian dan", "dan"}));
if (clonep())
set_default_object(__FILE__);
else {
set("unit", "��");
set("long", "����һ�źں�����ҩ�衣\n");
}
}
int do_eat(string arg)
{
object me=this_player();
if (!id(arg))
return notify_fail("��Ҫ��ʲôҩ��\n");
else{
message_vision("$N����һ���ɵ�,�����Լ��ֱ�������Щ��\n", this_player());
destruct(this_object());
return 1;
}
}
int query_autoload() { return 1; }
