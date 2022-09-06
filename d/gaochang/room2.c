// Room: /u/mei/room2.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
	set("short", "塞口");
	set("long", @LONG
这里是中原入西域的必经之路，大批的商人鸵队都一定要从这里经过，
形成了这里的畸形路容。向西你可以看到一段破旧的长城，上面好象还有被
土炮轰过的痕迹，向北是一家小店。一块“[1;37m龙门客栈[2;37;0m”的木板招牌孤零零的
在寒风中摇曳。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"room3",
  "north" : __DIR__"room16",
  "east" : __DIR__"room1",
]));
	set("no_new_clean_up", 0);
	set("outdoors", "room2");

	setup();
	replace_program(ROOM);
}
