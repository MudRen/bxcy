// wgargoyle.c
#include <ansi.h>
#include <command.h>
#include <login.h>
inherit NPC;
int ask_me();

int is_ghost(){	return 1;}
string *death_msg = ({
	HIW "白无常说道：喂！新来的，你叫什么名字？\n\n" NOR,
	HIW "白无常用奇异的眼光盯著你，好像要看穿你的一切似的。\n\n" NOR,
	HIW "白无常「哼」的一声，从袖中掏出一本像帐册的东西翻看著。\n\n" NOR,
	HIW "白无常合上册子，说道：咦？阳寿未尽？怎么可能？\n\n" NOR,
	HIW "白无常搔了搔头，叹道：罢了罢了，你走吧。\n\n"
		"一股阴冷的浓雾突然出现，很快地包围了你。\n\n" NOR,
});
void create()
{
	set_name("白无常", ({ "white gargoyle", "gargoyle" }) );
	set("long",
		"白无常伸著长长的舌头瞪著你，死白的脸上看不出任何喜怒哀乐。\n");
	set("attitude", "peaceful");
	set("chat_chance", 15);
	set("chat_msg", ({
		"白无常发出一阵像呻吟的声音，当他发现你正注视著他的时候，瞪了你一眼。\n",
		"白无常把长长的舌头伸出来，缓缓地舔了舔自己又白又长的手指。\n",
	}) );
	set("age", 217);
	set("no_die",1);
set("combat_exp", 2000000000);
set("max_jing", 1000000);
set("max_qi", 1000000);
set_skill("dodge", 4000);
set_skill("unarmed", 4000);
	set("inquiry", ([
		"天魔解体"       : (: ask_me :),
	]));
	setup();
}
void init()
{
	::init();
	call_out( "death_stage", 5,this_player(), 0 );
}
void death_stage(object ob, int stage)
{
	int i;
        object *inv,me;
	me = this_player();
	if( !ob || !present(ob) ) return;
if( !ob->is_ghost() && userp(ob)) {
		command("say 喂！阳人来阴间做什么？");
		kill_ob(ob);
		ob->fight_ob(this_object());
		return;
	}
	tell_object(ob, death_msg[stage]);
	if( ++stage < sizeof(death_msg) ) {
		call_out( "death_stage", 5, ob, stage );
		return;
	} else
		ob->reincarnate();
	
        inv =  all_inventory(ob);
        for (i = 0; i < sizeof(inv); i++)
                DROP_CMD->do_drop(ob, inv[i]);
ob->clear_condition();
ob->clear_condition(1);	
if(ob->query("block"))
ob->move("/clone/misc/block");
else    ob->move(REVIVE_ROOM);	
ob->delete_temp("last_damage_from");
ob->delete_temp("die_for");
ob->set("startroom","/d/city/wumiao");
	message("vision",
		"你忽然发现前面多了一个人影，不过那人影又好像已经在那里\n"
		"很久了，只是你一直没发觉。\n", environment(ob), ob);
	
}
int ask_me()
{
        mapping my_fam;
 
        object  me;
        int my_age, already_age;
	me = this_player();
        my_fam = (mapping)me->query("family");
	my_age = me->query("age");
	already_age = (int)me->query("already_age");
//            if (my_fam["family_name"] != "丐帮")	
if (me->query("class",1) != "beggar")
		return notify_fail("你不是丐帮的弟子，不能天魔解体。\n");
	if( already_age >= my_age)
		return notify_fail("你今年的天魔解体次数已经用完了！\n");
	if( (int)me->query("max_neili") < 50)
		return notify_fail("你的内力不够完成天魔解体大法！\n");
	if(random(5) >= 2)
	{
                me->set_skill("force",me->query_skill("force",1)+10);
		me->add("con_improve_time", 1);
		me->add("max_neili", -50);
		me->set("already_age", my_age);
	        message_vision(HIY"只见白无常举起手中的哭丧棒，喃喃地念了几局咒语，漆黑的天空中突然出\n" +
			"现一道闪电，击中你的头顶。你只觉得浑身象是被浸泡在一股暖流中。你的\n" +
			"体质提升了！\n"NOR, me);
	}
	else
		message_vision(HIY"只见白无常举起手中的哭丧棒，喃喃地念了几局咒语，结果什么也没发生！\n"NOR, me);
	return 1;
	
}
