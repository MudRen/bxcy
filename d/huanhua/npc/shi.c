
inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("佻����ɵ��Ĵ�����", ({ "dizi", "dizi" }));
	set("long", 
                "һ������ͨͨ��佻����ɵ���\n"
		"�������ʮ���ˣ�\n");
	set("gender", "����");
	set("age", 20);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 21);
	set("int", 22);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 280);
	set("max_jing", 200);
	set("neili", 200);
	set("max_neili", 200);
	set("combat_exp", 20000);
	set_skill("force", 45);
	set_skill("dodge", 45);
	set_skill("unarmed", 40);
	set_skill("parry",50);
	set_skill("sword",50);


	setup();
carry_object("/clone/misc/cloth")->wear();
}