// /clone/board/shashou_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("杀手楼弟子留言板", ({ "board" }) );
        set("location", "/d/shashou/jiaochang");
	set("board_id", "shashou_b");
	set("long", "这是一个供杀手楼弟子交留的留言板。\n" );
	setup();
	set("capacity", 60);
	replace_program(BULLETIN_BOARD);
}

