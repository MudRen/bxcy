// Room: /d/kunlun/sbxd.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
        set("short", "山边小店");
        set("long", @LONG
这里是昆仑山山脚的一间小店，由于方圆数十里就此一间小店，加上昆仑
山终年积雪，天气寒冷，而这里又有御寒衣物售卖，因此生意还算兴隆。
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"klsj1",
 "west" : "/d/gaochang/room63",
]));
        set("objects", ([ 
        __DIR__"npc/xiaoer2" : 1,
]));

        setup();
        replace_program(ROOM);
}
