// Room: /u/cass/hg/shenwumen.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�ɼ�¥����¥��������ɡ���¥�����ط��ܣ��Ĳ�������ײ�ƽ̨Χ��
������ʯ���������߶��������ף���̬���档��¥�����ط��ܣ�����¥��
�������������Խ�����ƣ��Ե�Ρ����ΰ���ڲ��õ������¸��ӽ�̻Ի͡�
LONG
);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"qinandian",
  "north" : "/d/city2/hbridge",
]));

        set("objects", ([
                "/d/huanggon/npc/shiwei" : 1,
                "/d/city/npc/wujiang" : 1,
                "/d/city/npc/bing" : 2,
        ]));

	setup();
}
int valid_leave(object me, string dir)
{
    int i;
    object *inv,ob1,ob2;
    ob1=present("wu jiang", environment(me));
    ob2=present("guan bing", environment(me));
    if(dir=="south") {
     if( me->query("huanggong/canenter") ) {
        inv = all_inventory(me);
        for(i=sizeof(inv)-1; i>=0; i--)
            if(inv[i]->query("weapon_prop")&& (inv[i]->query("equipped")))
                if( objectp(ob1) && living(ob1) )
                    return notify_fail("�佫��ǰ��ס�㣬����˵������λ" +
                        RANK_D->query_respect(me) + "����±��С�\n"
                        "���óֱ����빬��\n");
                else if(objectp(ob2) && living(ob2) )
                    return notify_fail("�ٱ���ǰ��ס�㣬����˵������λ" +
                        RANK_D->query_respect(me) + "����±��С�\n"
                        "���óֱ����빬��\n");
        return 1;
        }else{
        if (me->query("gender") == "Ů��") {
           if( objectp(ob1) && living(ob1) )
            return notify_fail("�佫��ǰ��ס��,����˵�����ʹ��صأ���" 
            "��Ѱ���̻�Ů�����ɳ���,\n" + RANK_D->query_respect(me) +"��أ����"
                "��ȡ���衣\n");
        else  if( objectp(ob2) && living(ob2) )
            return notify_fail("�ٱ���ǰ��ס�㣬����˵�����ʹ��صأ���" 
            "��Ѱ���̻�Ů�����ɳ���,\n" + RANK_D->query_respect(me) +"��أ����"
            "��ȡ���衣\n");
        }
        if (me->query("gender") == "����") {
           if( objectp(ob1) && living(ob1) )
            say("�佫Ц������˵������λ�����������ˣ�������ɡ�\n");
        else   if( objectp(ob2) && living(ob2) )
            say("�ٱ�Ц������˵������λ�����������ˣ�������ɡ�\n");
        }
        if (me->query("gender") == "����") {
           if( objectp(ob1) && living(ob1) )
            return notify_fail("�佫������ס������˵�����ʹ��صأ���" 
            "��Ѱ�����Ұ�����ɳ���.\n" + RANK_D->query_respect(me) +"��أ����"
                "��ȡ���衣\n");
        else   if( objectp(ob2) && living(ob2) )
            return notify_fail("�ٱ�������ס������˵�����ʹ��صأ���" 
            "��Ѱ�����Ұ�����ɳ���\n" + RANK_D->query_respect(me) +"��أ����"
            "��ȡ���衣\n");
        }
        }
    }       
    return 1;
}

