inherit ITEM;


void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name("�ɵ�", ({"huanhun dan", "dan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ���ɰ�����������ҩ�裬���������й��׵���ҡ�\n");
        }
}
int do_eat(string arg)
{
        if (!id(arg))
             return notify_fail("��Ҫ��ʲôҩ��\n");
 else{
       this_player()->add("combat_exp",50000);
       this_player()->add("potential",50000);
message_vision("$N����һ���ɵ���ֻ�����Լ��ֱ�������һЩ !\n", this_player());
        destruct(this_object());
        return 1;
        }
}

int query_autoload() { return 1; }
