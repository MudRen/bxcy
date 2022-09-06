// Room: yaofang1.c

inherit ROOM;

void create()
{
        set("short", "药房");
        set("long", @LONG
一进到这里就有一股呛人的药味扑鼻而来，高高低低的橱柜里放
满了不知名的药品，正在那里配药的中年药师起身对你作了个揖，冲
着你诡异地笑了笑，好象有什么秘密不告诉你。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"zoulang1",
  "east" : __DIR__"danfang",
]));
set("objects",([
        __DIR__"npc/hu-dizi" : 1,
]));
        set("no_clean_up", 0);
        set("no_fight", 1);

        setup();
        replace_program(ROOM);
}

