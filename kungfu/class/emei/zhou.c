// zhou.c 周芷若
// create by host oct,23

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("周芷若", ({ "zhou zhiruo", "zhou", "zhiruo"}));
        set("long",
"她是一位容貌美丽，端庄可爱的姑娘。虽然年纪很轻，但在峨嵋派中是\n出类拔萃的人物。\n");
        set("gender", "女性");
        set("age", 20);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 20);
        set("int", 35);
        set("con", 30);
        set("dex", 30);
        set("per", 40);

        set("qi", 2200);
        set("max_qi", 2200);
        set("jing", 1600);
        set("max_jing", 1600);
        set("neili", 2000);
        set("max_neili", 2000);
        set("jiali", 30);

        set("combat_exp", 8000000);
        set("score", 150000);

        set_skill("force", 280);
        set_skill("dodge", 280);
        set_skill("parry", 280);
        set_skill("sword", 280);
        set_skill("linji-zhuang",280);
        set_skill("jinding-zhang",260);
        set_skill("huifeng-jian",280);
        set_skill("zhutian-bu",285);
        set_skill("yugalism", 260);
        set_skill("dushi-jiren",150);
        set_skill("unarmed", 350);
        set_skill("zhuyan-shu", 320);
        set_skill("jiuyin-baiguzhao", 300);
        set_skill("literate", 120);
        map_skill("dodge","zhutian-bu");
        map_skill("strike","jinding-zhang");
        map_skill("unarmed","jiuyin-baiguzhao");
        map_skill("parry", "huifeng-jian");
        map_skill("sword", "huifeng-jian");
        map_skill("force","linji-zhuang");
        prepare_skill("unarmed", "jiuyin-baiguzhao");

        create_family("峨嵋派", 4,"弟子");
        set("class","tao_lady");
        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield();
  }

void attempt_apprentice(object ob)
 {

    mapping myfam;
    if ( (!(myfam = ob->query("family")) || myfam["family_name"] != "峨嵋派") )
       {
          command("say 我只收峨嵋门下弟子，你还是请回吧！");
          return;
        }
    if ((int)ob->query("shen") < 0) {
           command("say 我峨嵋乃是堂堂名门正派，对弟子要求极严。");
                command("say 在德行方面，" + RANK_D->query_respect(ob) +
                        "是否还做得不够？");
                return;
        }
    if ( (int)ob->query("combat_exp") > 100000 && (int)ob->query("betrayer") > (int)ob->query("K_betrayer"))
     {
         command("heng");
         command("say 象你这样不守门规，三心二意。我怎能再收你为徒。");
         return;
        }

    if ((int)ob->query("per") < 22 ) {
           command("giggle");
           command("say 这位"+RANK_D->query_respect(ob)+"容貌太也...，哎！还是请回吧！");
           return ;
       }

    if ((int)ob->query_dex() < 26  && (int)ob->query_int() < 28 ) {       
           command("say 这位"+RANK_D->query_respect(ob)+"恐怕资质差了一点。");
           command("say 不过尚大有潜力，还是先回去磨练磨练。");
           return ;
        }
    command("smile");
    command("recruit " + ob->query("id"));
//    if( (string)ob->query("class") != "swordsman");
//    ob->set("class","swordsman");
    ob->set("K_betrayer", (int)ob->query("betrayer") );
}
