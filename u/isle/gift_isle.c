#include <ansi.h>
string ask_me();
inherit NPC;
void create()
{
        set_name(HIW"isle"NOR, ({ "isle" }));        
        set("title", YEL"天神"NOR);
        set("gender", "男性");
        set("age", 25);
        set("str", 30);
        set("per", 30);
        set("dex", 30);
        set("inquiry", ([
      "gift":(:ask_me:),
    ]) );
        set("long", "他，就是碧血残阳的巫师之一，为人性格怪癖，你最好不要惹他。\n");
        set("combat_exp", 900000000);
        set("attitude", "peaceful");
        set_skill("unarmed", 30000);
        set_skill("force", 30000);
        set_skill("dodge", 30000);
        set_skill("parry", 30000);
        set_skill("taixuan-gong", 30000);
        set_skill("liumai-shenjian", 30000);
        set_skill("pixie-jian", 900);
        set_temp("apply/attack", 6000);
        set_temp("apply/defense", 6000);
        set_temp("apply/armor", 6000);
        set_temp("apply/damage", 6000);
        map_skill("force", "taixuan-gong");
        map_skill("unarmed", "liumai-shenjian");
        map_skill("parry", "liumai-shenjian");
        map_skill("dodge", "pixie-jian");         
        set("qi", 2250000);
        set("max_qi", 2250000);
        set("jiali", 100000); 
        set("neili", 9000000); 
        set("max_neili", 9000000); 
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.liumai" :),
                (: perform_action, "unarmed.liumai" :),
                (: exert_function, "recover" :),
                (: exert_function, "heal" :),
            }) );        
        setup();
        carry_object("/clone/misc/cloth")->wear();
}

string ask_me()
{
    object me,ob;
    ob=this_player();  
    command("say 欢迎来到夕阳再阳,祝你在这里玩的愉快!时值五一,巫师们准备了\n");
    command("say 一份小礼物,希望对你有用，希望你支持isle的工作,谢谢。\n");
    message_vision(HIY"isle从礼品盒中拿出一颗新手丹，交了给$N !\n\n"NOR,ob);
    me=new("/u/isle/gift");
    me->move(ob);
    return "这个东东不要来领二次,恶意捣乱对任何人都没有好处。\n";
}
