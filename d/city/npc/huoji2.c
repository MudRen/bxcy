// huoji. ҩ�̻��
inherit NPC;
inherit F_DEALER;
void create()
{
	set_name("ҩ�̻��", ({ "yaopu huoji", "huoji" }));
	set("str", 20);
	set("gender", "����");
	set("age", 18);
	set("long", "��ʮ��ǿ׳������ȥ�Ἰ���书����ҩ�������ƺ������ں���\n");
	set("combat_exp", 2500);
	set("attitude", "friendly");
	setup();
	carry_object("/clone/misc/cloth")->wear();
}
