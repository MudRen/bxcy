// Room: /d/quanzhou/nanmen.c
// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
    set("short", "泉州南门");
    set("long", @LONG
这里是南方第一港泉州的南门。南门外是一片荒野。
LONG
    );
    set("outdoors", "quanzhou");
    set("no_clean_up", 0);
    set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"zhongxin",
  "south" : __DIR__"huangye",
]));
    setup();
    replace_program(ROOM);
}
