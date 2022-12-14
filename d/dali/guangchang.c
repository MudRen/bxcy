// Room: /d/dali/guangchang.c
// Data: 哈迪斯(hades)
// Time: 公元：1999年4月19日，北京时间：21时28分14秒。

inherit ROOM;

void create()
{
	set("short", "大理城中心");
	set("long", @LONG
这里就是大理城的城中心，大理城的主要街道都在这里交会，宽广的路面在这里
形成了一个方园约十余丈的广场。广场呈菱形，一圈围的都是小贩，艺人，和看热闹
的。熙熙攘攘的人群中也少不了些个跑江湖的，杂耍声，叫卖声此起彼伏。一些在中
原闻所未闻的新鲜事物令一些初入江湖的年轻人兴奋不已。位于广场中心有一个不大
不小的水池，一巨大的闹龙石柱耸立水池中央，一汩汩的甘泉水从石柱的龙嘴中涌出，
放眼向石柱上看去，只见上书：

                          [1;33m~   天  大  ~[2;37;0m

                          [1;33m~   下  理  ~[2;37;0m

                          [1;33m~   太  中  ~[2;37;0m

                          [1;33m~   平  兴  ~[2;37;0m

LONG
	);
	set("resource", ([ /* sizeof() == 1 */
  "water" : 1,
]));
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"paifang",
  "west" : __DIR__"xidajie1",
  "east" : __DIR__"dongdajie1",
  "south" : __DIR__"nandajie1",
]));

        set("objects", ([
                __DIR__"npc/dlxunbu" : 2,
                __DIR__"npc/liumangtou" : 1,
                __DIR__"npc/liumang" : 2,
        ]));
	setup();
        "/d/board/dali_b"->foo();
}
