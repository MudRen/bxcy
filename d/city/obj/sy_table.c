#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("����̨", ({ "table"}));
    set_weight(5000000);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "��");
        set("long","һ��С�����������̨��ר��������������õġ�������ż���С�±���������ã�pick cake��һ���±����ԡ�");
        set("value", 0);
        set("material", "stone");
    }
}
void init()
{
    add_action("do_pick", "pick");
}
 
int do_pick(string arg)
{
       object me,obj;
       me = this_player();
       if( !arg || arg!="cake" ) return notify_fail("��Ҫ��ʲô��\n");
       if (me->query("get_cake")) return notify_fail("����ô���ɶ������ģ�\n");

      obj = new (__DIR__"yuebing");
       obj->move(me);
       message_vision("$N��ʯ��������һ��С�±���\n",me );
       me->set("get_cake",1);
       return 1;
}

int query_autoload() { return 1; }