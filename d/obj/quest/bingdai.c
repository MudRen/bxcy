inherit ITEM;
#include <task.h>
void create()
{
        set_name("����", ({"bing dai" ,"dai"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",   "һ������װ����Ĵ��ӡ�\n");
                set("unit", "��");
set("owner_name","ŷ����");
set("owner_id","ouyang feng");
        }
}
