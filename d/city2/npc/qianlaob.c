
#include <ansi.h>
inherit NPC;
inherit F_BANKER;
int ask_weiwang();
void create()
{
	set_name("钱老本", ({"qian laoben", "qian", "laoben"}));
	set("title", "钱庄老板");
	set("gender", "男性");
	set("age", 34);
	set("str", 22);
	set("int", 24);
	set("dex", 18);
	set("con", 18);
	set("qi", 500); 
	set("max_qi", 500);
	set("jing", 100);
	set("max_jing", 100);
	set("shen", 0);
	set("combat_exp", 50000);
	set("shen_type", 1);
	set("attitude", "friendly");
	set("env/wimpy", 50);
	set("chat_chance", 5);
	set("chat_msg", ({
	"钱老本说道：我叫钱老本，就是因为做生意连老本也赔了。\n",
	"钱老本笑着说道：在本店存钱利息至少百分之一，客官您只管存吧。\n",
	"钱老本说：只有对本派弟子我才这么客气，对别的人啊，哼哼......\n",
	"钱老本突然说道: 江湖威望很重要，威望值高大有好处啊。\n",
        "钱老本突然说：五人分开一首诗，身上洪英无人知。\n",
	}));
        set("inquiry", ([
		"利息" :  "\n想要利息先入会！\n",
		"陈近南" :  "\n想见总舵主可没那么容易。\n",
		"天地会" :  "\n只要是英雄好汉，都可以入我天地会(join tiandihui)。\n",
		"加入" :  "\n只要入了我天地会，可以向会中各位好手学武艺。\n",
		"入会" :  "\n只要入了我天地会，可以向会中各位好手学武艺。\n",
                "威望" :  (: ask_weiwang :),
                "江湖威望" : (: ask_weiwang :),
       ]) );
	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/damage", 40);
	setup();
	carry_object("/clone/misc/cloth")->wear();
	add_money("gold", 5);
}
void init()
{
    if (base_name(environment())!=this_object()->query("startroom")) return;
	add_action("do_check", "check");
	add_action("do_check", "chazhang");
	add_action("do_convert", "convert");
	add_action("do_convert", "huan");
	add_action("do_deposit", "deposit");
	add_action("do_deposit", "cun");
	add_action("do_withdraw", "withdraw");
	add_action("do_withdraw", "qu");
	add_action("do_join","join");
	delete_temp("busy");
}
int ask_weiwang()
{
command("tell "+this_player()->query("id")+" 你现在的江湖威望是 " +(string)(this_player()->query("weiwang")));
say("\n钱老本说：如果你威望值很高，有些人见了你不但不会杀你，还会教你武功，送你宝贝。\n"
+"而且你还可以加入帮会，率领会众去攻打目标，就连去钱庄取钱也会有利息 。。。。。\n");
say("钱老本又说：杀某些坏人或救某些好人可以提高江湖威望。\n");
return 1;
}
int do_join(string arg)
{
   object ob ;
   ob = this_player () ;
   if( !arg || arg!="tiandihui" )
	return notify_fail("你要加入什么组织？\n"); 
   if (ob->query("weiwang")<20)
        {
	command("tell "+this_player()->query("id")+" 你现在的江湖威望是 " +(string)(this_player()->query("weiwang")));
	message_vision(HIC "钱老本对$N摇了摇头说：你的江湖威望值太低。\n" NOR,this_player());
  	return 1;
  	}
   if (ob->query("combat_exp")<20000)
        {
	message_vision(HIC "钱老本对$N摇了摇头说：你的实战经验太低。\n" NOR,this_player());
  	return 1;
  	}
    if(ob->query("weiwang")<50)
    {
    ob->set("weiwang",50);
    message_vision(HIC "$N的江湖威望提高了！\n" NOR,this_player());
    command("tell "+this_player()->query("id")+" 你现在的江湖威望是 " +(string)(this_player()->query("weiwang")));
    return 1;	
    }
    else message_vision(HIC "钱老本对$N摇了摇头说：你已经入过天地会了。\n" NOR,this_player());
    return 1;
}
