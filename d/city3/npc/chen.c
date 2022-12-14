
inherit NPC;
inherit F_MASTER;

void consider();

void create()
{
        set_name("陈玉林", ({"chen yulin", "chen", "yulin"}));
        set("title", "丐帮成都分舵舵主");
        set("nickname", "不见天日");
	set("gender", "男性");
        set("age", 36);
	set("long", 
                "陈玉林虽然武功算不得顶尖高手，可是在江湖上却颇有声望。\n"
		"因为他在丐帮中有仁有义，行事光明磊落，深得洪七公的器重。\n");
	set("attitude", "peaceful");
	set("str", 25);
	set("int", 12);
	set("con", 25);
	set("dex", 20);

        set("qi", 600);
        set("max_qi", 600);
	set("jing", 100);
	set("max_jing", 100);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiali", 50);
	
        set("combat_exp", 120000);
        set("score", 4000);
	
        set_skill("force", 60);                         // 基本内功
        set_skill("huntian-qigong", 60);        // 混天气功
        set_skill("unarmed", 65);                       // 基本拳脚
        set_skill("xianglong-zhang", 60);       // 降龙十八掌
        set_skill("dodge", 60);                         // 基本躲闪
        set_skill("xiaoyaoyou", 60);            // 逍遥游
        set_skill("parry", 60);                         // 基本招架
        set_skill("staff", 75);                         // 基本棍杖
        set_skill("begging", 50);
	
	map_skill("force", "huntian-qigong");
	map_skill("unarmed", "xianglong-zhang");
	map_skill("parry", "xianglong-zhang");
	map_skill("dodge", "xiaoyaoyou");
	
        create_family("丐帮", 19, "分舵舵主");

	set("chat_chance_combat", 20);
	set("chat_msg_combat", ({
		(: perform_action, "unarmed.xianglong" :),
		(: exert_function, "recover" :),
	}) );

	setup();
        carry_object("/clone/misc/cloth")->wear();
}

void attempt_apprentice(object ob)
{
	if ( (int)ob->query("int") >= 25 ) {
		command("say 我们丐帮的武艺一向以刚猛为主，" + 
		RANK_D->query_respect(ob) + "聪慧过人，似乎不宜学丐帮的功夫？");
		return;
	}
	command("say 好吧，希望" + RANK_D->query_respect(ob) +
	"能好好学习本门武功，将来在江湖中闯出一番作为。");
	command("recruit " + ob->query("id"));
	if((string)ob->query("class") != "beggar")
		ob->set("class", "beggar");
}
