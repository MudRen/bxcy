// Room: /u/cass/hg/taihemen.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "̫���Ź㳡");
	set("long", @LONG
ӳ����������һ�����Ĺ㳡���㳡�����������׳��������¶̨��
̨�ϰ�����ͭ¯���ź�����ͭ�Ƶ��ɺס���ͷ�꣬�Լ��Ŵ��ļ�ʱ����
�С�����������վ���������Կ�����Զ�����������������ú�
�������ɵ�����ƽ̨֮�ϣ�ÿ�㶼Χ�к�����ʯ���ˡ�
LONG
);
	set("no_new_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"jinshuiqiao",
  "north" : __DIR__"taihedian",
  "northwest" : __DIR__"wuyingdian",
]));

	setup();
	replace_program(ROOM);
}
