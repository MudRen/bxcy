// /rtm_b.c
#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
	set_name(HIY"��ʹ��ˮ�����԰�", ({ "board" }) );
    set("location", "/u/skinys/workroom");
	set("board_id", "rtm_b");
       set("long", HIM"����һ����ˮ�����ɵ����԰�,ʹ�㶼��Ը�������������ˡ�\n"NOR );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}

