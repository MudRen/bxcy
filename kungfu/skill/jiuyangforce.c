// jiuyangforce.c

inherit FORCE;



mapping *action = ({

        ([      "action":

"$Nʹ��һ�С�������ػ�Ԫ�������־۳�һ�Ż�Ԫ��������$n��$l",

                "force":                300,

                "damage_type":  "����"

        ]),

        ([      "action":

"$Nʹ��һ�С�������ػ�Ԫ�������־۳�һ�Ż�Ԫ��������$n��$l",

                "force":                500,

                "damage_type":  "����"

        ]),

        ([      "action":

"$Nʹ��һ�С�������ػ�Ԫ����˫�����Ʊ�ȭ���۳�һ�Ż�Ԫ��������$n��$l",

                "force":                700,

                "damage_type":  "����"

        ]),

        ([      "action":

"$Nʹ��һ�С���������ݡ���ȫ���ڿն��𣬻���һ�Ż�Ԫ��������$n��$l",

                "force":                1000,

                "damage_type":  "����"

        ]),

});

mixed hit_ob(object me, object victim, int damage_bonus, int factor)

{

        mixed foo;

        int force;



        foo = ::hit_ob(me, victim, damage_bonus, factor);

        if( intp(foo) && (damage_bonus + foo > 0) ) {

              if( random(3*(me->query_skill("jiuyangforce"))) > (damage_bonus + foo))

                 {

                        victim->receive_wound("qi", (damage_bonus + foo));

                        victim->receive_wound("jing", (damage_bonus + foo));

//                        victim->receive_wound("sen", (damage_bonus + foo));

                        force = victim->query("force");

                        victim->set("force", force-random(10)-1);

                        victim->set("max_force", 0);

                        return

"$N�ľ����񹦴ݻ���$n����Ԫ��������\n";

                }

        }

        return foo;

}



int valid_enable(string usage) 

{ 

return  usage=="iron-cloth" ||

        usage=="unarmed" ||

        usage=="parry"||

        usage=="force";

}



//int valid_learn(object me) { return 1; }



int valid_learn(object me)

{

if ((int)me->query("max_neili") < 500)

                return notify_fail("�������������\n");

     if ((int)me->query("combat_exp") < 100000)

                return notify_fail("���������û�ﵽѧ�����񹦵ĵز��� \n");

        return 1;

}

int practice_skill(object me)

{

        return 

notify_fail("������ֻ����ѧ�ģ����Ǵ�����(exert)�����������ȡ�\\n");

}



int effective_level() { return 21; }

//int effective_level() { return 50;}



string *absorb_msg = ({

        "$n������ת��˫��΢�����޼᲻�ݵľ��������ȶ�����\n",

        "$nʩչ�������񹦣����������纮����\n",

        "$n����΢չ�������񹦳��������ռ䡣\n",

});



string query_absorb_msg()

{

        return absorb_msg[random(sizeof(absorb_msg))];

}

mapping query_action(object me, object weapon)

{

        return action[random(sizeof(action))];

}

string *unarmed_parry_msg = ({

        "$n�������ȣ��������飬$N�������ɽ���\n",

        "$n����һ˦��һ�ɴ�����$N�ͳ����⡣\n",

        "$nʩչ������Ԫ���ҡ������赭д�Ļ�����$N�Ĺ��ơ�\n",

});

string *parry_msg = ({

        "$n�������ȣ��������飬$N�������ɽ���\n",

        "$n����һ˦��һ�ɴ�����$N�ͳ����⡣\n",

        "$nʩչ�����������ҡ������赭д�Ļ�����$N�Ĺ��ơ�\n",

});

string query_parry_msg(object weapon)

{

        if( weapon )

                return parry_msg[random(sizeof(parry_msg))];

        else

                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];

}

string exert_function_file(string func)

{

        return CLASS_D("mingjiao") + "/jiuyangforce/" + func;

}

int bounce_ratio()

{

        return 40;

}



int learn_bonus()

{

        return -100;

}

int practice_bonus()

{

        return -500;

}

int black_white_ness()

{

        return 200;

}



