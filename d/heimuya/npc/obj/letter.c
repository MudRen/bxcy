// letter.c
inherit ITEM;
void create()
{
        set_name("��", ({"letter"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","����һ����ӯӯ�����������顣\n");
//		set("no_drop", "�������������뿪�㡣\n");
                set("material", "paper");
        }
}
int query_autoload() { return 1; }