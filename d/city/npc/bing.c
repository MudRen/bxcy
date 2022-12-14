// bing.c 官兵
inherit NPC;
void create()
{
	set_name("官兵", ({ "guan bing", "bing" }));
	set("age", 22);
	set("gender", "男性");
	set("long", "虽然官兵的武艺不能和武林人士相比，可是他们讲究的是人多力量大。\n");
	set("attitude", "peaceful");
	set("str", 30);
	set("dex", 16);
	set("combat_exp", 100000);
	set("shen_type", 1);
	set_skill("unarmed", 80);
	set_skill("dodge", 80);
	set_skill("parry", 80);
	set_skill("blade", 80);
	set_skill("force", 80);
	set_temp("apply/attack", 80);
	set_temp("apply/defense", 60);
	set_temp("apply/damage", 50);
	set_temp("apply/armor", 80);
        set("chat_chance_combat", 10);
	set("chat_msg_combat", ({
		"官兵喝道：大胆刁民，竟敢造反不成？\n",
		"官兵喝道：跑得了和尚跑不了庙，你还是快快束手就擒！\n",
	}));
	setup();
carry_object("/d/city/obj/gangdao")->wield();	
carry_object("/d/city/obj/junfu")->wear();	
}
void init()
{
	object ob;
	::init();
	if (!living(this_object()))	return;
	if (interactive(ob = this_player())){
                if (    (int)ob->query_condition("killer") ){
			command("say 哈！总算给大爷逮住了，杀人犯，那里逃？\n");
			remove_call_out("kill_ob");
			call_out("kill_ob", 1, ob);
		}
		if( this_player()->query_temp("illicit") ){
			command("say 盐枭！那里逃？\n");
			remove_call_out("kill_ob");
			call_out("kill_ob", random(2), ob);
		}
	}
	add_action("do_kill","kill");
	add_action("do_kill","hit");
}
int do_kill(string arg)
{
	object ob;
	if (living(this_object()) && this_object()->id(arg)){
		command("say 想打架？兄弟们，上！");
		if (ob=present("wu jiang",environment()))
			ob->kill_ob(this_player());
		if (ob=present("guan bing",environment()))
			ob->kill_ob(this_player());
	}
	return 0;
}
int accept_fight(object me)
{
	command("say 大爷我正想找人杀呐，今天算你倒霉。\n");
//        me->apply_condition("killer", 500);	 lisa 注释于2003.8.29
	kill_ob(me);
	return 1;
}
int accept_object(object who, object ob)
{
     string nature;
     nature=NATURE_D->room_event_fun();
    if( nature=="event_dawn"||nature=="event_night"||nature=="event_midnight") {
    if (ob->query("money_id") && ob->value() >= random(50000)+5000 ) {
    	if(objectp(present("wu jiang",environment(who))))
        {
        message_vision(name()+"拿起"+ob->name()+"在手中掂了掂，笑着对$N说：你这"+RANK_D->query_respect(who)+"还算上道, 不过我们老大在旁边,这个。。。\n",who);
        return 1;
}
    else
       message_vision(name()+"拿起"+ob->name()+"在手中掂了掂，对$N说：你这"+RANK_D->query_rude(who)+"还算识相，过去吧。\n",who);
        who->set_temp("paid_money_bing",1);
        return 1;
        }
    else
        message_vision(name()+"拿起"+ob->name()+"在手中掂了掂，对$N骂道：你这"+RANK_D->query_rude(who)+"拿那么点钱就想打发大爷我，快滚！\n", who);
        return 0;
    }
   else {
         
         message_vision(name()+"拿起"+ob->name()+"在手中掂了掂，哈哈大笑对$N说：你这"+RANK_D->query_rude(who)+"！怎无缘无故送大爷我\n那么多钱，我暂时替你收着。\n",who);
         return 1;
     }
}
