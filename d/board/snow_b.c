// /clone/board/kedian_b.c
#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
set_name(HIR"�ճ��������ż�¼��"NOR, ({ "board" }) );
set("location", "/d/wizard/snow_room");
set("board_id", "snow_b");
set("long", "����һ��������¼�ճ����������Լ��������̵İװ壬\n����Խ���Ĺ����ƻ���¼������\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}

