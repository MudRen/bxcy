
inherit ROOM;

void create()
{
        set("short", "骷髅梯");
        set("long",@LONG
这是一座骷髅架成的梯子，垂下来通往水面。忽听得旁边柳枝上
一只八哥 "有只小鸟跌落水，起不来。。起不来。。。" 的叫了起
来，把你吓了一跳。
LONG );
        set("outdoors", "yysz");
        set("exits", ([
            "eastup" : __DIR__"qinyun",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

