// Room: /d/quanzhen/jiangbmt.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "������ͷ");
	set("long", @LONG
������ʯ�����һ�𣬾ͳ���һ����ª��С��ͷ�ˡ�һ�������
��������ʯ�ϣ��ֳֵ������ڵ��㡣�����������ڶ��£�����������
����˷������ǽ��еĵ�˿ȴ��˿������
LONG
);
	set("outdoors", "quanzhen");
	set("exits", ([ /* sizeof() == 1 */
  "northup" : __DIR__"nanjie1",
]));
        set("objects", ([
                __DIR__"npc/laoyufu" : 1,
        ]));


	setup();
	replace_program(ROOM);
}
