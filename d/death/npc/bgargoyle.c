// bgargoyle.c
#include <ansi.h>
#include <command.h>
#include <login.h>
inherit NPC;
int ask_me();
int is_ghost(){	return 1;}
string *death_msg = ({
	HIB "���޳�˵����ι�������ģ����ʲô���֣�\n\n" NOR,
	HIB "���޳���������۹ⶢ���㣬����Ҫ�������һ���Ƶġ�\n\n" NOR,
	HIB "���޳����ߡ���һ�����������ͳ�һ�����ʲ�Ķ�����������\n\n" NOR,
	HIB "���޳����ϲ��ӣ�˵�����ף�����δ������ô���ܣ�\n\n" NOR,
	HIB "���޳�ɦ��ɦͷ��̾�������˰��ˣ����߰ɡ�\n\n"
		"һ�������Ũ��ͻȻ���֣��ܿ�ذ�Χ���㡣\n\n" NOR,
});
void create()
{
	set_name("���޳�", ({ "black gargoyle", "gargoyle" }) );
	set("long",
		"���޳�������������ͷ�����㣬��ڵ����Ͽ������κ�ϲŭ���֡�\n");
	set("attitude", "peaceful");
	set("chat_chance", 15);
	set("chat_msg", ({
		"���޳�����һ����������������������������ע��������ʱ�򣬵�����һ�ۡ�\n",
		"���޳��ѳ�������ͷ��������������������Լ��ֺ��ֳ�����ָ��\n"
	}) );
	set("age", 217);
set("combat_exp", 2000000000);
set("max_jing", 1000000);
set("max_qi", 1000000);
set_skill("dodge", 4000);
set_skill("unarmed", 4000);
	set_temp("apply/armor", 60);
	set_temp("apply/damage", 20);
	set("no_die",1);		//������ɱ��������.
	set("inquiry", ([
		"��ɲ����"       : (: ask_me :),
	]));
	setup();
}
void init()
{
	::init();
	if( !previous_object()
	||	!userp(previous_object()) )
		return;
	call_out( "death_stage", 5, previous_object(), 0 );
}
void death_stage(object ob, int stage)
{
	int i;
	object *inv;
	if( !ob || !present(ob) ) return;
if( !ob->is_ghost() && userp(ob)) {
		command("say ι��������������ʲô��");
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
	inv = all_inventory(ob);
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
		"���Ȼ����ǰ�����һ����Ӱ����������Ӱ�ֺ����Ѿ�������\n"
		"�ܾ��ˣ�ֻ����һֱû������\n", environment(ob), ob);
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
//    if (my_fam["family_name"] != "������")          	
if (me->query("class",1) != "taoist")                	
		return notify_fail("�㲻�������ɵĵ��ӣ����ܵ�ɲ���ꡣ\n");
	if( already_age >= my_age)
		return notify_fail("�����ĵ�ɲ��������Ѿ������ˣ�\n");
	if( (int)me->query("max_neili") < 50)
		return notify_fail("�������������ɵ�ɲ����󷨣�\n");
	if(random(5) >= 2)
	{
                me->set_skill("force",me->query_skill("force",1)+10);
		me->add("con_improve_time", 1);
		me->add("max_neili", -50);
		me->set("already_age", my_age);
	        message("vision", HIY"ֻ�����޳��������еĿ�ɥ�����૵����˼��������ڵ������ͻȻ��\n" +
			"��һ�����磬�������ͷ������ֻ���û������Ǳ�������һ��ů���С����\n" +
			"���������ˣ�\n"NOR, me);
	}
	else
		message("vision", HIY"ֻ�����޳��������еĿ�ɥ�����૵����˼���������ʲôҲû������\n"NOR, me);
	return 1;
	
}