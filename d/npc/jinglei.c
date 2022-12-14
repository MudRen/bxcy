// jinglei.c 惊雷

inherit NPC;


void create()
{
        set_name(HIR"惊雷"NOR, ({ "jing lei", "jinglei", "lei" }));        
        set("title", YEL"四大名捕之四"NOR"「"RED"雷"NOR"」");
        set("gender", "男性");
        set("age", 20);
        set("str", 30);
        set("per", 30);
        set("dex", 30);
        set("long", "他，就是闻名天下的四大名捕中最小的一个，虽然脾气火爆，但是为人豪爽重义，
交游广阔，再加上一身深不可测的武功，所以年纪轻轻，却已经名满天下了。\n");
set("combat_exp", 500000000);           	
        set("attitude", "peaceful");

        set_skill("unarmed", 320);
set_skill("force", 800);	
set_skill("unarmed", 1320);	
set_skill("qufeng", 1350);     	
set_skill("qimen-wuxing", 1350);     	
        set_skill("sword", 320);
set_skill("dodge", 1500);	
set_skill("parry", 1320);	
set_skill("liumai-shenjian", 900);	
        set_skill("beiming-shengong", 320);
set_skill("lingboweibu", 1500);	
        set_temp("apply/attack", 60);
        set_temp("apply/defense", 60);
        set_temp("apply/armor", 60);
        set_temp("apply/damage", 60);


        map_skill("force", "beiming-shengong");
        map_skill("unarmed","liumai-shenjian");
        map_skill("parry", "liumai-shenjian");
        map_skill("dodge", "lingboweibu");

set("max_qi", 350000);          	
set("max_jing", 350000);	
set("neili", 13500000);                  	
set("shen_type", 0);
        set("max_neili", 15000);
set("jiali", 75000);            	


        prepare_skill("unarmed","liumai-shenjian");
set("chat_chance_combat", 100);	
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.liumai" :),
                (: exert_function, "recover" :),
                (: exert_function, "max_suck" :),
            }) ); 
       
        set("chat_chance",4);
        set("chat_msg",({
     RED"惊雷哼了一声，说道：“有四大名捕在，谁也不要杀人...谁要是杀了人给我找麻烦，就让他妈的去坐牢！”\n"NOR,
     RED"惊雷看着手中的金子，喜滋滋地说道：“刚捉了几个乱杀人的混蛋，赚了不少赏银，看来又可以去喝两盅了。”\n"NOR,
        (: random_move :)
        }));
        setup();
        carry_object("/d/city/obj/tiejia")->wear();
}

void init()
{
        object ob;
        ::init();
        if (!living(this_object())) return;
        if (interactive(ob = this_player())){
                        if ( (int)ob->query_condition("killer")) {
                    command("say "+ob->name()+"，你杀了人，还想往那逃？！");
                        remove_call_out("kill_ob");
                        call_out("kill_ob", 1, ob);
                                        return ;
                }
                if (  !ob->query_temp("armor/cloth") && ob->query("race")=="人类" 
                   && ((int)ob->query_temp("summon_time")+400)< time() ) {
                remove_call_out("summon_ob");
                call_out("summon_ob", 1, ob);
                                return;
        }
            add_action("do_kill","kill");
        }

}
void summon_ob(object ob)
{
    object room;
    if (!ob || environment(ob)!=environment())
            return;
        if (! room=find_object("/d/city/jianyu"))
            room=load_object("/d/city/jianyu");
        message_vision("\n$N一把抓住$n，光天化日，当街裸跑，有伤风化！\n\n",this_object(),ob);
        message_vision("$N拎着$n向衙门走去！\n",this_object(),ob);
        ob->move(room);
    ob->set_temp("summon_time",time());
    message("vision",YEL+"\n\n当啷一声，一个赤条条的家伙被扔了进来。\n\n"+NOR,room,({ob}));
        if (! room=find_object("/d/city/yamen"))
            room=load_object("/d/city/yamen");
        this_object()->move(room);
}

int do_kill(string arg)
{
        object ob;
      if (!environment()) return 0;
        if (ob=present(arg,environment()))
        if (userp(ob)){
            command("say 想在大爷面前撒野？找死呀！");
            kill_ob(this_player());
        }
    return 0;
}

