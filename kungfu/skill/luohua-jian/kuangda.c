// kuangda.c 红花十三剑法「狂打」诀

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon;
        string msg;
        int i, attack_time;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("「狂打」诀只能对战斗中的对手使用。\n");

        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");

        if( (int)me->query_skill("luohua-jian", 1) < 400 )
                return notify_fail("你的红花十三剑法不够娴熟，不会使用「狂打」诀。\n");
        if( (int)me->query_skill("honghua-shengong", 1) < 300 )
        	return notify_fail("你的红花神功不够深厚，不能使用「狂打」诀。\n");

        msg = HIY "$N使出红花十三剑法「狂打」诀，招式陡然变快，疯狂的扑向对方。\n";

        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/20 )
        {
                attack_time = random((int)me->query_skill("luohua-jian", 1) / 50);
                if(attack_time < 1)
                        attack_time = 1;

                msg += CYN " 结果$p被$P攻了个措手不及！\n" NOR;
                for(i = 0; i < attack_time; i++){
                        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
                        }

                me->start_busy(2);
                me->add("neili", -100);
        }
        else
        {
                msg += "可是$p看破了$P的企图，并没有上当。\n" NOR;
                me->start_busy(4);
        }
        message_vision(msg, me, target);

        return 1;
}

