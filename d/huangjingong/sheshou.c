// wenwu 2003/8/5
inherit ROOM;
void create()
{
set("short", "���ֹ�");
set("exits", ([ /* sizeof() == 2 */
"north" : __DIR__"shanyang",
"south" : __DIR__"tianxie",
]));
setup();
replace_program(ROOM);
}
