//potential dan.c
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
        set_name(HIR"Ǳ�ܵ�"NOR, ({"potential dan", "dan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�źڰ���ɫ��Ǳ�ܵ���������isle�������ƣ�
��˲������Ǳ��֮Ч��\n");
                set("value", 250000);
        }
        setup();
}

int do_eat(string arg)
{
        object me = this_player();
        if (!id(arg))
        return notify_fail("��Ҫ��ʲô��\n");
        me->add("potential",500);
        if (me->query("potential")>500000)
        return notify_fail("���Ǳ��̫����,��Ȼ,Ǳ�ܵ�������������!");
        message_vision(HIR"$N����һ��Ǳ�ܵ�,$N��Ǳ�������ˣ�\n"NOR,me);
        destruct(this_object());
        return 1;
}
