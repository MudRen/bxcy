// Room: /d/gaochang/room49.c
// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
        set("short", "丛林");
        set("long", @LONG
越走树林越密，树缝中洒下来的阳光也变得斑斑点点。茅草渐厚，灌木丛生，
路径漫灭。吹来的风也越发的阴冷潮湿。远方密林的天空上有几只盘旋的秃鹰，发
出撕心裂肺的叫声，令人毛骨悚然。
LONG
);
        set("outdoors", "room49");
        set("objects", ([ 
        __DIR__"npc/ying" : 4,
]));
        set("exits", ([ 
  "westup" : __DIR__"room50",
  "east" : __DIR__"room48",
]));

        setup();
}
void init()
{
    if ( userp( this_player() ) )
    call_out("kill_user",1,this_player());
}
int kill_user(object me)
{
   object ob;
   if (!me || environment(me)!=this_object()) return 1;
    if (!present("tu ying",this_object())){
    ob=new( __DIR__"npc/tuying");
    ob->move(this_object());
    message("vision","一个黑影突然从天而降。\n",this_object());
    }
}
