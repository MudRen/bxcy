// jinchuang.c ��ҩ

inherit ITEM;

void setup()
{}

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name("������", ({"dieda wan", "wan", "yao"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�����˵ĵ���ҩ��\n");
                set("value", 1500);
          set("drug_type", "��ҩ");
        }
        setup();
}

int do_eat(string arg)
{
        if (!id(arg))
                return notify_fail("��Ҫ��ʲôҩ��\n");
        if ((int)this_player()->query("eff_kee") == 
            (int)this_player()->query("max_kee"))
                return notify_fail("�����ڲ���Ҫ�õ���ҩ��\n");
        else {
                this_player()->receive_curing("kee", 30);
                message_vision("$N����һ�ŵ����裬��ɫ�������ö��ˡ�\n",this_player());
                destruct(this_object());
                return 1;
        }
}

int query_autoload() { return 1; }