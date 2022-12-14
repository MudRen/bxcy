// jingkong.c 静空
// create by host dec,11
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("静空", ({ "jing kong", "jing", "kong"}));
        set("long",
        "她是峨嵋派三师姐，由于资质并不甚高，只得传了灭绝师太的一套指法。\n");
        set("gender", "女性");
        set("age", 38);
        set("attitude", "peaceful");
        set("nickname", HIY "三师姐" NOR);
        set("shen_type", 1);
        set("str", 24);
        set("int", 26);
        set("con", 26);
        set("dex", 28);

        set("qi", 1600);
        set("max_qi", 1600);
        set("jing", 1000);
        set("max_jing", 1000);
        set("neili", 1300);
        set("max_neili", 1300);
        set("jiali", 40);

        set("combat_exp", 1750000);
        set("score", 100000);

        set_skill("force", 160);
        set_skill("dodge", 180);
        set_skill("parry", 180);
        set_skill("unarmed",170);
        set_skill("linji-zhuang",180);
        set_skill("zhutian-bu",180);
        set_skill("tiangang-zhi",180);
        set_skill("literate", 180);
        map_skill("dodge","zhutian-bu");
        map_skill("parry", "tiangang-zhi");
        map_skill("unarmed", "tiangang-zhi");
        map_skill("force","linji-zhuang");
        prepare_skill("unarmed", "tiangang-zhi");

        create_family("峨嵋派", 4,"弟子");
        set("class","bonze");
        setup();
        carry_object("/clone/misc/cloth")->wear();
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
     if ((int)ob->query("shen") < 0)
        {
        command("say 我峨嵋乃是堂堂名门正派，对弟子要求极严。");
        command("say 在德行方面，" + RANK_D->query_respect(ob) +
                 "是否还做得不够？");
                return;
        }
    if ((int)ob->query("dex") < 26) 
        {
		command("say " + RANK_D->query_respect(ob) + 
			"的身法修为不足，恐怕难以学习我这套指法。");
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
