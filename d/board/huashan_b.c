// /clone/board/huashan_b.c
inherit BULLETIN_BOARD;
void create()
{
	set_name("��ɽ�ɵ������԰�", ({ "board" }) );
	set("location", "/d/huashan/square");
	set("board_id", "huashan_b");
	set("long", "һ�鹩��ɽ�ɵ������Ե�Сʯ�塣\n" );
	setup();
	set("unit","��");
	set("capacity", 30);
	replace_program(BULLETIN_BOARD);
}
