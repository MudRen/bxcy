//Room /d/honghua/zuolang.c
inherit ROOM;

void create()
{
	set("short", "����");
	set("long",@LONG
������һ�������������ϣ�����û��һ���ˣ���ĽŲ�
�����ú�Զ�����Գ�����Ĳк���ͣ�˼�ֻ�����ҽе�����
��������紵������������.
LONG
	);
	
	set("outdoors", "honghua");	

        set("objects", ([
                "/d/honghua/guanjia" : 1,
        ]));

	set("exits", ([
		"westup" : __DIR__"zoulang2",
		"down"   : __DIR__"damen",
	]));

	set("coor/x",-140);
	set("coor/y",100);
	set("coor/z",10);
	set("coor/x",-140);
	set("coor/y",100);
	set("coor/z",10);
	set("coor/x",-140);
	set("coor/y",100);
	set("coor/z",10);
	setup();

}
