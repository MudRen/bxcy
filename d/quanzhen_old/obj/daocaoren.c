// daocaoren.c
inherit ITEM;

void create()
{
        set_name("������", ({"daocao ren", "ren"}));
        set_weight(700);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ���õ������ɵĵ����ˡ�\n");
                set("unit", "��");
                set("value", 10);
        }
}

int query_autoload() { return 1; }