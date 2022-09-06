// jinglei.c ����

inherit NPC;


void create()
{
        set_name(HIR"����"NOR, ({ "jing lei", "jinglei", "lei" }));        
        set("title", YEL"�Ĵ�����֮��"NOR"��"RED"��"NOR"��");
        set("gender", "����");
        set("age", 20);
        set("str", 30);
        set("per", 30);
        set("dex", 30);
        set("long", "���������������µ��Ĵ���������С��һ������ȻƢ���𱬣�����Ϊ�˺�ˬ���壬
���ι������ټ���һ����ɲ���书������������ᣬȴ�Ѿ����������ˡ�\n");
set("combat_exp", 500000000);           	
        set("attitude", "peaceful");

        set_skill("unarmed", 320);
set_skill("force", 800);	
set_skill("unarmed", 1320);	
set_skill("qufeng", 1350);     	
set_skill("qimen-wuxing", 1350);     	
        set_skill("sword", 320);
set_skill("dodge", 1500);	
set_skill("parry", 1320);	
set_skill("liumai-shenjian", 900);	
        set_skill("beiming-shengong", 320);
set_skill("lingboweibu", 1500);	
        set_temp("apply/attack", 60);
        set_temp("apply/defense", 60);
        set_temp("apply/armor", 60);
        set_temp("apply/damage", 60);


        map_skill("force", "beiming-shengong");
        map_skill("unarmed","liumai-shenjian");
        map_skill("parry", "liumai-shenjian");
        map_skill("dodge", "lingboweibu");

set("max_qi", 350000);          	
set("max_jing", 350000);	
set("neili", 13500000);                  	
set("shen_type", 0);
        set("max_neili", 15000);
set("jiali", 75000);            	


        prepare_skill("unarmed","liumai-shenjian");
set("chat_chance_combat", 100);	
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.liumai" :),
                (: exert_function, "recover" :),
                (: exert_function, "max_suck" :),
            }) ); 
       
        set("chat_chance",4);
        set("chat_msg",({
     RED"���׺���һ����˵���������Ĵ������ڣ�˭Ҳ��Ҫɱ��...˭Ҫ��ɱ���˸������鷳�����������ȥ���Σ���\n"NOR,
     RED"���׿������еĽ��ӣ�ϲ���̵�˵��������׽�˼�����ɱ�˵Ļ쵰��׬�˲��������������ֿ���ȥ�������ˡ���\n"NOR,
        (: random_move :)
        }));
        setup();
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

