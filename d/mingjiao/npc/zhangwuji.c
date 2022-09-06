// zhangwuji.c
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string ask_me();
object who = this_player();

void create()
{
    set_name("���޼�", ({ "zhang wuji", "zhang", "wuji"}));
	set("title",HIR"���̽���"NOR);
	set("long",
	"�����۾��ر����������������ر�Ӣ����\n"
	"��������������Ե�����֮�������������̵�34������--���޼ɡ�\n");
	set("gender", "����");
	set("age", 25);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 32);
	set("per",28);
	set("int", 30);
	set("con", 30);
	set("dex", 32);

	set("max_qi", 40000);
	set("max_jing", 10000);
	set("neili", 300000);
	set("max_neili", 20000);
	set("jiali", 300);
	set("combat_exp", 70000000);
	set("shen",30000);
	set("score", 30000);



	set_skill("taiji-jian", 650);
	set_skill("qiankundanuoyi", 750);
set_skill("shenghuo-ling",700);	
	set_skill("sword",1000);
	set_skill("force", 900);
	set_skill("shenghuo-shengong", 750);
	set_skill("dodge", 1000);
	set_skill("tiyunzong", 750);
	set_skill("unarmed", 700);
	set_skill("jiuyang-force", 680);
	set_skill("parry", 700);
	set_skill("literate", 580);
//      set_skill("shenghuo-lingfa",220);
	set_skill("taoism",680);
	set_skill("taiji-quan",650);

	map_skill("force", "jiuyang-force");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "jiuyang-force");
	map_skill("parry", "jiuyang-force");
	map_skill("sword", "taiji-jian");
	map_skill("dodge", "qiankundanuoyi");


	create_family("����", 34, "����");

	set("inquiry", ([
		"����" : "�������������̵�34�����������޼ɡ�\n",
		"лѷ" : "�������µ��常�������������ҵ������Ҷ�����л��! \n",
		"�ؼ�" : "�ұ������д��һ��������������ƪ,ȴ��֪���ҵ���ͯŪ�Ķ�ȥ��.\n",
		"�����ؼ�" : (: ask_me :),
	]));

	set("no_get",1);
	set("book_count", 1);
	setup();
	carry_object("/clone/misc/cloth")->wear();
	set("chat_chance", 1);
	set("chat_msg", ({
		"���޼�����̾������֪���ǿ������常���ںδ�����\n",
		"���޼ɵ�����������������������\n",
	}) );

}

string ask_me()
{
	mapping fam;
	object ob;
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "����")
		return RANK_D->query_respect(this_player()) +
		"�뱾��������������֪�˻��Ӻ�̸��";
	if (!this_player()->query_temp("marks/�常"))
	return "������ܰ����ҵ��ҵ��常лѷ���ǻ����Կ��ǣ�";
	if (query("book_count") < 1)
		return "�������ˣ�����������û�б��̵�����ķ���";
	add("book_count", -1);
	ob = new(__DIR__"obj/jiuyang2");
	ob->move(this_player());
	return "�ðɣ�����������ҵ����常�ķ��ϣ��Ȿ�������ؼ������û�ȥ�ú����аɡ�";
}
/*
void init()
{
       object ob;

       ::init();

	ob = this_player();
	if( ((int)ob->query("score") < 200 || ob->query("shen") < 2000 ) && ob->query("family/master_id")=="zhang wuji" )
	{
		    command("chat "+ob->query("name")+"����Ϊ�˲��Ҳ��壬�������������㣿\n");
		    command("expell "+ ob->query("id"));
		    this_player()->set("title","����" + RED + "��ͽ" NOR);
	}

}
*/

