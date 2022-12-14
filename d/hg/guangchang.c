// Room: /u/cass/hg/guangchang.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "广场");
	set("long", @LONG
广场中心是用大理石围砌成的平台，供游人观赏休憩，轻歌曼舞。四角
四座巨型仿青铜器花坛上。绿色植物垂挂而下，平台中间是下沉式喷水池，
晚间灯光照射，恍如天上仙景。平台四周围有花岗石矮灯，权作坐凳，供人
休憩。
LONG
);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"baohedian",
  "northeast" : __DIR__"fengxiandian",
  "northwest" : __DIR__"qianqingmen",
]));

	setup();
	replace_program(ROOM);
}
