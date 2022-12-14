// yangbuhui.c 

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("杨不悔", ({ "yang buhui", "yang"}));
        set("long",
                "她梳着两条羊角辫，容颜俏丽，神情天真无邪，她就是杨逍的女儿不悔。\n");
        set("gender", "女性");
        set("age",15);
        set("attitude", "friendly");
        set("shen_type", 1);
        set("str", 25);
        set("int", 24);
        set("con", 28);
        set("dex", 26);
        set("per", 24);

        set("max_qi", 600);
        set("max_jing", 100);
        set("neili", 300);
        set("max_neili", 300);
        set("jiali", 30);
        set("combat_exp", 30000);
        set("shen",1000);
        set("score", 1000);

        set_skill("force", 30);
        set_skill("shenghuo-shengong", 30);
        set_skill("dodge", 34);
        set_skill("qingyunwu", 34);
        set_skill("parry", 30);
        set_skill("sword", 32);
        set_skill("liehuo-jian", 35);
        
        map_skill("force", "shenghuo-shengong");
        map_skill("dodge", "qingyunwu");
        map_skill("sword", "liehuo-jian");

        create_family("明教", 35, "弟子");
        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield();
}

void attempt_apprentice(object ob)
{
                command("say 就我这点功夫哪敢指导你，"+RANK_D->query_respect(ob)+
                                  "还是去找我父亲吧。");
 }

