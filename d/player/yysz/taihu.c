#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "千折湖");
        set("long",@LONG
这是一个支流众多的小河，四面都是霸王花。除了桨声和花叶与船身
相擦的沙沙轻声，四下一片寂静，湖上清风，夹着淡淡的幽香，你不禁
心想:  "就算这样一辈子，也好哇！"
LONG );
        set("outdoors", "yysz");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

