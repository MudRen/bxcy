// bye mei
inherit NPC;
int hai_tu();
void create()
{
        set_name("丁三", ({ "ding san", "ding", "waiter" }) );
        set("gender", "男性" );
        set("age", 22);
        set("long",
                "这位丁三正笑咪咪地忙著，地位虽然不高，但是别人叫他丁三，他还是没有不高兴。\n");
        set("combat_exp", 100);
        set("inquiry", ([
          "马车"  : (: hai_tu :),
        "回扬州"  : (: hai_tu :),
        ]) );
        set("attitude", "friendly");
        set("rank_info/respect", "小二哥");
        setup();
        carry_object("/clone/misc/cloth")->wear();
}
void init()
{       
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        if( this_player()->query_temp("dalikill") )
        {
                 kill_ob(ob);
        }
        add_action("do_kill","kill");
}
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(2) ) {
                case 0:
                        say( "丁三笑咪咪地说道：这位" + RANK_D->query_respect(ob)
                                + "，进来喝杯茶，润都哈喉咙。\n");
                        break;
                case 1:
                        say( "丁三用脖子上的毛巾抹了抹手，说道：这位" + RANK_D->query_respect(ob)
                                + "，欢迎光临，本店服务热情周到。\n");
                        break;
        }
}
int hai_tu()
{
     object who;
     who = this_player();
          message_vision("丁三上上下下打量了$N一下：想坐马车回扬州，可以。\n"
                         "不过掌柜的吩咐下来了，十两银子，嘿嘿！\n",who);
          who->set_temp("tmark/马", 1);
      return 1;
}
int accept_object(object who, object ob)
{        
        if ( who->query_temp("tmark/马") ) {
        if (ob->query("money_id") && ob->value() >= 1000) {
                tell_object(who, "丁三一哈腰，说道：多谢您老，客官请到后院。\n");
                who->move("/d/dali/houyuan.c");
                who->delete_temp("tmark/马");
                return 1;

                } else { 
                  message_vision("丁三不耐烦地对$N说：小的都说了要十两银子的了，客官没听清楚吗？\n", who);
                return 0;
                }
        }
        if (ob->query("money_id") && ob->value() >= 500) {
                tell_object(who, "丁三一哈腰，说道：多谢您老，客官请上楼歇息。\n");
                who->set_temp("rent_paid",1);
                return 1;
        }
        return 0;
}

int do_kill(string arg)
{
        this_player()->set_temp("dalikill", 1);
        return 0;
}