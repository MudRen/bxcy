// zuo.c
inherit NPC;
inherit F_MASTER;
#include <ansi.h>;
void create()
{
        set_name("左冷禅", ({ "zuo lengchan", "zuo" }) );
        set("title", HIR"五岳剑派盟主"HIY"嵩山派第十三掌门"NOR);
        set("gender", "男性");
        set("class", "swordsman");
        set("age", 55);
        set("attitude", "peaceful");
        set("str", 26);
        set("con", 30);
        set("dex", 30);
        set("int", 28);

        set("neili", 30000);
        set("max_neili", 30000);
        set("jiali", 300);
        set("max_qi",8000);
        set("max_jing",4500);
        set("combat_exp", 20000000);
        set("shen", -200000);

        set_skill("unarmed", 1000);
        set_skill("sword", 900);
        set_skill("force", 950);
        set_skill("parry", 800);
        set_skill("dodge", 1000);
        set_skill("songshan-sword", 900);
        set_skill("lingxu-bu", 850);

        map_skill("sword", "songshan-sword");
        map_skill("parry", "songshan-sword");
        map_skill("dodge", "lingxu-bu");
set("chat_chance_combat", 100);	
set("chat_msg_combat", ({	
(: perform_action, "sword.lian" :),	
}) );	

        create_family("嵩山派", 13, "掌门");
        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/cloth/cloth")->wear();
}

void attempt_apprentice(object ob)
{
if((int)ob->query_skill("songshan-sword",1) <= 299)
{
command("say 你的本门武学修为还不够，以后再来找我吧。");
return 0;
}
if (ob->query("class")!="songshandizi")
{
command("say 你和本派素无瓜葛，不知此话从何说起。");
return 0;       	
}
command("say 好吧，我就破例收下你了，以后要多为嵩山派出力啊。");
command("chat 嵩山派又多了名得力弟子，武林霸主舍我其谁。哈哈.....");
command("recruit " + ob->query("id"));
ob->set("class","songshandizi");	
}
