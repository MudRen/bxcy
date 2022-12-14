// jingxuan.c 静玄
// create by host dec,11
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("静玄", ({ "jing xuan", "jing", "xuan"}));
        set("long",
          "她是峨嵋派大师姐，跟随灭绝师太二十余载，峨嵋派的基本功夫已尽得所传。\n");
        set("gender", "女性");
        set("age", 40);
        set("attitude", "peaceful");
        set("nickname", HIY "大师姐" NOR);
        set("shen_type", 1);
        set("str", 28);
        set("int", 28);
        set("con", 28);
        set("dex", 28);

        set("qi", 2300);
        set("max_qi", 2300);
        set("jing", 1500);
        set("max_jing", 1500);
        set("neili", 1800);
        set("max_neili", 1800);
        set("jiali", 40);

        set("combat_exp", 3850000);
        set("score", 100000);

        set_skill("force", 210);
        set_skill("dodge", 210);
        set_skill("parry", 220);
        set_skill("sword", 220);
        set_skill("linji-zhuang",210);
        set_skill("huifeng-jian",225);
        set_skill("zhutian-bu",210);
        set_skill("yugalism", 180);  
        set_skill("literate", 200);
        map_skill("dodge","zhutian-bu");
        map_skill("parry", "huifeng-jian");
        map_skill("sword", "huifeng-jian");
        map_skill("force","linji-zhuang");

        create_family("峨嵋派", 4,"弟子");
        set("class","bonze");
        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield();
  }

void attempt_apprentice(object ob)
 {
     
     object me;
     me = this_player();

     if ((string)ob->query("gender") != "女性" )
      {
        command("say 我怎么能够收男子为徒呢？");
       return;
      }
/*     if(!(ob_fam = ob->query("family")) || ob_fam["family_name"] != "峨嵋派")
	{
		command("say " + RANK_D->query_respect(ob) + "与本派素无来往，不知此话从何谈起？");
		return;
	}  */
     if ((int)ob->query("shen") < 0)
        {
        command("say 我峨嵋乃是堂堂名门正派，对弟子要求极严。");
        command("say 在德行方面，" + RANK_D->query_respect(ob) +
                 "是否还做得不够？");
                return;
        }
    if ((int)ob->query_skill("linji-zhuang", 1) < 50) 
        {
		command("say " + RANK_D->query_respect(ob) + 
			"的内功火候是否还不够，应该在临济十二庄上多下点功夫。");
		return;
  	}       
    if( (string)me->query("class")=="bonze" )
       {
             command("nod");
             command("recruit " + ob->query("id"));
       }
     
      else {

                command("say 阿弥陀佛！善哉！善哉！施主若真心皈依我佛，可去静心那里受戒。\n");
		return ;
            }

  }
