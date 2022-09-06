// /clone/misc/fengjiangping.c
// lisa 2003.7.1

inherit ITEM;
inherit F_SAVE;

void create()
{
	set_name("�佬ƿ", ({ "fengjiang ping", "ping" }) );
	set("long","����һ��װ�ŷ��۵���ƿ,������������(qufeng).");
	set("unit", "��");
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
	if( me->is_busy()) return notify_fail("��������æ�š�\n");
	remain=this_object()->query("remaining");
	if (!remain) return notify_fail("ƿ������Ѿ������ˡ�\n");
	if (!str || str==" ") return notify_fail("��Ҫ����˭��\n");
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
	if (!ob) return notify_fail("û������ˣ�\n");
	if ( living(ob) )
		{
            ob->kill_ob(me);
			me->hit_ob(ob);
		}
	this_object()->set("remaining",(int)remain-1);
	tell_room(environment(me),HIM+me->name()+"�ο���ƿ����������ƿǱ��������ʹ��ƿ�е�����ԶԶƮ�˿�ȥ��\nͻȻ����֮����������֪�����������һ��Ⱥ��䣬��"+ob->name()+"Χ�˹�ȥ�� \n \n"+NOR);
	if (random(me->query_skill("qufeng",1))>random(ob->query_skill("qufeng",1)))
	{
		tell_room(environment(me),HIM+ob->name()+"��Χɲ�Ǽ価�����Χ�ƣ�һֻֻ��亷��η������"+ob->name()+"���˹�����\n"+ob->name()+"ֻ��������΢΢һʹ���ѱ�������У�\n"+NOR);
jing_damage=1000+(int)(me->query_skill("qufeng",1)-ob->query_skill("qufeng",1));
ob->add("eff_jing",-jing_damage,me);
ob->receive_wound("jing", (int)jing_damage/3 , me);
ob->start_busy((int)jing_damage/200);
me->start_busy((int)jing_damage/200-3);
    }
	else 
	{
		tell_room(environment(me),MAG+ob->name()+"�鴽һХ������ƺ������˺��ԶԶ���˿�ȥ��\n "+NOR);
		me->start_busy(5);
	}
	return 1;
}
int query_autoload() { return 1; }	
