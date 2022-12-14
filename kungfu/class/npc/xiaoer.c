inherit F_VENDOR_SALE;

void create()
{
       reload("xiaoer");
       set_name("店小二", ({"xiao er","xiaoer","xiao","waiter","er"}));
       set("shop_id",({"waiter","xiaoer","xiao","er"}));
       set("shop_title","店小二");
       set("gender", "男性");
       set("age", 26);
          set("max_qi", 600);
          set("eff_qi", 600);
          set("eff_jing", 600);
          set("max_jing", 600);
          set("max_neili", 1600);
          set("combat_exp", 16100);
       set("per", 14);
       set("attitude", "friendly");
       set("shen_type", 1);
       set_skill("unarmed", 10);
        set("vendor_goods", ({
                "/d/city/npc/obj/jiudai",
                "/d/city/npc/obj/jitui",
                "/d/city/npc/obj/baozi",
                "/d/city/obj/guiyu",
                "/d/city/npc/obj/hongcha",
        }) );

       setup();
       carry_object("/d/city/obj/cloth")->wear();
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_vendor_list", "list");
}

void greeting(object ob)
{
        if( !ob || !visible(ob) || environment(ob) != environment() ) return;
        switch( random(3) ) {  // 1/3 chance to greet.
                case 0:
                        say( name()+"笑咪咪地说道：这位" +
RANK_D->query_respect(ob)
                                + "，进来歇歇脚，喝两盅吧。\n");
                        break;
        }
}

/*
int accept_object(object who, object ob)
{
   if (ob->query("money_id") && ob->value() >= 300) 
   {
     tell_object(who, "小二一哈腰，说道：多谢您老，客官请上楼歇息。\n");
     return 1;
   }
   return 0;
}
*/
