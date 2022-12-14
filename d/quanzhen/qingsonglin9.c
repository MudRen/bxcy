// qingsonglin9.c 青松林

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "青松林");
	set("long", @LONG
青松林中一片黑暗，黑暗中充满了各式各样的危险，每一种都可以
至命。若是在林中迷失了方向，饥渴就足以至命。你感觉自己被困
在了阵法之中，只要走错一步，就有生命的危险，心中充满了恐惧。
LONG
	);
        set("outdoors", "quanzhen");

	set("exits", ([
		"south" : __DIR__"qingsonglin"+(random(8)+6),
		"north" : __DIR__"qingsonglin"+(random(8)+6),
              "west" :__DIR__"qingsonglin"+(random(8)+6),
		"east" : __DIR__"qingsonglin"+(random(8)+6),
         ]));
	setup();
	
}

void init()
{

	object ob, room;
	mapping fam;

	int i = random(2);
	if( i == 0) return;

	ob = this_player();
	room = this_object();

	if (ob->query("id") == "dao shi" || !living(ob)) return;

	room->delete("exits");

	if ( (fam = ob->query("family"))
	&& fam["family_name"] == "全真教" 
	&& ob->query("guilty") != 1 )  
	ob->set("guilty",3);

	ob->set("startroom", "/d/quanzhen/siguotang");

	message_vision(HIR "\n$N一不小心，走进了护山道士设下的陷阱！
$N只觉得脚下一阵巨痛，原来是踩上了埋在地下的竹签。\n\n" NOR, ob);

	message_vision(HIR "\n$N痛得几乎失去了知觉......\n\n" NOR, ob);

	call_out("trapping", 20, ob, room);

}

void trapping(object ob, object room)
{
	if ( !living(ob) ) return;

//    message_vision(HIY "\n道士们把$N从陷井里起了出来，送进了思过堂！\n\n\n" NOR, ob);	
message_vision(HIY "\n道士们把$N从陷井里起了出来，暂送少林戒律院待处！\n\n\n" NOR, ob);	
ob->move("/d/shaolin/jlyuan"); 	
//        ob->move(__DIR__"siguotang"); 	

	room->set("exits/south", __DIR__"shulin"+(random(8)+6));
	room->set("exits/north", __DIR__"shulin"+(random(8)+6));
	room->set("exits/east", __DIR__"shulin"+(random(8)+6));
	room->set("exits/west", __DIR__"shulin"+(random(8)+6));
}


