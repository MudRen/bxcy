// miejue.c 灭绝
// create by host dec,12

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("灭绝", ({ "mie jue", "mie", "jue"}));
        set("long",
"她是一位白发苍苍的老尼，是峨嵋派第三代掌门，她脸上冷冰冰，毫无表情。\n");

        set("gender", "女性");
        set("age", 60);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 30);
        set("int", 28);
        set("con", 30);
        set("dex", 30);

        set("qi", 4000);
        set("max_qi", 4000);
        set("jing", 3000);
        set("max_jing", 3000);
        set("neili", 6000);
        set("max_neili", 6000);
        set("jiali", 100);

        set("combat_exp", 20000000);
        set("score", 300000);

        set_skill("force", 500);
        set_skill("dodge", 550);
        set_skill("blade", 580);
        set_skill("unarmed",580);
        set_skill("parry", 500);
        set_skill("sword", 500);
        set_skill("linji-zhuang",500);
        set_skill("jinding-zhang",500);
        set_skill("huifeng-jian",500);
        set_skill("yanxing-dao", 580);
        set_skill("tiangang-zhi", 580);
        set_skill("zhutian-bu",550);
        set_skill("yugalism", 580);
        set_skill("dushi-jiren",500);
        set_skill("literate", 500);
        map_skill("dodge","zhutian-bu");
        map_skill("parry", "huifeng-jian");
        map_skill("sword", "huifeng-jian");
        map_skill("force","linji-zhuang");
        map_skill("unarmed","tiangang-zhi");
        map_skill("blade","yanxing-dao");
        prepare_skill("strike", "jinding-zhang");
        prepare_skill("unarmed", "tiangang-zhi");

        create_family("峨嵋派", 3,"掌门");
        set("class","bonze");
        setup();
        carry_object("/clone/misc/cloth")->wear();
//        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/emei/obj/yitian-jian")->wield();
  }

void attempt_apprentice(object ob)
 {

     string *prename = ({ "静" });
     string name, new_name;
     if ((string)ob->query("gender") != "女性") {
       command("say 我怎么能够收男子为徒呢？");
       return; 
     }  
     if((string)ob->query("class")!="bonze" )
       {
       command("say 阿弥陀佛！善哉！善哉！施主若真心皈依我佛，可去静心那里受戒。");
       return ;
       }
      if ((int)ob->query("shen") < 0) {
           command("say 我峨嵋乃是堂堂名门正派，对弟子要求极严。");
                command("say 在德行方面，" + RANK_D->query_respect(ob) +
                        "是否还做得不够？");
                return;
        }
     
     if ( ob->query("married") )
        {
           command("say 入我门者，最忌妄动尘缘！"+RANK_D->query_respect(ob)+"还是请回吧！"); 
           return ;
         }  
     if ( ob->query_skill("linji-zhuang",1) < 80 )
        {
           command("say 这位"+RANK_D->query_respect(ob)+"对我峨嵋内功似乎领会的不够。");
           command("say 是否应该多在这上面下点功夫。");
           return ;
         }
     if ( ob->query_con() < 28 && ob->query_int() < 28 )
       {
           command("sigh");
           command("say 这位"+RANK_D->query_respect(ob)+"恐怕资质差了一点。");
           command("say 不过尚大有潜力，还是先回去磨练磨练。");
           return ;
        }
   name = ob->query("name");
   new_name = prename[random(sizeof(prename))] + name[2..3];
   ob->set("name", new_name);
   command("smile");
   command("say 从今以后你的法名叫做" + new_name + "。");
   command("recruit " + ob->query("id"));
  }
