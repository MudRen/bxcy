// Room: tingtang.c

inherit ROOM;

void create()
{
        set("short", "厅堂");
        set("long", @LONG
这里是教中接待一般来访江湖人物的地方，几张红木太师椅和小
几分列南北两边，西边有几个小童垂手而立，不时过来端茶添水。

LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"chashi2",
  "east" : __DIR__"guangming-ding",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

