inherit ITEM;
void create()
{
set_name( "漫天花雨图解", ({ "book", "shu" }));
    set_weight(200);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "本");
 set("long", "这是一本漫天花雨图解，上面画着一些纷繁复杂的暗器手法及修练法门。\n");
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
