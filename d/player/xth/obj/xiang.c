inherit ITEM;
void init();
int do_dian(string arg);
void create()
{
    set_name("�����", ({ "baixiang" }) );
    set_weight(30);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "��");
                set("long", "����һ����,����Ե�ȼ��(dian)��\n");
        set("value", 100);
        set("material", "wood");
    }
    setup();
}
void init()
{
    add_action("do_dian", "dian");
}
int do_dian(string arg)
{
    object me;
    me = this_player();
    if(!arg||arg!="baixiang")
        return notify_fail("��Ҫ��ȼʲô������\n");
    else
        {
            me->set_temp("marks/dian_temp",1);
        return notify_fail("���ȼһ�����������С�\n");
        }       
    return 0;
}
int query_autoload() { return 1; }