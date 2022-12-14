// shihou.c 狮吼子
inherit NPC;
inherit F_MASTER;
string ask_me();
void create()
{
    set_name("狮吼子", ({ "shihou zi", "shihou" }));
    set("nickname", "星宿派二师兄");
    set("long", 
        "他就是丁春秋的二弟子狮吼子。\n"
        "他三十多岁，狮鼻阔口，一望而知不是中土人士。\n");
    set("gender", "男性");
    set("age", 32);
    set("attitude", "peaceful");
    set("shen_type", -1);
    set("str", 28);
    set("int", 20);
    set("con", 26);
    set("dex", 22);
    
    set("max_qi", 500);
    set("max_jing", 500);
    set("neili", 1000);
    set("max_neili", 1000);
    set("jiali", 20);
    set("combat_exp", 200000);
    set("score", 30000);
    set_skill("force", 100);
    set_skill("huagong-dafa", 110);
    set_skill("dodge", 110);
    set_skill("zhaixinggong", 110);
    set_skill("unarmed", 110);
    set_skill("xingxiu-duzhang", 110);
    set_skill("parry", 110);
    set_skill("staff", 110);
    set_skill("tianshan-zhang", 110);
    set_skill("literate", 100);
    map_skill("force", "huagong-dafa");
    map_skill("dodge", "zhaixinggong");
    map_skill("unarmed", "xingxiu-duzhang");
    map_skill("parry", "tianshan-zhang");
    map_skill("staff", "tianshan-zhang");
    create_family("星宿派", 2, "弟子");
    setup();
    carry_object("/clone/weapon/gangzhang")->wield();
    carry_object("/clone/misc/cloth")->wear();
}
void attempt_apprentice(object ob)
{
    command("say 好吧，我就收下你了。");
    command("recruit " + ob->query("id"));
}
