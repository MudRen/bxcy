// Room: /u/aplio/ltsh/tst.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "��ɷ��");
	set("long", @LONG
�����ĺ�һ�㶼�ڵ�ɷ�������������������ڡ�����һ�㣬�����������
����֮�Ž����������������á�ƽӹ֮�ˣ�ֻ��һ�����޴˸��֡�
LONG
);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/saveme" : 1,
]));
	set("exits", ([ /* sizeof() == 2 */
  "eastup" : __DIR__"lxg",
  "westdown" : __DIR__"jyt",
]));

	setup();
	replace_program(ROOM);
}
