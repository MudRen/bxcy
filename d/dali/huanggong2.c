// Room: /d/dali/huanggong2.c
// Data: 哈迪斯(hades)
// Time: 公元：1999年4月18日，北京时间：21时27分26秒。

inherit ROOM;

void create()
{
	set("short", "[1;33m丽正门[2;37;0m");
	set("long", @LONG
这里是大殿前的丽正门。放眼望去，但见金钉朱户，画栋雕梁，
屋顶尽覆铜瓦，镌镂龙凤飞镶之状，巍峨壮丽，光耀溢目。禁衣卫衣
甲鲜明，来回巡视。
LONG
	);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"huanggong1",
  "north" : __DIR__"huanggong3",
]));

	setup();
}

