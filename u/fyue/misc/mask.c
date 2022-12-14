// ----/clone/misc/mask.c ----
// mask.c
inherit ITEM;
void create()
{
        set_name("面具", ({ "mian ju", "mask" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long", "这似乎是一个由人皮制成的面具，你可以用它装扮(pretend)其他人。\n");
//                set("no_drop", "这样东西不能离开你。\n");
                set("no_put",1);
        }
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
                return notify_fail("你想假装谁？\n");
        if (arg == "none" || arg == "cancel") {
         if (!(string)this_player()->query_temp("apply/name"))
             {   tell_object(this_player(),"你已经取下面具了!\n"); return 1; }
                if (!(who=query("equipped_ob") ) )
                     who=this_player();
                who->delete_temp("apply/name");
                who->delete_temp("apply/id");
                who->delete_temp("apply/short");
                who->delete_temp("apply/long");
/*
        if (arg == "cancel")
                tell_object(who,"人皮面具从你脸上滑落下来。\n");
            else
                message_vision("$N从脸上取下了一个人皮面具。\n", who);
*/
                delete("equipped");
                delete("equipped_ob");
                return 1;
        }
        if(!objectp(who = present(arg, environment(this_player())))
            ||  wiz_level(who) > 1 
            ||  who->query("apply/name")
            ||  !living(who)
            ||  who->query("race")!="人类" )
              return notify_fail("你想假装谁？\n");
      if (who==this_player()) return notify_fail("扮自己还用得着面具么？\n");
      if ((string)this_player()->query_temp("apply/name")==who->name())
             {   tell_object(this_player(),"你已经带上面具了!\n"); return 1; }
        write("你开始假装" + who->name() + "。\n");
        message_vision("$N戴上了一个精功制成的人皮面具。\n", this_player());
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

