// Room: /new/guangchang.c


inherit ROOM;

void create ()
{
  set ("short", "����㳡");
  set ("long", @LONG
�������������������ģ�һ���ܿ����Ĺ㳡�����ź�ש�ĵ���,����������һ��
������ĸо�,�ϱ�������������������ʱ���Կ������Ը��ص����֡�
LONG);

   set("outdoors", "city");
  
  set("exits", ([ 
  
  "north" : __DIR__"nroom1",
  "east" : __DIR__"eroom1",
  "south" : __DIR__"sroom1",
  "west" : __DIR__"wroom1",

]));


  setup();
}

