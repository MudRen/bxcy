// jingzhen.c 静真
// create by host dec,11
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("静真", ({ "jing zhen","jing","zhen"}));
        set("long",
          "她是一位中年出家道姑，身穿道袍，正端坐在蒲团上，眉目之间有一股祥和之气。\n");
        set("gender", "女性");
        set("age", 33);
        set("attitude", "friendly");
        set("shen_type", 1);
        set("str", 24);
        set("int", 22);
        set("con", 23);
        set("dex", 21);

        set("qi", 800);
        set("max_qi", 800);
        set("jing", 900);
        set("max_jing", 900);
        set("neili", 600);
        set("max_neili", 600);
        set("jiali", 10);

        set("combat_exp", 800000);
        set("score", 70000);

        set_skill("force", 165);
        set_skill("dodge", 165);
        set_skill("parry", 170);
        set_skill("blade", 185);
        set_skill("yanxing-dao",185);
        set_skill("zhutian-bu",165);
        set_skill("literate", 180);
        set_skill("linji-zhuang",165);
        map_skill("dodge","zhutian-bu");
        map_skill("parry", "yanxing-dao");
        map_skill("blade", "yanxing-dao");
        map_skill("force","linji-zhuang");

        create_family("峨嵋派", 4,"弟子");
        set("class","bonze");
        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/gangdao")->wield();
  }
#include "/kungfu/class/emei/jing.h"