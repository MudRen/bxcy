inherit NPC;
inherit F_MASTER;
object ob = this_object();

void create()
{
        set_name("慕容博",({"murong bo","murong","bo"}));
        set("title","姑苏慕容老爷子");
        set("nick","以彼之道 还施彼身");
        set("long", 
              "他就是天下号称以彼之道，还彼之身的姑苏慕容博。\n"
              "他脸上带着不可一世的笑容。\n");
        set("age", 57);
          set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 40);
        set("int", 40);
        set("con", 40);
        set("dex", 40);
        
        set("max_qi", 4500);
        set("max_jing", 4500);
        set("neili", 4500);
        set("max_neili", 4500);
        set("jiali", 0);
        set("combat_exp", 20000000);
        set("score", 50000);                
set("chat_chance_combat",40);
        set("chat_msg_combat", ({
        (: perform_action, "parry.xingyi" :)
}));
    
         set_skill("unarmed",500);
        set_skill("dodge",500);
        set_skill("force", 500);
        set_skill("canhe-zhi", 500);
        set_skill("murong-jianfa",500);       
       set_skill("shenyuan-gong", 501);
        set_skill("yanling-shenfa", 500);
        set_skill("douzhuan-xingyi", 530);
        set_skill("parry", 510);
        set_skill("sword", 500);
        set_skill("literate", 500);
        set_skill("murong-daofa", 500);
        set_skill("blade",500);
        
        map_skill("blade", "murong-daofa");
        map_skill("unarmed", "canhe-zhi");
        map_skill("force", "shenyuan-gong");
       set("jiali",200);
        map_skill("dodge", "yanling-shenfa");
        map_skill("parry", "douzhuan-xingyi");
        map_skill("sword", "murong-jianfa");

        prepare_skill("finger","canhe-zhi");
        
        create_family("姑苏慕容",1,"弟子");

        set("inquiry", 
                ([
                        "name" : "我就是以彼之道，还施彼身的姑苏慕容博。\n",
                        "here" : "这里是少林寺的藏经楼。\n",
                        "rumors" : "我那慕容复儿在武林之中闯出了名头，老爷子我是真高兴呀！\n",
                        
                ]));
        setup();
        
        carry_object("/d/city/obj/gangjian")->wield();
}

void attempt_apprentice(object ob)
{
        if (ob->query_skill("parry", 1) < 170) {
                command("say 我姑苏慕容以彼之道、还施彼身对招架要求甚高，小兄弟似乎不宜学习。");
    command("say " + RANK_D->query_respect(ob) + "的功力不够，还是请回吧。");
                return;
        }

        if (ob->query_skill("shenyuan-gong", 1) < 160) {
                command("say 我姑苏慕容以彼之道、还施彼身对内功心法要求甚高，小兄弟似乎不宜学习。");
    command("say " + RANK_D->query_respect(ob) + "的功力不够，还是请回吧。");
                return;
        }

  command("say 嗯，看你还是个学武的料，我就收下你吧！");
        command("say 苍天在上，让我姑苏慕容又得一良材，为复兴我大燕多了一份力量。");
        command("chat# 朗声说道：老夫我又收一良材，大燕兴复指日可待啦！");
        command("chat* haha"); 
        command("recruit " + ob->query("id"));
        ob->set("title","以彼之道 还施彼身");
}
