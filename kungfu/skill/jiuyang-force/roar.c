// roar.c

#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
	object *ob;
	int i, skill, damage;
	if( (int)me->query("neili") < 1000 )
		return notify_fail("��������������������ĺ���һ��, ��������˼�ֻ����\n");

	if( (int)me->query_skill("jiuyang-force") < 60 )
		return notify_fail("��ľ��������ļ��𻹲�����\n");

	skill = me->query_skill("force");

	me->add("neili", -200);
	me->receive_damage("qi", 30);

	me->start_busy(2);
	message_vision(
		HIY "$N�������һ�����������ŷ�������һ�����춯�صľ޺�\n" NOR, me);

	ob = all_inventory(environment(me));
			if(me->query("id")=="gud"){
			for(i=0; i<sizeof(ob); i++){
				if( !living(ob[i]) || ob[i]==me )
					continue;
				damage = skill - ((int)ob[i]->query("max_neili") / 10);
				if( damage < 0 )
					damage = (int)ob[i]->query("eff_jing") / 2;
					ob[i]->receive_damage("jing", damage * 2,me );
					if( (int)ob[i]->query("neili") < skill * 2 )
						ob[i]->receive_wound("jing", damage,me);
					tell_object(ob[i], "�������ǰһ�������ð������ʹ������Ҫ�ѿ�һ����\n");
				ob[i]->start_busy(20);
				if( !ob[i]->is_killing(me) )	ob[i]->kill_ob(me);
				if( !me->is_killing(ob[i]) )	me->fight_ob(ob[i]);
				}
			}else{
	for(i=0; i<sizeof(ob); i++) {
		if( !living(ob[i]) || ob[i]==me ) continue;
		if( skill/2 + random(skill/2) < (int)ob[i]->query("con") * 2 ) continue;

		damage = skill * 3 - ((int)ob[i]->query("max_neili") / 5);
		if( damage > 0 ) {
			ob[i]->receive_damage("jing", damage * 2 );
			if( (int)ob[i]->query("neili") < skill * 2 )
				ob[i]->receive_wound("jing", damage);
			tell_object(ob[i], "�������ǰһ�������ð������ʹ������Ҫ�ѿ�һ����\n");
		}
		if( !ob[i]->is_killing(me) ) ob[i]->kill_ob(me);
		if( !me->is_killing(ob[i]) ) me->fight_ob(ob[i]);
	}
}
	return 1;
}
