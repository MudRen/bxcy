//room: lgting.c
inherit ROOM;
void create()
{
  set("short","��������");
  set("long",@LONG
�����ǽ��������Ǿ����ۼ��д�ĵط�������򵥡����������ǰ�����ֶ���������ĥ������
LONG
     );
  set("no_sleep_room",1);
set("no_fight", 1);
set("exits",([
      "east" : __DIR__"dongdajie1",
      "west" : __DIR__"xidajie1",
      "north" : __DIR__"beidajie1",
      "south" : __DIR__"nandajie1",
     ]));
set("objects", ([ /* sizeof() == 1 */
__DIR__"npc/wenqianer" : 1,      	
]));


 setup();
 replace_program(ROOM);
}
