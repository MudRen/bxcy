// Room: /d/wizard/wizard_room.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "snow 办公室");
	set("long", YEL@LONG
这里就是snow的办公室,虽然小了点，里面却布置得井井有条.
早晨的阳光透过明亮的玻璃窗照射在窗边的办公桌上，不时的
几只小鸟叽叽喳喳的从窗前飞过。打开窗户，一阵清新的泥土
气息夹着清晨小草的芳香扑面而来, 新的一天又开始了。。。
墙上挂着一块白板(board)，是用来纪录日常工作安排的。
LONG NOR );

	set("exits", ([ /* sizeof() == 1 */
         "east" : __DIR__"wizard_room",
          "south" : __DIR__"newsroom",
	]));
	set("no_fight", "1");
	set("no_clean_up", 0);
	setup();
	call_other("/d/board/snow_b", "???");
	
	replace_program(ROOM);
}
