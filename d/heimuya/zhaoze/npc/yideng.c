//yideng.c
inherit NPC;
inherit F_MASTER;
void checking(object me,object ob);
void create()
{
    set_name("一灯", ({"yideng dashi", "yideng", "dashi"}));
    set("nickname", HIY "南帝" NOR );
    set("gender", "男性");
    set("age", 42);
    set("long", 
        "他面目慈祥，两道长长的白眉从眼角垂了下来。\n"
        "眉间虽隐含愁苦，但却有一番雍容高华的神色。\n");
    set("attitude", "peaceful");
    set("per",32);
    set("class", "bonze");
    set("str", 71);
    set("int", 80);
    set("con", 86);
    set("dex", 240);
    set("chat_chance", 1);
    set("chat_msg", ({
        "一灯大师低头沉思，悠然不语。\n",
    }));
    set("inquiry", ([
    "老顽童周伯通" : (: command("sigh"),command("buddhi") :),
          "老顽童" : (: command("sigh"),command("buddhi") :),
          "周伯通" : (: command("sigh"),command("buddhi") :),
            "瑛姑" : (: command("buddhi") :),
    ]));
    set("qi", 5000);
    set("max_qi", 5000);
    set("jing", 5000);
    set("max_jing", 5000);
    set("max_jingli", 3000);

    set("jingli", 3000);
    set("neili", 13500000);
    set("max_neili", 13500);
    set("jiali", 300);
    
    set("combat_exp", 337500000);
     
    set_skill("force", 500);             // 基本内功
    set_skill("kumu-shengong", 500);
    set_skill("shaolin-shenfa", 1500);
    set_skill("yiyang-zhi", 500);
    set_skill("unarmed", 500);           // 基本拳脚
    set_skill("dodge", 1500);             // 基本躲闪
    set_skill("parry", 500);             // 基本招架
    set_skill("sword", 500);             // 基本剑法
    set_skill("literate",550);           // 读书识字
set_skill("duanjia-sword",850);          
set_skill("sword",1100);          
    
    map_skill("force"  , "kumu-shengong");
    map_skill("unarmed", "yiyang-zhi");
    map_skill("dodge"  , "shaolin-shenfa");
map_skill("sword"  , "duanjia-sword");	
    map_skill("parry"  , "yiyang-zhi");
    
    create_family("大理段家",17,"国王");
set("chat_chance_combat", 300);	
set("chat_msg_combat", ({	
(: perform_action, "sword.ailao" :),	
(: perform_action, "sword.fenglei" :),	
(: perform_action, "sword.jingtian" :),	
(: perform_action, "unarmed.sandie" :),	
}) );	
    setup();
carry_object("/clone/weapon/changjian")->wield();    	
    carry_object(__DIR__"obj/sengpao")->wear();    
}
void init()
{
    object me;
    ::init();
    me=this_player();
    if (me->query_temp("kill_shi")){
          command("buddhi");
          message_vision("$N看了看$n，摇了摇头，叹道：这位" + RANK_D->query_respect(me) + "，你的杀性太重了，还是请回吧！\n",this_object(),me);
          me->delete_temp("tmark/绢");
          me->delete_temp("kill_shi");
    }
}

void attempt_apprentice(object ob)
{       
        if ((int)ob->query("class", "officer")) {
        if ((int)ob->query_skill("kumu-shengong",1) < 250 ) {
           command("say 你的本门内功心法太低了,还是努努力先提高一下吧!");
        return;
        } else { 
                command("nod");
                command("say " + RANK_D->query_respect(ob) + "日后必成大器 ！\n");
                command("recruit " + ob->query("id") );
               }
        } else  command("say 老衲已是出家之人，不再收徒的了！");
}

int accept_object(object me, object ob)
{
    if (me->query_temp("tmark/绢")){
        if ( (string) ob->query("id") =="hong juan" ) {
          message_vision("$N对$n说道：该来的还是来了，这事我们还是作个了结吧！\n", this_object(),me);
          message_vision("$N对$n说道：施主之恩，老衲无以为报。施主如有空暇，可去天龙寺找本因指点指点！\n", this_object(),me);
          remove_call_out("checking");
          call_out("checking", 1, this_object(),me);
          return 1;
            }
        } else return 0;
}

void checking(object me, object ob)
{
        if (!ob || !present(ob, environment()) ) return; 
        me->set("eff_qi",me->query("max_qi"));
        me->set("qi",me->query("max_qi"));
        me->set("eff_jing",me->query("max_jing"));
        me->set("jing",me->query("max_jing"));
me->set("neili",13500000);	

        ob->fight_ob(me);
        me->fight_ob(ob);
        remove_call_out("do_checking");
        call_out("do_checking", 1, me,ob);
}
void do_checking(object me,object ob)
{
        int my_qi, his_qi;
        if (!me || !ob || !present(ob,environment()) )
             return;
        if (me->is_fighting(ob) && ob->is_fighting(me)){
            remove_call_out("do_checking");
            call_out("do_checking", 1, me,ob);
            return;
        }

        if (!living(me)){
            me->revive();
            my_qi=0;
        }else
            my_qi  = (int)me->query("qi")*100/(int)me->query("max_qi");
        his_qi = (int)ob->query("qi")*100/(int)ob->query("max_qi");

        if (his_qi > my_qi) 
        {
                say(CYN+"一灯说道：施主身手果然不凡，老衲佩服。老衲终于可以了却尘缘了。\n"+NOR);
                ob->set_temp("tmark/绢1", 1);
ob->set_temp("tmark/收", 1);
                return;
        }else{
                say(CYN+"一灯双手合十道：尘缘一切自心起，施主请回吧。\n"+NOR);
                message_vision("$N对一灯大师恭恭敬敬地磕了一个头。\n", ob);
                me->delete_temp("tmark/绢");
        }
}

void die()
{
        object killer;
        if( objectp(killer = query_temp("last_damage_from")) ){
              say(CYN+"一灯说道：南无阿弭佗佛！ 善哉！善哉！老衲终于可以了却尘缘了。\n"+NOR);
              killer->delete_temp("tmark");
         }
        ::die();
}

