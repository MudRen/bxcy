// Room: /u/mei/zhaoze/room14.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
	set("short", "苗人部落");
	set("long", @LONG
你眼前突然一亮，原来是走进了一个苗人部落。苗人们围坐在火
堆边，面色虔诚，好象在作某种祭神仪式。几个巫士挥舞着木镗，口
中念念有词。突然，他们好象发现了你。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"room16",
  "east" : __DIR__"room15",
]));

        set("objects",([
                        __DIR__"npc/wushi": 4,        
        ]));
	setup();
	replace_program(ROOM);
}
