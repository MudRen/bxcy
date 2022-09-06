// limochou.c ��Ī��
// By Kayin @ CuteRabbit Studio 99-3-29 11:48 new 
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
int do_look(string target);
string ask_zhen();
void create()
{
	set_name("��Ī��", ({ "li mochou", "li","mochou" }));
	set("nickname",HIR"��������"NOR);
	set("long",
		"�����ü�Ϊ��ò���������Ŀ�����˲���������\n");
	set("gender", "Ů��");
	set("age", 34);
	set("attitude", "heroism");
	set("shen_type", 1);
	set("per",29);
	set("str", 30);
	set("dex", 35);
	set("con", 17);
	set("int", 25);

	set("bpzhen",10);
	
	set("shen",600000);
	set("neili", 4000);
	set("max_neili", 4000);
	set("jiali", 100);

	set("combat_exp", 5000000);
	set("score", 8500);	
	
	set_skill("force",350);
	set_skill("yunu-xinfa",350);
	set_skill("literate",300);
	set_skill("meinu-quanfa",300);
	set_skill("tianluo-diwang",300);
	set_skill("wudu-shenzhang",300);
	set_skill("swsb-shou",300);
	set_skill("unarmed",300);
	set_skill("dodge",400);
	set_skill("whip",300);
	set_skill("xianyun-bufa",400);
	set_skill("throwing",400);
	set_skill("parry",300);

	map_skill("force","yunu-xinfa");
	map_skill("unarmed","wudu-shenzhang");
	map_skill("dodge","xianyun-bufa");
	map_skill("parry","swsb-shou");
	map_skill("whip","swsb-shou");
        set("inquiry", ([
	    "��������":(: ask_zhen :),
	    "С��Ů" : "�����ҵ�ʦ�á����������ʲô��",
	    "�ֳ�Ӣ" : "�����ҵ�ʦ�棬�������ʵ�����ʣ�С���������㡣",

	]));
	set("chat_chance", 10);
	set("chat_msg", ({
	    "��Ī���������裬�������񣬸�����������䣬���Ǻ��ֱ������������\n",
	    "��Ī�����������ϵر�˫�ɿͣ��ϳἸ�غ����\n",
	    "��Ī�����������Ȥ�����࣬���и��гն�Ů����\n",
	    "��Ī���������Ӧ�����������ƣ�ǧɽĺѩ��ֻӰ��˭ȥ����\n",
	    "��Ī����Ɐ�У��������ǰ�Թ�������������·����į������ġ���������ƽ������\n",
	    "��Ī���������л�Щ��ർ���ɽ��������ꡣ��\n",
	    "��Ī���������Ҳ�ʣ�δ���ˣ�ݺ�����Ӿ��������\n",
	    "��Ī�������ǧ����ţ�Ϊ����ɧ�ˣ����ʹ�����������𴦡���\n",
	}) );

	
	create_family("��Ĺ��", 3, "����");
	setup();
        carry_object("/d/gumu/obj/fuchen")->wield();
           carry_object("/d/city/obj/cloth")->wear();

}
void attempt_apprentice(object ob)
{
        mapping myfam;
       	 myfam = (mapping)ob->query("family");
        if(!myfam && myfam["family_name"] != "��Ĺ��")
        {
        	command("say �Բ����Ҳ��ձ��ɵ��ӡ�");
        	return;
        }
         
        if(ob->query("class")!="taoist")
		{
			command("say ���Ѿ�����ʦ�õĵ����ˣ��㻹�����Ҹ��");
			return;
		}
	if ((int)ob->query("shen") > - 50000) {
		command("say " + RANK_D->query_respect(ob) +
			"�Ƿ񻹲����ݶ���");
		return;
	}

	
	if( (int)ob->query_dex()< 30){
		command("say �����̫��.");
		return;
	}
	if( (int)ob->query_int() < 45){
		command("say �������̫�");
		return;
	}
	if((int)ob->query_skill("yunu-xinfa",1)< 200){
		command("say �����Ů�ķ�̫���ˡ�");
		return ;
	}
	if((int)ob->query_skill("tianluo-diwang",1)<150){
		command("say ������޵����ƻ�򲻹���");
		return ;
	}
	if((int)ob->query_skill("xianyun-bufa",1)<150){
		command("say ������Ʋ���̫�����ˡ�");
		return ;
	}
	if((int)ob->query("max_neili")< 1000){
		command("say ����ڹ���Ϊ������");
		return ;
	}
	
			
        	command("say �ðɣ��Ҿ��������ˡ�");
		command("recruit " + ob->query("id"));
		if( (string)ob->query("class") != "taoist")
		ob->set("class", "taoist");
}

string ask_zhen()
{
	object me=this_player();
	object obn;
	mapping myfam;
	if (query("bpzhen") < 1)
		return "�������Ѿ�û��������ˡ�\n";

	 myfam = (mapping)me->query("family");
        if(myfam && myfam["family_name"] == "��Ĺ��")
       	if(myfam["generation"] == 4)
            {
            	if(me->query("class")=="taoist")
            	{
            		obn=new("/d/gumu/obj/bpzhen");
            		obn->move(me);
            		add("bpzhen", -1);
            		return "��Щ����������͸���ɡ�\n";
            	}
            	else
            	{
            		command("say ������ʦ�õĵ��ӣ��Ҹ���Ҫ���㣿.\n");
            		return 0;
            	}
        }
        else
        {
        	return 0;
        }
}	
int do_look(string target)
{
	object me;

	me = this_player();
	if (target=="li" || target=="li mochou" || target=="mochou" )
           if ((string)me->query("gender") != "Ů��") {
		   message("vision",
   HIY "��Ī���ŭ���ȵ��������������Щ����ĳ����ˣ�ȥ���ɣ�\n"
       "��Ī�����ɱ��" + me->name() +"\n"
   NOR, environment(), this_object() );
                   kill_ob(this_player());
           }
}
