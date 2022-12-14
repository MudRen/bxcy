//
// /kungfu/class/xueshan/jiumozhi.c 鸠摩智
// by secret
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("鸠摩智", ({ "jiumo zhi", "zhi" ,"ming wang"}));
        set("nickname", HIG "大轮明王" NOR);
        set("long",@LONG
他就是雪山寺的掌门，人称大轮明王的鸠摩智。他对佛法有精深的研究。
身穿一件大红袈裟，头带僧帽。
LONG
        );
        set("title","雪山寺掌门");
        set("gender", "男性");
        set("age", 60);
       set("attitude", "peaceful");
        set("str", 60);
        set("int", 60);
        set("con", 80);
        set("dex", 180);
        set("max_qi", 5000);
        set("max_jing", 5000);
        set("neili", 15000);
        set("max_neili", 9000);
        set("jiali", 200);
        set("combat_exp", 6400000);
        set_skill("force", 400);
        set_skill("xiaowuxiang", 400);
        set_skill("dodge", 400);
        set_skill("shenkong-xing", 400);
        set_skill("unarmed", 420);
        set_skill("yujiamu-quan", 400);
        set_skill("parry", 400);
        set_skill("sword", 400);
        set_skill("mingwang-jian", 400);
        set_skill("mizong-xinfa", 400);
        set_skill("literate", 400);
        set_skill("staff", 400);
        set_skill("xiangmo-chu", 400 );
        set_skill("huoyan-dao", 420);


        map_skill("force", "xiaowuxiang");
        map_skill("dodge", "shenkong-xing");
        map_skill("unarmed", "huoyan-dao");
        map_skill("parry", "mingwang-jian");
        map_skill("sword", "mingwang-jian");
        map_skill("staff", "xiangmo-chu");
        create_family("雪山寺", 1, "掌门");
        set("class", "bonze");
        setup();
//        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/xueshan/obj/r-jiasha")->wear();
        carry_object("/d/xueshan/obj/sengmao")->wear();
        add_money("gold",1);
}
void attempt_apprentice(object ob)
{
          if ((string)ob->query("gender") != "男性") {
                     command("say 修习密宗内功需要纯阳之体。");
                command("say 这位" + RANK_D->query_respect(ob) +
                        "还是请回吧！");
                return;
          }
          if ((string)ob->query("class") != "bonze") {
                     command("say 我佛门的清规戒律甚多。");
                command("say 这位" + RANK_D->query_respect(ob) +
                        "还是请回吧！");
                return;
          }
        if ((string)ob->query("family/family_name") != "雪山寺")        {
                command("say 这位" + RANK_D->query_respect(ob) +
                        "既非本寺弟子，还是请回吧！");
                return;
          }
        if ((int)ob->query_skill("mizong-xinfa", 1) < 100) {
                command("say 入我雪山寺，修习密宗心法是首要的。");
                command("say 这位" + RANK_D->query_respect(ob) +
                        "是否还应该多多钻研本门的心法？");
                return;
        }
//        command("chat 哈哈哈哈！！！！！");
//        command("chat 我雪山寺真是后继有人，真是可喜可贺。");
//        command("chat 哈哈哈哈！！！！！");
        command("recruit " + ob->query("id"));
    ob->set("title",HIY"法王"NOR);
}
