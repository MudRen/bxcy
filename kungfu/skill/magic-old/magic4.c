// 闪电术
#include <ansi.h>
inherit F_SSERVER;
int thunderspell(object me, object obj)
{
int	kee, damage, spells;
if ((int)me->query_skill("magic-old", 1) < 200)
return notify_fail(WHT"你的古代魔法不够娴熟，还使不出「龙破斩」。\n"NOR);
message_vision(YEL "\n一个巨大的冲击波向$N的身上打来，\n" NOR, obj);
obj->receive_damage("jing", 0, me);
spells = me->query_skill("spells");
if(obj->is_ghost()==1) {
message_vision(RED "$N惨叫了一声，化为了灰烬！\n" NOR, obj);
obj->die();
return 1;
}
if(obj->is_zombie()==1) {
message_vision(RED "$N惨叫了一声，化为了一滩血水！\n" NOR, obj);
obj->die();
return 1;
}
if(obj->query("race")=="野兽") {
damage = (int)me->query_skill("magic-old", 5);
damage = damage + random(damage);
if(damage <= 20) damage = 0;
if(damage > 35) damage = 35;
if(damage != 0) {
message_vision(RED "$N的全身都被打中了！\n" NOR, obj);
obj->receive_damage("qi", 3000);
obj->receive_damage("jing", 500);
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
message_vision(RED "但被$N躲过了！\n" NOR, obj);
return 1;
}
damage = (int)me->query_skill("magic-old", 5);
damage = damage + random(damage);
if(damage < 0) damage = 0;
if(damage > 20) damage = 20;
if(damage != 0) {
message_vision(RED "$N的全身都被打中了\n" NOR, obj);
obj->receive_damage("qi", 3000);
obj->receive_damage("jing", 500);
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
message_vision(RED "但被$N躲过了！\n" NOR, obj);
return 1;
}
int perform(object me)
{
string 	msg;
object	env;
object	*inv;
int	i;
if((int)me->query_skill("spells") < 200 )
return notify_fail("你的法术不够高！\n");
if((int)me->query("neili") < 200 )
return notify_fail("你的法力不够！\n");
if((int)me->query("qi") < 500 )
return notify_fail("你的体力不够！\n");
if((int)me->query("jing") < 100 )
return notify_fail("你的精神没有办法有效集中！\n");
me->add("neili", -500);
msg = YEL "$N脚踩五芒星，双手握成伏魔印，口中喃喃地念著咒文，\n" NOR;
msg += RED"$N念到 比黄昏还要昏喑的东西,比血液还要鲜红的东西...\n"NOR;
msg += RED"$N继续念到 出现在时间之流  把挡在我面前一切愚不可及的事物摧毁...\n"NOR;
msg += HIR"$N大叫一声  龙破斩!!  巨大的的冲击波直向四周飞去，能量大的可怕.！\n"NOR;
message_vision(msg, me);
env = environment(me);
inv = all_inventory(env);
for(i=0; i<sizeof(inv); i++) {
if( inv[i]==me ) continue;
if( !inv[i]->is_character() || inv[i]->is_corpse() ) continue;
thunderspell(me, inv[i]);
}
me->start_busy(5);
return 1;
}
