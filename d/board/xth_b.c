// /clone/board/baituo_b.c
#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
        set_name(HIR"龙吟"HIW"虎啸"HIG"石"NOR, ({ "board" }) );
        set("location", "/d/player/xth/zly");
        set("board_id", "xth_b");
        set("long", @LONG
这是一条数丈高的石柱。数条浮雕巨盘旋闹柱，龙首高昂
，仰天长吟，一群恶虎，对地狂啸。远远望去宏伟壮观。
LONG
        );
        setup();
        set("capacity", 30);
        replace_program(BULLETIN_BOARD);
}

