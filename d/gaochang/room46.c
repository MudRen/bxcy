// Room: /u/mei/room46.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
	set("short", "湖边");
	set("long", @LONG
呆望湖面，忽见湖水中微微起了一点漪涟，忽然湖那边传来了娇柔清亮的歌
声：
    　　“过路的大哥你回来，
          为甚么逃得快？口不开？
          人家洗澡你来偷看，我问你哟，这样的大胆该不该？”
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"room45",
  "west" : __DIR__"room47",
]));
	set("no_new_clean_up", 0);
	set("outdoors", "room46");

	setup();
	replace_program(ROOM);
}
