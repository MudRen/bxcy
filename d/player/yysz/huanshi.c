
inherit ROOM;

void create()
{
        set("short", "还施水阁");
        set("long",@LONG
阁中满是书架，架上摆着许多颇古旧的书籍，架上均贴有标签(sign)。
这就是御云山庄历经无数次血腥屠杀才收集积累而成的武学宝库。
LONG );
        set("exits", ([
            "north": __DIR__"jiashan",
        ]));
        
        set("item_desc",([
            "sign" :
            "由于血狼外出，大部分密籍都备封存了。\n"
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

