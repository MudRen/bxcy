// mudao.c
#include <weapon.h>
inherit CLUB;
void create()
{
    set_name("ľ��", ({ "mu gun", "gun", "club" }) );
    set_weight(2000);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "��");
        set("value", 30);
        set("material", "iron");
        set("long", "����һ�������೤��ľ����\n");
        set("wield_msg", "$N˫������$n���趯��һ�£�����������\n");
        set("unequip_msg", "$N�����е�$n��ر���\n");
    }
    init_club(1,1);
    setup();
}
