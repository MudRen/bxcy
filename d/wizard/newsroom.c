#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
	set("short", HIY "��������" NOR);
set("long",
"  �����Ǻ�����������ŷ������ģ���ʲô���Ŷ����������﷢����Ȼ��ϵͳ�Զ����֪ͨ����������ҡ�\n"
HIC"����" + YEL" �鿴����-(listmsg)" + GRN"...��������-(addmsg)" + HIR"...ɾ������-(delmsg) " + HIC"����\n"NOR 	
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