// thousand-china.c	

#include <ansi.h>

inherit MONEY;

void create()
{
set_name(GRN "�����" NOR, ({"rmb"}));          	
	if( clonep() )
		set_default_object(__FILE__);
	else {
set("money_id", "rmbB");                 	
//                 set("no_drop",1);	  //lisa 2003.7.2ע��
set("long", "һ�����һ��Բ������ҡ�\n");	
		set("unit", "��");
set("base_value", 100000000);	
		set("base_unit", "��");
		set("base_weight", 6);
set("no_drop",1);
set("no_give",1);
set("no_put",1);	
	}
	set_amount(1);
}

