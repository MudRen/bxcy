inherit ROOM;
void create()
{
    set("short", "������");
    set("long", @LONG
����һƬ�����֡���ʮ�ɸߵĴ���������һ�飬��ʵ��֦Ҷ
��һ�����ɡ��������գ��������ڵ�˿��Ҳ�ޡ��߰Ѻ������
���ڵ��ϣ�һ�Ų���ȥ������β�������
LONG
    );
    set("exits", ([
        "east" : __DIR__"fzws",
//        "west" : __DIR__"shulin2",
     ]));
    set("outdoors", "xth");
    set("objects",([
    ]));
    setup();
}
