// lbook1.c
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(YEL"���־�"NOR, ({ "literateb1", "shu1", "book1" }));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "��");
                set("long","�����˱ض������־���\n");
                set("value", 30000); //ԭ����5 gold,mudos
                set("material", "paper");
                set("skill",
                ([
                        "name": "literate",      // name of the skill
                        "exp_required": 10,      // minimum combat experience required
                        "jing_cost":    10,      // jing cost every time study this
                        "difficulty":   15,      // the base int to learn this skill
                        "max_skill":    49,      // the maximum level you can learn
                        "min_skill":    20,      // minimun level required
                ]) );
        }
}
int query_autoload() { return 1; }