// wenwu 2003/8/5
inherit ROOM;
void create()
{
set("short", "��ӹ�");	
set("exits", ([ /* sizeof() == 2 */
"north" : __DIR__"tianxie",
"south" : __DIR__"chunv",
]));
setup();
replace_program(ROOM);
}
