// qqren.c 裘千仞

inherit NPC;
int ask_qiubai();
inherit F_MASTER;

void create()
{
    set_name("裘千仞", ({ "qiu qianren", "qiu", "qianren", "ren"}));
    set("nickname", "铁掌水上漂");
	set("long", 
        "他就是威震川湘的铁掌帮的帮主-铁掌水上漂裘千仞。\n"
        "他是一个白须老头，身穿黄葛短衫，右手挥着一把大蒲扇。\n");
	set("gender", "男性");
	set("age", 60);
    set("attitude", "peaceful");
	set("shen_type", -1);
        set("str", 35);
	set("int", 30);
	set("con", 28);
        set("dex", 35);
	
set("max_qi", 400000);	
set("max_jing", 300000);	
set("neili", 5000000);	
set("max_neili", 4000);	
set("jiali", 5000);     	
set("combat_exp", 500000000);	
	set("score", 400000);
set_skill("hammer",1200);	
set_skill("tiexue-hammer",1180);	
set_skill("force", 1160);	
set_skill("guiyuan-tunafa", 1200);	
set_skill("dodge", 1160);	
set_skill("shuishangpiao", 1200);	
set_skill("unarmed", 1200);	
set_skill("tiezhang-zhangfa", 1200);	
set_skill("parry", 1160);	
set_skill("literate", 1000);	
set_skill("axe", 1160);	
set_skill("duanyun-fu", 1200);	
	map_skill("hammer", "tiexue-hammer");

	map_skill("force", "guiyuan-tunafa");
	map_skill("dodge", "shuishangpiao");
map_skill("unarmed", "tiezhang-zhangfa");	
	map_skill("parry", "tiezhang-zhangfa");
set("chat_chance_combat", 200);	
        set("chat_msg_combat", ({
(: perform_action, "unarmed.tianlei" :),	
(: perform_action, "unarmed.tianlei" :),	
(: perform_action, "unarmed.tiezhangxianglong" :),	
(: perform_action, "unarmed.tiezhangxianglong" :),	
(: perform_action, "unarmed.zhangdao" :),	
(: perform_action, "unarmed.zhangdao" :),	
        }) );


    create_family("铁掌帮", 14, "帮主");

    set("inquiry", ([
"name" : "老夫便是“铁掌水上漂”裘千仞，你问老夫姓名有什么事么？\n",
"here" : "这里就是铁掌帮的总坛所在，你如没事，不要四处乱走，免招杀身之祸！！！\n",
"上官剑南" : (: ask_qiubai :),
    ]));

	setup();
	carry_object(__DIR__"obj/black-cloth")->wear();
}

void attempt_apprentice(object me)
{
        if ((int)me->query("shen") > -10000) {
                command("hehe");
                command("say 我裘千仞可不收心慈手软的人做徒弟。");
                return;
        }
                command("say 好吧，我就收下你了。希望你苦练铁掌神功，将之发扬光大。");
                command("recruit " + me->query("id"));
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                add("apprentice_available", -1);
}
int ask_qiubai()
{
say("他是我师父。我在十三岁那年曾救过他，之后他感恩图报，将全\n"
    "身武功倾囊相受。可惜十年前，他在湖北遭人围攻而死！唉！\n");
return 1;
}
