// Room: /u/mei/room20.c
// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
    set("short", "С��");
    set("long", @LONG
��·��֪���ж������������ߣ���Щ�ط����ݱ��˻��ߣ���Щ�ط���ȫ��
ɳ����������������һ��ļž���ֻ�з紵�����ҵ�ɳɳ֮����ż��һ������
�������ȷ�Ʈ�����ʡ�
LONG
    );
    set("exits", ([ 
  "northwest" : __DIR__"room20",
  "south" : __DIR__"room20",
  "southwest" : __DIR__"room19",
  "north" : __DIR__"room20",
  "northeast" : __DIR__"room71",
  "east" : __DIR__"room20",
  "southeast" : __DIR__"room21",
  "west" : __DIR__"room20",
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
    message("vision","������ӰͻȻ����������\n",this_object());
    }
}
int valid_leave(object me, string dir)
{
    object ob;
    ob=present("wolf", environment(me));
    if ( ob && living(ob))
       return notify_fail("��Ⱥ��ס�����ȥ·��\n");
    else
        return 1;
}