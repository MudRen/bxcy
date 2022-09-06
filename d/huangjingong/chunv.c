// wenwu 2003/8/5
inherit ROOM;
void create()
{
set("short", "´¦Å®¹¬");
set("exits", ([ /* sizeof() == 2 */
"north" : __DIR__"tianping",
"south" : __DIR__"shizi",
]));
setup();
replace_program(ROOM);
}
