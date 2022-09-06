// Npc: /kungfu/class/shaolin/xuan-bei.c
// Date: YZC 96/01/19
inherit NPC;
inherit F_MASTER;
void create()
{
    set_name("������ʦ", ({
        "xuanbei dashi",
        "xuanbei",
        "dashi",
    }));
    set("long",
        "����һλ�����ü����ɮ������һϮ��˿�ػ����ġ����������ߣ�\n"
        "��������񣬶��Ÿ��ʣ�˫ĿտȻ����\n"
    );
    set("nickname", "��ĦԺ����");
    set("gender", "����");
    set("attitude", "friendly");
    set("class", "bonze");
    set("age", 70);
    set("str", 30);
    set("int", 30);
    set("con", 30);
    set("dex", 130);
    set("max_qi", 3500);
    set("max_jing", 1500);
    set("neili", 3000);
    set("max_neili", 3000);
    set("jiali", 150);
    set("combat_exp", 1300000);
    set("score", 1000000);
//before the modification, all the skills are 150
    set_skill("force", 200);
    set_skill("hunyuan-yiqi", 200);
    set_skill("dodge", 200);
    set_skill("shaolin-shenfa", 200);
    set_skill("unarmed", 200);
    set_skill("blade", 200);
    set_skill("sword", 200);
    set_skill("parry", 200);
    set_skill("qianye-shou", 205);
    set_skill("longzhua-gong", 205);
    set_skill("cibei-dao", 200);
    set_skill("damo-jian", 200);
    set_skill("buddhism", 200);
    set_skill("literate", 200);
    map_skill("force", "hunyuan-yiqi");
    map_skill("dodge", "shaolin-shenfa");
        map_skill("unarmed", "longzhua-gong");
    map_skill("blade", "cibei-dao");
    map_skill("sword", "damo-jian");
    map_skill("parry", "cibei-dao");
    create_family("������", 36, "����");
    set("chat_chance_combat", 45);
    set("chat_msg_combat", ({
        (: perform_action, "sword.sanjue" :),
        (: exert_function, "recover" :),
    }) );
    setup();
    carry_object("/d/shaolin/obj/xuan-cloth")->wear();
    carry_object("/d/city/obj/changjian")->wield();
}
void attempt_apprentice(object ob)
{
    object me; 
    mapping ob_fam, my_fam;
    string name;
    me = this_object();
    my_fam  = me->query("family");
    name = ob->query("name");
    if (!(ob_fam = ob->query("family")) || ob_fam["family_name"] != "������")
    {
        command("say " + RANK_D->query_respect(ob) + "�뱾��������������֪�˻��Ӻ�̸��");
        return;
    }
    if ( (string)ob->query("class")!="bonze" && ob_fam["family_name"] == "������") 
    {
        command("say " + RANK_D->query_respect(ob) + "���׼ҵ��ӣ�����������ѧ�ա�");
        return;
    }
    if ( ob_fam["generation"] <= my_fam["generation"] )
    {
        command("say " + RANK_D->query_respect(ob) + "��ƶɮ����ҵ� !");
        return;
    }
    if ( ob_fam["generation"] == (my_fam["generation"] + 1) && name[0..1] == "��")
    {
        command("say " + ob_fam["master_name"] + "��ͽ�������ܵ���������ˣ������� !");
        command("recruit " + ob->query("id"));
    }
    else
    {
        command("say " + RANK_D->query_respect(ob) + "���㱲�ݲ��ϣ�����Խ����ʦ��");
        return;
    }
    return;
}