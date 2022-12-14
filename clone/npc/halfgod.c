#include <ansi.h>


inherit NPC;


void create()
{
     set_name( "朱半仙" , ({ "zhu banxian","zhu","halfgod","xian"}) );
        set("gender", "男性" );
        set("age", 56);


        set("long","朱半仙是个神经兮兮的老家伙。\n");
	set("no_die",1);
        set("env/wimpy", 70);
	set("max_jingli", 1000);
	set("max_neili", 100);
	set("jingli", 100000);
	set("neili",10000000);


         set("jiali",1000);
	set("str", 530);
	set("con", 30);
	set("int", 10);
	set("dex", 530);


	set("combat_exp", 100000000);


	set_skill("force", 50);
        set_skill("unarmed", 200+random(2000));
        set_skill("sword", 200+random(2000));
	set_skill("parry", 2000);
        set_skill("dodge", 200+random(2000));


	set_temp("apply/attack", 200);
	set_temp("apply/defense", 200);
	set_temp("apply/armor", 200);
	set_temp("apply/dodge", 800);


	setup();
	set("water",max_water_capacity());
	set("food",max_food_capacity());
	carry_object(__DIR__"obj/wizardsword")->wield();
	carry_object(__DIR__"obj/cloth")->wear();


}


void init()
{
	add_action("give_quest", "quest");
}


string time_period(int timep)
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


		return " 在" + time + "内,";
}


int give_quest()
{
        object me,*ob;
        int i,j,num,combatexp;
	string tag;
        mapping quest=([ ]) ;
	string *levels = ({
		"1000",
		"3000",
		"5000",
		"10000",
		"20000",
		"50000",
		"100000",
		"150000",
		"200000",
		"250000",
		"300000",
		"400000",
		"500000",
                "1000000",
                "2000000",
	});
	me = this_player();
	combatexp = (int)(me->query("combat_exp"));


        if((quest =  me->query("quest"))){
                if( ((int)me->query("quest/task_time")) >  time() ){
                        message_vision("$N看了$p一眼: "+RANK_D->query_respect(me)+"似乎还有任务在身吧？\n", this_object(),me);
                        return 0;
                }else{
			me->set("quest_failed",(int)me->query("quest/task_time") + random(100)+10);
                	me->delete("quest");
                }
        }
        if( time() >= me->query("quest_failed") ){
		me->delete_temp("count");
               	me->delete("quest_failed");
	}
        if(me->query("quest_failed") ) {
               message_vision("$N对$p哼了一声: 上次的任务都完成不了，再问我就杀了你！\n", this_object(),me);
               return 1;
	}
	for(j = sizeof(levels) - 1 ; j >= 0; j--)
	{
		if( atoi(levels[j])  <= combatexp )
		{
			num = random(j);
			break;
		}
	}


	tag = levels[num];
	while(1){
	        if (random(10)>5){
			quest = QUEST_D(tag)->query_quest();
			if (!mapp(quest))	return 0;
			quest["time"]=quest["diff"]*(random(70)+150);
		        tag=time_period(quest["time"]);
        		command("whisper "+me->query("id")+tag+ "帮我找『" + quest["quest"] + "』。\n");
		        me->set("quest", quest);
			me->set("quest/quest_type","寻");
		        me->set("quest/task_time", (int)time() + (int)quest["time"]);
			me->add_temp("quest_count",1);
		        return 1;
                }else{
		        ob=livings();
		        for (j=0;j<sizeof(ob);j++) {
				i=random(sizeof(ob));
                                if (ob[i]->query("combat_exp")<= combatexp+10 ){
					if (!environment(ob[i])) continue;
                                        if (userp(ob[i]) || !living(ob[i]) ) continue;
					if (environment(ob[i])->query("no_fight")) continue;
					if (ob[i]->query("no_die")) continue;
                                        if (sscanf(base_name(ob[i]),"/u/%*s" )) continue;
					me->set("quest/time",random(200)+150);
				        tag=time_period(me->query("quest/time"));
	        			command("whisper "+me->query("id")+tag+ "杀了" + ob[i]->short() + "。\n");
				        me->set("quest/quest", ob[i]->short());
					me->set("quest/quest_type","杀");
					me->set("quest/diff",random(4)+2);
				        me->set("quest/task_time", (int)time() + me->query("quest/time"));
					me->add_temp("quest_count",1);
				        return 1;
				}
		        }
			continue;
		}
	}


}


int accept_object(object me, object obj)
{
	mapping quest,target;
	object home;
        int i;


	if( time() < me->query("quest_failed") || mapp(quest=me->query("quest"))) {
                  i=me->query("combat_exp");
               if (i>100000 ) i=100000;
                if (obj->query("money_id") && obj->value() >= i ){
			command("say 好吧！"+me->name()+"，上次的任务就算了！");
			me->delete("quest_failed");
			me->delete("quest");
			return 1;
		}
	}
	if (!mapp(quest)){
		command("say 我对"+obj->name()+CYN+"不感兴趣。");
           	return 0;
	}
        if ( quest["quest_type"] != "寻" ) {
	        say( CYN+this_object()->name()+"摇了摇头："+RANK_D->query_respect(me)+"的任务不是拍我的马屁！\n"NOR);
		return 0;
	}


        target = quest["quest"];
        if ( target!=obj->name() ){
		command("say 我对"+obj->name()+CYN+"不感兴趣。");
           	return 0;
	}
        if(!home = find_object(query("startroom")) )
                home = load_object(query("startroom"));
	if (environment()!=home){
		command("say 我现在正忙着呢！等我回去再说吧！");
		return 0;
	}
        if( quest["task_time"] >  time() ){
                i=quest["diff"]*50+1;
		if(!(me->query_temp("quest_count")%8))
			i*=2;
	        command("smile");
		i=(i/3+1)*2;
	        tell_object(me, sprintf(WHT"你圆满完成了你的任务:\n你获得了%s点战斗经验！", chinese_number(i)) );
        	me->add("combat_exp", i);
                i=random(i)*2+1;
	        tell_object(me, sprintf(HIY"\n%s点潜能！\n"NOR, chinese_number(i)) );
		me->add("potential",i);
		i=random(i)*2/3+10;
		tell_object(me, sprintf(YEL"%s点综合评价！\n"NOR, chinese_number(i)) );
		me->add("score",i);
		me->delete("quest");
	        return 1;
	}else{
		me->set("quest_failed",(int)me->query("quest/task_time") + (int)me->query("quest/time"));
	        if( time() >= me->query("quest_failed") ){
			me->delete_temp("quest_count");
               		me->delete("quest_failed");
		}
                message_vision(CYN+"$N很生气地对$n说道：这么点儿事都办不好，真没用！\n"+NOR, this_object(), me);
		me->delete("quest");
		return	1;
	}
}






