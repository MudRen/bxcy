#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIB"土灵珠"NOR, ({ "tuzhu" }) );
    set_weight(1);
            set("no_put", 1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
	       
            set("no_put", 1);
            set("no_steal", 1);
            set("no_get", 1);
            set("no_beg", 1);
            set("value", 100000);
            set("unit", "颗");
            set("material", "paper");
            set("long", "你可以用(gohome),或(usezhu)来离开迷宫。用(setzhu)来设置空间门位置\n");
          }

    setup();
}
void init()
{
	add_action("do_eatt", "gohome");
	add_action("do_eat", "usezhu");
	add_action("do_set", "setzhu");
}

int do_set(string arg)
{
	object *inv;
	int sizeinv;
        object me = this_player();
        string target;
 	if (!id(arg))
	return notify_fail("你要用什么？\n");
		inv=all_inventory(me);
		sizeinv=sizeof(inv);
	
		while (sizeinv--)
		{
       			if (inv[sizeinv]->is_character())  
     				return notify_fail("你不能背着人用土珠!\n");
       		
		}
    if (me->is_fighting()) 
        return notify_fail("你正打的热闹着呢!\n");
    if (me->is_busy()) 
        return notify_fail("你正热闹着呢!\n");
    if (me->query("neili")<1000)
	return notify_fail("你的内力不足!\n");
    if(environment(me)->query("short")==BLU"山洞"NOR
       ||environment(me)->query("short")==WHT"钟乳石洞"NOR
       ||environment(me)->query("short")==YEL"岩洞"NOR
       ||environment(me)->query("short")==RED"熔岩洞"NOR
       ||environment(me)->query("short")==CYN"石洞"NOR)
{
        target=(string)file_name(environment(me));
        me->set("jobtarget",target);
        me->start_busy(8);
        message_vision(HIG "$N吃把珠拿出，一阵光辉笼罩了你!\n" NOR, me);
        message_vision(HIG "下次使用土灵珠你将会直接来到这里!\n" NOR, me);
        me->add("neili",-1000);
}	
else 
{
        message_vision(HIG "$N这里不能使用!\n" NOR, me);
}
	return 1;
}


int do_eat(string arg)
{
	object *inv;
	int sizeinv;
        object me = this_player();
        object tarset;
 	if (!id(arg))
	return notify_fail("你要用什么？\n");
		inv=all_inventory(me);
		sizeinv=sizeof(inv);
	
		while (sizeinv--)
		{
       			if (inv[sizeinv]->is_character())  
     				return notify_fail("你不能背着人用土珠!\n");
       		
		}

    if (me->is_fighting()) 
        return notify_fail("你正打的热闹着呢!\n");
    if (me->is_busy()) 
        return notify_fail("你正热闹着呢!\n");
    if (me->query("neili")<1000)
	return notify_fail("你的内力不足!\n");

    if(environment(me)->query("short")==BLU"山洞"NOR
       ||environment(me)->query("short")==WHT"钟乳石洞"NOR
       ||environment(me)->query("short")==YEL"岩洞"NOR
       ||environment(me)->query("short")==RED"熔岩洞"NOR
       ||environment(me)->query("short")==CYN"石洞"NOR)
{
        if (!me->query("jobtarget"))
       {
        me->move("d/city/guangchang");
       }
      else{
      tarset=me->query("jobtarget");
      me->move(tarset);
      }
        me->start_busy(8);
        message_vision(HIG "$N吃把珠拿出，一阵光辉笼罩了你!\n" NOR, me);
        me->add("neili",-1000);
	destruct(this_object());
}	
else 
{
        message_vision(HIG "$N这里不能使用!\n" NOR, me);
}
	return 1;
}

int do_eatt(string arg)
{
	object *inv;
	int sizeinv;
        object me = this_player();
        object tarset;
 	if (!id(arg))
	return notify_fail("你要用什么？\n");
		inv=all_inventory(me);
		sizeinv=sizeof(inv);
	
		while (sizeinv--)
		{
       			if (inv[sizeinv]->is_character())  
     				return notify_fail("你不能背着人用土珠!\n");
       		
		}

    if (me->is_fighting()) 
        return notify_fail("你正打的热闹着呢!\n");
    if (me->is_busy()) 
        return notify_fail("你正热闹着呢!\n");

    if(environment(me)->query("short")==BLU"山洞"NOR
       ||environment(me)->query("short")==WHT"钟乳石洞"NOR
       ||environment(me)->query("short")==YEL"岩洞"NOR
       ||environment(me)->query("short")==RED"熔岩洞"NOR
       ||environment(me)->query("short")==CYN"石洞"NOR)
{
        me->move("d/migong/migong3");
        me->start_busy(8);
        message_vision(HIG "$N吃把珠拿出，一阵光辉笼罩了你!\n" NOR, me);
	destruct(this_object());
}	
else 
{
        message_vision(HIG "$N这里不能使用!\n" NOR, me);
}
	return 1;
}
