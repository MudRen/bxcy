// lbook3.c
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIR"�����徭"NOR, ({ "literateb5", "shu5", "book5" }));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "��");
                set("long","��̶��ı��顣\n");
                set("value", 500000);//ԭ��100 gold,mudos
                set("material", "paper");
                set("skill",
                ([
                        "name": "literate",      // name of the skill
                        "exp_required": 1000,      // minimum combat experience required
                        "jing_cost":    1,      // jing cost every time study this
                        "difficulty":   40,      // the base int to learn this skill
                        "max_skill":    180,      // the maximum level you can learn
                        "min_skill":    100,      // minimun level required
                ]) );
        }
}
int query_autoload()
{
   return 1;
}
int query_autoload() { return 1; }