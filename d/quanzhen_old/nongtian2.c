// Room: /d/quanzhen/nongtian2.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "ũ��");
	set("long", @LONG
һƬ���ɫ�����Զ����ũ������ϲ��������ո����ӣ����
���Ÿ������ˡ���ֻ��ȸ��������ţ�����������ӡ�
LONG
);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"nongtian2",
  "north" : __DIR__"nongtian2",
  "south" : __DIR__"guangdao3",
  "east" : __DIR__"nongtian1",
]));
        set("objects", ([
                __DIR__"npc/maque" : 2,
                __DIR__"obj/daocaoren" : 1,
]));
	set("outdoors", "quanzhen");

	setup();
	replace_program(ROOM);
}
