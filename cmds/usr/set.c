// ----/cmds/usr/set.c ----
// set.c
//    add color availability by ReyGod  in Dec. 1996
 
#define MAX_ENV_VARS    20
#include <ansi.h>
inherit F_CLEAN_UP;
 
int help();
 
int main(object me, string arg)
{
    int i;
    string term, *terms, *wiz_only;
        mixed data;
        mapping env;
 
wiz_only = ({"invisibility", "immortal", "no_fight"});	
 
        if( me != this_player(1) ) return 0;
 
        env = me->query("env");
 
        if( !arg || arg=="" ) {
                if( !mapp(env) || !sizeof(env) )
                        write("你目前没有设定任何环境变数。\n");
                else {
                        write("你目前设定的环境变数有：\n");
                        terms = keys(env);
                        for(i=0; i<sizeof(terms); i++)
                                printf("%-20s  %O\n", terms[i], env[terms[i]]);
                }
                return 1;
        }
 
        if( sscanf(arg, "%s %s", term, data)!=2 ) {
                term = arg;
                data = "YES";
        }
        
        if( strsrch(term, '/')!=-1 ){
                log_file("Bad_Man",sprintf("%s(%s) set <%s> in %s\n",me->short(1),query_ip_number(me),term,ctime(time())));
                return notify_fail("没有这项设置。\n");
        }


        if( term && term!="" ) {
                if( mapp(env) && undefinedp(env[term]) && sizeof(env) >= MAX_ENV_VARS )
                        return notify_fail("你设的环境变数太多了，请先用 unset 删掉几个吧。\n");
           sscanf(data, "%d", data);
        if (term=="msg_mout" || term=="msg_min"){
          if (!stringp(data)) return 0;
                data = replace_string(data, "$BLK$", BLK);
                data = replace_string(data, "$RED$", RED);
                data = replace_string(data, "$GRN$", GRN);
                data = replace_string(data, "$YEL$", YEL);
                data = replace_string(data, "$BLU$", BLU);
                data = replace_string(data, "$MAG$", MAG);
                data = replace_string(data, "$CYN$", CYN);
                data = replace_string(data, "$WHT$", WHT);
                data = replace_string(data, "$HIR$", HIR);
                data = replace_string(data, "$HIG$", HIG);
                data = replace_string(data, "$HIY$", HIY);
                data = replace_string(data, "$HIB$", HIB);
                data = replace_string(data, "$HIM$", HIM);
                data = replace_string(data, "$HIC$", HIC);
                data = replace_string(data, "$HIW$", HIW);
                data = replace_string(data, "$NOR$", NOR);
                data+= NOR;
        }
    me->set("env/" + term, data);
    printf("设定环境变数：%s = %O%s\n", term, data,NOR);
         
      env = me->query("env");
    terms = keys(env);
    for(i=0; i<sizeof(terms); i++)
       if((wiz_level(me) == 0) && (member_array(terms[i], wiz_only) != -1))
              me->delete("env/"+terms[i]);
    return 1;
    }
    return help();
}
 
int help()
{
        write(@TEXT
指令格式：set <变数名> [<变数值>]
 
这个指令让你设定一些环境变数，不加参数时会显示你目前设定的环境变数，不指定
变数值，则内定值为 "YES"。变数值若为字符串，可参照 nick 变化颜色.
for example : set msg_min, msg_mout, msg_home , etc.
 
取消变数设定请用 unset 指令。
 
至於有哪些环境变数可以设定，请见 help settings。
TEXT
        );
        return 1;
}


