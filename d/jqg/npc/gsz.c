// gsz.c 公孙止
// By River 99.5.25
#include <ansi.h>
inherit NPC;
string ask_gu();
void create()
{
	set_name("公孙止", ({ "gongsun zhi", "gongsun", "zhi" }));
	set("long","面目英俊，透出轩轩高举之概，只是面色蜡黄，容颜枯槁。\n");
        set("title",HIW"绝情谷谷主"NOR);
	set("gender", "男性");
	set("age", 45);
	set("attitude", "friendly");
	set("shen", -3000);
	set("str", 25);
	set("int", 24);
	set("con", 28);
	set("dex", 26);
        set("per", 20);
        set("unique", 1);

set("max_qi", 500000);	
set("max_jing", 150000);	
set("neili", 3000000);	
set("max_neili", 1500); 	
set("jiali", 5000);	
set("combat_exp", 300000000);	
 
set_skill("force", 1250);      	
set_skill("dodge", 1250);	
set_skill("parry", 1250);	
set_skill("guiyuan-tunafa", 1250);	
set_skill("literate", 1220); 	
set_skill("art", 900);    	
set_skill("shuishangpiao", 1250);	
set_skill("tiezhang-zhangfa", 1250);	
set_skill("strike",1250);	
set_skill("sword", 1250);	
set_skill("liangyi-jian", 1100);	

        map_skill("force", "guiyuan-tunafa");
        map_skill("dodge", "shuishangpiao");
        map_skill("strike", "tiezhang-zhangfa");
map_skill("unarmed", "tiezhang-zhangfa");	
        map_skill("parry", "liangyi-jian");
	map_skill("sword", "liangyi-jian");
        prepare_skill("strike", "tiezhang-zhangfa");

        set("inquiry", ([
            "绝情丹": "丹药无多，而且也很难炼制，非万不得已。。。",
            "绝情谷": (: ask_gu :),
        ]) );
set("chat_chance_combat", 200);	
set("chat_msg_combat", ({	
(: perform_action, "sword.feixue" :),	
(: perform_action, "sword.jianqin" :),	
(: perform_action, "sword.juedi" :),	
(: perform_action, "sword.ren" :),	
(: perform_action, "unarmed.tianlei" :),	
(: perform_action, "unarmed.tiezhangxianglong" :),	
(: perform_action, "unarmed.zhangdao" :),	
(: exert_function, "recover" :),	
}) );	
	setup();
	carry_object("/clone/weapon/gangjian")->wield();
	carry_object("/clone/misc/cloth")->wear();
}

string ask_gu()
{
       object me,ob;
       me=this_object();
       ob=this_player();
       if(ob->query("combat_exp") < 200000)
         return RANK_D->query_respect(ob)+"功夫还太弱，绝情谷中甚为危险，还是不要在此久留了。";      
         ob->set_temp("gsz_agree", 1);
         return RANK_D->query_respect(ob)+"既然对绝情谷甚有兴趣，就请随便看看吧。";
}
