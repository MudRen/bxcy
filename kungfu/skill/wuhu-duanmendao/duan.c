#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_SSERVER;
 
int perform(object me, object target)
{
    object weapon, ob;
    string msg;
    int i;
 
    if( !me->is_fighting() )
        return notify_fail("�廢���ŵ����ϡ��־�ֻ����ս����ʹ�á�\n");
    if (me->query_temp("perform")) return notify_fail("����һ��δʹ�꣡\n");
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "blade")
    if (!objectp(weapon = me->query_temp("secondary_weapon"))
    || (string)weapon->query("skill_type") != "blade")
        return notify_fail("��ʹ�õ��������ԡ�\n");
    else me->set_temp("secondly_weapon",1);
    if( (int)me->query("neili") < 200 )
        return notify_fail("�������������\n");
    if( (int)me->query_skill("blade") < 60 ||
        me->query_skill_mapped("blade") != "wuhu-duanmendao")
        return notify_fail("��ġ��廢���ŵ����������ң��޷�ʹ�á��ϡ��־���\n");
    msg = HIY "$N��Ȼ���أ�ʹ�����õ����־�����ʱһƬ�׹�ֱ��ǰ��ȥ��\n" NOR;
    message_vision(msg, me);
    me->clean_up_enemy();
    ob = me->select_opponent();
    me->add("neili", -150);
    me->set_temp("perform",1);
    me->set_temp("perform_duan",1);
    for(i = 0; i < 3; i++)
        if (me->is_fighting(ob) && ob->is_fighting(me) && ob->query("eff_qi")>0){
              me->set_temp("action_msg","������");
                if (!weapon->query("equipped")) break;
              COMBAT_D->do_attack(me, ob,weapon, 0);
            }else break;
    me->delete_temp("perform_duan");
    me->delete_temp("secondly_weapon");
    me->start_call_out( (: call_other, __FILE__, "del_perform", me :), 3);;
    return 1;
}

void del_perform(object me)
{
   if (!me) return;
   me->delete_temp("perform");
}


