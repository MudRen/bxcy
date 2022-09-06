// ----/clone/misc/mask.c ----
// mask.c
inherit ITEM;
void create()
{
        set_name("���", ({ "mian ju", "mask" }) );
        set_weight(3000);
/*
        if( clonep() )
                set_default_object(__FILE__);
        else {
*/
                set("unit", "��");
                set("long", "���ƺ���һ������Ƥ�Ƴɵ���ߣ����������װ��(pretend)�����ˡ�\n");
set("value", 0);                	
//                set("no_drop", "�������������뿪�㡣\n");
                set("no_put",1);                
// }
        setup();
}

void init()
{
    if (this_player()==environment()){
        add_action("do_pretend", "pretend");
    }
}

int do_pretend(string arg)
{
        object who;
        if (!arg || wiz_level(arg) > 0)
                return notify_fail("�����װ˭��\n");
        if (arg == "none" || arg == "cancel") {
         if (!(string)this_player()->query_temp("apply/name"))
             {   tell_object(this_player(),"���Ѿ�ȡ�������!\n"); return 1; }
                if (!(who=query("equipped_ob") ) )
                     who=this_player();
                who->delete_temp("apply/name");
                who->delete_temp("apply/id");
                who->delete_temp("apply/short");
                who->delete_temp("apply/long");
// /*
        if (arg == "cancel")
                tell_object(who,"��Ƥ��ߴ������ϻ���������\n");
            else
                message_vision("$N������ȡ����һ����Ƥ��ߡ�\n", who);
// */
                delete("equipped");
                delete("equipped_ob");
                return 1;
        }
        if(!objectp(who = present(arg, environment(this_player())))
            ||  wiz_level(who) > 1 
            ||  who->query("apply/name")
            ||  !living(who)
            ||  who->query("race")!="����" )
              return notify_fail("�����װ˭��\n");
      if (who==this_player()) return notify_fail("���Լ����õ������ô��\n");
      if ((string)this_player()->query_temp("apply/name")==who->name())
             {   tell_object(this_player(),"���Ѿ����������!\n"); return 1; }
        write("�㿪ʼ��װ" + who->name() + "��\n");
        message_vision("$N������һ�������Ƴɵ���Ƥ��ߡ�\n", this_player());
this_player()->set_temp("apply/name", ({who->name()}));	
        this_player()->set_temp("apply/id",who->parse_command_id_list());
        this_player()->set_temp("apply/short", ({who->short(1)}));
        this_player()->set_temp("apply/long", ({who->long()}));
        set("equipped","mask");
        set("armor_type","head");
        set("equipped_ob",this_player());
        return 1;
}

int unequip()
{
    do_pretend("none");
    return 1;
}

int query_autoload() { return 1; }