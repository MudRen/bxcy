// tuoboseng.c
// Date: YZC 96/01/19
inherit NPC;
void create()
{
    set_name("托钵僧", ({"tuobo seng","seng"}));
    set("long",
        "他是一位未通世故的青年和尚，脸上挂着孩儿般的微笑。\n"
    );
    set("gender", "男性");
    set("attitude", "heroism");
    set("class", "bonze");
    set("age", 20);
    
    set("str", 15);
    set("int", 30);
    set("con", 30);
    set("dex", 18);
set("no_get",1);
    set("max_qi", 280);
    set("max_jing", 300);
    set("neili", 380);
    set("max_neili", 380);
    set("jiali", 27);
    set("combat_exp", 10000);
    
    set("chat_chance", 30);
    set("chat_msg", ({
        "托钵僧说道: 请这位施主化几两银子给贫僧，积点阴德，造福众生。\n",
        (: random_move :)
    }) );
    set_skill("force", 41);
    set_skill("unarmed", 41);
    set_skill("dodge", 41);
    set_skill("parry", 41);
    set_skill("shaolin-shenfa", 42);
    set_skill("jingang-quan", 41);
    set_skill("hunyuan-yiqi", 41);
    map_skill("force", "hunyuan-yiqi");
    map_skill("dodge", "shaolin-shenfa");
    create_family("少林派",32, "弟子");
    map_skill("unarmed", "jingang-quan");
    map_skill("parry", "jingang-quan");
    setup();
    carry_object("/clone/misc/seng_cloth")->wear();
    setup();
}
int accept_object(object me, object ob)
{
    object ling;
    
    command("smile");
    command("say 阿弭陀佛，多谢这位" + RANK_D->query_respect(me) + " ！");
    if( ob->query("money_id") && me->query("class") != "bonze" ) 
    {
        if(ob->value() < 5000)
        {
            command("say 鉴于近日英雄令较为紧俏，现进行第一次涨价。价格吗...");
            command("say 这位施主给的未免少了点。");
            return 1;
        }
        else
        {
            command("say " + RANK_D->query_respect(me) + 
            "如此乐善好施，兼又身怀绝艺，本寺方丈正欲一晤天下英雄，不知可愿赴少林寺内一游？");
            ling=new("/d/shaolin/obj/tie-ling");
            ling->move(me);
            message_vision("托钵僧给$N一块铁铸令牌。\n", me);
            command("say 此牌限时一日，逾时失效，请于限时前离寺，否则多有不便，切记切记！"); 
            return 1;
        }
    }
    return 1;
}
