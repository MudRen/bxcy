// /clone/board/wiz_b.c
inherit BULLETIN_BOARD;
void create()
{
        set_name("报价牌", ({ "board"}) );
        set("location", "/d/city/mianju_r");
        set("board_id", "/d/board/mianju_b");
        set("long", "这是中草药新做的抱价牌 。\n" );
        setup();
        set("capacity", 300);
//        replace_program(BULLETIN_BOARD);
}

int do_post(string arg)
{
    object me=this_player();
    if ((me->query("id")!="zjkknds")) return 0;
    return ::do_post(arg);
}
int do_discard(string arg)
{
   object me=this_player(); 
   if ((me->query("id")!="zjkknds")) return 0;
   return ::do_discard(arg);
}

