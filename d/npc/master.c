        set("inquiry", ([
                "��ʦ": "Ŷ....�Ϸ������и���أ����������Ϊʦ�ģ��ý������в�������������(accept 
test)��\n"
        ]) );

void init()
{
        ::init();
        add_action("do_accept", "accept");
}


int do_accept(string arg)
{
	object me=this_object();
	object ob=this_player();
    if( arg== "test" ) {
		say("\n"+me->name()+"���˵�ͷ��˵�����ܺã����ǵ�һ��....\n\n");
		COMBAT_D->do_attack(me, ob,me->query_temp("weapon"));
		call_out("do_accept2",0,me,ob);
		return 1;
	}
	return 0;

}
int do_accept2(object me,object ob)
{
	if (!me)	return 1;
	if (!ob){
		say("\n"+me->name()+"̾�˿�����˵��������һ�ж��Ų����������Բ�����....\n");
		return 1;
	}
	if( (int)ob->query("qi") < 0 || !present(ob, environment(me))) {
		say("\n"+me->name()+"̾�˿�����˵��������һ�ж��Ų����������Բ�����....\n");
		return 1;
	}
	say("\n"+me->name()+"˵�������ǵڶ���....\n\n");
	COMBAT_D->do_attack(me, ob,me->query_temp("weapon"));
	call_out("do_accept3",0,me,ob);
	return 1;
}
int do_accept3(object me,object ob)
{
	if (!me)	return 1;
	if (!ob){
		say("\n"+me->name()+"���ߡ���һ����˵��������������಻�����ļһ�....\n");
		return 1;
	}
	if( (int)ob->query("qi") < 0 || !present(ob, environment(me))) {
		say("\n"+me->name()+"���ߡ���һ����˵��������������಻�����ļһ�....\n");
		return 1;
	}
	say("\n"+me->name()+"˵��������������....\n\n");
	COMBAT_D->do_attack(me, ob,me->query_temp("weapon"));
	call_out("do_accept4",0,me,ob);
	return 1;
}
int do_accept4(object me,object ob)
{
	if (!me)	return 1;
	if (!ob){
		say("\n"+me->name()+"̾������ϧ!��ϧ....\n");
		return 1;
	}
	if( (int)ob->query("qi") < 0 || !present(ob, environment(me))) {
		say("\n"+me->name()+"���ߡ���һ��������"+ob->name(1)+"��Ҫ����ʮ��....\n");
		return 1;
	}

}
