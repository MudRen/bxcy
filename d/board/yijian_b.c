
inherit BULLETIN_BOARD;
void create()
{
set_name("处分公告栏", ({"board"}) );
set("location", "/d/city2/wenmiao");        	
set("board_id", "yijian_b");	
    set("no_get",1);
  set("long","这是一块用来公布对巫师和玩家所作处分的白版。");

	setup();
	set("unit","块");
        set("capacity", 218);
replace_program(BULLETIN_BOARD);
}
