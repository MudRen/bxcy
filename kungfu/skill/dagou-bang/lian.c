// lian.c 「连」字诀
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
    if (weapon == me->query_temp("secondary_weapon") )
    me->set_temp("secondly_weapon",1);
    if (!weapon->query("equipped")){ me->start_busy(3); return; }
    if (environment(me)!=environment(target)) return;
        for(i = 0; i < attack_time; i++)
            if (me->is_fighting(target) && target->is_fighting(me) && target->query("eff_qi")>0){
              me->set_temp("action_msg","紧接着");
// 断掉的断掉的断掉的断掉的断掉的断掉的断掉的断掉的，
                if (!weapon->query("equipped")){ me->start_busy(2); return; }
        if (me->query_skill_mapped("club")!="dagou-bang") {me->start_busy(3); return; }
              COMBAT_D->do_attack(me, target, weapon, 0);
              me->start_busy(1);
            }else break;
    me->delete_temp("secondly_weapon");
    if (i) message_vision(CYN " 结果$p被$P攻的蹦跳不停，手忙脚乱！\n" NOR, me, target);
}

int perform(object me, object target)
{
    object weapon;
    string msg;
    int attack_time;
    if( !target ) target = offensive_target(me);
    if( !target
    ||  !target->is_character()
    ||  !me->is_fighting(target) )
        return notify_fail("「连」字诀只能对战斗中的对手使用。\n");
    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "club")
    if (!objectp(weapon = me->query_temp("secondary_weapon"))
        || (string)weapon->query("skill_type") != "club")
        return notify_fail("你使用的武器不对。\n");
    if( (int)me->query_skill("dagou-bang", 1) < 300 )
        return notify_fail("你的打狗棒不够娴熟，不会使用「连」字诀。\n");
    if (!me->visible(target))    return notify_fail("你看不到"+target->name()+"。\n");
    if (me->query_temp("perform"))  return notify_fail("你上一个招式还没完成!\n");
    if ( me->query("neili")<150 )   return notify_fail("你的内力不足!\n");
    if( me->is_busy()) return notify_fail("你现在正忙着。\n");
        msg = HIY "$N使出打狗棒法「连」字诀，棒头连点，连绵不绝地挑向$n。\n" NOR;
    if( !living(target) || random(10) > 1 )
    {
        attack_time = (int)me->query_skill("dagou-bang", 1) / 60;
        if(attack_time < 1)
            attack_time = 1;
if(attack_time > 30)
attack_time = 30;
    me->start_call_out( (: call_other, __FILE__, "do_attack", me, target,weapon,attack_time :), 2);
    if (me->query("neili")<150)
        me->set("neili",0);
    else
        me->add("neili", -150);
    me->set_temp("perform",1);
    }
    else
    {
        msg += HIY  "可是$p看破了$P的企图，镇定解招，一丝不乱。\n" NOR;
          me->start_busy(1);
    }
    message_vision(msg, me, target);
    return 1;
}

