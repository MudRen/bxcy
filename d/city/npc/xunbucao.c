// yamen_police.c

inherit NPC;

void create()
{
     string *surname=({"Ľ��","����","����","�Ϲ�","�Ϲ�","ŷ��","˾ͽ","����","����",});
     set_name(surname[random(sizeof(surname))]+"Ѳ��", ({ "xun bu","police"}) );
     set("gender", "����" );
     set("age", 25);
     set("str", 185);
     set("cor", 180);
     set("cps", 185);
     set("int", 180);
     set("per", 180);
     set("kar", 185);
     set("dex", 200);
     set("long",@LONG
Ѳ���������ֽý���ǿ����ɽ���޲��ŷ�ɥ����
LONG
);
     set("status","patrol");
     set("CatchWho",0);
     set("combat_exp", 20000000);
     set("attitude", "heroism");
     set("chat_chance_combat", 90);
     set("chat_msg_combat", ({
                (: perform_action, "blade.leitingpili" :),
                (: perform_action, "blade.kuang" :),
                            }) );
     set ("inquiry",([
                "bribery":
"˵���ﻰ������̫ү��ƶ���������������µ�������û����������\n"+
"�������Ǯ�ɣ�\n",
                "salary":
"������үٺ��΢�������ǵ�������Ȼ������......\n",
                "money":
"˵ʵ�ڵģ���Ҳ��ҪǮ����Ҫ������ү֪���������ܻ�¸(bribery)��\n����Ҳ�ðǲ�Ƥ\n
",
                        ]));
     set("pursuer",1);
     set_skill("blade", 400);
     set_skill("parry", 400);
     set_skill("dodge", 400);
     set_skill("unarmed", 400);
     set_skill("force", 400);
	 set("neili", 400000); 	 
	 set("max_neili", 400000);
	 set("jiali", 350);
        set_skill("wind-blade", 500);
        
        map_skill("blade", "wind-blade");
        map_skill("parry", "wind-blade");
        set_temp("apply/attack", 300);
        set_temp("apply/defense", 800);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 500);
        
     setup();
     carry_object("/clone/weapon/gangdao")->wield();
     carry_object("/clone/misc/cloth")->wear();
     add_money("silver",30);
}
void init()
{
	object ob;
	::init();
	if (interactive(ob = this_player()) && 
		(int)ob->query_condition("killer")) {
		remove_call_out("kill_ob");
		call_out("follow_ob", 0, ob);
		call_out("kill_ob", 0, ob);
command("kill "+ob->query("id"));
	}
}
void unconcious()
{
    die();
}
