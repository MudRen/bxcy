// qingcaop.c
// by shilling 97.2
inherit ROOM;
void create()
{
        set("short", "���ƺ");
        set("long", @LONG
�����������е�һƬ�Ƚϴ�Ŀյأ���Ի�����ƺ����Ϊ��������֮��
��������ƽʱ���������������ǲ�֪��Ϊʲô������ȴ�������˼����֡���
������һ�����ˡ�
LONG
        );
       set("exits", ([
               "north" : __DIR__"xiaodao3",
               "south" : __DIR__"xiaodao5",
               "east" : __DIR__"xiaodao4",
               "west" : __DIR__"xiaodao1",
       ]));
    set("outdoors", "xiaoyao");
    set("objects", ([
        __DIR__"npc/suxingh": 1,
]));
    set("no_clean_up", 0);
    setup();
    set("valid_startroom", 1);
        "/d/board/xiaoyao_b"->foo();
}
