// lbook2.c
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(YEL"�ټ���"NOR, ({ "literateb2", "shu2", "book2" }));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);                                   
        else
        { 
               set("unit", "��");
                set("long","�����˱ض��İټ��ա�\n");
                set("value", 100000); //ԭ����20 gold,mudos
                set("material", "paper");
                set("skill",
                ([
                        "name": "literate",      // name of the skill
                        "exp_required": 100,      // minimum combat experience required
                        "jing_cost":    10,      // jing cost every time study this
                        "difficulty":   15,      // the base int to learn this skill
                        "max_skill":    79,      // the maximum level you can learn
                        "min_skill":    50,      // minimun level required
                ]) );
        }
}
int query_autoload() { return 1; }