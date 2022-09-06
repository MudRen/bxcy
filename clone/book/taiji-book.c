inherit ITEM;
void create()
{
   set_name( "太极剑剑谱", ({ "jian pu", "pu" }));
    set_weight(200);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "本");
  set("long", "这是一本太极剑剑谱，上面画着一些纷繁复杂的招式及修练法门。\n");
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
