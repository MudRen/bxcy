// /clone/board/baituo_b.c
inherit BULLETIN_BOARD;
void create()
{
        set_name("玩家意见留言板", ({ "board" }) );
        set("location", "/d/city/chatroom");
        set("board_id", "player_b");
	set("long", "这是一个供白驼山弟子交流的留言板。\n" );
	setup();
	set("capacity", 30);
	set("unit","块");
	replace_program(BULLETIN_BOARD);
}
