//ROOM damen.c

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "红花会总舵大门");
        set("long",@LONG
你站在两扇红漆大门前，门上钉满的碗口大小的铜钉，
门口的台阶上叉腰站着两个膀阔腰圆的大汉，往里看去可以
看见一条蜿延曲折的走廊通向房屋深处。
LONG
	);
        
	set("outdoors", "honghua");
        
	set("exits", ([
               "up" : __DIR__"zoulang" ,
		"southeast" : __DIR__"caoyuan3",
        ]));
	
	set("objects", ([
		"/d/honghua/dizi" : 2,
            "/d/honghua/wen-tailai" : 1,
	]));	

	set("coor/x",-140);
	set("coor/y",100);
	set("coor/z",0);
	set("coor/x",-140);
	set("coor/y",100);
	set("coor/z",0);
	set("coor/x",-140);
	set("coor/y",100);
	set("coor/z",0);
	set("coor/x",-140);
	set("coor/y",100);
	set("coor/z",0);
	setup();
}

void init()
{
	object me;
	me=this_player();
	if ( interactive( this_player())
           && ((string)me->query("family/family_name") != "红花会")
           && (!present("honghua_ling",me))
	   )
		message_vision(HIG"两个大汉向你瞪了一眼,鼻子里重重的哼了一声！\n"NOR,me);
        else if ( present("honghua_ling",me) && !(present("honghua_ling",me))->query("zizhi")) 
		message_vision(HIG"两个大汉躬身向你行了个礼,说道：令主好！\n"NOR,me);
}
int valid_leave(object me, string dir)
{
	me=this_player();
	if (  (dir == "up")
           && ((string)me->query("family/family_name") != "红花会")
	  && objectp(present("wen tailai", environment(me)))
           && (!present("honghua_ling", me))
           )

	return notify_fail
		("文泰来拦住你说：你不是本会弟兄，不能进去！\n");
	return ::valid_leave(me, dir);
}
