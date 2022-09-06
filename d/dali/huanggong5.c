// Room: /d/dali/huanggong5.c
// Data: 哈迪斯(hades)
// Time: 公元：1999年4月18日，北京时间：21时27分26秒。

inherit ROOM;

void create()
{
	set("short", "[1;33m正殿[2;37;0m");
	set("long", @LONG
这里是承德殿前的一间正殿。这里是朝臣上朝必由之路，因此
殿内甲士林立，戒备森严。
LONG
	);
	set("exits", ([ /* sizeof() == 5 */
  "south" : __DIR__"huanggong4",
  "west" : __DIR__"huanggong11",
  "east" : __DIR__"huanggong10",
  "north" : __DIR__"huanggong7",
  "northup" : __DIR__"huanggong6",
]));

                 set("objects", ([
                __DIR__"npc/shiwei" : 4,

        ]));

	setup();
}

