// wenwu 2003/8/5
inherit ROOM;
void create()
{
set("short", "ˮƿ��");
set("exits", ([ /* sizeof() == 2 */
"north" : __DIR__"shuangyu",
"south" : __DIR__"shanyang",
]));
setup();
replace_program(ROOM);
}
