//mayu.c ����

inherit NPC;
inherit F_MASTER;

void consider();
string ask_me();

void create()
{
	set_name("����", ({"master ma","ma yu", "ma", "yu"}));
	set("nickname", "������");
	set("gender", "����");
	set("age", 60);
	set("long",
             "�����봹�أ���ɫ����ü��Ŀ�ƣ�һ�����һ����Ⱦ��\n"
	      "����������������ͽ��ȫ��̵ڶ����ƽ����ڡ�\n");
	set("attitude", "peaceful");
	set("class", "taoist");

	
	set("str", 33);
	set("int", 30);
	set("con", 33);
	set("dex", 30);

	set("chat_chance", 1);
	set("chat_msg", ({
		"����˵��������һ�λ�ɽ�۽�����ʦ�����˵�һ���õ��ˡ������澭������\n",
		"���ڵ���������а�������ϵ۱�ؤ������ͨ������ʮһ����\n��������һ�������е���λ�������֡���\n",
		"�����૵���������а������ɮ���� ����ͯ���������˵��������е���λ�������֡��� \n", 
                           
//		(: random_move :),
	}));
	set("inquiry", ([
		"�����澭":"ʦ�������Ժ󣬾����澭������ʦ�塰����ͯ���ܲ�ͨ�����ϡ�\n",
		"�ܲ�ͨ":"��˵ʦ�屻����а����ҩʦ�������һ�����\n",
		"����" : (: ask_me :),
	]));


	set("letter_count", 1);


	set("qi", 2000);
	set("max_qi", 2000);
	set("jing", 1700);
	set("max_jing", 1700);
	set("neili",2000);
	set("max_neili",2000);
	set("jiali", 115);
	
	set("combat_exp", 2200000);
	set("score", 200000);
 
	set_skill("force", 200);             // �����ڹ�
	set_skill("tiangang-zhengqi", 200);    //�������
	set_skill("unarmed", 190);           // ����ȭ��
	set_skill("kongmingquan", 190);    //����ȭ 
	set_skill("dodge",190);      	     // ��������
	set_skill("qixing-huanwei", 190);        //���ǻ�λ
	set_skill("parry", 200);             // �����м�
	set_skill("sword", 200);             // ��������
	set_skill("tiangang-jian", 200);        //����� 
       set_skill("taoism", 200);             //��ѧ�ķ�
	set_skill("literate",200);           //����д��  
  
	map_skill("force", "tiangang-zhengqi");
	map_skill("unarmed", "kongmingquan");
	map_skill("dodge", "qixing-huanwei");
	map_skill("parry", "tiangang-jian");
	map_skill("sword", "tiangang-jian");
	
	create_family("ȫ���", 2, "�ƽ�");
	
	set("chat_chance_combat", 40);
	set("chat_msg_combat", ({
		(: perform_action, "sword.qixinggongyue" :),
		(: exert_function, "recover" :),
	}) );


	setup();
	
	carry_object("/d/quanzhen/npc/obj/changjian")->wield();
	carry_object("/d/quanzhen/npc/obj/greyrobe")->wear();

}

void attempt_apprentice(object ob)
{	

	object me  = this_object();
	mapping ob_fam  = ob->query("family");
	mapping my_fam  = me->query("family");

	
	if ( ob_fam["generation"] <= my_fam["generation"] )
	{
		command("say " + RANK_D->query_respect(ob) + "��ƶ������ҵ� !");
		return;
	}

	if ((int)ob->query_str() < 28 || (int)ob->query_con() < 28) {
		command("say ����ʿ��Ҫ�ܳԿ����ͣ������徲���ҿ�" + RANK_D->query_respect(ob) + "�������ƺ����ʺϵ���ʿ��");
		return;
	}
	if ((string)ob->query("family/family_name") != "" &&
           (string)ob->query("family/family_name") != "ȫ���") {
		command("say " + RANK_D->query_respect(ob) + "��Ȼ������ʦָ�㣬�α������ݱ������أ�");
		return;
	}
       if ((int)ob->query_skill("tiangang-zhengqi", 1) < 110) {
		command("say ��ȫ������ڼ��书���������ڹ��ķ���"); 
		command("say " + RANK_D->query_respect(ob) + 
			"�Ƿ�Ӧ������������϶��µ㹦��");
		return;
       }
       command("smile");  
       command("say �ðɣ�ƶ�����������ˡ�");
	command("recruit " + ob->query("id"));
	
}
	

string ask_me()
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "ȫ���")
		return RANK_D->query_respect(this_player()) + 
		"�뱾��������������֪�˻��Ӻ�̸��";

	if (  present("shou yu", this_player()) )
		return RANK_D->query_respect(this_player()) + 
		"�����ϲ�����������������Ҫ�ˣ� ��ȥ�ɣ�";

	if (query("letter_count") < 1) return "�Բ��������ˣ��Ժ���Ŭ���ɡ�";

	ob = new(__DIR__"allow-letter");
	ob->move(this_player());

	add("letter_count", -1);

	message_vision("$N���һ�����͡�\n",this_player());
	return "����ؾ����Ժ��Ҫ�ú�Ŭ����Ϊȫ������⣬��Ҫ�������ҵĺ�����";

}


