// diamond.c

inherit MONEY;

void create()
{
set_name("钻石", ({"diamond", "zuanshi", "diamond_money"}));	
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("money_id", "diamond");        	
                set("long", "亮晶净的钻石，人见人爱的钻石，啊～～钻石！\n");
set("no_drop",1);
set("no_give",1);
set("no_put",1);	
                set("unit", "克拉");
set("base_value", 10000 );     	
                set("base_unit", "克拉");
                set("base_weight", 5);
        }
        set_amount(1);
}


