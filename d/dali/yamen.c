// Room: /d/dali/yamen.c
// Data: ����˹(hades)
// Time: ��Ԫ��1999��4��21�գ�����ʱ�䣺17ʱ28��57�롣

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���������Ŵ��ţ�������ľ���Ž����ر��š����ྲ�����رܡ������ӷַ���
ͷʯʨ�ӵ��Աߡ�ǰ����һ����ģ���Ȼ�ǹ�С����ԩ�õġ�������������ǰѲ�ߡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"yamen2",
  "east" : __DIR__"xbdajie1",
]));

                 set("objects", ([
    __DIR__"npc/yayi" : 4,
        ]));

         
	setup();
}

int valid_leave(object me, string dir)
{
	if (!wizardp(me) && objectp(present("ya yi", environment(me))) && dir == "west")
		return notify_fail("���ۺȵ������������䡭������\n");
	return ::valid_leave(me, dir);
}
