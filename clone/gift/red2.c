// lingzhi.c ǧ����֥
//����(lywin)2000/4/22

#include <ansi.h>
inherit ITEM;

void setup()
{}

void init()
{
        add_action("do_eat", "kai");

}
void create()
{
        set_name(HIR"�ɷɷɷɻ�"NOR, ({"sos"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
    set("no_give","ÿ����ֻ��һ�����㶼��ô�󷽣�\n");
    set("value", 0);
set("no_steal",1);
set("no_beg",1);
    set("no_put",1);
    set("no_get","ÿ����ֻ��һ������Ҫ��ô̰�ģ�\n");
    set("no_drop","��ô���Ķ�����Ҳ�ӣ���\n");

                set("unit", "��");
                set("long", "�ɷɷɷɻ��Ǻ������˳�ר��,�����Ĵ���������������(kai)��\n");
                set("no_give", 1);
		set("value", 0);
	}
	setup();
}

int do_eat(string arg)
{
if (this_player()->query("combat_exp") <100000)
  return notify_fail("ֻ�о������100000���ܽ��룡\n");
	if (!id(arg))
        return notify_fail("��Ҫ��ʲô��\n");
        this_player()->move("/d/pk/pk/entry");

	this_player()->add("combat_exp", 500);
	this_player()->add("potential",200);
        message_vision("$N������һ�ܷɷɷɷɻ����ɵ������˳���������˳����ѵĽ���\n", this_player());
	destruct(this_object());
	return 1;
}

void owner_is_killed()
{
	destruct(this_object());
}
