
inherit ROOM;

void create()
{
        set("short", "Ū��");
        set("long",@LONG
��֪��ʲô�ܹ��ɽ����������Ū�ã��������ۣ��������������
ν�ɶ��칤�������Ͼ��Ǻ�Ժ�ˣ�������һ�������á�
LONG );
        set("exits", ([
            "south" : __DIR__"lixiang",
            "north" : __DIR__"cuixia",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

