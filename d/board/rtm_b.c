// /rtm_b.c
#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
	set_name(HIY"天使的水晶留言板", ({ "board" }) );
    set("location", "/u/skinys/workroom");
	set("board_id", "rtm_b");
       set("long", HIM"这是一块用水晶做成的留言板,使你都不愿意在上面留言了。\n"NOR );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}

