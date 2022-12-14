// sanjue.c  达摩剑 [达摩三绝剑]
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_SSERVER;
 
void do_attack(object me,object target,object weapon,int attack_time)
{
    int i;
    if (!me) return;
    me->delete_temp("perform");
    if (!living(me) || !target ) return;
    if (environment(me)!=environment(target)) return;
    if (weapon!=me->query_temp("weapon"))
         me->set_temp("secondly_weapon",1);
    if (!weapon->query("equipped")){ me->start_busy(1); return; }
        for(i = 0; i < attack_time; i++)
            if (me->is_fighting(target) && target->is_fighting(me) && target->query("eff_qi")>0){
              me->set_temp("action_msg","紧接着");
                if (!weapon->query("equipped")){ me->start_busy(1); return; }
        if (me->query_skill_mapped("sword")!="damo-jian") {me->start_busy(1); return; }
              COMBAT_D->do_attack(me, target,weapon, 0);
            }else break;
    me->delete_temp("secondly_weapon");
    me->start_call_out( (: call_other, __FILE__, "del_perform", me:), 1);
   
}

int perform(object me, object target)
{
    object weapon, ob;
    string msg;
 
    if( !me->is_fighting() )
        return notify_fail("「达摩三绝剑」只能在战斗中使用。\n");
    if (me->query_temp("perform"))  return notify_fail("你上一个招式还没完成!\n");
    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
    if (!objectp(weapon = me->query_temp("secondary_weapon"))
        || (string)weapon->query("skill_type") != "sword")
            return notify_fail("你使用的武器不对。\n");
    if((int)me->query_dex() < 30)
        return notify_fail("你的身法不够, 目前还不能使用这项绝技! \n");
    if((int)me->query_skill("hunyuan-yiqi",1) < 100 )
     if( (int)me->query_skill("yijing-force",1) < 100)
        return notify_fail("你的混元一气功的修为不够, 不能使用这一绝技 !\n");
    if((int)me->query_skill("dodge") < 135)
        return notify_fail("你的轻功修为不够, 不能使用达摩三绝剑！\n");
 
    if((int)me->query_skill("sword") < 135)
        return notify_fail("你的剑法修为不够， 目前不能使用达摩三绝剑! \n");
    if( (int)me->query("neili") < 500 )
        return notify_fail("你的真气不够！\n");
    msg = HIG "$N使出达摩剑的绝技「达摩三绝剑」，身法陡然加快！\n" NOR;
    message_vision(msg, me);
    me->clean_up_enemy();
    ob = me->select_opponent();
    me->add("neili", -150);
    me->start_call_out( (: call_other, __FILE__, "do_attack", me, ob,weapon,3 :), 1);
    me->set_temp("perform",1);
    return 1;
}

