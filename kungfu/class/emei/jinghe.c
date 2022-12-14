// jinghe.c 静和
// create by host dec,11
#include <ansi.h>
inherit NPC;

string ask_for_join();
string ask_for_join();

void create()
{
        set_name("静和", ({ "jing he","jing","he"}));
        set("long",
            "她是一位中年出家道姑，道冠高拢，慈眉善目。\n");
        set("gender", "女性");
        set("age", 31);
        set("attitude", "friendly");
        set("shen_type", 1);
        set("str", 26);
        set("int", 22);
        set("con", 26);
        set("dex", 22);

        set("qi", 1000);
        set("max_qi", 1000);
        set("jing", 800);
        set("max_jing", 800);
        set("neili", 800);
        set("max_neili", 800);
        set("jiali", 30);

        set("combat_exp", 3000000);
        set("score", 70000);

        set_skill("force", 175);
        set_skill("dodge", 175);
        set_skill("parry", 180);
        set_skill("blade", 185);
        set_skill("linji-zhuang",180);
        set_skill("zhutian-bu",180);
        set_skill("yanxing-dao",190);
        set_skill("literate", 180);
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
