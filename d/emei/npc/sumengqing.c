// sumengqing.c 苏梦清
// create by host dec,16 1997

#include <ansi.h>
inherit NPC;

void create()
{
        set_name("苏梦清", ({ "su mengqing", "su", "mengqing"}));
        set("long",
      "她是一位面容清瘦，身材娇小的女子，但却善使一门刀法。\n");
        set("gender", "女性");
        set("age", 28);
        set("attitude", "friendly");
        set("shen_type", 1);
        set("str", 23);
        set("int", 21);
        set("con", 22);
        set("dex", 20);

        set("qi", 500);
        set("max_qi", 500);
        set("jing", 300);
        set("max_jing", 300);
        set("neili", 400);
        set("max_neili", 400);

        set("combat_exp", 12000);
      
        set_skill("force", 40);
        set_skill("dodge", 35);
        set_skill("parry", 45);
        set_skill("blade", 50);
        set_skill("yanxing-dao",55);
        set_skill("zhutian-bu",35);
        set_skill("linji-zhuang",40);
        map_skill("dodge","zhutian-bu");
        map_skill("parry", "yanxing-dao");
        map_skill("blade", "yanxing-dao");
        map_skill("force","linji-zhuang");  
      
        create_family("峨嵋派", 5,"弟子");
        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/gangdao")->wield();
  }
#include "/kungfu/class/emei/sujia.h"