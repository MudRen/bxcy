// ITEM: shiquanwan.c
// Date: Qianyu 99/11/08

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
        set_name(HIC"ʮȫ����"NOR, ({"jiuhuayulu wan", "jiuhua wan", "wan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�ž�Ө������ʮȫ���裬������ǧ�������ƶ��ɣ�
���ú�����̩ͨ����������������\n");
                set("value", 1400000);
        }
        setup();
}

int do_eat(string arg)
{
        int fw;
        object me = this_player();

	if (!id(arg))  return notify_fail("��Ҫ��ʲô��\n");
	if (me->is_busy() )
		return notify_fail("�𼱣������ԣ�С�ı�ҭ���ˡ�\n");
	if(arg=="wan") 
	{
                     
	 	me->set("eff_jing",me->query("max_jing"));
		me->set("jing",me->query("max_jing"));
		me->set("eff_qi",me->query("max_qi"));
		me->set("qi",me->query("max_qi"));
		me->set("neili",me->query("max_neili"));
message_vision(HIC"$N����һ��ʮȫ���裬һ��������ˬ�Ե����͵�������ȫ����ɢ��\n"NOR,me);
		me->start_busy(1);
        	destruct(this_object());
	}
	return 1;
}

int query_autoload() { return 1; }