// Room: lianwu-chang1.c

inherit ROOM;

void create()
{
        set("short", "练武场");
        set("long", @LONG
这是明教的练武场。由数块巨大的花岗岩铺垫而成。地面坑坑洼
洼留下无数脚印，可见教中弟子用功之甚。当中摆放着许多由锐金旗
的能工巧匠们精心制作的练功铜人。不论白天黑夜，都可见到十几个
教众正在此苦练武技。东面就是洪水旗。
LONG
        );
        set("objects", ([ /* sizeof() == 1 */
__DIR__"npc/tongren" : 1,
]));
        set("outdoors", "none");
        set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"lianwu-chang2",
  "west" : __DIR__"houtuqi",
  "east" : __DIR__"hongshuiqi",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

