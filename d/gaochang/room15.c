// Room: /u/mei/room15.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
        set("short", "沙漠绿洲");
        set("long", @LONG
你脚下的流沙已经不见，一个小小的湖泊呈现在你的眼前。湖里的水虽然
只有二指厚，却很清澈。在酷热的风中，湖水仍是那么的清凉。一弯清流由北
往南注入湖中。湖边有一块石碑(shibei)。
    向西凝望，一座雪白的山峰皎洁如玉。仰望峰巅，崇敬之心，油然而生。
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"room13",
  "west" : __DIR__"room17",
  "north" : __DIR__"room41",
]));
        set("no_new_clean_up", 0);
        set("outdoors", "room15");

        set("item_desc", ([
                "shibei" : "北至昆仑，西去高昌。\n",
        ]));
        setup();
        replace_program(ROOM);
}
