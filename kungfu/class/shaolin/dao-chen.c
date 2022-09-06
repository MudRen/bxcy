// Npc: /kungfu/class/shaolin/dao-chen.c
// Date: YZC 96/01/19
inherit NPC;
string ask_me(string name);
void create()
{
    set_name("道尘禅师", ({
        "daochen chanshi",
        "daochen",
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
        set("str", 20);
    set("int", 20);
    set("con", 20);
    set("dex", 20);
    set("max_qi", 400);
    set("max_jing", 300);
    set("neili", 450);
    set("max_neili", 450);
    set("jiali", 40);
    set("combat_exp", 52000);
    set("score", 100);
    set_skill("force", 80);
    set_skill("hunyuan-yiqi", 80);
    set_skill("dodge", 80);
    set_skill("shaolin-shenfa", 80);
    set_skill("unarmed", 80);
    set_skill("banruo-zhang", 80);
    set_skill("parry", 80);
    set_skill("damo-jian", 80);
    set_skill("buddhism", 80);
    set_skill("literate", 80);
    map_skill("force", "hunyuan-yiqi");
    map_skill("dodge", "shaolin-shenfa");
    map_skill("unarmed", "banruo-zhang");
    map_skill("parry", "damo-jian");
    
    create_family("少林派", 39, "弟子");
        set("inquiry", ([
        "齐眉棍" : (: ask_me, "qimeigun" :),
        "戒刀" :   (: ask_me, "jiedao" :),
        "禅杖" :   (: ask_me, "chanzhang" :),
        "长剑" :   (: ask_me, "changjian" :),
        "皮鞭" :   (: ask_me, "changbian" :),
        ]));
    setup();
        carry_object("/d/shaolin/obj/dao-cloth")->wear();
}
string ask_me(string name)
{
    mapping fam; 
    object ob;
    
    if (!(fam = this_player()->query("family")) || fam["family_name"] != "少林派")
        return RANK_D->query_respect(this_player()) + 
        "与本派素无来往，不知此话从何谈起？";
    if (time()-this_player()->query_temp("道尘/"+name)<100)
        return RANK_D->query_respect(this_player()) + 
        "你不是刚拿过了吗？怎麽又来要了？ 真是贪得无餍！";
    ob = new("/d/shaolin/obj/" + name);
    ob->move(this_player());
    this_player()->set_temp("道尘/"+name,time());
    message_vision("道尘给$N一件" + ob->query("name") + "。\n", this_player());
    return "拿去吧。不过要记住，武器只可防身练武，不可凭此杀害生灵。";
}
