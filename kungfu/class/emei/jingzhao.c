// jingzhao.c 静照
// create by host dec,11
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

string ask_for_join();
string ask_for_join();

void create()
{
        set_name("静照", ({ "jing zhao","jing","zhao"}));
        set("long",
           "她是一位中年出家道姑，道冠高拢，慈眉善目。\n");
        set("gender", "女性");
        set("age", 40);
        set("attitude", "friendly");
        set("shen_type", 1);
        set("str", 24);
        set("int", 24);
        set("con", 24);
        set("dex", 24);

        set("qi", 1000);
        set("max_qi", 1000);
        set("jing", 800);
        set("max_jing", 800);
        set("neili", 800);
        set("max_neili", 800);
        set("jiali", 30);

        set("combat_exp", 850000);
        set("score", 70000);

        set_skill("force", 170);
        set_skill("dodge", 170);
        set_skill("parry", 170);
        set_skill("sword", 185);
        set_skill("linji-zhuang",175);
        set_skill("zhutian-bu",175);
        set_skill("huifeng-jian",185);
        set_skill("literate", 180);
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
#include "/kungfu/class/emei/jing.h"