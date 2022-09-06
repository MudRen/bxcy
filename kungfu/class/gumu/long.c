// long.c С��Ů
// By Kayin @ CuteRabbit Studio 99-3-29 11:48 new 
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
int ask_chongyang();
int ask_jiuyin();
string ask_shoutao();
string ask_suo();
string ask_zhen();
void create()
{
	set_name("С��Ů", ({ "xiao long nu", "long" }));
	set("long",
		"����һϮ��ɴ��İ��£��������������������һͷ�ڷ�֮�⣬ȫ��ѩ�ף�\n"+
"�����������ף�ֻ�Ǽ���������һ��Ѫɫ.\n");
	set("gender", "Ů��");
	set("age", 29);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 25);
	set("per",31);
	set("int", 30);
	set("con", 25);
	set("dex", 30);

	set("count",1);
	set("yfzhen",10);
	
	set("shen",600000);
	set("max_jingli",2000);
	set("jingli",2000);
	set("neili", 4000);
	set("max_neili", 4000);
	set("jiali", 100);

	set("combat_exp", 5000000);
	set("score", 8500);	
	
	set_skill("force",350);
	set_skill("yunu-xinfa",350);
	set_skill("yunu-xinjing",350);
	set_skill("literate",300);
	set_skill("meinu-quanfa",300);
	set_skill("tianluo-diwang",300);
	set_skill("sword",400);
	set_skill("yunu-jianfa",400);
	set_skill("unarmed",300);
	set_skill("dodge",400);
	set_skill("yufeng-shu",300);
	set_skill("whip",300);
	set_skill("yinsuo-jinling",300);
	set_skill("xianyun-bufa",400);
	set_skill("throwing",400);
	set_skill("parry",300);

	map_skill("force","yunu-xinjing");
	map_skill("unarmed","meinu-quanfa");
	map_skill("sword","yunu-jianfa");
	map_skill("dodge","xianyun-bufa");
	map_skill("parry","yunu-jianfa");
	map_skill("whip","yinsuo-jinling");
        set("inquiry", ([
	"�����ſ�":(: ask_chongyang :),
	"��Ů�ľ�":(: ask_chongyang :),
	"����":(: ask_jiuyin :),
	"�����澭":(: ask_jiuyin :),
	"������":(: ask_suo :),
	"��˿����":(: ask_shoutao :),
	"�����":(: ask_zhen :),
	]));
	
	create_family("��Ĺ��", 3, "����");
	setup();
	carry_object("/d/gumu/obj/jinling-suo")->wield();
	carry_object("/d/gumu/obj/jinsi-shoutao")->wear();
	carry_object("/d/gumu/obj/si_cloth")->wear();

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
         
        if(ob->query("class")=="taoist")
		{
			command("say ���Ѿ�����ʦ��ĵ����ˣ��㻹�����Ҹ��");
			return;
		}
	if ((int)ob->query("shen") < 50000) {
		command("say �ڵ��з��棬" + RANK_D->query_respect(ob) +
			"�Ƿ����ò�����");
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
	if((int)ob->query_skill("yunu-xinfa",1)< 100){
		command("say �����Ů�ķ�̫���ˡ�");
		return ;
	}
	if((int)ob->query_skill("tianluo-diwang",1)<100){
		command("say ������޵����ƻ�򲻹���");
		return ;
	}
	if((int)ob->query_skill("xianyun-bufa",1)<100){
		command("say ������Ʋ���̫�����ˡ�");
		return ;
	}
	if((int)ob->query("max_neili")< 1000){
		command("say ����ڹ���Ϊ������");
		return ;
	}
	
			
        	command("say �ðɣ��Ҿ��������ˡ�");
        	command("say �Ժ�һ�������������¡�");
		command("recruit " + ob->query("id"));

}

