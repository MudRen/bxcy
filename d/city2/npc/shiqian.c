// shiqian
#include <ansi.h>
inherit NPC;
void create()
{
        set_name("石千", ({"shi qian", "qian", "shi gonggong"}));
        set("title", "东厂总管");
        set("long",
        "他是东厂总管石千，他脸上擦满脂粉，一副很女人的样子。据说他杀起人来毫不含糊。\n"
        );
        set("gender", "无性");
        set("rank_info/respect", "公公");
        set("attitude", "heroism");
        set("class", "eunach");
        set("age", 70);
        set("str", 105);
        set("int", 120);
        set("con", 120);
        set("dex", 100);
        set("max_qi", 10000);
        set("max_jing", 10000);
        set("neili", 50000);
        set("max_neili", 20000);
        set("jiali", 300);
        set("combat_exp", 16600000);
        set("score", 5000);
        set("apply/attack",  30);
        set("apply/defense", 30);
        set_skill("force", 550);
        set_skill("unarmed", 550);
        set_skill("sword", 550);
        set_skill("dodge", 550);
        set_skill("parry", 550);
        set_skill("pixie-jian", 550);
        map_skill("dodge", "pixie-jian");
        map_skill("sword", "pixie-jian");
        map_skill("parry", "pixie-jian");
        create_family("  ", 13, "  ");
        setup();

        set("chat_chance", 15);
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/d/city/obj/jiudai");
        carry_object("/d/city2/obj/yaofen");
        add_money("silver", 50);
}
void attempt_apprentice(object ob)
{   
     
     if ((int)ob->query_skill("pixie-jian", 1) < 300) 
           {
        command("say " + RANK_D->query_respect(ob) + "以你的身手似乎......？");
        return;
       }
    command("recruit " + ob->query("id"));
        ob->set("title","一品带刀侍卫");
   }
