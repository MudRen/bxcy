#include <ansi.h>
#include <mudlib.h>
 
inherit ROOM;
 
void create()
{
        set("short","�׺�");
        set("long",
"������"+MUD_NAME+"("+INTERMUD_MUD_NAME+")�Ĺ�ѵ��, ����㱻�͵���\n"
"��, ��ʾ��"+BRED+HIY+"��Υ������Ϸ����, ��úõķ�ʡһ�����������Ϊ"NOR"����Χ\n"
"�ǲ�ã��һƬ�󺣡�\n\n");
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
        if((string)query_verb() == "look") return 0;
        if((string)query_verb() == "help") return 0;
        if((string)query_verb() == "say") return 0;
        if((string)query_verb() == "quit") return 0;
        return 1;
}

void green()
{
        tell_room(environment(this_player()),
                "��Զ����Ц��������Լ�����϶������ĸ�����\n\n"+
                "�׺�һ��Ц����������������\n\n"
                );
        return;
}
