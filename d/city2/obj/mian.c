// mian.c
inherit ITEM;
void create()
{
	set_name("面", ({ "mian" }));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "一碗热气腾腾的汤面。\n");
		set("unit", "碗");
		set("value", 1000);
		set("remaining", 2);
		set("food_supply", 250);
		set("water_supply", 10);
        }
    setup();
}
void init()
{
	add_action("do_eat", "eat");
}
int do_eat(string arg)
{
object me = this_player();		
object ob;		
int food;
    if( !this_object()->id(arg) ) return 0;
if( !objectp(ob = present(arg, me)) )
return notify_fail("什么?\n");			
    if( this_player()->is_busy() )
        return notify_fail("你上一个动作还没有完成。\n");
    if(   (int)this_player()->query("food")
       >= (int)this_player()->max_food_capacity() )
     return notify_fail("你已经吃太饱了，再也吃不下了。\n");
    set("value", 0);
food=(int)(this_player()->max_food_capacity()*2/3);
this_player()->add("food", food);
    if(   (int)this_player()->query("water")
       < (int)this_player()->max_water_capacity()-(int)query("water_supply"))
    this_player()->add("water", (int)query("water_supply"));
    if( this_player()->is_fighting() ) this_player()->start_busy(2);
    add("remaining", -1);
	if ( query("remaining") )
	{
   		 message_vision("$N端起汤面，狼吞虎咽地吃起来。\n", this_player());
	} 
	else 
	{ 
   		 message_vision("$N端起碗来，把剩下的面连汤吞了。\n",this_player());
   		 message_vision("$N将碗往后一扔，抹了抹嘴，赞道：好香！\n",this_player());
		destruct(this_object());
	}
	return 1;
}
int query_autoload() { return 1; }
