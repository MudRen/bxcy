// ning.c 宁中则
inherit NPC;
inherit F_MASTER;
int ask_book(string str);
void create()
{
    set_name("宁中则", ({ "ning zhongze", "ning", "zhongze", "shiniang" }));
        set("long",   @LONG
她就是华山派的现任掌门人——“君子剑”岳不群的夫人。她为人和蔼可\ 
亲，颇受华山派中弟子敬仰。虽然已是三十出头了，但是却风韵尤存。一\ 
看就知道她以前必定是个美人。\ 
LONG );
        set("inquiry", ([
                "华山剑谱": (: ask_book :),
        ]) );
    set("gender", "女性");
    set("age", 38);
    set("attitude", "peaceful");
    set("shen_type", 1);
    set("str", 20);
    set("int", 35);
    set("con", 30);
        set("per", 28);
    set("dex", 30);
    
    set("qi", 2200);
    set("max_qi", 2200);
    set("jing", 1600);
    set("max_jing", 1600);
    set("neili", 2000);
    set("max_neili", 2000);
    set("jiali", 30);
    set("combat_exp", 1060000);
    set("combat_exp", 1060000);
    set_skill("force", 220);
    set_skill("dodge", 220);
    set_skill("parry", 220);
    set_skill("sword", 220);
    set_skill("unarmed", 220);
    set_skill("blade", 220);
    set_skill("zixia-shengong", 220);
    set_skill("huashan-jianfa", 220);
    set_skill("huashan-shenfa", 220);
    set_skill("hunyuan-zhang", 220);
    set_skill("poyu-quan", 220);
    set_skill("fanliangyi-dao", 220);
    set_skill("literate", 220);
    map_skill("dodge", "huashan-shenfa");
    map_skill("force", "zixia-shengong");
    map_skill("parry", "huashan-jianfa");
    map_skill("sword", "huashan-jianfa");
    map_skill("unarmed", "poyu-quan");
    map_skill("blade", "fanliangyi-dao");

    create_family("华山派", 13, "弟子");
    set("chat_chance_combat", 50);
    set("chat_msg_combat", ({
        (: perform_action, "sword.jianzhang" :),
        (: perform_action, "sword.wushuang" :),
        (: exert_function, "recover" :),
    }) );
    setup();
    carry_object("/clone/misc/pink_cloth")->wear();
    carry_object("/clone/weapon/changjian")->wield();
}
void attempt_apprentice(object ob)
{
    if ((string)ob->query("gender") != "女性") {
        command("say 阁下开什么玩笑！我怎么能够收男子为徒呢？真是羞人嗒嗒的。");
                command("say 我只收女弟子，你还是去拜我丈夫吧。");
        return;
    }
    if ((int)ob->query("shen") < 0) {
        command("say 我华山派乃是堂堂名门正派，对弟子要求极严。");
        command("say 在德行方面，" + RANK_D->query_respect(ob) +
            "是否还做得不够？");
        return;
    }
    if ((int)ob->query_dex() < 20) {
        command("say 依我看" + RANK_D->query_respect(ob) + "的资质似乎不适合学我华山派武功？");
        return;
    }
    command("say 好吧，我就收下你了。");
    command("recruit " + ob->query("id"));
    if((string)ob->query("class") != "swordsman")
        ob->set("class", "swordsman");
}
int ask_book(string arg)
{
        object me;
        object ning;
        object book;
        ning=this_object();
        me=this_player();
        if (me->query("class")!="swordsman")  
                {
                  command("say 对不起，华山剑谱不可以给你。");
                  return 1;
                }
        else {
                if (ning->query_temp("sign"))  
                        {
                        command("say 你来晚啦，华山剑谱早被人拿走啦。");
                        return 1;
                        }
                else {
                        message_vision(CYN "宁中则微笑着从怀中取出华山剑谱，交了给$N \n" NOR,me);
                        book=new("/d/huashan/obj/sword-book");
                        book->move(me);
                        ning->set_temp("sign",1);
                        return 1;
                        }
                }
}
