// kuangfeng.c ���


inherit NPC;

void create()
{
        set_name(HIG"���"NOR, ({ "kuang feng", "feng", "kuangfeng" }));        
        set("title", YEL"�Ĵ�����֮��"NOR"��"GRN"��"NOR"��");
        set("gender", "����");
        set("age", 38);
        set("str", 3000);
        set("per", 30);
        set("dex", 30);
        set("long", "���������������µ��Ĵ��������ϴ�����ľ�ޱ��飬������˪��"+
        	"\n����һ����ʬ���⣬����һ������η��\n");
set("combat_exp", 500000000);   	
        set("attitude", "peaceful");


set_skill("force", 1350);	
set_skill("unarmed", 1350);	
set_skill("qufeng", 1350);     	
set_skill("qimen-wuxing", 1350);     	
set_skill("yizhi-chan", 1350);	
set_skill("sword", 1350);	
set_skill("dodge", 1500);	
set_skill("parry", 1350);	
set_skill("hunyuan-yiqi", 1350);	
set_skill("wuying-jian", 1350);	
set_skill("shaolin-shenfa", 1500);	

        set_temp("apply/attack", 60);
        set_temp("apply/defense", 60);
        set_temp("apply/armor", 60);
        set_temp("apply/damage", 60);


        map_skill("force", "hunyuan-yiqi");
        map_skill("unarmed", "yizhi-chan");
        map_skill("sword", "wuying-jian");
        map_skill("parry", "wuying-jian");


        map_skill("dodge", "shaolin-shenfa");
          
set("max_jing", 350000);  	
set("max_qi", 350000);  	

        set("max_neili", 5000);
set("neili",13500000);           	
set("jiali",75000);             	
set("shen_type", 0);

        prepare_skill("unarmed","yizhi-chan");
set("chat_chance_combat", 100);	
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.jingmo" :),
                (: perform_action, "sword.wuying" :),
        
                (: exert_function, "recover" :),
                (: exert_function, "heal" :),
            }) ); 
       
        set("chat_msg",({
     GRN"���"HIY"����һ����˵���������Ĵ������ڣ�˭Ҳ��Ҫɱ��...˭Ҫ��ɱ���˸������鷳�����������ȥ���Σ���\n"NOR,
     GRN"���ٺٺٵؼ�Ц�˼��£���������˵����ɱ����ʵ�Ǻܺ���ģ���ɱ�˿���Ӵ̼���\n"+
         "�����һ�����¸��ˣ�һ����ȥ��ɱ�˿񣬺�~����~����~����\n"NOR,
        (: random_move :)
        }));
        setup();
        carry_object("/d/city/obj/gangjian")->wield();
        carry_object("/d/city/obj/tiejia")->wear();
}
void init()
{
        object ob;
        ::init();
        if (!living(this_object())) return;
        if (interactive(ob = this_player())){
                        if ( (int)ob->query_condition("killer")) {
                    command("say "+ob->name()+"����ɱ���ˣ����������ӣ���");
                        remove_call_out("kill_ob");
                        call_out("kill_ob", 1, ob);
                                        return ;
                }
                if (  !ob->query_temp("armor/cloth") && ob->query("race")=="����" 
                   && ((int)ob->query_temp("summon_time")+400)< time() ) {
                remove_call_out("summon_ob");
                call_out("summon_ob", 1, ob);
                                return;
        }
            add_action("do_kill","kill");
        }

}
void summon_ob(object ob)
{
    object room;
    if (!ob || environment(ob)!=environment())
            return;
        if (! room=find_object("/d/city/jianyu"))
            room=load_object("/d/city/jianyu");
        message_vision("\n$Nһ��ץס$n�����컯�գ��������ܣ����˷绯��\n\n",this_object(),ob);
        message_vision("$N����$n��������ȥ��\n",this_object(),ob);
        ob->move(room);
    ob->set_temp("summon_time",time());
    message("vision",YEL+"\n\n���һ����һ���������ļһﱻ���˽�����\n\n"+NOR,room,({ob}));
        if (! room=find_object("/d/city/yamen"))
            room=load_object("/d/city/yamen");
        this_object()->move(room);
}

int do_kill(string arg)
{
        object ob;
      if (!environment()) return 0;
        if (ob=present(arg,environment()))
        if (userp(ob)){
            command("say ���ڴ�ү��ǰ��Ұ������ѽ��");
            kill_ob(this_player());
        }
    return 0;
}

