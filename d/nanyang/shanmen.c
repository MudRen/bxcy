// Date: YZC 96/01/19
#include <room.h>
inherit ROOM;
void create()
{
    set("short", "������");
    set("long", @LONG
һ���޴���Ʒ��������Ƭɽ��֮�䣬�Ʒ����Ϸ���������
������֣��������¡����ּ���Щ���䣬����ȥ�����Զ����λ
��ʮ�����ɮ���ֳֽ䵶����ɽ�����ࡣ�������һ��ʯ����
LONG
    );
    set("exits", ([
        "eastup" : "/d/shaolin/shijie8",
        "west" : __DIR__"shijie7",
    ]));
    set("outdoors", "shaolin");
    set("objects",([
        CLASS_D("shaolin") + "/xu-tong" : 1,
        CLASS_D("shaolin") + "/xu-ming" : 1,
    ]));
    setup();
//    replace_program(ROOM);
}
int valid_leave(object me, string dir)
{
    object *inv;
    object ob;
    mapping myfam;
    int i;
    if (me->query("gender") == "Ů��" && dir == "eastup" ) {
        ob=present("xu tong", environment(me));
      if (ob && living(ob) )
            return notify_fail("��ͨ������ס�����һ��˵����ǧ����������������"
                "Ů�����롣" + RANK_D->query_respect(me) +"\n����ɽȥ�ɣ����"
                "����ûȤ��\n");
        else{  ob=present("xu ming", environment(me));
            if (ob)
            if (living(ob))
            return notify_fail("����������������ǰ��˫�ֺ�ʲ˵���������ӷ�"
                "��λ" + RANK_D->query_respect(me) + "��������\nˡС�²��Ӵ�Ů"
                "�͡�Ůʩ������һ����𣬺η�ȥ��üɽ��ϲ��\n");
       }
    }
    myfam = (mapping)me->query("family");
    if ((!myfam || myfam["family_name"] != "������" ) && dir == "eastup") {
        inv = all_inventory(me);
        for(i=sizeof(inv)-1; i>=0; i--)
            if(inv[i]->query("weapon_prop") && (inv[i]->query("equipped")))
                { ob=present("xu tong", environment(me));
      if (ob && living(ob) )
                    return notify_fail("��ͨ��ס��˵������λ" +
                        RANK_D->query_respect(me) + "����±��С�����ǧ���"
                        "��أ����\n���óֱ�����ɽ��\n");
                else { ob=present("xu ming", environment(me));
                     if (ob)
                     if (living(ob))
                    return notify_fail("����������������ǰ��˫�ֺ�ʲ˵������"
                        "���ӷ���λ" + RANK_D->query_respect(me) + "������"
                        "\n���С������徲֮�أ����������赶Ū��������ʩ����"
                        "�¡�\n");
              }
           }
    }
    return 1;
}
