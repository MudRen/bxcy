// dadao.c
#include <weapon.h>
inherit BLADE;
void create()
{
        set_name(RED "血狼" NOR, ({ "blade","wolf blade" }));
        set_weight(1000);
                if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("long", RED "刀身上隐隐透出红光，令人看了心中一寒。\n" NOR);
                set("value", 0);
                set("flag",2);
                                set("material", "steel");
                set("wield_msg", RED "$N抽出一把血狼，顿时$N双目尽赤，身上发出爆豆一样的声响。\n" NOR);
                set("unwield_msg", RED "$N将手中的$n插回背后。\n" NOR);
        }
        init_blade(random(1000)+50,1);
        setup();
}
/*
int wield()
{
    if (::wield()){
            environment()->set("attitude","aggressive");
            return 1;
    }else
    return 0;
}
int unequip()
{
    if (::unequip()){
            environment()->set("attitude","heroism");
            return 1;
    }else
    return 0;
}
*/
int query_autoload() { return 1; }