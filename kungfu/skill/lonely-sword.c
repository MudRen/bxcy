// lonely-sword.c 独孤九剑

#include <ansi.h>
#include <combat.h>
#include "/kungfu/skill/eff_msg.h";

inherit SKILL;  
string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});
string *parry_msg = ({
        ""+(order[random(13)])+"却见$n踏前一步，剑式斜指你的右臂，想要使$P闪身而退。"NOR"\n",
        "$n以攻为守，以进为退，凝神运气向$P猛攻快打地挥出方位大异的泰山"+(order[random(13)])+"「快活三」"NOR"三剑。"NOR"\n",
        ""+(order[random(13)])+"$n剑法突变，剑势伸缩不定，奔腾矫夭，逆使嵩山剑法的"+(order[random(13)])+"「天外玉龙」"NOR"企图迫使$P变招。"NOR"\n",
        ""+(order[random(13)])+"$n突然一剑点向$P的$l，虽一剑却暗藏无数后着，$P手足无措，攻势不由自主停了下来！"NOR"\n"
        "$n不闪不避，举剑闪电般使出"+(order[random(13)])+"「叠翠浮青」"NOR"反削$P的$l，想挡过你此招。"NOR"\n",
        "$n突然使出青城派松风剑法的"+(order[random(13)])+"「鸿飞冥冥」"NOR"，可是方位却有所偏差，长剑对着$P一绞，企\n图突破$P的攻势！"NOR"\n"
        "$n挺剑一招象是"+(order[random(13)])+"「白云出岫」"NOR"回刺$P的$l，企图将$P的攻势化解。"NOR"\n",
        "只见$n不退反进，身如飘风，诡异地一式"+(order[random(13)])+"「天柱云气」"NOR"，动向无定不可捉摸地挡住了$P的\n进攻。"NOR"\n",
        "$n不退反进，使出恒山剑招"+(order[random(13)])+"「绵里藏针」"NOR"，森森剑气充溢四周！架开了$P的这招"NOR"\n",
});

