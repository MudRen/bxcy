// file:            Autosave daemon
// for autosave players data file.

#pragma save_binary
void autosave(int i)
{

    int  j;
    object *user=children(USER_OB);
    j=i+5;
    for (j=i;j<i+5;j++){
        if(j>=sizeof(user)) return;
        if (!user[j] || !environment(user[j])) continue;
    user[j]->save();

  tell_object(user[j], "�����̾��顿---"+CYN+"�������Ѿ�������ϡ�\n"NOR);
//  CHANNEL_D->do_channel( this_object(), "sys",sprintf("ϵͳ�Զ���� " + reclaim_objects() + " ��������\n"));
   if(random(user[j]->query("kar"))<6&&user[j]->query_condition("killer"))
     CHANNEL_D->do_channel(this_object(),"rumor","�ݿɿ���Ϣ��ɱ�˷�"+user[j]->query("name")+"["+user[j]->query("id")+"]��"+environment(user[j])->query("short")+"һ�����ܡ�\n");



    }
    call_out("autosave",1,i+5);
}
void auto_save();
 
void create()
{
        seteuid(ROOT_UID);
        CHANNEL_D->do_channel( this_object(), "sys", "�Զ�����ϵͳ�Ѿ�������\n\n");
        remove_call_out("auto_save");
        call_out("auto_save", 40);
}

mixed query(string arg)
{
    if (arg=="channel_id") return "���̾���(AutoSave)";
    return 0;
}

void auto_save()
{
        remove_call_out("autosave");
        call_out("autosave",1,0);
        remove_call_out("auto_save");
call_out("auto_save", 600);
}



