// shuanger.c
#include <ansi.h>

inherit NPC;
inherit F_UNIQUE;
int ask_go();
int ask_kiss();

void create()
{
	set_name("灵儿", ({ "ling er", "ling","er"}));
	set("title", HIW "李逍遥的大老婆" NOR);
	set("nickname", HIM "一往情深" NOR);
	set("gender", "女性");
	set("age", 16);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 35);
	set("int", 35);
	set("con", 35);
	set("dex", 40);
	set("per", 32);
	
        set("max_qi", 5000);
	set("max_jing", 2000);
	set("neili", 5000);
	set("max_neili", 5000);
	set("jiali", 50);
	set("combat_exp", 50000+random(10000));
	set("score", 20000);

	set_skill("force", 200);
	set_skill("dodge", 200);
	set_skill("unarmed", 200);
	set_skill("sword", 200);
	set_skill("taiji-jian", 200);
	set_skill("taiji-quan", 200);
	set_skill("tiyunzong",200);
	map_skill("dodge", "tiyunzong");
	map_skill("parry", "taiji-jian");
	map_skill("sword", "taiji-jian");
	map_skill("unarmed", "taiji-quan");

	set_temp("apply/attack", 15);
	set_temp("apply/attack", 15);
	set_temp("apply/damage", 15);
	 set("inquiry", ([
	     "xiaoyao" : (: ask_go :),
	     "kiss" :  (: ask_kiss :),
	]));
	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/city/obj/cloth")->wear();

}


int init()
{
	add_action("do_attack","attack");
	add_action("do_stop","stop");
	add_action("do_send","sendto");
	add_action("do_sha","sha");
}

int ask_kiss()
{
	object me;
	string new_name,new_id,host_id;
	me=this_player();
	if(query("id")!="ling er")
	{
		sscanf(query("id"),"%s's ling er",host_id);
		if(me->query("id")==host_id)
		{
			if(random(10)<1)	          
			{
				say(query("name")+"满脸羞得通红,垂下头来,缓缓的点了点头.\n");
             			add("combat_exp",2000);
			}
			else 
			say(query("name")+"啊的一声,一下子跳将开去,说:不嘛,不要.\n");
			return 1;
		}
	}
	say(query("name")+"说道:呸,我不干!");
	return 1;
}

int ask_go()
{
	object me;
	string new_name,new_id,host_id;
	me=this_player();
	if(query("id")!="ling er")
	{
		sscanf(query("id"),"%s's ling er",host_id);
		if(query("id")==host_id)
		{
			say(query("name")+"睁大眼睛看了看"+
				me->query("name")+"，说:当然愿意啦,我都听你的。\n");
			return 1;
		}
		if(me->query("id")!=host_id)
		{
			say(query("name")+"睁大眼睛看了看"+
				me->query("name")+"，说:不行的,我得听我主人的。\n");
			return 1;
           	}
	}
	if ((int)this_player()->query("weiwang")>=70)
	{
		write( HIY "灵儿道:我是你逍遥的老婆,当然听逍遥的咯~\n" NOR);
		write( HIY "你是我老公嘛,灵儿一定尽心服侍。\n" NOR);
		command("nod");	
		set_leader(me);
		new_name = me->query("name")+"的丫环灵儿";
		new_id=me->query("id")+"'s ling er";
		set("name",new_name);
		set("id",new_id);
		write( "可用指令:\nattack sb 攻击某人.\nsha sb 杀死某人.\nstop 停止战斗.\nsendto sb.--把灵儿送给sb.\n");
		set("long","这是"+new_name+"。\n"
		"她是一个十分清秀的少女,大约十四五岁年纪;\n"
		"一张雪白的脸庞,眉弯嘴小,笑靥如花,正笑嘻嘻地看着你。\n");
	}
	else say(query("name")+"睁大眼睛看着"+
		me->query("name")+"，说:不行的,夫人没有同意。\n");
	return 1;
}

int do_attack(string arg)
{
	object ob; 
	string host_id;
	object me=this_player();
	if(query("id")=="ling er")
	{
		say("你无权使用此命令。\n");
		return 0;
	}
	sscanf(query("id"),"%s's ling er",host_id);
	if(me->query("id")!=host_id) return notify_fail("灵儿连理都不理你！\n");
	if(!arg||!objectp(ob=present(arg,environment(me))))
		return notify_fail("灵儿傻傻地望着你，不明白你的意思。\n");
	if(!living(ob)) 
		return notify_fail("灵儿说:"
			+ob->query("name")+"已经这样啦你还要...??!!\n");
	if(ob->query("age")< 16 ) 
		return notify_fail("灵儿说:"
			+ob->query("name")+"还是个小孩子, 算了吧...!!\n");
	if(!environment(ob)->query("no_fight"))
	{
		message_vision("灵儿对主人$N点头道: 嗯,好的..\n",me);
		fight_ob(ob);
	}
	return 1;
}

int do_stop()
{
	string host_id;
	object me=this_player();
	if(query("id")=="ling er") return notify_fail("你无权使用此命令。\n");
	sscanf(query("id"),"%s's ling er",host_id);
	if(me->query("id")!=host_id) return notify_fail("灵儿连理都不理你！\n");
	if(!is_fighting()) return notify_fail("灵儿现在没和人打斗..\n");
	command("halt");
	message_vision("灵儿对主人$N微微一笑。\n",me);
	return 1;
}

int do_send(string arg)
{
	object ob; string host_id,new_name,new_id;
	object me=this_player();
	if(query("id")=="ling er") return notify_fail("你无权使用此命令。\n");
	sscanf(query("id"),"%s's ling er",host_id);
	if(me->query("id")!=host_id) return notify_fail("灵儿连理都不理你！\n");
	if(!arg||!objectp(ob=present(arg,environment(me))))
		return notify_fail("你要把灵儿送给谁？\n");
	if(!living(ob)) 
		return notify_fail("你只能把灵儿给活人!\n");
message_vision("灵儿眼泪汪汪地望着主人$N，说:\n主人待我好,是我命好;主人待我不好,是我命苦罢了.\n",me);
	set_leader(ob);
	new_name = ob->query("name")+"的丫环灵儿";
	set("long","这是"+new_name+"。\n"
		"她是一个十分清秀的少女,大约十四五岁年纪;\n"
		"一张雪白的脸庞,眉弯嘴小,却象是刚受人欺负,眼泪汪汪地看着你。\n");
	new_id=ob->query("id")+"'s ling er";
	set("name",new_name);
	set("id",new_id);
	write( HIY "灵儿对新主人"+ob->query("name")+"楚楚可怜地盈盈一拜。\n" NOR);
	message_vision("可用指令:\nattack sb 攻击某人.\nsha sb 杀死某人.\nstop 停止战斗.\nsendto sb.--把灵儿送给sb.\n",me);
	return 1;
}

int do_sha(string arg)
{
        int i ;
	object me,ob;
	object* obj;
	me = this_object();
	if(!arg||!objectp(ob=present(arg,environment(me))))
		return notify_fail("灵儿说: 主人你要灵儿杀谁？\n");
	if(ob->query("age")< 16 ) 
		return notify_fail("灵儿说:"
			+ob->query("name")+"还是个小孩子, 算了吧...!!\n");
	if(!environment(ob)->query("no_fight"))
	{
		message_vision("灵儿对$N点头说道: 嗯, 好的. \n",me);
		command("say 哼, 主人要我杀了你! ");
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob); 
	}
	return 1;
}       

