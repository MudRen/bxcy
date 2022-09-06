
inherit ROOM;

void create()
{
        set("short", "普渡桥");
        set("long",@LONG
绿油油的水面上，一条曲曲折折的小桥通向水中的一片小洲，
洲上花红柳绿，似乎别有洞天。
LONG );
        set("outdoors", "yusz");
        set("exits", ([
            "west" : __DIR__"huayuan",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

