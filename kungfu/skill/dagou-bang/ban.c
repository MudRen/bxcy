//ban.c �򹷰��������־�
// fear 12/99

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int perform(object me, object target)
{
                string* msgsuccess;
                string* msgfail;
                string* msgloop, msg;
                int random_text;
                int duration;
                int dodge;
                int speed;
                string weapon;
        int skill, att;
                int nskill;
                int ndamage;
        int hits;
        int i;
        int ban_count=0;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("���־�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( target->is_busy() ) {
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɢ�\n");
        }

        if( me->query_temp("ban",1) )
                return notify_fail("������ʹ�ð��־���\n");

        if( me->query_skill_mapped("force") != "huntian-qigong" )
                return notify_fail("�����õĲ��ǻ����������޷�ʩչ���־���\n");

        if( me->query_skill("huntian-qigong") < 199 )
                return notify_fail("��Ļ����������δ�����޷�ʩչ���־���\n");


        if( me->query_skill("dagou-bang") < 199 )
                return notify_fail("��Ĵ򹷰�����Ϊ���㣬������ʹ�ð��־���\n");

        skill =  ( me->query_skill("dagou-bang")
                + me->query_skill("huntian-qigong") ) / 5;

                nskill = ( me->query_skill("dagou-bang") ) /4;

                me->set_temp("apply/speed", me->query_temp("apply/speed",1)+skill*3/2);
                speed = target->query_temp("apply/speed",1);
                dodge = target->query_temp("apply/dodge",1);
                
        if( me->query("neili") <= skill*3 )
                return notify_fail("�����������ʹ�ð��־���\n");

        weapon = me->query_temp("weapon");

        if( me->query_skill("dagou-bang") < 300 ) { hits=3; }
        else if( me->query_skill("dagou-bang") < 400 ) { hits=4; }
        else if( me->query_skill("dagou-bang") < 500 ) { hits=5; }
        else { hits=6; }

                if( random(2)) {
                        message_vision(HIG "ͻȻ$N"+ weapon->name()+HIG"�ӳ����Դ򹷰��ġ����־��ŵ�ɨȥ�����糤����ӣ����������\n\n" NOR, me, target); }
                else {
                        message_vision(HIG "$N"+ weapon->name()+HIG"�����ʩչ�򹷰����ġ����־����������̣���ֻһ�������֣��м�ȴ�̲���ǧ���򻯡�\n\n" NOR, me, target);}


        for(i=0;i<=hits;i++) {
if (random(me->query("combat_exp")/10000) * me->query_skill("club") > (random((int)target->query("combat_exp")/10000) * target->query_skill("dodge") * (1-(((ban_count * 2)+50)/100)))) { 
                                        msgsuccess = ({
                                                "$n������������"+ weapon->name()+HIY"��������һ����������һ�����˵ص��ˡ�",
                                                "$n���㲻ס����"+ weapon->name()+HIY"����һ��������ˤ����",
                                                weapon->name()+HIY"�ڵ�һ�£�$n��ʱ���ֲ����������һ��ˤ����",
                                                weapon->name()+HIY"��Ȼ��ת������$n�Ľ��֡�$p���㲻�ȣ�һ�����ģ��˵ص�����"
                                        });
                        msg = HIY"\n"+ msgsuccess[random(sizeof(msgsuccess))] +"\n" NOR;
                                message_vision(msg, me, target);

                                if(nskill > 100) { ndamage=100;}
                                else {
                                        ndamage = nskill; }

                        ban_count++;
                        me->start_busy(1 + random(2));
                                target->start_busy(1 + random(2));
                        target->add("jing",-ban_count * ndamage);
                            target->add("qi",-me->query_skill("dagou-bang")/5);
                        target->add_temp("apply/dodge", -skill/10 );
                                target->add_temp("apply/speed", -skill/10 );
                }
                else
                {
                                        msgfail = ({
                                                "$n΢�о���Ϯ�����̣���æӿ��Ծ����������һ�С�",
                                                "$n��Ծ��ܣ���ʱ�㿪����һ�С�" ,
                                                "$n����Ծ�𣬱ܹ����⾪�յ�һ����",
                                                "$n��մ��𣬽����Ʊ�ΪԾ�ƣ����������¡�"
                                        });
                        msg = CYN"\n"+ msgfail[random(sizeof(msgfail))] +"\n" NOR;
                                message_vision(msg, me, target);

                        me->start_busy(1+random(2));
                }
            if (i < hits) { 
                                        msgloop = ({
                                                "$n��Ծ����δ��أ���"+ weapon->name()+HIG"����һ��һ��",
                                                "$pԽԾԽ�죬��������һƬ���񻯳ɵı̹��������衣",
                                                "�ǡ����־�����һ������һ����$Nһ���У�����������������$n��˿����Ϣʱ����",
                                                "$n������Ծ�������ý����������������ӣ����Ʋ���������֦֮�С�"
                                        });
                        msg = HIG"\n"+ msgloop[random(sizeof(msgloop))] +"\n" NOR;
                                message_vision(msg, me, target);

                                }
                        me->add("neili", -150 );
                        me->add("qi", -55 );
        }

        me->set_temp("ban",1);
                duration = 15 - me->query_skill("dagou-bang") / 50;
                if (duration < 5) { duration = 5; }
        call_out("remove_effect",duration,me,target,speed , dodge);
        return 1;
}

void remove_effect(object me, object victim, int speed, int dodge)
{
        if (objectp(victim)) {
                victim->set_temp("apply/speed", speed);
                victim->set_temp("apply/dodge", dodge);
        }
        if (objectp(me)) {
                me->set_temp("apply/speed",0);
        me->delete_temp("ban");
        }

        if( objectp(me) && objectp(victim) && victim->is_fighting(me) )
                message_vision(HIG "\n$N����һ�������������ջص������Ҳ�ָ�������\n\n" NOR, me);

        return 0;
}
