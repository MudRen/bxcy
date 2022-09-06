// Room: /u/cass/hg/shangshufang.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "上书房");
	set("long", @LONG
但见房中一排排都是书架，架上都摆满了书，也不知有几千几万本。
正中摆着的那张紫檀木的书桌极大，桌面金镶玉嵌，桌上摊着一本书，
左首放着的砚台笔筒也都雕刻精致。椅子上披了锦缎，上面绣着一条金
龙。书桌右首是一只青铜古鼎，烧着檀香，鼎盖的兽头口中袅袅吐出一
缕缕青烟，旁边还摆了个青铜香炉。
LONG
);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"wenyuange",
]));
	set("no_new_clean_up", 0);

	setup();
	replace_program(ROOM);
}
