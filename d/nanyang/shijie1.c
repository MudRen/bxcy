// Room: /d/nanyang/shijie1.c
// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
    set("short", "石阶");
    set("long", @LONG
这里是嵩山南麓的少室山山脚。一条长长的石阶如同巨龙般
蜿蜒而上，直没云端。嵩山群峰壁立，翠色满山，令人俯仰间顿
生渺小之意。边上有几个叫卖的小贩和挑夫，似乎在嚷嚷着争吵
些什么。
LONG
    );
    set("objects", ([ /* sizeof() == 2 */
  "/d/shaolin/npc/xiao-fan" : 1,
  "/d/shaolin/npc/tiao-fu" : 2,
]));
    set("no_clean_up", 0);
    set("outdoors", "shaolin");
    set("exits", ([ /* sizeof() == 3 */
 "east" : "/d/songshan/songshan",
"south" : "/d/xiangyang/caodi3",	
  "northup" : __DIR__"shijie2",
  "west" : __DIR__"xiaojing1",
]));
    setup();
    replace_program(ROOM);
}
