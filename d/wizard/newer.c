inherit NPC;
#include <ansi.h>

#define NEWS_OB "/feature/news"

string do_say();
int do_news(string);

string *rnd_say = ({
	"我忽然好想去滑冰.",
	"今天有没有上bbs？有好新闻哟!",
	"为什么大家都不理我?！",
	"可不可以告诉我哪里有杀人？",
	"今天我心情不大好, 大家可要小心了.",
	"今晚有人跳舞吗?",
	"谁想讲个故事？",
	"现在几点了？",
	"为什么不说话呢?",
	"为什么不回去睡觉呢?",
	"谁想去看电影?",
	"我可以出去杀人吗?",
	"我对MUD根本没什么好感.",
	"我对足球根本没什么兴趣.",
	"我好象很苯耶.",
	"今晚有人请客吗?",
	});

void create()
{
set_name(HIM "新闻发布使" NOR, ({"newer"}));              	
	set("gender", "女性");
	set("age", 21);
	set("rank_info/respect", "小姑娘");
	set("max_qi", 10000);
	set("max_jing", 10000);
	set("neili", 5000);
	set("max_neili", 5000);
	set("jiali", 100);
	set("inmortal",1);
	set("age", 20);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 50);
	set("int", 50);
	set("con", 50);
	set("dex", 50);
	set("no_get_from", 1);

        set("chat_chance",30);
	set("chat_msg", ({
		(: do_say :),
	}) );
	set("combat_exp", 3000000);
	set("shen_type", 1);
	set("score", 5000000);
	setup();
carry_object("/clone/cloth/zixuan")->wear();	
carry_object("/clone/weapon/longyin")->wield();	
	if( clonep() ) CHANNEL_D->register_relay_channel("chat");
}

void init()
{
	if(wizardp(this_player()))
		add_action("do_news","news");
}

void die()
{
	message_vision("抱歉，我是不会死的。\n",this_object());
	return ;
}

string do_say()
{
	int i=random(sizeof(rnd_say));
	if(random(5)>4)
		do_news("random");
	return rnd_say[i];
}

void relay_channel(object ob, string channel, string msg)
{
	if( !userp(ob) || (channel != "chat") ) return;

	if( ob==this_object() ) return;

	if(random(11)>10)
		do_news("random");
}

int do_news(string num)
{
	object newob,*alluser;
	string msg;
	int i;
	newob=new(NEWS_OB);
	if(num&&num!="random"&&sscanf(num,"%*d")==1)
		msg=NOR+"〖"HIG"江湖新闻"NOR"〗(NEWS)："+HIG+newob->query_news(num)+NOR;
	else
		msg=NOR+"〖"HIG"江湖新闻"NOR"〗(NEWS)："+HIG+newob->query_news()+NOR;
	alluser=users();
	if(pointerp(alluser))
	{
		for(i=0;i<sizeof(alluser);i++)
		{
			if(alluser[i]->query("env/nonews")==0)
				tell_object(alluser[i],msg);
		}
	}
	return 1;
}
