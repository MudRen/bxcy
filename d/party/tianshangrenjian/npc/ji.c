// WENWU 2003.9.24
// ji.c ����Ȼ
inherit NPC;
//inherit F_VENDOR;
inherit F_DEALER;
void create()
{
set_name("����Ȼ", ({ "ji yanran", "ji" }));	
set("title", "���Ʋ�Ů");	
set("shen_type", 0);	
set("gender", "Ů��");	
set("age", 23);	
	set("long",
"���ϲ�Ů��\n");	
set_skill("unarmed", 850);	
set("per", 30);      	
set_skill("dodge", 850);	
	set_temp("apply/damage", 15);
set("combat_exp", 50000);	
	set("attitude", "friendly");
	set("vendor_goods", ({
"/d/city/npc/obj/sleepbag",	
"/d/city/npc/obj/jinchuang",	
"/d/city/npc/obj/yangjing",	
	}));
	
	setup();
carry_object("/d/city/npc/cloth/zi-dress.c")->wear();	
}
void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}
