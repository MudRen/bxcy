// yangguo.c 杨过
// By Kayin @ CuteRabbit Studio 99-4-16 21:10 new
#include <ansi.h>

inherit NPC;
inherit F_UNIQUE;
inherit F_MASTER;
int do_skills(string arg);
int do_kill(object me, object dest);
void create()
{
	set_name("杨过", ({ "yang guo", "yang" }));
	set("nickname", HIG "神雕大侠" NOR);
	set("gender", "男性");
	set("age", 30);
	set("int",30);
	set("con",30);
	set("str", 30);
	set("dex", 30);
	set("long", "他是一位高大的男子，相貌俊秀。\n"+
	"一只长袖空空如也，显是断了一臂，尽管如此，\n"+
	"仍然掩不住他迷人的风采。\n");
	set("combat_exp", 5000000);
	set("score", 10000);
	set("shen_type", 1);
	set("attitude", "peaceful");

	set_skill("sword", 350);
	set_skill("force", 400);
	set_skill("unarmed", 400);
	set_skill("dodge", 350);
	set_skill("parry", 350);
	set_skill("anranxiaohun-zhang",400);
	set_skill("quanzhen-jianfa", 350);
	set_skill("xiantian-gong", 400);
	set_skill("xianyun-bufa",350);
	map_skill("sword", "quanzhen-jianfa");
	map_skill("parry", "anranxiaohun-zhang");
	map_skill("unarmed","anranxiaohun-zhang");
	map_skill("dodge", "xianyun-bufa");

	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/armor", 40);
	set_temp("apply/damage", 100);
	set("neili", 5000); 
	set("max_neili", 5000);
	set("jiali", 100);
        set("inquiry", ([
                "小龙女" : "她就在小屋里。\n",
       ]) );
       create_family("古墓派", 3, "弟子");
	setup();
	carry_object("/clone/misc/cloth")->wear();
	add_money("gold", 2);
}

void init()
{
::init();
add_action("do_skills","skills");
add_action("do_skills","cha");
}

int recognize_apprentice(object ob)
{
    if (ob->query("shen")<50000) 
    {
    message_vision("$N摇了摇头说道，你的评价好像不是很好呀。\n",this_object());
    return 0;
	}
    if(!ob->query("couple/have_couple"))
    {
command("tell "+ob->query("id")+" 对不起，你还没有所爱的人，我不能教你。\n"); 
	return 0;
}
    return 1;	
}
int do_skills(string arg)
{
   object ob ;
   ob = this_player () ;
   if( !arg || arg!="yang" )
     return 0;
  if (ob->query("shen")<50000)
  {
   message_vision("$N摇了摇头说道，你的评价不怎么好吧！\n",this_object());
   return 1;
   }
   command("tell "+ob->query("id")+" 我所有的武功如下：\n"+
"□黯然消魂掌 (anranxiaohun-zhang)          - 深不可测 400/    0\n"+
"  基本轻功 (dodge)                         - 深不可测 350/    0\n"+    
"  基本内功 (force)                         - 深不可测 400/    0\n"+
"  基本拳脚 (unarmed)                       - 深不可测 400/    0\n"+
"  基本招架 (parry)                         - 深不可测 350/    0\n"+
"□全真剑法 (quanzhen-jianfa)               - 深不可测 350/    0\n"+
"  基本剑法 (sword)                         - 深不可测 350/    0\n"+
"  先天神功 (xiantian-gong)                 - 深不可测 400/    0\n"+
"□纤云步法 (xianyun-bufa)                  - 深不可测 350/    0\n");
return 1;
}

int do_kill(object me, object dest)
{
	if( objectp(dest) && present(dest, environment(me))
		 && !environment(me)->query("no_fight"))
	{
		message_vision(HIR "$N对$n说道：我一见邪派高手就生气。"
			+RANK_D->query_rude(dest)+"，纳命来！\n" NOR, me, dest);
		me->set_leader(dest);
		me->kill_ob(dest);
		dest->fight_ob(me);

		call_out("checking", 0,  me, dest);
	}
	else  
		call_out("waiting", 1, me, dest);
	
	return 1;
}
