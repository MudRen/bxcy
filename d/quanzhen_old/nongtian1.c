// Room: /d/quanzhen/nongtian1.c
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
	set("outdoors", "quanzhen");
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"nongtian3",
  "west" : __DIR__"nongtian2",
  "east" : __DIR__"nongtian1",
  "south" : __DIR__"guangdao2",
]));
        set("objects", ([
                __DIR__"npc/maque" : 2,
                __DIR__"obj/daocaoren" : 1,
]));

	setup();
	replace_program(ROOM);
}
