// /clone/board/xueshan_b.c
// by secret
inherit BULLETIN_BOARD;
void create()
{
       set_name("雪山寺缘法轮",({ "board" }) );
	set("location", "/d/xueshan/dadian");
	set("board_id", "xueshan_b");
        set("long",
		"这是一个黄铜铸成的法轮，从它上面斑驳的铜绿痕迹可以看出它的年代已经\n"
		"相当久远了，缘法轮旁边放著一本册子供寺中僧人或香客留言。\n" );
	setup();
	set("unit","个");
	set("capacity", 30);
	replace_program(BULLETIN_BOARD);
}
