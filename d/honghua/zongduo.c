//Room: /d/honghua/zongduo.c
//Date: 1998.10
inherit ROOM;
#include <ansi.h>
int flag=0;
int get=1;
void create()
{
	set("short", "红花会总舵");
	set("long", @LONG
这里是红花会的总舵，大堂上站满了红花会的弟子。他们的脸
上表情肃穆，每个人的右手都紧握着自己的兵刃，中间的椅子空着
，看来总舵主陈家洛不在，两旁的香炉(xiang lu)散发出缭缭的青
烟，更是衬托出一股神圣的氛围.
LONG
	);

	set("valid_startroom", 1);	

	set("exits", ([
		"southdown" : __DIR__"zoulang2",
		"west" : __DIR__"goldroom",
	]));

	set("objects", ([
//                "/d/honghua/wen-tailai" : 1,
		"/d/honghua/wuchen" : 1,
		"/d/honghua/dizi" : 2,
	]));
	set("coor/x",-150);
	set("coor/y",110);
	set("coor/z",30);
	set("coor/x",-150);
	set("coor/y",110);
	set("coor/z",30);
	set("coor/x",-150);
	set("coor/y",110);
	set("coor/z",30);
	set("coor/x",-150);
	set("coor/y",110);
	set("coor/z",30);
	setup();

	"/clone/board/honghua_b"->foo();

	set("item_desc", ([
	    "xiang lu" : "一个古色古香的青铜香炉，一股淡淡的香气从里面不时的冒出来.\n",
	    
	]));
}
void init()
{
 add_action("do_tui", "tui");
 add_action("do_wedge", "wedge");
}
int do_tui(string arg)
{

	object me=this_player();

	if(!arg || arg!="xiang lu")
		return notify_fail("你要推什么？\n");
        if( me->query("combat_exp") < 200000 )
                return notify_fail("你的功夫太差。无法推动香炉。再去练几年吧。\n");
	else if ( flag==0 )
		{
			flag=1;
			message_vision("只听“咔嚓”一响，香炉上现出一个小洞\n",me);
        		set("item_desc", ([
	               "xiang lu" : "一个古色古香的青铜香炉，一股淡淡的香气从里面不时的冒出来,
上面有一个小洞,好像可以插入什么东西！\n",
	    		]));
		}
	     else message_vision("香炉已经推不动了!\n",me); 		

	return 1;
}

int do_wedge(string arg)
{
 	object me=this_player();
        if ( !arg || arg!="honghua_ling" )
		return notify_fail("你要把什么东西插入香炉？\n");

        if ( me->is_busy() )
                return notify_fail("你正忙着呢。\n");
	else if ( get==1 && flag==1 && present("honghua_ling",me) && !(present("honghua_ling",me))->query("zizhi") )
		{
                         message_vision( "$N试着把红花令插入了香炉..\n",me);
			message_vision( HIR"只听香炉里面咔嚓乱响，好像是触动了什么机关...\n"NOR,me);
                        me->start_busy(2);
                        call_out("hit", 0 , me);
		}
	     else 
		{
			if ( flag==0 ) return notify_fail("香炉上连洞都没有，什么东西也插不进去！\n");
			if ( !present("honghua_ling",me) || (present("honghua_ling",me))->query("zizhi") ) return notify_fail("你并没有带红花令！\n");
			if ( get==0 ) return notify_fail("雪中莲已经被人拿走了!\n");
		}		
	return 1;
}

void hit()
{
	object me;
	object ob;
	me = this_player();
                ob = present ("honghua_ling", me);
                destruct (ob);

	message_vision( HIR"突然只听“嗖”的一声，从香炉中射出三支出铁箭\n",me);
        if ( random( (int)me->query("kar") ) < 20 )     {
		message_vision( HIR"$N眼前一花，来不及射闪，三箭齐齐的钉在$N的胸口\n"NOR,me);
		me->unconcious();
	}
	else {
		message_vision( HIG"$N连忙一个侧身，险险的避开了\n"NOR,me );
		message_vision( HIG"香炉慢慢转动，露出一朵"NOR,me);
		message_vision( HIW"雪中莲"NOR,me);
                 message_vision( HIG",$N赶忙拿在手中\n"NOR,me);
		ob = new ( "/d/honghua/xuelian" );
                        me->start_busy(2);
 		ob->move( this_player() );
		get=0;
	     }	
        return;
} 
         	
 
