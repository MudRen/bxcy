
inherit ROOM;

void create()
{
        set("short", "��ʩˮ��");
        set("long",@LONG
����������ܣ����ϰ�������Ĺžɵ��鼮�����Ͼ����б�ǩ(sign)��
���������ɽׯ����������Ѫ����ɱ���ռ����۶��ɵ���ѧ���⡣
LONG );
        set("exits", ([
            "north": __DIR__"jiashan",
        ]));
        
        set("item_desc",([
            "sign" :
            "����Ѫ��������󲿷��ܼ���������ˡ�\n"
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

