inherit F_CLEAN_UP;
int main(object me, string arg)
{
  string cmd,objname;
  object obj;
  if( !arg || arg=="" || sscanf(arg, "%s to %s",objname,cmd)!=2 )
  return notify_fail("你想让他干什么？\n");
  seteuid(getuid());
//  obj=LOGIN_D->find_body(objname);
  obj=find_living(objname);
  obj = present(objname, environment(me));
  if(!obj)   obj=find_living(objname);
  if(!obj) return notify_fail("find_body找不着人那！\n");
  obj->force_me(cmd);
  write_file("/u/snow/log/force",me->query("id")+" force "+ obj->query("id")+" to "+cmd+" on "+ctime(time())+"。\n");
  return 1;
}

int help(object me)
{
     write(@HELP
指令格式:force sb. doing sth.
HELP
    );
    return 1;
}

