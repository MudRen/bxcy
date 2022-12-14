// Room: guangming-ding.c

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", RED"光明顶"NOR);
        set("long",
"这里就是明教光明顶。你走到这里，可看见三个黄金色大字。明
教，少林，丐帮中明教是最大的教，少林是最大的门派，而丐帮则是
最大帮派。明教自由波斯总教传至中原已有一百多年的历史了。明教
始终都以反元抗胡，行善去恶，除暴安良为自已的宗旨，但由于明教
太大，门下教众难免莨莠不齐，至使被名门正派称为魔教。正中央坐
一面红色火焰的大旗。东边是厢房，西边是厅堂。"

"
                   "HIY"光    明    顶"NOR"

"
        );
        set("valid_startroom", 1);
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"tingtang",
  "north" : __DIR__"houtuqi",
  "east" : __DIR__"xiangfang_1",
  "southwest" : __DIR__"qian-ting",
]));
        set("objects", ([ /* sizeof() == 2 */
__DIR__"npc/xunluo" : 3,
  __DIR__"npc/yangxiao" : 1,
  __DIR__"npc/zuozong" : 3,
]));
        set("no_clean_up", 0);

        setup();
        "/d/board/mingjiao_b"->foo();
        replace_program(ROOM);

}

