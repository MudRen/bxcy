// /clone/board/snowflk_b.c
inherit BULLETIN_BOARD;
void create()
{
        set_name("风雪的留言板", ({ "board" }) );
        set("location", "/u/snow/workroom");
        set("board_id", "snowflk_b");
        set("long", "这是一个风雪用来记事的留言板。\n" );
        setup();
        set("capacity", 200);
        set("unit","块");
        replace_program(BULLETIN_BOARD);
}
