// bai.百晓生
inherit NPC;
inherit F_MASTER;
int ask_lunjian(string str);		
int ask_kaiqi(string str);            	
void create()
{
set_name("百晓生", ({"bai xiaosheng", "bai", "xiaosheng"}));
set("nickname", "武林神话");
set("gender", "男性");
set("age", 35);
set("long", 
"一代奇才,武林中的不败神话.无所不知,无所不能.功盖宇内.被誉为华山论剑权威主持人.\n");
set("attitude", "peaceful");
set("str", 100);
set("int", 100);
set("con", 100);
set("dex", 100);
set("breakup", 1);	
set("neili", 35000000);
set("max_neili", 5000);
set("jiali", 50000);
set("max_jingli", 50000);	
set("jingli", 100000);	
set("max_qi", 3500000);	
set("max_jing", 3500000);	
set("combat_exp", 1500000000);
set_skill("sword", 3500);	
set_skill("dodge", 3500);	
set_skill("parry", 3500);	
set_skill("unarmed", 3500);	
set_skill("force", 3500);	
set_skill("jiuyang-shengong", 3500);	
set_skill("anranxiaohun-zhang", 3500);	
set_skill("douzhuan-xingyi", 3500);	
set_skill("qufeng", 3500);     	
set_skill("qimen-wuxing", 3500);     	
set_skill("yan-shuangfei", 3500);	
set_skill("taiji-jian", 3500);	
map_skill("dodge", "yan-shuangfei");	
map_skill("force", "jiuyang-shengong");	
map_skill("unarmed", "anranxiaohun-zhang");	
map_skill("parry", "douzhuan-xingyi");	
map_skill("sword", "taiji-jian");	
set("inquiry", ([
"华山论剑" : (: ask_lunjian :),	
"召开论剑" : (: ask_kaiqi :), 	
]));
create_family("天魔宫", 1, "宫主");
set("chat_chance_combat", 300);	
set("chat_msg_combat", ({	
(: perform_action, "sword.chanup" :),	
(: perform_action, "sword.lianup" :),	
(: exert_function, "recover" :),	
}) );	
setup();
carry_object("/d/lingxiao/obj/ganjiang")->wield();	
carry_object("/d/flypproom/wuping/tianmojie")->wear(); 	
carry_object("/d/city/npc/cloth/feature")->wear();  	
carry_object("/clone/npc/obj/battle_armor")->wear();   	
}
int ask_lunjian(string arg)		
{
object me;	
object bai;		
me = this_player();	
bai=this_object(); 		
if ( !bai->query("kaishi"))
{
command("say 现在没有举行华山论剑!");         	
return 1;		
}
if (me->query("age",1) < 18 )
{
command("say 你的江湖阅历还不够，多磨练两年再来吧!");	
return 1;	
}
message_vision(CYN "一阵旋风过后,$N的身影已然不见。\n" NOR,me); 	
me->move("/d/huashan/huashanjueding");
message_vision(CYN "$N的身影突然出现在旋风中。\n" NOR,me);   
return 1;	
}
int ask_kaiqi(string arg)             	
{
object me;      	
object bai;              	
bai=this_object();              	
me = this_player();     	
if ( !wizardp(me) ) 
{
command("say 只有巫师才能开启华山论剑。");	
return 1;	
}
if (bai->query("kaishi"))
{
command("say 华山论剑正在举行。");      	
return 1;       	
}
message("channel:chat", HIY"【华山论剑】"+HIM"华山绝顶举行论剑大会,五分钟后正式开始,各位江湖朋友速来报名参加！\n"NOR,users() );                     	
call_out("kaishi", 120, this_object());  	
bai->set("kaishi",1);
return 1;	
}
void kaishi(object bai)   	
{
message("channel:chat", HIY"【华山论剑】"+HIM"距离开始时间还有三分钟,参加华山论剑的朋友赶快前来报名！\n"NOR,users() );                  	
call_out("yubei", 120, this_object());           	
}
void yubei(object bai)       	
{
message("channel:chat", HIY"【华山论剑】"+HIM"还剩最后一分钟,参加华山论剑的朋友再不报名就没机会了！\n"NOR,users() );             
call_out("zhuyi", 60, this_object());           	
}
void zhuyi(object bai)       	
{
message("channel:chat", HIY"【华山论剑】"+HIM"华山论剑停止报名,正式开始！\n"NOR,users() );        		
bai->delete("kaishi");
}
