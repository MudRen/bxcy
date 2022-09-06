// sleepbag.c

void wakeup(object,object);

#include <ansi.h>
inherit ITEM;

void create()
{
    set_name(HIR"˯��"NOR, ({ "sleep bag","bag"}) );
        set_weight(1500);
        set_max_encumbrance(8000);
        seteuid(ROOT_UID);
        if( clonep() )
                set_default_object(__FILE__);
        else {
          set("unit", "ֻ");
          set("long", "����һֻ��ͨ����֯˯����������ʿ��������Ұ��¶�ޡ�\n");
          set("value", 1000);
        }
}

int is_container()      {return 1;}

int init()
{
    add_action("do_sleep", "sleep");
}

int do_sleep(object me, string arg)
{
        int rnd;
        object where;
        mapping fam;
        me = this_player();

        where = environment(me);
        

        seteuid(getuid());

        if (me->is_busy())
                return notify_fail("����æ���أ�\n");

        if( me->is_fighting() )
                return notify_fail("ս���в���˯����\n");

        if (where->query("sleep_room"))
        {
                write("��������һ�ɣ���ʼ˯����\n");
                write("��һ�������ͽ��������硣\n");
                me->set_temp("block_msg/all",1);
                message_vision("$Nһ�������ڴ��ϣ���һ����������������������硣\n",me);
            rnd = random((20 - me->query_con()) / 3);
        }
        else { 
                write("��չ��һ��˯�����˽�ȥ����ʼ˯����\n");
                write("��һ�������ͽ��������硣\n");
                me->set_temp("block_msg/all",1);
                message_vision("$Nչ��һ��˯�����˽�ȥ����һ�����������������������\n",me);
            rnd = random((100 - me->query_con()) / 3);
        }
        where->set("no_fight", 1);
        where->add_temp("sleeping_person", 1);
        me->set("no_get", 1);   
        me->set("no_get_from", 1);      
        
        if (!(where->query("hotel"))) 
                me->set_temp("sleeped",1);
        else
                me->delete_temp("rent_paid");

        //me->disable_player("<˯����>");
         "/cmds/adm/bag"->main(me,"<��Ϣ��>");

        if ( rnd < 1 ) rnd = 0;
        call_out("wakeup",10, me, where);
        
        return 1;
}

void wakeup(object me,object where)
{
        me->set("qi",    me->query("eff_qi"));
        me->set("jing",  me->query("eff_jing"));
        me->add("neili", me->query("max_neili")/2 - me->query("neili")/2 );
        me->enable_player();
  
        message_vision("$Nһ����������������ػ��һ�½�ǡ�\n",me);
        me->set_temp("block_msg/all", 0);
        write("��һ��������ֻ���������档�ûһ���ˡ�\n");

        if (!where->query("sleep_room") && !where->query("hotel"))
                where->delete("no_fight");
     
        where->add_temp("sleeping_person", -1);
        me->delete("no_get");   
        me->delete("no_get_from");      

}
int query_autoload() { return 1; }
