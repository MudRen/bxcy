#include <ansi.h>
#include <room.h>
inherit ROOM;
void auto_free(object who,int sec);
void create()
{
set("short","[1;35m������[0m");
set("long", @LONG

  �����Ǿ�����������������Ķ���--��MUD���ع涨���ˡ�
�������������, ��ú���ʦ��ϻش�һЩ�򵥵�����, �������
������Ի�ü����!! Ȱ�㲻Ҫ����, ������ر��Ƿǳ�ɭ�ϵġ�
��~~~ѽ~~~ѽ~~~~  �ú÷�ʡ��!!! ���ĵĵȺ������о���!

LONG
       );
set("light",1);
set("objects", ([ /* sizeof() == 2 */
]));
setup();
}
void init()
{
	int time;
	if(time=this_player()->query("putjail_time")) call_out("auto_free",5,this_player(),time-5);
	if(wiz_level(this_player()) > wiz_level("(immortal)"))
	{
		tell_object(this_player(),"\n�뿪���ͷ�����free <id>\n�� timeup ָ����Զ�ʱ�Զ��ͷ�.\n\n");
		add_action("do_free", "free");
		add_action("do_countdown","timeup");
		return;
	}
	this_player()->set_temp("out_of_power",1);
        add_action("no_action", "cast");
        add_action("no_action", "exert");
        add_action("no_quit", "quit");
        add_action("no_quit", "Q");
        add_action("no_kill", "kill");
        add_action("no_goto", "home");
        add_action("no_goto", "recall");
        add_action("no_quit", "fight");
        add_action("no_goto", "goto");
        add_action("no_goto", "recall");
        add_action("no_rm",   "rm");
        add_action("no_dest", "dest");
        add_action("no_more", "more");
        add_action("no_cat",  "update");
        add_action("no_cat",  "cat");
        add_action("no_edit", "edit");
        add_action("no_tell", "clone");
        add_action("no_tell", "mkroom");
        add_action("no_tell", "shutdown");
        add_action("no_tell", "rest");
        add_action("no_tell", "connect");
        add_action("no_tell", "saveroom");
        add_action("no_tell", "localcmds");
        add_action("no_tell", "cp");
        add_action("no_tell", "tell");
        add_action("no_tell", "beep");
        add_action("no_tell", "tchat");
        add_action("no_tell", "tchat*");
        add_action("no_tell", "ds");
        add_action("no_tell", "ds*");
        add_action("no_tell", "chat");
        add_action("no_tell", "chat*");
        add_action("no_tell", "music");
        add_action("no_tell", "music*");
        add_action("no_tell", "rumor");
        add_action("no_tell", "report");
        add_action("no_tell", "rumor*");
        add_action("no_tell", "wiz");
        add_action("no_tell", "wiz*");
        add_action("no_tell", "es");
        add_action("no_tell", "es*");
        add_action("no_tell", "gwiz");
        add_action("no_tell", "twiz");
        add_action("no_tell", "sys");
        add_action("no_tell", "ls");
        add_action("no_tell", "shout");
        add_action("no_call", "call");
        add_action("no_dest", "smash");
        add_action("do_fuck", "fuck");
        add_action("no_fly","fly");
        add_action("no_jump","jump");
        add_action("no_summon","summon");
        add_action("no_suicide", "suicide");
}
int do_countdown(string str)
{
	object who;
	int time;
	string who_name;
	
     if(sscanf(str,"%s %d",who_name,time)!=2) return notify_fail("time <who> <����>\n");
     if(!who=present(who_name,this_object())) return notify_fail("�Զ��ͷ�˭?\n");
     if(time < 179) return notify_fail("����Ҫ��������!! (180��)\n");
     message_vision("$N��$n�ļ��ʱ���趨Ϊ"+(string)time+"�롣\n",this_player(),who);
     who->set("putjail_time",time);
     who->save();
     who->move("/u/fyue/jail");
     call_out("auto_free",180,who,time-180);
        return 1;
}

