
inherit ROOM;

void create()
{
        set("short","Ʈ����");
        set("long",@LONG
����һ�����µķ��䣬���ü򵥶����š�����ü���Ư������Ů
���ͼ�����ͯ׷��׷ȥ�Ĵ��֡�
LONG );
        set("exits",([
            "north" : __DIR__"qinyun",
        ]));
//        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}


