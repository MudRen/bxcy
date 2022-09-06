//NPC: /d/lingshedao/npc/xiexue.c
//Creat by Yjss on Sep.1999
#include "ansi.h"
inherit NPC;
inherit F_UNIQUE;
int ask_wuji();
int ask_tulong();
void create()
{
        set_name("лѷ", ({"xie xun", "xie", "xun", }));
        set("long",
        "\n����һλ���Ŀ�ΰ�쳣�ĵ�����,��ͷ�Ʒ�����������.\n"
        "����,������ֻ�۾���������,������Ϲ��.\n"
        "������һ�ѱ���,���ڿ��ڤ˼��ʲô.\n"
        );
        set("nickname",HIY "��ëʨ��" NOR);
        set("gender", "����");
        set("attitude", "peaceful");

        set("age", 53);
        set("shen_type", 1);
        set("per", 20);
        set("str", 40);
        set("int", 30);
        set("con", 30);
        set("dex", 30);

        set("max_qi", 3000);
        set("max_jing", 1300);
        set("neili", 4000);
        set("max_neili", 4000);
        set("jiali", 200);
        set("combat_exp", 950000);
        set("score", 700000);
        set("max_qi", 5500);
        set("max_jing", 5500);
        set("neili", 15000);
        set("max_neili", 15000);
        set("jiali", 250);

        set("combat_exp", 8000000);
        set("score", 800000);

        set_skill("force", 260);
        set_skill("dodge", 240);
        set_skill("sword", 240);
        set_skill("blade", 240);
        set_skill("parry", 240);
        set_skill("cuff", 200);
        set_skill("blade", 250);
        set_skill("jinwu-daofa", 250);
        set_skill("jiuyang-shengong", 250);
        set_skill("lingxu-bu", 250);
        set_skill("damo-jian", 250);
        set_skill("qishang-quan", 250);
        set_skill("hunyuan-zhang", 250);
        set_skill("literate", 100);

        map_skill("force", "jiuyang-shengong");
        map_skill("dodge", "lingxu-bu");
        map_skill("cuff", "qishang-quan");
        map_skill("parry", "hunyuan-zhang");
        map_skill("sword", "damo-jian");
        map_skill("blade", "jinwu-daofa");

        set_temp("apply/attack", 700);
        set_temp("apply/defense", 500);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 200);
        prepare_skill("cuff","qishang-quan");

        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: command("perform hunpofeiyang") :),
                (: command("perform youyouhunduan") :),
        }) );
       
        set("inquiry",([
            "�޼�" :    ( :ask_wuji: ),
            "������" :  ( :ask_tulong: ),
            "wuji" :    ( :ask_wuji: ),
            "tulong" :  ( :ask_tulong: ),
        ]) );

        set("chat_chance",4);
        set("chat_msg",({
           "лѷ������˼��:��������������,�㵽����ʲô������?\n",
           "лѷ�޺޵�˵��:��������,�㺦�Ҽ�������,�Ҳ�����ɱ����,�����Ŀ!\n",
           "лѷ�૵�˵��:Ҳ��֪�������޼ɺ�����������.\n",
           "лѷ�����̾��:��֪�������˴��ҵ������Ϊ��ʲô.\n",
        }) );
        setup();
        carry_object("/d/city/obj/cloth")->wear();
}


int accept_fight(object ob)
{
        say("лѷ��Ȼ��: ��Ҫ��ǿ�ᵶ���ǲ��ǣ�лѷ�����������֣��ֵù�����һ������..\n");
        say("лѷŭ��һ��: Ҫȡ��������ȡ������������!\n");
        kill_ob(ob);
        return 1;
}

