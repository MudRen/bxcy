// Npc: /kungfu/class/shaolin/dao-cheng.c
// Date: YZC 96/01/19
inherit NPC;
inherit F_MASTER;
void create()
{
    set_name("道成禅师", ({
        "daocheng chanshi",
        "daocheng",
        "chanshi",
    }));
    set("long",
        "他是一位身材高大的中年僧人，两臂粗壮，膀阔腰圆。他手持兵\n"
        "刃，身穿一袭灰布镶边袈裟，似乎有一身武艺。\n"
    );
    set("gender", "男性");
    set("attitude", "friendly");
    set("class", "bonze");
    set("age", 40);
    set("str", 21);
    set("int", 20);
    set("con", 19);
    set("dex", 24);
    set("max_qi", 400);
    set("max_jing", 300);
    set("neili", 450);
    set("max_neili", 450);
    set("jiali", 40);
    set("combat_exp", 52000);
    set_skill("force", 80);
    set_skill("hunyuan-yiqi", 80);
    set_skill("dodge", 80);
    set_skill("shaolin-shenfa", 80);
    set_skill("unarmed", 80);
    set_skill("banruo-zhang", 80);
    set_skill("unarmed", 82);
    set_skill("longzhua-gong", 82);
    set_skill("parry", 80);
    set_skill("buddhism", 80);
    set_skill("literate", 80);
    map_skill("force", "hunyuan-yiqi");
    map_skill("dodge", "shaolin-shenfa");
    map_skill("unarmed", "banruo-zhang");
    map_skill("parry", "longzhua-gong");
    create_family("少林派", 39, "弟子");
    setup();
        carry_object("/d/shaolin/obj/dao-cloth")->wear();
}
#include "/kungfu/class/shaolin/dao.h"
