inherit ITEM;
 
#include <ansi.h>
 
void create()
{
        set_name(HIG"��·����"NOR,({ "cigarette","xiang yan","yan" }) );
        set("long", "����һ��װ���������̡�\n");
        set("unit", "��");
        set("number", 20);
        set("base_weight", 200);
}
 
void init()
{
        if( this_player()==environment() )
        add_action("do_smoking", "smoke");
}
 
int do_smoking(string arg)
{
        object ob,me;
        int jing,max_jing;
        jing = me->query("jing");
        max_jing = me->query("max_jing");
        if( !arg || (arg != "cigarette"&&arg !="xiang yan" && arg != "yan"))
                return notify_fail("��Ҫ��������? \n");
        if( this_object()->query("number") <=0)
        {
               destruct(this_object());
               return notify_fail("���Ѿ�����ˡ�\n");
         }
        
        message_vision( MAG
        "$N�ó���һ�����̣�Ȼ��ӻ����ͳ�һ����ʽ�������.....\n"+HIR
        "$N��Ȼ�Եõĳ�����������ʱ�м�����Ȧ�ӿ���ð�˳�����\n" NOR,this_player
()
        ); //end_message_vision
        message_vision(WHT"�������$N�����ˣ�$N����һ����˵Ҳ��ֵؾͲ����ˡ�
                                \n"NOR,this_player() );
        if (jing >= max_jing )
        return 1;
        this_player()->add("jing",5);
        this_object()->add("number", -1);
        return 1;
}
