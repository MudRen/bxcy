#include <ansi.h>
inherit NPC;

void create()
{
    set_name("�ɹŰٷ�", ({ "menggujiang", "jiang" }));
    set("gender", "����" );//�Ա��������Ӧ
        set("long",
"һ����ߴ����������˰̼Ӻ�����ɹű���\n");
        set("attitude", "aggressive");
        set("vendetta/authority",1);
	set("nickname",HIW"�ɹ�С��"NOR);
  set("force_factor",2+random(390));
  set("max_qi",400+random(590));
  set("max_jing",400+random(590));
  set("max_sen",400+random(590));
  set("max_neili",400+random(590));
  set("max_mana",400+random(590));
  set("eff_neili",400+random(390));
  set("neili",400+random(590));
        set("per", 1);
        set("age", 22);
        set("shen", -5000);
        set("intellgent",1);
	set("pursuer",1);
        set("combat_exp", 200000+random(300000));
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "blade.leitingpili" :),
		            (: random_move :),
        }) );
        set("chat_chance", 5);
        set("chat_msg", ({
                "�ɹŰٷ򳤺ȵ���ɱ���ģ���\n",
                "�ɹŰٷ�Ц�������һ��Ҫ��������!\n",
                (: random_move :),
        }) );

        set_skill("unarmed", 100+random(150));
        set_skill("blade", 100+random(150));
        set_skill("parry", 100+random(150));
        set_skill("dodge", 100+random(150));
        set_skill("kuang-blade", 100+random(150));
        
        map_skill("blade", "kuang-blade");
        map_skill("parry", "kuang-blade");
        set_temp("apply/attack", 30);
        set_temp("apply/defense", 50);
        set_temp("apply/armor", 50);
        set_temp("apply/damage", 20);

if (random(20)>15)
{
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 200);
        set_temp("apply/damage", 200);
}

        setup();

        carry_object(__DIR__"obj/japancloth")->wear();
        carry_object(__DIR__"obj/japanblade")->wield();
	add_money("silver", random(50));
}
void init( )
{
        call_out("hunting",180);
}

void hunting()
{
object ob=this_object();
write(HIW"ֻ����������������!�ɹŰٷ�����������!\n"NOR);
destruct(ob);
}

void die()
{
        object ob, me, corpse;
        
        ob = this_object();
        me = query_temp("last_damage_from");
        
if (me)
{        message_vision(WHT"$N���һ��,������!!���ض�����\n"NOR,ob,me);
        if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
        corpse->move(environment(this_object()));
        if((int)me->query("combat_exp") < 600000)   {
        message("vision", me->name() + HIG"���ڳɹ��ı���������,������200�����100Ǳ�ܡ�\n"NOR, me);
        me->add("combat_exp",200);
        me->add("potential",100);
        destruct(ob);
        }
        message("vision", me->name() + HIG"�ɹ��ı�����������\n"NOR, me);
        me->add("score",2);
        me->add("shen",10);
 }
        destruct(ob);
        return;
}
