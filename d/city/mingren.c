// Room: /city/mingren.c
// YZC 1995/12/04 

#include <room.h>

inherit ROOM;
string look_shu();

void create()
{
	set("short", "������");
	set("long", @LONG
������ǽ�����һ�ٵ������á������﹩����д�����Ҳ��ħͷ��	
Ҳ�в��Ǵ�������ħͷ����ҡ���������һλ�������ھ�һʱ������
һ�����������Ķ��ǵĹ��£�ÿһ�����¶�������Զ��Ӱ����һ����
����������ҡ�
    ��Ȼ���Ƕ�����������������������ķ��꣬���������Ҳ��
���ڽ��������ˡ����Ƕ��Ѿ��˳������������ǵ���Ӱħ�ٺܳ�ʱ��
�Ժ�����һ����˵��
LONG );

set("no_fight", "1");      	
	set("no_steal", "1");
	set("no_beg", "1");
	set("no_sleep_room", "1");
	set("no_clean_up", 0);

	set("exits", ([
"down" : __DIR__"shijian",	
	]));
	set("objects", ([
"/d/npc/bai" : 1,               	
"/quest/fyue" : 1,                       	
	]));
	setup();
	replace_program(ROOM); 
}
