// Room: /u/fan/hg/taihe-dian.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
	set("short", "泰和殿");
	set("long", @LONG
历代皇后的寝宫。正中得摆着一张紫檀木制的圆桌，桌上磊着一些
书籍和茶具。靠东壁面西设着青缎靠椅引枕，西壁面摆着一张酸枝木造
的贵妃椅，上面铺着青缎靠背从褥。在一道画有丹凤朝阳的屏风后面是
内室，里有只有一张牙床，上面挂着一顶藕合色花帐，床上的锦被缎褥
摆得整整齐齐。
LONG
	);
	set("no_new_clean_up", 0);

	setup();
	replace_program(ROOM);
}
