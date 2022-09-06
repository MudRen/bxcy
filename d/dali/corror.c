inherit ROOM;
#include <room.h>
void create()
{
        set("short", "走廊");
        set("long", @LONG
每隔五步，左右各一门。门上似有记号，门后似有人声。每隔十步，烛灯一盏，
忽明忽暗。凝神细听，又似乎每户空空。走廊弯弯曲曲，向前伸展，一眼望不到尽
头。每当船身随波摇摆，给人旋晕的感觉。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"wting",
  "south" : __DIR__"corror1",
  "east" : __DIR__"hotel4",
]));

        create_door("east", "木雕门", "west", DOOR_CLOSED);
        setup();
}
