// jingxu.c 静虚
// create by host dec,11
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("静虚", ({ "jing xu", "jing", "xu"}));
        set("long",
          "她是峨嵋派二师姐，峨嵋门下多年，一套峨嵋掌法名动江湖。。\n");
        set("gender", "女性");
        set("age", 40);
        set("attitude", "peaceful");
        set("nickname", HIY "二师姐" NOR);
        set("shen_type", 1);
        set("str", 27);
        set("int", 25);
        set("con", 27);
        set("dex", 25);

        set("qi", 2000);
        set("max_qi", 2000);
        set("jing", 1000);
        set("max_jing", 1000);
        set("neili", 1700);
        set("max_neili", 1700);
        set("jiali", 40);

        set("combat_exp", 3000000);
        set("score", 100000);

        set_skill("force", 210);
        set_skill("dodge", 200);
        set_skill("parry", 220);
        set_skill("unarmed",220);
        set_skill("linji-zhuang",210);
        set_skill("zhutian-bu",200);
        set_skill("jinding-zhang",220);
        set_skill("yugalism", 180);  
        set_skill("literate", 180);
        map_skill("dodge","zhutian-bu");
        map_skill("parry", "jinding-zhang");
        map_skill("unarmed", "jinding-zhang");
        map_skill("force","linji-zhuang");
        prepare_skill("unarmed", "jinding-zhang");

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
    if ((int)ob->query("str") < 26) 
        {
		command("say " + RANK_D->query_respect(ob) + 
			"的臂力不足，恐怕无法修炼跟高的掌法。");
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
