// jiaotou.c
// 沙千里
// by star
#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("沙千里", ({ "sha qianli", "sha" }));
        set("nickname", HIG "黑龙" NOR);
        set("long",@LONG
他就是五毒教的护法弟子沙千里，身材魁梧，方面大耳。在教中转管招募
教众，教授弟子们的入门功夫。
LONG
        );
        set("title","五毒教护法弟子");
        set("gender", "男性");
        set("age", 32);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 20);
        set("int", 20);
        set("con", 20);
        set("dex", 20);
        set("max_qi", 1000);
        set("max_jing", 1000);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiali", 40);
        set("combat_exp", 1000000);
        set("score", 5000);

        set_skill("force", 150);
        set_skill("wudu-shengong", 150);
        set_skill("dodge", 150);
        set_skill("wudu-yanluobu", 150);
        set_skill("unarmed", 180);
        set_skill("qianzhu-wandushou", 200);
        set_skill("parry", 170);
        set_skill("sword", 170);
        set_skill("wudu-goufa", 170);
        set_skill("duji", 180);
        set_skill("literate", 60);
//        set_skill("hammer", 60);
//        set_skill("jinshe-chui", 70 );
//      set_skill("strike", 200 );


        map_skill("force", "wudu-shengong");
        map_skill("dodge", "wudu-yanluobu");
        map_skill("unarmed", "qianzhu-wandushou");
        map_skill("parry", "wudu-goufa");
        map_skill("sword", "wudu-goufa");
//        map_skill("hammer", "jinshe-chui");

        create_family("五毒教", 13, "护法弟子");

        setup();

        carry_object(__DIR__"obj/ganggou")->wield();
        carry_object("/d/city/obj/cloth")->wear();

        add_money("silver",30);
}

void attempt_apprentice(object ob)
{

                  if ((string)ob->query("gender") == "无性") {
                                 command("say 这位公公不要开玩笑了。");
                command("say 这位" + RANK_D->query_respect(ob) +
                        "还是快去伺候皇上吧！");
                return;
                  }

                  if ((int)ob->query("shen") > 1000) {
                                 command("say 做我五毒教弟子必须心狠手辣。");
                command("say 我教弟子贵在随心所欲，不收伪君子");
                return;
                  }
if ((int)ob->query("age") > 18 ) {	
command("say 我教神功需孩童之身练之!");        	
return;
}


          command("chat* hehe "+ob->query("id"));
          command("chat 该当我五毒教发扬光大，称霸武林指日可待了。");

        command("recruit " + ob->query("id"));
        ob->set("class", "none");
         ob->set("title",HIY"五毒教徒"NOR);
       return;
}

