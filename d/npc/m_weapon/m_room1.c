// Room: /d/npc/m_weapon/m_room1.c
// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
    set("short", "沙漠绿洲");
    set("long", @LONG
这里是沙漠中不多的一块绿洲，向南不远隐约可以看见一座
黑黑的山洞。随风传来一些叮叮当当的打铁的声音。也不知是谁
在打造什么。西北面群山叠嶂，白云飘渺。
LONG
    );
    set("no_clean_up", 0);
    set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"xuanbing",
  "east" : "/d/xingxiu/nanjiang2",
//  "northwest" : "/d/sunlight/tohsq1",
]));
    setup();
    replace_program(ROOM);
}
