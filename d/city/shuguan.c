
//modify by isle

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
��������ݵĴ���������������һ����Ⱦ��һλׯ���������������̫ʦ
���Ͻ�ѧ�����������������˳����ѧ����һ�Ź��ⰻȻ���鰸��������
��ǰ�棬���ϰ��ż��������˵���װ�鼮��
LONG );
	
        set("no_fight", 1);
        set("no_sleep_room", 1);

	set("exits", ([ /* sizeof() == 1 */
	    "west" : __DIR__"beimen",
	]));

	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/xiansheng" : 1,
	]));

	setup();
	replace_program(ROOM);
}
