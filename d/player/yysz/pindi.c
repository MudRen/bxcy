
inherit ROOM;

void create()
{
        set("short", "����ͥ");
        set("long",@LONG
ֻ��ǽ�Ϲ�������֮������������Ϸ���һ����ף���������ɽׯ
���������������ˡ��������͵����齭���ߣ�����������ɽׯ�Ӵ���
�͵ı����������ˡ�
LONG );
        set("exits", ([
            "east"  : __DIR__"longfeng",
            "west"  : __DIR__"bozhou",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

