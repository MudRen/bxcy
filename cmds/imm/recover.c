// recover.c
inherit F_CLEAN_UP;
int help(object me);
int main(object me, string arg)
{
	seteuid(geteuid(me));
	if (arg && (arg=="?" || arg=="/?")) return help(me);
	me->set("eff_jing",me->query("max_jing"));
	me->set("jing",me->query("max_jing"));
	me->set("eff_qi",me->query("max_qi"));
	me->set("qi",me->query("max_qi"));
	if (me->query("neili")<me->query("max_neili"))
		me->set("neili",me->query("max_neili"));
	if (me->query("jingli")<me->query("max_jingli"))
		me->set("jingli",me->query("max_jingli"));
    me->set("food",me->max_food_capacity()*10);
    me->set("water",me->max_water_capacity()*10);
    me->start_busy(0);
	write("OK!\n");
	return 1;
}
int help(object me)
{
write(@HELP
ָ���ʽ : recover
 
�ָ��Լ��ľ���������������״̬�� 
HELP
    );
    return 1;
}
