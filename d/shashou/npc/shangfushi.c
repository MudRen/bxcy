// sgangfyshi.c 赏罚使

#include <ansi.h>
#include "/quest/quest.h"
inherit F_UNIQUE;
inherit NPC;

int ask_me();

void create()
{
       seteuid(getuid());
	set_name("黑白子", ({ "heibai zi", "zi" }) );
         set("nickname", HIM "冷面" NOR);
	set("gender", "男性");
	set("age", 48);
	set("long",
		"只见他昂然而立，青袍短须，容貌清癯，\n");
set("combat_exp", 1200000000);
	set("shen_type", 1);
	set("attitude", "peaceful");

set("max_qi", 2000000);
//           set("eff_qi", 300);^M	
//            set("qi", 300);^M	
set("max_jing", 1000000);
//             set("jing", 200);^M	
set("neili", 10000000);
set("max_neili", 2000);
set("jiali", 25000);

set_skill("unarmed", 1200);
set_skill("force", 2700);
set_skill("parry", 1200);
set_skill("dodge", 1300);
set_skill("strike",1500);
set_skill("wuji-shengong",1800);
set_skill("fanyun-zhang",1200);
set_skill("bugui-bufa",1200);

	
	map_skill("force", "wuji-shengong");
	map_skill("dodge", "bugui-bufa");
	map_skill("parry", "fanyun-zhang");
	map_skill("strike", "fanyun-zhang");
map_skill("unarmed", "fanyun-zhang");

	
	create_family("杀手楼", 2, "杀手");
	set("title","杀手楼赏罚使");

            set("no_get",1);
	set("inquiry", ([
                "职位" : (: ask_me :),
	]));

set("chat_chance_combat", 300);		
set("chat_msg_combat", ({	
(: perform_action, "blade.shaqi" :),	
(: perform_action, "unarmed.yunkai" :),     		
(: exert_function, "recover" :),	
}) );	
	setup();

}

int ask_me()
{
        object me;
	mapping fam;
	me=this_player();
        fam = me->query("family");

	if ( ((string)me->query("family/family_name") == "" ) || 
		( (string)me->query("family/family_name") != "" &&
		(string)me->query("family/family_name") != "杀手楼" ) )
	{
		message_vision("黑白子对$N说道：你不是本帮的人，帮内事务怎能告诉你？\n", me);
		return 1;
	}

if ( (int)me->query("combat_exp") < 10000000 )
	{
		message_vision("黑白子对$N说道：你对本帮的贡献还不够，以后再说吧。\n", me);
		return 1;
	}
	message_vision("黑白子对$N说道：你对本帮的贡献不小，先在就提升你做本帮的护法吧。\n", me);
if ( (int)me->query("combat_exp") >= 1500000000 )       	
{
me->set("title","杀手楼金衣杀手");	
return 1;	
}
if ( (int)me->query("combat_exp") >= 1000000000 )	
{
me->set("title","杀手楼银衣杀手");
return 1;	
}
if ( (int)me->query("combat_exp") >= 500000000 )
	{
                me->set("title", "杀手楼红衣杀手");
		return 1;
	}
if ( (int)me->query("combat_exp") >= 200000000 )
	{
               me->set("title","杀手楼青衣杀手");
		return 1;
	}
if ( (int)me->query("combat_exp") >= 100000000 )
	{
                me->set("title","杀手楼黄衣杀手");
		return 1;
	}
if ( (int)me->query("combat_exp") >= 50000000 )
	{
                me->set("title","杀手楼蓝衣杀手");
		return 1;
	}
if ( (int)me->query("combat_exp") >= 10000000 )
	{
                me->set("title","杀手楼白衣杀手");
		return 1;
	}
	return 1;
}

