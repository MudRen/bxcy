// cangjingge2.c 藏经阁

#include <room.h>
inherit ROOM;

string* books = ({
	"force_book",
	"unarmed_book",
	"sword_book",
	"unarmed_book",
	"sword_book",
	"force_book",
	"sword_book",
	"force_book",
	"unarmed_book",
	"sword_book"
	});

void create()
{
	set("short", "藏经阁二楼");
	set("long", @LONG
这里是藏经阁二楼，靠墙是几排书架，全真教历代道藏、王重阳和七第子
的著作，以及教中机密文卷尽数藏在这里。阁后有一条深达数十丈的溪涧。
LONG
	);

	set("exits", ([
	    "down" : __DIR__"cangjingge1",
	]));

	
	set("objects", ([
"/d/quanzhen/npc/qiuchuji" : 1,
		__DIR__"obj/bookshelf" : 1,
	]));
          
	setup();
	
}
int valid_leave(object me, string dir)
{
	object ob;

	if ( present("master qiu", environment(me)) )
	if ( present("book", me)
	||   objectp(ob = present("corpse", me)) && present("book", ob) )
	{
		if (dir == "down" )
		{
			return notify_fail("丘处机说道: “武功秘籍只许在藏经阁内研习，不得携带外出 !”\n");
		}
	}
	return ::valid_leave(me, dir);
}


