//bye enter

inherit ROOM;

void create()
{
        set("short", "ɽ��");
	set("long", @LONG
����һ����᫲�ƽ��ɽ�����˼���������˵���ﲻ�Ǻ�̫ƽ��
LONG
	);
        set("outdoors", "chengdu");

	set("exits", ([
                "southdown" : __DIR__"shandao1",
                "northup" : __DIR__"shandao3",
	]));
        set("objects", ([
                __DIR__"npc/tufei2" : 1,
            ]));

	setup();
	replace_program(ROOM);
}

