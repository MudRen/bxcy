// shulin3.c
#include <room.h>

inherit ROOM;

void create()
{ 
       set("short","����");
       set("long", @LONG
����һƬټ������֣���ľ���죬���α��գ����������ʧ�˷���
��֪�������Լ����ںδ������в�ʱ����Ұ�޵ĵͺ�,�͹����Х������
����ë���Ȼ��ֻ������뿪��
LONG
     );

    
        set("exits", ([
                 "east" : __DIR__"shulin"+(random(10)+2),
                "south" : __DIR__"shulin"+(random(10)+2),
                "west" : __DIR__"shulin4",
                "north" : __DIR__"shulin2",        ]));             
        setup();
          replace_program(ROOM);
}

