// dagou-bang.c
inherit SKILL;
mapping *action = ({
([  "action": "$Nʹ��һ�С�"+BLK+"����˫Ȯ"+NOR+"��������$w���������������$n��$l",
    "force" : 50,
    "lvl" : 1,
    "damage_type": "����"
]),
([  "action": "$N����$w���һζ���һ�С�"+RED+"����Ѱ��"+NOR+"����$n��$l��ȥ",
    "force" : 100,
    "lvl" : 33,
    "damage_type": "����"
]),
([  "action": "$N����$w���Ӹ�����ʹһ�С�"+GRN+"��ݾ���"+NOR+"������$n��$l",
    "force" : 180,
    "lvl" : 66,
    "damage_type": "����"
]),
([  "action": "$Nʩ����"+YEL+"��������"+NOR+"����$w����������$n��ȥ",
    "force" : 250,
    "lvl" : 100,
    "damage_type": "����"
]),
});
int practice_level(){   return 100;  }
int valid_enable(string usage) { return (usage == "club") || (usage == "parry"); }
int valid_learn(object me)
{
    if ((int)me->query("max_neili") < 100)
        return notify_fail("�������������\n");
if ((int)me->query_skill("huntian-qigong",1) < 500 )                 
return notify_fail("����ڹ���Ϊ����,�޷�����򹷰����ľ�Ҫ��\n");	
if ((int)me->query_skill("dagou-bang",1) >= 450 )    			
return notify_fail("ʦ��ֻ�ܽ��㵽�⣬�Ժ��Լ������ϰ��ᡣ\n");		
    if (me->query_skill("club", 1) <=me->query_skill("dagou-bang", 1))
        return notify_fail("��Ļ����������޷���������ļ��ɡ�\n");
    else
    return 1;
}
mapping query_action(object me, object weapon)
{
    mapping a_action;
    int level=me->query_skill("dagou-bang",1);
    if ((int)me->query_temp("wugou")>0)
        return (["action": BOLD ""+HIC+"������"+NOR+"ָ��$n"+BOLD+"��$l" NOR,
                 "dodge": -3*random(level),
                 "damage": level,
                 "damage_type":"����",
                ]);
    a_action = action[random(sizeof(action))];
    a_action["dodge"]  = 0-level;
    a_action["damage"] = level;
    return a_action;
}
 int practice_skill(object me)
 {
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "club")
    if (!objectp(weapon = me->query_temp("secondary_weapon"))
    || (string)weapon->query("skill_type") != "club")
        return notify_fail("��ʹ�õ��������ԡ�\n");
    if ((int)me->query("qi") < 50)
        return notify_fail("��������������򹷰�����\n");
    me->receive_damage("qi", 40);
    return 1;
 }

void do_interlink(object me, object victim)
{
    int skill,skill2,i,j;
    object *enemy,weapon=me->query_temp("weapon");
    string all_enemy;
    
    if (!weapon) return;
    skill=me->query_skill("dagou-bang", 1);
    skill2=me->query_skill("huntian-qigong", 1);
    if (random(skill)>500&&random(skill2)>500&&
    	me->query_skill_mapped("force") == "huntian-qigong"&&
    	(string)weapon->query("id") == "yuzhu zhang"&&
    	me->query("neili") > 20000&&
    	me->query("family/family_name") == "ؤ��"
    	){
        enemy=me->query_enemy();
        if (!sizeof(enemy)) return;
        if (sizeof(enemy)==1 && enemy[i]->query("eff_qi")<0 ) return;
        all_enemy=enemy[0]->name();
        for (i=1;i<sizeof(enemy);i++)
            all_enemy+=("��"+enemy[i]->name());
        message_vision(HIG+"$N�������һ����â������������ʹ���������޹���������ǵذ㹥��"+all_enemy+"��\n\n" NOR,me);
        me->set_temp("wugou",1);
        for (i=0;i<sizeof(enemy);i++){
            for (j=0;j<(skill/(80*sizeof(enemy)));j++)
                if ((me->is_fighting(enemy[i]) || enemy[i]->is_fighting(me)) && enemy[i]->query("eff_qi")>0 ){
                    if (environment(me) == environment(enemy[i]))
                     {
                        COMBAT_D->do_attack(me, enemy[i], me->query_temp("weapon"), 0);
                     }
                }else break;
        }
    me->delete_temp("wugou");
    me->add("neili",-random(4500)-500);
    }
}

string perform_action_file(string action){	return __DIR__"dagou-bang/" + action;}
