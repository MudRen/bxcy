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
             "south" : __DIR__"xiaojing5",
             "east" : __DIR__"liulin1",
]));     
         set("objects",([
             __DIR__"npc/obj/liutiao" : 2,
             "/d/heimuya/npc/tong-ren":2,
]));
         setup();
         replace_program(ROOM);
}
