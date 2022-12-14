// jinshe.c 金蛇郎君

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("夏雪宜", ({"xia xueyi", "xia", "xueyi"}));
	set("nickname", HIY"金蛇郎君"NOR);
	set("gender", "男性");
	set("age", 25);
	set("long", 
		"他就是人称“金蛇郎君”的一代怪杰——夏雪宜。\n"
		"他做事全凭好恶，时正时邪，端地是独来独往，好不潇洒！\n"
		"听说他的身世很惨，人也变得偏激起来。\n"
		"看起来他好象受了点伤，脸色很难看。\n");
 	set("attitude", "peaceful");
set("per", 21);	
set("str", 50);        	
set("int", 150);	
set("con", 150);	
set("dex", 150);	

	set("chat_chance", 15);
	set("chat_msg", ({
		"夏雪宜突然恶狠狠地说道：仪儿，你到底为什么要害我！？\n",
		"夏雪宜眼中仿佛要喷出火来。\n",
                "突然，夏雪宜“哇”地一声，吐出一大口带黑的血。\n",
	}));

	set("inquiry", ([
		"温仪": "她....她..... \n",
	]));

set("max_qi", 3500000);   	
set("jing", 3500000);	
set("max_jing", 3500000);	
set("neili", 15000000);	
set("max_neili", 500000); 	
set("no_suck",1); 	
set("jiali", 50000);	
	
set("combat_exp", 810000000);  	
	 
set_skill("force", 2000);                // 基本内功	
set_skill("huntian-qigong", 1550);       // 混天气功	
set_skill("unarmed", 1800);              // 基本拳脚	
set_skill("dodge", 1800);                // 基本躲闪	
set_skill("parry", 1700);                // 基本招架	
set_skill("sword", 1500);                // 基本剑法	
set_skill("jinshe-zhui", 1700);         
set_skill("jinshe-zhang", 1900);         
set_skill("throwing", 1900);         
set_skill("jinshe-jian",1500);         // 金蛇剑法       	
set_skill("youlong-shenfa",1500);   
	
	map_skill("force", "huntian-qigong");
map_skill("sword", "jinshe-jian");	
map_skill("throwing", "jinshe-zhui");      	
map_skill("unarmed", "jinshe-zhang");      	
map_skill("dodge", "youlong-shenfa");      	
map_skill("parry", "jinshe-jian");	
set("chat_chance_combat", 350);  	
set("chat_msg_combat", ({	
(: perform_action, "sword.hengkong" :),	
(: perform_action, "sword.suo" :),	
(: perform_action, "throwing.tuwu" :),	
(: perform_action, "unarmed.youshen" :),	
(: perform_action, "unarmed.fugu" :),	
}));	
set("chat_chance",15);  	
set("chat_msg", ({	
(: command("unwield zhui"):),	
(: command("unwield jian"):),	
(: command("wield jian"):),	
(: command("wield zhui"):),	
(: command("exercise 150"):),	
(: random_move :),	
}));	
	
	setup();
	
	carry_object("/clone/misc/cloth")->wear();
carry_object("/clone/book/jinshe1");	
carry_object("/d/jinshe/obj/jinshe-zhui")->wield();          
carry_object("/d/city3/obj/jinshejian")->wield();       	
}

int accept_object(object who, object ob)
{
	object obn;

	if( !who || environment(who) != environment() ) return 0;
	if ( !objectp(ob) ) return 0;
	if ( !present(ob, who) ) return notify_fail("你没有这件东西。\n");

        if (  (string)ob->query("id") != "shou pa")
		    return notify_fail("夏雪宜不需要这件东西。\n");
         write(HIY "夏雪宜接过手帕，呆呆地出神，突然间潸然泪下。 \n" NOR);
         write(HIR "夏雪宜喃喃道：仪儿啊，我知道你的心意，其实就算是真的，我也不在乎的。\n" NOR);         
         write(HIY "夏雪宜转过头来对你说：我该怎样感谢你呢？\n" NOR);
         write(HIY "他背转身去，沉默不语，好象在思考着什么。\n" NOR);
         write(HIY "夏雪宜突然象下了很大决心似地对你说：我看\n" NOR);
         write(HIY "你也是武林中人，这里有本我毕身心血的《金蛇剑谱》，\n" NOR);
         write(HIY "现在它对我来说已经没有什么用了，你就拿去吧。\n" NOR);
         write(HIY "夏雪宜叹了口气道：你是锄恶扬善也好，我行我素也好，胡作非为也好，通通与我无关。\n" NOR);
         write(HIY "夏雪宜挥了挥手：好了，你可以走了。\n" NOR);

	obn = new("/d/city3/wenzai/npc/obj/jianpu");
	obn->move(who);
     destruct(ob);
      return 1;
}
