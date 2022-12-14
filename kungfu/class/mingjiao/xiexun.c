// XieXun.c
// pal 1997.05.09

#include "ansi.h"

inherit NPC;
inherit F_MASTER;
inherit F_UNIQUE;

void create()
{
    set_name("谢逊", ({"xie xun", "xie", "xun", }));
	set("long",
        "他是一位身材魁伟异常的的老者，身穿一件白布长袍。\n"
        "他满头黄发，威风凛凛，真如天神一般，只是两只眼睛并不睁开。\n"
	);

	set("title",HIG "明教" HIY "金毛狮王" NOR);
	set("level",9);
	set("gender", "男性");
	set("attitude", "peaceful");

	set("age", 63);
//	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("max_qi", 150000);
	set("max_jing", 15000);
	set("neili", 1000000);
	set("jingli", 400000);
	set("max_neili", 1000000);
	set("max_jingli", 400000);
	set("jiali", 1500);

	set("combat_exp", 150000000);
	set("score", 800000);

    	set_skill("force", 1500);
	set_skill("dodge", 1500);
	set_skill("parry", 1500);
	set_skill("unarmed", 1500);
	set_skill("hunyuan-yiqi", 1500);
	set_skill("shaolin-shenfa", 1500);
  set_skill("qishang-quan", 1500);
  set_skill("jingang-quan", 1500);
  set_skill("blade", 1500);
  set_skill("wuhu-duanmendao", 1500);
  set_skill("literate", 100);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("unarmed", "qishang-quan");
  map_skill("parry", "jingang-quan");
  map_skill("blade", "wuhu-duanmendao");

	prepare_skill("blade","wuhu-duanmendao");

	set("chat_chance_combat", 200);
    set("chat_msg_combat", ({
        (: perform_action, "blade.duan" :),
        (: perform_action, "unarmed.hunpofeiyang" :),
        (: exert_function, "recover" :),
	}) );
	setup();

    	carry_object("/clone/cloth/zixuan")->wear();
    	carry_object("/clone/cloth/lingyun")->wear();
    	carry_object("/clone/weapon/tulong")->wield();
}
/*
void init()
{
	object me,ob;
	me = this_object () ;
	ob = this_player () ;

	::init();

	if( interactive(ob) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, me, ob);
	}
}*/

#include "fawang.h"
