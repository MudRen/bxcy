// /clone/board/kedian_b.c
inherit BULLETIN_BOARD;
void create()
{
    set_name("五毒教留言板",({ "board" }) );
    set("location", "/d/wudujiao/dating");
     set("board_id", "wudu_b");
    set("no_get",1);
     set("long", "一块供五毒教弟子交流经验的留言板。\n");
	setup();
	set("unit","块");
        set("capacity", 218);
	replace_program(BULLETIN_BOARD);
}