int ask_chongyang()
{
	object me=this_player(1);
	mapping myfam;
	 myfam = (mapping)me->query("family");
        if(myfam && myfam["family_name"] == "��Ĺ��")
            {
            	if(me->query("class")==!"taoist")
            	{
            		command("say Ҫ���ڴ����򿪻��أ���ȥ�򿪰���.\n");
            		me->set_temp("gumu/����",1);
            		return 1;
            	}
            	else
            	{
            		command("say ������ʦ��ĵ��ӣ��Ҹ���Ҫ�����㣿.\n");
            		return 1;
            	}
        }
        else
        {
        	return 1;
        }
}
int ask_jiuyin()
{
	object me=this_player(1);
	mapping myfam;
	 myfam = (mapping)me->query("family");
        if(myfam && myfam["family_name"] == "��Ĺ��")
            {
            	if(me->query("class")==!"taoist")
            	{
            		command("say ��ȥ�ƿ���ľ��Ȼ���Լ�ȥ���ɡ�.\n");
            		me->set_temp("gumu/����",1);
            		return 1;
            	}
            	else
            	{
            		command("say ������ʦ��ĵ��ӣ��Ҹ���Ҫ�����㣿.\n");
            		return 1;
            	}
        }
        else
        {
        	return 1;
        }
}
string ask_suo()
{
	object me=this_player();
	object obn;
	mapping myfam;
	if (query("count") < 1)
		return "�������ˣ��������Ѿ�����ȡ���ˡ�\n";

	if(me->query_temp("������",1))
		return "���Ǹ���������\n";
		
	 myfam = (mapping)me->query("family");
        if(myfam && myfam["family_name"] == "��Ĺ��")
       	if(myfam["generation"] == 4)
            {
            	if(me->query("class")==!"taoist")
            	{
            		obn=new("/d/gumu/obj/jinling-suo");
            		obn->move(me);
            		add("count", -1);
            		me->set_temp("������",1);
            		return "�������������͸���ѡ�";
            	}
            	else
            	{
            		command("say ������ʦ��ĵ��ӣ��Ҹ���Ҫ���㣿.\n");
            		return 0;
            	}
        }
        else
        {
        	return 0;
        }
}	
string ask_shoutao()
{
	object me=this_player();
	object obn;
	mapping myfam;
	if (query("count") < 1)
		return "�������ˣ���˿�����Ѿ�����ȡ���ˡ�\n";

	if(me->query_temp("��˿����",1))
		return "���Ǹ���������\n";
		
	 myfam = (mapping)me->query("family");
        if(myfam && myfam["family_name"] == "��Ĺ��")
       	if(myfam["generation"] == 4)
            {
            	if(me->query("class")==!"taoist")
            	{
            		obn=new("/d/gumu/obj/jinsi-shoutao");
            		obn->move(me);
            		add("count", -1);
            		me->set_temp("��˿����",1);
            		return "��˫��˿���׾��͸���ɡ�\n";
            	}
            	else
            	{
            		command("say ������ʦ��ĵ��ӣ��Ҹ���Ҫ���㣿.\n");
            		return 0;
            	}
        }
        else
        {
        	return 0;
        }
}	
string ask_zhen()
{
	object me=this_player();
	object obn;
	mapping myfam;
	if (query("yfzhen") < 1)
		return "�������Ѿ�û��������ˡ�\n";

	 myfam = (mapping)me->query("family");
        if(myfam && myfam["family_name"] == "��Ĺ��")
       	if(myfam["generation"] == 4)
            {
            	if(me->query("class")==!"taoist")
            	{
            		obn=new("/d/gumu/obj/yfzhen");
            		obn->move(me);
            		add("yfzhen", -1);
            		return "��Щ�������͸���ɡ�\n";
            	}
            	else
            	{
            		command("say ������ʦ��ĵ��ӣ��Ҹ���Ҫ���㣿.\n");
            		return 0;
            	}
        }
        else
        {
        	return 0;
        }
}	
        
           