void attempt_apprentice(object ob)
{
	if ((int)ob->query("shen") < 5000) {
		command("shake");
		command("say ��Ŀ¶�׹⣬�������֮������������֮�ˣ��㻹�ǻ�ȥ�ɣ�");
		return;
	}
	if ((int)ob->query_skill("force", 1) < 100) {
		command("shake");
		command("say �ҵľ����������������Ļ����ڹ�Ϊ�����ģ�");
		command("say ��Ļ�������δ���ã�������ûʲô���Խ���ģ�");
		command("sigh");
		return;
	}
	if ((int)ob->query_skill("taoism", 1) < 101) {
		command("shake");
		command("say ������������Ҫ���ľ���ģ�");
		command("say ��Ļ�������δ���ã�������ûʲô���Խ���ģ�");
		return;
	}
	if ((int)ob->query("max_neili", 1) < 500) {
		command("shake");
		command("say ������������Ҫ����������");
		command("say ����������㣬������ûʲô���Խ���ģ�");
		return;
	}
	if ((int)ob->query_skill("parry", 1) < 90) {
		command("shake");
		command("say �ҵ��书�����ޱȣ�����мܲ�����");
		command("say ��Ļ�������δ���ã�������ûʲô���Խ���ģ�");
		return;
	}
	if ((int)ob->query("score") < 2000 ) {
		command("say ��Ա��ŵĹ��׻�����,����Ŭ��ѽ��");
		return;
	}

	if (this_player()->query_temp("marks/�常")) {
		command("say �ðɣ��Ҿ��������ˡ�");
		command("recruit " + ob->query("id"));
		ob->set("title","�����Ž�����������");
		this_player()->delete_temp("marks/�常");
		command("say ������ �������ֵ�һ���ģ������պ󿵷����壬�������̷�����");
		command("recruit " + ob->query("id"));
		if((string)ob->query("class") != "shizhe")
			ob->set("class", "shizhe");
//              ob->set("title",HIW"���̹�����ʹ"NOR);
	}
	else {
		command("say ��ƽ��ֻ��һ���常�ܹ�Т�������ܰ���֪̽����������");
	}
	return;
}

int prevent_learn(object me, string skill)
{
	if( skill == "jiuyang-force" && me->query_skill(skill, 1) < 100)
		return notify_fail("�����ľ�������Ҫ�Ӿ����ؼ���ѧϰ.\n");
}

int accept_object(object who, object ob)
{
	object obj,me = this_player();
	obj=this_object();
	if ( ob->query("id") != "jin mao" || userp(ob) )
		return 0;
	tell_object(who,GRN"���޼ɼ�����˵�������ҵ��ҵ��常�ˡ�\n"NOR);
	if ( !me->query_temp("marks/�常") )
		me->set_temp("marks/�常", 1);
	remove_call_out("destrory");
	call_out("destrory",1,ob);
	return 1;
}

void destrory(object ob)
{
	destruct(ob);
}



void do_kill(string arg)
{
	object me = this_player();
	object obj;

	if (!arg || !objectp(obj = present(arg, environment(me))))
		return;

	if (arg == "zhang wuji" || arg == "zhang")
		obj->kill_ob(me);
	else obj->fight_ob(me);

	me->fight_ob(obj);
}


int accept_fight(object ob)
{
	object me  = this_object();

	me->set("eff_qi", me->query("max_qi"));
	me->set("qi",     me->query("max_qi"));
	me->set("jing",   me->query("max_jing"));
	me->set("neili",  me->query("max_neili"));

	if ( me->is_fighting()) return 0;

	if ( !present(ob, environment()) ) return 0;

	remove_call_out("checking");
	call_out("checking", 1, me, ob);

	return 1;
}

int checking(object me, object ob)
{
	int my_max_qi, his_max_qi;

	if ( !present(ob, environment()) ) return 1;

	my_max_qi  = me->query("max_qi");
	his_max_qi = ob->query("max_qi");

	if( me->is_fighting() )
	{
		if ( (int)me->query("qi")*100/my_max_qi <= 80 )
		{

			me->set("eff_qi", me->query("max_qi"));
			me->set("qi",     me->query("max_qi"));
			me->set("jing",   me->query("max_jing"));
			me->set("neili",  me->query("max_neili"));
		}
		       if ( present(ob, environment()) )
			call_out("checking", 1, me, ob);
	}

	return 1;
}

