// Room: xiaoting.c

inherit ROOM;

void create()
{
        set("short", "小厅");
        set("long", @LONG
这是通往教主休息的后院的小厅，四周摆放着一些名贵的花草，
散发着阵阵幽香。墙上悬挂着一些名家字画。两边摆放着几张红木椅
和小几，教主在处理繁忙教务之余，常在这里稍事歇息。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"houyuan",
  "east" : __DIR__"shenghuo-tang",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}


