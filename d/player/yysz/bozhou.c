
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "����̲");
        set("long",@LONG
һƬ��ɪ�����״����ֳ�һ����ͷ����С��ֻ�����ſ����⻨��Ҷ
��������ˮ����ͨ�˴�ɴ˿ɳ˴��뿪����ɽׯ��������ͣ��һ��С��
(zhou)��
LONG );
        set("outdoors", "yysa");
        set("exits", ([
            "east"  : __DIR__"pindi",
        ]));
        set("item_desc", ([
            "zhou" : "��������ɽׯ�ͽ�����ϵ��С�ۡ�����һ��������Ů�����ϵĿ���ֻҪ��
��(enter)�Ϳ��Գ����ˡ�\n",
        ]));
        set("no_clean_up", 0);
        setup();
}
void init()
{
       add_action("do_enter", "enter");
}
int do_enter(string arg)
{
       object ob ;
       string dir;
       if( !arg || arg !="zhou" ) 
       {
             tell_object(this_player() , "������ɱ����ȥtam,n.out.лл����!\n" ) ;
             return 1 ;
       }
       ob = this_player();
message_vision("����һ�����������������Ů����$N���ۣ������㣬�����밶��
����ɽׯ��������Ұ��Զȥ��\n", ob);
       ob ->move(__DIR__"taihu") ;
       tell_object(ob, HIG "��������Զ���������ǿ������Ľ���������\n" NOR ) ;
       call_out("home", 10 , ob );
       return 1 ;
}
void home( object ob )
{
       tell_object(ob , "С��������������ؿ����ˡ�������С��������Ů���ֵ���\n" ) ;
       ob->move (__DIR__"hupan") ;
}

