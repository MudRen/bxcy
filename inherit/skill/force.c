// force.c
inherit SKILL;
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
    int damage;
    me->add("neili", - factor );
    damage = (int)me->query("neili")/100 + factor - (int)victim->query("neili")/100;
    if( damage < 0 ) {
        if( !me->query_temp("weapon")
        &&  random(me->query_skill("force")) < victim->query_skill("force") ) {
            damage = - damage;
            me->receive_damage( "qi", damage * 2,victim );
            me->receive_wound( "qi", damage ,victim);
            if( damage < 10 ) return "$N受到$p的内力反震，闷哼一声。\n";
            else if( damage < 20 ) return "$N被$p以内力反震，「嘿」地一声退了两步。\n";
            else if( damage < 40 ) return "$N被$p以内力一震，胸口有如受到一记重锤，连退了五六步！\n";
            else return "$N被$p的内力一震，眼前一黑，身子向后飞出丈许！！\n";
        }
    }
    if( damage_bonus + damage < 0 ) return - damage_bonus;
        return damage;
}
mixed armor_ob(object me, object victim, int damage_bonus,int force_armor)
{
    if (!living(victim) || damage_bonus<0) return damage_bonus;
    if (victim->query("neili") >= force_armor )
        if (force_armor > damage_bonus){
            victim->add("neili",-damage_bonus);
                return BOLD "$p用"+to_chinese(victim->query_skill_mapped("force"))+"的护体真气化解了$N的伤害！\n" NOR;
        }else{
            message_vision( BOLD "\n$p催动"+to_chinese(victim->query_skill_mapped("force"))+"的护体真气试图削弱$N的伤害！" NOR,me,victim);
            victim->add("neili",force_armor);
            return damage_bonus-force_armor;
        }
        return damage_bonus;
}
