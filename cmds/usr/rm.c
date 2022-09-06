#include "/doc/help.h"
inherit F_CLEAN_UP;
int help(object me);

string query(string str)
{
    if (str && str=="channel_id")
        return "�ڿ͹���";
    return 0;
}
int main(object me, string str,int flag)
{
   mixed *multi;
   int loop;
    if ( wiz_level(me) > 3 )  return "/cmds/wiz/rm.c"->main(me,str);
 
   if(!str || str == "")  return help(me);
   
   seteuid(getuid(me));
 
   if(sscanf(str, "-r %s", str) == 1
   || sscanf(str, "%s -r", str) == 1)
      flag = 1;
  
   multi = explode(str, " ");

   if(multi && sizeof(multi) > 1) {

      for(loop=0; loop<sizeof(multi); loop++)
          main( me,multi[loop],flag );

      return 1; 
   }
 
 
   //  Check to see if the request is bad ("..*")

   if(str == "..*") {
      write("Rm: ��Ч�Ĳ�����\n");
      return 1; 
   }
 
   str = resolve_path(me->query("cwd"), str);
   if (! wizardp(me) ){
        str=sprintf("%s(%s) try rm %s\n",me->short(1),query_ip_number(me),str);
        log_file("RM",str );
        CHANNEL_D->do_channel(this_object(), "sys",str);
   }
 
   return 0; 
}
 

int help(object me)
{
    return 0;
}

