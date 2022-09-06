// Room: shiwangdian.c

inherit ROOM;

void create()
{
        set("short", "义气堂");
        set("long", @LONG
这是为纪念当年教主外父率天鹰教教众重归明教的壮举而特设的
大堂，以示明教上下尽释前嫌、同心协力重振明教神威的决心。堂中
备有香炉烛台，许多教众在此效仿刘关张，结为异姓兄弟。

LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"zoulang2",
  "south" : __DIR__"guangchang1",
  "north" : __DIR__"juyiting",
  "east" : __DIR__"zoulang1",
]));
        set("no_clean_up", 0);

set("objects",([ __DIR__"npc/fuwang":1,
        __DIR__"npc/yingwang":1,
]));
        setup();
        replace_program(ROOM);
}

