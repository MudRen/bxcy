//jinlvyi.c
#include <armor.h>

inherit CLOTH;

void create()
{
    set_name("������", ({"jinlv yi", "cloth","yi"}) );
    set_weight(2000);
    if( clonep() )
       set_default_object(__FILE__);
    else {
	set("unit", "��");
		set("long", "���Ǽ������ϼѵĽ����£���������ʹ���ַ��Ƶġ�\n");
	set("material", "cloth");
	set("armor_prop/armor", 10);
        set("value",100);
    }
    setup();
}
int query_autoload() { return 1; }