// m_bian.c
#include <ansi.h>
#include <weapon.h>
inherit M_WEAPON;
int do_hui(object weapon);
void create()
{
        object me;
        string w_name,w_id,w_or;
        me = this_player();

        set_name( HIR "��" NOR HIY "��" NOR HIB "��" NOR, ({ "huolong bian", "bian" }) );
        set_weight(150000);
                set("flag",2);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ���ɻ������ѩ��˿�ʳɵĳ��ޣ��ѱ�Ϊǧ�꺮����Զ��ɡ�\n");
                set("material", "leather");
                set("wield_msg", HIY "����к�Ȼ����������Խ�������ͼ���Ĺ�Х֮��............\n"
HIC "һ" HIR "��" HIC "һ" HIW"��" HIC "���������໥��Ť����أ����$N������,һ����������������һ�����ޡ�\n" NOR);
                set("unwield_msg", HIC "һ������֮������$N���е�$n" HIC "��Ȼ�����ˡ�\n" NOR);
        }
//��������
        w_name=me->query("weapon/name");
        w_id = me->query("weapon/id");
        w_or = me->query("weapon/or");
        set("no_get",1);
        set("no_drop",1);
set("no_put",1);
        init_whip(1000,2);
        setup();
}
void init()
{
     if (this_player()!=environment()) return;
     add_action("do_hui","hui");
}
void create()
{   
    object me;
    string w_name,w_id,w_or;
    me = this_player();
//��������
    w_name=me->query("weapon/name");
    w_id = me->query("weapon/id");
    w_or = me->query("weapon/or");
    set("unit", "��");   
    set("no_get",1);
    set("no_drop",1);
    setup();
}   
int do_hui(string weapon)
{   
    string w_name;
    object me;
    me=this_player();
    w_name=me->query("weapon/id");
    if( !weapon || w_name!=weapon)
        return notify_fail("��Ҫ�ݻ�ʲô?\n");
    message_vision(HIR "����һ����һ����ޣ�һ���͵�һ�������ž��һ������"
            +this_object()->name()+HIR+"��Ϊ����!\n" NOR,me);
    me->delete("weapon");   
    me->save();
    destruct( this_object() );
    return 1;
}

