
inherit NPC;
#include <ansi.h>
string ask_me();
void create()
{
	set_name("阿飞", ({ "afei", "fei","feia" }) );
	set("gender", "男性" );
        set("title", HIG "情为何物" NOR);
set("class", "jianxia");	
	set("age", 20);
	set("int", 30);
	set("per", 30);
	set("long",
		"天下无敌－－－阿飞\n"
		);
        set("force_factor", 200);
        set("max_gin", 3000);
        set("max_kee", 3000);
        set("max_sen", 3000);
        set("eff_gin", 3000);
        set("eff_kee", 3000);
        set("eff_sen", 3000);
set("nickname",RED"魔剑"NOR);	
        set("gin", 3000);
        set("kee", 3000);
        set("sen", 3000);
set("max_force", 30000);	
        set("force", 30000);
	set("cor",200);
set("combat_exp", 1500000000);	
        set("score", 90000);
set_skill("sword", 2400);	
set_skill("force", 2400);	
set_skill("parry", 1800);	
set_skill("literate", 1800);	
set_skill("dodge", 2000);	
set("max_neili",1000);  	
set("neili",15000000);  	
set("max_jingli",500000);  	
set("max_jingli",200000);  	
set("jingli",400000);  	
set("max_jing",500000);  	
set("max_qi",1000000);  	
set("shen",300000000);
set("jiali",50000);  	
        set("int",30);
set("chat_chance_combat", 300);	
        set("chat_msg_combat", ({
(: perform_action, "sword.jiushi" :),	
//(: perform_action, "sword.zongjue" :),	
//(: perform_action, "sword.pozhao" :),  	
//(: perform_action, "sword.pojian" :),	
//(: perform_action, "sword.podao" :),	
//(: perform_action, "sword.pobian" :),	
//(: perform_action, "sword.poqi" :),	
//(: perform_action, "sword.pozhang" :),	
        }) );
set_skill("lonely-sword", 2100);	
set_skill("pmshenfa", 1500);        	
set_skill("zhentian-quan", 1500);            	
set_skill("unarmed", 1500);            	
map_skill("dodge", "pmshenfa");     	
map_skill("unarmed", "zhentian-quan");         	
map_skill("sword", "lonely-sword");	
map_skill("parry", "lonely-sword");	
create_family("圣剑魔宫", 5, "掌门");	
    set("inquiry", ([
     "独孤九剑":(:ask_me:),
     ]) );;
	setup();
	carry_object("clone/cloth/cloth")->wear();
        carry_object(__DIR__"obj/toysword")->wield();
}
int accept_fight(object me)
{
        command("grin");
        command("say 我的剑是用来杀人的，不是用来比划着玩的．");
        return 0;
}
void init()
{
	add_action("do_killing", "kill");
}

int do_killing(string arg)
{
	
	object player, victim, weapon;
	string name;
	player = this_player();
	if( !arg) return 0;
	if( objectp(victim = present(arg, environment(this_object()))) && living(victim))
	{
		name = (string)victim->name();
		if( (string)name == "林仙儿")
		{
		message_vision("$N冷笑一声道：我看你活得太长了。\n", this_object());
		this_object()->kill_ob(player);
		player->kill_ob(this_object());
		return 1;
		}
	}
	return 0;		
}
void attempt_apprentice(object ob)	
{
if((int)ob->query("shen",1) < 150000000)               	
{
command("say 我的剑法只传侠义人士，你在德行方面还做得不够吧。");	
return 0;	
}
command("say 好吧，我就破例收下你了，以后要多多行侠仗义。");	
command("chat 我的绝世剑法终有传人了，武林中又多了位行侠仗义的大侠。哈哈.....");	
command("recruit " + ob->query("id"));	
ob->set("class","jianxia");                  	
}
string ask_me()
{
    object me,ob;

    me = this_player();
    if ((string)me->query("family/master_id")==(string)this_object()->query("id"))
    {
         if (me->query("fengset")) 
         	return "你竟然能领悟独孤九剑的精华,今后武林正义就要靠你了。";
         switch (random(10))
         {
              case 0:
                   me->set_temp("marks/fengseto",1);
                   return "当年风大侠曾得到独孤大侠的指点,你不防去问问他。";
              default:
                   return "「独孤九剑」？这套剑法博大精深,你要好好领悟。";
         }
    }
    else return RANK_D->query_respect(this_player()) + "不是我的徒弟吧？";
}