
inherit ROOM;

void init();

void create()
{
        set("short", "���о�");
        set("long",@LONG
���ǳ̹��ӵ����ң����г�����ͨ����ʰ����Ϊ���࣬�ݽ�һ��
ï���辰(penjing)���ú�����ʢ�������¹�Ӵ�����������������⣬
���������һ��������
LONG );
        set("exits", ([
            "west": __DIR__"shuwu",
        ]));

        set("item_desc", ([
            "penjing" : "���辰�����������˲��ٵ���Ѫȥ���డ���㲻������̹��ӵľ���\n",
        ]));
        set("no_clean_up", 0);
        setup();
}

