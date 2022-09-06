// jiuyang-force.c
inherit FORCE;
#include <ansi.h>    
mapping *action = ({
        ([      "action":
"$Nʹ��һ�С�������ػ�Ԫ�������־۳�һ�Ż�Ԫ��������$n��$l",
               "force" : 300,
          "dodge" : -5,
           "parry" : 20,
           "skill_name" : "������ػ�Ԫ",
          "damage": 30,
           "lvl" : 0,
                 "damage_type" : "����",
        ]),
        ([      "action":
"$Nʹ��һ�С�������ػ�Ԫ�������־۳�һ�Ż�Ԫ��������$n��$l",
                "force":                500,
                "dodge" : -10,
                 "skill_name" : "������ػ�Ԫ",
                "damage": 50,
                 "lvl" : 50,
                 "parry" : 40,        
                              "damage_type":  "����"
        ]),
        ([      "action":
"$Nʹ��һ�С�������ػ�Ԫ����˫�����Ʊ�ȭ���۳�һ�Ż�Ԫ��������$n��$l",
                "force":                700,
                "dodge" : -20,
                  "parry" : 60,
                "skill_name" : "������ػ�Ԫ",
                "damage": 80,
                "lvl" : 100,
                "damage_type":  "����"
        ]),
([      "action":
"$Nʹ��һ�С�������ػ�Ԫ����˫�ֻ�����ǰ��ӿ��ȫ���Ԫ�������һ��ŨŨ�İ������
$n��$l",
                "force":    1000,
                "dodge" : -30,
                 "parry" : 100,
                "skill_name" : "������ػ�Ԫ",
                "damage": 120,
                "lvl" : 140,
                "damage_type":  "����"
        ]),      ([      "action":
YEL"$Nʹ��һ�С���������ݡ���ȫ���ڿն��𣬻���һ�Ż�Ԫ��������$n��$l"NOR,
                "force":                2000,
                "dodge" : -50,
                 "parry" : 160,
                "skill_name" : "���������",
                "damage": 240,
                "lvl" : 180,
                "damage_type":  "����"
        ]),
});
string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level   = (int) me->query_skill("jiuyang-force",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        mixed foo;
        int force;

        foo = ::hit_ob(me, victim, damage_bonus, factor);
        if( intp(foo) && (damage_bonus + foo > 0) ) {
              if( (random(2*(me->query_skill("jiuyang-force"))) > (damage_bonus + foo))&&(me->query("max_neili")>2000)&&(me->query_skill("jiuyang-force")>120) )
                 {                        
                        force = me->query_skill("force");
                        victim->receive_wound("qi", (damage_bonus + foo));
                        victim->receive_wound("jing", random(force/2));
                        victim->set("neili", 0);
                        return
HIR"$N�ľ��������ݻ���$n����Ԫ��������\n"NOR;
                }
        }
        return foo;
}

int valid_enable(string usage) 
{ 
      return usage=="unarmed" ||
        usage=="parry"||
        usage=="force";
}

int valid_learn(object me,mapping fam)
{
mapping skl;	
string *sname;	
int i;	
        if (!(fam = this_player()->query("family")) || fam["family_name"] != "����")
                return notify_fail("�㲻�����̵�������ô��ѧ������ľ���������?\n");
        if ((int)me->query("max_neili") < 1500)
                return notify_fail("�������������\n");
        if ((int)me->query("combat_exp") < 1000000)
                return notify_fail("���������û�ﵽѧ������ľ��������ĵز��� \n");
        if ( me->query("gender") == "����" && (int)me->query_skill("jiuyang-force", 1) > 49)
                return notify_fail("���޸����ԣ���������������������ľ���������\n");
//      if ((string)me->query("gender") == "Ů��" )
//              return notify_fail("��һ��Ů�������ѧϰ�����񹦣�\n" );
skl = this_player()->query_skills();	
sname  = keys(skl);	
for (i=0;i<sizeof(skl);i++){	
if (sname[i]=="yijing-force") continue;	
if (sname[i]=="shenghuo-shengong") continue; 	
if (sname[i]=="jiuyang-force") continue;	
if( SKILL_D(sname[i])->valid_enable("force") )	
/*
        if ( me->query_skill("bibo-shengong",1)
        || me->query_skill("beiming-shengong",1)
        || me->query_skill("bahuang-gong",1)
        || me->query_skill("hamagong",1)
        || me->query_skill("huagong-dafa",1)
        || me->query_skill("huntian-qigong",1)
        || me->query_skill("longxiang",1)
        || me->query_skill("jiuyang-shengong",1)
        || me->query_skill("shenyuan-gong",1)
        || me->query_skill("taiji-shengong",1)
        || me->query_skill("xiaowuxiang",1)
        || me->query_skill("zixia-shengong",1) 
        || me->query_skill("yunlong-shengong",1)
        || me->query_skill("wuji-shengong",1)
        || me->query_skill("guiyuan-dafa",1)
        || me->query_skill("xiantian-wuji",1)
        || me->query_skill("yunu-xinjing",1)
//      || me->query_skill("hunyuan-yiqi",1)
        || me->query_skill("xixing-dafa",1)
        || me->query_skill("kurong-changong",1)
        || me->query_skill("tiangang-zhengqi",1))
*/
                return notify_fail("�㲻��ɢ�˱����ڹ�������ѧ������������\n");
}
                
        return 1;
}

int practice_skill(object me)
{
   return notify_fail("��������ֻ����ѧ�ģ����Ǵ�����(exert)�����������ȡ�\n\n");
}

int effective_level() { return 21; }
string *absorb_msg = ({
       GRN "$n������ת��˫��΢�����޼᲻�ݵľ����������ȶ�����\n",
       GRN"$nʩչ���������������������纮����\n",
       GRN "$n����΢չ�������������������ռ䡣\n",
});

string query_absorb_msg()
{
        return absorb_msg[random(sizeof(absorb_msg))];
}
string *unarmed_parry_msg = ({
        GRN"$n�������ȣ��������飬$N�������ɽ���\n",
        GRN"$n����һ˦��һ�ɴ�����$N�ͳ����⡣\n",
        GRN"$nʩչ������Ԫ���ҡ������赭д�Ļ�����$N�Ĺ��ơ�\n",
});
string *parry_msg = ({
        GRN"$n�������ȣ��������飬$N�������ɽ���\n",
        GRN"$n����һ˦��һ�ɴ�����$N�ͳ����⡣\n",
        GRN"$nʩչ�����������ҡ������赭д�Ļ�����$N�Ĺ��ơ�\n",
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
       return __DIR__"jiuyang-force/" + func;
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

