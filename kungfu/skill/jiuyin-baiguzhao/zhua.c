// zhua.c  九阴白骨爪「亡魂一击」
#include <ansi.h>
inherit F_SSERVER;
int perform(object me, object target)
{
    int damage;
    string msg;
    if( !target ) target = offensive_target(me);
    if( !target || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("「亡魂一击」只能对战斗中的对手使用。\n");
    if( (int)me->query("shen", 1) > 0)
        return notify_fail(WHT"你是侠义道人士，怎麽能「亡魂一击」这种阴毒武功。\n"NOR);
    if( (int)me->query_skill("jiuyin-baiguzhao", 1) < 300 )
  
      return notify_fail(WHT"你的九阴白骨爪不够娴熟，还使不出「亡魂一击」。\n"NOR);
    if( (int)me->query_skill("force", 1) < 400 )
        return notify_fail(RED"你的内功心法火候不够，使用「亡魂一击」会震伤自己的经脉。\n"NOR);
    msg = HIC "$N突然将双掌变爪合于胸前，然后象风车般急转数圈，而后施展出「亡魂一击」，双爪向外一翻，随后绕着$n疾转数圈，又回到原地。\n"NOR;
    if (random(me->query_skill("force")) > target->query_skill("force")/2||
        random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 )
    {
        me->start_busy(2);
        target->start_busy(random(3));
        damage = (int)me->query_skill("jiuyin-baiguzhao", 1/2);
        damage = damage + random(damage/2);
        target->receive_damage("qi", damage);
        target->receive_wound("qi", damage/3);
        target->receive_damage("jing", damage/3);
        target->receive_wound("jing", damage/6);
        me->add("neili", -damage/3);
   msg += HIC"原来$N已在$n头顶留下了五个整整齐齐的指洞！$n只觉得头顶一阵麻痒，就软软地歪在一边了。厉害！！！\n"NOR;
    } else
    {
        me->start_busy(4);
        msg += HIY"可是$p看破了$P的企图，闪身护头躲在了一边。\n"NOR;
    }
    message_vision(msg, me, target);
    if(userp(target)) target->fight_ob(me);
    else if( !target->is_killing(me) ) target->kill_ob(me);
    return 1;
}
