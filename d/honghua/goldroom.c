//ROOM goldroom.c

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "������");
        set("long",@LONG
����һ��С���ӣ����ϸɸɾ������˳���Ⱦ����ǽ�ǵĵط�����
�������ӣ���������������˴�����۵ĺ����յ�������ͬ����һ
�㡣
LONG
	);
        
	        
	set("exits", ([
		"east" : __DIR__"zongduo",
        ]));
	
	set("objects", ([
//              "/u/ybl/honghua/npc/xutianhong" : 1,
                "/d/honghua/box" : 1,
	]));	

	set("coor/x",-160);
	set("coor/y",110);
	set("coor/z",30);
	set("coor/x",-160);
	set("coor/y",110);
	set("coor/z",30);
	set("coor/x",-160);
	set("coor/y",110);
	set("coor/z",30);
	set("coor/x",-160);
	set("coor/y",110);
	set("coor/z",30);
	setup();
}
