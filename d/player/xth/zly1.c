// qjc 2000/5/3 

inherit ROOM;

void create()
{
	set("short", "Х��¥");
	set("long", "�������Х�������ܵĵط�֮һ����¥��ľ��������
ԼԼ�ģ���֪�������˶��ٵĻ��ء�ƽʱֻ�л᳤�����Ϻ���
�������ſ��Խ�����\n");

	set("exits", ([
                "north" : __DIR__"zly",
                   "up" : __DIR__"jing",

	]));
	setup();
//	replace_program(ROOM);
}
int valid_leave(object me, string dir)
{
        if (dir=="up"){
if ((string)me->query("id")=="wenwu"||(string)me->query("id")=="lisa") return 1;	
  else    return notify_fail("�󵨣���������ȥ�ĵط���!\n");
}
       else return 1;
}

