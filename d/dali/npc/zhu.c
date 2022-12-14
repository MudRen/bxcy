// zhu.c 朱丹臣
// CLEANSWORD 1996/2/2
inherit NPC;
void create()
{
        set_name("朱丹臣", ({ "zhu danchen", "zhu" }));
        set("long", "他是大理国四大护卫之一。一副书生酸溜溜的打扮行头。\n");
        set("gender", "男性");
        set("age", 65);
        set("class", "officer");
        set("attitude", "friendly");
        set("shen_type", 1);
        set("str", 25);
        set("int", 30);
        set("con", 25);
        set("dex", 25);
        
        set("max_qi", 1000);
         set("max_jing", 6250);
         set("max_jingli", 6250);
         set("jingli", 6250);
          set("jing", 62500);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiali", 50);
        set("combat_exp", 350000);
        set("score", 110000);

        set_skill("literate", 30000);
        set_temp("apply/attack", 100);
        set_temp("apply/defense", 100);
        set_temp("apply/damage", 20);
        set("combat_exp", 500000);
        setup();
        carry_object("/clone/misc/cloth")->wear();
        add_money("gold",2);
        
        set("chat_chance", 3);
        set("chat_msg", ({
                "朱丹臣说道：普天之下，莫非王土；率土之滨，莫非王臣。\n",
                "朱丹臣说道：出家人，小过损益焉；无妄大过，未济咸困之。\n",
                "朱丹臣说道：大学之道，在明明德。在亲民，在止于至善。 \n",
                "朱丹臣说道：格物致知，诚意正心，修身齐家，治国平天下。\n",
        }) );
        create_family("大理段家",19,"护卫");
}
void init()
{
        ::init();
        if( this_player()->query_temp("dalikill") )
        {
                 kill_ob(this_player());
        }
        add_action("do_kill","kill");
        add_action("do_learn","learn");
}
int accept_object(object who, object ob)
{
        int learn;
        learn=who->query_skill("literate",1);
        learn= learn?learn*10:500;
        if( !who->query("dushu") ) {
                if( ob->value() >= learn ) {
                say(this_object()->name()+"点了点头，说道：哦，像你这麽有心的学生还真是不多见，好好努力\n"
                                "                      字(literate)的任何问题。\n");
                         who->set("dushu", ob->value()/20);
                        return 1;
                } else {
                        say(this_object()->name()+"说道：你的诚意不够，这钱还是拿回去吧。\n");
                        return 0;
                }
        } else if(ob->value()){
                say(this_object()->name()+"点了点头，说道：哦，向你这麽有心的学生还真是不多见，好好努力\n"
                        "                      将来必定前途无量，谢了。\n");
                        who->add("dushu", ob->value()/10);
        }
        return 1;
}
int do_learn(string arg)
{
        string skill, teacher;
        object me,ob,room;
        int learn,times,i;
        int master_skill, my_skill, gin_cost, my_combat_exp,grade;
        me=this_player();
        ob=this_object();
        if (me->is_busy())
                return notify_fail("你现在正忙着呢。\n");
        if(!arg || arg=="?" || arg=="/?")
                return notify_fail("指令格式：learn <某人> <技能> <次数>\tlearn <技能> at <次数> from <某人>\n");
        if ((sscanf(arg, "%s at %d from %s", skill,times,teacher)!=3 ))
                if ((sscanf(arg, "%s %s %d", teacher, skill,times)!=3 ))
                        return notify_fail("指令格式：learn <某人> <次数> <技能>\tlearn <技能> at <次数> from <某人>\n");
        if (!ob->id(teacher))   return 0;
        if( me->is_fighting() )
                return notify_fail("临阵磨枪？来不及啦。\n");
        if( !living(ob) )
                return notify_fail("嗯....你得先把" + ob->name() + "弄醒再说。\n");
        learn=me->query_skill("literate",1);
        if( !me->query("dushu") || me->query("dushu")<times*learn){
                command("say 咦？"+me->name()+"，我不记得收过你这个学生啊....\n");
                return 0;
        }
        if (!learn)     learn=10;
        if (skill!="literate")
                return notify_fail("这项技能你恐怕必须找别人学了。\n");
        if (! room=find_object(ob->query("startroom")))
                room=load_object(ob->query("startroom"));
        if (room!=environment()){
                command("say 我出来办点事，等我回去再说吧！");
                return 1;
        }
        if (ob->query("jing<30"))
{
                 ob->set("env/no_teach",1);
                command("say 我今天累了，我要去休息了！");
                return 1;
        }
        my_skill = me->query_skill(skill, 1);
        master_skill = ob->query_skill(skill, 1);
        if( my_skill >= master_skill )
                return notify_fail("这项技能你的程度已经不输你师父了。\n");
        gin_cost = 150 / (int)me->query_int() + 1;
        if( !my_skill ) {
                gin_cost *= 2;
                me->set_skill(skill,0);
        }
        printf("你向%s请教有关「%s」的疑问。\n", ob->name(), to_chinese(skill));
         if( (int)ob->query("jing") > 20)
        {
                ob->receive_damage("jing", gin_cost/10+1);
        }
        else
        {
                write("但是" + ob->name() + "显然太累了，没有办法教你什麽。\n");
                ob->set("env/no_teach",1);
                call_out("do_sleep",1,ob);
                return 1;
        }
                
        my_combat_exp = (int)me->query("combat_exp");
        if(my_combat_exp < 10000)
                grade = 1;
        else if(my_combat_exp < 80000)
                grade = 3;
        else if(my_combat_exp < 500000)
                grade = 7;
        else
                grade = 13;
        if ( grade < 1 )
                grade = 1;
        if((int)me->query("jing") > times*gin_cost+10 )
        {
                printf("你听了%s的指导，似乎有些心得。\n", ob->name());
                for (i=0;i<times ;i++ )
                {
					me->improve_skill(skill, grade * (10 + random((int)me->query_int() - 9)));
				}        
		}
        else
        {
                write("你今天太累了，结果什么也没有学到。\n");
              return 1;
        }
        me->receive_damage("jing", times*gin_cost );
        me->add("dushu", -times*learn);
        return 1;
}
int do_sleep(object ob)
{
        object room;
        if (!ob)        return  0;
        message("vision",ob->name()+"揉揉眼睛，回房睡觉去了。\n",environment(ob));
        if (!room=find_object("/d/dali/shuyuan2"))
                room=load_object("/d/dali/shuyuan2");
        ob->move(room);
        command("sleep");
        call_out("do_back",20,ob);
        return 1;
}
int do_back(object ob)
{
        object room;
        if (!ob)        return 0;
        if (!living(ob)){
                remove_call_out("do_back");
                call_out("do_back",10,ob);
        }
        ob->delete("short");
        ob->delete("env");
        if (!room=find_object(ob->query("startroom")))
                room=load_object(ob->query("startroom"));
        ob->move(room);
        message("vision",ob->name()+"伸了伸懒腰，走了过来。\n",room);
        return 1;
}
int return_home(object home)
{
        if( !environment()
        ||      environment()==home )
                return 1;
        // Are we able to leave?
        if( !living(this_object())
        ||      is_fighting()
        ||      !mapp(environment()->query("exits")) ){ call_out("return_home",10,home); return 1;}
        // Leave for home now.
        message("vision", this_object()->name() + "急急忙忙地离开了。\n",
                environment(), this_object());
        return move(home);
}

int do_kill(string arg)
{
        this_player()->set_temp("dalikill", 1);
        return 0;
}
