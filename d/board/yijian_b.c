
inherit BULLETIN_BOARD;
void create()
{
set_name("���ֹ�����", ({"board"}) );
set("location", "/d/city2/wenmiao");        	
set("board_id", "yijian_b");	
    set("no_get",1);
  set("long","����һ��������������ʦ������������ֵİװ档");

	setup();
	set("unit","��");
        set("capacity", 218);
replace_program(BULLETIN_BOARD);
}
