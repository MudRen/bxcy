// qjc 2000/5/3 

inherit ROOM;

void create()
{
	set("short", "�����ֵ�");
	set("long", "�����Х��������ÿ���ĵط������������һ�ŵ���
����������̴ľ�Ρ�����������������������������������¡�
����Ψһ�ĳ���ͨ�������ô�����\n");

	set("exits", ([
                "west" : __DIR__"dt1",
	]));
	setup();
	replace_program(ROOM);
}

