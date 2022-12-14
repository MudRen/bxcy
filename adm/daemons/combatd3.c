// combatd.c
// #pragma save_binary
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_DBASE;
mapping prepare;
mapping limb_damage = ([
// 人类身体部位
        "头部"  :   100,
        "颈部"  :   90,
        "胸口"  :   90,
        "后心"  :   80,
        "左肩"  :   50,
        "右肩"  :   55,
        "左臂"  :   40,
        "右臂"  :   45,
        "左手"  :   20,
        "右手"  :   30,
        "腰间"  :   60,
        "小腹"  :   70,
        "左腿"  :   40,
        "右腿"  :   50,
        "左脚"  :   35,
        "右脚"  :   40,
//  动物身体部位
        "身体"  :   80,
        "前脚"  :   40,
        "后脚"  :   50,
        "腿部"  :   40,
        "尾巴"  :   10,
        "翅膀"  :   50,
        "爪子"  :   40,
]);

string *guard_msg = ({
    CYN "$N注视著$n的行动，企图寻找机会出手。\n" NOR,
    CYN "$N正盯著$n的一举一动，随时准备发动攻势。\n" NOR,
    CYN "$N缓缓地移动脚步，想要找出$n的破绽。\n" NOR,
    CYN "$N目不转睛地盯著$n的动作，寻找进攻的最佳时机。\n" NOR,
    CYN "$N慢慢地移动著脚步，伺机出手。\n" NOR,
});
string *catch_hunt_msg = ({
    HIW "$N和$n仇人相见分外眼红，立刻打了起来！\n" NOR,
    HIW "$N对著$n大喝：「可恶，又是你！」\n" NOR,
    HIW "$N和$n一碰面，二话不说就打了起来！\n" NOR,
    HIW "$N一眼瞥见$n，「哼」的一声冲了过来！\n" NOR,
    HIW "$N一见到$n，愣了一愣，大叫：「我宰了你！」\n" NOR,
    HIW "$N喝道：「$n，我们的帐还没算完，看招！」\n" NOR,
    HIW "$N喝道：「$n，看招！」\n" NOR,});
