inherit ITEM;
void create()
{
 set_name( "暗器详解", ({ "book", "shu" }));
    set_weight(200);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "本");
 set("long", "这是一本暗器详解，上面详细的记录了暗器的修练法门。\n");
        set("value", 500);
        set("material", "paper");
        set("skill", ([
 "name": "throwing",    
            "exp_required": 100000, // minimum combat experience required
            "jing_cost": 30,    // jing cost every time study this
            "difficulty":   30, // the base int to learn this skill
 "max_skill":    3500,    // the maximum level you can learn
        ]) );
    }
}
int query_autoload() { return 1; }
