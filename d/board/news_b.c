// /clone/board/news_b.c

inherit BULLETIN_BOARD;

void create()
{
        set_name("新闻发布板", ({ "board" }) );
        set("location", "/d/wizard/newsroom");
        set("board_id", "news_b");
        set("long", "这是一个巫师们发布新闻的发布板。\n" );
        setup();
        set("capacity",200);
        replace_program(BULLETIN_BOARD);
}
