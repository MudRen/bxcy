
inherit ROOM;

void create()
{
        set("short", "������");
        set("long",@LONG
����һ�����üܳɵ����ӣ�������ͨ��ˮ�档�������Ա���֦��
һֻ�˸� "��ֻС�����ˮ��������������������" �Ľ�����
������������һ����
LONG );
        set("outdoors", "yysz");
        set("exits", ([
            "eastup" : __DIR__"qinyun",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

