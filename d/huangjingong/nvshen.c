// wenwu 2003/8/5
inherit ROOM;
void create()
{
set("short", "Ů���");
set("exits", ([ /* sizeof() == 1 */	
"south" : __DIR__"jiaohuang",	
]));
setup();
replace_program(ROOM);
}
