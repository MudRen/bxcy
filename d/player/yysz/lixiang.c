
inherit ROOM;

void create()
{
        set("short", "�ϻ�Ժ");
        set("long",@LONG
����ɽׯ�ĺ�ԺҲ���ڲ�ͬ��Բ��Ժ���Ͽ��жϻ�Ժ���֣�Ժ��ѩ��
���滨������֦ͷ��������ǽӴ�������������ˣ�������һ��������
���ȡ���������ֻ���������˶��ѡ�
LONG );
        set("outdoors", "yysz");
        set("exits", ([
            "north" : __DIR__"chuantang",
            "west"  : __DIR__"longfeng",
            "east"  : __DIR__"changlang"
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

