// create by snowcat jan 21 1998


inherit ROOM;

void create ()
{
  set ("short", "��ٵ�");
  set ("long", @LONG

һ��������ֱ�Ĵ�ٵ��Գ����Զ����Ӷ�ȥ������ݵ���ʮ��
���ۡ�����ͨ����ƹ��������ǣ�����ͨ��Զ����

LONG);

  set("exits", ([
        "east" : __DIR__"east2",
"south" : "/d/wanjiegu/road4",   	
      ]));
  set("outdoors", __DIR__);

  setup();
}


