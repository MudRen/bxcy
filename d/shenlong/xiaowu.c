#include <ansi.h>
inherit ROOM;
string* books = ({
    "/d/shaolin/obj/book-bamboo",
    "/d/shaolin/obj/book-paper",
    "/d/shaolin/obj/book-silk",
    "/d/shaolin/obj/book-stone",
    "/d/shaolin/obj/book-iron",
    "/d/wudang/obj/quanpu",
        "/d/xingxiu/obj/dujing_1",
//        "/d/shenlong/obj/zhangfa",
//        "/d/shenlong/obj/shoufa",
//        "/d/shenlong/obj/bufa",
});
void create()
{
    set("short", "С��");
    set("long", @LONG
һ��С��,ֻ��ǽ�Ϲ���������������ֻ�.�����Ҳ������
ƽʱ�ѵ�һ���ĸ��ָ������鼮.һ����òӢ���������ʿ����
��һ���ֻ�����̾��.
LONG
    );
    set("exits", ([
        "south" : __DIR__"kongdi",
    ]));
    set("objects", ([
        "/d/shenlong/npc/lu": 1,
        books[random(sizeof(books))] : 1,
        books[random(sizeof(books))] : 1,
    ]));
    set("outdoors", "shenlong");
    setup();
   replace_program(ROOM); 
}
