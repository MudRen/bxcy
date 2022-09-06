// /NPC tonglao.c
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
    set_name("��ɽͯ��", ({ "tong lao", "tong", "lao" }));
    set("long",
        "�����ǡ����չ����Ŀ�ɽ��ʦ.\n"+
        "էһ���ƺ��Ǹ��ˡ������Ů��,������ȴ����������.\n"+
        "˫Ŀ���,��������,��������ʱ,����һ�����˵�����.\n");
    set("title", "���չ�����");
    set("gender", "Ů��");
    set("age", 96);
    set("nickname", HIR "Ψ�Ҷ���" NOR);
    set("attitude", "peaceful");
    set("str", 90);
    set("int", 65);
    set("con", 60);
    set("dex", 250);
    set("qi", 20000);
    set("max_qi", 20000);
    set("jing", 20000);
    set("max_jing", 20000);
    set("jingli", 3000);
    set("max_jingli", 3000);
    set("neili", 50000);
    set("max_neili", 20000);
    set("jiali", 500);
     set("combat_exp", 90000000);
    set("score", 200000);
    set_skill("force", 420);
    set_skill("unarmed", 420);
    set_skill("dodge", 520);
    set_skill("parry", 420);
    set_skill("sword",450);
    set_skill("zhemei-shou",460);
    set_skill("liuyang-zhang",460);
    set_skill("tianyu-qijian",460);
    set_skill("yueying-wubu",460);
    set_skill("bahuang-gong", 460);
    map_skill("force", "bahuang-gong");
    map_skill("dodge", "yueying-wubu");
    map_skill("unarmed", "liuyang-zhang");
    map_skill("parry", "liuyang-zhang");
    map_skill("sword","tianyu-qijian");
    create_family("���չ�",1, "��ɽ��ʦ");
    set("chat_chance_combat", 20);
    set("chat_msg_combat", ({
        (: perform_action, "sword.san" :),
    }) );
    setup();
    carry_object("/d/lingjiu/obj/qingyi")->wear();
    carry_object("/d/lingjiu/obj/doupeng")->wear();
    carry_object("/clone/weapon/changjian")->wield();
}
void attempt_apprentice(object ob)
{
   
   if ((string)ob->query("gender")!="Ů��")
           {
        command("say ��������!");
        return;
       }
   if ((int)ob->query_skill("bahuang-gong", 1) < 130) 
           {
        command("say " + RANK_D->query_respect(ob) + "�Ƿ�Ӧ�ö������˻�����Ψ�Ҷ��𹦣�");
        return;
       }
   if (ob->query_con() < 40) 
           {
        command("say ���Ź�����Ϊ����,��ĸ����ƺ�����.");
        return;
       }
   command("recruit " + ob->query("id"));
   if((string)ob->query("class") != "dancer")
     ob->set("class", "dancer");
   return;
}
