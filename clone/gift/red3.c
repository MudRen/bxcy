// lingzhi.c ǧ����֥
//����(lywin)2000/4/22

#include <ansi.h>
inherit ITEM;

void setup()
{}

void init()
{
        add_action("do_eat", "eat");

}
void create()
{
        set_name(HIR"ȱ�¾�ʿ"NOR, ({"damenly"}));
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

                set("unit", "ͷ");
                set("long", "ȱ�¾�ʿ�Ǻ����һ�Ķ��ˣ������Գ������������\n");
		set("value", 0);
	}
	setup();
}

int do_eat(string arg)
{
	if (!id(arg))
        return notify_fail("��Ҫ��ʲô��\n");
        this_player()->start_busy(50);

        this_player()->add("potential",2000);
        message_vision("$N����һͷȱ�¾�ʿ����������ĳ���Ѭ�ö������ã����û����2000������(pot)\n", this_player());
	destruct(this_object());
	return 1;
}

void owner_is_killed()
{
	destruct(this_object());
}
