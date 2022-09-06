//liuchuxuan.c ������

inherit NPC;
inherit F_MASTER;

void consider();

void create()
{
	set_name("������", ({"liu chuxuan", "liu", "chuxuan"}));
	set("nickname", "������");
	set("gender", "����");
	set("age", 51);
	set("long",
             "�����ΰ�С����Ŀ����Գ��һ��������ò�����\n"
		"������ȫ�������еġ������ӡ���������\n");
	set("attitude", "peaceful");
	set("class", "taoist");

	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("chat_chance", 20);
	set("chat_msg", ({
		"������˵�������콫��������˹��Ҳ�������������ǣ��������......����\n",
		(: random_move :),
	}));

	set("inquiry", ([
		"��԰":"��԰���ƽ������ĵط���ֻ���������ϵĵ��Ӳ����ʸ�ݼ��ƽ̡�\n",
		]));

	set("qi", 1400);
	set("max_qi", 1400);
	set("jing", 1500);
	set("max_jing", 1500);
	set("neili", 1200);
	set("max_neili", 1200);
	set("jiali", 100);
	
	set("combat_exp", 1700000);
	set("score", 50000);
 
	set_skill("force", 170);                // �����ڹ�
	set_skill("tiangang-zhengqi", 170);      //�������
	set_skill("unarmed", 170);              // ����ȭ��
	set_skill("kongmingquan", 170);         //����ȭ 
	set_skill("dodge",170);      	      // ��������
	set_skill("qixing-huanwei", 170);      //���ǻ�λ
	set_skill("parry", 170);              // �����м�
	set_skill("sword", 170);              // ��������
	set_skill("tiangang-jian", 170);      //����� 
	set_skill("taoism", 170);             //��ѧ�ķ�  
        set_skill("literate",170);          //����д��  
  
	map_skill("force", "tiangang-zhengqi");
	map_skill("unarmed", "kongmingquan");
	map_skill("dodge", "qixing-huanwei");
	map_skill("parry", "tiangang-jian");
	map_skill("sword", "tiangang-jian");
	
	create_family("ȫ���",2,"����");
	
	set("chat_chance_combat", 40);
	set("chat_msg_combat", ({
		(: perform_action, "sword.qixinggongyue" :),
		(: exert_function, "recover" :),

	}) );
	
	setup();
	
	carry_object("/d/quanzhen/npc/obj/changjian")->wield();
	carry_object("/d/quanzhen/npc/obj/greyrobe")->wear();

}
void init()
{
	object me, ob;
	mapping fam;

	::init();

	ob = this_player();
	me = this_object();
	
	if (interactive(ob) 
	&& !environment(ob)->query("no_fight")
	&& !present("yingxiong ling", ob) 
	&& ( (fam = ob->query("family")) && fam["family_name"] != "ȫ���" ) )
	{
		if( !ob->query_temp("warned") ) {
			command("say ����˭��  ��ô����ȫ�����԰�����ˣ���");
			command("say ����������뿪���´ο����������ģ�");
			ob->set_temp("warned", 1);
		}
		else if( ob->query_temp("stay") < 10 ) ob->add_temp("stay", 1);
		else {
			command("say �󵨿�ͽ�����Ҵ���ȫ�����԰������Ұ�����ˣ��������¡�\n");
			me->set_leader(ob);
			remove_call_out("kill_ob");
			call_out("kill_ob", 1, ob); 
		}
	}       

}


