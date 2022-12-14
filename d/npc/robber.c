// robber.c
#include <ansi.h>
inherit NPC;
void create()
{
        set_name("蒙面强盗", ({ "mask robber" }) );
        set("long","这是一名蒙面强盗，样子很神秘。\n");
        set("attitude", "heroism");
        set("str", 20 + random(11));            // 膂力         
        set("per", 20 + random(11));            // 容貌
        set("int", 20 + random(11));            // 悟性         
        set("con", 20 + random(11));            // 根骨
        set("dex", 100 + random(11));            // 身法         
        set("kar", 20 + random(11));            // 福缘
        set("chat_chance_combat", 15);
        set("chat_msg_combat", ({
                BOLD "蒙面强盗喝道：呔！此路是我开，此树是我栽，要想从此过，留下镖银来！\n" NOR,
                CYN "蒙面强盗喝道：快快放下东西，留你一条生路！\n" NOR,
                CYN "蒙面强盗喝道：老子看你是要钱还是要命！\n"NOR ,
                BOLD "蒙面强盗喝道：钱也要，命也要！\n"NOR,
        }) );
        set("neili", 500);
        set("max_neili", 500);
        set("jiali", 10);
        set("shen", -10);
     set("demogorgon",1);
        set("no_suck",1);
        set_temp("apply/attack", 40);
        set_temp("apply/defense", 40);
        set_temp("apply/damage", 40);
        set_temp("apply/armor", 40);
        set_temp("apply/dodge", 40);
        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/d/city/npc/obj/gangdao")->wield();
        add_money("silver", 20);
}
void init()
{       
    object me,ob;
    int n;
    me=this_object();
    ob=this_player();
    ::init();
    if (present("biao yin",ob)){
        if (!me->is_killing(ob)){
                command("say "+ob->name()+"，把镖银留下，放你走路！！\n");
                set_leader(ob);
                command("kill "+ob->query("id") );
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
                    set_skill("blade", n ); 
                n = ob->query_skill("parry", 1) + random(10) - 7;
                if( n <= 0 ) n = random(3) + 1;
                    set_skill("parry", n );
                n = ob->query_skill("dodge", 1) + random(10) - 7;
                if( n <= 0 ) n = random(3) + 1;
                    set_skill("dodge", n );
                n = ob->query_skill(ob->query_skill_mapped("force"), 1) + random(10) - 7;
                if( n <= 0 ) n = random(3) + 1;
                    set_skill("taiji-shengong", n );
                n = ob->query_skill(ob->query_skill_mapped("force"), 1) + random(10) - 7;
                if( n <= 0 ) n = random(3) + 1;
                    set_skill("taiji-dao", n );
                n = ob->query_skill(ob->query_skill_mapped("dodge"), 1) + random(10) - 7;
                if( n <= 0 ) n = random(3) + 1;
                    set_skill("tiyunzong", n );
                map_skill("dodge", "tiyunzong");
                map_skill("force", "taiji-shengong");
                map_skill("blade", "taiji-dao");
                map_skill("parry", "taiji-dao");
        }
    }else   if (me->is_killing(ob) ){
            me->remove_killer(ob);
            me->set_leader(0);
    }
    if (living(ob))
   add_action("do_go","go");
}

int do_go(string arg)
{
	mapping exit;
	if (!environment()) return 1;
	if( !mapp(exit = environment()->query("exits")) || undefinedp(exit[arg]) )
		return 0;
	if (is_killing(this_player()))
		if (random(10)>8) {
			message_vision(YEL "$N见势不好，转身要走，被$n一把拦在面前。想走？先放下镖银！\n"NOR, this_player(), this_object());
			return 1;
	}
	return 0;
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
       if (!environment()) return;
        message("vision",HIB + name() + "急急忙忙地走开了。\n" NOR, environment(), this_object() );
        destruct(this_object());
}
