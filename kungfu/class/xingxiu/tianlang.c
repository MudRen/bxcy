// tianlang.c 天狼子
inherit NPC;
inherit F_MASTER;
string ask_me();
void create()
{
    set_name("天狼子", ({ "tianlang zi", "tianlang" }));
    set("nickname", "星宿派三师兄");
    set("long", 
        "他就是丁春秋的三弟子天狼子。\n");
    set("gender", "男性");
    set("age", 30);
    set("attitude", "peaceful");
    set("shen_type", -1);
    set("str", 27);
    set("int", 16);
    set("con", 25);
    set("dex", 27);
    
    set("max_qi", 400);
    set("max_jing", 400);
    set("neili", 1000);
    set("max_neili", 1000);
    set("jiali", 15);
    set("combat_exp", 150000);
    set("score", 30000);
    set_skill("force", 110);
    set_skill("huagong-dafa", 115);
    set_skill("dodge", 110);
    set_skill("zhaixinggong", 110);
    set_skill("unarmed", 110);
    set_skill("xingxiu-duzhang", 110);
    set_skill("parry", 110);
    set_skill("staff", 110);
    set_skill("tianshan-zhang", 110);
    set_skill("literate", 110);
    map_skill("force", "huagong-dafa");
    map_skill("dodge", "zhaixinggong");
    map_skill("unarmed", "xingxiu-duzhang");
    map_skill("parry", "tianshan-zhang");
    map_skill("staff", "tianshan-zhang");
    create_family("星宿派", 2, "弟子");
    setup();
//      carry_object("/clone/weapon/gangzhang")->wield();
    carry_object("/clone/misc/cloth")->wear();
}
void attempt_apprentice(object ob)
{
    command("say 好吧，我就收下你了。");
    command("recruit " + ob->query("id"));
}
