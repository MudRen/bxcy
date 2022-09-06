// douzhuan-xingyi ��ת����
// 1997-2-14
#include <ansi.h>
#include <weapon.h>
#include <combat.h>

inherit SKILL;
#include "/kungfu/skill/eff_msg.h";
int douzhuan(object me, object victim);
string *parry_msg = ({
YEL"�����һ��������������$Nһ��һ����$N��������Խ����������һ��"NOR,	
BLU"$n����һ����������$N��$N����$n������Ī��������ﻬ��һ��"NOR,	
HIW"$n˫��ǰ̽����۴���$N�ұۣ��ұ�ʹ��$N��������$N���л�ȥ"NOR,	
HIY"$n���ƶ�ת��$N����Ī�����������;ת�˷���ֱ���Լ�Ϯ��"NOR,	
YEL"$n�����Ϲۣ�˫����Է��ཻ���ƣ�̸Ц�侹ʹ��$N�������գ�ʹ��$N��֪����Ǻ�"NOR,	
BLU"$n����������$N�͹����ʹ������������$N�ĳ�����������$N��������������"NOR,	
HIW"ֻ��$n����Ʈ�磬ǡ���������ƣ������һʽ��˫�ƶ����޶�����׽��������$N"NOR,	
HIY"$n����Ʈ�������������ƶ�ת֮�䷴��$N����������$N��ȴ����$N��˼�������"NOR,	
});

int valid_enable(string usage)
{
	return usage == "parry";
}

string query_parry_msg(object weapon)
{
	
		return parry_msg[random(sizeof(parry_msg))] + "��\n";
}

int valid_learn(object me)
{
     return notify_fail("��ת����ֻ��ͨ����������ߡ�\n");
}

int practice_skill(object me)
{
	return notify_fail("��ת����ֻ��ͨ����������ߣ��޷�ͨ����ϰ����ߡ�\n");
}

string perform_action_file(string action)
{
	return __DIR__"douzhuan-xingyi/" + action;
}

