// /clone/board/baituo_b.c
#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
        set_name(HIR"����"HIW"��Х"HIG"ʯ"NOR, ({ "board" }) );
        set("location", "/d/player/xth/zly");
        set("board_id", "xth_b");
        set("long", @LONG
����һ�����ɸߵ�ʯ��������������������������׸߰�
�����쳤����һȺ�񻢣��Եؿ�Х��ԶԶ��ȥ��ΰ׳�ۡ�
LONG
        );
        setup();
        set("capacity", 30);
        replace_program(BULLETIN_BOARD);
}

