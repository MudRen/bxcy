// Room: /u/xdd/gumu/gmanhe2.c
// Modify By csy 98/12
#include <ansi.h>;
inherit ROOM;

void create()
{
     set("short", HIR"����"NOR);
     set("long", @LONG
ԭ��������һ�����°��ӣ��˴�ˮ�����Ǻ�䣬���Ƽ�Ϊ���ˡ������һ
��̤�գ�����ˮ��ֱ���ʺ�����Ǳ����֪���Ժδ�������֪ͨ���η���������
�Ѹо�ˮ�ƽ��������ƽ��ߡ�
LONG 
       );

     set("exits", ([
         "eastdown" :  __DIR__"gmql2",
         "northup" : __DIR__"dongkou",
      ]));

     setup();
}

void init()
{
     object me;
     me = this_player();
     me->receive_damage("qi", 50 );
     me->receive_damage("jing", 50 ); 
     message_vision(HIB"$N������������ʧ������ʮ�����ѡ�\n"NOR, me);
     if ( me->query("qi") < 10 || (int)me->query("jing") < 10) {
     me->set_temp("last_damage_from","�ڰ����б���");
     me->unconcious();
     me->die();   
     return ;     
     }
}

int valid_leave(object me, string dir)
{
       if (dir == "northup") {
          write(HIW"\n����ö�����ǿ����ҫ��һʱ֮�侹Ȼ�������ۡ�\n\n"NOR);
       }
       return 1;
}
