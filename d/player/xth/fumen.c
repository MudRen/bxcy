// qjc 2000/5/3 

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", "����");
	set("long", "
    ������һ���ṹ��ΰ�Ľ���ǰ������ʯ̳�ϸ�����һ�����ɶ�ߵ���ˣ�
��������Ʈ����������ý�������һͷ������צ��ʨ�ӣ�ʨ����ͷ��һֻ
������衣����������д��"BLINK HIR"Х���"NOR"�����̽���֣������������վ��Ƿ���\n");

	set("exits", ([
		"south" : __DIR__"sclk",
          "north" : "/d/xingxiu/jiayuguan",
	]));
	setup();
}

int valid_leave(object me, string dir)
{
        if (dir=="south"){
 if (me->query("ttt")==1) return 1;
else    return notify_fail("�㲻�Ǳ�����ˣ��������һ᳤�����һ��ڽ�ȥ��!\n");
}
       else return 1;
}
