//for birthday
#include <room.h>
#include <ansi.h>

string look_cake();
inherit ROOM;
void create()
{
 set("short","���������谲�ļ�");
set("long", @LONG
�����谲�����Ǿ�, ������ 20��ʱ��̶�ĳ�����Ⱥ��Ⱥ��Ϊ���ǵ�
����֮�ϰ���һ�Ű�����, �谲��������Ц���еõ��Ŵ�Ұ���.
��������һ��޴�ĵ���(cake). ����Ϯ��, ��, �谲�Ŀ�ˮ����
������.
LONG );
set("exits",([
             "west"     :  __DIR__"home",
           "south" : "/u/xinyue/sunrise_room",
         ]) );
set("item_desc",(["cake" : (: look_cake :), 
                 ]));

setup();
}

string look_cake()
{
string cake;
       cake = read_file(__DIR__"cake.txt",1,39);
return cake;
}
