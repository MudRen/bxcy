// gvmt_jail.c
// Produce By Freeze(Rtm)

#include <ansi.h>
#include <login.h>

int update_condition(object me, int duration)
{
	if (duration < 1) {
		me->move("/d/city/guangchang");
		message("vision",
			HIY "ֻ��ƹ��һ����������һ��������һ����\n"
			"ԭ����һ���������ļһ�Ӵ����ﱻ���˳�����\n" NOR, environment(me), me);
		tell_object(me, HIY "ֻ��һ�����Ƽ���㣬��������ر��ӳ����γ�Ӫ��\n" NOR);
		me->set("startroom", "/d/city/guangchang");
		me->remove_call_out("revive");
		me->revive();
		me->reincarnate();
		return 0;
	}
//	tell_object(me, "debug: " + duration + " beats more to go...\n");
	me->apply_condition("sd_jail", duration - 1);
	return 1;
}
