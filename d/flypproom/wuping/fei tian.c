//fei tian.c
#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
set_name( HIR "飞天" NOR , ({ "feitian sword","sword","jian"}));      	
        set_weight(8000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
set("long", HIC"传说中爱神的随身配剑,据说是用仙界炼器之法锻铸九九八十一年而成.据说此剑有飞天遁地之神通,故而名为"HIR"飞天!\n");
                set("no_give",1);
                set("no_get",1);
                set("no_put",1);
                set("no_drop",1);
                set("value", 20000);
                set("material", "steel");
                set("weapon_prop/strength", 30);
                set("weapon_prop/unarmed", 100);
set("wield_msg",HIC"$N冷哼一声,双手平举向天.........\n"
HIR"刹那间风云变色.仿佛与$N杀气呼应一般,天也为之震怒.随着一声惊天的\n"
HIY"        ∠∈...霹.....○...★...●.....雳...々№...\n"
HIC"一道巨大的闪电落在$N的手中.随着电光的慢慢敛去,一把电光吞吐的双手巨剑也慢慢的展露在$N的手中.\n" NOR);	
set("unwield_msg", HIM"随着$N"HIR"杀气"HIC"的减退,"HIY"神剑"HIR"飞天"HIW"的光芒也越来越平和.终于$N的"HIR"杀气"HIC"完全消失,"HIR"飞天"HIY"也化成一道神光消失于九天之外！" NOR);
        }
init_sword(1500,1);	
        setup();
}
mixed hit_ob(object me,object victim,int damage_bonus)
{
if(me->query_skill_mapped("sword") == "taiji-jian") {
                        victim->receive_wound("qi", (damage_bonus ));
                        victim->receive_wound("jing", (damage_bonus ));
                        victim->add("neili", -(int)me->query("jiali"));
return HIM "随着$N"HIR"杀气"HIC"的增加,流动于"HIR"飞天"HIC"剑身的"HIY"电光"HIC"忽然绽放出"HIR"妖异"HIY"的光芒!\n" NOR;
        }

}

int query_autoload() { return 1; }      	
