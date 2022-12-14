// robber.c

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("蒙面强盗", ({ "mask robber", "robber" }) );
        set("long","这是一名蒙面强盗，样子很神秘。\n");

        set("attitude", "heroism");

        set("str", 20 + random(11));            // 膂力         
        set("per", 20 + random(11));            // 容貌
        set("int", 20 + random(11));            // 悟性         
        set("con", 20 + random(11));            // 根骨
        set("dex", 20 + random(11));            // 身法         
        set("kar", 20 + random(11));            // 福缘

        set("chat_chance_combat", 15);
        set("chat_msg_combat", ({
                "蒙面强盗喝道：呔！此路是我开，此树是我栽，要想从此过，留下买路钱！\n",
                "蒙面强盗喝道：快快放下东西，留你一条生路！\n",
                "蒙面强盗喝道：老子看你是要钱还是要命！\n"
                "蒙面强盗喝道：钱也要，命也要！\n"
        }) );

        set("neili", 500);      set("max_neili", 500);          set("jiali", 10);
        set("shen", -10);

        set_temp("apply/attack", 40);
        set_temp("apply/defense", 40);
        set_temp("apply/damage", 40);
        set_temp("apply/armor", 40);
        set_temp("apply/move", 40);

        setup();

        carry_object("/obj/cloth/cloth")->wear();
        carry_object("/obj/weapon/blade")->wield();

        add_money("gold", 3);
}

void init()
{       
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("checking");
                call_out("checking", 0, ob);
        }
}

void checking(object ob)
{
        int n;

        if( !ob || !present(ob, environment(this_object())) || !present("mi han", ob) ) {
                if(ob == query_leader() )  set_leader(0);
                return;
        }

        // 自动生成武功参数

        n = ob->query("combat_exp") + random(10000) - 7000;
        if( n <= 0 ) n = random(3000) + 1;
        set("combat_exp", n );

        n = ob->query_skill("force", 1) + random(10) - 7;
        if( n <= 0 ) n = random(3) + 1;
        set_skill("force", n );
        n = ob->query_skill("unarmed", 1) + random(10) - 7;
        if( n <= 0 ) n = random(3) + 1;
        set_skill("unarmed", n );
        n = ob->query_skill("force", 1) + random(10) - 7;
        if( n <= 0 ) n = random(3) + 1;
        set_skill("blade", n );                 // 本来的做法是取兵器中最强的一项，为了简单，这里用force取代
        n = ob->query_skill("parry", 1) + random(10) - 7;
        if( n <= 0 ) n = random(3) + 1;
        set_skill("parry", n );
        n = ob->query_skill("dodge", 1) + random(10) - 7;
        if( n <= 0 ) n = random(3) + 1;
        set_skill("dodge", n );

        n = ob->query_skill(ob->query_skill_mapped("force"), 1) + random(10) - 7;
        if( n <= 0 ) n = random(3) + 1;
        set_skill("hunyuan-force", n );
        n = ob->query_skill(ob->query_skill_mapped("force"), 1) + random(10) - 7;
        if( n <= 0 ) n = random(3) + 1;
        set_skill("ruyi-blade", n );
        n = ob->query_skill(ob->query_skill_mapped("dodge"), 1) + random(10) - 7;
        if( n <= 0 ) n = random(3) + 1;
        set_skill("taxue-steps", n );

        map_skill("dodge", "taxue-steps");
        map_skill("force", "hunyuan-force");
        map_skill("blade", "ruyi-blade");
        map_skill("parry", "ruyi-blade");

        command("say "+ob->name()+"，把密函留下，放你走路！！\n");
        set_leader(ob);

        command("kill "+ob->query("id") );
}

int heal_up()
{
        if( environment() && !is_fighting() ) {
                call_out("leave", 1);
                return 1;
        }
        return ::heal_up() + 1;
}

void leave()
{
        message("vision",HIB + name() + "急急忙忙地走开了。\n" NOR, environment(), this_object() );
        destruct(this_object());
}
