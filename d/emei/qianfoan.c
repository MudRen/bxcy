// Room: /d/emei/qianfoan.c ������ ǧ����

inherit ROOM;

void create()
{
	set("short", "ǧ����");
	set("long", @LONG
�����Ƕ��ҵ�ǧ���֡���һ��������ΰ�����ã���ǰ����������Ĺ�
�촻������ľï�ܣ�������ա��������й����ͭ���ķ�����Ϊ����
עĿ�����ݶ�����һյ�����������ͭ����񣬷������������ٵ�ǧ����
�ơ�����������������˳�;����ǰ���β��������ʮ�ֵ���ʢ��
LONG
	);

	set("exits", ([
		"west" : __DIR__"shangu",
	]));

	set("objects",([
                 CLASS_D("emei") + "/jingzhao": 1,
	]));

	setup();
}