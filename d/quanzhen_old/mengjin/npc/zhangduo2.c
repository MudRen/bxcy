// zhangduo.c 小掌舵

#include <ansi.h>

inherit NPC;

#define IN_ROOM "/d/quanzhen/mengjin/mengjin-dukou2"

void goto_matou1(object ob);
void create()
{
        set_name("小掌舵", ({ "xiao zhangduo","zhangduo" }));
        set("gender", "男性");
        set("age", 21);
        set("long",
                "这是一个船夫。饱经风霜的脸上什么也看不出来。\n",
        );
        set("combat_exp", 1000000);
        set("str",800);
        set("max_neili", 100);
        set("neili", 100);
        set("jiali", 500);
        set_skill("force", 100);
        set_skill("unarmed", 300);
        set_skill("dodge", 100);
        set_skill("parry", 100);
        setup();
        carry_object("/clone/misc/scloth")->wear();
}
int accept_object(object who, object ob)
{
        object room=environment();
        if (base_name(room)!=IN_ROOM){
                message_vision("$N对$n摇了摇头，我的渡船还在孟津渡口北岸，要想渡江，还是等我回去再说罢。\n",this_object(),who);
                return 0;
        }
        if (NATURE_D->outdoor_room()){
                message_vision("$N抬头看了看，对$n摇了摇头，现在天色已晚，这位" + RANK_D->query_respect(who) + "明天早点来吧。\n",this_object(),who);
                return 0;
        }
        if (ob->query("money_id") && ob->value() >= 4000) {
            who->set_temp("rent_paid",1);
            if (room->check_trigger()){
                    message_vision("$N对$n说：好！这位" + RANK_D->query_respect(who) + "请上船吧。\n" ,this_object(), who);
                    return 1;
            }else{
                    message_vision("$N对$n说：这位" + RANK_D->query_respect(who) + "请等等，船还在对岸呢。\n" ,this_object(), who);
                    return 0;
            }
                
        } else  
                message_vision("$N皱眉对$n说：您给的也太少了吧？\n", this_object(),who);
        return 0;
}

