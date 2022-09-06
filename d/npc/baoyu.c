// baoyu.c ����


inherit NPC;



void create()
{
        set_name( HIB"����"NOR, ({ "bao yu", "baoyu", "yu" }));        
        set("title", YEL"�Ĵ�����֮��"NOR"��"BLU"��"NOR"��");
        set("gender", "����");
        set("age", 32);
        set("str", 30);
        set("per", 30);
        set("dex", 30);
        set("long", "���������������µ��Ĵ��������϶�����Ȼ�书������������͵ģ�
���Ǵ������أ���ϸ�緢������һ�㶼������������ѷɫ��\n");
set("combat_exp", 500000000);   	
        set("attitude", "peaceful");

set_skill("unarmed", 1300);	
set_skill("qufeng", 1300);     	
set_skill("qimen-wuxing", 1300);     	
set_skill("force", 1300);	
set_skill("sword", 1300);	
set_skill("strike", 1300);	
set_skill("dodge", 1500);	
set_skill("parry", 1300);	
set_skill("zixia-shengong", 1300);	
set_skill("dugu-jiujian", 1300);	
set_skill("poyu-quan", 1300);	
set_skill("hunyuan-zhang", 1300);	
set_skill("qiankundanuoyi", 1500);      	

        set_temp("apply/attack", 50);
        set_temp("apply/defense", 50);
        set_temp("apply/armor", 50);
        set_temp("apply/damage", 50);


        map_skill("force", "zixia-shengong");
        map_skill("unarmed", "poyu-quan");
        map_skill("strike", "hunyuan-zhang");
        map_skill("sword", "dugu-jiujian");
        map_skill("parry", "qiankundanuoyi");
        map_skill("dodge", "qiankundanuoyi");
          
set("max_jing", 350000);  	
set("max_qi", 350000);  	
set("neili", 13500000);          	
set("shen_type", 0);
        set("max_neili", 4000); 
set("jiali",75000);             	

        prepare_skill("strike", "hunyuan-zhang");
        prepare_skill("unarmed", "poyu-quan");
set("chat_chance_combat", 100);	
        set("chat_msg_combat", ({
                (: perform_action, "sword.pojian" :),
                (: perform_action, "sword.podao" :),
                (: perform_action, "sword.poqi" :),
                (: perform_action, "sword.poanqi" :),
                (: perform_action, "sword.pobian" :),
                (: perform_action, "sword.pozhang" :),
                (: perform_action, "unarmed.leidong" :),
                (: perform_action, "strike.wuji" :),
                (: exert_function, "recover" :),
                (: exert_function, "heal" :),
            }) ); 
       
        set("chat_chance",4);
        set("chat_msg",({
     BLU"����"HIY"����һ����˵���������Ĵ������ڣ�˭Ҳ��Ҫɱ��...˭Ҫ��ɱ���˸������鷳�����������ȥ���Σ���\n"NOR,
     BLU"����¶���Ի�ı��飬��˼�����ҡҡͷ˵�����ף����ǰ�����ô��ôˮ��������׾ͱ�PK�ˣ�
         �ֲ���Ҫ���������Ĵ�����������\n"NOR,
        (: random_move :)
        }));
        setup();
        carry_object("/d/city/obj/gangjian")->wield();
        carry_object("/d/city/obj/tiejia")->wear()
;
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

