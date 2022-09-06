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
            if( damage < 10 ) return "$N�ܵ�$p�����������ƺ�һ����\n";
            else if( damage < 20 ) return "$N��$p���������𣬡��١���һ������������\n";
            else if( damage < 40 ) return "$N��$p������һ���ؿ������ܵ�һ���ش�����������������\n";
            else return "$N��$p������һ����ǰһ�ڣ��������ɳ�������\n";
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
                return BOLD "$p��"+to_chinese(victim->query_skill_mapped("force"))+"�Ļ�������������$N���˺���\n" NOR;
        }else{
            message_vision( BOLD "\n$p�߶�"+to_chinese(victim->query_skill_mapped("force"))+"�Ļ���������ͼ����$N���˺���" NOR,me,victim);
            victim->add("neili",force_armor);
            return damage_bonus-force_armor;
        }
        return damage_bonus;
}
