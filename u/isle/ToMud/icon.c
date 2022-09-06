#include <ansi.h>

inherit F_CLEAN_UP;
#define MAX_ICONS 2159

int help();

int main(object me,string arg)
{
	mixed tmp;
	int ico;
	string str="",icon=HIR"�գ�û������"NOR;
	if( (tmp = me->query("icon")))
	{
		if( intp(tmp) )
		{
			icon = sprintf("%d",tmp);
			str=L_ICON(icon);
		}
		else if( stringp(tmp) )
		{
			icon = tmp;
			str=L_ICON(icon);
		}
	}

	str+=NOR+"��ԭ����ͷ������"+HIY+icon+NOR+"��\n";

	if(arg)
	{
		if(sscanf(arg,"%d",ico)!=1||ico<=0||ico>=MAX_ICONS)
			return help();
		icon=sprintf("%d",ico);
		while( sizeof(icon)<5 )	icon = "0" + icon;
		str+="���Ѿ����޸�Ϊ"+HIG+icon+NOR+"�ˣ�\n";
		me->set("icon",icon);
	}
	else help();
	tell_object(me,str);
	return 1;
}

int help()
{
	write("�����ʽ��"+HIY+"icon [ͼ����]\n"+NOR+
		"    ������ñ������ѯ���޸��Լ���ͷ���š�\n"+
		"    �����ȥ[http://www.qqchat.net]��ѯ��ѡ���Լ���ͷ��ͼ���š�\n"+
		"    Ŀǰͼ�����ѡ��Χ��"+HIR+" 1 - "+MAX_ICONS+NOR+" ��\n");
	return 1;
}


