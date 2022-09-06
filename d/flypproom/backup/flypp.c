// flypp.c 飞天
// FLYPP 2003/10/17
inherit NPC;
void create()
{
set_name("飞天", ({ "flypp" }));
set("title",HIM"紫电神君"NOR);
 set("nickname",HIC"独孤求败"NOR);
set("long", "他是飞天楼的楼主。据说飞天楼是一个神秘的组织，创始人飞天的武功无人能敌！但是却从来没听说过飞天楼的人出来江湖走动，奇怪，奇怪。。。\n");	
set("gender", "男性");
set("age", 22);
set("attitude", "friendly");
set("shen_type", 0);
set("str", 35);
set("int", 35);
set("con", 35);
set("dex", 35);
set("max_qi", 2000000);
set("max_jing", 2000000);
set("max_jingli", 10000);
set("max_neili", 500000);
set("neili", 3500000);
set("jiali", 20000);
set("combat_exp", 1000000000);
set("score", 35000);                                 
set_skill("literate", 35000);
set_skill("unarmed", 3500);
set_skill("dodge", 3500);
set_skill("sword", 3500);
set_skill("parry", 3500);
set_skill("force", 3500);
set_skill("adai-quanfa", 3500);
set_skill("yan-shuangfei", 3500);
set_skill("jiuyang-shengong", 3500);
set_skill("douzhuan-xingyi", 3500);
set_skill("mantianhuayu", 3500);
set_skill("riyue-bian", 3500);
set_skill("qufeng", 3500);
set_skill("taoism", 3500);
set_skill("pixie-jian", 1000);
set_skill("qimen-wuxing", 3500);
set_skill("wuming-jianfa", 2000);
map_skill("throwing", "mantianhuayu");
map_skill("sword", "wuming-jianfa");       map_skill("parry", "douzhuan-xingyi");       map_skill("force", "jiuyang-shengong");       map_skill("unarmed", "adai-quanfa");      map_skill("dodge", "yan-shuangfei");
prepare_skill("unarmed", "adai-quanfa");	
set("chat_chance_combat", 50);  	
set("chat_msg_combat", ({
(: perform_action, "sword.moming" :),
(: perform_action, "unarmed.aiai" :),
(: exert_function, "recover" :),
}));
set("inquiry", ([	
"name" : CYN "我就是飞天楼楼主 "HIG" 飞天。" NOR,	
"飞天楼" : BLU "嘿嘿,想入我飞天楼可不是那么容易的事!" NOR, 
"龙云梦" : HIC "不会吧,一个白痴也值得问吗???,呵呵，也许你比他还白痴:) \n $N「哈哈哈」大笑几声。" NOR, 
"冰雁" : HIM "嘻嘻,一个傻傻的小女孩,不过挺可爱的:)" NOR,
"挑战" : HIR "没点本事可别来丢人现眼啊...这可是有生命危险的,挂了可别哭!" NOR,
"奖品" : HIW "夕阳的精华都在我身上，你有本事打死我就可以得到:)" NOR,	
"专用擂台" : HIR "这个是飞天楼专用擂台，可以打死人的，擂台下面可以拣尸体，记得打死我之后要下去拣你的战利品哦~" NOR,
]) );
setup();
carry_object("/clone/money/coin")->wield();
carry_object("/clone/weapon/yuenv")->wield();	
carry_object("/clone/cloth/zixuan")->wear();	
carry_object("/clone/cloth/lingyun")->wear();	
carry_object("/clone/cloth/fengting")->wear();
carry_object("/clone/cloth/qiankun")->wear();
carry_object("/clone/weapon/huolin")->wear();
carry_object("/d/flypproom/wuping/tianmojie")->wear();
carry_object("/d/flypproom/wuping/baiyushouzhuo")->wear();
carry_object("/d/taishan/obj/pie");
carry_object("/clone/weapon/longyin");
add_money("thousand-gold",10);	
add_money("coin",20);
}
void init()
{
object ob;
::init();
if (interactive(ob = this_player()) && !is_fighting()) {
remove_call_out("greeting");
call_out("greeting", 1, ob);
add_action("do_sell", "sell");
}
}
void greeting(object me)
{
if (!me || environment(me) != environment() ) return;
command("look " + me->query("id"));
/*
if (me->query("id")=="wenwu") {
command("say 呵呵，骂你不服气吗? 来单挑哈:)！");             		
command("kok wenwu");                                  	
command("kick wenwu"); 
*/
/*
if (me->query("id")=="lisa") {
command("say 小妹妹,来看哥哥了啊,乖哦:)！");             		
command("kiss lisa");                                  	
command("ppp lisa");
*/
/*
if (me->query("id")=="loveall") {
command("say 呵呵,好像,好像,实在太像了");             		
*/
if (me->query("id")=="caixiamantian") {
command("say 你也算一代奇才了,可惜仍然不及我万一！"); 
command("sigh");                                   	
}
return ;
}
