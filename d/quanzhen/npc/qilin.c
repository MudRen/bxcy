// huo-chan.c

inherit NPC;

void create()
{
        set_name(HIR"火麒麟"NOR, ({ "qilin" }) );
        set("race", "野兽");
        set("age", 100);
        set("long", "一只昂首挺胸，通体金黄的麒麟。\n");
        set("attitude", "aggressive");
        set("max_qi",9000);
        set("qi",9000);
        set("jing",3000);
        set("max_jing",3000);
        set("str", 300);
        set("cor", 200);

        set("limbs", ({ "头部", "身体", "前脚", "后脚" }) );
        set("verbs", ({ "bite", "claw" }) );

               
        set("chat_msg_combat", ({
                (: this_object(), "random_move" :),
                "金麒麟突然向你喷出了一口大火！\n",
                  }) );
                
        set_temp("apply/attack", 300);
        set_temp("apply/damage", 300);
       set_temp("apply/armor", 250);

        setup();
}

void init()
{
        object ob;
        ::init();
        if (interactive(ob = this_player()) &&
                random(ob->query_kar() + ob->query_per()) < 30) {
                        remove_call_out("kill_ob");
                        call_out("kill_ob", 1, ob); 
        }       
}
void die()
{
        object ob;
        message_vision("$N惨叫一声，死了！\n", this_object());
        ob = new(__DIR__"obj/qilinjia.c");
        ob->move(environment(this_object()));
        destruct(this_object());
}

