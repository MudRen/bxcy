// Npc: /kungfu/class/shaolin/qing-wei.c
// Date: YZC 96/01/19
inherit NPC;
inherit F_MASTER;
void create()
{
    set_name("清为比丘", ({
        "qingwei biqiu",
        "qingwei",
        "biqiu",
    }));
    set("long",
        "他是一位体格强健的壮年僧人，他身得虎背熊腰，全身似乎蕴含\n"
        "着无穷劲力。他身穿一袭白布黑边袈裟，似乎身怀武艺。\n"
    );
    set("gender", "男性");
    set("attitude", "friendly");
    set("class", "bonze");
    set("age", 30);
    set("str", 23);
    set("int", 19);
    set("con", 22);
    set("dex", 20);
    set("max_qi", 350);
    set("max_jing", 200);
    set("neili", 350);
    set("max_neili", 350);
    set("jiali", 30);
    set("combat_exp", 5000);
    set("score", 100);
    set_skill("force", 30);
    set_skill("hunyuan-yiqi", 30);
    set_skill("dodge", 30);
    set_skill("shaolin-shenfa", 30);
    set_skill("unarmed", 30);
    set_skill("banruo-zhang", 30);
    set_skill("parry", 30);
    set_skill("buddhism", 30);
    set_skill("literate", 30);
    map_skill("force", "hunyuan-yiqi");
    map_skill("dodge", "shaolin-shenfa");
    map_skill("unarmed", "banruo-zhang");
    map_skill("parry", "banruo-zhang");
    
    create_family("少林派", 40, "弟子");
    setup();
        carry_object("/d/shaolin/obj/qing-cloth")->wear();
}
void attempt_apprentice(object ob)
{
    object me  = this_object();
    mapping ob_fam = ob->query("family");
    mapping my_fam = me->query("family");
    if( (string)ob->query("gender") != "男性" )
    {
        command ("say 阿弥陀佛！女施主呀，贫僧可不敢开这等玩笑啊。");
        return;
    }
    
    if (mapp(ob_fam))
    if ( ob_fam["family_name"] == "少林派" && (ob_fam["generation"] <= my_fam["generation"]) )
    {
        command("say " + RANK_D->query_respect(ob) + "，贫僧哪里敢当 !");
        return;
    }
    if( (string)ob->query("class")!="bonze" )
    {
        command ("say 阿弥陀佛！贫僧就收下你做『俗家弟子』了。");
    }
    command("say 阿弥陀佛，善哉！善哉！");
    command("recruit " + ob->query("id"));
}
