//LUCAS 2000-6-18
#include <ansi.h>

inherit NPC;

void create()
{
        set_name("������",({"bai zizai","bai"}));
        set("nickname", HIC"��������"NOR);
        set("gender", "����");
        set("age", 55);
        set("long", 
             "������ѩɽ���ɵ������ˣ�ϰ����ԣ�����Ϊ�����书��һ,\n"
             "����Լ��ʮ���꣬�����ܸɣ�������������һ�\n");
        set("attitude", "peaceful");

        set("str", 35);
        set("con", 35);
        set("int", 30);
        set("dex", 30);
        set("per", 25);
        set("neili", 24000);
set("max_neili", 9000);	
        set("jing", 8000);
        set("max_jing", 8000);
        set("qi", 8000);
        set("max_qi", 8000);
        set("jiali", 100);
        set("inquiry", ([
            "ʯ����"   : "������Ҵ������С���˵�,�ҷǰ�������Ƥ���ɡ�",
        ]) );

        set("combat_exp", 3000000);
        set("shen_type", 1);
        set("score", 100000);

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: perform_action, "sword.fengxue" :),
                (: perform_action, "sword.wanmei" :),
                (: perform_action, "sword.xuehua" :),
                (: perform_action, "sword.xuehua" :),
                (: perform_action, "unarmed.yanxue" :),
                (: perform_action, "unarmed.yanxue" :),
                (: perform_action, "unarmed.yanxue" :),
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :)
        }) );

        set_skill("unarmed", 250);
        set_skill("sword", 300);
        set_skill("force", 300);
        set_skill("parry", 250);
        set_skill("dodge", 250);
        set_skill("literate", 200);

set_skill("lingxiao-jian", 300);	
        set_skill("bingxue-xinfa", 300);
        set_skill("snow-zhang", 300);
        set_skill("snowstep", 300);

map_skill("sword", "lingxiao-jian");	
map_skill("parry", "lingxiao-jian");	
        map_skill("force", "bingxue-xinfa");
        map_skill("unarmed", "snow-zhang");
        map_skill("dodge", "snowstep");

        create_family("������", 5, "����");
        setup();

        
        carry_object("/d/lingxiao/obj/icesword")->wield();
        carry_object("/clone/cloth/cloth")->wear();
}
void attempt_apprentice(object ob)
{
    if (ob->query_int() < 30) {
        command("say ����������,Ҳ����˼�����ң�");
                return;
    }
    if ((int)ob->query_skill("bingxue-xinfa",1) < 80 ) {
        command("say ��ı����ڹ��ķ�̫����,����ŬŬ�������һ�°�!");
                return;
    } 
    if ((int)ob->query("shen") < 50000 ) {
         command("say �������������������˾��ӣ��������㡣"); 
                return;
    } 
    if ((int)ob->query("max_neili") < 800 ) {
         command("say ���������㣬�����������񹦵ľ��"); 
                return;
    }
if ((int)ob->query_skill("lingxiao-jian",1) < 150 ) { 	
        command("say ��ı��Ž���̫����,����������ԭ����ʦ����߰�!"); 
                return;
    }
    if ((int)ob->query_skill("sword",1) < 100 ) {  
        command("say ��Ļ�������̫����,��������߻�������!"); 
                return; 
    }
    command("say �ܺã��ܺ�,���ӽ��������,��������ɡ�");
    command("say ���������û������ˣ�����Ȱ��ҹ��Űɡ�");
    command("recruit " + ob->query("id"));
} 

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) ) 
        ob->set("title", HIW"�����ǳ���"NOR); 
}

