inherit NPC;
inherit F_MASTER;
object ob = this_object();

void create()
{
        set_name("Ľ�ݲ�",({"murong bo","murong","bo"}));
        set("title","����Ľ����ү��");
        set("nick","�Ա�֮�� ��ʩ����");
        set("long", 
              "���������ºų��Ա�֮��������֮��Ĺ���Ľ�ݲ���\n"
              "�����ϴ��Ų���һ����Ц�ݡ�\n");
        set("age", 57);
          set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 40);
        set("int", 40);
        set("con", 40);
        set("dex", 40);
        
        set("max_qi", 4500);
        set("max_jing", 4500);
        set("neili", 4500);
        set("max_neili", 4500);
        set("jiali", 0);
        set("combat_exp", 20000000);
        set("score", 50000);                
set("chat_chance_combat",40);
        set("chat_msg_combat", ({
        (: perform_action, "parry.xingyi" :)
}));
    
         set_skill("unarmed",500);
        set_skill("dodge",500);
        set_skill("force", 500);
        set_skill("canhe-zhi", 500);
        set_skill("murong-jianfa",500);       
       set_skill("shenyuan-gong", 501);
        set_skill("yanling-shenfa", 500);
        set_skill("douzhuan-xingyi", 530);
        set_skill("parry", 510);
        set_skill("sword", 500);
        set_skill("literate", 500);
        set_skill("murong-daofa", 500);
        set_skill("blade",500);
        
        map_skill("blade", "murong-daofa");
        map_skill("unarmed", "canhe-zhi");
        map_skill("force", "shenyuan-gong");
       set("jiali",200);
        map_skill("dodge", "yanling-shenfa");
        map_skill("parry", "douzhuan-xingyi");
        map_skill("sword", "murong-jianfa");

        prepare_skill("finger","canhe-zhi");
        
        create_family("����Ľ��",1,"����");

        set("inquiry", 
                ([
                        "name" : "�Ҿ����Ա�֮������ʩ����Ĺ���Ľ�ݲ���\n",
                        "here" : "�����������µĲؾ�¥��\n",
                        "rumors" : "����Ľ�ݸ���������֮�д�������ͷ����ү�����������ѽ��\n",
                        
                ]));
        setup();
        
        carry_object("/d/city/obj/gangjian")->wield();
}

void attempt_apprentice(object ob)
{
        if (ob->query_skill("parry", 1) < 170) {
                command("say �ҹ���Ľ���Ա�֮������ʩ������м�Ҫ�����ߣ�С�ֵ��ƺ�����ѧϰ��");
    command("say " + RANK_D->query_respect(ob) + "�Ĺ���������������ذɡ�");
                return;
        }

        if (ob->query_skill("shenyuan-gong", 1) < 160) {
                command("say �ҹ���Ľ���Ա�֮������ʩ������ڹ��ķ�Ҫ�����ߣ�С�ֵ��ƺ�����ѧϰ��");
    command("say " + RANK_D->query_respect(ob) + "�Ĺ���������������ذɡ�");
                return;
        }

  command("say �ţ����㻹�Ǹ�ѧ����ϣ��Ҿ�������ɣ�");
        command("say �������ϣ����ҹ���Ľ���ֵ�һ���ģ�Ϊ�����Ҵ������һ��������");
        command("chat# ����˵�����Ϸ�������һ���ģ������˸�ָ�տɴ�����");
        command("chat* haha"); 
        command("recruit " + ob->query("id"));
        ob->set("title","�Ա�֮�� ��ʩ����");
}