mapping *action = ({
([      "action" : "但见$N挺身而上，$w一旋，一招仿佛泰山剑法的"+(order[random(13)])+"「来鹤清泉」"NOR"直刺$n
的$l！",
        "force" : 110,
        "dodge" : 65,
        "damage": 150,
        "lvl" : 0,
        "damage_type" : "刺伤"
]),
([      "action" : "$N奇诡地向$n挥出"+(order[random(13)])+"「泉鸣芙蓉」"NOR"、"+(order[random(13)])+"「鹤翔紫盖」"NOR"、"+(order[random(13)])+"「石廪书声」"NOR"、"+(order[random(13)])+"「
天柱云气」"NOR"及"+(order[random(13)])+"「雁回祝融」"NOR"衡山五神剑！",
        "force" : 110,
        "dodge" : 60,
        "damage": 150,
        "lvl" : 7,
        "damage_type" : "刺伤"
]),
([
        "action" : "$N剑随身转，续而刺出十九剑，竟然是华山"+(order[random(13)])+"「玉女十九剑」"NOR"，但奇的
是这十九剑便如一招，手法之快，直是匪夷所思！",
        "force" : 110,
        "dodge" : 65,
        "damage": 150,
        "lvl" : 14,
        "damage_type" : "刺伤"
]),
([      "action" : ""+(order[random(13)])+"$N剑势忽缓而不疏，剑意有余而不尽，化恒山剑法为一剑，向$n慢慢
推去！",
        "force" : 120,
        "dodge" : 65,
        "damage": 150,
        "lvl" : 21,
        "damage_type" : "刺伤"
]),
([      "action" : ""+(order[random(13)])+"$N剑意突焕气象森严，便似千军万马奔驰而来，长枪大戟，黄沙千里
，尽括嵩山剑势击向$n的$l！",
        "force" : 120,
        "dodge" : 80,
        "damage": 150,
        "lvl" : 28,
        "damage_type" : "刺伤"
]),
([      "action" : "却见$N身随剑走，左边一拐，右边一弯，剑招也是越转越加狠辣，竟
化"+(order[random(13)])+"「泰山十八盘」"NOR"为一剑攻向$n！",
        "force" : 130,
        "dodge" : 100,
        "damage": 155,
        "lvl" : 35,
        "damage_type" : "刺伤"
]),
([      "action" : "$N剑招突变，使出衡山的"+(order[random(13)])+"「一剑落九雁」"NOR"，削向$n的$l，怎知剑到中
途，突然转向，大出$n意料之外！",
        "force" : 140,
        "dodge" : 100,
        "damage": 160,
        "lvl" : 42,
        "damage_type" : "刺伤"
]),
([      "action" : "$N吐气开声，一招似是"+(order[random(13)])+"「独劈华山」"NOR"，手中$w向下斩落，直劈向$n的
$l！",
        "force" : 150,
        "dodge" : 100,
        "damage": 180,
        "lvl" : 49,
        "damage_type" : "刺伤"
]),
([      "action" : "$N手中$w越转越快，使的居然是衡山的"+(order[random(13)])+"「百变千幻云雾十三式」"NOR"，剑
式有如云卷雾涌，旁观者不由得目为之眩！",
        "force" : 160,
        "dodge" : 100,
        "damage": 190,
        "lvl" : 56,
        "damage_type" : "刺伤"
]),
([      "action" : "$N含笑抱剑，气势庄严，$w轻挥，尽融"+(order[random(13)])+"「达摩剑」"NOR"为一式，闲舒地刺
向$n！",
        "force" : 170,
        "dodge" : 100,
        "damage": 200,
        "lvl" : 63,
        "damage_type" : "刺伤"
]),
([      "action" : "$N举起$w运使"+(order[random(13)])+"「太极剑」"NOR"剑意，划出大大小小无数个圆圈，无穷无尽
源源不绝地缠向$n！",
        "force" : 280,
        "dodge" : 100,
        "damage": 220,
        "lvl" : 70,
        "damage_type" : "刺伤"
]),
([      "action" : "$N神声凝重，$w上劈下切左右横扫，挟雷霆万钧之势逼往$n，"+(order[random(13)])+"「伏摩
剑」"NOR"的剑意表露无遗！",
        "force" : 290,
        "dodge" : 105,
        "damage": 230,
        "lvl" : 77,
        "damage_type" : "刺伤"
]),
([      "action" : "却见$N突然虚步提腰，使出酷似武当"+(order[random(13)])+"「蜻蜓点水」"NOR"的一招！",
        "force" : 200,
        "dodge" : 105,
        "damage": 260,
        "lvl" : 84,
        "damage_type" : "刺伤"
]),
([      "action" : "$N运剑如风，剑光霍霍中反攻$n的$l，尝试逼$n自守，剑招似是"+(order[random(13)])+"「伏
魔剑」"NOR"的"+(order[random(13)])+"「龙吞式」"NOR"。",
        "force" : 220,
        "dodge" : 100,
        "damage": 295,
        "lvl" : 91,
        "damage_type" : "刺伤"
]),
([      "action" : "$N突然运剑如狂，一手关外的"+(order[random(13)])+"「乱披风剑法」"NOR"，猛然向$n周身乱刺乱
削！",
        "force" : 240,
        "dodge" : 100,
        "damage": 320,
        "lvl" : 98,
        "damage_type" : "刺伤"
]),
([      "action" : ""+(order[random(13)])+"$N满场游走，东刺一剑，西刺一剑，令$n莫明其妙，分不出$N剑法的
虚实！"NOR"",
        "force" : 260,
        "dodge" : 100,
        "damage": 350,
        "lvl" : 105,
        "damage_type" : "刺伤"
]),
([      "action" : ""+(order[random(13)])+"$N抱剑旋身，转到$n身后，杂乱无章地向$n刺出一剑，不知使的是什
么剑法！"NOR"",
        "force" : 280,
        "dodge" : 100,
        "damage": 380,
        "lvl" : 112,
        "damage_type" : "刺伤"
]),
([      "action" : ""+(order[random(13)])+"$N突然一剑点向$n的$l，虽一剑却暗藏无数后着，$n手足无措，不知
如何是好！"NOR"",
        "force" : 200,
        "dodge" : 100,
        "damage": 485,
        "lvl" : 119,
        "damage_type" : "刺伤"
]),
([      "action" : ""+(order[random(13)])+"$N剑挟刀势，大开大阖地乱砍一通，但招招皆击在$n攻势的破绽，迫
得$n不得不守！"NOR"",
        "force" : 320,
        "dodge" : 100,
        "damage": 450,
        "lvl" : 126,
        "damage_type" : "刺伤"
]),
([      "action" : ""+(order[random(13)])+"$N反手横剑刺向$n的$l，这似有招似无招的一剑，威力竟然奇大，$n
难以看清剑招来势！"NOR"",
        "force" : 340,
        "dodge" : 105,
        "damage": 480,
        "lvl" : 133,
        "damage_type" : "刺伤"
]),
([      "action" : ""+(order[random(13)])+"$N举剑狂挥，迅速无比地点向$n的$l，却令人看不出其所用是什么招
式。"NOR"",
        "force" : 460,
        "dodge" : 100,
        "damage": 450,
        "lvl" : 140,
        "damage_type" : "刺伤"
]),
([      "action" : ""+(order[random(13)])+"$N随手一剑指向$n，落点正是$n的破绽所在，端的是神妙无伦，不可
思议！"NOR"",
        "force" : 480,
        "dodge" : 100,
        "damage": 450,
        "lvl" : 147,
        "damage_type" : "刺伤"
]),
([      "action" : ""+(order[random(13)])+"$N脸上突现笑容，似乎已看破$n的武功招式，胸有成竹地一剑刺向$n
的$l！"NOR"",
        "force" : 500,
        "dodge" : 100,
        "damage": 520,
        "lvl" : 154,
        "damage_type" : "刺伤"
]),
([
    "action" : ""+(order[random(13)])+"$N将$w随手一摆，但见$n自己向$w撞将上来，神剑之威，实人所难测！"NOR"",
        "force" : 600,
        "dodge" : 100,
        "damage": 665,
        "lvl" : 180,
    "damage_type" : "刺伤"
])
});

