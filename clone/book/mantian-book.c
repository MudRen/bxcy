inherit ITEM;
void create()
{
set_name( "���컨��ͼ��", ({ "book", "shu" }));
    set_weight(200);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "��");
 set("long", "����һ�����컨��ͼ�⣬���滭��һЩ�׷����ӵİ����ַ����������š�\n");
        set("value", 500);
        set("material", "paper");
        set("skill", ([
   "name": "mantianhuayu",    
            "exp_required": 100000, // minimum combat experience required
            "jing_cost": 30,    // jing cost every time study this
            "difficulty":   30, // the base int to learn this skill
 "max_skill":    3500,    // the maximum level you can learn
        ]) );
    }
}
int query_autoload() { return 1; }
