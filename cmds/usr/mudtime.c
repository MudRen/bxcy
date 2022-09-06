// uptime.c
// Modified by Fan
#include <mudlib.h>
inherit F_CLEAN_UP;
// This command is also called by LOGIN_D, so we don't want it use 
// arguments.
int main()
{
        int t, d, h, m, s;
	string time;
	t = uptime();
	s = t % 60;		t /= 60;
	m = t % 60;		t /= 60;
	h = t % 24;		t /= 24;
	d = t;
        t = 172800-uptime();
	if(d) time = chinese_number(d) + "��";
	else time = "";
	if(h) time += chinese_number(h) + "Сʱ";
	if(m) time += chinese_number(m) + "��";
      if (t>8640){
        if(s) time += chinese_number(s) + "�롣";
        else  time += "��";
          write(time);
        return 1;
    }
	if(s) time += chinese_number(s) + "�룬";
	else  time += "��";
	if (t > 0 ){
		s = t % 60;		t /= 60;
		m = t % 60;		t /= 60;
		h = t % 24;		t /= 24;
		d = t;
		time += " ������������ʱ�仹��";
                if(d) time += chinese_number(d) + "��";
		if(h) time += chinese_number(h) + "Сʱ";
		if(m) time += chinese_number(m) + "��";
		if(s) time += chinese_number(s) + "�롣";
		else  time +="��";
	}else time+="ϵͳ��������������";
          write(time);
	
	return 1;
}
int help(object me)
{
	write(@HELP
ָ���ʽ : uptime
 
���ָ���������������Ϸ�Ѿ�����ִ���˶��.
 
HELP
    );
    return 1;
}
