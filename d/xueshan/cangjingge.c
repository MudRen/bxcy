//
// cangjingge.c ѩɽ�ؾ���
// by secret
inherit ROOM;
string* books = ({
        "/d/xueshan/obj/skin",
        "/d/xueshan/obj/jing",
    "/d/shaolin/obj/book-bamboo",
        "/d/shaolin/obj/book-silk",
    "/d/shaolin/obj/book-stone",
    "/d/shaolin/obj/book-iron",
});
void create()
{
        set("short", "ѩɽ�ؾ���");
    set("long", @LONG
������ѩɽ�µĲؾ��ң���ǽ��һ����ܣ������˸���ȭ�ס��鼮��
����ǵ����������Ħ�Ƿ���ķ𾭺ʹ�������ȡ������ѧ�伮��
LONG
    );
    set("exits", ([
                "southeast" : __DIR__"dating",
    ]));
    set("objects", ([
        books[random(sizeof(books))] : 1,
        books[random(sizeof(books))] : 1,
        books[random(sizeof(books))] : 1,
                CLASS_D("xueshan")+"/daerba" : 1,
    ]));
    setup();
    replace_program(ROOM);
}
