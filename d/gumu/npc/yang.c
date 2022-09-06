//yang.c ���
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("���",({"yang guo","yang","guo"}));
        set("title","��Ĺ����");
        set("nickname",HIY"������"NOR);
        set("long", "�������������µ���������һ�۵����ڲ�ȥһ����Ӣ�ۺ�����\n");
        set("age", 35);
        set("shen", 1000000);
        set("per", 30);
        set("str", 28);
        set("int", 28);
        set("con", 30);
        set("dex", 29);
set("max_qi", 300000);          	
set("max_jing", 100000); 	
set("neili", 1000000);                   	
        set("eff_jingli", 3000);
set("max_jingli", 100000); 	
set("jingli", 50000);	
set("max_neili", 50000);        	
set("jiali", 300);      	
set("combat_exp", 150000000);    	
set_skill("sword",850);	
set_skill("dodge",1200);	
          set_skill("unarmed",500);
        set_skill("force", 500);
set_skill("yunu-shenfa", 1200);	
set_skill("xuantie-jianfa", 850);	
set_skill("anranxiaohun-zhang", 500);     	
set_skill("quanzhen-jianfa",600);	
        set_skill("tianluo-diwang", 480);
        set_skill("parry", 400);
set_skill("yunv-xinfa",500);	
        set_skill("literate", 450); 
map_skill("force", "yunv-xinfa");        	
        map_skill("sword","xuantie-jianfa");
        map_skill("dodge", "yunu-shenfa");
map_skill("parry", "xuantie-jianfa");        	
map_skill("unarmed", "anranxiaohun-zhang");              	
prepare_skill("unarmed","anranxiaohun-zhang");	
set("chat_chance_combat", 100);	
        set("chat_msg_combat", ({
(: perform_action, "unarmed.xiaohun" :),	
                (: perform_action, "sword.haichao" :),
        }));
    
        create_family("��Ĺ��",3,"������");
        set("inquiry", ([
           "��Ĺ" : "���ջ�ɽ����Ӣ�۾��������������ڴ��������꣬�������£�����
�����ڴ˳���һ�����������ӣ�",
           "������" : "������������������֮��˽�ɱ�����أ��������ô˽����ֽ�����
���زش˽���һ����",
           "С��Ů" : "�������Ұ��ޣ�������������",
        ]));

        setup();

        carry_object("/d/gumu/obj/buxue1")->wear();
carry_object("/d/gumu/obj/xuantiejian")->wield();	
        carry_object("/d/gumu/obj/pao1")->wear();         
}

void attempt_apprentice(object ob)
{
     mapping fam = ob->query("family");
if (!fam || fam["family_name"] != "��Ĺ��" || fam["generation"]!=5){
                command("say "+RANK_D->query_respect(ob)+"�뱾��������������֪�˻��Ӻ�̸��");
                return;
                }       
      if((int)ob->query_skill("yunu-xinjing", 1) < 120) {
                command("say �ڹ��ǹ�Ĺ�书֮������"); 
                command("say " + RANK_D->query_respect(ob)+"�Ƿ�Ӧ�������ڹ��϶��µ㹦��");
                return;
                }   
      if((int)ob->query_int() < 30 ) {
                command("say �ҵ��书��Ҫ���ߵ����Բ���ѧ�ᡣ");
                command("say Ҫ�ܴﵽ¯����֮��������ʲô�ĵ����޹ؽ�Ҫ������ȴ�ǰ��Ҳ�������á�");
                command("say "+RANK_D->query_respect(ob)+"�����Ի�����Ǳ�����ڣ�������ذɡ�");
                return;
                }
      if(ob->query("gender") != "����") {
                command("say �ҿ�ֻ����ͽ����ȥ�������������԰ɡ�");
                return;
                }
        command("say �ţ����㻹�Ǹ�ѧ����ϣ��Ҿ�������ɣ�");         
        command("chat ��Ĺ�书���ֽ�����"+ ob->name() +"�ɱ���Ϊʦ�������ˣ�");
        command("chat* pat " + ob->query("id"));
        command("recruit " + ob->query("id"));
        ob->set("title","��Ĺ��������´���");
        ob->set("class","sworder");
}
