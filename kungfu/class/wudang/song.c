// song.c 宋远桥
inherit NPC;
inherit F_MASTER;
string ask_me();
void create()
{
    set_name("宋远桥", ({ "song yuanqiao", "song" }));
    set("nickname", "武当首侠");
    set("long", 
        "他就是张三丰的大弟子、武当七侠之首的宋远桥。\n"
        "身穿一件干干净净的灰色道袍。\n"
        "他已年过六十，身材瘦长，满脸红光。恬淡冲和，沉默寡言。\n");
    set("gender", "男性");
    set("age", 61);
    set("attitude", "peaceful");
    set("shen_type", 1);
    set("str", 38);
    set("int", 58);
    set("con", 68);
    set("dex", 128);
    
    set("max_qi", 1000);
    set("max_jing", 1000);
    set("neili", 16000);
    set("max_neili", 8000);
    set("jiali", 50);
    set("combat_exp", 2400000);
    set("score", 70000);
    set_skill("force", 280);
    set_skill("taiji-shengong", 280);
    set_skill("dodge", 285);
    set_skill("tiyunzong", 260);
    set_skill("unarmed", 280);
    set_skill("taiji-quan", 280);
    set_skill("parry", 280);
    set_skill("taoism",500);
    set_skill("sword", 280);
    set_skill("taiji-jian", 260);
    set_skill("literate", 250);
    map_skill("force", "taiji-shengong");
    map_skill("dodge", "tiyunzong");
    map_skill("unarmed", "taiji-quan");
    map_skill("parry", "taiji-jian");
    map_skill("sword", "taiji-jian");
    create_family("武当派", 2, "弟子");
    set("inquiry", ([
        "秘籍" : (: ask_me :),
    ]));
    set("book_count", 1);
    set("chat_chance_combat", 40);
    set("chat_msg_combat", ({
        (: perform_action, "unarmed.zhen" :),
        (: exert_function, "recover" :),
    }) );
    setup();
//  carry_object("/clone/weapon/changjian")->wield();
    carry_object("/d/wudang/obj/greyrobe")->wear();
}
void attempt_apprentice(object ob)
{
    if ((int)ob->query("shen") < 0) {
        command("say 我武当乃是堂堂名门正派，对弟子要求极严。");
        command("say 在德行方面，" + RANK_D->query_respect(ob) +
            "是否还做得不够？");
        return;
    }
    command("say 好吧，贫道就收下你了。");
    command("recruit " + ob->query("id"));
    if( (string)ob->query("class") != "taoist")
        ob->set("class", "taoist");
}
string ask_me()
{
    mapping fam; 
    object ob;
    
    if (!(fam = this_player()->query("family")) || fam["family_name"] != "武当派")
        return RANK_D->query_respect(this_player()) + 
        "与本派素无来往，不知此话从何谈起？";
    if (query("book_count") < 1)
        return "你来晚了，本派的内功心法不在此处。";
    add("book_count", -1);
    ob = new(__DIR__"force_book");
    ob->move(this_player());
    return "好吧，这本「太极十三式」你拿回去好好钻研。";
}
