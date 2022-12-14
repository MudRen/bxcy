// miejian.c  回风拂柳剑  (灭剑)
//create bye cuer
#include <ansi.h>
inherit F_SSERVER;
void end(object,int);
int perform(object me, object target)
{       
        object weapon, ob;        int damage;
        string msg;
        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "sword")
                        return notify_fail("你使用的武器不对。\n");       
               if( !target ) target = offensive_target(me);
        if( !target || !target->is_character() )
                return notify_fail("灭剑只能对同地方的对手使用。\n");
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("灭剑攻击只能对战斗中的对手使用。\n");
        if( (int)me->query_skill("fuliu-jian", 1) < 80 )
                return notify_fail("你的回风拂柳剑不够娴熟，不会使用「灭剑」。\n");
        if( (int)me->query_skill("linji-zhuang", 1) < 30 )
                return notify_fail("你的临济十二庄不够高，不能用内力使出灭剑。\n");
        if( (int)me->query("neili", 1) < 200 )
                return notify_fail("你现在内力太弱，不能使出灭剑。\n");
        if( target->query_temp("sword")==1)
                return notify_fail(target->query("name")+"正被你的攻势所吓，快功击啊。 \n");
        msg = HIC "$N手中长剑剑芒跃动，剑光暴长，幻出死亡的色彩，剑尖渐\n"NOR;
        msg += HIC"渐逼近$n，$n看到漫天剑光，抽身后跃，只这一刹，漫天剑\n"NOR;
        msg += HIC"影化为一剑直刺$n前胸，快捷无伦，只有一剑！\n"NOR;
        me->add("neili", -100);
        me->start_busy(1);              
        if(random(me->query("combat_exp"))>(int)target->query("combat_exp")/2)
        { 
        msg += HIR"$n根本没法躲避，一式「回风拂柳剑」的绝招「灭剑」端端正\n"NOR;
        msg += HIR"正扎进在$n胸口！$n一低头，看长剑自胸口拔出！\n"NOR;
                me->add("neili",-200);          
                me->start_busy(2);
                target->start_busy(random(3));
                damage = (int)me->query_skill("fuliu-jian", 1);
                damage = damage + random(damage);
                target->receive_damage("qi", damage/2);
                target->receive_wound("qi", damage);
                target->receive_damage("jing", damage);
                target->receive_wound("jing", damage/2);
        
                }                                                 
        else
        { 
        msg += HIY"可是$p轻轻一笑，侧身右转，伸出两指，正弹在$P的剑上，长\n"NOR;
        msg += HIY"剑在$p身侧划过，毫发无伤。\n"NOR;           
        }
        message_vision(msg, me, target);
        return 1;
}

void end(object target,int damage)
{
  target->delete_temp("sword");
  target->add_temp("apply/attack",0-damage);
  target->add_temp("apply/defense",0-damage);
  message_vision(RED"$N终于从灭剑的阴影里恢复了出来。\n"NOR,target);
}
