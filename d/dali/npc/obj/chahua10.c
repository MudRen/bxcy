//chahua10.c
#include <ansi.h>;
#include <armor.h>;
inherit HEAD;

void create()
{
set_name(HIB"��"HIW"����"NOR, ({"cha hua","cha hua 10", "hua"}));	
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", 
"һ��軨����ɫ��������������魺˶��ڰߡ�\n");
                set("value", 5000);
                set("material", "plant");
                set_weight(10);
                set("armor_prop/armor", 0);
                set("armor_prop/personality", 3);
                set("wear_msg", "$N����ذ�һ��$n����ͷ�ϡ�\n");
                set("unequip_msg", "$N����ذ�$n��ͷ��ժ��������\n");
        }
        setup();
}
int query_autoload() { return 1; }