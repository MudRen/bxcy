#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "�ɴ�");
        set("long", @LONG
һҶС�ۣ����Ҳ�������ߡ��˸��ˡ�һ����ʮ�����������
�ֳֳ���ݣ����ڴ�β�����س��Ŵ���
LONG
        );
        set("exits",([
                "out"  :  __DIR__"xiaodao",
        ]));
        setup();
}
void init()
{
       object me,room;
       me=this_player();
       room=this_object();
       message_vision(
               YEL "\n���ڵ���С���ߣ������С�ۿ��ڰ��ߣ����´��ɡ�\n\n"NOR,me);
}