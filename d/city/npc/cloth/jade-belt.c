// jade-belt.c example belt

#include <ansi.h>

inherit EQUIP;

void create()
{
        set_name( HIB "����ʯ����" NOR, ({ "jade belt", "belt" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 30000);
                set("material", "cloth");
                set("armor_type", "waist");
                set("armor_prop/personality", 2);
                set("armor_prop/armor", 4);
                set("armor_prop/dodge", -1);
                set("wear_msg","$NΧ��һ��$n��\n");
                set("remove_msg","$N��$n����������\n");
        }
}