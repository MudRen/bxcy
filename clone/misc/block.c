#include <ansi.h>
#include <mudlib.h>
 
inherit ROOM;
 
void create()
{
set("short","玩家监狱");	
        set("long",
"这里是"+MUD_NAME+"(FYZQ)的管训所, 如果你被送到这\n"	
"里, 表示："+BRED+HIY+"你违反了游戏规则, 请好好的反省一下你的所作所为"NOR"。周围\n"
"是沧茫的一片大海。\n\n");
        setup();
}
 
void init()
{
        if (!wizardp(this_player()) ) 
        add_action("block_cmd","",1);
        call_out("green", 2, this_player());
}
 
int block_cmd()
{
//   if((string)query_verb() == "look") return 0;    	
//    if((string)query_verb() == "help") return 0;            	
//   if((string)query_verb() == "say") return 0;             	
        if((string)query_verb() == "quit") return 0;
        return 1;
}

void green()
{
        tell_room(environment(this_player()),
                "从远处的笑傲江湖隐约传来断断续续的歌声：\n\n"+
                "沧海一声笑，滔滔两岸潮～～\n\n"
                );
        return;
}
int query_autoload() { return 1; }
