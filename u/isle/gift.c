//gift.c

#include <ansi.h>
inherit ITEM;

void init()
{
        add_action("do_eat", "eat");  
}
void create()
{
        set_name(HIC"���ֵ�"NOR, ({"dan"}));          
        set("unit", "��");
        set("value", 0);
        set("long", "����һ��isle�͸���һ�ڼ�����Ѫ���������ֵ����\n");
        setup();

}
int do_eat(string arg)
{
        object me=this_player();
        if (!id(arg))  return notify_fail("��Ҫ��ʲô��\n");
        if (me->is_busy() )
                return notify_fail("�𼱣������ԣ�С�ı�ҭ���ˡ�\n");
        if (me->query("combat_exp")>500000)
              return notify_fail("��ʲô�����㶼���������˻���ԣ���\n");
        if (me->query("max_neili")>1000)
              return notify_fail("�������������ֵ�����,���С���ˣ�\n");
     else
        {
        me->set("combat_exp", 200000);                    
        me->add("potential", 5000);
        me->set("max_neili",2000);
        me->set("max_jingli",300);
        message_vision(HIW"$N����һ�����ֵ���һ�������ӵ������𣬶�ʱȫ�����������\n"NOR,me);
              me->start_busy(2);
        destruct(this_object());
        return 1;
}
}
