  // Room: /d/player/seascape.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
        set("short", "海景大街");
        set("long", @LONG
轻柔的海风，轻抚着你的脸庞，令你浑身懒洋洋的。江湖恩怨，血腥仇杀
通通抛于脑后。碧海银沙，海涛声声，衬起海边的栋栋小屋，一种想家的感觉
油然而起。路边的岩石上刻着“海景新村一路”。
LONG
);
        set("shout", "海景大街");
        set("exits", ([ /* sizeof() == 1 */
//  "west" : "/d/quanzhou/yucun1",
]));

        setup();
        replace_program(ROOM);
}