int valid_enable(string usage)
{
        return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

string query_parry_msg(string limb)
{
        return parry_msg[random(sizeof(parry_msg))];
}

int valid_learn(object me)
{
        object ob;

        mapping myfam;
        myfam = (mapping)me->query("family");
if(!myfam || myfam["family_name"] != "圣剑魔宫"|| myfam["master_id"] != "afei")	
return notify_fail("独孤九剑只有向阿飞学习。\n");	
        if( (int)me->query("max_neili") < 600 )
                return notify_fail("你的内力不够，没有办法练独孤九剑。\n");
        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
                return notify_fail("你必须先找一把剑才能练剑法。\n");
        if ((int)me->query_skill("lonely-sword",1) > 120)
                return notify_fail("这套剑法我就教到这儿，以后就要靠你自己练了。\n");

        return 1;
}

int practice_skill(object me)
{
        return notify_fail("独孤九剑只能通过"+(order[random(13)])+"「总诀式」"NOR"来演练。\n");
}

int valid_effect(object me, object weapon, string name, int skill)
{
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor, string limb)
{       
int jiali;
	object weapon;
	weapon = me->query_temp("weapon");
        if (random(me->query_skill("lonely-sword",1)) < 100 ||		             me->query_skill("force",1) < 100 )
        return 0;
        if (random(me->query_skill("lonely-sword",1)) > 200 &&
        random(me->query_skill("sword",1))>180 &&
     	me->query_skill("force",1) > 250 
     	&& !victim->is_busy())
{
        me->add("neili", -50);
        victim->map_skill("dodge");
  if( !victim->is_busy() )
{
        victim->start_busy(random(3)+1);
}
        message_vision(HIC "$n突然举剑一刺，剑招随便无章，却莫明奇妙地突破了$N的攻势，大出$N意料！" NOR, victim,me  );
        return HIR"$n大吃一惊，竟然忘了闪避！\n"NOR;
        
}
        if (random(me->query_skill("lonely-sword",1)) > 140 &&	
	 random(me->query_skill("sword",1))>140 &&
            me->query_skill("force",1) > 200 
            && !victim->is_busy())	
{
        
        me->add("neili", -50);
        victim->map_skill("parry");
  if( !victim->is_busy() )
{
        victim->start_busy(random(2)+1);
}
        message_vision(HIC "$n举剑反攻，后发先至地刺向$N，不仅把$N招术封死，更进一步发出攻击！" NOR, victim,me);
        return HIY"$n难以看清剑招来势,竟然忘了招架！\n"NOR;
} 
        if (random(me->query_skill("lonely-sword",1)) > 130 &&	
        random(me->query_skill("sword",1))>130 &&
	 me->query_skill("force",1) > 150
	 && !victim->is_busy())
{
        me->add("neili", -50);
  if( !victim->is_busy() )
{
        victim->start_busy(random(3)+1);
}
        message_vision(HIC "$n提剑回刺，落点正是$N的破绽，$N不得不撤招严守，身形一晃间已退出丈许！" NOR, victim,me );
        return HIG"$n手忙脚乱，慌乱不堪！\n"NOR;
} 
        if (random(me->query_skill("lonely-sword",1)) > 100 &&
        random(me->query_skill("sword",1))>100 &&
      	me->query_skill("force",1) > 120
      	&& !victim->is_busy() )	
{
if (victim->query("neili")>600)
{
        victim->add("neili", -500);
}
        message_vision(HIC "$n一转剑势，剑招源源而出，对$N发动攻势！\n" NOR, victim,me );
	return HIM"$n使出浑身解数才脱出剑圈！\n"NOR;
}
        if (random(me->query_skill("lonely-sword",1)) > 80 &&	
        random(me->query_skill("sword",1))>80 &&  
	  me->query_skill("force",1) > 100 
	  && !victim->is_busy())	
{

  if( !victim->is_busy() )
{        victim->start_busy(random(2)+1);
}
        message_vision(HIC "$n眼见避无可避，只好提剑乱刺一通，居然出乎意料地将$N的攻击接去大半。" NOR, victim,me );
	return HIW"$n顿时手足无措，不知如何是好！\n"NOR;
  } 
	
	jiali = me->query("jiali");

if (!jiali) jiali=10;
	if( damage_bonus > 100 && random(me->query_skill("lonely-sword",1))>140 
	&& me->query("fengset")
	) {
	victim->receive_wound("qi", (random(jiali)+100));
	return HIM"$N剑气纵横! 一道剑气划过了$n的$l。结果鲜血狂奔!\n"NOR;
}
}
string perform_action_file(string action)
{
        return __DIR__"lonely-sword/" + action;
}


int ob_hit(object ob, object me, int damage)
{
	object weapon = me->query_temp("weapon");
        string msg,dodge_skill,*limbs;
        int i, j, level, p, q;
        
if ((int)me->query("qi")>1 && (int)me->query("eff_qi")>1)
{
if ((int)me->query("qi") < (int)me->query("eff_qi"))
        i = (int)me->query("eff_qi") / (int)me->query("qi") + 1;
else         i = (int)me->query("max_qi") / (int)me->query("eff_qi") + 1;
        if ( i > 5 ) i = 5;
}
else i=1;
        limbs = ob->query("limbs");
        level = me->query_skill("lonely-sword", 1);

        if( me->is_busy()) return 1;
        if( damage < 100 ) return 1;
        if (  random(level) > 100 /i 
         && me->query_skill_mapped("sword") =="lonely-sword"
         && me->query_skill_mapped("parry") =="lonely-sword"
         && me->query("fengset")
         && weapon
         && weapon->query("skill_type") == "sword"
         && me->query_skill("sword") > 300
         && random(me->query_skill("sword",1)) > 150
         && !me->is_busy()
         && me->query("neili") > 200 
         && me->query("max_neili") > 4000
         && random(me->query_int()) >= 20 ){
            me->add("neili", -100);
            msg = HIW"$N身子摇摇欲坠，行动不便，知道这一招无可躲避，当即挺剑刺出，后发先至，噗的一声刺向$n的咽喉。\n"NOR;
            if ( random(level) > ob->query_skill("dodge", 1) / i){
             q = damage * i ;
             if ( q > 3500 ) q = 3500 + ( q - 3500 )/ 100;
             ob->receive_damage("qi", q);
             ob->receive_wound("qi", q/3);
             if (!ob->is_busy())
             ob->start_busy(2+random(2));
             if ( random(me->query("combat_exp")) > ob->query("combat_exp") / i)
             p = ob->query("qi")*100/ob->query("max_qi");
             msg += damage_msg(damage, "刺伤") + "( $n"+eff_status_msg(j)+" )\n";
             msg = replace_string(msg, "$l", limbs[random(sizeof(limbs))]);
             msg = replace_string(msg, "$w", "剑刃");
             j = -(damage/2+random(damage/2));
            }
            else {
              dodge_skill = ob->query_skill_mapped("dodge");
              if( !dodge_skill ) dodge_skill = "dodge";
              msg += SKILL_D(dodge_skill)->query_dodge_msg(ob, 1);
              j = -damage/4; 
            }
            message_vision(msg, me, ob);
            return j;
        }
}
