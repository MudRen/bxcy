//fei tian.c
#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
set_name( HIR "����" NOR , ({ "feitian sword",}));	
        set_weight(8000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "XXXXXXXXXX\n");
                set("value", 20000);
                set("material", "steel");
                set("weapon_prop/strength", 30);
                set("weapon_prop/unarmed", 100);
                set("wield_msg","xxxxxxxxxxxxx" NOR);
set("unwield_msg", "dddddddddddddddddd" NOR);
        }
init_sword(1500,1);	
        setup();
}
mixed hit_ob(object me,object victim,int damage_bonus)
{
    if(!(me->query_skill("tianji-jian",1))) {
                        victim->receive_wound("qi", (damage_bonus ));
                        victim->receive_wound("jing", (damage_bonus ));
                        victim->add("neili", -(int)me->query("jiali"));
                        return HIR "SSSSSSSSSSSSSSSS\n" NOR;
        }

}

int query_autoload() { return 1; }      	
