// qjc 2000/5/3 

inherit ROOM;

void create()
{
	set("short", "����֧Ԯ��");
	set("long", "����������ĵ�����Ҫ��æ��ʱ�����õط��������ﲢ
û��ʲô����ֻ��ǽ�Ϲ��˼����ֻ����������ȥ�����͵���
  �����ô����ˡ�\n");

	set("exits", ([
                "east" : __DIR__"xs4",
                "north" : __DIR__"yt",
	]));
	setup();
	replace_program(ROOM);
}

