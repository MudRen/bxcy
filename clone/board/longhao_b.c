// /clone/board/wudang_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("���ƵĹ�����־",({"board"}));
	set("location", "/u/longhao/workroom");
	set("board_id", "longhao_b");
	set("long", "���ǹ��������Եİ���.\n");
	setup();
	set("capacity", 200);
	replace_program(BULLETIN_BOARD);
}

