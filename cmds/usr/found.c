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
        return notify_fail("ָ���ʽ����found xuelianjiao ѩ����\n");
   if (me->query("guild/id"))
   	return notify_fail("���Ѿ��а����ˡ�\n");
   for(i=0; i<strlen(e_name); i++)
   if( e_name[i] < 'a' || e_name[i] > 'z' )
   	return notify_fail("<���ɴ���>������СдӢ����ĸ��ɡ�\n");
	 if((int)me->query("combat_exp")/10 < 10000000)
        return notify_fail("��ľ��鲻��һ�ڵ㡣\n");
	if((int)me->query("more_money")<100)
		return notify_fail("���Ǯׯ����һ����\n");
	if(!check_legal_name(c_name))
	return 1;
	dir = get_dir(DATA_DIR+"guild/");
	for(i=0; i<sizeof(dir); i++) 
	if(dir[i] == e_name || dir[i] == c_name)
	return notify_fail("���봴���İ������Ļ�Ӣ�������Ѿ�������ռ���ˣ�\n");	

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
	HIM"\n  �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� \n\n\n"HIW 
		"\t\t      ��  "+c_name+"��"+"�ڽ����г����ˣ�\n\n\n"HIW"
	    \n  �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� \n"NOR,
			users() );
    return 1;
}


 
int help(object me)
{
    write(@HELP
�����ڱ�Ѫ�����г����Լ��İ��ɣ�

ָ���ʽ: 
found yanyulou ����¥

��ָ�����㴴��һ���µİ�ɣ���̡�
HELP
    );
	return 1;
}
 
int check_legal_name(string name)
{
        int i;
        i = strlen(name);
        if( (strlen(name) < 4) || (strlen(name) > 30 ) ) {
                write("�Բ����������ֱ����Ƕ���ʮ��������֡�\n");
                return 0;
        }
        while(i--) {
                if( name[i]<=' ' ) {
                        write("�Բ����������ֲ����ÿ�����Ԫ��\n");
                        return 0;
                }
                if( i%2==0 && !is_chinese(name[i..<0]) ) {
                        write("�Բ������ֱ��������ġ�\n");
                        return 0;
                }
        }
        return 1;
}
string resolvePath(string path,int op)
{
	string *dn,tmp;
	int i;
	if(path=="/")//�����������⴦��
		return (op)?"/":"*";
	dn=explode(path,"/");
	if(op)//opΪ��0��ʾ��Ҫ����·��
	{
		//dn=dn-({dn[sizeof(dn)-1]});
		//tmp=implode(dn,"/")+"/";
		//����ĳ��򲻺ã����ܶ�ͬ��·����ȷ�������粻����/log/log�ļ�������
		tmp="/";
		for(i=0;i<sizeof(dn)-1;i++)
		{
			//write("�ϲ�"+dn[i]+"\n");
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
	reset_eval_cost();//��������ʣ��ִ��ʱ�䣬�������ã�
	if(dest[sizeof(dest)-1]!='/')//���ز����٣���Ȼ�Ͳ�����ȷ����Ŀ��·��
    	dest=dest+"/";
	if(this_player()->query("env/debug"))
		write("��ʼ����"+path+wild+"��"+dest+"\n");
	if(level<0)
	{
		//write("�������ƣ������ٽ��롣\n");
		return 0;
	}
	
	foreach(file in get_dir(path+wild))
	{

		if(file=="."||file=="..")
			continue;
		
		switch(file_size(path+file))
		{
			case -1:
				//�޷���ȡ��Ŀ¼������
				break;
			case -2:
				if(file!="."&&file!="..")
					do_cp(path+file+"/","*",dest+file+"/",level-1);
				break;
			default:
				assure_file(dest+file);
				//write("�����ļ���"+path+file+"��"+dest+file+"\n");
				cp(path+file,dest+file);
		}
		
	}
	return 1;
}

