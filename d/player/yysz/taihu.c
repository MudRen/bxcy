#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "ǧ�ۺ�");
        set("long",@LONG
����һ��֧���ڶ��С�ӣ����涼�ǰ����������˽����ͻ�Ҷ�봬��
�����ɳɳ����������һƬ�ž���������磬���ŵ��������㣬�㲻��
����:  "��������һ���ӣ�Ҳ���ۣ�"
LONG );
        set("outdoors", "yysz");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

