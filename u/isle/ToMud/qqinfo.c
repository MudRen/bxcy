int main(object me,string arg)
{
	object obj;
	string str;
	if(!arg)
		obj=me;
	if(arg&&sscanf(arg,"set %s",arg))
	{
	        arg=replace_string(arg,"\"","");
	        arg=replace_string(arg,"'","");
	        arg=replace_string(arg,"\\","");
		me->set("qqinfo",arg);
		write(ALERT("��ĸ�����Ϣ�Ѿ����óɹ�!\n"));
		return 1;
	}
	if(arg&&!objectp(obj))
		obj = UPDATE_D->global_find_player(arg);
	if(!objectp(obj)) return notify_fail(ALERT("�޷���ѯ�Է���Ϣ��"));
	if(stringp(str=obj->query("qqinfo")))
	{
		write(TMI("qqinfo"+((obj==me)?"0":"1")+" "+str));
		return 1;
	}
	write(TMI("qqinfo"+((obj==me)?"0":"1")+""));
	if(obj->query_temp("temp_loaded"))
		UPDATE_D->global_destruct_player(obj,0);
	return 1;
}
