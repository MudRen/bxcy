// /clone/board/thomas_b.c

inherit BULLETIN_BOARD;
#include <ansi.h>

void create()
{
	set_name(HIC"豪侠晚歌"+HIR+"开发计划板"NOR, ({ "board" }) );
	set("location", "/u/thomas/workroom");
	set("board_id", "thomas_b");
	set("long", "有有用的话就往这里说，乱灌水smash无赦。\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}

