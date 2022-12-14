// yuan.c 
inherit NPC;

void create()
{
        set_name("圆真", ({ "yuan zhen", "yuan" }) );
        set("age", 56);
        set("long", "少林的弟子，被江湖人称“混元霹雳手”的便是,\n看起来满脸的阴气。\n");
       set("gender", "男性");
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 28);
        set("int", 28);
        set("con", 24);
        set("dex", 25);

        set("max_qi", 800);
        set("max_jing", 200);
        set("neili", 800);
        set("max_neili", 800);
        set("jiali", 60);
        set("combat_exp", 1000000);
        set("shen",-500000);
        set("score", -100);

        set_skill("force", 201);
        set_skill("sword", 201);
        set_skill("dodge", 180);
        set_skill("unarmed",201);
        set_skill("parry", 201);
        set_skill("sword", 201);
       set_skill("hunyuan-yiqi",201);
        set_skill("fumo-jian",201);
       set_skill("shaolin-shenfa",280);

       map_skill("dodge","shaolin-shenfa");
       map_skill("sword","fumo-jian");
       map_skill("parry","fumo-jian");
       map_skill("force","hunyuan-yiqi");
       setup();
       carry_object("/clone/weapon/changjian")->wield();
       carry_object("/clone/misc/cloth")->wear();
        add_money("gold", 1);

}

void init()
{
        object ob;
        ::init();
        if (interactive(ob = this_player()) &&
                random(ob->query_kar() + ob->query_per()) < 30) {
                        remove_call_out("kill_ob");
                        call_out("kill_ob", 1, ob); 
        }
}
void unconcious()
{
        object ob;
        tell_room(environment(this_player()), "圆真惨嚎一声，倒在地上，头颅已然不见了．\n");
        ob = new(__DIR__"obj/rentou");
        ob->move(environment(this_object()));
        this_object()->set("long", "少林的弟子，被江湖人称“混元霹雳手”的便是,\n看起来满脸的阴气，只是，目前已经没有了头颅。\n");
        ::die();
}

void die()
{
        unconcious();
}

