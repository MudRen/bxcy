
inherit ROOM;

void create()
{
        set("short", "木桩");
        set("long",@LONG
烟波浩淼的江面上，水天一色，多么美丽的地方，在这儿练功怎能
不事半功倍呢。
LONG );
        set("outdoors", "yysz");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

