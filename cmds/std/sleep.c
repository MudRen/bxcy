// sleep.c

void wakeup(object,object);
void del_sleeped(object);
int main(object me, string arg)
{
    int rnd;
        object where = environment(me);
        
        seteuid(getuid());
        if (where->query("no_sleep_room")
        || ( ( me->query("family/family_name") != "ؤ��") && (!(where->query("sleep_room")))) )
             return notify_fail("���ﲻ������˯�ĵط���\n");

   
        if (me->is_busy())
                return notify_fail("����һ������δ��ɣ�\n");
        if( me->is_fighting() )
                return notify_fail("ս����˯��������ѽ��\n");
        
 
        if (me->query_temp("sleeped"))
                return notify_fail("���˯��һ��, ��˯�������к�����! \n");
        if (where->query("sleep_room"))
        {
                write("��������һ�ɣ���ʼ˯����\n");
                write("��һ�������ͽ��������硣\n");
                message("vision",me->name()+"һ�������ڴ��ϣ���һ����������������������硣\n",environment(me),({me}));
          rnd=random(100/me->query_con()+3);
        }else{ 
                write("�������½���һ�ɣ���ʼ˯����\n");
                write("��һ�������ͽ��������硣\n");
                message("vision",me->name()+"�����½�������һ�ɣ���һ�����������������������\n",environment(me),({me}));
                rnd=random(100/me->query_con()+2);
        }
        where->add_temp("sleeping_person", 1);
        me->set("no_get", 1);   
        me->set("no_get_from", 1);      
        me->set_temp("block_msg/all", 1);

        me->set_temp("sleeped",1);
        me->disable_player("<˯����>");
        if ( rnd < 1 ) rnd = 0;
        call_out("wakeup", rnd + 10, me, where);
        
        return 1;
        
}
void wakeup(object me,object where)
{
        while( environment(me)->is_character() )
                me->move(environment(environment(me)));
        me->enable_player();
    me->set_temp("block_msg/all",1);
    me->move(environment(me));
        me->delete_temp("block_msg");
        if ( userp(me) && (!me->query("food") || !me->query("water")) ){
                message("vision",me->name()+"һ��������������������ģ�û�а�㾫��\n",environment(me),({me}));
                write("��һ��������������������ģ�û�а�㾫�񡣿�����Ҫȥ�ҵ�Ե��ˣ�\n");
        }else{
        message("vision",me->name()+"һ����������������ػ��һ�½�ǡ�\n",environment(me),({me}));
        write("��һ��������ֻ���������档�ûһ���ˡ�\n");
        me->set("qi",    me->query("eff_qi"));
        me->set("jing",  me->query("eff_jing"));
        }  
        call_out("del_sleeped", 5, me);
    if (where)
        where->add_temp("sleeping_person", -1);
        me->delete("no_get");   
        me->delete("no_get_from");      
 
}
void del_sleeped(object me)
{
        if (objectp(me) &&  me->query_temp("sleeped"))
                me->delete_temp("sleeped");
}

