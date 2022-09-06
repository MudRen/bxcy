// mei_po.c
#include <ansi.h>
inherit NPC;
string marry();
string unmarry();
string ask_huajiao();
void create()
{
        set_name("媒婆", ({ "mei_po" }) );
        set("title", "红娘");
        set("gender", "女性" );
        set("age", 43);
        set("long",
                "一位精明能干的老媒婆。\n");
        set("combat_exp", 100000);
        set("attitude", "friendly");
        set("inquiry", ([
         "做我们的主婚人好吗?": (: command("chat* ok") :),
          "结婚" : "是啊... 这里就可以缔结(marry)和解除(unmarry)婚约的。",
         "花轿" : (: ask_huajiao :), 
         "租花轿" : (: ask_huajiao :), 
        ]) );
        set_skill("literate", 100);
        set_skill("dodge", 100);
        set_skill("unarmed", 100);
        setup();
        add_money("gold", 1);
      carry_object("d/city/obj/pink_cloth")->wear();
}
void init()
{
        ::init();
        add_action("do_marry", "marry");
        add_action("do_unmarry", "unmarry");
        add_action("do_name","拜");
}
int do_marry(string arg)
{
    object obj,ob, me, old_target;
    string target;
    me = this_player();
    if ( (string)me->query("gender") == "无性")
        return notify_fail(CYN"媒婆说道：你无根无性，阴阳不调！\n"NOR);
    if (((int)me->query("age") < 18) && (me->query("gender") == "男性")
        ||((int)me->query("age") < 16) && (me->query("gender") == "女性"))
        return notify_fail(CYN"媒婆说道：你现在还年轻，以后再说吧！\n"NOR);
    if (me->is_busy())
        return notify_fail(CYN"媒婆说道：你现在正忙着呢。\n"NOR);
    if( me->is_fighting(this_object()) )
    {
        if( !this_object()->is_killing(me) )
            this_object()->kill_ob(me); 
        return notify_fail(CYN"媒婆说道：老娘送你去阴间成婚！\n"NOR); 
    }
    if( this_object()->is_fighting() )
        return notify_fail(CYN"媒婆说道：没看见这儿有人捣乱吗！\n"NOR);
    if( !living(this_object()) )
        return notify_fail("你还是先想办法把媒婆救醒吧。\n"); 
    if( me->is_fighting() )
        return notify_fail(CYN"媒婆说道：嘿嘿，你先还是料理完你的朋友再说吧！\n"NOR);
    if( !environment() || base_name(environment()) != query("startroom"))
        return notify_fail(CYN"媒婆说道：真是抱歉，请您等一下到红娘庄来找我吧。\n"NOR);
    if( (string)me->query("class")=="bonze" ) 
        return notify_fail(CYN"媒婆笑道：哈哈！怎么，和尚也想开色戒了吗?\n"NOR);
    if(!arg || !objectp(obj = present(arg, environment(me)))
        || !find_player(arg) )
        return notify_fail(CYN"媒婆说道：你想和谁喜结良缘？\n"NOR);
    if( me->query_temp("pending/pro") )
        return notify_fail(CYN"媒婆说道：你的婚礼正在进行中。\n"NOR);
    if( obj->query_temp("pending/pro") )
        return notify_fail(CYN"媒婆说道：你想给别人搅局吗？\n"NOR);
    if( !obj->is_character() )
        return notify_fail(CYN"媒婆说道：你这不是拿自己开涮吗。\n"NOR);
    if( (string)obj->query("class")=="bonze" ) 
        return notify_fail(CYN"媒婆笑道：哈哈！人家可是出家人，别跟人家开玩笑了。\n"NOR);
    if(obj == me)
        return notify_fail(CYN"媒婆说道：你这不是拿自己开涮吗。\n"NOR);
        if (stringp(target=me->query("marry"))){
            if (objectp(ob=present("marry ring",me))){
            if ( obj == present(target, environment(me)) ){
                    if (objectp(ob=present("marry ring",obj))){
                    command("say 你们本来就是夫妻呀！\n");
                    return 1;
                }else{
                    command("say 你们本来就是夫妻呀！\n");
                        ob = new("/clone/misc/marry_ring");
                        ob->move(obj);
                    ob->autoload();
                    message_vision("$N给了$p一个结婚戒指。\n\n" ,this_object(), obj);
                    command("say 小心保管呀！下次可别丢了！\n");
                    return 1;
                }
            }else
                if ((string)me->query("gender") == "女性") 
                    return notify_fail(CYN"媒婆说道：你已经是有夫之妇了，这里不允许重婚的。\n"NOR);
                else
                    return notify_fail(CYN"媒婆说道：你已经是有妇之夫了，这里不允许重婚的。\n"NOR);
        }else{
                ob = new("/clone/misc/marry_ring");
                ob->move(me);
            ob->autoload();
            message_vision("$N给了$p一个结婚戒指。\n\n" ,this_object(), me);
            command("say 小心保管呀！下次可别丢了！\n");
            call_out("do_marry",1,arg);
            return 1;
        }
    }
        if (stringp(target=obj->query("marry"))){
            if (objectp(ob=present("marry ring",obj))){
            if ( me->query("id") == target ){
                    if (objectp(ob=present("marry ring",me))){
                    command("say 你们本来就是夫妻呀！\n");
                    return 1;
                }else{
                    command("say 你们本来就是夫妻呀！\n");
                        ob = new("/clone/misc/marry_ring");
                        ob->move(me);
                    ob->autoload();
                    message_vision("$N给了$p一个结婚戒指。\n\n" ,this_object(), me);
                    command("say 小心保管呀！下次可别丢了！\n");
                    return 1;
                }
            }else   if((string)obj->query("gender") == "女性") 
                    return notify_fail(CYN"媒婆说道：可惜她已经是有夫之妇了，这里不允许重婚的。\n"NOR);
                else
                    return notify_fail(CYN "媒婆说道：可惜他已经是有妇之夫了，这里不允许重婚的。\n"NOR);
        }else{
                ob = new("/clone/misc/marry_ring");
                ob->move(obj);
            ob->autoload();
            message_vision("$N给了$n一个结婚戒指。\n\n" ,this_object(), obj);
            command("say 小心保管呀！下次可别丢了！\n");
            call_out("do_marry",1,arg);
            return 1;
        }
    }
    if( !living(obj) )
        return notify_fail(CYN"媒婆说道：" + obj->name() + "无法和你共结连理。\n"NOR); 

    if((string)obj->query("gender") == (string)me->query("gender"))
        return notify_fail(CYN"媒婆说道：你不怕" + RED"AIDS"CYN + "吗？\n"NOR);
    if( !userp(obj) )
        return notify_fail(CYN"媒婆说道：对不起，你只能娶玩家。\n"NOR);
    if( (object)obj->query_temp("pending/marry")!=me )
    {
        if ((string)obj->query("gender") == "女性") 
            message_vision(MAG "\n$N对著$n说道：你愿意嫁给我吗？\n\n"NOR, me,obj);
        else
            message_vision(MAG "\n$N对著$n说道：你愿意娶我吗？\n\n"NOR, me,obj);
        if( objectp(old_target = me->query_temp("pending/marry")) && old_target != obj )
            tell_object(old_target, YEL + me->name() + "取消了和你结婚的念头。\n" NOR);
           
        me->set_temp("pending/marry", obj);
        if ((string)obj->query("gender") == "女性") 
            tell_object(obj, MAG "如果你愿意嫁给他，请你也对" + me->name()
            + "("+(string)me->query("id") + ")"+ "下一次 marry 指令。\n" NOR);
        else
            tell_object(obj, MAG "如果你愿意娶她，请你也对" + me->name() + 
            "("+(string)me->query("id") + ")"+ "下一次 marry 指令。\n" NOR);
                write(MAG  "现在你急切盼望着你的心上人说同意...\n" NOR);
                return 1;
    }
    message_vision(MAG "\n$N对著$n说道：我愿意！\n\n"NOR, me,obj);           
    CHANNEL_D->do_channel(this_object(), "chat",obj->name(1)+"和"+me->name(1)+"现在开始拜堂啦! \n");
    message_vision(MAG "媒婆说道：我来作你们的主婚人。\n\n" NOR,obj, me);
    message_vision(MAG "媒婆喊道：拜 天地 喽！\n" NOR,obj, me);
    me->set_temp("pending/pro", 1);
    obj->set_temp("pending/pro", 1);
    me->set_temp("couple/couple_name",(string)obj->name(1));
    me->set_temp("couple/couple_id",obj->query("id"));
    obj->set_temp("couple/couple_name",(string)me->name(1));
    obj->set_temp("couple/couple_id",me->query("id"));
    return 1;
}
int do_unmarry()
{
    object me, obj,ob;
    string target;
    me = this_player();       
    if (me->is_busy())
        return notify_fail("媒婆说道：你现在正忙着呢。\n");
    if( me->is_fighting(this_object()) )
    {
        if( !this_object()->is_killing(me) )
            this_object()->kill_ob(me); 
        return notify_fail("媒婆说道：老娘先送你去阴间！\n");
    }
    if( this_object()->is_fighting() )
        return notify_fail("媒婆说道：没看见这儿有人捣乱吗！\n");
    if( !living(this_object()) )
        return notify_fail("你还是先想办法把媒婆救醒吧。\n"); 
    if( me->is_fighting() )
        return notify_fail("媒婆说道：嘿嘿，你先还是料理完你的朋友再说吧！\n");
    if( !environment()||base_name(environment()) != query("startroom") )
        return notify_fail("媒婆说道：真是抱歉，请您等一下到红娘庄来找我吧。\n");
        if (!stringp(target=me->query("marry"))){
        if ((string)me->query("gender") == "女性") 
            return notify_fail("媒婆说道：你还未有老公啊。\n");
        else
            return notify_fail("媒婆说道：你还未有老婆啊。\n");
    }
    if( !objectp(obj = present(target, environment(me))))
        return notify_fail(CYN "媒婆说道：你的伴侣现在不在场。\n" NOR);
    if( (object)obj->query_temp("pending/unmarry")!=me )
    {
        message_vision(MAG "\n$N对著$n说道：对不起，不是我不爱你，只是... 咱们好聚好散，好吗?\n\n"NOR, me,obj);           
        me->set_temp("pending/unmarry", obj);
        if ((string)obj->query("gender") == "女性") 
            tell_object(obj, MAG "如果你不爱他了，请你也对" 
                        +me->name() + "("+(string)me->query("id")+
                        ")"+ "下一次 unmarry 指令。\n" NOR);
        else
            tell_object(obj, MAG "如果你不爱她了，请你也对" +me->name() + "("+(string)me->query("id")+")"+ "下一次 unmarry 指令。\n" NOR);
        write(MAG "现在你正等待着你的伴侣的回答...\n" NOR);
        return 1;
    }
       
    message_vision(MAG "\n$N对著$n说道：既然无缘，咱们就各走各的路吧。\n\n"NOR, me,obj);           
    message_vision(MAG "媒婆说道：$N和$n，现在开始不是夫妇啦! \n" NOR, obj, me);
    CHANNEL_D->do_channel(this_object(), "chat",
    sprintf( "可惜%s和%s，一对璧人劳燕分飞... 但愿爱相随。\n", me->name(), obj->name()));
    me->delete("couple");
    obj->delete("couple");
    me->add("unmarried", 1);
    obj->add("unmarried", 1);
    me->delete("marry");
    obj->delete("marry");
        if (objectp(ob=present("marry ring",me)))
        destruct(ob);
        if (objectp(ob=present("marry ring",obj)))
        destruct(ob);
    return 1;
}
int do_name(string arg)
{
    object me, obj,marry_card1,marry_card2;
    me = this_player();       
    if (me->is_busy())
        return notify_fail("媒婆说道：你现在正忙着呢。\n");
    if( me->is_fighting(this_object()) )
    {
        if( !this_object()->is_killing(me) )
            this_object()->kill_ob(me); 
        return notify_fail("媒婆说道：老娘送你去阴间成婚！\n");
    }
    if( this_object()->is_fighting() )
        return notify_fail("媒婆说道：没看见这儿有人搅局吗！\n");
    if( !living(this_object()) )
        return notify_fail("你还是先想办法把媒婆救醒吧。\n"); 
    if( me->is_fighting() )
        return notify_fail("媒婆说道：嘿嘿，你先还是料理完你的朋友再说吧！\n");
    if( !environment()||base_name(environment()) != query("startroom") )
        return notify_fail("媒婆说道：真是抱歉，请您等一下到红娘庄来找我吧。\n");
    if( !me->query_temp("pending/pro") )
        return notify_fail("媒婆笑道：哈哈，你犯什么傻呀！\n");
    if( !objectp(obj = present((string)me->query_temp("couple/couple_id"), environment(me)))
        || !find_player(me->query_temp("couple/couple_id")) )
        return notify_fail("媒婆说道：你的爱人现在离开了，婚礼只好中断。\n");
    if(!arg)
        return notify_fail("媒婆笑道：你乱拜什么呀？\n");
    if ( (me->query_temp("pending/pro")==1 && arg!="天地")
        || (me->query_temp("pending/pro")==2 && arg!="高堂")
        || (me->query_temp("pending/pro")==3 && arg!=(string)me->query_temp("couple/couple_name")))
        return notify_fail("媒婆笑道：你乱拜什么呀？\n");
    {
        if( (string)obj->query_temp("pending/act")!=arg ){
            if((me->query_temp("pending/pro")==3 && arg==(string)me->query_temp("couple/couple_name"))){
                tell_object(obj, MAG"你的伴侣正等着和你夫妻对拜呢...\n" NOR);
                arg=obj->query_temp("couple/couple_name");
            }else
                tell_object(obj, MAG"你的伴侣正等着和你拜" + arg + "呢...\n" NOR);
            write(MAG "现在你正等待着你的伴侣...\n" NOR);
            me->set_temp("pending/act", arg);
            return 1;
        }else{  switch(me->query_temp("pending/pro")){
            case 1:
                CHANNEL_D->do_channel(this_object(), "chat","一拜天地! \n");
                me->add_temp("pending/pro",1);
                obj->add_temp("pending/pro",1);
                return 1;
            case 2:
                CHANNEL_D->do_channel(this_object(), "chat","二拜高堂! \n");
                me->add_temp("pending/pro",1);
                obj->add_temp("pending/pro",1);
                return 1;
            case 3:
                CHANNEL_D->do_channel(this_object(), "chat","夫妻对拜! \n");
            }
        }
    }
    message_vision(MAG "媒婆说道：$N和$n，现在是夫妻啦! \n" NOR, obj, me);
    CHANNEL_D->do_channel(this_object(), "chat",
        sprintf( "恭喜%s和%s，一对璧人喜结良缘。\n", me->name(1), obj->name(1)));
    if ((string)me->query("gender") == "女性") {
        me->set("couple/couple_gender","老公");
        obj->set("couple/couple_gender","老婆");
    }else{
        me->set("couple/couple_gender","老婆");
        obj->set("couple/couple_gender","老公");
    }
    me->set("couple/couple_name",obj->name(1));
    obj->set("couple/couple_name",me->name(1));
    me->set("marry",obj->query("id"));        
    obj->set("marry",me->query("id"));        
    obj->set("couple/marry_time",time());
    me->set("couple/marry_time",time());
    me->save();
        obj->save();
    marry_card1 = new("/clone/misc/marry_ring");
    marry_card1->move(me);
    marry_card2 = new("/clone/misc/marry_ring");
    marry_card2->move(obj);
    me->delete_temp("pending");
    obj->delete_temp("pending");
    return 1;
}
string ask_huajiao()
{
    object obj, me;
    me = this_player();
    
    if ( (string)me->query("gender") == "无性")
        return ("你无根无性，阴阳不调！");
    if (((int)me->query("age") < 18) && (me->query("gender") == "男性")
        ||((int)me->query("age") < 16) && (me->query("gender") == "女性"))
        return ("你现在还年轻，以后再说吧！");
    if (me->is_busy())
        return ("你现在正忙着呢。");
    if( me->is_fighting(this_object()) )
    {
        if( !this_object()->is_killing(me) )
            this_object()->kill_ob(me); 
        return ("老娘送你去阴间! "); 
    }
    if( this_object()->is_fighting() )
        return ("没看见这儿有人捣乱吗！");
    if( me->is_fighting() )
        return ("嘿嘿，你先还是料理完你的朋友再说吧！");
    if( !environment() || base_name(environment()) != query("startroom"))
        return ("真是抱歉，请您等一下到红娘庄来找我吧。");
    if( me->query_temp("pending/pro") )
        return ("你的婚礼正在进行中。");
    if( (string)me->query("class")=="bonze" ) 
        return ("哈哈！出家人租什么花轿，别开玩笑了。");

          message_vision("媒婆上上下下打量了$N一下：\n",me);
          me->set_temp("tmark/租", 1);
      return ("想租花轿，可以。不过说明了是租的，一千两金子租一次。");
}
int accept_object(object who, object ob)
{                    
        if ( who->query_temp("tmark/租") ) {
           if (ob->query("money_id") && ob->value() >= 10000000) {
                tell_object(who, "媒婆一哈腰，说道：多谢您了，请进！\n");               
                who->delete_temp("tmark/租");
                who->set_temp("asked",1);
                who->move("/d/nanyang/houyian.c");
                return 1;
                } else { 
                  message_vision("媒婆不耐烦地对$N说：老身都说了要一千两金子的，没听清楚吗？\n", who);
                return 0;
                }
        }

}

