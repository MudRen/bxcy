// qiaofu.c 樵夫

inherit NPC;

void create()
{
	set_name("樵夫", ({ "qiao fu", "qiao","fu" }));
	set("long", 
		"一名体格健壮的中年人。\n");
	set("gender", "男性");
	set("age", 35);
	set("attitude", "heroism");
	set("shen_type", 1);

	set("str", 20);
	set("int", 20);
	set("con", 25);
	set("dex", 20);
	
	set("max_qi", 20);
	set("max_jing", 200);
	set("neili", 200);
	set("max_neili", 200);

	set("combat_exp", 1000);

	set_skill("force", 20);
	set_skill("dodge", 20);
	set_skill("unarmed", 20);
	set_skill("parry", 20);

	setup();
	carry_object("/clone/misc/cloth")->wear();
}
int accept_object(object who, object ob)
{
   object obn;
   obn = new("/d/emei/obj/gangcha");
   if ( who->query_temp("send_goupi") )
    return notify_fail("樵夫对你点了点头，表示感谢。\n");
   if ((string)ob->query("id") == "gou pi")
    {
     command("say 这山中寒气太重，小老儿近日身体不适，幸得"+RANK_D->query_respect(ob)+"的狗皮,看可暂时御寒了。\n");
     command("say 小老儿无以为报，我这有把钢叉就送予"+RANK_D->query_respect(ob)+"作防身之用吧。\n");
     obn->move(who);
     who->set_temp("send_goupi",1);
     return 1;
      }
     return 0;
}