// Room: /d/quanzhou/huangye.c
// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
    set("short", "荒野");
    set("long", @LONG
你走在泉州郊外的荒野上，不时有一阵阵海风从南面吹来，北边通往
南方第一港泉州，南面是一个小渔村。
LONG
    );
    set("outdoors", "quanzhou");
    set("no_clean_up", 0);
    set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"nanmen",
  "south" : __DIR__"yucun",
]));
    setup();
    replace_program(ROOM);
}
