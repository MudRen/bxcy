
inherit ROOM;

void create()
{
        set("short", "���Ƹ�");
        set("long",@LONG
�����ǹ�����ɽׯ������С�ĵط���������ˮ��΢�����������
���ƵĻ��㣬�����ķΡ�һ��ī��ɫ������ͨ��¥�ϵ���Ϣ�ҡ�
LONG );
        set("exits", ([
            "east"  : __DIR__"yimen",
"up"    : __DIR__"qinfeng2",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

