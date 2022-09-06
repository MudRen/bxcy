// /clone/misc/fengjiangping.c
// lisa 2003.7.1

inherit ITEM;
inherit F_SAVE;

void create()
{
	set_name("蜂浆瓶", ({ "fengjiang ping", "ping" }) );
	set("long","这是一个装着蜂蜜的玉瓶,可以用来驱蜂(qufeng).");
	set("unit", "个");
	set("value",0);
	set("remaining", 5);
}

void init()
{
	
	if( this_player() && environment()==this_player() ) add_action("do_qufeng","qufeng");
	
}

int do_qufeng(string str)
{
	object ob,me;
	object *inv;
	int i,remain;
int jing_damage;
	me=this_player();
	if (me->query_skill("qufeng",1)<100) return 0;
	if( me->is_busy()) return notify_fail("你现在正忙着。\n");
	remain=this_object()->query("remaining");
	if (!remain) return notify_fail("瓶里的蜜已经用完了。\n");
	if (!str || str==" ") return notify_fail("你要驱蜂谁？\n");
	inv = all_inventory(environment(me));
	for ( i=0 ; i<sizeof(inv) ; i++ )
	{
		if (inv[i]->query("id")==str || inv[i]->id(str)) 
		{
			ob=inv[i];
			tell_object(me,i);
			break;
		}
	}
	if (!ob) return notify_fail("没有这个人？\n");
	if ( living(ob) )
		{
            ob->kill_ob(me);
			me->hit_ob(ob);
		}
	this_object()->set("remaining",(int)remain-1);
	tell_room(environment(me),HIM+me->name()+"拔开玉瓶塞，手捂玉瓶潜运内力，使得瓶中的香气远远飘了开去，\n突然嗡嗡之声大作，不知道从哪里飞来一大群玉蜂，向"+ob->name()+"围了过去。 \n \n"+NOR);
	if (random(me->query_skill("qufeng",1))>random(ob->query_skill("qufeng",1)))
	{
		tell_room(environment(me),HIM+ob->name()+"周围刹那间尽是玉蜂围绕，一只只玉蜂悍不畏死地向"+ob->name()+"蜇了过来，\n"+ob->name()+"只觉得脸上微微一痛，已被玉蜂蜇中！\n"+NOR);
jing_damage=1000+(int)(me->query_skill("qufeng",1)-ob->query_skill("qufeng",1));
ob->add("eff_jing",-jing_damage,me);
ob->receive_wound("jing", (int)jing_damage/3 , me);
ob->start_busy((int)jing_damage/200);
me->start_busy((int)jing_damage/200-3);
    }
	else 
	{
		tell_room(environment(me),MAG+ob->name()+"撮唇一啸，玉蜂似乎听懂了号令，远远避了开去。\n "+NOR);
		me->start_busy(5);
	}
	return 1;
}
int query_autoload() { return 1; }	
