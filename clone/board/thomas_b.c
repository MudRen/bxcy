// /clone/board/thomas_b.c

inherit BULLETIN_BOARD;
#include <ansi.h>

void create()
{
	set_name(HIC"�������"+HIR+"�����ƻ���"NOR, ({ "board" }) );
	set("location", "/u/thomas/workroom");
	set("board_id", "thomas_b");
	set("long", "�����õĻ���������˵���ҹ�ˮsmash���⡣\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}