mixed hit_ob(object ob, object me, int damage)	
{
        string msg;
        int i,p,j,skill, neili, neili1, exp, exp1;
	int hurt;
        object randomtarget, *rob;

	rob = all_inventory(environment(me));
	i = random(sizeof(rob));
	randomtarget = rob[i];

	hurt = damage;
	if ( me->query_temp("mr_bishen", 1) > (random(2)+3) ) {
		me->delete_temp("mr_bishen");
		if( !ob || !ob->is_character() || !me->is_fighting(ob) )
	                return 0;
		call_out("bishen", 0, me, ob);
	}
	damage = hurt;
	me->add_temp("mr_bishen", 1);
        skill = me->query_skill("douzhuan-xingyi", 1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
        exp = me->query("combat_exp");
        exp1 = ob->query("combat_exp");

        if(!living(ob)) return damage;
        if(neili < 300) return damage;

	if ( damage > 0 ) {
		if ( rob[i] && living(rob[i]) && rob[i] != me
		&& rob[i]->is_fighting(me)) {
			if (me->query_skill("douzhuan-xingyi", 1) > 150 && me->query("max_neili") > 2500
			    && me->query("neili") > 1000 && random(me->query("combat_exp")) > me->query("combat_exp")/2 
			    && random(skill)> 100) {
				msg = HIC+BBLU+"$Nʹ��Ľ���书���棬$n����ʽĪ������ػ���"+rob[i]->query("name")+HIC+BBLU+"\n"NOR;
				tell_object(rob[i], HIR"ͻȻ֮�䣬���ȻĪ������ر����С�\n"NOR);
				damage = damage * 2 / 3;
if (ob->query("qi") > damage)
				rob[i]->receive_wound("qi", damage);
                                p = rob[i]->query("qi")*100/rob[i]->query("max_qi");
				msg += "( "+rob[i]->query("name") + eff_status_msg(p)+" )\n";

                                message_vision(msg, me, ob);
				if ( random(rob[i]->query("int")) > me->query("int")*2/3 )
					rob[i]->kill_ob(me);
				return -damage;
			}
		}
		else {
			if ( (random(me->query("combat_exp")) > ob->query("combat_exp")/2)
			     && (random(me->query("str", 1)) > ob->query("str", 1)/2)
			     && (random(me->query("dex", 1)) > ob->query("dex", 1)/2)
			     && (me->query_skill("douzhuan-xingyi", 1)>300) 
			     ) {
				msg = HIC"$Nʹ��Ľ���书���棬��ת���Ƽ�$n���Լ��ĳ����������С�\n"NOR;

				damage =damage/2+random(damage/3);
                                if (ob->query("qi") > damage)
				ob->receive_wound("qi", damage);
				p = ob->query("qi")*100/ob->query("max_qi");
				msg += "( $n"+eff_status_msg(p)+" )\n";
				message_vision(msg, me, ob);
				return -damage;
			}		

			else if ( random(me->query("combat_exp")) > ob->query("combat_exp")/2
				  && (random(me->query("dex", 1)) > ob->query("dex", 1)/2)
				  && (me->query_skill("douzhuan-xingyi", 1)>240) )
			{
				msg = HIY"ͻȻ��$n����������;ת�򣬻������Լ���\n"NOR;

				if (ob->query("qi") > damage/3)
				ob->receive_damage("qi", damage/3);
				p = ob->query("qi")*100/ob->query("max_qi");
				msg += "( $n"+eff_status_msg(p)+" )\n";
				message_vision(msg, me, ob);
				return -damage;
			}

			if ( random(me->query("combat_exp")) > ob->query("combat_exp")/2
			     && (me->query_skill("douzhuan-xingyi", 1)>120) )
			{
				msg = MAG"$n��������$N�Ĵ�������;ת�򣬻�Ϊ���Ρ�\n"NOR;
				message_vision(msg, me, ob);
				return damage/8;
			}
          }
}

if (damage <10)
{
damage=10;      
}

if (me->query_skill("shenyuan-gong",1) <100)
{
           me->delete_temp("dzxy");
           return 1;
}

	 if(me->query_temp("dzxy")){
           me->delete_temp("dzxy");
           return 1;
           }

        if(me->query("jiali") && random(skill)+20 > random(ob->query_skill("parry", 1)) 
         && exp > exp1/2 && skill > 150
         && neili > 300 && living(ob)){
    
   message_vision(HIG"$N��ʱ�Բ�������������������ͼ��$n�Ĺ���ת��$n�Լ����ϣ�\n"NOR,me, ob); 

       if(neili >= neili1+random(neili1)+damage){
            message_vision(HIY"���$n������$N����ͼ����ʽ���䣬$N��һ��ȴδ�ɹ���\n"NOR,me, ob);
            return damage;
            }else{ 
   message_vision(HIR"$nֻ���ƺ�˫�ֲ���ʹ������ʽ��$Nһ��һ����ֱ��$n�Լ�����������\n"NOR,me,ob);
         msg = "";
         if(random(2)==1) me->add_temp("dzxy", 1); 
if (ob->query("qi") > damage)
              ob->receive_damage("qi", damage);
if (ob->query("eff_qi") > damage/10)
              ob->receive_wound("qi", damage/10);
              p = ob->query("qi")*100/ob->query("max_qi");
              msg += "( $n"+eff_status_msg(p)+" )\n";
              j = -(damage*2+skill);
              }
        }else{       
           msg = parry_msg[random(sizeof(parry_msg))];
             if(neili >= random(neili1)+damage){
              msg += HIR"\n��������ж����$n��������\n"NOR;              
              j = -(damage+skill);
              }
           else{
              j = damage/2+random(damage/2); 
              if(j<damage/2) msg += HIC"\n���ж����һЩ$n��������\n"NOR;
              else msg += HIB"\n���ж����$nһ���������\n"NOR;
              j = -j;
              }
           }           
           message_vision(msg, me, ob);
           return j;
          
     
}

void bishen (object me, object ob)
{
	int damage, p;
	object weapon;
	string msg, menpai;
if (!me) return;
if (!ob) return;
if (!living(ob))return;
if (me->query("neili") <500) return;
if (me->query("jing") <100) return;
	damage = (int)me->query_skill("douzhuan-xingyi", 1);
	damage += damage + random (damage);
	menpai = ob->query("family/family_name");
	weapon = me->query_temp("weapon");

	msg = HIW"\n�Ա�֮������ʩ����ͻȻ֮�䣬$Nʹ��$n�ľ�����\n\n"NOR;

	switch ( menpai ) {
	case "������" :
		if ( objectp( me->query_temp("weapon")) ) {
			msg += BLU"\nͻȻ$N���һ�������׶����졹����ɫ৵ı��ͨ�죬�뷢�Էɣ���������" + weapon->name() + BLU"���У����ˡ���һ��������"HIW"��������"BLU"��\n" NOR;
			me->add("neili", -100);
			me->add("jing", -10);
if (ob->query("qi") > damage/2)
			ob->receive_damage("qi", damage/2);
			p = (int)ob->query("qi")*100/(int)ob->query("max_qi");
			msg += "( $n"+eff_status_msg(p)+" )\n";
		}
		else {
			msg += "$N��ȻԾ�����һ��һ������ʱ֮���߳�һ�С�"HIY"��"NOR"���־��Ĵ����ȣ�ֱϮ$nǰ�أ�\n";
			me->add("neili", -100);
			me->add("jing", -10);
if (ob->query("qi") > damage/3)
			ob->receive_damage("qi", damage/3);
			p = (int)ob->query("qi")*100/(int)ob->query("max_qi");
			msg += "( $n"+eff_status_msg(p)+" )\n";
			msg += "\n������$N���ȹ��أ�������һŤ�������ȵ�һ�С�"HIY"Ӱ"NOR"���־���������������$n��\n";
			me->add("neili", -100);
			me->add("jing", -10);
if (ob->query("qi") > damage/3)
			ob->receive_damage("qi", damage/3);
			p = (int)ob->query("qi")*100/(int)ob->query("max_qi");
			msg += "( $n"+eff_status_msg(p)+" )\n";
			msg += "\nֻ��$N�ҽž���δ���������һת������˳��ɨ��һ�С�"HIY"��"NOR"���־�����Ӱ������\n";
			me->add("neili", -100);
			me->add("jing", -10);
if (ob->query("qi") > damage/3)
			ob->receive_damage("qi", damage/3);
			p = (int)ob->query("qi")*100/(int)ob->query("max_qi");
			msg += "( $n"+eff_status_msg(p)+" )\n";
			msg += "\n�����$N��δ�󳷣��Ѿ�����"HIY"��"NOR"���־����ھ�ֱ͸�ż⣬��$n�ظ�����������ʮ�£�\n";
			me->add("neili", -100);
			me->add("jing", -10);
if (ob->query("qi") > damage/3)
			ob->receive_damage("qi", damage/3);
			p = (int)ob->query("qi")*100/(int)ob->query("max_qi");
			msg += "( $n"+eff_status_msg(p)+" )\n";
		}
	break;
	case "������" :
		if ( objectp( me->query_temp("weapon")) )
			msg += HIW "\n$NƮ�����ʹ�����Ҿ������𽣡��ķ�����ʱ�������Ʈ�ݣ�����ǧ�������裬����ͷ�����
������$n����֮�£���ʱ����ɢ�ң��޴��мܣ�\n\n" NOR;
		else
			msg += MAG "\nֻ��$N����ׯ�ϣ�һʽ��"HIY"�������"MAG"������һ��������Ʈ����ϣ���������ƽ���һ���ھ���������
�ˣ������������Ƶ磬��һ���ĳ�������$n����ʽƽƽ������һ�ɲ��䣬��ȴ���޿ɵ������޿ɱܣ�\n"NOR;
		me->add("neili", -100);
		me->add("jing", -10);
if (ob->query("qi") > damage/5)
		ob->receive_wound("qi", damage/5);
		p = (int)ob->query("qi")*100/(int)ob->query("max_qi");
		msg += "( $n"+eff_status_msg(p)+" )\n";
	break;
	case "����μ�" :
		if ( objectp( me->query_temp("weapon")) ) 
			msg += BLU"\n $N��Цһ�����������֣�������ϣ�ʩչ�������Ļ�������,��ͼ���ٻ���$n \n"NOR;
		else
			msg += YEL "\n$N������ָ��һʽ������������������������������죬һ�ɴ���������ֱϮ$n�ؿڣ�\n" NOR;
		me->add("neili", -100);
		me->add("jing", -10);
if (ob->query("qi") > damage/4)
		ob->receive_wound("qi", damage/4);
		ob->start_busy(1);
		p = (int)ob->query("qi")*100/(int)ob->query("max_qi");
		msg += "( $n"+eff_status_msg(p)+" )\n";
	break;
	case "�䵱��" :
		if ( objectp( me->query_temp("weapon")) ) {
			msg += CYN"\n$Nʹ��̫������"RED"������"CYN"�־���һ��"+weapon->name()+CYN"�ڻ���һ����ԲȦ��ÿһ�о����Ի��δ̳��������ջء�
���ڽ��ȣ����಻��������������һ�Ŵ���������$n�ս���\n\n"NOR;
			msg += HIY"���̫������ɢ������ϸ˿Խ��Խ�࣬���ǻ�����һ����˿�ޣ���$n��������������\n"NOR;
if (!ob->is_busy() && random(3)==0)
			ob->start_busy(4);
		}
		else {
			msg += CYN"̫��֮�����಻�ϣ�������ȥ�пգ�һ��ԲȦδ�꣬�ڶ���ԲȦ����������һ�죬$pһ����ͷ���ʶϣ�\n"NOR;
			me->add("neili", -100);
			me->add("jing", -10);
if (ob->query("qi") > damage/3)
			ob->receive_wound("qi", damage/3);
			p = (int)ob->query("qi")*100/(int)ob->query("max_qi");
			msg += "( $n"+eff_status_msg(p)+" )\n";
		}
	break;
	case "��ɽ��" :
		if ( objectp( me->query_temp("weapon")) ) {
			if ( me->query("gender") == "����")
				msg += HIC"��Хһ����ʹ��ƽ���������������������ǻ�ɽ���ھ�ѧ��"HIY"�����������ɽ�"HIC"����\n"NOR;
			else 
				msg += HIC"$NͻȻʹ����ɽ������һʽ����˫�޶ԣ���ʽһ������ֻ��$Nͦ��
ֱ������ʽ��磬����֮���������������ף������ѽ�$nȫ�����֡�\n"NOR;

			msg += "$n��ôҲ�벻��$N��ʹ���Լ��ĳ���������һʱ�䲻֪���롣\n"NOR;
if (!ob->is_busy()&& random(3)==0)
			ob->start_busy(3);
		}
		else {
			msg += MAG"$Nʹ����ʯ����ȭ�ľ�ѧ�׶����죬��ʱ��յ���������\n"NOR;
			me->add("neili", -100);
			me->add("jing", -10);

if (ob->query("qi") > damage/4)
			ob->receive_wound("qi", damage/4);
			p = (int)ob->query("qi")*100/(int)ob->query("max_qi");
			msg += "( $n"+eff_status_msg(p)+" )\n";
		}
	break;
	case "�һ���" :
		if ( objectp( me->query_temp("weapon")) ) {
			msg += CYN "$N���һֻ����յ���ߣ��������£�����Ͳ��ͻȻ���һ����⣬ֱ��$n��\n";
			msg += "$n��������������ǰ�أ�\n";
		}
		else
			msg += GRN "$Nһ����Х��ȭ����ʩ��ʹ���һ�����������Ѹ�����׵ع���$n��\n"NOR;
		me->add("neili", -100);
		me->add("jing", -10);
if (ob->query("qi") > damage/4)
		ob->receive_wound("qi", damage/4);
		p = (int)ob->query("qi")*100/(int)ob->query("max_qi");
		msg += "( $n"+eff_status_msg(p)+" )\n";
	break;			
	case "ؤ��" :
		if ( objectp( me->query_temp("weapon")) ) {
			msg += HIG"$N��"+ weapon->name() + HIG"������ʹ���򹷰��������֡�����ֻ��һ����Ӱ��$n�������˹�ȥ��\n";
			msg += HIY "���$p��$P���˸����ֲ�����\n" NOR;
if (!ob->is_busy()&& random(3)==0)
			ob->start_busy(3);
		}
		else {
			 msg += HIM"\n$N˫��ƽ��ǰ�أ�����֮���������У����ֻ�������$n���������赭д��\n"+
                HIG"��һ������������������ھ���һ��ǿ��һ������Х����$n��ȥ��\n"NOR;
			me->add("neili", -100);
			me->add("jing", -10);
if (ob->query("qi") > damage/3)
			ob->receive_wound("qi", damage/3);
			p = (int)ob->query("qi")*100/(int)ob->query("max_qi");
			msg += "( $n"+eff_status_msg(p)+" )\n";
		}
	break;
	case "����" :
		if ( objectp( me->query_temp("weapon")) ) {
			msg += HIW"\n������ʹ����ʥ�������ѧ"BLU"���絶"HIW"������һ���������ʵ�����֮����ֱ��"+ob->name()+"�ؿ�����ѨҪѨ��\n"NOR;
if (ob->query("qi") > damage/2)
			ob->receive_wound("qi", damage/2);
		}
		else {
			msg += HIR"\nͻȻ$N���侫�⣬����������Ƹ�Ǹ衢��ʫ��ʫ��ȭ������������������Ƿ������������ǰȥ�����һȭ����$n��\n"NOR;
			msg += HIW"�ڸ�һ����"+ob->name()+"������ʱ����㰵������������������ȭ�ڵ������������˹�ȥ��\n"NOR;
if (ob->query("qi") > damage)
			ob->receive_wound("qi", damage);
		}
		me->add("neili", -100);
		me->add("jing", -10);
if (!ob->is_busy()&& random(3)==0)
		ob->start_busy(2);
		p = (int)ob->query("qi")*100/(int)ob->query("max_qi");
		msg += "( $n"+eff_status_msg(p)+" )\n";
	break;
	case "������" :
		if ( objectp( me->query_temp("weapon")) ) {
			msg += HIY"\n$N��$n��������֮����ƴ��ȫ��ʹ�����������֮����������Ӣ�����С���\n"NOR;
if (ob->query("qi") > damage/2)
			ob->receive_wound("qi", damage/2);
		}
		else {
			msg += HIR"\n$N��Ȼ��һ������˫��һ�����������ƣ���$n������ĳ���$n��\n"NOR;
if (ob->query("qi") > damage)
			ob->receive_wound("qi", damage);
		}
		me->add("neili", -100);
		me->add("jing", -10);
if (!ob->is_busy()&& random(3)==0)
		ob->start_busy(2);
		p = (int)ob->query("qi")*100/(int)ob->query("max_qi");
		msg += "( $n"+eff_status_msg(p)+" )\n";
	break;
	case "��Ĺ��" :
		if ( objectp( me->query_temp("weapon")) ) {
			msg += HIB"\n$N���һ�����ֳ�������Ю���˳�ӿ֮��,������죬������ᣬ����Ȼ�����������֮���������ߴΣ�ϯ���ȥ����\n"NOR;
if (ob->query("qi") > damage/2)
			ob->receive_wound("qi", damage/2);
		}
		else {
			msg += HIR"\n$N������֮ɫ�����������ң�û����ɵĻ����������ĳ�һ�ƣ�$n��\n"NOR;
if (ob->query("qi") > damage)
			ob->receive_wound("qi", damage);
		}
		me->add("neili", -200);
		me->add("jing", -10);
if (!ob->is_busy()&& random(3)==0)
		ob->start_busy(2);
		p = (int)ob->query("qi")*100/(int)ob->query("max_qi");
		msg += "( $n"+eff_status_msg(p)+" )\n";
	break;
	case "������" :
		if ( objectp( me->query_temp("weapon")) ) {
			msg += HIB"\n$Nһ����Ц������һ�ź��ư��������������ϸ�뼲ָ˫Ŀ��\n"NOR;
if (ob->query("qi") > damage/2)
			ob->receive_wound("qi", damage/2);
		}
		else {
			msg += HIR"\n$N��¶����֮ɫ��˫��ɫ�����ϣ�ԭ��������Ʒ羹���������Ϣ��\n"NOR;
if (ob->query("qi") > damage)
			ob->receive_wound("qi", damage);
		}
		me->add("neili", -200);
		me->add("jing", -10);
if (!ob->is_busy()&& random(3)==0)
		ob->start_busy(2);
		p = (int)ob->query("qi")*100/(int)ob->query("max_qi");
		msg += "( $n"+eff_status_msg(p)+" )\n";
	break;
	case "���չ�" :
		if ( objectp( me->query_temp("weapon")) ) {
			msg += HIC"\n$N����Ϣ�������󼲶������ǧ�������������ǵط���$n��\n"NOR;
if (ob->query("qi") > damage/2)
			ob->receive_wound("qi", damage/2);
		}
		else {
			msg += HIC"\n$N��ˮΪ�����������У�˫ָһ�������ϼ�����⼱������$n\n"NOR;
                if (ob->query("qi") > damage)
			ob->receive_wound("qi", damage);
		}
		me->add("neili", -100);
		me->add("jing", -10);
                if (!ob->is_busy()&& random(3)==0)
		ob->start_busy(2);
		p = (int)ob->query("qi")*100/(int)ob->query("max_qi");
		msg += "( $n"+eff_status_msg(p)+" )\n";
	break;

	case "��ң��" :
		if ( objectp( me->query_temp("weapon")) ) {
			msg += HIY"\n$Nһ����Ц��ֻ���������⣬�������أ��Ĺ�ʲô�Ƿ����裬����һ����������\n"NOR;
if (ob->query("qi") > damage/2)
			ob->receive_wound("qi", damage/2);
		}
		else {
                        msg += CYN"\n$N��ˮΪ�����������У�˫ָһ�������ϼ�����⼱������$n\n"NOR;
                if (ob->query("qi") > damage)
			ob->receive_wound("qi", damage);
		}
		me->add("neili", -100);
		me->add("jing", -10);
                if (!ob->is_busy()&& random(3)==0)
		ob->start_busy(2);
		p = (int)ob->query("qi")*100/(int)ob->query("max_qi");
		msg += "( $n"+eff_status_msg(p)+" )\n";
	break;
	case "����ɽ��" :
		if ( objectp( me->query_temp("weapon")) ) {
			msg += HIY"\n$Nͻ�������Ĵӿ��������������$n��ǰ����һ�ȣ�\n"NOR;
if (ob->query("qi") > damage/2)
			ob->receive_wound("qi", damage/2);
		}
		else {
                        msg += BLU"\n$N���Ӷ��£�����ƽ�ƶ�����ʹ������$N��ƽ�����ġ���󡹦�����У��Ʒ�ֱ��$n��ȥ��\n"NOR;
                if (ob->query("qi") > damage)
			ob->receive_wound("qi", damage);
		}
		me->add("neili", -100);
		me->add("jing", -10);
                if (!ob->is_busy()&& random(3)==0)
		ob->start_busy(2);
		p = (int)ob->query("qi")*100/(int)ob->query("max_qi");
		msg += "( $n"+eff_status_msg(p)+" )\n";
	break;
	case "ѩɽ��" :
		if ( objectp( me->query_temp("weapon")) ) {
			msg += HIY"\n$N���ִ��ڷ�������б��һ���������ڿ��л���һ�����ߣ���$n��ȥ��\n"NOR;
if (ob->query("qi") > damage/2)
			ob->receive_wound("qi", damage/2);
		}
		else {
                        msg += RED"\n$N�������ƣ�ʹ��һ�С������Ի𡹣���$n���ؿڻ�ȥ��\n"NOR;
                if (ob->query("qi") > damage)
			ob->receive_wound("qi", damage);
		}
		me->add("neili", -100);
		me->add("jing", -10);
                if (!ob->is_busy()&& random(3)==0)
		ob->start_busy(2);
		p = (int)ob->query("qi")*100/(int)ob->query("max_qi");
		msg += "( $n"+eff_status_msg(p)+" )\n";
	break;
	case "������" :
		if ( objectp( me->query_temp("weapon")) ) {
			msg += HIR"\n$N���赭д���ӳ����⣬һ˲�����ʹ������ʮ��ʽ�����е������������� 
�������Ǻ�ˮ�����$n�̳�,��ؼ��ݷ������ɱ����\n"NOR;
if (ob->query("qi") > damage/2)
			ob->receive_wound("qi", damage/2);
		}
		else {
                        msg += RED"\n$N��ȫ��ľ���ע��˫��,�߸�Ծ��**��Ѫ��ץ**��һץץ�����Ʋ��ɵ���\n"NOR;
                if (ob->query("qi") > damage)
			ob->receive_wound("qi", damage);
		}
		me->add("neili", -100);
		me->add("jing", -10);
                if (!ob->is_busy()&& random(3)==0)
		ob->start_busy(2);
		p = (int)ob->query("qi")*100/(int)ob->query("max_qi");
		msg += "( $n"+eff_status_msg(p)+" )\n";
	break;
	case "ȫ���" :
		if ( objectp( me->query_temp("weapon")) ) {
			msg += YEL"\n$Nʹ��ȫ���ɾ�����һ�������塹������Ȼ�ӿ�,���ս����γ�����������\n"NOR;
if (ob->query("qi") > damage/2)
			ob->receive_wound("qi", damage/2);
		}
		else {
                        msg += HIR"\n$Nŭ��һ�����վ�ȫ����ͻȻ����㹥��ȭ���ơ����������У�\n"NOR;
                if (ob->query("qi") > damage)
			ob->receive_wound("qi", damage);
		}
		me->add("neili", -100);
		me->add("jing", -10);
                if (!ob->is_busy()&& random(3)==0)
		ob->start_busy(2);
		p = (int)ob->query("qi")*100/(int)ob->query("max_qi");
		msg += "( $n"+eff_status_msg(p)+" )\n";
	break;
	case "���ư�" :
		if ( objectp( me->query_temp("weapon")) ) {
			msg += CYN"\n$NͻȻ����һ���������ң����ң��������ң��������о޸���Ȼ����$n���б��У�\n"NOR;
if (ob->query("qi") > damage/2)
			ob->receive_wound("qi", damage/2);
		}
		else {
                        msg += HIR"\n$N����۹�Ԫ���ɷ��ݣ�ͬʱʹ�������ƽ�����һ��һ����������糱ˮ��Ļ���$n��\n"NOR;
                if (ob->query("qi") > damage)
			ob->receive_wound("qi", damage);
		}
		me->add("neili", -100);
		me->add("jing", -10);
                if (!ob->is_busy()&& random(3)==0)
		ob->start_busy(2);
		p = (int)ob->query("qi")*100/(int)ob->query("max_qi");
		msg += "( $n"+eff_status_msg(p)+" )\n";
	break;
	case "������" :
		if ( objectp( me->query_temp("weapon")) ) {
			msg += HIC"\n$N���г�����âԾ�������Ⱪ������������ƺ������Ҵ���$n\n"NOR;
if (ob->query("qi") > damage/2)
			ob->receive_wound("qi", damage/2);
		}
		else {
                        msg += HIG"\n$N����һ���������һ������������"HIW+ (random(10)+1) +HIG"�ƣ���������ǰ�У�����������һ������$n��\n"NOR;
                if (ob->query("qi") > damage)
			ob->receive_wound("qi", damage);
		}
		me->add("neili", -100);
		me->add("jing", -10);
                if (!ob->is_busy()&& random(3)==0)
		ob->start_busy(2);
		p = (int)ob->query("qi")*100/(int)ob->query("max_qi");
		msg += "( $n"+eff_status_msg(p)+" )\n";
	break;
	case "�������" :
		if ( objectp( me->query_temp("weapon")) ) {
			msg += YEL"\n$N"+RED+"����೤Ц��������ħ�����������С�\n"NOR;
if (ob->query("qi") > damage/2)
			ob->receive_wound("qi", damage/2);
		}
		else {
                        msg += RED"\n$N�͵�������$n��ȥ����ָһ����ϸ����˳�ȥ������$n��Ŀ��\n"NOR;
                if (ob->query("qi") > damage)
			ob->receive_wound("qi", damage);
		}
		me->add("neili", -100);
		me->add("jing", -10);
                if (!ob->is_busy()&& random(3)==0)
		ob->start_busy(2);
		p = (int)ob->query("qi")*100/(int)ob->query("max_qi");
		msg += "( $n"+eff_status_msg(p)+" )\n";
	break;
	case "������" :
		if ( objectp( me->query_temp("weapon")) ) {
			msg += HIW"\n$N��Хһ��,ʹ������÷Ʈ�㡹,���б�������,�������ѩ����ǰ����ǵص���ȥ��\n"
    "�ڰ�ãã��һƬ��,��Ȼ�������÷���ν���,��͸ѩĻ,������˷����������\n"NOR;
if (ob->query("qi") > damage/2)
			ob->receive_wound("qi", damage/2);
		}
		else {
                        msg += HIW"\n$N��ѩ�ķ���תһ���죬ȫ��ֻ��һ�ɺ�����������,��Хһ��,\n"
"�������,ʩչ����"+HIW"��ѩ��÷����˫��һ��һ��,һ��������Ѫ��\n"
"�����$n����ǵ�ϯ���ȥ��\n"NOR;
                if (ob->query("qi") > damage)
			ob->receive_wound("qi", damage);
		}
		me->add("neili", -100);
		me->add("jing", -10);
                if (!ob->is_busy()&& random(3)==0)
		ob->start_busy(2);
		p = (int)ob->query("qi")*100/(int)ob->query("max_qi");
		msg += "( $n"+eff_status_msg(p)+" )\n";
	break;

	case "�嶾��" :
		if ( objectp( me->query_temp("weapon")) ) {
			msg += HIY"\n$N������⿪����ͷɢ������ɫͻȻ��ף����е�"+weapon->name()+"Ҳ���ž��Ҷ����ţ�
ͻȻ$Nһ���񺿣�����޹���Ƶ���Х������أ������ƵĽ��嶾׷�깳����ʹ����\n"NOR;
if (ob->query("qi") > damage/2)
			ob->receive_wound("qi", damage/2);
		}
		else {
                        msg += HIR"\n$Nһ����Ц�����������һָ��$n��ü�ĵ�ȥ��\n"NOR;
                if (ob->query("qi") > damage)
			ob->receive_wound("qi", damage);
		}
		me->add("neili", -100);
		me->add("jing", -10);
                if (!ob->is_busy()&& random(3)==0)
		ob->start_busy(2);
		p = (int)ob->query("qi")*100/(int)ob->query("max_qi");
		msg += "( $n"+eff_status_msg(p)+" )\n";
	break;
	case "����" :
		if ( objectp( me->query_temp("weapon")) ) {
			msg += HIM"\n$N˫ĿͻȻ���������̹�,��ָ�ڲ��ײ����΢΢һ��,һ������������Ϣ����$nü�ġ���\n"NOR;
if (ob->query("qi") > damage/2)
			ob->receive_wound("qi", damage/2);
		}
		else {
                        msg += HIM"\n$NͻȻ���ƣ�Ȼ��Ѹ�ٷ���! ���о�Ȼ�ж�ɰ�����Ʒ羡Ȼ��������ɫ�ģ���\n"NOR;
                if (ob->query("qi") > damage)
			ob->receive_wound("qi", damage);
		}
		me->add("neili", -100);
		me->add("jing", -10);
                if (!ob->is_busy()&& random(3)==0)
		ob->start_busy(2);
		p = (int)ob->query("qi")*100/(int)ob->query("max_qi");
		msg += "( $n"+eff_status_msg(p)+" )\n";
	break;
	case "����������" :
		if ( objectp( me->query_temp("weapon")) ) {
			msg += HIM"\n$Nʹ����������������߽�����" + HIR "��������" +HIW "��$nֻ��$N����һ�����ʺ��ѱ��Դ������� \n"NOR;
if (ob->query("qi") > damage/2)
			ob->receive_wound("qi", damage/2);
		}
		else {
                        msg += HIM"\n�����ؾ�!��$Nȫ�����һ����,ƴ����������ʹ����������ȭ�����ռ�������\n"NOR;
                if (ob->query("qi") > damage)
			ob->receive_wound("qi", damage);
		}
		me->add("neili", -100);
		me->add("jing", -10);
                if (!ob->is_busy()&& random(3)==0)
		ob->start_busy(2);
		p = (int)ob->query("qi")*100/(int)ob->query("max_qi");
		msg += "( $n"+eff_status_msg(p)+" )\n";
	break;
	default :
		msg += HIW"$Nʹ��$n�ĳ���������ɲ�Ǽ�һ����ɽ����֮������$n��\n"NOR;
		me->add("neili", -100);
		me->add("jing", -10);
                if (ob->query("qi") > damage/3)
		ob->receive_wound("qi", damage/3);
               if (!ob->is_busy()&& random(3)==0)
		ob->start_busy(2);
		p = (int)ob->query("qi")*100/(int)ob->query("max_qi");
		msg += "( $n"+eff_status_msg(p)+" )\n";
	}
	message_vision(msg, me, ob);
}
