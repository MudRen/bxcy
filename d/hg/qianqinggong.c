// Room: /u/cass/hg/qianqinggong.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "乾清宫");
	set("long", @LONG
宫内正中设金漆宝座和御案，上悬挂着一块题有“正大光明”的匾
额。临窗大坑上铺着猩红洋毯，正面设着大红金钱蟒靠背，石青金钱蟒
引枕，秋香色金钱蟒大条褥，坑的两边设一对梅花式洋漆小几。左边几
上文王鼎匙箸香盒，右边几上汝窟美人觚----觚内插着时鲜花卉。地下
面西一排四张椅上，都搭着银红撒花椅搭，底下四副脚踏，椅的两边，
也有一对高几，几上茗碗瓶花俱香。
LONG
);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"qianqingmen",
  "north" : __DIR__"jiaotaidian",
]));
	set("no_new_clean_up", 0);

	setup();
	replace_program(ROOM);
}
