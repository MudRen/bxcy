// fonghuang.c
inherit NPC;
inherit F_DEALER;
int ask_dao();
void create()
{
        set_name(MAG "蓝凤凰" NOR, ({"lan fonghuang", "lan", "fonghuang" }));
        set("title", CYN "五毒教主" NOR);
        set("shen_type", 5);
        set("gender", "女性");
        set("per",28);
        set("long",
                "她就是人称五毒教主的蓝凤凰。\n");
        set("age", 22);
        set("attitude", "friendly");
        set("inquiry", ([
                "任盈盈" : "那是我教的圣姑。\n",
                "令狐冲" : "嘻嘻，那是我教圣姑的心上人！",
                  "圣使" : (: ask_dao :),
              "波斯圣使" : (: ask_dao :),
        ]));
        set("neili", 200);
        set("max_neili", 100);
        set("jiali", 10);
        set("shen", 0);
        set("combat_exp", 12500);
        set("shen_type", 1);
        set("attitude", "friendly");
        set("env/wimpy", 50);

        set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_skill("force", 100);

        set_temp("apply/attack", 100);
        set_temp("apply/defense", 100);
        set_temp("apply/damage", 40);

        set("chat_chance", 3);
        set("chat_msg", ({
        "蓝凤凰自言自语地说到：不知那些波斯圣使走了没有，唉！\n",
        "蓝凤凰自言自语地说到：圣姑现在都不知怎么了，唉！\n",
        }) );

        setup();
         carry_object("/clone/misc/hiw_cloth")->wear();
}

void init()
{
    object me;
    me = this_player();
    if ( present("card4",me) )
    if (userp(me)){
        message_vision("蓝凤凰吓得连忙跪下，对$N高呼: 不知圣使驾到，有失迎迓！\n",me);
        return;
    }  
}

int accept_object(object who, object ob)
{
        if ( (string) ob->query("id") =="card4" ) {
                message_vision("蓝凤凰拿起令牌看了看，对$N说到：不知圣使有何吩咐！\n"+
                               "说完后将令牌还给$N。\n", who);
                new("/d/heimuya/npc/obj/card4")->move(who); 
                who->set_temp("tmark/令", 1);       
                return 1;
        }
       return 0;   
}

int ask_dao()
{
      if ((int)this_player()->query_temp("tmark/令")) {
           command("whisper " +this_player()->query("id")+ " 你把令牌给海边的老船夫吧！\n");
           this_player()->set_temp("tmark/令", 0);
           this_player()->set_temp("tmark/令1", 1);
           return 1;
           }
       return 0;   
}

