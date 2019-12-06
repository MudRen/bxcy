// Room: /u/mei/room26.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
        set("short", "高昌废墟");
        set("long", @LONG
一眼望去，高高矮矮的房子栉比鳞次，可是声息全无，甚至雀鸟啾鸣之
声亦丝毫不闻。如此奇特可怖的景象，寂静的气势使人连大气也不敢喘上一
口。一片寂静之中，远处忽然传来隐隐的狼嗥。
LONG
        );
        set("outdoors", "room26");
        set("exits", ([ 
  "east" : __DIR__"room25",
  "west" : __DIR__"room27",
  "north" : __DIR__"room28",
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
    if (!present("wolf",this_object())){
    ob=new( __DIR__"npc/wolf");
    ob->move(this_object());
    ob=new( __DIR__"npc/wolf");
    ob->move(this_object());
    ob=new( __DIR__"npc/wolf");
    ob->move(this_object());
    ob=new( __DIR__"npc/wolf");
    ob->move(this_object());
    ob=new( __DIR__"npc/wolf");
    ob->move(this_object());
    ob=new( __DIR__"npc/wolf");
    ob->move(this_object());
    message("vision","几条黑影突然向你扑来。\n",this_object());
    }
}
