// wenwu 2003/8/5
inherit ROOM;
void create()
{
set("short", "ħ�ɹ�");	
set("exits", ([ /* sizeof() == 2 */
"north" : __DIR__"shuiping",
"south" : __DIR__"sheshou",
]));
setup();
replace_program(ROOM);
}
