// zhuziliu.c

#include <ansi.h>
//   #include "/u/fyue/job/askjob.h"	

inherit NPC;
void create()
{
	set_name("������", ({"zhu ziliu", "zhu", "ziliu"}));
	set("gender", "����");
	set("age", 55);
	set("long", "һ�ƴ�ʦ���Ĵ����֮һ��\n");
 	set("attitude", "peaceful");
	
	set("per", 17);
	set("str", 40);
	set("int", 20);
	set("con", 30);
	set("dex", 25);

	set("qi", 3500);
	set("max_qi", 3500);
	set("eff_jingli", 4000);
	set("max_jing", 3500);
	set("neili", 45000);
	set("max_neili", 4500);
	set("inquiry",([
//                   "�س�": (:give_job:),	
//                   "���": (:task_ok:),	
		]));
	
	set("combat_exp", 9000000);
     	set_skill("force", 170);
	set_skill("sun-finger", 170);
	set_skill("jinyu-quan", 170);
	set_skill("dodge", 1700);
	set_skill("parry", 170);
       set_skill("unarmed",800);
	
	map_skill("unarmed", "sun-finger");
	map_skill("parry", "sun-finger");
	reincarnate();
	setup();
   	carry_object(__DIR__"obj/gangjian")->wield();
	carry_object(__DIR__"obj/tiejia")->wear();

	
	
}
