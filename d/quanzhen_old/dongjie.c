// dongjie.c ����
// By Lgg,1998.10

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�����Ǿ��ݸ��Ķ��֣������߾��Ǿ��ݶ����ˡ����ݸ��Ǹ�С
���򣬲��㷱�������ϵ�����Ҳ��ϡ�١�������һ����լԺ�����
�����ϲ���ͭ���������������ߣ����Ǿ��ݸ��������ˡ�
LONG
        );
        set("outdoors", "quanzhen");
        set("exits", ([
                "east" : __DIR__"dongmen",
                "west" : __DIR__"zhongxin",
                "south" : __DIR__"fu-damen",
        ]));
        set("objects", ([
                __DIR__"npc/seller" : 1,
        ]));
        setup();
        replace_program(ROOM);
}
