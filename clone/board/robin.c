// /clone/board/robin.c
#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
 set_name(HIC"继续讨论"+HIW+"我们的"+HIY+"梦想"NOR, ({ "dream" }) );
          set("location", "/u/robin/workroom");
          set("board_id", "robin");
          set("long", "这是失却了天堂的天神黄百家临时的留言板。\n" );
	  setup();
	  set("capacity", 100);
	  replace_program(BULLETIN_BOARD);
}
