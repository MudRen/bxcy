// /clone/board/towiz_b.c

inherit BULLETIN_BOARD;

void create()
{
        set_name("���̵������԰�", ({ "board" }) );
        set("location", "/d/mj/guangming-ding");
        set("board_id", "mingjiao_b");
        set("long", "����һ�������̵���ʹ�õ����԰塣\n" );
        setup();
        set("capacity", 60);
        replace_program(BULLETIN_BOARD);
}


