// Room: /d/emei/shandong2.c ɽ��2
// create by host dec,20 1997

inherit ROOM;

void init();

void create()
{
        set("short", "ɽ��");
	set("long", @LONG
������һ�����ɽ��������У���ʱ�е�ͷ��һ���ʹ��ֻ���ö�
��ʮ����խ�͵Ͱ������Ŷ����ұڻ���ǰ�У���ǽ����ɢ���������䳱ʪ
��Ϣ��ʹ�㲻�������Ĵ��˺��䣬������˵���������ܡ�
LONG
	);
        set("exits", ([
           "east":  __DIR__"shandong10",
           "west":  __DIR__"shandong"+(random(6)+5),
           "south": __DIR__"shandong"+(random(6)+5),
           "north": __DIR__"shandong"+(random(6)+5), 
	]));
	setup();
}