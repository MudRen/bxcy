// /clone/board/kedian_b.c
inherit BULLETIN_BOARD;
void create()
{
	set_name("�͵����԰�", ({ "board" }) );
	set("location", "/d/city/kedian");
	set("board_id", "kedian_b");
    set("no_get",1);
	set("long", "һ����ͨ�����԰壬�����������������á�\n" );
	setup();
	set("unit","��");
        set("capacity", 218);
	replace_program(BULLETIN_BOARD);
}
