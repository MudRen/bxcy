//youtan.c ����ɻ�
inherit ITEM;
#include <ansi.h>
void init()
{
        add_action("do_eat", "eat");
}
void create()
{
    set_name( MAG "����ɻ�" NOR, ({"youtan flower","youtan","flower"}));
        set("unit", "��");
        set("value", 0);
    set("long", "һ�亣������滨��������̣������������������й����ĵ����㡣\n");
        setup();
}
void add_age(object me)
{
    if (me!=environment()) return;
       tell_object(me,MAG+"���Ȼ�������巢����һЩ΢��ı仯��\n"+NOR);
    if ( ( me->query("mud_age") / 86400) > 5 ){
    if ( ((int)me->query("mud_age") / 86400)  > 5 - me->query("age_modify") )
    me->add("age_modify",-1);
    else
    me->set("age_modify",-((int)me->query("mud_age") / 86400) + 5 );
    }
    me->set_temp("add_age",0);
    me->update_age();
    destruct(this_object());
}

int do_eat(string arg)
{
    object me;
    me = this_player();
    if (!id(arg))  return notify_fail("��Ҫ��ʲô��\n");
    if ( me->query_temp("add_age"))  return notify_fail("��Ҫ��ʲô��\n");
    message_vision(HIG"$N������ô�����"+this_object()->name()+HIG+"����Ҳ����,һ�ڰ�"+this_object()->name()+HIG+"����!\n" NOR,this_player());
    if (me->query("age")<20){
        tell_object(me,"�����һ�����������"+this_object()->name()+NOR+"��\n");
        destruct(this_object());
        return 1;
     }
     call_out("add_age",10,this_player());
     me->set_temp("add_age",1);
    return 1;
}
void reset(){ }

int query_autoload() { return 1; }