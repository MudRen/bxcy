// limingxia.c 李明霞
// create by host dec,16 1997

#include <ansi.h>
inherit NPC;

void create()
{
        set_name("李明霞", ({ "li mingxia", "li", "xia"}));
        set("long",
      "她是一位俗家女弟子，入门未久，武功平平。\n");
        set("gender", "女性");
        set("age", 25);
        set("attitude", "friendly");
        set("shen_type", 1);
        set("str", 19);
        set("int", 22);
        set("con", 20);
        set("dex", 22);

        set("qi", 550);
        set("max_qi", 550);
        set("jing", 350);
        set("max_jing", 350);
        set("neili", 350);
        set("max_neili", 350);

        set("combat_exp", 10000);
      
        set_skill("force", 110);
        set_skill("dodge", 105);
        set_skill("parry", 100);
        set_skill("unarmed", 90);
        set_skill("tiangang-zhi",100);
        set_skill("zhutian-bu",105);
        set_skill("linji-zhuang",105);
        map_skill("dodge","zhutian-bu");
        map_skill("parry", "tiangang-zhi");
        map_skill("unarmed", "tiangang-zhi");
        map_skill("force","linji-zhuang");  
        prepare_skill("unarmed", "tiangang-zhi");
      
        create_family("峨嵋派", 5,"弟子");
        setup();
        carry_object("/clone/misc/cloth")->wear();
  }
#include "/kungfu/class/emei/sujia.h"