// file:            Autosave daemon
// for autosave players data file.

// #pragma save_binary
void autosave(int i)
{

    int  j;
    object *user=children(USER_OB);
    j=i+5;
    for (j=i;j<i+5;j++){
        if(j>=sizeof(user)) return;
        if (!user[j] || !environment(user[j])) continue;
    user[j]->save();

  tell_object(user[j], "【存盘精灵】---"+CYN+"【档案已经储存完毕】\n"NOR);
//  CHANNEL_D->do_channel( this_object(), "sys",sprintf("系统自动清除 " + reclaim_objects() + " 个变数。\n"));
   if(random(user[j]->query("kar"))<6&&user[j]->query_condition("killer"))
     CHANNEL_D->do_channel(this_object(),"rumor","据可靠消息，杀人犯"+user[j]->query("name")+"["+user[j]->query("id")+"]在"+environment(user[j])->query("short")+"一带流窜。\n");



    }
    call_out("autosave",1,i+5);
}
void auto_save();

void create()
{
        seteuid(ROOT_UID);
        CHANNEL_D->do_channel( this_object(), "sys", "自动存盘系统已经启动。\n\n");
        remove_call_out("auto_save");
        call_out("auto_save", 40);
}

mixed query(string arg)
{
    if (arg=="channel_id") return "存盘精灵(AutoSave)";
    return 0;
}

void auto_save()
{
        remove_call_out("autosave");
        call_out("autosave",1,0);
        remove_call_out("auto_save");
call_out("auto_save", 600);
}
