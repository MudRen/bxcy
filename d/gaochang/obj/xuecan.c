// medicine: xuecan.c
// by mei 
inherit ITEM;
void setup()
{}
void create()
{
        set_name(HIW "雪蚕" NOR, ({ "xue can", "can" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "条");
                set("long", "这是一条只有在极寒冷的地方才能生长的、通体雪白的"+HIW+"雪蚕"+NOR+"。\n");
                set("value", 100);
        }
        setup();
}
int move(mixed dest, int silently)
{
    if (objectp(dest)){
        if (userp(dest))
         dest->apply_condition("xuecan_poison", 30);
    }
    return ::move(dest,silently);
}int query_autoload() { return 1; }