string *winner_msg = ({
    CYN "\n$N哈哈大笑，愉快地说道：承让了！\n\n" NOR,
    CYN "\n$N双手一拱，笑著说道：知道我的利害了吧！\n\n" NOR,
    CYN "\n$N哈哈大笑，双手一拱，笑著说道：承让！\n\n" NOR,
    CYN "\n$N胜了这招，向后跃开三尺，笑道：承让！\n\n" NOR,
    CYN "\n$n脸色微变，说道：佩服，佩服！\n\n" NOR,
    CYN "\n$n向后退了几步，说道：这场比试算我输了，佩服，佩服！\n\n" NOR,
    CYN "\n$n向后一纵，躬身做揖说道：阁下武艺不凡，果然高明！\n\n" NOR,
});
void create()
{
    seteuid(getuid());
    set("name", "战斗精灵");
    set("id", "combatd");
}
string damage_msg(int damage, string type,object ob)
{
    string str;
    int qi=ob->query("qi");
//  return "造成 " + damage + " 点" + type + "。\n";
    if( damage == 0 ) return "结果没有造成任何伤害。\n";
    if (qi>0){
        damage=damage*100;
        damage /= qi;
    }else
        damage=120;
    switch( type ) {
    case "擦伤":
    case "割伤":
        if( damage < 5 ) return "结果只是轻轻地划破$p的皮肉。\n";
        else if( damage < 10 ) return "结果在$p$l划出一道细长的血痕。\n";
        else if( damage < 20 ) return "结果「嗤」地一声划出一道伤口！\n";
        else if( damage < 40 ) return "结果「嗤」地一声划出一道血淋淋的伤口！\n";
        else if( damage < 80 ) return "结果「嗤」地一声划出一道又长又深的伤口，溅得$N满脸鲜血！\n";
        else return "结果只听见$n一声惨嚎，$w已在$p$l划出一道深及见骨的可怕伤口！！\n";
        break;
    case "刺伤":
        if( damage < 10 ) return "结果只是轻轻地刺破$p的皮肉。\n";
        else if( damage < 20 ) return "结果在$p$l刺出一个创口。\n";
        else if( damage < 40 ) return "结果「噗」地一声刺入了$n$l寸许！\n";
        else if( damage < 60 ) return "结果「噗」地一声刺进$n的$l，使$p不由自主地退了几步！\n";
        else if( damage < 80 ) return "结果「噗嗤」地一声，$w已在$p$l刺出一个血肉模糊的血窟窿！\n";
        else return "结果只听见$n一声惨嚎，$w已在$p的$l对穿而出，鲜血溅得满地！！\n";
        break;
    case "瘀伤":
        if( damage < 5 ) return "结果只是轻轻地碰到，比拍苍蝇稍微重了点。\n";
        else if( damage < 10 ) return "结果在$p的$l造成一处瘀青。\n";
        else if( damage < 25 ) return "结果一击命中，$n的$l登时肿了一块老高！\n";
        else if( damage < 40 ) return "结果一击命中，$n闷哼了一声显然吃了不小的亏！\n";
        else if( damage < 50 ) return "结果「砰」地一声，$n退了两步！\n";
        else if( damage < 60 ) return "结果这一下「砰」地一声打得$n连退了好几步，差一点摔倒！\n";
        else if( damage < 80 ) return "结果重重地击中，$n「哇」地一声吐出一口鲜血！\n";
        else return "结果只听见「砰」地一声巨响，$n像一捆稻草般飞了出去！！\n";
        break;
    case "内伤":
        if( damage < 10 ) return "结果只是把$n打得退了半步，毫发无损。\n";
        else if( damage < 20 ) return "结果$n痛哼一声，在$p的$l造成一处瘀伤。\n";
        else if( damage < 30 ) return "结果一击命中，把$n打得痛得弯下腰去！\n";
        else if( damage < 40 ) return "结果$n闷哼了一声，脸上一阵青一阵白，显然受了点内伤！\n";
        else if( damage < 60 ) return "结果$n脸色一下变得惨白，昏昏沉沉接连退了好几步！\n";
        else if( damage < 75 ) return "结果重重地击中，$n「哇」地一声吐出一口鲜血！\n";
        else if( damage < 90 ) return "结果「轰」地一声，$n全身气血倒流，口中鲜血狂喷而出！\n";
        else return "结果只听见几声喀喀轻响，$n一声惨叫，像滩软泥般塌了下去！！\n";
        break;
    default:
        if( !type ) type = "伤害";
        if( damage < 10 ) str =  "结果只是勉强造成一处轻微";
        else if( damage < 20 ) str = "结果造成轻微的";
        else if( damage < 30 ) str = "结果造成一处";
        else if( damage < 50 ) str = "结果造成一处严重";
        else if( damage < 60 ) str = "结果造成颇为严重的";
        else if( damage < 70 ) str = "结果造成相当严重的";
        else if( damage < 80 ) str = "结果造成十分严重的";
        else if( damage < 90 ) str = "结果造成极其严重的";
        else str =  "结果造成非常可怕的严重";
        return str + type + "！\n";
    }
}
string eff_status_msg(int ratio)
{
    if( ratio==100 ) return HIG "看起来气血充盈，并没有受伤。" NOR;
    if( ratio > 95 ) return HIG "似乎受了点轻伤，不过光从外表看不大出来。" NOR;
    if( ratio > 90 ) return HIY "看起来可能受了点轻伤。" NOR;
    if( ratio > 80 ) return HIY "受了几处伤，不过似乎并不碍事。" NOR;
    if( ratio > 60 ) return HIY "受伤不轻，看起来状况并不太好。" NOR;
    if( ratio > 40 ) return RED "气息粗重，动作开始散乱，看来所受的伤著实不轻。" NOR;
    if( ratio > 30 ) return RED "已经伤痕累累，正在勉力支撑著不倒下去。" NOR;
    if( ratio > 20 ) return RED "受了相当重的伤，只怕会有生命危险。" NOR;
    if( ratio > 10 ) return HIR "伤重之下已经难以支撑，眼看就要倒在地上。" NOR;
    if( ratio > 5  ) return HIR "受伤过重，已经奄奄一息，命在旦夕了。" NOR;
    return HIR "受伤过重，已经有如风中残烛，随时都可能断气。" NOR;
}
string status_msg(int ratio)
{
    if( ratio==100 ) return HIG "看起来充满活力，一点也不累。" NOR;
    if( ratio > 95 ) return HIG "似乎有些疲惫，但是仍然十分有活力。" NOR;
    if( ratio > 90 ) return HIY "看起来可能有些累了。" NOR;
    if( ratio > 80 ) return HIY "动作似乎开始有点不太灵光，但是仍然有条不紊。" NOR;
    if( ratio > 60 ) return HIY "气喘嘘嘘，看起来状况并不太好。" NOR;
    if( ratio > 40 ) return RED "似乎十分疲惫，看来需要好好休息了。" NOR;
    if( ratio > 30 ) return RED "已经一副头重脚轻的模样，正在勉力支撑著不倒下去。" NOR;
    if( ratio > 20 ) return RED "看起来已经力不从心了。" NOR;
    if( ratio > 10 ) return HIR "摇头晃脑、歪歪斜斜地站都站不稳，眼看就要倒在地上。" NOR;
    return HIR "已经陷入半昏迷状态，随时都可能摔倒晕去。" NOR;
}
varargs void report_status(object ob, int effective)
{
    if( effective )
        message_vision( "( $N" + eff_status_msg(
            (int)ob->query("qi") * 100 / (int)ob->query("max_qi") )
            + " )\n", ob);
    else
        message_vision( "( $N" + status_msg(
            (int)ob->query("qi") * 100 / (int)ob->query("max_qi") )
            + " )\n", ob);
}
// This function calculates the combined skill/combat_exp power of a certain
// skill. This value is used for A/(A+B) probability use.
varargs int skill_power(object ob, string skill, int usage)
{
    int status, level, power;

    if( !living(ob) ) return 0;
    if (ob->over_encumbranced())    return 0;
    status=1;
    if (ob->query("max_qi")<1 || ob->query("max_jing")<1) return 1;
    else {
        status=(ob->query("eff_qi")*10)/ob->query("max_qi");
    status=status*(ob->query("jing")*10)/ob->query("max_jing");
    }
    if (status<1)   return 1;
    level = ob->query_skill(skill)/5;
    switch(usage) {
        case SKILL_USAGE_ATTACK:
            level += ob->query_temp("apply/attack");
            if (ob->is_fighting())
                level +=  ob->query_temp("fight/attack");
            break;
        case SKILL_USAGE_DEFENSE:
            level += ob->query_temp("apply/defense");
            if (ob->is_fighting())
                level += ( ob->query_temp("fight/dodge")+ ob->query_temp("fight/parry"));
            break;
    }
    if( !level || level<1){
        power=(int)ob->query("combat_exp")/2;
        if (power>10000000){
            power /= 100;
            power*=status;
        }else{
            power *= status;
            power/=100;
        }
        return  power;
    }
    // here need a modification later
     power=level*level;
    if (usage == SKILL_USAGE_ATTACK){
        if (skill=="unarmed")
        power*=(ob->query_str() + ob->query_temp("str")-ob->query("jiali"));
        else
        power*=(ob->query("str") + ob->query_temp("str")+ob->query_skill(skill,1)/20);
        power=(power/5);
    }else
        power*=(ob->query_dex()/5 + ob->query_temp("dex"));

      power += (ob->query("combat_exp"));
    if (power>10000000){
        power /= 100;
        power*=status;
    }else{
        power *= status;
        power/=100;
    }
    if (level>3000 && power<0) return 2100000000;
    return power;
}
// do_attack()
//
// Perform an attack action. This function is called by fight() or as an
// interface for some special utilize in quests.
//
int vic_exp, me_exp,em,max_tili,tili;
varargs int do_attack(object me, object victim, object weapon, int attack_type)
{
    mapping my, your,action;
    string limb, *limbs, result,dodge_msg,parry_msg;
    string attack_skill, martial_skill, dodge_skill, parry_skill;
    mixed foo;
    int ap, dp, pp ;
    int damage, damage_bonus, defense_factor;
    int cost;
    int wounded = 0;

    if (!living(me)) return 1;
    // added by snow@jhfy (战斗中精力或者精下降，18岁以前降精神，以后降精力)
/*    if(me->query("age")>60)
        {    	max_tili = me->query("max_jingli");
        tili = me->query("jingli");
       }
     if(max_tili==0)
        max_tili = 1;
    if (userp(me)) {

		em = sizeof(me->query_enemy())+1;
		if(me->query("age")>60)
                      me->add("jingli", -(2+random(2))*em);
		        if (tili * 100 / max_tili < 100)
                     tell_object(me, HIR "\n太累了，你的体力快消耗完了！\n" NOR);
	}
	if (userp(victim) && living(victim)
	&& 3*me->query("combat_exp") >= 2*victim->query("combat_exp")) {
        if(me->query("age")>60)
          me->add("jingli", -(2+random(2))*em);
		if (tili * 100 / max_tili < 100)
        tell_object(me, HIR "\n太累了，你的体力快消耗完了！\n" NOR);
	}
*/

    my = me->query_entire_dbase();
    your = victim->query_entire_dbase();
    prepare = me->query_skill_prepare();
    vic_exp = victim->query("combat_exp");
    me_exp = me->query("combat_exp");
    if (!prepare) prepare = ([]);
    //
    // (0) Choose skills.
    //
    me->delete_temp("fight");
    victim->delete_temp("fight");

    if( objectp(weapon) )   attack_skill = weapon->query("skill_type");
    else if ( sizeof(prepare) == 0)	attack_skill = "unarmed";
    else if ( sizeof(prepare) == 1)	attack_skill = (keys(prepare))[0];
    else if ( sizeof(prepare) == 2)	attack_skill = (keys(prepare))[me->query_temp("action_flag")];
    //else attack_skill = "unarmed";

    //
    // (1) Find out what action the offenser will take.
    //
    me->reset_action();
    action = me->query("actions");
    if( !mapp(action) ) {
        me->reset_action();
        action = me->query("action");
        if( !mapp(action) ) {
            CHANNEL_D->do_channel( this_object(), "sys",
                sprintf("%s(%s): bad action = %O",
                    me->name(1), me->query("id"), me->query("actions", 1)));
            return 0;
        }
    }
    if (stringp(me->query_temp("action_msg"))){
        result = "\n" + (string)me->query_temp("action_msg")+ action["action"] + "！\n";
        me->delete_temp("action_msg");
    }else if (me->query_temp("action_flag") == 0)
		result = "\n" + action["action"] + "！\n";
	else
		result = "\n" + "紧跟着"+action["action"] + "!\n";

    //
    // (2) Prepare AP, DP for checking if hit.
    //
    limbs = victim->query("limbs");
    limb = limbs[random(sizeof(limbs))];

    // 以下可能在query_xxxx_msg中，加入招式的特殊防御,
    //比如,victim->set_temp("fight/dodge",100)
    // 因此,应该在计算前先进行调用
    dodge_skill = me->query_skill_mapped("dodge");
    if( !dodge_skill ) dodge_skill = "dodge";
        dodge_msg = SKILL_D(dodge_skill)->query_dodge_msg(limb,me);
    dodge_skill = victim->query_skill_mapped("dodge");
    if( !dodge_skill ) dodge_skill = "dodge";
        dodge_msg = SKILL_D(dodge_skill)->query_dodge_msg(limb,victim);
    if (!dodge_msg || dodge_msg=="")
        dodge_msg = SKILL_D("dodge")->query_dodge_msg(limb,victim);
    parry_skill = victim->query_skill_mapped("parry");
    if( !parry_skill ) parry_skill = "parry";
    parry_msg = SKILL_D(parry_skill)->query_parry_msg(victim,weapon);
    if (!parry_msg || parry_msg=="")
        parry_msg = SKILL_D("parry")->query_parry_msg(victim,weapon);

    // --------------------------------------------------------
    // 以下增加攻击招式的特殊攻防
    if (intp(action["dodge"]))
        victim->add_temp("fight/dodge", action["dodge"]/15);
    if (intp(action["parry"]))
        victim->add_temp("fight/dodge", action["parry"]/15);
    if (intp(action["attack"]))
        me->set_temp("fight/attack", action["attack"]/10);
    // ---------------------------------------------------------

    ap = skill_power(me, attack_skill, SKILL_USAGE_ATTACK)/20;
    if (cost=sizeof(me->query_enemy())>1){
        me->delete_temp("fighting");
        if (cost>6) cost=6;
        ap /=cost;
    }
    if( ap < 1) ap = 1;
    if( victim->is_busy() )
        dp = skill_power(victim, "skill", SKILL_USAGE_DEFENSE)/20;
    else
        dp = skill_power(victim, "dodge", SKILL_USAGE_DEFENSE)/20;

    if (cost=sizeof(victim->query_enemy())>1){
       victim->delete_temp("fighting");
        if (cost>6) cost=6;
        dp /=cost;
    }
    if (!victim->visible(me)) dp /= 10;

    if( dp < 1 ) dp = 1;
    cost=skill_power(me, "dodge", SKILL_USAGE_DEFENSE)/10;
    if (cost<1) cost=1;
     if (ap>0 && cost>0 && (ap+cost)<0) cost=2000000000-ap;
    if (!me->visible(victim)) { ap /= 10; cost /= 10; }
    //
    // (3) Fight!
    //     Give us a chance of AP/(AP+DP) to "hit" our opponent. Since both
    //     AP and DP are greater than zero, so we always have chance to hit
    //     or be hit.
    //

    // modified by snow@jhfy to avoid exp increase by player fighting with player

    if( random(ap + cost) < dp && living(victim) && living(me))
    {      // Does the victim dodge this hit?
        result += dodge_msg;
        if( ap+cost > dp && random(your["jing"]*100/your["max_jing"] + victim->query_int()) > 60)
        {
        	 if(vic_exp>150000000)
                   {
                   	 your["combat_exp"] += victim->query_int()/60;
                         victim->improve_skill("dodge", random(victim->query_int())/20);
                    }
                    else if(vic_exp>100000000)
                   {
                   	 your["combat_exp"] += victim->query_int()/40;
                         victim->improve_skill("dodge", random(victim->query_int())/20);
                    }

                else {
                	your["combat_exp"] += victim->query_int()/15;
                        victim->improve_skill("dodge", random(victim->query_int())/10);
                        }
        }
        // This is for NPC only. NPC have chance to get exp when fail to hit.
       if( (ap < dp) && !userp(me) )
        {
                if( random(me->query_int()) > 15 ) my["combat_exp"] += me->query_int()/10;
                me->improve_skill(attack_skill, random(me->query_int()));
        }
                damage = RESULT_DODGE;
    } else {
        //
        //  (4) Check if the victim can parry this attack.
        //
        if (intp(action["parry"]))
            victim->add_temp("fight/parry", action["parry"]);
        if( victim->is_busy() )
            pp = skill_power(victim, "skill", SKILL_USAGE_DEFENSE)/20;
        else
            pp = skill_power(victim, "parry", SKILL_USAGE_DEFENSE)/20;
        if( victim->query_temp("weapon") ){
            if( !weapon ) pp *= 2;
        }else
            if( weapon ) pp /= 2;
        if (sizeof(victim->query_enemy())>1){
            pp-=pp*(sizeof(victim->query_enemy())/4);
        }
        if (!victim->visible(me)) pp /= 10;
        if( pp < 1 ) pp = 1;
        if( random(ap + cost)< pp )
   {
            result += parry_msg;
        if( ap+cost > pp && random(your["jing"]*100/your["max_jing"] + victim->query_int()/2) > 30)
            {
               if(vic_exp>150000000)
                   {
                   	 your["combat_exp"] += victim->query_int()/60;
                         victim->improve_skill("parry", random(victim->query_int())/20);
                    }

               else if(vic_exp>100000000)
                   {
                   	 your["combat_exp"] += victim->query_int()/40;
                         victim->improve_skill("parry", random(victim->query_int())/20);
                    }

                else { your["combat_exp"] += victim->query_int()/15;
                victim->improve_skill("parry", random(victim->query_int())/10);
                }
            }
            damage = RESULT_PARRY;
        } else {
            //
            //  (5) We hit the victim and the victim failed to parry
            //
            if (weapon) damage = weapon->query("weapon_prop/damage");
            damage += me->query_temp("apply/damage");
            damage = (damage + random(damage)) / 2;
            if( action["damage"] )
                damage += action["damage"] * damage / 100;
            damage_bonus = me->query_str();
            // Let force skill take effect.
            if( my["jiali"] && (my["neili"] > my["jiali"]) ) {
                if( stringp(martial_skill = me->query_skill_mapped("force")) ) {
                    foo = SKILL_D(martial_skill)->hit_ob(me, victim, damage_bonus, my["jiali"]);
                    if( stringp(foo) ) result += foo;
                    else if( intp(foo) ) damage_bonus += foo;
                }
            }
            if( action["force"] )
                damage_bonus += action["force"] * damage_bonus / 100;
            if( stringp(martial_skill = me->query_skill_mapped(attack_skill)) ) {
                foo = SKILL_D(martial_skill)->hit_ob(me, victim, damage_bonus);
                if( stringp(foo) ) result += foo;
                else if(intp(foo) ) damage_bonus += foo;
            }
            // Let weapon or monster have their special damage.
            if( weapon ) {
                foo = weapon->hit_ob(me, victim, damage_bonus);
                if( stringp(foo) ) result += foo;
                else if(intp(foo) ) damage_bonus += foo;
            } else {
                foo = me->hit_ob(me, victim, damage_bonus);
                if( stringp(foo) ) result += foo;
                else if(intp(foo) ) damage_bonus += foo;
            }
            if( damage_bonus > 0 )
                damage += (damage_bonus + random(damage_bonus))/2;
            if( damage < 0 ) damage = 0;
            // Let combat exp take effect
            defense_factor = your["combat_exp"];
            while( random(defense_factor) > my["combat_exp"] ) {
                damage -= damage / 3;
                defense_factor /= 2;
            }
            //
            //  (6) Inflict the damage.
            //
            if (!undefinedp(limb_damage[limb]))
            damage = (damage*limb_damage[limb]/100);

            if( stringp(martial_skill = victim->query_skill_mapped("force")) && (int)victim->query_temp("apply/armor_vs_force") ) {
                    foo = SKILL_D(martial_skill)->armor_ob(me, victim, damage,(int)victim->query_temp("apply/armor_vs_force"));
                    if( stringp(foo) ) {result += foo;  damage=0;}
                    else if( intp(foo) ) damage = foo;
                }
// npc的特殊防御
                foo = victim->weapon_ob(victim,me, damage);
                if( stringp(foo) ) result += foo;
                else if(intp(foo) ) damage += foo;

            result += damage_msg(damage, action["damage_type"],victim);
            damage = victim->receive_damage("qi", damage, me );
            if( random(damage) > (int)victim->query_temp("apply/armor")
            && ( (me->is_killing(victim))
                && ((!weapon) && !random(4) || weapon && !random(2) )
                || ( (!weapon) && !random(7) || weapon && !random(4) ) )  )
            {
                // We are sure that damage is greater than victim's armor here.
                victim->receive_wound("qi",
                    damage - (int)victim->query_temp("apply/armor"), me);
                wounded = 1;
            }
             if (me->query_temp("sum_power"))
                victim->receive_wound("qi", damage - (int)victim->query_temp("apply/armor"), me);
            //
            //  (7) Give experience
            //
           // modified by snow@jhfy
           // player vs NPC -> fastest exp increase
           // player vs player, if player's exp<90000000, exp get moderate increase
           // else exp get slowest increase
            if( vic_exp+1000 > me_exp && (random(my["jing"]*100/my["max_jing"] + me->query_int()) > 50) )
            {
            	if(me_exp>150000000)

                  	my["combat_exp"] += me->query_int()/60;
            	else if(me_exp>100000000)

                  	my["combat_exp"] += me->query_int()/40;

                else
                	my["combat_exp"] += me->query_int()/15;
                        me->improve_skill(attack_skill, random(me->query_int()));
                         if( my["potential"] - my["learned_points"] < 10*me->query_int() )
                            my["potential"] += 1;

            }
        }
    }
    result = replace_string( result, "$l", limb );
    if( objectp(weapon) )
		result = replace_string( result, "$w", weapon->name() );
	else if( stringp(action["weapon"]) )
		result = replace_string( result, "$w", action["weapon"] );
	else if( attack_skill == "unarmed" )
              result = replace_string( result, "$w", "无形劲气" );
	else if( attack_skill == "finger" )
                result = replace_string( result, "$w", "指间一股真气" );
        else if( attack_skill == "strike" )
                result = replace_string( result, "$w", "无形掌力" );
    message_vision(result, me, victim );
    if(wizardp(me) && me->query("env/combat")) {
        if( damage > 0 )
            tell_object(me, sprintf( BOLD "my AP：%d，victim DP：%d，victim PP：%d，伤害力：%d\n" NOR,
                (ap+cost)/200, dp/200, pp/200, damage));
        else
            tell_object(me, sprintf( BOLD "my AP：%d，victim DP：%d，victim PP：%d\n" NOR,
                (ap+cost)/200, dp/200, pp/200));
    }
    if( wizardp(victim) && victim->query("env/combat") ) {
        if( damage > 0 )
            tell_object(victim, sprintf( BOLD "victim AP：%d，my DP：%d，my PP：%d，伤害力：%d\n" NOR,
                ap/200, dp/200, pp/200, damage));
        else
            tell_object(victim, sprintf( BOLD "victim AP：%d，my DP：%d，my PP：%d\n" NOR,
                ap/200, dp/200, pp/200));
    }
    if( damage > 0 ) {
        report_status(victim, wounded);
        if( victim->is_busy() ) victim->interrupt_me(me);
        if( (!me->is_killing(victim)) &&
        (!victim->is_killing(me)) &&
        victim->query("qi")*2 <= victim->query("max_qi")) {
            me->remove_enemy(victim);
            victim->remove_enemy(me);
            if (me->query("family/family_name")!="少林派"
            && victim->query_temp("fighting")==me
            && me->query("family/master_id")==(string)victim->query("id")) {
                me->delete("family");
                me->set("title","普通百姓");
                me->delete("class");
                victim->delete_temp("fighting");
                CHANNEL_D->do_channel(victim, "chat",
                sprintf("真不愧是青出于蓝而胜于蓝！%s，你可以出师了，从此另立门户吧！", me->name(1)));
            }else
            message_vision( winner_msg[random(sizeof(winner_msg))], me, victim);
        }
    }
    if( functionp(action["post_action"]) )
        evaluate( action["post_action"], me, victim, weapon, damage);
        else
        WEAPON_D->bash_weapon(me, victim, weapon, damage);
    // See if the victim can make a riposte.
    if( attack_type==TYPE_REGULAR
    &&  damage < 1
    &&  victim->query_temp("guarding") ) {
        victim->set_temp("guarding", 0);
        if( random(my["dex"]) < 5 ) {
            message_vision("$N一击不中，露出了破绽！\n", me);
            do_attack(victim, me, victim->query_temp("weapon"), TYPE_QUICK);
        } else {
            message_vision("$N见$n攻击失误，趁机发动攻击！\n", victim, me);
            do_attack(victim, me, victim->query_temp("weapon"), TYPE_RIPOSTE);
        }
    }
}
//  fight()
//
//  This is called in the attack() defined in F_ATTACK, which handles fighting
//  in the heart_beat() of all livings. Be sure to optimize it carefully.
//
void fight(object me, object victim)
{
    object ob;
    string skill_name;
    if( !living(me) || me->is_busy() ) return;
    if (!me->visible(victim)) return;
    if (environment(me)!=environment(victim) ) return;
//    if (userp(me) && environment(me)->query("freeze"))  return;

    // If victim is busy or unconcious, always take the chance to make an attack.
    if( victim->is_busy() || !living(victim) ) {
        me->set_temp("guarding", 0);
        if( !victim->is_fighting(me) ) victim->fight_ob(me);
        do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
        if ((random(me->query_int())>50 || random(10)<3) && victim->is_fighting(me)){
            me->set_temp("secondly_weapon",1);
            do_attack(me, victim, me->query_temp("secondary_weapon"), TYPE_QUICK);
            me->delete_temp("secondly_weapon");
        }
       else if( me->is_fighting(victim) && victim->is_fighting(me)) {
		if( (!objectp(me->query_temp("weapon"))
		   && sizeof(me->query_skill_prepare()) > 1)
		||  ( objectp(me->query_temp("weapon"))
		   &&(me->query_temp("weapon"))->query("skill_type") == "sword"
		   && me->query_skill("pixie-jian", 1) >= 60
		   && me->query_skill_mapped("sword") == "pixie-jian") )
		{
		   me->set_temp("action_flag",1);
		   do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
		   me->set_temp("action_flag",0);
	     	} }


        if (living(victim)){

            if(  !objectp(ob=me->query_temp("weapon")))
                skill_name="unarmed";
            else skill_name=ob->query("skill_type");
            skill_name=me->query_skill_mapped(skill_name);
            if (stringp(skill_name)){
                me->set_temp("action_flag",1);
                SKILL_D(skill_name)->do_interlink(me, victim);
                me->set_temp("action_flag",0);
            }
        }

   // Else, see if we are brave enough to make an aggressive action.

    } else if( random( (int)victim->query_dex() * 2 ) < (int)me->query_dex() || random(10)<3) {
        me->set_temp("guarding", 0);
        if( !victim->is_fighting(me) ) victim->fight_ob(me);
        do_attack(me, victim, me->query_temp("weapon"), TYPE_REGULAR);
        if( me->is_fighting(victim) && victim->is_fighting(me)) {
		if( (!objectp(me->query_temp("weapon"))
		   && sizeof(me->query_skill_prepare()) > 1)
		||  ( objectp(me->query_temp("weapon"))
		   &&(me->query_temp("weapon"))->query("skill_type") == "sword"
		   && me->query_skill("pixie-jian", 1) >= 60
		   && me->query_skill_mapped("sword") == "pixie-jian") )
		{
		   me->set_temp("action_flag",1);
		   do_attack(me, victim, me->query_temp("weapon"), TYPE_REGULAR);
		   me->set_temp("action_flag",0);
	     	}
}
       else if ((random(me->query_int())>50 || random(10)<2) && victim->is_fighting(me)){
            me->set_temp("secondly_weapon",1);
            do_attack(me, victim, me->query_temp("secondary_weapon"), TYPE_QUICK);
            me->delete_temp("secondly_weapon");
        }

        if(  !objectp(ob=me->query_temp("weapon")))
              skill_name="unarmed";
        else skill_name=ob->query("skill_type");
        skill_name=me->query_skill_mapped(skill_name);
        if (stringp(skill_name)){
            me->set_temp("action_flag",1);
            SKILL_D(skill_name)->do_interlink(me, victim);
            me->set_temp("action_flag",0);
        }
    } else if( !me->query_temp("guarding") ) {
        me->set_temp("guarding", 1);
        message_vision( guard_msg[random(sizeof(guard_msg))], me, victim);
        return;
    } else return;
}

