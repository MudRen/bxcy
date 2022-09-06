// zuo.c
inherit NPC;
inherit F_MASTER;
#include <ansi.h>;
void create()
{
        set_name("������", ({ "zuo lengchan", "zuo" }) );
        set("title", HIR"������������"HIY"��ɽ�ɵ�ʮ������"NOR);
        set("gender", "����");
        set("class", "swordsman");
        set("age", 55);
        set("attitude", "peaceful");
        set("str", 26);
        set("con", 30);
        set("dex", 30);
        set("int", 28);

        set("neili", 30000);
        set("max_neili", 30000);
        set("jiali", 300);
        set("max_qi",8000);
        set("max_jing",4500);
        set("combat_exp", 20000000);
        set("shen", -200000);

        set_skill("unarmed", 1000);
        set_skill("sword", 900);
        set_skill("force", 950);
        set_skill("parry", 800);
        set_skill("dodge", 1000);
        set_skill("songshan-sword", 900);
        set_skill("lingxu-bu", 850);

        map_skill("sword", "songshan-sword");
        map_skill("parry", "songshan-sword");
        map_skill("dodge", "lingxu-bu");
set("chat_chance_combat", 100);	
set("chat_msg_combat", ({	
(: perform_action, "sword.lian" :),	
}) );	

        create_family("��ɽ��", 13, "����");
        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/cloth/cloth")->wear();
}

void attempt_apprentice(object ob)
{
if((int)ob->query_skill("songshan-sword",1) <= 299)
{
command("say ��ı�����ѧ��Ϊ���������Ժ��������Ұɡ�");
return 0;
}
if (ob->query("class")!="songshandizi")
{
command("say ��ͱ������޹ϸ𣬲�֪�˻��Ӻ�˵��");
return 0;       	
}
command("say �ðɣ��Ҿ������������ˣ��Ժ�Ҫ��Ϊ��ɽ�ɳ�������");
command("chat ��ɽ���ֶ������������ӣ����ְ���������˭������.....");
command("recruit " + ob->query("id"));
ob->set("class","songshandizi");	
}
