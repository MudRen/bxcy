// Room: home.c
#include "ansi.h"
string look_shelf();
//   #define STORY_DIR "/d/emei/user-room/host/catalog.txt"	
#define STORY_TOC "/d/emei/user-room/host/"

inherit ROOM;

void create()
{
     set("short","����С��");
     set("long", @LONG
�����������˺�С�Ƶ��·�������װ��һ�£�����ɫ�ĵ�̺��ǳ��ɫ�Ĵ�
�����������ǽ���Ϲ������˴�������Ƭ����Ƭ���������˽�����������һ
������¶���Ҹ���Ц�ݡ��峿��������Ͷ�䵽���ڣ�����ɢ������͵Ĺ��ߣ�
���Ŵ�����һ��ˮ�ɣ������ĵ�Ư�������������ݵ������һ�����(shelf)��
������˸��ְ����鼮��
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
                return notify_fail("����û���Ȿ�顣\n");
        this_player()->start_more(read_file(STORY_TOC + arg));
        return 1;
}
