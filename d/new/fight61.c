
inherit ROOM;

void create()
{
	set("short", "练功房");
	set("long", @LONG
   这里是新手区的练功房。房间布置的极为简陋。
LONG
);
	set("exits", ([ /* sizeof() == 1 */
        "west" : __DIR__"nroom2",
]));
	set("objects", ([ /* sizeof() == 1 */
            __DIR__"npc/mu-ren" : 4,
]));
	set("no_new_clean_up", 0);

	setup();
	replace_program(ROOM);
}
