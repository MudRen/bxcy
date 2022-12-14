// jingjia.c 静迦
// create by host dec,11
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

string ask_for_join();
string ask_for_join();

void create()
{
        set_name("静迦", ({ "jing jia","jing","jia"}));
        set("long",
           "她是一位中年出家道姑，道冠高拢，慈眉善目。\n");
        set("gender", "女性");
        set("age", 35);
        set("attitude", "friendly");
        set("shen_type", 1);
        set("str", 26);
        set("int", 23);
        set("con", 26);
        set("dex", 22);

        set("qi", 1000);
        set("max_qi", 1000);
        set("jing", 800);
        set("max_jing", 800);
        set("neili", 800);
        set("max_neili", 800);
        set("jiali", 30);

        set("combat_exp", 1550000);
        set("score", 70000);

        set_skill("force", 175);
        set_skill("dodge", 165);
        set_skill("parry", 180);
        set_skill("unarmed", 185);
        set_skill("linji-zhuang",180);
        set_skill("zhutian-bu",170);
        set_skill("jinding-zhang",185);
        set_skill("yugalism",180);
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
#include "/kungfu/class/emei/jing.h"