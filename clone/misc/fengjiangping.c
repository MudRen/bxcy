// /clone/misc/fengjiangping.c
// 1��02 lisa 2003.7.1
// �޸�����Ϊʹ��������
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
if(environment(me)->query("no_fight") || environment(me)->query("no_magic")) 	
return notify_fail("�����ֹս����\n");  	
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
if((int)ob->query("age") <= 17 && userp(ob)) return notify_fail("Ϊ����������ã��Ź�С���Ӱ�.\n");
if(me->query_temp("apply/name") && userp(ob)) return notify_fail("�㻹����ȡ����߰�!\n");
	if (me->query("jingli")<50) return notify_fail("��ľ�������ʩչ����֮����\n");
	if ( living(ob) )
		{
me->fight_ob(ob);	
ob->fight_ob(me);	
me->att_kill_ob(ob);
            ob->kill_ob(me);
			me->hit_ob(ob);
		}
	this_object()->set("remaining",(int)remain-1);
	tell_room(environment(me),HIM+me->name()+"�ο���ƿ����������ƿǱ��������ʹ��ƿ�е�����ԶԶƮ�˿�ȥ��\nͻȻ����֮����������֪�����������һ��Ⱥ��䣬��"+ob->name()+"Χ�˹�ȥ�� \n \n"+NOR);
	me->add("jingli",-50);
if (random(me->query_skill("qufeng",1))>(ob->query_skill("qufeng",1)/2))	
	{
		tell_room(environment(me),HIM+ob->name()+"��Χɲ�Ǽ価�����Χ�ƣ�һֻֻ��亷��η������"+ob->name()+"���˹�����\n"+ob->name()+"ֻ��������΢΢һʹ���ѱ�������У�\n"+NOR);
jing_damage=150+(me->query_skill("qufeng",1)-ob->query_skill("qufeng",1));
if (jing_damage < 0)
jing_damage=150;
ob->receive_damage("jing",jing_damage,me);             	
ob->receive_wound("jing", jing_damage/3,me);
ob->start_busy((int)jing_damage/50+2);                          	
me->start_busy((int)jing_damage/50+1);                          	
me->improve_skill("qufeng", random(me->query_int()/10)); //ʹ������������ĵȼ��������������Ӷ��٣�����������ֵ����Կ�
	}
	else 
	{
		tell_room(environment(me),MAG+ob->name()+"�鴽һХ������ƺ������˺��ԶԶ���˿�ȥ��\n "+NOR);
		me->start_busy(5);
	}
	return 1;
}
int query_autoload() { return 1; }