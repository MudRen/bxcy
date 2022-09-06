inherit NPC;
inherit F_MASTER;

void consider();

void create()
{
	set_name("�´�ͨ", ({"hao datong", "hao", "datong"}));
	set("nickname", "������");
	set("gender", "����");
	set("age", 55);
	set("long",
             "���׷���ü�����׼��������Ż�ɫ���ۣ���ģ����ȫ��̵ĸ��֡�\n"
		"�����������������ߴ����֮һ�������ӡ��´�ͨ��\n");
	set("attitude", "peaceful");
	set("class", "taoist");

	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("chat_chance", 1);
	set("chat_msg", ({
		"�´�ͨ˵�������Ǳ��̵��Ӳ�Ҫ���ߡ���\n",
//	(: random_move :),
	}));

	set("qi", 1800);
	set("max_qi", 1800);
	set("jing", 1500);
	set("max_jing", 1500);
	set("neili", 1700);
	set("max_neili", 1700);
	set("jiali", 110);
	
	set("combat_exp", 1800000);
	set("score", 50000);
 
	set_skill("force", 180);             // �����ڹ�
	set_skill("tiangang-zhengqi", 180);    //�������
	set_skill("unarmed", 180);           // ����ȭ��
	set_skill("kongmingquan", 180);    //����ȭ 
	set_skill("dodge",180);      	     // ��������
	set_skill("qixing-huanwei", 180);        //���ǻ�λ
	set_skill("parry", 180);             // �����м�
	set_skill("sword", 180);             // ��������
	set_skill("tiangang-jian", 180);        //����� 
	set_skill("taoism", 180);            //��ѧ�ķ�  
       set_skill("literate",180);           //����д��  
  
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
