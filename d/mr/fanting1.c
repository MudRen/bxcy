#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short",HIY"����"NOR);
         set("long",@long
����һ��С����, ��Ȼ����, ���ǹ���ư��, ���ν���, ������ȫ����̨
�϶��������ʹϹ��߲�, �����Ϻ, �������಻��, ��ʮ�ָɾ����롣
long);
         set("objects", ([
             __DIR__"npc/obj/longjing-caiyeji" : 1,
             __DIR__"npc/obj/meihua-zaoya" : 1,
]));
             set("exits",([
             "west" : __DIR__"c15-0",
]));
         setup();
         
}
