//Room /d/honghua/zuolang.c
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short","忆香亭");
	set("long",@LONG
这是一个精巧别致的小亭，上书“忆香亭”三个字，
清秀挺拔宛然便是陈家洛的手笔。旁边几行小字写的是
：“碧亦有时灭，血亦有时灭，一缕香魂无断绝！是耶
非耶？化为蝴蝶。”陈家洛心中想念香香公主的时候，
常一个人来此独坐
LONG
	);
	

	set("exits", ([
		"east" : __DIR__"zoulang2",
	]));

	set("objects", ([
		"/d/honghua/xiangcha" : 2,
		"/d/honghua/dianxin" : 1,
           "/d/city/npc/main" : 1,
	]));
	
	set("coor/x",-160);
	set("coor/y",100);
	set("coor/z",20);
	set("coor/x",-160);
	set("coor/y",100);
	set("coor/z",20);
	set("coor/x",-160);
	set("coor/y",100);
	set("coor/z",20);
	set("coor/x",-160);
	set("coor/y",100);
	set("coor/z",20);
	setup();
}

void init()
{
 object me;
 me=this_player();

		tell_object(me,	"                         ");
		tell_object(me,	YEL"________\n"NOR);
		tell_object(me,	"                         ");
		tell_object(me,  YEL"|"NOR);
		tell_object(me, HIG"忆香亭"NOR);  
		tell_object(me, YEL"|\n"NOR);
		tell_object(me,	"                        ",);
		tell_object(me,	YEL"==========\n"NOR);



}   
	
