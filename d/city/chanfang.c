// Room: chanfang.c

inherit ROOM;

void create()
{
        set("short", "����������");
        set("long", @LONG
����һ��ר��Ϊ�и�׼���Ĳ���,�������Ҫ��Baby�͸Ͽ���Ӵ��
LONG
        );
        set("no_fight",1);
        set("no_sleep_room",1);
        set("no_steal",1);
        set("no_beg",1);
        set("no_study",1);
        set("no_yun",1);

        set("exits", ([
                "down" : "/d/city/yaopu",
        ]));

        setup();
        replace_program(ROOM);
}

