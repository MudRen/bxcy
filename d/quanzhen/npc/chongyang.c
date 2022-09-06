inherit NPC;
inherit F_MASTER;
#include <ansi.h>

void create()
{
        set_name("������", ({ "wang chongyang", "wang" }));
        set("nickname", HIC "����ͨ" NOR);
        set("long", 
                "������ȫ��̿�ɽ��ʦ������ͨ��������\n"
                "��һ�����ɫ���ۣ���һ�����ǽ���\n"
                "��ɫ���󣬿������ڹ�һ���ܸ��\n");
        set("gender", "����");
        set("age", 70);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 80);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        
        set("max_qi", 8000);
      set("max_jing", 5000);
        set("neili", 5000);
        set("max_neili", 10000);
        set("jiali", 100);
        set("combat_exp", 80000000);
        set("score", 500000);

        set_skill("force", 750);
        set_skill("tiangang-zhengqi", 750);
        set_skill("dodge", 1300);
        set_skill("qixing-huanwei", 700);
        set_skill("unarmed", 650);
        set_skill("kongming-quan", 600);
        set_skill("parry", 800);
        set_skill("sword", 700);
        set_skill("quanzhen-jianfa", 720);
        set_skill("xiantian-gong", 700);
        set_skill("qixing-array", 700);
        set_skill("taoism", 700);
          set_skill("literate", 700);

     map_skill("force", "xiantian-gong");
        map_skill("dodge", "qixing-huanwei");
        map_skill("unarmed", "kongming-quan");
        map_skill("parry", "quanzhen-jianfa");
        map_skill("sword", "quanzhen-jianfa");

        create_family("ȫ���", 1, "��ɽ��ʦ");
        set("class", "taoist");

set("chat_chance_combat", 100);	
        set("chat_msg_combat", ({
                (: perform_action, "sword.qixing" :),
(: perform_action, "sword.jianzhen" :),	
                (: exert_function, "recover" :),
        }) );

        setup();
        carry_object("/d/quanzhen/obj/qixingjian")->wield();
        carry_object("/d/quanzhen/npc/obj/greenrobe")->wear();
}

void attempt_apprentice(object ob)
{
        if ((string)ob->query("family/family_name")!="ȫ���" || (string)ob->query("class")!="taoist") {
                command("say ��ȫ�����ǵ������ɡ�");
                command("say " + RANK_D->query_respect(ob) + "����������������ҵ���"); 
                return;
        }
        if ((int)ob->query_skill("tiangang-zhengqi", 1) < 300) {
                command("say ��ȫ������ڼ��书���������ڹ��ķ���"); 
                command("say " + RANK_D->query_respect(ob) + 
                        "�Ƿ�Ӧ������������϶��µ㹦��");
                return;
        }
        if ((int)ob->query("shen") < 100000) {
                command("say ѧ��֮�ˣ�����Ϊ�ȣ������֮��");
                command("say �ڵ��з��棬" + RANK_D->query_respect(ob) +
                        "�Ƿ����ò�����");
                return;
        }
        if (ob->query_int() < 60) {
                command("say ��ȫ����书ȫ�ӵ��������");
                command("say Ҫ�ܴﵽ¯����֮�������ԵͲ��á�");
                command("say " + RANK_D->query_respect(ob) + "�����Ի�����Ǳ�����ڣ�������ذɡ�");
                return;
        }
        command("chat �ã��ã����ã�����");
        command("chat ϣ��" + RANK_D->query_respect(ob) + "���ܹ�ѧ����ȫ��̵����裡��");
        command("chat* pat " + ob->query("id"));
        
        command("recruit " + ob->query("id"));
        ob->set("title",HIC"ȫ����������˴���"NOR);}


void init()
{

        object ob;

        ::init();

        ob = this_player();
        if ( (int)ob->query("shen") <-2000 && (string)ob->query("family/master_id") == "wang chongyang")
        {
                  command("chat "+ob->query("name")+"!����ɱ��Խ����������Ϊ���������������ʦ����\n");
                command("expell "+ ob->query("id"));
                this_player()->set("title","ȫ���" + RED + "��ͽ" NOR);   
                
        }
}


void do_kill(string arg)
{
        object me = this_player();
        object obj;
        
        if (!arg || !objectp(obj = present(arg, environment(me))))
                return;

        if (arg == "zhang sanfeng" || arg == "zhang")
                obj->kill_ob(me);
        else obj->fight_ob(me);
        
        me->fight_ob(obj);
}

       
int accept_fight(object ob)
{
        object me  = this_object();
                
        me->set("eff_qi", me->query("max_qi"));
        me->set("qi",     me->query("max_qi"));
        me->set("jing",   me->query("max_jing"));
        me->set("neili",  me->query("max_neili"));

        if ( me->is_fighting()) return 0;

        if ( !present(ob, environment()) ) return 0;

        remove_call_out("checking");
        call_out("checking", 1, me, ob);
        
        return 1;
}

int checking(object me, object ob)
{
        int my_max_qi, his_max_qi;

        if ( !present(ob, environment()) ) return 1; 

        my_max_qi  = me->query("max_qi");
        his_max_qi = ob->query("max_qi");

        if( me->is_fighting() ) 
        {
                if ( (int)me->query("qi")*100/my_max_qi <= 80 )
                {
                   
                        me->set("eff_qi", me->query("max_qi"));
                        me->set("qi",     me->query("max_qi"));
                        me->set("jing",   me->query("max_jing"));
                        me->set("neili",  me->query("max_neili"));
                }
                       if ( present(ob, environment()) )
                        call_out("checking", 1, me, ob);
        }


        return 1;  
}
