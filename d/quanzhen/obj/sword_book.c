inherit ITEM;

void create()
{
        set_name( "ȫ�潣��", ({ "book","jian pu" }));
        set_weight(100);
        set("unique", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ��ȫ�潣�ף����滭��һЩ�׷����ӵ���ʽ���������š�\n");
                set("material", "paper");
                set("skill", ([
                         "name": "quanzhen-jianfa",        
                        "exp_required": 100000, // minimum combat experience required
                        "jing_cost": 30,        // jing cost every time study this
                        "difficulty": 30,       // the base int to learn this skill
                        "max_skill":    150,    // the maximum level you can learn
                ]) );
        }
}

