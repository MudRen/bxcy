// wudunlu.c

#include <ansi.h>

inherit NPC;
void create()
{
	set_name("�����", ({"wu dunru", "wu", "dunru"}));
	set("title", HIY"���������"NOR);
	set("gender", "����");
	set("age", 23);
	set("long", "���ǹ�������ӣ���ò�Ͱ���һ�쵽��Ц�Ǻǵġ�\n");
 	set("attitude", "peaceful");
	
	set("per", 24);
	set("str", 20);
	set("int", 20);
	set("con", 30);
	set("dex", 25);

	set("inquiry", ([
		"����" : "������ʦĸ��\n",
		"����" : "������ʦ����\n",
	]));

	set("qi", 1000);
	set("max_qi", 1000);
	set("jing", 500);
	set("max_jing", 500);
	set("neili", 1000);
	set("max_neili", 1000);
	
	set("combat_exp", 180000);
	set("score", 20000);
	 
	set_skill("force", 150);			// �����ڹ�
	set_skill("huntian-qigong", 150);	// ��������
	set_skill("unarmed", 150);		// ����ȭ��
	set_skill("xianglong-zhang", 150);	// ����ʮ����
	set_skill("dodge", 150);			// ��������
	set_skill("xiaoyaoyou", 150);		// ��ң��
	set_skill("parry", 150);			// �����м�
	
	map_skill("force", "huntian-qigong");
	map_skill("unarmed", "xianglong-zhang");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("parry", "xianglong-zhang");
	
	setup();
	
	carry_object("/clone/misc/cloth")->wear();
}
