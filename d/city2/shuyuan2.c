// Room: /d/city/shuyuan2.c
// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
	set("short", "寝室");
	set("long", @LONG
顾炎武老先生一向过着简朴的生活，这里除了一张床以外，唯一值钱的
只有一个书架了。
LONG
	);
	set("no_clean_up", 0);
	set("no_fight", "1");
	set("sleep_room", "1");
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"shuyuan",
]));
	setup();
	replace_program(ROOM);
}
