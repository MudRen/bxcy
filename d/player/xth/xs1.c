// qjc 2000/5/3 

inherit ROOM;

void create()
{
	set("short", "���־ȼô�");
	set("long", "������Х���������˵ĵط���ƽʱ������ֵܶ���Ӹ�
���ռ������������챦������������һЩ��Ҫ���ֵ��ǣ���
 Ҳ���԰����ò����Ķ��������⡣�������ϱ�ȥ���������ô�
���ˡ�\n");

	set("exits", ([
                "east" : __DIR__"xs3",
                "south" : __DIR__"yt",
	]));
	setup();
	replace_program(ROOM);
}

