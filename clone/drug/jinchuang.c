// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
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
        set_name("��ҩ", ({"jinchuang yao", "yao", "jinchuang"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�����˵Ľ�ҩ��\n");
                set("value", 2000);
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
                return notify_fail("�����ڲ���Ҫ�ý�ҩ��\n");
        else {
                this_player()->receive_curing("kee", 50);
                message_vision("$N����һ����ҩ����ɫ�������ö��ˡ�\n",
this_player());
                destruct(this_object());
                return 1;
        }
}

int query_autoload() { return 1; }