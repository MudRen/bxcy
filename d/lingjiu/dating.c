//ROOM dating.c
inherit ROOM;
void create()
{
    set("short", "������");
        set("long",@LONG
����ǡ����չ���������������ȫ���Ծ�ʯ���ɣ�ʯ��֮�侹�ް��
��϶�����˳��档���ڴ������ĸ�ʯ������Ϊ��Ӳ�Ļ���ʯ���ơ�
LONG
    );
        set("exits", ([
        "north" : __DIR__"changl15",
        "south" : __DIR__"damen",
        ]));
    set("objects",([
        CLASS_D("lingjiu")+"/xuzhu" : 1,
    ]));
    set("valid_startroom", 1);
    setup();
        "/d/board/lingjiu_b"->foo();  }