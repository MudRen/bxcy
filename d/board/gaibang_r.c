// /clone/board/gaibang_r.c
inherit BULLETIN_BOARD;
void create()
{
	set_name("ؤ��������԰�", ({ "report" }) );
	set("location", "/d/city/gbxiaowu");
	set("board_id", "gaibang_r");
	set("long", "����һ����ؤ����ӽ�����Ϣ�����԰塣\n" );
	setup();
	set("unit","��");
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}
