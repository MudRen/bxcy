// /clone/board/baituo_b.c
#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
        set_name(HIG"����ʯ��"NOR, ({ "board" }) );
        set("location", "/u/hades/d/dali/guangchang");
        set("board_id", "dali_b");
        set("long", @LONG
����һ�����ɸߵ�ʯ���������������������������
��򥣬������ˮ��������ӿ����ԶԶ��ȥ��ΰ׳�ۡ�
LONG
        );
        setup();
        set("capacity", 30);
        replace_program(BULLETIN_BOARD);
}

