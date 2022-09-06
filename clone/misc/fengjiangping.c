// /clone/misc/fengjiangping.c
// 1。02 lisa 2003.7.1
// 修改驱蜂为使用能升级
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
if(environment(me)->query("no_fight") || environment(me)->query("no_magic")) 	
return notify_fail("这里禁止战斗。\n");  	
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
if((int)ob->query("age") <= 17 && userp(ob)) return notify_fail("为了世界更美好，放过小孩子吧.\n");
if(me->query_temp("apply/name") && userp(ob)) return notify_fail("你还是先取下面具吧!\n");
	if (me->query("jingli")<50) return notify_fail("你的精力不够施展驱蜂之术！\n");
	if ( living(ob) )
		{
me->fight_ob(ob);	
ob->fight_ob(me);	
me->att_kill_ob(ob);
            ob->kill_ob(me);
			me->hit_ob(ob);
		}
	this_object()->set("remaining",(int)remain-1);
	tell_room(environment(me),HIM+me->name()+"拔开玉瓶塞，手捂玉瓶潜运内力，使得瓶中的香气远远飘了开去，\n突然嗡嗡之声大作，不知道从哪里飞来一大群玉蜂，向"+ob->name()+"围了过去。 \n \n"+NOR);
	me->add("jingli",-50);
if (random(me->query_skill("qufeng",1))>(ob->query_skill("qufeng",1)/2))	
	{
		tell_room(environment(me),HIM+ob->name()+"周围刹那间尽是玉蜂围绕，一只只玉蜂悍不畏死地向"+ob->name()+"蜇了过来，\n"+ob->name()+"只觉得脸上微微一痛，已被玉蜂蜇中！\n"+NOR);
jing_damage=150+(me->query_skill("qufeng",1)-ob->query_skill("qufeng",1));
if (jing_damage < 0)
jing_damage=150;
ob->receive_damage("jing",jing_damage,me);             	
ob->receive_wound("jing", jing_damage/3,me);
ob->start_busy((int)jing_damage/50+2);                          	
me->start_busy((int)jing_damage/50+1);                          	
me->improve_skill("qufeng", random(me->query_int()/10)); //使用能增加驱蜂的等级，不过具体增加多少，，，这个数字得试试看
	}
	else 
	{
		tell_room(environment(me),MAG+ob->name()+"撮唇一啸，玉蜂似乎听懂了号令，远远避了开去。\n "+NOR);
		me->start_busy(5);
	}
	return 1;
}
int query_autoload() { return 1; }
