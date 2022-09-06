// hong.c ���߹�
inherit NPC;
inherit F_MASTER;
void create()
{
    set_name("���߹�", ({"hong qigong", "hong", "qigong"}));
    set("nickname", HIW "��ָ��ؤ" NOR);
    set("gender", "����");
    set("age", 75);
    set("long", 
        "������ؤ���ʮ���ΰ������ųơ���ؤ���ĺ��߹���ү�ӡ�\n");
    set("attitude", "peaceful");
    
    set("str", 100);
    set("int", 84);
    set("con", 60);
    set("dex", 184);
    set("chat_chance", 1);
    set("chat_msg", ({
        "���߹�̾�˿�����������������ʱ���ٳԵ��ض����ġ��л�������������\n",
        "���߹�˵�������׻�˵�����ڽ��ϡ��������Ͻл��ص��������ݿ�������\n",
        "���߹��૵���������ؤ��ġ�����ʮ���ơ���������Ե����Ʒ�����\n",
    }));
//    set("chat_chance_combat", 80);
//    set("chat_msg_combat", ({
//         (: command("unwield yuzhu zhang") :),
//    }) );
    set("inquiry", ([
        "������" : "����������������\n",
        "ؤ��" : "����������������\n",
        "��ʦ" : "�����ȥ���������Ұ��ܶ��³�нţ�����Ϊʦ��\n",
    ]));
    set("qi", 20000);
  set("max_qi", 20000);
    set("jing", 2500);
    set("max_jing",6000);
   set("neili",random(60000));
  set("max_neili", 30000);
   set("jing",5000);
  set("max_jing",5000);
    set("jiali", 300);
    
      set("combat_exp", 30000000+random(40000000));
    set_temp("apply/damage",500);
     
    set_skill("force", 800);
     set_skill("huntian-qigong",800);
     set_skill("unarmed", 850);
     set_skill("xianglong-zhang", 1000);
     set_skill("dodge", 900);
     set_skill("xiaoyaoyou", 950);
    set_skill("parry", 900);
      set_skill("club", 850);
   set_skill("dagou-bang", 1000);
     set_skill("begging", 500);
    set_skill("checking", 420);          // ����;˵
    
    map_skill("force", "huntian-qigong");
    map_skill("unarmed", "xianglong-zhang");
    map_skill("dodge", "xiaoyaoyou");
    map_skill("parry", "xianglong-zhang");
    map_skill("club", "dagou-bang");
    
    create_family("ؤ��", 17, "����");
    setup();
    
    carry_object(__DIR__"yuzhu_zhang")->wield();
    carry_object("/clone/misc/pcloth")->wear();
}
void attempt_apprentice(object ob)
{
    if ((int)ob->query_str() < 20 || (int)ob->query_con() < 25) {
        command("say ���л�����Ҫ�ܳԿ����ͣ����ҿ�" + RANK_D->query_respect(ob) + "�������ƺ����ʺϵ��л��ӣ�");
        return;
    }
    if (mapp(ob->query("family")) &&
        (string)ob->query("family/family_name") != "ؤ��") {
        command("say " + RANK_D->query_respect(ob) + "��Ȼ������ʦָ�㣬�α��������Ͻл��أ�");
        return;
    }
    command("recruit " + ob->query("id"));
    if((string)ob->query("class") != "beggar")
        ob->set("class", "beggar");
    
}
int accept_object(object who, object ob)
{
    object ob_yzz, me = this_object();
    if (ob->query("food_supply") <= 0)
        return 0;
    if ((string)ob->query("name") != "�л���") {
        command("say �Ͻл���" + (string)ob->query("name") + "ûʲô��Ȥ����");
        return 0;
    }
    if (query("food") >= max_food_capacity() - ob->query("food_supply")) {
        command("say �Ͻл����ڱ��úܡ�");
        return 0;
    }
    command("say ����������������ԵĽл���ѽ��");
    command("eat ji");
    command("say �벻����СС��ͣ���˼ȴ��ϸ���͸�������ض�һ����");
    if ((string)ob->query("family/family_name") != "" &&
        (string)ob->query("family/family_name") != "ؤ��") {
        command("say " + RANK_D->query_respect(ob) + "�㻹���������ʲô��");
        return 1;
    }
    if( ob_yzz = present("yuzhu_zhang", me) )
    {
        ob_yzz->move(who);
        write("������ȸ����Ҷ����ˣ����͸�����������ɡ�");
        return 1;
    }
    else
    {
        write("���������ò���ʱ���������Ѿ��������ˡ�");
        return 1;
    }
    return 1;
}
