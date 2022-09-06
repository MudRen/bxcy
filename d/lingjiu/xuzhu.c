// /NPC xuzhu.c
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
    set_name("����", ({ "xu zhu", "xu", "zhu" }));
    set("long",
        "����һ����ʮ�������������, Ũü����,\n"+
        "���ı��ӱ�ƽ����, ��ò��Ϊ��ª. \n"+
        "��һ���������µĳ���, ��ʹ�����Լ��־���.\n"+
        "��������ɽͯ�ѵľ�������.\n");
    set("title", "���չ�������");
    set("gender", "����");
    set("age", 26);
    set("nickname", HIR "����" NOR);
    set("attitude", "peaceful");
    set("str", 45);
    set("int", 65);
    set("con", 40);
    set("dex", 130);
    set("qi", 5000);
    set("max_qi", 5000);
 set("jing", 5000);
    set("max_jing", 2000);
    set("neili", 40000);
    set("max_neili", 20000);
    set("jiali", 200);
    set("max_jingli", 2000);
    set("jingli", 4000);
        set("combat_exp", 5500000);
    set("score", 20000);
    set_skill("force", 350);
    set_skill("unarmed", 380);
    set_skill("dodge", 350);
    set_skill("parry", 350);
    set_skill("zhemei-shou",350);
    set_skill("liuyang-zhang",350);
    set_skill("yueying-wubu",300);
    set_skill("bahuang-gong", 350);
    map_skill("force", "bahuang-gong");
    map_skill("dodge", "yueying-wubu");
    map_skill("unarmed", "liuyang-zhang");
    map_skill("parry", "liuyang-zhang");
    create_family("���չ�",2, "����");
    setup();
    carry_object("/d/lingjiu/obj/changpao")->wear();
    add_money("silver",50);
}
void attempt_apprentice(object ob)
{
   if ((int)ob->query_skill("bahuang-gong", 1) < 50) 
           {
        command("say " + RANK_D->query_respect(ob) + "�Ƿ�Ӧ�ö������˻�����Ψ�Ҷ��𹦣�");
        return;
       }  
   if ((string)ob->query("gender")=="Ů��")
   {
        message_vision("����Ŀ��˼Ƭ��, ˵�������ð�, �Ҿ��������ˡ���\n",ob);
       command("recruit " + ob->query("id"));
        if((string)ob->query("class") != "dancer")
            ob->set("class", "dancer");
       return;}
   else
      {
        message_vision("��������㿴�˰���,˵���������²������������ҵ������?��\n",ob);
       return;}
}
