// wenwu 2003/8/5
inherit ROOM;
void create()
{
set("short", "�̻���");
set("exits", ([ /* sizeof() == 2 */	
"south" : __DIR__"shuangyu",
"north" : __DIR__"nvshen",	
]));
setup();
replace_program(ROOM);
}
