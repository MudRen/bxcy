// ������
#include <ansi.h>
inherit F_SSERVER;
int thunderspell(object me, object obj)
{
int	kee, damage, spells;
if ((int)me->query_skill("magic-old", 1) < 100)
return notify_fail(WHT"��ĹŴ�ħ��������죬��ʹ������������������\n"NOR);
message_vision(YEL "\nһ��������$N��ͷ�ϴ�����\n" NOR, obj);
obj->receive_damage("jing", 0, me);
spells = me->query_skill("spells");
if(obj->is_ghost()==1) {
message_vision(RED "$N�ҽ���һ������Ϊ�˻ҽ���\n" NOR, obj);
obj->die();
return 1;
}
if(obj->is_zombie()==1) {
message_vision(RED "$N�ҽ���һ������Ϊ��һ̲Ѫˮ��\n" NOR, obj);
obj->die();
return 1;
}
if(obj->query("race")=="Ұ��") {
damage = (int)me->query_skill("magic-old", 1);
damage = damage + random(damage);
if(damage <= 20) damage = 0;
if(damage > 35) damage = 35;
if(damage != 0) {
message_vision(RED "��������$N��ͷ�ϣ�\n" NOR, obj);
obj->receive_damage("qi", 400);
obj->receive_damage("jing", 30);
obj->receive_damage("qi", damage);
obj->receive_damage("jing", damage);
COMBAT_D->report_status(obj);
if( !obj->is_fighting(me) ) {
if( living(obj) ) {
if( userp(obj) ) 
obj->fight_ob(me);
else
obj->kill_ob(me);
}
me->kill_ob(obj);
}
} else
message_vision(RED "����$N����ˣ�\n" NOR, obj);
return 1;
}
damage = (int)me->query_skill("magic-old", 1);
damage = damage + random(damage);
if(damage < 0) damage = 0;
if(damage > 20) damage = 20;
if(damage != 0) {
message_vision(RED "��������$N��ͷ�ϣ�\n" NOR, obj);
obj->receive_damage("qi", 400);
obj->receive_damage("jing", 30);
obj->receive_damage("qi", damage);
obj->receive_damage("jing", damage);
COMBAT_D->report_status(obj);
if( !obj->is_fighting(me) ) {
if( living(obj) ) {
if( userp(obj) ) 
obj->fight_ob(me);
else
obj->kill_ob(me);
}
me->kill_ob(obj);
}
} else 
message_vision(RED "����$N����ˣ�\n" NOR, obj);
return 1;
}
int perform(object me)
{
string 	msg;
object	env;
object	*inv;
int	i;
if((int)me->query_skill("spells") < 200 )
return notify_fail("��ķ��������ߣ�\n");
if((int)me->query("neili") < 200 )
return notify_fail("��ķ���������\n");
if((int)me->query("qi") < 100 )
return notify_fail("�������������\n");
if((int)me->query("jing") < 100 )
return notify_fail("��ľ���û�а취��Ч���У�\n");
me->add("neili", -200);
msg = YEL "$N�Ų���â�ǣ�˫���ճɷ�ħӡ�������૵��������ģ�\n" NOR;
msg = msg + RED "�͵�˫��һ�ӣ����ϴ����������磡\n\n" NOR;
message_vision(msg, me);
env = environment(me);
inv = all_inventory(env);
for(i=0; i<sizeof(inv); i++) {
if( inv[i]==me ) continue;
if( !inv[i]->is_character() || inv[i]->is_corpse() ) continue;
thunderspell(me, inv[i]);
}
me->start_busy(2);
return 1;
}
