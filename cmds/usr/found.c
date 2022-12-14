#include <ansi.h>
inherit F_CLEAN_UP;
int check_legal_name(string name);
int do_cp(string,string,string,int);
string resolvePath(string,int);
int main(object me, string arg)
{
	object gold;
	string e_name,c_name;	
	string *dir;
	int i;
	string  path,wild,dest;
	seteuid(getuid());
        if(!arg || sscanf(arg,"%s %s",e_name, c_name) != 2)
        return notify_fail("指令格式：　found xuelianjiao 雪莲教\n");
   if (me->query("guild/id"))
   	return notify_fail("你已经有帮派了。\n");
   for(i=0; i<strlen(e_name); i++)
   if( e_name[i] < 'a' || e_name[i] > 'z' )
   	return notify_fail("<帮派代号>必须由小写英文字母组成。\n");
	 if((int)me->query("combat_exp")/10 < 10000000)
        return notify_fail("你的经验不够一亿点。\n");
	if((int)me->query("more_money")<100)
		return notify_fail("你的钱庄存款不够一百万。\n");
	if(!check_legal_name(c_name))
	return 1;
	dir = get_dir(DATA_DIR+"guild/");
	for(i=0; i<sizeof(dir); i++) 
	if(dir[i] == e_name || dir[i] == c_name)
	return notify_fail("你想创立的帮派中文或英文名字已经被别人占用了！\n");	

write_file(DATA_DIR+"guild/"+e_name,me->query("id"));
write_file(DATA_DIR+"guild/"+c_name,me->query("name"));

	me->set("guild/id",e_name);
	me->set("guild/name",c_name);
	me->set("guild/generation",1);
	me->add("more_money",-100);
	
	path="/u/party/*.c";
	dest="d/" + "party/" + me->query("guild/id");
	wild=resolvePath(path,0);
	path=resolvePath(path,1);
	do_cp(path,wild,dest,15);
	path="/u/party/npc";
	wild=resolvePath(path,0);
	path=resolvePath(path,1);
	do_cp(path,wild,dest,15);	
 	message("system",
	HIM"\n  ☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆ \n\n\n"HIW 
		"\t\t      『  "+c_name+"』"+"在江湖中成立了！\n\n\n"HIW"
	    \n  ☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆ ☆ \n"NOR,
			users() );
    return 1;
}


 
int help(object me)
{
    write(@HELP
让你在碧血残阳中成立自己的帮派！

指令格式: 
found yanyulou 烟雨楼

此指令让你创立一个新的帮，派，或教。
HELP
    );
	return 1;
}
 
int check_legal_name(string name)
{
        int i;
        i = strlen(name);
        if( (strlen(name) < 4) || (strlen(name) > 30 ) ) {
                write("对不起，中文名字必须是二到十五个中文字。\n");
                return 0;
        }
        while(i--) {
                if( name[i]<=' ' ) {
                        write("对不起，中文名字不能用控制字元。\n");
                        return 0;
                }
                if( i%2==0 && !is_chinese(name[i..<0]) ) {
                        write("对不起，名字必需是中文。\n");
                        return 0;
                }
        }
        return 1;
}
string resolvePath(string path,int op)
{
	string *dn,tmp;
	int i;
	if(path=="/")//对这个情况特殊处理
		return (op)?"/":"*";
	dn=explode(path,"/");
	if(op)//op为非0表示需要返回路径
	{
		//dn=dn-({dn[sizeof(dn)-1]});
		//tmp=implode(dn,"/")+"/";
		//上面的程序不好，不能对同名路径正确处理，比如不能在/log/log文件里搜索
		tmp="/";
		for(i=0;i<sizeof(dn)-1;i++)
		{
			//write("合并"+dn[i]+"\n");
			tmp+=dn[i]+"/";
		}
		return tmp;
	}
	else
		return dn[sizeof(dn)-1];
}
int do_cp(string path,string wild,string dest,int level)
{
	//int i;string *fs;
	string file;
	reset_eval_cost();//重新设置剩余执行时间，必须设置！
	if(dest[sizeof(dest)-1]!='/')//这句必不可少，不然就不能正确生成目标路径
    	dest=dest+"/";
	if(this_player()->query("env/debug"))
		write("开始复制"+path+wild+"到"+dest+"\n");
	if(level<0)
	{
		//write("级别限制，不能再进入。\n");
		return 0;
	}
	
	foreach(file in get_dir(path+wild))
	{

		if(file=="."||file=="..")
			continue;
		
		switch(file_size(path+file))
		{
			case -1:
				//无法读取该目录，跳过
				break;
			case -2:
				if(file!="."&&file!="..")
					do_cp(path+file+"/","*",dest+file+"/",level-1);
				break;
			default:
				assure_file(dest+file);
				//write("复制文件："+path+file+"到"+dest+file+"\n");
				cp(path+file,dest+file);
		}
		
	}
	return 1;
}

