// /clone/board/wudang_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("龙浩的工作日志",({"board"}));
	set("location", "/u/longhao/workroom");
	set("board_id", "longhao_b");
	set("long", "这是供龙浩留言的板子.\n");
	setup();
	set("capacity", 200);
	replace_program(BULLETIN_BOARD);
}

