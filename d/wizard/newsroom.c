#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
	set("short", HIY "江湖新闻" NOR);
set("long",
"  这里是豪侠晚歌的新闻发布中心，有什么新闻都可以在这里发布，然后系统自动随机通知所有在线玩家。\n"
HIC"〔「" + YEL" 查看新闻-(listmsg)" + GRN"...增加新闻-(addmsg)" + HIR"...删除新闻-(delmsg) " + HIC"」〕\n"NOR 	
);	
	set("exits", ([
           "north" : __DIR__"snow_room",
	]));
	set("objects",([
"d/wizard/newer":1,   	
"adm/daemons/msgd":1,     	
	]));
	set("no_clean_up", 1);
set("no_fight", 1);	
	setup();
//           call_other("/d/board/news_b", "???");	
	replace_program(ROOM);
}
