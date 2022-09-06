// Room: home.c
#include "ansi.h"
string look_shelf();
//   #define STORY_DIR "/d/emei/user-room/host/catalog.txt"	
#define STORY_TOC "/d/emei/user-room/host/"

inherit ROOM;

void create()
{
     set("short","爱情小筑");
     set("long", @LONG
这里是冷晴人和小云的新房，四周装潢一新，淡红色的地毯，浅紫色的窗
帘。正对面的墙壁上挂着两人大幅结婚照片，照片上两对新人紧紧的依偎在一
起，脸上露出幸福的笑容。清晨几许阳光投射到窗内，屋内散发着柔和的光线，
靠着窗边有一盆水仙，清幽幽的漂来阵阵香气。屋的左边有一个书架(shelf)上
面摆满了各种爱情书籍。
LONG
    );

    set("item_desc", ([
         "shelf" : (: look_shelf :),
      ]));
    set("objects", ([
         "/d/shaolin/npc/mei_po" : 1,
     ]));
//        set("no_die", 1);
        set("valid_startroom",1);

        set("exits", ([
          "south": "/d/emei/center",
        ]));
        setup();
}
   string look_shelf()
    {
      this_player()->start_more(read_file(STORY_DIR));
      return "\n";
}
void init()
{
        add_action("do_readlove","yuedu");
}
int do_readlove(string arg)
{
        if (arg == "" || file_size(STORY_TOC + arg) <= 0)
                return notify_fail("我们没有这本书。\n");
        this_player()->start_more(read_file(STORY_TOC + arg));
        return 1;
}
