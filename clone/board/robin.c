// /clone/board/robin.c
#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
 set_name(HIC"��������"+HIW+"���ǵ�"+HIY+"����"NOR, ({ "dream" }) );
          set("location", "/u/robin/workroom");
          set("board_id", "robin");
          set("long", "����ʧȴ�����õ�����ưټ���ʱ�����԰塣\n" );
	  setup();
	  set("capacity", 100);
	  replace_program(BULLETIN_BOARD);
}
