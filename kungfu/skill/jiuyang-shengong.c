// jiuyang-shengong.c

#include <ansi.h>
inherit FORCE;	
mapping *action = ({

        ([      "action":
"$Nʹ��һ�С�"CYN"��"HIC"����ػ�Ԫ"NOR"�������־۳�һ�Ż�Ԫ��������$n��$l",
                "force":                300,
                "damage_type":  "����"

        ]),

        ([      "action":
"$Nʹ��һ�С�"YEL"��"HIC"����ػ�Ԫ"NOR"�������־۳�һ�Ż�Ԫ��������$n��$l",
                "force":                500,
                "damage_type":  "����"

        ]),

        ([      "action":
"$Nʹ��һ�С�"HIR"��"HIC"����ػ�Ԫ"NOR"����˫�����Ʊ�ȭ���۳�һ�Ż�Ԫ��������$n��$l",
                "force":                700,
                "damage_type":  "����"
        ]),

        ([      "action":
"$Nʹ��һ�С�"HIW"��"HIB"��"HIY"��"HIC"����"NOR"����ȫ���ڿն��𣬻���һ�Ż�Ԫ��������$n��$l",
                "force":                1000,
                "damage_type":  "����"
        ]),

});

int valid_enable(string usage)
{
        return  usage=="unarmed" ||
                usage=="parry"||
                usage=="force";

}

int valid_learn(object me)
{
    mapping skl;
    string *sname;
    int i;
    int lvl = (int)me->query_skill("jiuyang-shengong", 1);
    if ( me->query("gender") == "����" && lvl > 49)
        return notify_fail("���޸����ԣ���������������������ľ����񹦡�\n");
    if ( me->query("gender") != "����")
        return notify_fail("��������Ҫ����֮�������ʺ���ѧ��\n");
    if ((int)me->query_skill("force", 1) < 30)
        return notify_fail("��Ļ����ڹ���򻹲������޷��������񹦡�\n");
    if (lvl > 80)
    	return notify_fail("�Ҿͽ̵�������Ժ��Ҫ�����Լ����ˡ�\n");
    if (me->query_skill("force",1)<=lvl)
        return notify_fail("��Ļ����ڹ�������������ѧ��ȥ���߻���ħ�ġ�\n");
    skl = me->query_skills();
    sname  = keys(skl);
    for (i=0;i<sizeof(skl);i++){
//            if (sname[i]=="hunyuan-yiqi") continue;	
        if (sname[i]=="yijing-force") continue;
        if (sname[i]=="jiuyang-shengong") continue;
//            if (sname[i]=="taiji-shengong") continue;	
            if( SKILL_D(sname[i])->valid_enable("force") )
        return notify_fail("�㲻��ɢ�˱����ڹ�������ѧ�����񹦣���\n");
    }
    return 1;
}

int practice_skill(object me)
{
        return notify_fail("������ֻ����ѧ�ģ����Ǵ�����(exert)�����������ȡ�\n");
}

int effective_level() { return 21; }

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

string *parry_msg = ({

        "$n�������ȣ��������飬$N�������ɽ���\n",
        "$n����һ˦��һ�ɴ�����$N�ͳ����⡣\n",
        "$nʩչ�����������ҡ������赭д�Ļ�����$N�Ĺ��ơ�\n",
});

string query_parry_msg(object me,object weapon)
{
            return parry_msg[random(sizeof(parry_msg))];
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	object ob = victim->query_temp("armor/finger");
	string msg;
    if( damage_bonus < 100 ) return 0;
if ( me->query("couple") ) return 0;
	if( random(3*(me->query_skill("jiuyang-shengong",1))) > (damage_bonus ))
	{
		msg = HIR "$N�ľ����񹦴ݻ���$n����Ԫ��������\n" NOR;
		if(objectp(ob))
		{
			if(ob->query("id") == "tianmo ring")
			{
				damage_bonus = damage_bonus / 2;
				msg = HIR "$n����ħ��������$N�����񹦵��˺���������\n" NOR;
			}
		}
		victim->receive_wound("jing", damage_bonus / 2, me);
		victim->add("neili", -(int)me->query("jiali"));
		return msg;
        }
}

string exert_function_file(string func)
{
        return __DIR__"jiuyang-shengong/" + func;
}


