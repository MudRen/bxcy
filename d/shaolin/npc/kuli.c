// kuli.c ����
inherit NPC;
void create()
{
    set_name("����", ({ "zhao liu", "liu", "zhao" }));
    set("title", "�̲�����");
    set("nickname", "ˮ���");
    set("str", 37);
    set("gender", "����");
    set("age", 35);
    set("long",
        "�����̲�������һ��ֵ���С�����ٲ��󣬿�Ȩ��ȴ��С\n");
    set("combat_exp", 1500);
    set("attitude", "friendly");
    set("inquiry", ([
        "����" : "Ҫ�����ȵý�Ǯ��",   //��Ҫ30���ƽ�
    ]));
    
    setup();
    carry_object("/clone/misc/cloth")->wear();
//  carry_object("/d/shaolin/obj/qimeigun")->wield();
}
void init()
{
    object ob;
    
    ::init();
    if (interactive(ob = this_player()) && !is_fighting()) {
        remove_call_out("greeting");
        call_out("greeting", 1, ob);
    }
    add_action("do_betray","decide");
}
void greeting(object ob)
{
    if (!ob || environment(ob) != environment())
        return;
    switch(random(2)) {
    case 0 :
        say("����Ц���е�˵������λ" + RANK_D->query_respect(ob) +
            "���������Ъ�����ɡ�\n");
        break;
    case 1 :
        say("����˵����Ӵ����λ" + RANK_D->query_respect(ob) + 
            "�����˰�����Ҫ���������ʦ��¼��\n");
        break;
    }
}
int accept_object(object who, object ob)
{
    
        if(! (int)who->query("betrayer"))
        return notify_fail("����˵�������Ѿ�û����ʦ��¼��ѽ��\n");
    if (ob->query("money_id") && ob->value() >= 100000)
    {
        tell_object(who, "����Ц���е�˵�����ðɣ�ÿ���һ����ʦ��¼Ҫ��ȥ15%�ľ��顢���Ҹ��Ź���������\n");
        tell_object(who, "�㿼������˾������������ɡ�(decide)\n");
        who->set_temp("fee_paid",1);
        return 1;
    }
    else if (ob->query("money_id") && ob->value() < 300000) 
    {
        tell_object(who, "�����ٺ�һЦ��˵�������������Ǯ�� �����ҿ�û�����㰡��\n");
        return 1;
    }
    return 0;
}
int do_betray()
{
    int i, level, exper;
    object me;
    mapping skill_status;
    string *sname;
    me = this_player();
    if(! (int)me->query("betrayer"))
        return notify_fail("����˵�������Ѿ�û����ʦ��¼��ѽ��\n");
    if( !me->query_temp("fee_paid") ) 
        return notify_fail("���������˵�������ܽ�����ʲ�ᣬ���ɵ��ȸ�Ǯ�ģ�\n");
    me->add("betrayer", -1);
//       exper = me->query("combat_exp");	
//    exper += exper * 15 / 100;      	
//       if(exper <= 0)	
//           exper = 0;	
    if ( !(skill_status = me->query_skills()) )
    {
exper = ((me->query("combat_exp"))/100)*85;	
        me->set("combat_exp", exper);
        me->delete_temp("fee_paid");
        tell_object(me, "����Ц���е�˵������������ʦ��¼�����һ�Ρ�\n");
        me->unconcious();
        return 1;
    }
    sname  = keys(skill_status);
    for(i = 0; i < sizeof(skill_status); i++) 
    {
        level = skill_status[sname[i]] - 2;
        if(level <= 0)
            me->delete_skill(sname[i]);
        else
            me->set_skill(sname[i], level);
    }
exper = ((me->query("combat_exp"))/100)*85;	
    me->set("combat_exp", exper);
    me->delete_temp("fee_paid");
    tell_object(me, "����Ц���е�˵������������ʦ��¼�����һ�Ρ�\n");
    me->unconcious();
    return 1;
}
