// /clone/board/huanhua_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("浣花剑派弟子留言板", ({ "board" }) );
        set("location", "/d/huanhua/dating");
	set("board_id", "huanhua_b");
	set("long", "这是一个供浣花弟子交留的留言板。\n" );
	setup();
	set("capacity", 30);
	replace_program(BULLETIN_BOARD);
}

