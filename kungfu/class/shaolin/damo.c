// damo.c ��Ħ��ʦ
inherit NPC;
inherit F_MASTER;
void create()
{
    set_name("��Ħ��ʦ", ({ "damo zushi", "damo" }));
    set("nickname", "һέ�ɽ�");
    set("long", 
        "�����������ɿ�ɽ���桢�������ֵ�������ɮ��Ħ��ʦ��\n"
        "����һ��������������ִ���ȡ�\n"
        "���ĸߴ��������꣬������⣬��ü�԰ס�\n");
    set("gender", "����");
    set("age", 500);
    set("attitude", "peaceful");
    set("str", 50);
    set("int", 50);
    set("con", 50);
    set("dex", 250);
    
    set("max_qi", 10000);
    set("max_jing", 5000);
    set("neili", 10000);
    set("max_neili", 10000);
    set("jiali", 300);
    set("combat_exp", 42300000);
    set("score", 1000000);
    set_skill("force", 750);
    set_skill("buddhism-force", 750);
    set_skill("dodge", 750);
    set_skill("shaolin-shenfa", 750);
    set_skill("unarmed", 700);
    set_skill("sword", 700);
    set_skill("parry", 700);
    set_skill("shaolin-shenfa", 700);
    set_skill("staff", 700);
    set_skill("club", 700);
    set_skill("blade", 700);
    set_skill("whip", 700);
    set_skill("damo-jian", 700);
    set_skill("jingang-quan", 700);
    set_skill("buddhism", 700);
    set_skill("literate", 700);
    set_skill("riyue-bian", 700);
    map_skill("force", "buddhism-force");
    map_skill("dodge", "shaolin-shenfa");
    map_skill("unarmed", "jingang-quan");
    map_skill("parry", "jingang-quan");
    map_skill("sword", "damo-jian");
    map_skill("whip", "riyue-bian");
    set_temp("apply/armor_vs_force",1000);
    create_family("������", 1, "��ɽ��ʦ");
    set("class", "bonze");
    set("chat_chance_combat", 60);
    set("chat_msg_combat", ({
        (: perform_action, "whip.chan" :),
        (: exert_function, "recover" :),
    }) );
    setup();
    carry_object("/d/shaolin/obj/jingang-zhao")->wear();    
    carry_object("/d/shaolin/obj/changbian")->wield();
}
void attempt_apprentice(object ob)
{
    object me; 
    mapping ob_fam, my_fam;
    string name, new_name;
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
    if ((int)ob->query_skill("hunyuan-yiqi", 1) < 200) {
        command("say �����������ڼ��书���������ڹ��ķ���"); 
        command("say " + RANK_D->query_respect(ob) + 
            "�Ƿ�Ӧ�����ڹ��϶��µ㹦��");
        return;
    }
    if ((int)ob->query_skill("buddhism", 1) < 180) {
        command("say ����֮�ˣ�����Ϊ�ȣ�����ĸߵ͵�������Σ�δ���䣬Ҫ��ѧ���ˡ�");
        command("say �������ķ����棬" + RANK_D->query_respect(ob) +
            "�Ƿ����ò�����");
        return;
    }
    if ((int)ob->query_skill("dodge", 1) < 200) {
        command("say ���Ṧ���棬" + RANK_D->query_respect(ob) +
            "�Ƿ����ò�����");
        return;
    }
    if ((int)ob->query_skill("shaolin-shenfa", 1) < 200) {
        command("say ���Ṧ���棬" + RANK_D->query_respect(ob) +
            "�Ƿ����ò�����");
        return;
    }
    if ((int)ob->query_skill("force", 1) < 200) {
        command("say ���ڹ����棬" + RANK_D->query_respect(ob) +
            "�Ƿ����ò�����");
        return;
    }
    if ((int)ob->query_skill("parry", 1) < 200) {
        command("say �ڻ��������棬" + RANK_D->query_respect(ob) +
            "�Ƿ����ò�����");
        return;
    }
    if (ob->query_int() < 45) {
        command("say ���¶���һ��Ե�֡�");
        command("say " + RANK_D->query_respect(ob) + "�����Ե��������ذɡ�");
        return;
    }
    if (ob->query_MKS() > 0 ) {
        command("say ���¶���һ��Ե�֡�");
        command("say " + RANK_D->query_respect(ob) + "�����Ե��������ذɡ�");
        return;
    }
    if (ob->query_PKS() > 0 ) {
        command("say ���¶���һ��Ե�֡�");
        command("say " + RANK_D->query_respect(ob) + "�����Ե��������ذɡ�");
        return;
    }
//  if ( ( ob_fam["generation"] + 35 ) == (my_fam["generation"]) )
    if ( ob->query("family/generation") == 36 )
    {
    //  if ( ob->query("luohan_winner") )
    //  {   
            command("say ���Ĵ���֮�꣬�ֵ�һ����֮�ţ����ǿ�ϲ�ɺ� !");
            name = ob->query("name");
            new_name = "��" + name[2..3];
            ob->set("name", new_name);
            ob->set("family/generation", 35);
            command("say �ӽ��Ժ���ķ�������" + new_name + "����ϲ������Ϊ�����ɶ��ֱ��޺�֮һ !");
            command("recruit " + ob->query("id"));
        
        
    }
    return;
}