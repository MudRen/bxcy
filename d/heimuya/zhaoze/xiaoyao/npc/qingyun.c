// qingyun.c
// shilling 97.2
inherit NPC;
#include <ansi.h>
void create()
{
    set_name("����", ({ "qingyun", "shizhe" }));
    set("long", 
        "���������˵ĵ���������һ��ʮ���������������\n");
    set("gender", "����");
    set("age", 50);
    set("attitude", "peaceful");
    set("shen_type", 1);
    set("str", 35);
    set("int", 28);
    set("con", 30);
    set("dex", 28);
    
    set("max_qi", 1000);
    set("max_jing", 1000);
    set("neili", 1000);
    set("max_neili", 1000);
    set("jiali", 100);
    set("combat_exp", 200000);
    set("score", 50000);
    set_skill("blade",100);
    set_skill("ruyi-dao",100);
    set_skill("force", 100);
    set_skill("dodge", 100);
    set_skill("unarmed", 100);
    set_skill("parry", 100);
    set_skill("lingboweibu", 100);
    set_skill("beiming-shengong",100);
    set_skill("liuyang-zhang", 100);

    map_skill("unarmed", "liuyang-zhang");
    map_skill("dodge", "lingboweibu");
    map_skill("force", "beiming-shengong");
    map_skill("blade", "ruyi-dao");
    set("book_count", 1);
    create_family("��ң��", 2, "����");
    set("title",RED "��ң�ɻ���ʹ��" NOR);
    set("nickname",HIC "��ʹ֮��" NOR);
    setup();
    carry_object(__DIR__"obj/cloth")->wear();
    carry_object(__DIR__"obj/blade")->wield();
}
void init()
{
    object ob;
    ::init();
    ob = this_player();
    if (interactive(ob) || ob->query("family/master_name")!="��ң��")
    {
            command("hehe");
            command("say ��ô�ĵ��ӣ����ɵ�����Ҳ�Ҵ����� ����\n");
            remove_call_out("kill_ob");
            call_out("kill_ob", 1, ob); 
    }
    else if(ob->query("family/master_name")=="��ң��")
    {
    command("smile");
    command("say ʦ������������ȥ��ʦ���ɣ�����������ء�");
    }
}