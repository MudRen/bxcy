// jiuyang-shengongt.c

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

mixed hit_ob(object me,object victim,object target,int damage_bonus)
{
    if( damage_bonus < 100 ) return 0;
    if( random(3*(me->query_skill("jiuyang-shengongt",1))) > (damage_bonus )) {
                        victim->receive_wound("qi", (damage_bonus ));
                        victim->receive_wound("jing", (damage_bonus ));
                        victim->add("neili", -(int)me->query("jiali"));
                        return HIR "$N�ľ����񹦴ݻ���$n����Ԫ��������\n" NOR;
        }
if(!( target->query_temp("armor")->id("tianmo jie")))
{
                        victim->receive_wound("qi", (damage_bonus ));
                        victim->receive_wound("jing", (damage_bonus ));
                        victim->add("neili", -(int)me->query("jiali"));
                        return HIB "$n����ħ�䷢����������������$N�����񹦵��˺���������\n" NOR;
        }
}

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
    int lvl = (int)me->query_skill("jiuyang-shengongt", 1);
    if ( me->query("gender") == "����" && lvl > 49)
        return notify_fail("���޸����ԣ���������������������ľ����񹦡�\n");
    if ( me->query("gender") != "����")
        return notify_fail("��������Ҫ����֮�������ʺ���ѧ��\n");
    if ((int)me->query_skill("force", 1) < 30)
        return notify_fail("��Ļ����ڹ���򻹲������޷��������񹦡�\n");
    if (me->query_skill("force",1)<=lvl)
        return notify_fail("��Ļ����ڹ�������������ѧ��ȥ���߻���ħ�ġ�\n");
    skl = me->query_skills();
    sname  = keys(skl);
    for (i=0;i<sizeof(skl);i++){
        if (sname[i]=="hunyuan-yiqi") continue;
        if (sname[i]=="yijing-force") continue;
        if (sname[i]=="jiuyang-shengong") continue;
        if (sname[i]=="taiji-shengong") continue;
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

string exert_function_file(string func)
{
        return __DIR__"jiuyang-shengong/" + func;
}


