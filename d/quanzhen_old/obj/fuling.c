// fuling.c ����
// By Lgg,1998.10

inherit ITEM;
#include <ansi.h>

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name(YEL"����"NOR, ({"fuling"}));
        set_weight(500);
        set("unit", "��");
        set("long", "����һ����͵����ߣ�����������ҩ��\n");
        setup();
}

int do_eat(string arg)
{
        if (!(arg))  return notify_fail("��Ҫ��ʲô��\n");
        if(arg=="fuling")
        {
                write("���������ڰ����߳�����ȥ��\n");
                destruct(this_object());
        }
        return 1;
}
int query_autoload() { return 1; }