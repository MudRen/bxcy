// /clone/board/snowflk_b.c
inherit BULLETIN_BOARD;
void create()
{
        set_name("��ѩ�����԰�", ({ "board" }) );
        set("location", "/u/snow/workroom");
        set("board_id", "snowflk_b");
        set("long", "����һ����ѩ�������µ����԰塣\n" );
        setup();
        set("capacity", 200);
        set("unit","��");
        replace_program(BULLETIN_BOARD);
}
