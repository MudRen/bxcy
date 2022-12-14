// jingxian.c 静闲
// create by host dec,11
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("静闲", ({ "jing xian","jing","xian"}));
        set("long",
           "她是一位中年出家道姑，身穿道袍，正端坐在蒲团上，眉目之间有一股祥和之气。\n");
        set("gender", "女性");
        set("age", 37);
        set("attitude", "friendly");
        set("shen_type", 1);
        set("str", 21);
        set("int", 25);
        set("con", 20);
        set("dex", 25);

        set("qi", 800);
        set("max_qi", 800);
        set("jing", 900);
        set("max_jing", 900);
        set("neili", 600);
        set("max_neili", 600);
        set("jiali", 10);

        set("combat_exp", 900000);
        set("score", 70000);

        set_skill("force", 165);
        set_skill("dodge", 175);
        set_skill("parry", 170);
        set_skill("unarmed", 185);
        set_skill("tiangang-zhi",185);
        set_skill("zhutian-bu",175);
        set_skill("literate", 180);
        set_skill("linji-zhuang",165);
        map_skill("dodge","zhutian-bu");
        map_skill("parry", "tiangang-zhi");
        map_skill("unarmed", "tiangang-zhi");
        map_skill("force","linji-zhuang");
        prepare_skill("unarmed", "tiangang-zhi");

        create_family("峨嵋派", 4,"弟子");
        set("class","bonze");
        setup();
        carry_object("/clone/misc/cloth")->wear();
    }
#include "/kungfu/class/emei/jing.h"