inherit NPC;
inherit F_MASTER;

void consider();

void create()
{
        set_name("�ܲ�ͨ", ({"master zhou","zhou botong", "zhou", "botong"}));
        set("nickname", "����ͯ");
        set("gender", "����");
        set("age", 70);
        set("long",
             "���׷����룬������⣬Ц�ݿ��䡣\n"
                "�������������£���������������ͯ��\n"
                "��˵�����������һ�������֪��ô��\n"
                "��������,Ҳ���������ΰɡ�\n");
        set("attitude", "peaceful");
        set("class", "taoist");

        set("str", 35);
        set("int", 30);
        set("con", 35);
        set("dex", 30);

        set("chat_chance", 1);
        set("chat_msg", ({
                "�ܲ�ͨ˵����������а��쵰Ϊ�ˡ������澭����������ʮ�����ˡ���\n",
                "�ܲ�ͨ̾�˿����������Ҵ�Ӧʦ�ֲ����������澭���ģ�����ѧ�ִ򲻹�����а����\n",
             "�ܲ�ͨ�૵�������һ��Ҫ�ѡ������澭�����书�����ˡ��� \n",
//              (: random_move :),
        }));
//      set("inquiry", ([
//              "�����澭":"ʦ�����󣬾����ұ��ܣ��¾��Ի٣�ֻʣ�Ͼ��ˡ�\n",
//              "��\n",
//      ]));

        set("qi", 5500);
        set("max_qi", 5500);
        set("jing",2500);
        set("max_jing",2500);
        set("neili", 5500);
        set("max_neili", 5500);
        set("jiali", 200);
        
        set("combat_exp", 20000000);
        set("score", 300000);
         
        set_skill("force", 500);             // �����ڹ�
        set_skill("tiangang-zhengqi", 500);    //�������
        set_skill("unarmed", 500);           // ����ȭ��
        set_skill("kongming-quan", 500);       //����ȭ 
        set_skill("dodge", 500);             // ��������
        set_skill("qixing-huanwei",500);        //���ǻ�λ
        set_skill("parry", 500);             // �����м�
        set_skill("sword", 500);             // ��������
        set_skill("quanzhen-jianfa", 500);        //����� 
        set_skill("taoism",500);           //��ѧ�ķ�  
        set_skill("literate",500);           //����д��
       
        map_skill("force", "tiangang-zhengqi");
        map_skill("unarmed", "kongming-quan");
        map_skill("dodge", "qixing-huanwei");
        map_skill("parry", "quanzhen-jianfa");
        map_skill("sword", "quanzhen-jianfa");
        
        create_family("ȫ���", 1, "Ԫ��");
        setup();
        
        carry_object("/d/quanzhen/obj/changjian")->wield();
        carry_object("/d/quanzhen/obj/greyrobe")->wear();
}
void attempt_apprentice(object ob)
{
        if ((int)ob->query_str() < 35 || (int)ob->query_con() < 20) {
                command("say ����ʿ��Ҫ�ܳԿ����ͣ������徲���ҿ�" + RANK_D->query_respect(ob) + "�������ƺ����ʺϵ���ʿ��");
                return;
        }
        if ((string)ob->query("family/family_name") != "" &&
            (string)ob->query("family/family_name") != "ȫ���") {
                command("say " + RANK_D->query_respect(ob) + "��Ȼ������ʦָ�㣬�α������ݱ������أ�");
                return;
        }
       if ((int)ob->query_skill("tiangang-zhengqi", 1) < 180) {
                command("say ��ȫ������ڼ��书���������ڹ��ķ���"); 
                command("say " + RANK_D->query_respect(ob) + 
                        "�Ƿ�Ӧ������������϶��µ㹦��");
                return;
       }
       if ((int)ob->query_skill("quanzhen-jianfa", 1) < 220) {
                command("say ��ȫ��̽����������£�������˫��"); 
                command("say " + RANK_D->query_respect(ob) + 
                        "�Ƿ�Ӧ����ȫ�潣���϶��µ㹦��");
                return;
       }
       command("chat ����������������");
       command("say �벻��������ͯ��������������ʵ�ͽ�ܣ�һ����ѧҲ������ʧ����");
        command("recruit " + ob->query("id"));
        
}





















































