//LUCAS 2000-6-18
#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
set_name( HIY "移"HIR"夕"HIB"剑" NOR , ({ "yixi sword",}));       	
        set_weight(8000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
set("long", "这就是上古三大神兵之一"HIR"移夕剑，"HIB"传说干将一生矢志完成师傅遗愿，用爱的力量铸造出一柄绝世神剑，却因爱情的无常演变成一柄充满无穷恨意的绝世魔剑。\n");	
                set("value", 20000);
                set("material", "steel");
                set("weapon_prop/personality", 8);
                set("weapon_prop/unarmed", 100);
                set("wield_msg","$N暗运内力，一道血光从剑鞘冲出,"HIR"漫天乌云笼罩,怨气冲天,"HIW"一柄血红的$n已然在手" NOR);
set("unwield_msg", "$N将$n缓缓的插回剑鞘 ，"GRN" 如获释重，长长的叹了口气...。" NOR);
        }
init_sword(750,2);     	
        setup();
}

int query_autoload() { return 1; }      	
