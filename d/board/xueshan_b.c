// /clone/board/xueshan_b.c
// by secret
inherit BULLETIN_BOARD;
void create()
{
       set_name("ѩɽ��Ե����",({ "board" }) );
	set("location", "/d/xueshan/dadian");
	set("board_id", "xueshan_b");
        set("long",
		"����һ����ͭ���ɵķ��֣���������߲���ͭ�̺ۼ����Կ�����������Ѿ�\n"
		"�൱��Զ�ˣ�Ե�����Ա߷���һ�����ӹ�����ɮ�˻�������ԡ�\n" );
	setup();
	set("unit","��");
	set("capacity", 30);
	replace_program(BULLETIN_BOARD);
}
