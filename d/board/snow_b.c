// /clone/board/kedian_b.c
#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
set_name(HIR"日常工作安排记录板"NOR, ({ "board" }) );
set("location", "/d/wizard/snow_room");
set("board_id", "snow_b");
set("long", "这是一块用来纪录日常工作安排以及工作进程的白板，\n你可以将你的工作计划记录在上面\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}

