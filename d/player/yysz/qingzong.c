
inherit ROOM;
void create()
{
        set("short", "Ӣ��ڣ");
        set("long",@LONG
�������������ư��ƣ���Ȼ��Ȼ���ʣ�ԭ����������ɽׯ��Ĺ�أ�
��˵����ɽׯ�Ĵ�ʼ���˾����ڴ��ˡ����ϳ�����ϸ��С�ݣ���˵��
�ֲݳ�����̣�������ή���������Ϊ����Ӣ�鲻Ϣ��Ե�ʰɡ��ƺ�
����������һƬ��������޳��ڡ�
LONG );
        set("outdoors", "yysz");
        set("exits", ([
                "south" : __DIR__"zhulin3",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

