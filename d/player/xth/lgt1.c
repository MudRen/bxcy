// qjc 2000/5/3 

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", "�����ǻ��е��������ĵط��������˲���ľ׮ľ�˺�ͭ��
�������ﻹ�в��ټ��ӷ�������ʱ�õ�ľ�ʱ�����\n");

	set("exits", ([
                "west" : __DIR__"lgf1",
		"south" : __DIR__"lt",

	]));
   set("objects",([
             "/d/huashan/npc/tong-ren" : 4,
    ]));
	setup();
	replace_program(ROOM);
}

