// Room: /u/mei/room33.c
// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
    set("short", "甬道");
    set("long", @LONG
走过了长长一条甬道，白玉壁上映出人的影子，此时深入峰腹，吉凶祸福，
殊难逆料，生平遭遇之奇，实以此时为最了。
LONG
    );
    set("no_new_clean_up", 0);
    set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"room34",
]));
    setup();
    replace_program(ROOM);
}
