// reboot.c
inherit F_CLEAN_UP;
int main(object me, string arg)
{
	string wiz_status;
	object npc;
	if( me != this_player(1) ) return 0;
	
	wiz_status = SECURITY_D->get_status(me);
    if( wiz_status != "(boss)" && wiz_status != "(admin)" && wiz_status != "(arch)"&&me->query("id")!="snow" )
		return notify_fail("只有 (arch) 以上的巫师才能重新启动" + MUD_NAME + "\n");
	seteuid(getuid());
	npc = new("/clone/npc/demogorgon");
	npc->move("/d/city/guangchang");
	npc->start_shutdown();
	write_file("/log/static/LASTCRASH", geteuid(me) + " reboot豪侠晚歌于 " + ctime(time()) + "\n");
	write("Ok。\n");
	return 1;
}
int help (object me)
{
        write(@HELP
指令格式: reboot
 
延时十五分钟重新起动游戏。
 
HELP
);
        return 1;
}
 