//  auto_fight()
//
//  This function is to start an automatically fight. Currently this is
//  used in "aggressive", "vendetta", "hatred", "berserk" fight.
//
void auto_fight(object me, object obj, string type)
{
    // Don't let NPC autofight NPC.
    if( !userp(me) && !userp(obj) ) return;
    // Because most of the cases that we cannot start a fight cannot be checked
    // before we really call the kill_ob(), so we just make sure we have no
    // aggressive callout wating here.
    if( me->query_temp("looking_for_"+type ) ) return;
    me->set_temp("looking_for_"+type, 1);
    // This call_out gives victim a chance to slip trough the fierce guys.
    call_out( "start_" + type, 0, me, obj);
}
void start_berserk(object me, object obj)
{
    int shen,sb_shen;
    if( !me || !obj ) return;               // Are we still exist( not becoming a corpse )?
    me->set_temp("looking_for_berserk", 0);
    if( me->is_fighting(obj)                // Are we busy fighting?
    ||  !living(me)                         // Are we capable for a fight?
    ||  environment(me)!=environment(obj)   // Are we still in the same room?
    ||  environment(me)->query("no_fight")  // Are we in a peace room?
    )   return;
    message_vision("$N用一种异样的眼神扫视著在场的每一个人。\n", me);
    if( (shen < -50000 || sb_shen>100000) && me->query_per()>random(obj->query_per())*2
    &&  !wizardp(obj) ) {
        message_vision("$N对著$n喝道：" + RANK_D->query_self_rude(me)
            + "看你实在很不顺眼，去死吧。\n", me, obj);
        me->kill_ob(obj);
        obj->fight_ob(me);
    } else {
        message_vision("$N对著$n喝道：喂！" + RANK_D->query_rude(obj)
            + "，" + RANK_D->query_self_rude(me) + "正想找人打架，陪我玩两手吧！\n",me, obj);
        me->fight_ob(obj);
        obj->fight_ob(me);
    }
}
void start_hatred(object me, object obj)
{
    if( !me || !obj ) return;               // Are we still exist( not becoming a corpse )?
    me->set_temp("looking_for_hatred", 0);
      if (!me->query("demogorgon") && !obj->query("demogorgon")  )
    if( me->is_fighting(obj)                // Are we busy fighting?
    ||  !living(me)                         // Are we capable for a fight?
    ||  environment(me)!=environment(obj)   // Are we still in the same room?
    ||  environment(me)->query("no_fight")  // Are we in a peace room?
    )   return;
    // We found our hatred! Charge!
    message_vision( catch_hunt_msg[random(sizeof(catch_hunt_msg))], me, obj);
    me->kill_ob(obj);
    obj->fight_ob(me);
}
void start_vendetta(object me, object obj)
{
    if( !me || !obj ) return;               // Are we still exist( not becoming a corpse )?
    me->set_temp("looking_for_vendetta", 0);
    if( me->is_fighting(obj)                // Are we busy fighting?
    ||  !living(me)                         // Are we capable for a fight?
    ||  environment(me)!=environment(obj)   // Are we still in the same room?
    ||  environment(me)->query("no_fight")  // Are we in a peace room?
    )   return;
    // We found our vendetta opponent! Charge!
    me->kill_ob(obj);
    obj->fight_ob(me);
}
void start_aggressive(object me, object obj)
{
    if( !me || !obj ) return;               // Are we still exist( not becoming a corpse )?
    me->set_temp("looking_for_aggressive", 0);
    if( me->is_fighting(obj)                // Are we busy fighting?
    ||  !living(me)                         // Are we capable for a fight?
    ||  environment(me)!=environment(obj)   // Are we still in the same room?
    ||  environment(me)->query("no_fight")  // Are we in a peace room?
    )   return;
    // We got a nice victim! Kill him/her/it!!!
    me->kill_ob(obj);
    obj->fight_ob(me);
}
// This function is to announce the special events of the combat.
// This should be moved to another daemon in the future.
void announce(object ob, string event)
{
    object *target;
    int i;
    switch(event) {
        case "dead":
			if(random(20) > 10)
			message_vision( NOR"\n$N扑在地上挣扎了几下，腿一伸，口中喷出几口"HIR"鲜血"NOR"，死了！\n\n" NOR, ob);
			else if(random(20)>10)
			message_vision( NOR"\n$N大叫一声倒在地上，挣扎了几下，"HIR"死了"NOR"！\n\n", ob);
			else message_vision( NOR"\n$N口中喷出几口"HIR"鲜血"NOR"，倒在地上,死了！\n\n", ob);
			break;
        case "unconcious":
            if(random(20) > 10)
			message_vision("\n$N脚下一个不稳，跌在地上一动也不动了。\n\n", ob);
		        else message_vision("\n$N突然觉得头晕目眩，跌在地上不省人事了。\n\n", ob);
                        break;
        case "revive":
            if(random(20) > 10)
			message_vision("\n$N慢慢睁开眼睛，清醒了过来。\n\n", ob);
			else message_vision("\n慢慢的,$N又恢复了神智。\n\n", ob);
            if (sizeof(target=ob->query_killer())>0)
                for (i=0;i<sizeof(target);i++){
                  if (objectp(target[i]))
                    if (present(target[i],environment(ob))){
                        auto_fight(ob, target[i], "hatred");
                        return;
                    }
                break;
            }
    }
}
void winner_reward(object killer, object victim)
{
    killer->defeated_enemy(victim);
}
int die_for(object victim)
{
    if (!userp(victim)) return 0;
        victim->add("DIED",1);
        victim->clear_condition();
        // Give the death penalty to the dying user.
        victim->add("shen", -(int)victim->query("shen") / 10);
        victim->add("combat_exp", -(int)victim->query("combat_exp") / 50);
        victim->delete("vendetta");
        victim->delete("bellicosity");
        if( victim->query("thief") )
            victim->set("thief", (int)victim->query("thief") / 2);
        if( (int)victim->query("potential") > (int)victim->query("learned_points"))
            victim->add("potential",
                ((int)victim->query("learned_points") - (int)victim->query("potential"))/4 );
        victim->skill_death_penalty();
         if (stringp(victim->query_temp("die_for"))){
            CHANNEL_D->do_channel(this_object(), "rumor",
            sprintf("听说%s%s死了。", victim->name(1),victim->query_temp("die_for")));
            victim->delete_temp("die_for");
        }else
        {
         CHANNEL_D->do_channel(this_object(),"sys",victim->name(1)+"死于"+environment(victim)->query("short")+"("+file_name(environment(victim))+")\n");
          message("channel:rumor",HIW"\n〖江湖传闻〗: 听说"+victim->name(1)+"死了，而且死的很离奇！\n\n",users());
          }
}
void killer_reward(object killer, object victim)
{
    int bls,int_skill;
    string vmark,killer_master_id,msg;
    mapping actions;
    object link_ob,money;
    int exp;

      if (!killer)     return;
    killer->killed_enemy(victim);
    killer_master_id=killer->query("family/master_id");
    if (userp(killer) && (int)victim->query_condition("killer"))
                    {
                      killer->add("combat_exp",(int)victim->query("combat_exp")/10);
                      killer->add("score",(int)victim->query("score")/10);
                            if(victim->query("combat_exp") > 500000){
                                       money = new("/clone/money/gold");
                           money->set_amount((random(5)+1) * 100);
                           money->move(killer);}
                           CHANNEL_D->do_channel(this_object(), "rumor",
sprintf("官府通缉犯%s被%s就地正法，%s获得了应有的奖励!",victim->name(),killer->name(),killer->name()));
                      killer->clear_condition("killer");
                      killer->delete_temp("kill_killer");
                      victim->clear_condition("killer");
            }

        else if( userp(victim) ) {
    if (wiz_level(killer)>1) return;
        if ( victim->is_att_killing(killer) ){
            victim->set_temp("die_for","活腻而被"+killer->query("name")+"杀");
            die_for(victim);
            return;
        }
        if (userp(killer))
        {
        killer->add("PKS", 1);
                victim->add("PKD",1);
                }
        victim->add("DIED",1);
        victim->clear_condition();

        // Give the death penalty to the dying user.
        victim->add("shen", -(int)victim->query("shen") / 10);
        victim->delete("vendetta");
        victim->delete("bellicosity");
        if( victim->query("thief") )
            victim->set("thief", (int)victim->query("thief") / 2);
        if (!userp(killer) && killer->query("id")=="demogorgon"){
                          int_skill=victim->query_skill("literate",1);
                        if (int_skill>10)
                            victim->set_skill("literate",int_skill-10);
                                else{  if( (int)victim->query("potential") > (int)victim->query("learned_points"))
                                victim->add("potential",((int)victim->query("learned_points") - (int)victim->query("potential"))/2 );
        victim->add("combat_exp", -(int)victim->query("combat_exp") / 40);
        }
        }else{    victim->skill_death_penalty();
        victim->add("combat_exp", -(int)victim->query("combat_exp") / 40);
                    if( (int)victim->query("potential") > (int)victim->query("learned_points"))
                                victim->add("potential",((int)victim->query("learned_points") - (int)victim->query("potential"))/2 );
       }


        bls = 10;
         if(objectp(killer))
                {
                     //   if(environment(killer)&&environment(killer)->query("short"))
                     //   msg = "在"+environment(killer)->query("short");
                    //    else msg = "在一个不为人知的地方";
                        msg="被"+killer->name();
                        actions = killer->query("actions");
                        switch(actions["damage_type"]) {
                        case "擦伤":
                        case "割伤":
                                msg+=HIM"用武器砍死了。";
                                break;
                        case "刺伤":
                                msg+=HIM"用利器刺死了。";
                                break;
                        case "瘀伤":
                                msg+=HIM"用掌力击毙了。";
                                break;
                        case "内伤":
                                msg+=HIM"用掌力震死了。";
                                break;
                        default:
                                msg+=HIM"杀害了。";
                        }

                }
		if (killer_master_id==(string)victim->query("id"))
		CHANNEL_D->do_channel(this_object(), "rumor",sprintf("%s将自己的师傅%s杀死了,真是惨无人道啊。", killer->name(0),victim->name(1)));
		else
		CHANNEL_D->do_channel(this_object(), "rumor",
			sprintf("听说%s"+msg, victim->name(1)));

            if (userp(killer))
     {
        write_file("/log/static/KILL_PLAYER",sprintf("%s(%s) killed by %s(%s) on %s\n",
        victim->name(1), victim->query("id"),
        killer->name(1),killer->query("id"),ctime(time()) ));
    if ((killer->query_temp("pker_starttime")+900*killer->query_temp("pker_time")) < killer->query("mud_age"))
       {
		killer->set_temp("pker_starttime",killer->query("mud_age"));
		killer->delete_temp("pker_time");
	}
        killer->add_temp("pker_time",1);
        if(!victim->query_condition("killer"))
         CHANNEL_D->do_channel(this_object(), "rumor",
                                sprintf("官府开始捉拿%s,并奖励将杀人犯就地正法之江湖好汉。", killer->name(0)));
        victim->add("combat_exp", -(int)victim->query("combat_exp") / 30);
      }
    } else {
        killer->add("MKS", 1);
        bls = 1;
    }
    if (killer_master_id==(string)victim->query("id") && !userp(victim))
		CHANNEL_D->do_channel(this_object(), "rumor",sprintf("%s将自己的师傅%s杀死了,真是惨无人道啊。", killer->name(0),victim->name(1)));
    if (!killer->is_ghost())
    killer->add("shen", -(int)victim->query("shen") / 10);
    if (userp(victim) && userp(killer)&&!victim->query_condition("killer"))
        killer->apply_condition("killer", 1000);

        exp=killer->query("combat_exp");
    if (exp<200000 && exp<victim->query("combat_exp")){
       exp+=random(exp/10);
        killer->set("combat_exp", exp);
    }
    if( stringp(vmark = victim->query("vendetta_mark")) )
        killer->add("vendetta/" + vmark, 1);
    if( killer->query("family/master_id")==(string)victim->query("id")) {
        if ( victim->query_temp("fighting")==killer){
                killer->delete("family");
                killer->set("title","普通百姓");
                killer->delete("class");
                victim->delete_temp("fighting");
                CHANNEL_D->do_channel(victim, "chat",
                sprintf("真不愧是青出于蓝而胜于蓝！%s，你可以出师了，从此另立门户吧！", killer->name(1)));
        }else   if (killer->query("class") == "bonze" && victim->query("class") == "bonze"){
                 killer->set("kill_bonze",time());
                killer->delete("family");
          if (link_ob=killer->query_temp("link_ob"))
             killer->set("name",link_ob->query("name"));
                killer->set("title","普通百姓");
                killer->delete("class");
                CHANNEL_D->do_channel(victim, "chat",
                sprintf("%s，你谋害自己的师傅，为我佛门所不容，你走吧！", killer->name(1)));
        }
    }
}
