// /clone/board/shashou_b.c

inherit BULLETIN_BOARD;

void create()
{
set_name("凌宵城弟子留言板", ({ "board" }) );
set("location", "/d/lingxiao/dadian");	
set("board_id", "lingxiao_b");
set("long", "这是一个供凌宵城弟子交留的留言板。\n" );
	setup();
	set("capacity", 60);
	replace_program(BULLETIN_BOARD);
}

