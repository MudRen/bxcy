// Room: /city/kedian.c
// YZC 1995/12/04 
inherit ROOM;
void create()
{
set("short", CYN"���ݿ�ջ"NOR);	
        set("long", @LONG
�������ݳǱ���һ�Ҽ�Ǯ�����Ŀ�ջ������ǳ���¡������οͶ�
ѡ��������ţ��������������������صķ������顣��С����������
æ������ת���Ӵ�����ǻ�����Ŀ��ˡ������Ｘλ����������Ĵ�
��Χ��һ�����Ӳ�֪��������ʲô,�͵�����˴Ӳ�¶�棬��������˭��
�и��ָ����Ĳ²⡣ǽ�Ϲ���һ������(paizi)��
LONG
        );
          set("no_fight", 1);
        set("valid_startroom", 1);
        set("no_sleep_room",1);
        set("item_desc", ([
                "paizi" : "¥���ŷ���ÿҹһ��������\n",
        ]));
        set("objects", ([
                __DIR__"npc/xiaoer" : 1,
"d/city/npc/scavenger":3,
        ]));
        set("no_clean_up",1);
        set("exits", ([
                "west" : __DIR__"beidajie1",
                "up" : __DIR__"kedian2",
        ]));
        setup();
        "/d/board/kedian_b"->foo();
}
int valid_leave(object me, string dir)
{
          if (!userp(me))         return ::valid_leave(me, dir);
        if (present("xiao er",environment(me))){
        if ( !me->query_temp("rent_paid") && dir == "up" )
        return notify_fail("��С��һ�µ���¥��ǰ��"+HIW"����"NOR+"һ���������ţ����ס����\n");
        if ( me->query_temp("rent_paid") && dir == "west" )
        return notify_fail("��С���ܵ��ű���ס���͹��Ѿ��������ӣ����᲻ס��������أ�
���˻���ΪС���ź����أ�\n");
        }
        return 1;
}
