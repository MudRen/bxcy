// Room: /d/songshan/luyanpubu.c
// Date: CSWORD 96/03/25

inherit ROOM;

void create()
{
	set("short", "«���ٲ�");
	set("long", @LONG
����ˮ�����ף��ͱ�����������ֱ��������˫�ٲ�й������
��������Ծ���ݣ�ˮ��ӳ�գ�����������
    �ٲ�һ����һСС«���£��ٲ�б������ʤ�۷塣�ٲ�֮��
��·���ϡ�
LONG );
	set("exits", ([
		"southwest" : __DIR__"shandao1",
		"up"        : __DIR__"tieliang",
	]));
	set("no_clean_up", 0);
	set("outdoors", "songshan");
	setup();
}
 
int valid_leave(object me, string dir)
{
if ((int)me->query_skill("dodge",1) <= 200 && dir=="up") 
    {
    	if (me->query("qi")>=30){
      me->improve_skill("dodge",(int)me->query_skill("dodge",1)/2);
      me->add("qi",-15);
      me->add("jing",-10);     
 
}
}

    return ::valid_leave(me, dir);
}

