// shihou.c 出尘子
inherit NPC;
inherit F_MASTER;
string ask_me();
void create()
{
    set_name("出尘子", ({ "chuchen zi", "chuchen" }));
    set("nickname", "星宿派八师兄");
    set("long", 
        "他就是丁春秋的八弟子出尘子。\n"
        "他身才矮胖，可手中握的钢杖又长又重。\n");
    set("gender", "男性");
    set("age", 25);
    set("attitude", "peaceful");
    set("shen_type", -1);
    set("str", 30);
    set("int", 15);
    set("con", 28);
    set("dex", 28);
    
    set("max_qi", 300);
    set("max_jing", 300);
    set("neili", 800);
    set("max_neili", 800);
    set("jiali", 15);
    set("combat_exp", 100000);
    set("score", 20000);
    set_skill("force", 120);
    set_skill("huagong-dafa", 120);
    set_skill("dodge", 120);
    set_skill("zhaixinggong", 120);
    set_skill("unarmed", 120);
    set_skill("xingxiu-duzhang", 120);
    set_skill("parry", 120);
    set_skill("staff", 120);
    set_skill("tianshan-zhang", 120);
//  set_skill("literate", 120);
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
void init()
{
        object ob;
        mapping myfam;
        
        ::init();
        if (interactive(ob = this_player()) && !is_fighting()) {
                myfam = (mapping)ob->query("family");
                if ((!myfam || myfam["family_name"] != "星宿派") &&
                        (!wizardp(ob))) {
                        remove_call_out("do_killing");
                        call_out("do_killing",4,ob);
                }
        }
}
void do_killing(object ob)
{
    if (!ob || environment(ob) != environment())
                return;
        this_object()->kill_ob(ob);
}
void attempt_apprentice(object ob)
{
    command("say 老仙还没允许我收徒呢。");
    //command("recruit " + ob->query("id"));
}
