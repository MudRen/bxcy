 
//#include <npc.h>

//inherit F_VILLAGER;
inherit F_VENDOR;
inherit NPC;
int on_service = 0;

void create()
{
	set_name("С۪", ({ "xiao li", "li" }) );
        set("gender", "Ů��" );
        set("age", 18);
        set_temp("apply/attack", 25);
        set_temp("apply/defense", 25);
        set("combat_exp", 2000);
        set("mingwang", 10);
        set("str", 5);
        set("kar", 10);
        set("con", 8);
        set("int", 5);
        set("attitude", "friendly");
	set("long",
		"����С�������ã�һ��Լʮ�����С�����æ��æ����С��������\n"
		);
	set("chat_chance", 4);
	set("merchandise", ([
		"/u/caac/obj/tea": 50,
		"/u/caac/obj/dianxin": 50,
	]));

	setup();
}

void init()
{
	::init();
	add_action("do_vendor_list", "list");
}


/*int accept_fight(object ob)
{
	do_chat("С۪�˸�������˵��������Ҫ��ܵĻ����ҿɲ��Ƕ��֡�\n");
	return 0;
}*/

mixed affirm_merchandise(object customer, string item_name)
{
	if( on_service == 1)
		return notify_fail("С۪��æ���к��������ˣ������һ�����\n");
	//return ::affirm_merchandise(customer, item_name);
}

private void handover(object customer, mixed item)
{
	on_service = 0;
	if( !customer || environment(customer)!=environment() ) {
		command("say �ף��ո���λ�������أ������˲����� ...");
		say("С۪�Ѷ˳�����" + item->name() + "�ֶ��˻�ȥ��\n");
		return;
	}
	command("say ����" + item->name() + "������");
	message_vision("$N�Ѹմӳ����˳�����" + item->name()
		+ "�͵�$n��ǰ��\n", this_object(), customer);
	//::deliver_merchandise(customer, item);
}

void deliver_merchandise(object customer, mixed item)
{
	command("say " + item->name() + "�ǰɣ���������");
	say("С۪һ�����������һ�ߺ�����" + item->name() + "һ�ݣ�������\n");
	on_service = 1;
	//do_chat((: handover, customer, item :));
}
