// enterance.c

inherit ROOM;

void create()
{
	set("short", "ɱ��¥����");
	set("long", @LONG
�ߵ�����㷢�������Ȼ���ж��졣ǰ����һ�����ž�լ��
��ǰһ�Խ����ʦ���������ͣ�����ɱ֮�ơ��������ұ����絶��ɱ��
��Ȼ�������������֡�ɱ��¥����һ�����Ż���Ҳ�Ǵ���ɽ��ģ����
�������������������צ����������һ����
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
		"south" : __DIR__"",
		"north" : __DIR__"xiaolu",
	]));
	set("no_clean_up", 0);
	set("outdoors", "shashou" );

	setup();
	replace_program(ROOM);
}
