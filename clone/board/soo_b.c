// /clone/board/soo_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("������԰�", ({ "board" }) );
	set("location", "/u/winder/workroom");
	set("board_id", "soo_b");
	set("long", "����һ�����԰塣\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}

