// dongfang.c
// by mei
#include <ansi.h>
inherit NPC;
void reset();
int do_answer(string str);
void do_dest(object ob);
void do_give(object ob);
void create()
{
    set_name("东方不败", ({"dongfang bubai", "dongfang"}));
    set("nickname", HIY "日月神教教主" NOR );
    set("gender", "无性");
    set("age", 46);
    set("shen",-4000);
    set("long",
        "她就是日月神教教主。号称无人可敌，因此有一称号为「东方不败」。\n");
    set("attitude", "peaceful");
    set("str", 31);
    set("int", 80);
    set("con", 86);
    set("dex", 100);
    set("per",44);
    set("no_magic",1);
    set("chat_chance", 1);
    set("chat_msg", ({
        "东方不败叹了口气道：“唉 …… 那任我行难道逃了出来吗?\n",
        }));
    set("inquiry", ([
        "葵花宝典" : "如果你能帮我取得葵花宝典上册，我一定重重谢你。\n",
              "线" : "就是柔丝索嘛，SIGH，笨蛋！\n",
    ]));
    set("qi", 10000);
    set("max_qi", 10000);
    set("jing", 5000);
    set("max_jing", 5000);
    set("jingli", 10000);
    set("max_jingli", 10000);
    set("neili", 10000000);
    set("max_neili", 20000);
    set("jiali", 800);
    set("combat_exp", 82800000);

    set_skill("force", 850);              // 基本内功
    set_skill("dodge", 850);              // 基本躲闪
    set_skill("parry", 850);              // 基本招架
    set_skill("sword", 850);              // 基本剑法
    set_skill("pixie-jian", 450);         // PiXieJian
    set_skill("literate",1000);           // 读书识字
    set_skill("kuihua-xinfa", 100);       // 葵花心法
    map_skill("force"  , "kuihua-xinfa");
    map_skill("sword", "pixie-jian");
    map_skill("dodge"  , "pixie-jian");
    map_skill("parry"  , "pixie-jian");
    set_temp("apply/shade_vision",1);
    create_family("日月神教", 2, "教主");
    set("chat_msg_combat", ({
    (: exert_function, "recover" :),
    }) );

    setup();
    carry_object(__DIR__"obj/zhen")->wield();
    carry_object("/d/quanzhou/obj/xiuhua")->wield();
    carry_object(__DIR__"obj/hongchouxiaoshan")->wear();
}
void init()
{
    ::init();
    if (this_player()->query_temp("kill yang")){
          command("say 大胆狂徒，竟敢杀我爱夫，看招!\n");
          call_out("kill_ob", 0, this_player()); 
          this_player()->fight_ob(this_object());
          COMBAT_D->do_attack(this_object(), this_player(), query_temp("weapon"));
    }else
    add_action("do_answer","answer");
}

int accept_fight(object me)
{
        if (me->query_temp("fight/东") > 1){
            this_object()->kill_ob(me);
            me->kill_ob(this_object());
            return 1;
        }else{
        command("say 哈哈！"+me->name(1)+"，你是寿星公上吊--找死！滚吧，我不跟你计较！\n不过你再在这乱逛我就杀了你。\n");
                me->add_temp("fight/东", 1);
        }                
        return 0;
}

int accept_object(object who, object ob)
{
        if ( (string) ob->query("id") =="kuihua baodian1" ) {
                message_vision("东方不败看了看$N送来的秘籍，点了点头，说道：\n"+
                               "难得你将宝典送回。你送我的东西我就收下了。\n"+
                               "不过我还差点线才能将这花绣完，你帮我找线回来。\n", who);
                who->set_temp("tmark/东", 1);
                return 1;
        }
        if ( (string) ob->query("id") =="rousisuo" ) {
             if ((int)who->query_temp("tmark/东")){
                message_vision("东方不败看了看$N送来的柔丝索，点了点头，说道：很好！这位"+RANK_D->query_respect(who)+",\n看看我绣的这花手绢上有几朵花(answer)?\n",who);
                who->set_temp("tmark/东", 2);
                call_out("do_dest",10,who);
                return 1;
             }else
                message_vision("东方不败看了看$N送来的柔丝索，点了点头，说道：谢了。\n",who);
                return 1;
        }
        return 0;
}

mixed weapon_ob(object me,object victim,int damage)
{
      object weapon;
      if (!weapon=me->query_temp("weapon"))
      {
          weapon=new("/d/heimuya/npc/obj/zhen");
          weapon->move(me);
          command("wield zhen 1");
          weapon=new("/d/heimuya/npc/obj/zhen");
          weapon->move(me);
          command("wield zhen 1");
      }
      return 0;
}
int do_answer(string str)
{
      int i,j;
      object ob=this_player();
      object me=this_object();
      if (ob->query_temp("tmark/东")!=2)  return 0;
      if (!str || !sscanf(str,"%d",i)) return notify_fail("东方不败阴笑地看着你:快答呀!\n");
      message_vision("$N颤颤惊惊地答到："+CHINESE_D->chinese_number(i)+"朵花。\n",ob);
      ob->delete_temp("tmark/东");
      j=ob->query("birthday");
      j=j%90+10;
      if (i==j){
          message_vision("$N高兴地拍了拍$n的头，对，我就想绣"+CHINESE_D->chinese_number(i)+"朵花。\n",me,ob);
          call_out("do_give",1,ob);
      }else{
          message_vision("$N的脸色微变：看来你是瞎了眼，老娘就成全你吧！\n",me);
          me->kill_ob(ob);
          ob->fight_ob(me);
      }
      return 1;
}
void do_dest(object ob)
{
      object me=this_object();
      if( !ob || !ob->query_temp("tmark/东") ) return;
      ob->delete_temp("tmark/东");
      if ( environment(ob) != environment() ) return;

      message_vision("$N的目露凶光：支支唔唔的，看来你是瞧不起我绣的花手绢！\n",this_object());
      me->kill_ob(ob);
      ob->fight_ob(me);
}
void do_give(object ob)
{
     object obj;
     if( !ob || environment(ob) != environment() ) return;
     obj=new(__DIR__"obj/kuihua2");
obj->set("owner",ob->query("id"));
     if (!obj->move(ob))
        destruct(obj);
     message_vision("$N给了$n一本"+obj->query("name")+"。\n",this_object(),ob);

                ob->add_temp("study_book", 1);
}

void reset()
{
    this_object()->remove_all_killer();
}

