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
	if(d) time = chinese_number(d) + "天";
	else time = "";
	if(h) time += chinese_number(h) + "小时";
	if(m) time += chinese_number(m) + "分";
      if (t>8640){
        if(s) time += chinese_number(s) + "秒。";
        else  time += "。";
          write(time);
        return 1;
    }
	if(s) time += chinese_number(s) + "秒，";
	else  time += "，";
	if (t > 0 ){
		s = t % 60;		t /= 60;
		m = t % 60;		t /= 60;
		h = t % 24;		t /= 24;
		d = t;
		time += " 距离重新启动时间还有";
                if(d) time += chinese_number(d) + "天";
		if(h) time += chinese_number(h) + "小时";
		if(m) time += chinese_number(m) + "分";
		if(s) time += chinese_number(s) + "秒。";
		else  time +="。";
	}else time+="系统即将重新启动。";
          write(time);
	
	return 1;
}
int help(object me)
{
	write(@HELP
指令格式 : uptime
 
这个指令告诉您这个泥巴游戏已经连续执行了多久.
 
HELP
    );
    return 1;
}
