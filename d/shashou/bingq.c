
inherit ROOM;

void create()
{
	set("short", "兵器室");
	set("long", @LONG
这里是杀手楼的兵器室，四周放这几个兵器架，
上面是杀手楼各弟子平时练剑用的竹剑。
LONG
	);
	set("exits", ([
		"west" : __DIR__"jiaoch",
	]));
	set("objects", ([
                "/d/village/obj/zhujian" : 2,
            "/d/taohua/npc/jiguan" : 2]));

//           set("no_fight", 1);
	
	setup();
	replace_program(ROOM);
}
// bingqi.c 兵器室
