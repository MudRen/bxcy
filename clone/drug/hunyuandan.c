// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// hunyuandan.c ��Ԫ�� 

inherit ITEM;

void setup()
{}

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name("��Ԫ��", ({"hunyuan dan", "dan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ���Դ�������ҩ�裮\n");
                set("value", 2000);
          set("drug_type", "��ҩ");
        }
        setup();
}

int do_eat(string arg)
{
        if (!id(arg))
                return notify_fail("��Ҫ��ʲôҩ��\n");
        if ((int)this_player()->query("eff_sen") == 
            (int)this_player()->query("max_sen"))
                return notify_fail("�����ڲ���Ҫ�û�Ԫ����\n");
        else {
                this_player()->receive_curing("sen", 40);
                message_vision("$N����һ�Ż�Ԫ������ɫ�������ö��ˣ�\n",
this_player());
                destruct(this_object());
                return 1;
        }
}

int query_autoload() { return 1; }