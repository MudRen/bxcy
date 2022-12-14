// post_officer.c

inherit NPC;
string send_mail();
string receive_mail();
void create()
{
        set_name("杜宽", ({ "post officer", "post","officer" }) );
        set("title", "驿长");
        set("gender", "男性" );
        set("age", 43);
        set("long",
                "杜宽担任雪亭镇的驿长已经有十几年了，虽然期间有几次升迁的\n"
                "机会，但是他都因为舍不得离开而放弃了，这次应风子的邀请，\n"
                "终于走出ES2，来到这里当驿站站长，风子对他很是感激。\n");
        set("combat_exp", 800);
        set("attitude", "friendly");
        set("inquiry", ([
                "风子" : "我老朋友呀！他看扬州邮件混乱，百姓叫苦连天，让\n我来当这里的驿站站长。他可是一个好巫师哟！",
                "驿站" : "是啊... 这里就是扬州驿，你要寄信吗？",
                "寄信" : (: send_mail :),
                "收信" : (: receive_mail :),
                "mail" : (: receive_mail :),
        ]) );
        set_skill("literate", 70);
        set_skill("dodge", 50);
        set_skill("unarmed", 40);
        setup();
        add_money("coin", 70);
}
string send_mail()
{
        object mbox;
        if( this_player()->query_temp("mbox_ob") )
                return "你的信箱还在吧？用信箱就可以寄信了。\n";
        if( !environment()
        ||      base_name(environment()) != query("startroom") )
                return "真是抱歉，请您等一下到驿站来找我吧。\n";
        seteuid(getuid());
        mbox = new(MAILBOX_OB);
        mbox->move(this_player());
        return "哦... 要寄信是吗？这是你的信箱，寄信的方法信箱上有说明。\n";
}
string receive_mail()
{
        object mbox;
        if( this_player()->query_temp("mbox_ob") )
                return "你的信箱还在吧？你所有的信都在里面。\n";
        if( !environment()
        ||      base_name(environment()) != query("startroom") )
                return "真是抱歉，请您等一下到驿站来找我吧。\n";
        seteuid(getuid());
        mbox = new(MAILBOX_OB);
        mbox->move(this_player());
        return "好，待我找找....有了，你的信箱在这，慢慢看吧，不打搅你了。\n";
}
void init()
{
    if( !environment()  ||  base_name(environment()) != query("startroom") )
            return;
    add_action("give_quest", "quest");

}



int time_period(int timep, object me)
{
        int t, d, h, m, s;
        string time;
        t = timep;
        s = t % 60;             t /= 60;
        m = t % 60;             t /= 60;
        h = t % 24;             t /= 24;
        d = t;

        if(d)
                time = chinese_number(d) + "天";
        else
                time = "";
        if(h)
                time += chinese_number(h) + "小时";
        if(m)
                time += chinese_number(m) + "分";
        time += chinese_number(s) + "秒";

        tell_object(me, HIW "杜宽说道：在" + time + "内");

                return 1;
}



int give_quest()
{
        object me,letter;
        object *ob=livings();
        int i,timep;

        me = this_player();

        if((int)(me->query("combat_exp")) > 150000000){
                message_vision("杜宽对$N说：您已是武林绝顶高手了，这种小事怎敢劳您大驾？！\n",me);
                return 0;
        }
        
        if( ((int)me->query("letter/task_time")) >  time() ){
                tell_object(me,"你现在的任务是把信送给"+me->query("letter/target")+"\n");
                message_vision("杜宽生气的对$N说： 你得把信帮我送到呀。\n", me);
                return 0;
        }
        message_vision("杜宽对$N说：你来得正好，我这儿刚好有一封信件要送出去。\n",me);
        timep = random(100) + 300;
        i=random(sizeof(ob));
        while (1){
                i++;
                if (i==sizeof(ob))
                    i=random(sizeof(ob));
                if (ob[i]==me)  continue;
                if (!environment(ob[i])) continue;
                if (ob[i]->is_ghost())  continue;
                if (random(20)==3)
                    if ( !userp(ob[i]) ) continue;
                if (sscanf(base_name(ob[i]),"/u/%*s" )) continue;
         break;
        }
        time_period(timep,me);
        tell_object(me, "把信送给『" + ob[i]->short() + HIW +"』你的任务就完成了。\n" NOR);
        message_vision("$N给了$n一封信。\n",this_object(),me);
        letter = new(__DIR__+"obj/letter");
        letter->set_target(ob[i]->short());
        letter->move(me);
        me->set("letter/target",ob[i]->short());
        me->set("letter/task_time", (int)time() + timep);
        return 1;
}

