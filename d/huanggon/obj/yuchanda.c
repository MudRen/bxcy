inherit ITEM;
void init()
{
    add_action("do_eat", "eat");
}
void create()
{
    set_name("ѩ����󸵤", ({"yuchan dan", "dan"}));
    if (clonep())
        set_default_object(__FILE__);
    else {
        set("unit", "��");
        set("long", "\n���Ǹ�����������ҩ������ⶾ���ˣ�����Ƿ���\n");
        set("value", 10000);
    }
    setup();
}
int do_eat(string arg)
{
    object me = this_player();
    if (!id(arg))
        return notify_fail("��Ҫ��ʲô��\n");
    me->set("jing",me->query("max_jing"));
    me->set("eff_jing",me->query("max_jing"));
    me->set("eff_qi",me->query("max_qi"));
    me->set("qi",me->query("max_qi"));
    message_vision(HIW "$N����һ��ѩ����󸵤��ֻ��һ�ɺƵ�����ֱӿ������
    ��æ��ϥ��������Ŀ�˹�...\n" NOR, me);
    destruct(this_object());
    return 1;
}
int query_autoload() { return 1; }