// long.c 小龙女
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
	set_name("小龙女", ({ "xiao long nu", "long" }));
	set("long",
		"披著一袭轻纱般的白衣，犹似身在烟中雾里，除了一头黑发之外，全身雪白，\n"+
"面容秀美绝俗，只是肌肤间少了一层血色.\n");
	set("gender", "女性");
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
	"重阳遗刻":(: ask_chongyang :),
	"玉女心经":(: ask_chongyang :),
	"密室":(: ask_jiuyin :),
	"九阴真经":(: ask_jiuyin :),
	"金铃索":(: ask_suo :),
	"金丝手套":(: ask_shoutao :),
	"玉蜂针":(: ask_zhen :),
	]));
	
	create_family("古墓派", 3, "掌门");
	setup();
	carry_object("/d/gumu/obj/jinling-suo")->wield();
	carry_object("/d/gumu/obj/jinsi-shoutao")->wear();
	carry_object("/d/gumu/obj/si_cloth")->wear();

}
void attempt_apprentice(object ob)
{
        mapping myfam;
       	 myfam = (mapping)ob->query("family");
        if(!myfam && myfam["family_name"] != "古墓派")
        {
        	command("say 对不起，我不收别派弟子。");
        	return;
        }
         
        if(ob->query("class")=="taoist")
		{
			command("say 你已经是我师姐的弟子了，你还来找我干嘛？");
			return;
		}
	if ((int)ob->query("shen") < 50000) {
		command("say 在德行方面，" + RANK_D->query_respect(ob) +
			"是否还做得不够？");
		return;
	}

	
	if( (int)ob->query_dex()< 30){
		command("say 你的身法太差.");
		return;
	}
	if( (int)ob->query_int() < 45){
		command("say 你的悟性太差。");
		return;
	}
	if((int)ob->query_skill("yunu-xinfa",1)< 100){
		command("say 你的玉女心法太差了。");
		return ;
	}
	if((int)ob->query_skill("tianluo-diwang",1)<100){
		command("say 你的天罗地网势火候不够。");
		return ;
	}
	if((int)ob->query_skill("xianyun-bufa",1)<100){
		command("say 你的纤云步法太生疏了。");
		return ;
	}
	if((int)ob->query("max_neili")< 1000){
		command("say 你的内功修为不够。");
		return ;
	}
	
			
        	command("say 好吧，我就收下你了。");
        	command("say 以后一定更不能做坏事。");
		command("recruit " + ob->query("id"));

}

int ask_chongyang()
{
	object me=this_player(1);
	mapping myfam;
	 myfam = (mapping)me->query("family");
        if(myfam && myfam["family_name"] == "古墓派")
            {
            	if(me->query("class")==!"taoist")
            	{
            		command("say 要先在大厅打开机关，再去打开暗门.\n");
            		me->set_temp("gumu/重阳",1);
            		return 1;
            	}
            	else
            	{
            		command("say 你是我师姐的弟子，我干嘛要告诉你？.\n");
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
        if(myfam && myfam["family_name"] == "古墓派")
            {
            	if(me->query("class")==!"taoist")
            	{
            		command("say 你去推开棺木，然后自己去看吧。.\n");
            		me->set_temp("gumu/九阴",1);
            		return 1;
            	}
            	else
            	{
            		command("say 你是我师姐的弟子，我干嘛要告诉你？.\n");
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
		return "你来晚了，金铃索已经给人取走了。\n";

	if(me->query_temp("金铃索",1))
		return "不是给过你了吗？\n";
		
	 myfam = (mapping)me->query("family");
        if(myfam && myfam["family_name"] == "古墓派")
       	if(myfam["generation"] == 4)
            {
            	if(me->query("class")==!"taoist")
            	{
            		obn=new("/d/gumu/obj/jinling-suo");
            		obn->move(me);
            		add("count", -1);
            		me->set_temp("金铃索",1);
            		return "这条金铃索我送给你把。";
            	}
            	else
            	{
            		command("say 你是我师姐的弟子，我干嘛要给你？.\n");
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
		return "你来晚了，金丝手套已经给人取走了。\n";

	if(me->query_temp("金丝手套",1))
		return "不是给过你了吗？\n";
		
	 myfam = (mapping)me->query("family");
        if(myfam && myfam["family_name"] == "古墓派")
       	if(myfam["generation"] == 4)
            {
            	if(me->query("class")==!"taoist")
            	{
            		obn=new("/d/gumu/obj/jinsi-shoutao");
            		obn->move(me);
            		add("count", -1);
            		me->set_temp("金丝手套",1);
            		return "这双金丝手套就送给你吧。\n";
            	}
            	else
            	{
            		command("say 你是我师姐的弟子，我干嘛要给你？.\n");
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
		return "我这里已经没有玉蜂针了。\n";

	 myfam = (mapping)me->query("family");
        if(myfam && myfam["family_name"] == "古墓派")
       	if(myfam["generation"] == 4)
            {
            	if(me->query("class")==!"taoist")
            	{
            		obn=new("/d/gumu/obj/yfzhen");
            		obn->move(me);
            		add("yfzhen", -1);
            		return "这些玉蜂针就送给你吧。\n";
            	}
            	else
            	{
            		command("say 你是我师姐的弟子，我干嘛要给你？.\n");
            		return 0;
            	}
        }
        else
        {
        	return 0;
        }
}	
        
           
