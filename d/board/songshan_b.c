// /clone/board/baituo_b.c
#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
        set_name(HIG"��ɽ�������԰�"NOR, ({ "board" }) );
        set("location", "/d/songshan/chanyuan");
        set("board_id", "songshan_b");
        set("long", @LONG
����һ�鹩��ɽ�������Ե�ľ��
LONG
        );
        setup();
        set("capacity", 30);
        replace_program(BULLETIN_BOARD);
}

