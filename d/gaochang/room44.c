// Room: /u/mei/room44.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
        set("short", "大湖");
        set("long", @LONG
转了几个弯，从一排参天青松中穿了出去，登时惊得呆了。眼前一片大湖，
湖的南端又是一条大瀑布，水花四溅，日光映照，现出一条彩虹，湖周花树参差，
杂花红白相间，倒映在碧绿的湖水之中，奇丽莫名。远处是大片青草平原，无边
无际的延伸出去，与天相接。路边有一块石碑(shibei)。
LONG
        );
        set("outdoors", "room44");
        set("no_new_clean_up", 0);
        set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"room45",
  "south" : __DIR__"caoyuan1",
  "east" : __DIR__"room43",
]));

        set("item_desc", ([
                "shibei" : "西至昆仑，南达光明顶。\n",
        ]));
        setup();
        replace_program(ROOM);
}