int accept_object(object who, object ob)
{
        object tlblade;
        object shi1,shi2,shi3;
        object room;
        if ((string)ob->query("id")=="blade")
           {
            if(!who->query("blade_get"))
            {
              if(who->query_temp("marks/wuji")&&who->query_temp("marks/tulong"))
               {
     say("лѷ��"+ ob->query("name") + "�������︧����һ��,ͻȻ
���ʵ�:�ǵ�,�����޼ɺ����Ķ���\n");
                if(who->query("party/party_name")== HIG "����" NOR)
               {
                tlblade= new("/d/lingshedao/obj/tlblade");
               message_vision("лѷ������ס$N����˵����лл��������޼ɵ�ѶϢ�����Ѿ���������
�������ϵķ���,���������,������ת�����޼ɰ�!\n
˵��лѷ��"+ tlblade->query("name") + "������" + who->query("name") + "��\n",who);
              tlblade->move(who);
                command("rumor "+who->query("name")+"�õ��������ˡ�\n");
                add("blade_count",-1);
                who->set("blade_get",1);
                who->delete_temp("marks/wuji",1);
                who->delete_temp("marks/tulong",1);
                message_vision(HIC" ���ڴ�ʱ���������������������������������˼�������,
�����˶�����������ۣ����������������ߣ�����һ���Ǹ�Ů�ӡ�
ÿ�˵İ��۽��Ϻ�Ȼ������һ������֮�Σ������������ˡ�\n\n"NOR,who);
                if(!(room=find_object("/d/lingshedao/chuan")) )
                room=load_object("/d/lingshedao/chuan");
                shi1=present("liu yun",room);
                shi2=present("miao feng",room);
                shi3=present("hui yue",room);
                shi1->move("d/lingshedao/xiaowu");
                shi2->move("d/lingshedao/xiaowu");
                shi3->move("d/lingshedao/xiaowu");
                return 1;
               }
              say("лѷ��Ĭ��һ��,˵��:��������������������ת�����޼�,��ϧ 
�������������,��ʵ�ڷ��Ĳ���.��!\n\n");
              say("лѷ��˵��:������һ��С��,������,�����㵽�Ƕ�,��������ǧ��Ҫй¶�ҵ�����.��.\n\n");
              call_out("go_back",4,ob);
              return 1;
               }
              say("лѷ��Цһ��:����ʲô����?���������Զ��!\n");
              return 0;
            }
        say("лѷ˵��:�Ҳ��������������ת�����޼���?\n");  
        command("heng");
        command("give " + ob->query("id") + " to " + who->query("id"));
        return 1;
         }
           return 0;
}


int ask_wuji()
{
        object ob;
        ob=this_player();
        message_vision(MAG"\nлѷһ�,�������еı���,�����ʵ�:�޼�,�޼�,��֪��\n
���޼ɺ�������Ϣô?�������,�޼ɺ�������?\n"NOR,ob);
        ob->set_temp("marks/wuji","1");
        return 1;
}


int ask_tulong()
{
        object ob;
        ob=this_player();
        if((int)ob->query("combat_exp")<200000)
        {
        say("лѷ�ߵ�һ��,˵��:�������΢ĩ����,Ҳ������������?\n");
        message_vision("˵��лѷ����һ��,��$N�߳���С��\n",ob);
        ob->move("/d/lingshedao/xiaowuout");
        return 1;
        }
        if(!query("blade_count")<1) 
       { command("nod");
        say(HIW"лѷ˵��: �������𣬱����������������£�Ī�Ҳ��ӣ�\n"NOR);
        ob->set_temp("marks/tulong","1");
        return 1;
       }
        command("say �Ѿ����˰�������������.\n");
        return 1;
}


int go_back(object ob)
{
        message_vision("лѷ��$N�͵���һ����̲��.\n",ob);
        ob->move("/d/lingshedao/haitan2");
        return 1;
} 
void die()
{
        message("vision","\nлѷ���쳤Ц��:�벻����лѷ�ݺὭ����ʮ��,���վ�����һ
������С������.ֻ��ϧ���������,�������ֽ����ҵ��޼ɺ�����!\n","/d/lingshedao/xiaowu");
        message("vision","лѷ��̾һ��:����������,������Ҳ�����������֮��!˵��,лѷ
������������������һ��,����������ɽ������,��Ҳû����Ӱ.\n","/d/lingshedao/xiaowu");
        message_vision("ֻ��$N�����ĵ�����ȥ,����.\n",this_object());
        ::die();
}