// /clone/board/wiz_b.c
inherit BULLETIN_BOARD;
void create()
{
    set_name("������̱�", ({ "bei" }) );
	set("location", "/d/wizard/wizard_job");
	set("board_id", "wiz_j");
    set("long", "����һ��ר����ʦ��¼�����Ĵ���ʯ����\n");
	setup();
	set("capacity", 60);
	replace_program(BULLETIN_BOARD);
}
