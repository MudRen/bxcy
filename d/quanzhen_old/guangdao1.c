// Room: /d/quanzhen/guangdao1.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "官道");
	set("long", @LONG
这是条建在大堤上的官道，一旁是川流不息的滚滚江流，一旁是
肥沃的农田，农夫们正在田里忙着收割稻子。官道上人来人往，十分
热闹。
LONG
);
	set("outdoors", "quanzhen");
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"guangdao2",
  "east" : "/d/nanyang/hanshui2",
]));

	setup();
	replace_program(ROOM);
}
