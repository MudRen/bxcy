#include <ansi.h>
inherit BULLETIN_BOARD;
void create()
{
       set_name(HIY"�����ɵ������԰�"NOR, ({ "board" }) );
        set("location", "/d/emei/jinding");
        set("board_id", "emei_b");
        set("long", "����һ���������ɵ��ӽ��������԰塣\n");
        setup();
        set("capacity", 30);
        replace_program(BULLETIN_BOARD);
}
