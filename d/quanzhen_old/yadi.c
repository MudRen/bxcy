// yadi.c �µ�

#include <room.h>
void init();
int do_dive();
inherit ROOM;

void create()
{
	set("short", "ɽ�µ�");
	set("long", @LONG
��ǰͻȻһ�����㿴���Լ�վ��ɽ�µף�ֻ���µ׵����ܶ�����ɽ����Χ����
·��Ѱ����Ҫ˵�ˣ���������Ҳ�ɲ���ȥ��������һ��ֻ����һ��ͨ����ɽ����
������һ��С����dive������ˮ�ںڵģ�����ף�����һ�ֲ���ĸо���
LONG
	);
        set("outdoors", "quanzhen");

         set("objects", ([
                  "/u/brave/obj/qilin":1,
                          ]) );
	set("exits", ([
		"east" : __DIR__"yuxudong",
	]));
	setup();
}

void init()
{
        add_action("do_dive","dive");
}

int do_dive()
{
        object me = this_player();
        message_vision("$N����Ծ�𣬿���һ�����﷭����ͷ�½��ϣ��˵�һ��Ǳ����в�����.\n", me);
        me->move("/d/quanzhen/hudi1");
        return 1;
}
