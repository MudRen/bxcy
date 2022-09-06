inherit F_CLEAN_UP;

int main(object me, string arg)
{
   object link_ob;
   int cur_time;

   seteuid(getuid());

   if( !objectp(link_ob = me->query_temp("link_ob")) )
     return notify_fail("�㲻�Ǿ����������߽��룬���ܴ��档\n");
     
    cur_time = time();
    if( (cur_time-me->query("last_backup")) < 600 )     
      return notify_fail("Ϊ�˽�ʡϵͳ������10����֮��ֻ�ܱ���һ�Ρ�\n");
   
    me->set("last_backup", cur_time);
    
   if( (int)link_ob->save() && (int)me->save() && (int)me->backup()) {

         write("�������沢������ϡ�\n");
        
     return 1;
   } else {
       write("��������ʧ�ܣ�����ϵ��ʦ��\n");
     return 1;
   }
}

int help(object me)
{
   write(@HELP
ָ���ʽ��backup

���ݵ���������ĵ�������Ī��������˺��󣬿�Ҫ����ʦ�ָ���
HELP
   );
   return 1;
}

