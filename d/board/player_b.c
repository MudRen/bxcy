// /clone/board/baituo_b.c
inherit BULLETIN_BOARD;
void create()
{
        set_name("���������԰�", ({ "board" }) );
        set("location", "/d/city/chatroom");
        set("board_id", "player_b");
	set("long", "����һ��������ɽ���ӽ��������԰塣\n" );
	setup();
	set("capacity", 30);
	set("unit","��");
	replace_program(BULLETIN_BOARD);
}
