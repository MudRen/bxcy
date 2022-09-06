// zhang.c ������
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
    set_name("������", ({ "zhang sanfeng", "zhang" }));
    set("nickname", HIG "��������" NOR);
    set("long", 
        "�������䵱�ɿ�ɽ���桢�������ֵ�̩ɽ�������������ˡ�\n"
        "��һ���ۻ�Ļ�ɫ���ۣ����ޱ߷���\n"
        "��ĸߴ��������꣬������⣬��ü�԰ס�\n");
    set("gender", "����");
    set("age", 100);
    set("attitude", "peaceful");
    set("shen_type", 3);
    set("str", 70);
    set("int", 90);
    set("con", 230);
    set("dex", 230);
    
    set("max_qi", 5000);
    set("max_jing", 3000);
    set("max_jingli", 3000);
    set("jingli", 3000);
    set("neili", 30000);
    set("max_neili", 20000);
    set("jiali", 300);
        set("combat_exp", 16637500);
    set("score", 500000);
    set_skill("force", 850);
    set_skill("taiji-shengong", 480);
    set_skill("dodge", 450);
    set_skill("tiyunzong", 450);
    set_skill("unarmed", 450);
    set_skill("taiji-quan", 450);
    set_skill("parry", 450);
    set_skill("sword", 400);
    set_skill("taiji-jian", 500);
    set_skill("blade", 400);
    set_skill("taiji-dao", 500);
    set_skill("taoism", 850);
    set_skill("literate", 500);
    map_skill("force", "taiji-shengong");
    map_skill("dodge", "tiyunzong");
    map_skill("unarmed", "taiji-quan");
    map_skill("parry", "taiji-jian");
    map_skill("sword", "taiji-jian");
    map_skill("blade", "taiji-dao");
    create_family("�䵱��", 1, "��ɽ��ʦ");
    set("class", "taoist");
    set("chat_chance_combat", 60);
    set("chat_msg_combat", ({
        (: perform_action, "sword.lian" :),
        (: perform_action, "sword.chan" :),
        (: perform_action, "sword.sui" :),
        (: exert_function, "recover" :),
    }) );
    setup();
    carry_object("/clone/weapon/changjian")->wield();
    carry_object("/d/wudang/obj/greyrobe")->wear();
}
void attempt_apprentice(object ob)
{
    if ((int)ob->query_skill("taiji-shengong", 1) < 50) {
        command("say ���䵱�����ڼ��书���������ڹ��ķ���"); 
        command("say " + RANK_D->query_respect(ob) + 
            "�Ƿ�Ӧ����̫�����϶��µ㹦��");
        return;
    }
    if ((int)ob->query("shen") < 2000) {
        command("say ѧ��֮�ˣ�����Ϊ�ȣ�����ĸߵ͵�������Σ�δ���䣬Ҫ��ѧ���ˡ�");
        command("say �ڵ��з��棬" + RANK_D->query_respect(ob) +
            "�Ƿ����ò�����");
        return;
    }
    if (ob->query_int() < 30) {
        command("say ���䵱���书ȫ�ӵ��������");
        command("say Ҫ�ܴﵽ¯����֮��������ʲô�ĵ����޹ؽ�Ҫ������ȴ�ǰ��Ҳ�����á�");
        command("say " + RANK_D->query_respect(ob) + "�����Ի�����Ǳ�����ڣ�������ذɡ�");
        return;
    }
    command("chat ����������������");
    command("chat �벻���ϵ��ڴ���֮�꣬���ٵ�һ������֮�ţ����ǿ�ϲ�ɺء�");
    command("recruit " + ob->query("id"));
}
