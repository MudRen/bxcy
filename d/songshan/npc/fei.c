// fei.c
inherit NPC;
inherit F_MASTER;
#include <ansi.h>;
void create()
{
        set_name("�ѱ�", ({ "fei bing", "bing", "fei" }) );
        set("nickname", "��������");
        set("gender", "����");
        set("class", "swordsman");
        set("age", 45);
        set("attitude", "peaceful");
        set("str", 26);
        set("con", 30);
        set("dex", 30);
        set("int", 28);

        set("neili", 2000);
        set("max_neili", 2000);
        set("jiali", 30);
        set("max_qi",2000);
        set("max_jing",1200);
        set("combat_exp", 600000);
        set("shen_type", -1);

        set_skill("unarmed", 280);
        set_skill("sword", 300);
        set_skill("force", 300);
        set_skill("parry", 300);
        set_skill("dodge", 300);
        set_skill("songshan-sword", 300);
        set_skill("lingxu-bu", 300);

        map_skill("sword", "songshan-sword");
        map_skill("parry", "songshan-sword");
        map_skill("dodge", "lingxu-bu");

        create_family("��ɽ��", 13, "����");
        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/cloth/cloth")->wear();
}

void attempt_apprentice(object ob)
{
command("say �ðɣ��Ҿ��������ˣ��Ժ�Ҫ��Ϊ��ɽ�ɳ�������");	
command("recruit " + ob->query("id"));
ob->set("class","songshandizi");    	
}
