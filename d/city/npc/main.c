// main.c 陈家洛

inherit NPC;
inherit F_MASTER;
#include <ansi.h>
string ask_me();
string ask_ling();
int count=1;
void create()
{
	set_name("陈家洛", ({ "chen jialuo", "chen" }));
	set("nickname", HIR "落花神剑" NOR );
	set("long", 
		"他就是天下闻名的红花会的总舵主陈家洛\n"
		"身穿一件干干净净的青色长袍。\n"
		"他看起来二十来岁，身材瘦长，背上一把长剑令人不寒而粟\n");
	set("gender", "男性");
	set("age", 22);
	set("shen_type", 1);
	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 28);
	
set("max_qi", 500000);	
set("max_jing", 150000);	
set("neili", 5000000);	
	set("max_neili", 5000);
set("jiali",15000);	
set("combat_exp", 1500000000);   	
	set("score", 700000);

set_skill("force", 2100);	
set_skill("honghua-shengong", 850);	
set_skill("dodge", 850);	
set_skill("youlong-shenfa", 850);	
set_skill("unarmed", 850);	
set_skill("baihuacuo-quan", 850);	
set_skill("parry", 850);	
set_skill("sword", 1500);	
set_skill("luohua-jian", 850);	
set_skill("literate", 2000);	

	map_skill("force", "honghua-shengong");
	map_skill("dodge", "youlong-shenfa");
	map_skill("unarmed", "baihuacuo-quan");
	map_skill("parry", "luohua-jian");
	map_skill("sword", "luohua-jian");

	create_family("红花会", 2, "总舵主");

	set("inquiry", ([
		"红花会" : (: ask_me :),
	]));

        

        set("chat_chance", 5);         // 随机动作概率 25%
        set("chat_msg", ({
                "陈家洛叹了一口气道：唉....想不到乾隆竟是我兄弟，这可如何是好？\n",
                "陈家洛恨声说道：我们汉人的江山，一定要从满清手中夺回来\n",
                "陈家洛说道：这位兄弟，可要加入我们红花会吗？\n",
        }) );
set("chat_chance_combat", 100);  
        set("chat_msg_combat", ({
                "陈家洛说道：你敢惹我，追到天涯海角我都要杀了你！\n",
(: perform_action, "sword.chan" :),	
(: perform_action, "sword.kuangda" :),	
(: perform_action, "sword.shisan" :),	
		(: exert_function, "recover" :),
                
        }) );

	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/wudang/obj/greyrobe")->wear();

}

void attempt_apprentice(object ob)
{
	if ((int)ob->query("shen") <50000) {
		command("say 红花会中皆是敢作敢当的好汉子，你这小贼也想混进来么？");
		command("say 想要加入红花会" + RANK_D->query_respect(ob) +
			"你先去杀几个清狗再说！");
		return;
	}
        command("say 在下对"+RANK_D->query_respect(ob)+
                "已是神交已久，从今而后咱们就是一家人了！");
	command("recruit " + ob->query("id"));
	if( (string)ob->query("class") != "taoist")
		ob->set("class", "taoist");
}
/*
void init()
{
        object ob;

        ::init();

        ob = this_player();

        if((int)ob->query("shen") < -1000 && ob->query("family/master_id")=="chen jialuo")
        {
                command("chat "+ob->query("name")+"!你这等邪恶奸诈之徒，我岂能仍是你的师傅。\n");
                command("expell "+ ob->query("id"));
                this_player()->set("title","红花会" + RED + "弃徒" NOR);
        }

        add_action("do_say", "say");
}
*/
int do_say(string arg)
{

	if( !arg || arg=="" ) return 0;
 
	if( arg=="青叶红花白莲藕") 
        
	{
		write("陈家洛说道：天下英雄是一家\n");
		message("vision", "原来是自家弟兄，不知有何见教？\n", this_player());
		set("inquiry", ([
		"红花令" : (: ask_ling :),
	
	]));

	}
}
string ask_me()
{
	
	return RANK_D->query_respect(this_player()) + 
		",我红花会乃天下第一大帮，专与清狗作对，哈.哈...";
        
}
string ask_ling()
{
        
  	object ob,me;
	if (count == 0) return "红花令已经传出去了！\n";
	message_vision(HIR"陈家洛说道：“想要红花令吗？，先接我三招！\n"NOR,this_player());
	ob = this_object();
	me = this_player();
	COMBAT_D->do_attack(ob, me, query_temp("weapon") );
	COMBAT_D->do_attack(ob, me, query_temp("weapon") );
	COMBAT_D->do_attack(ob, me, query_temp("weapon") );

	me->set_temp("fighter", 1);
		
	ob->fight_ob(me);
	me->fight_ob(ob);

	command("halt");
		
        if (( (int)me->query("qi")*100 / (int)me->query("max_qi") ) >= 30 )
        {
			ob = new("/d/honghua/honghua-ling");
	        	ob->move(this_player());
		        count=0;
			return "好，这支红花令兄弟你要好好保管！\n";
			message_vision(HIY"陈家洛交给$N一支红花令!\n"NOR,me);
		}
	else
		
			return "你这样武功怎能掌管红花令？";	
}
