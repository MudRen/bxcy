// damo-ling.c 达摩令
inherit ITEM;
void create()
{
        set_name("达摩令", ({"damo ling", "letter", "ling"}));
        set_weight(500);
    if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "面");
                set("long","这是一面金光闪闪的令牌，由方丈签发，凭此可弟子自由向师尊挑战。\n");
                set("material", "steel");
            set("no_sell",1);
        }
}
int query_autoload() { return 1; }