// qjc 2000/5/3 

inherit ROOM;

void create()
{
	set("short", "������");
set("long", "�����Ǹ��е��������ĵط��������˲���ľ׮ľ�˺�ͭ���������ﻹ��
���ټ��ӷ�������ʱ�õ�ľ�ʱ�����\n");
       
	set("exits", ([
                "west" : __DIR__"zt",

	]));
   set("objects",([
             "/d/shaolin/npc/mu-ren" : 6,
    ]));
	setup();
	replace_program(ROOM);
}

