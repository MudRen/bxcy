
inherit NPC;
#include <ansi.h>
string ask_me();
void create()
{
	set_name("����", ({ "afei", "fei","feia" }) );
	set("gender", "����" );
        set("title", HIG "��Ϊ����" NOR);
set("class", "jianxia");	
	set("age", 20);
	set("int", 30);
	set("per", 30);
	set("long",
		"�����޵У���������\n"
		);
        set("force_factor", 200);
        set("max_gin", 3000);
        set("max_kee", 3000);
        set("max_sen", 3000);
        set("eff_gin", 3000);
        set("eff_kee", 3000);
        set("eff_sen", 3000);
set("nickname",RED"ħ��"NOR);	
        set("gin", 3000);
        set("kee", 3000);
        set("sen", 3000);
set("max_force", 30000);	
        set("force", 30000);
	set("cor",200);
set("combat_exp", 1500000000);	
        set("score", 90000);
set_skill("sword", 2400);	
set_skill("force", 2400);	
set_skill("parry", 1800);	
set_skill("literate", 1800);	
set_skill("dodge", 2000);	
set("max_neili",1000);  	
set("neili",15000000);  	
set("max_jingli",500000);  	
set("max_jingli",200000);  	
set("jingli",400000);  	
set("max_jing",500000);  	
set("max_qi",1000000);  	
set("shen",300000000);
set("jiali",50000);  	
        set("int",30);
set("chat_chance_combat", 300);	
        set("chat_msg_combat", ({
(: perform_action, "sword.jiushi" :),	
//(: perform_action, "sword.zongjue" :),	
//(: perform_action, "sword.pozhao" :),  	
//(: perform_action, "sword.pojian" :),	
//(: perform_action, "sword.podao" :),	
//(: perform_action, "sword.pobian" :),	
//(: perform_action, "sword.poqi" :),	
//(: perform_action, "sword.pozhang" :),	
        }) );
set_skill("lonely-sword", 2100);	
set_skill("pmshenfa", 1500);        	
set_skill("zhentian-quan", 1500);            	
set_skill("unarmed", 1500);            	
map_skill("dodge", "pmshenfa");     	
map_skill("unarmed", "zhentian-quan");         	
map_skill("sword", "lonely-sword");	
map_skill("parry", "lonely-sword");	
create_family("ʥ��ħ��", 5, "����");	
    set("inquiry", ([
     "���¾Ž�":(:ask_me:),
     ]) );;
	setup();
	carry_object("clone/cloth/cloth")->wear();
        carry_object(__DIR__"obj/toysword")->wield();
}
int accept_fight(object me)
{
        command("grin");
        command("say �ҵĽ�������ɱ�˵ģ����������Ȼ�����ģ�");
        return 0;
}
void init()
{
	add_action("do_killing", "kill");
}

int do_killing(string arg)
{
	
	object player, victim, weapon;
	string name;
	player = this_player();
	if( !arg) return 0;
	if( objectp(victim = present(arg, environment(this_object()))) && living(victim))
	{
		name = (string)victim->name();
		if( (string)name == "���ɶ�")
		{
		message_vision("$N��Цһ�������ҿ�����̫���ˡ�\n", this_object());
		this_object()->kill_ob(player);
		player->kill_ob(this_object());
		return 1;
		}
	}
	return 0;		
}
void attempt_apprentice(object ob)	
{
if((int)ob->query("shen",1) < 150000000)               	
{
command("say �ҵĽ���ֻ��������ʿ�����ڵ��з��滹���ò����ɡ�");	
return 0;	
}
command("say �ðɣ��Ҿ������������ˣ��Ժ�Ҫ����������塣");	
command("chat �ҵľ����������д����ˣ��������ֶ���λ��������Ĵ���������.....");	
command("recruit " + ob->query("id"));	
ob->set("class","jianxia");                  	
}
string ask_me()
{
    object me,ob;

    me = this_player();
    if ((string)me->query("family/master_id")==(string)this_object()->query("id"))
    {
         if (me->query("fengset")) 
         	return "�㾹Ȼ��������¾Ž��ľ���,������������Ҫ�����ˡ�";
         switch (random(10))
         {
              case 0:
                   me->set_temp("marks/fengseto",1);
                   return "�����������õ����´�����ָ��,�㲻��ȥ��������";
              default:
                   return "�����¾Ž��������׽���������,��Ҫ�ú�����";
         }
    }
    else return RANK_D->query_respect(this_player()) + "�����ҵ�ͽ�ܰɣ�";
}