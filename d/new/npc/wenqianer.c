// wenqianer.c

inherit NPC;
inherit F_DEALER;	
//    inherit F_BANKER;       	
void create()
{
	set_name(HIB"静静"NOR,({ "wenqianer" }) );
  set("title",HIM"紫云玄女"NOR);
 set("nickname",HIC"碧玉清心"NOR);
      set("gender", "女性" );
        set("age", 24);
        set("long", 
CYN"她清丽脱俗，眉目间略带幽思，更显出其绝代风华！\n");
create_family("碧云山庄",3,"二庄主");	
 set("max_qi", 3000000);
  set("max_jing", 3000000);
  set("neili", 3000000);
	set("max_jingli", 50000);
set("max_neili", 50000);
set("jingli", 3000000);
set("combat_exp", 500000000);
//        set("shen", 0);
	       set("str", 24);
       set("dex", 23);
         set("con", 20);
      set("per", 30);
  set("int", 24);
set("inquiry", ([	
"name" : "我是静静呀。",          	
//"龙吟古剑" : "这个啊... 是当年龙云梦的佩剑。",                	
"紫旋披风" : "你问这个干嘛啊？就不告诉你。哼...",                	
"静静" : "就是我啊！",    	
"碧云山庄" : "武林四大圣地之一，山庄高手如云，不知什么原因，及少见到他们在江湖上走动。",          	
//"龙云梦" : "他就是碧云山庄的大庄主，据说其武学造诣已经达到了天人合一的境界。",    
"纪嫣然" : "她是我的好妹妹，一个活泼好动的MM。想不想认识她啊？她呀！能说会道，可会逗人开心了。",          	
]) );	
        set("attitude", "friendly");
  set_skill("parry", 3500);
  set_skill("sword", 3500);
   set_skill("unarmed", 3500);
set_skill("force", 900);	
  set_skill("dodge", 3500);
set_skill("riyue-bian", 3500);
 set_skill("whip", 3500);
set_skill("qufeng",350);	
set_skill("literate", 3500);
 set_skill("qiankundanuoyi", 3500);
set_skill("xuantie-jianfa", 3500); 
 set_skill("liumai-shenjian", 3500);
set_skill("taixuan-gong", 900);	
 set_skill("yan-shuangfei", 3500);
 map_skill("force", "taixuan-gong");
map_skill("sword", "xuantie-jianfa");	
map_skill("parry", "xuantie-jianfa");
map_skill("dodge", "yan-shuangfei");
 map_skill("unarmed", "liumai-shenjian");
prepare_skill("sword", "xuantie-jianfa");	
set("chat_chance_combat", 100);  	
set("chat_msg_combat", ({
(: perform_action, "sword.haichao" :),
}));
 set("jiali",2625);
set("vendor_goods", ({	
"clone/misc/zhujingchan",		
"clone/misc/qsdan",
"clone/gift/shenliwan",               	
"clone/gift/xiandan",                 	
"clone/gift/xisuidan",                 	
"clone/gift/jiejue",                 	
"clone/gift/xianhai",                 	
"clone/gift/xianxing",                 	
"clone/drug/yydan",                 	
"clone/gift/unknowdan",                 	
}));	
  setup();
carry_object("clone/cloth/zixuan")->wear();	
carry_object("clone/cloth/lingyun")->wear();     	
carry_object("clone/cloth/fengting")->wear();     	
	carry_object("kungfu/class/taohua/obj/ruanwei")->wear();
	carry_object("clone/drug/yydan");
//           carry_object("clone/drug/huanyang");	
carry_object("d/gumu/obj/xuantiejian")->wield();	
carry_object("clone/weapon/longyin")->wield();          	
	
}

void init()	
{
add_action("do_list", "list");	
add_action("do_buy", "buy");	
/*
if (base_name(environment())!=this_object()->query("startroom")) return;	
add_action("do_check", "check");	
add_action("do_check", "cha");	
add_action("do_convert", "convert");	
add_action("do_convert", "huan");	
add_action("do_deposit", "deposit");	
add_action("do_deposit", "cun");	
add_action("do_withdraw", "withdraw");	
add_action("do_withdraw", "qu");	
*/
}	
int do_buy(string arg)
{
    int amount,once;
    string items,targ;
        if(sscanf(arg, "%d %s %d from %s",amount,items,once, targ)!=4 )
            if(sscanf(arg, "%d %s from %s",amount,items, targ)!=3 )
            if(sscanf(arg, "%s %d from %s", items,once,targ)!=3 )
        if( sscanf(arg, "%d %s %d",amount,items,once)!=3 )
                if(sscanf(arg, "%s from %s", items, targ)!=2 )
            if( sscanf(arg, "%d %s",amount,items)!=2 )
            if( sscanf(arg, "%s %d",items,once)!=2 )
                items=arg;
         if (amount>1 ) 
         	{ command("say 我忙着呢,你只一次买这么多想做弊吗。"); 
         	 return 1; 
         	 }
         	else return ::do_buy(arg);
}
