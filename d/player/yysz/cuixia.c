inherit ROOM;

void create()
{
        set("short","��ϼ��");
        set("long",@LONG
����ׯ�ϣ����ȷǷ�����һ���žͲ��ɵľ�̾���ô�һ������! ��
�߷·���һ��С������������һƬ���֣�������һ��Ū�ã���֪ͨ��ʲ
ô�ط���
LONG );
        set("exits",([
//        "west" : __DIR__"xiaoting",     	
//   "east" : __DIR__"zhulin1",
            "south": __DIR__"chuantang",
        ]));
        setup();
}

