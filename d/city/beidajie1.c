// Room: /city/beidajie1.c
// YZC 1995/12/04 
inherit ROOM;
void create()
{
	set("short", "�����");
	set("long", @LONG
	������һ����æ�Ľֵ��ϣ����Ų�����ǻ������������ɫ�Ҵң������
�����ϱ���ȥ��������һ�����ֵĹ㳡��������һ��������¡�Ŀ�ջ�����Ը���
�����ǽ�����������˵Ҳ�������ǵ��Ļ�ص㡣������һ��Ǯׯ��������������
�����Ľ���������
LONG
	);
        set("outdoors", "city");
	set("objects", ([
		CLASS_D("btshan") + "/ouyangke" : 1,
// "/u/snow/milestone" : 1,	
	]));
	set("exits", ([
		"east" : __DIR__"kedian",
		"south" : __DIR__"guangchang",
		"west" : __DIR__"qianzhuang",
		"north" : __DIR__"beidajie2",
	]));
 set("post_limit",1);
//	set("objects", ([
//		CLASS_D("mingjiao") + "/zhangwuji" : 1,
//	]));
"/d/board/yijian_b"->foo();
	setup();
	replace_program(ROOM);
}
