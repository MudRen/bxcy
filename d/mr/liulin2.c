#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short","������");
         set("long",@long
����һƬ���̵������֣�һƬ���̵���ɫ����������ȥ֦Ҷïʢ�����ϼ�
ֻС�����������Ľи���ͣ����������΢������ڶ���
long);
         set("exits",([
             "west" : __DIR__"liulin1",
             "south" : __DIR__"xiaojing7",
]));
         set("objects",([
             "/d/heimuya/npc/tong-ren":2,
]));
         setup();
         replace_program(ROOM);
}
