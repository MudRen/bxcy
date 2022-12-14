// Npc: /kungfu/class/shaolin/hui-xin.c

inherit NPC;
inherit F_MASTER;
string ask_me();
void create()
{
    set_name("慧心尊者", ({
        "huixin zunzhe",
        "huixin",
        "zunzhe",
    }));
    set("long",
        "他是一位两鬓斑白的老僧，身穿一袭青布镶边袈裟。他身材略高，\n"
        "太阳穴高高凸起，双目炯炯有神。\n"
    );
    set("gender", "男性");
    set("attitude", "friendly");
    set("class", "bonze");
    set("age", 50);
set("no_get",1);
    set("str", 20);
    set("int", 20);
    set("con", 20);
    set("dex", 20);
    set("max_qi", 10000);
    set("max_jing", 3000);
    set("neili", 600000);
    set("max_neili", 600000);
    set("jiali", 50);
    set("combat_exp", 1000000);
    set("shen", 10000);
    set_skill("force", 100);
    set_skill("hunyuan-yiqi", 100);
    set_skill("dodge", 100);
    set_skill("shaolin-shenfa", 100);
    set_skill("unarmed", 108);
    set_skill("nianhua-zhi", 108);
    set_skill("parry", 100);
    set_skill("buddhism", 100);
    set_skill("literate", 100);
    map_skill("force", "hunyuan-yiqi");
    map_skill("dodge", "shaolin-shenfa");
    map_skill("unarmed", "nianhua-zhi");
    map_skill("parry", "nianhua-zhi");
    
    create_family("少林派", 38, "弟子");
       setup();

        carry_object("/d/shaolin/obj/hui-cloth")->wear();
}
#include "/kungfu/class/shaolin/hui.h"
