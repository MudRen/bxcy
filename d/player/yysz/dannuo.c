
inherit ROOM;
void create()
{
        set("short", "啖人厅");
        set("long",@LONG
这是一间雅致的大厅，厅上摆着几张紫檀木大桌。桌上银制餐具一
应俱全，桌边一溜犁花木椅。每日御云山庄很多人都在此用餐。看
血狼正在那力大啖人肉呢，还是快走吧。
LONG );
        set("exits", ([
            "west" : __DIR__"yimen",
            "east" : __DIR__"huayuan",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

