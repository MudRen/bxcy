// Room: qingcaodi.c

inherit ROOM;

void create()
{
        set("short", "古树");
        set("long", @LONG
这是一棵参天的古树，粗壮的树干非三四个人不能合抱，树下厚
厚地积着一层飘落的树叶，一个八、九岁的放牛小童正不知所措地紧
握着手的一段断掉的缰绳，望着远方的山里发呆。

LONG
        );
        set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/mutong2" : 1,
]));
        set("outdoors", "none");
        set("exits", ([ /* sizeof() == 1 */
  "southwest" : __DIR__"caodi1",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

