inherit ITEM;
#include <task.h>
void create()
{
        set_name("������", ({"suoming sheng", "sheng"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "�����������ͷ��һ�ף���ɾ͡�������\n");
                set("unit", "��");
 set("owner_name",HIR "����" NOR);
               set("owner_id","jing lei");
        }
}