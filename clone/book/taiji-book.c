inherit ITEM;
void create()
{
   set_name( "̫��������", ({ "jian pu", "pu" }));
    set_weight(200);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "��");
  set("long", "����һ��̫�������ף����滭��һЩ�׷����ӵ���ʽ���������š�\n");
        set("value", 500);
        set("material", "paper");
        set("skill", ([
     "name": "taiji-jian",    
            "exp_required": 100000, // minimum combat experience required
            "jing_cost": 30,    // jing cost every time study this
            "difficulty":   30, // the base int to learn this skill
 "max_skill":    3500,    // the maximum level you can learn
        ]) );
    }
}
int query_autoload() { return 1; }