int no_action(string str)
{
     write(HIY"����ﰡ? �㻹�ǹԹԷ�ʡһ�°�.. \n"NOR);
        return 1;
}
int no_suicide(string str)
{
     write(HIY"����Ҳ������ô���׵�..����Ϊsuicide��û����  :( \n"NOR);
        return 1;
}
int no_quit(string str)
{
     write(HIY"��ץ��..������..����Ϊquit��û����  :( \n"NOR);
        return 1;
}
int no_goto(string str)
{
     write(HIC"������!!���Ծ�����������..������????\n"NOR);
        return 1;
}
int no_kill(string str)
{
	write("�����ֹ���κ�Ѫ�ȵı����¼�������\n");
        return 1;
}
int no_more(string str)
{
     write(HIY"����more ͵����ĵ��...�Ŷ�û��...\n"NOR);
        return 1;
}
int no_rm(string str)
{
        write("ʲô?!�����˾�ʲôȨ����û��, ����rm!!\n");

       return 1;
}
int no_dest(string str)
{
        write("����ݻ�����!!�����������ǲ��ܴݻٵ�!!\n");
        return 1;

}
int no_cat(string str)
{
        write("����è����������������������\n");
        return 1;
}
int no_edit(string str)
{
    write(HIG"������EDIT͵�����ﰡ..�Ŷ�û��!!!\n"NOR);
       return 1;
}
int no_call(string str)
{
       write("CALL!!�� �� �� B.B.CALL ��\n");
        return 1;
}
int do_fuck(string str)
{
        object ob;
        ob = this_player();
        //ob->reincarnate();
//ob->move("/u/s/sammy/pkroom");
        return 1;
}

int do_free(string str)
{
        object ob,who,env;
        string where;
        
        ob = this_player();
        if(!who=present(str,this_object())) return notify_fail("�ͷ�˭?\n");
	message_vision("$N��$n�ͷ���!\n",ob,who);
	message("system","\n\n  [1;32m "+who->name(1)+"������, ϣ�����ܸĹ�����, �´β�Ҫ�ٷ����ˡ�[0m\n\n",users());
	where=who->query("putjail_position");
	if(where)
	{
		env=load_object(where);
		if(env && env!= this_object() )
		{
			message_vision("$N�����ͻ�"+env->query("short")+"��..\n",who);
			who->move(env);
			
		}else who->move("/d/city/wumiao");
	}
	else who->move("/d/city/wumiao");
        who->delete_temp("out_of_power");
        who->delete("putjail_time");
	who->delete("putjail_position");
        who->save();
        return 1;
}


int no_fly(string str)
{
        write("������~~~���ǲ��Ҳ�ѷ���~~~~~�Ǻ�~~:p\n");
        return 1;
}
int no_jump(string str)
{
        write("��!!!����??��Ҫ��ȥ�ǰ�???????\n");

return 1;
}
int no_summon(string str)
{
        write("�ٺ�....��ץ�������㰡???????ʡʡ��!!!!!\n");
        return 1;
}
int no_tell(string str)
{
write("[1;33m����ɶ?���ڳ��η��˻������ְ�������[0m");
write("\n");
return 1;
}

void auto_free(object who,int sec)
{
	string where;
	object env;
	if(!who) return;
	if(environment(who)!=this_object())
	{
		who->delete("putjail_position");
		who->delete("putjail_time");
		who->delete_temp("out_of_power");
		return ;
	}
	
	if(sec<1)
	{
		message("system","\n\n  [1;32m "+who->name(1)+"������, ϣ�����ܸĹ�����, �´β�Ҫ�ٷ����ˡ�[0m\n\n",users());
		where=who->query("putjail_position");
		if(where) env=load_object(where);
		if(env && env!=this_object())
		{
			who->move(env);
		}
		else who->move("/d/city/wumiao");
        	who->delete_temp("out_of_power");
		who->delete("putjail_position");
		who->delete("putjail_time");
		who->save();
        	return;
        }
        message_vision("$N�����ڻ���"+sec+"��.\n",who);
        who->set("putjail_time",sec);
        who->save();
	if(sec>300) call_out("auto_free",300,who,sec-300);
	else call_out("auto_free",sec,who,0);
	return;
}