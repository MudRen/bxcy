
inherit ROOM;

void create()
{
        set("short", "СԺ");
        set("long",@LONG
�����ʯ�ѵ�����ʯ�β����Щͷ��Ŀѣ����ô��ɽ���㲻֪������
һ��������ɽ�����谵���ۣ�ʵ�ڲ�֪ͨ��ʲô�ط���Ժ�����л���һ
����Ȫ����"ͻ.ͻ.."����ˮ�ء�
LONG );
        set("outdoors", "yysz");
        set("exits", ([
            "west" : __DIR__"zuijing",
            "east" : __DIR__"shuiyun",
            "north": __DIR__"huayuan",
//          "south": __DIR__"huanshi",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

