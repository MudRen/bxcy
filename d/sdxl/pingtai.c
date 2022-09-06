// by dubei

#include <ansi.h>
#include <room.h>

inherit ROOM;

string jianzhong(object);

void create()
{
    set("short", BLU "ƽ̨"NOR);
    set("long", @LONG
ֻ�����ʯ�����һ����ء���ر���ɽ�ȣ�������������ʯ�Ͻ�
ڣ(jianzhong)��������֮�ԣ��������������С��ʯ�̣�
    ��ħ������ܼ��޵�����£������˹��
�����غ���Ⱥ�����֣��������������౯��
LONG
    );

    set("item_desc", ([
        "jianzhong" : (: jianzhong :),
    ]));

    set("outdoors", "xiangyang");
        set("no_clean_up", 1);

    setup();
}

string jianzhong(object me)
{
    object where = environment(me);
	if(where->query_temp("temp/ban")<1)
    {
        return  "������һ����������ǰ����߾����书��˵�����������ὣ������֮�ࡣ��\n";
    }

    return "�Ὺڣ��ʯ���¶���������������������ڵ�һ���ڶ����ѽ�֮\n"+
"�䣬����һ�鳤��ʯƬ����������ʯƬ�����һ�����ʯ֮�ϡ�\n"+
"ʯ�Ͽ��֣�\n\n"+
"        �� ��       �� ��       �� ��       �� �� ��\n"+
"        �� ��       �� ޱ       ʮ ��       �� ľ ʮ\n"+
"        ǰ ��       �� ��       �� ��       �� �� ��\n"+
"        �� ��       �� ��       ǰ ��       �� ʯ ��\n"+
"        ֮          ��          ��          �� ��\n"+
"        �� ��          ��       ֮ ��       ʤ �� ��\n"+
"        �� ��       �� ʮ       �� ��       �� Ϊ ��\n"+
"        ˷ ��       �� ��       �� ��       �� �� ��\n"+
"        Ⱥ ��       ֮ ǰ       �� ��       ֮    ��\n"+
"        ��          �� ��       ��          �� ��\n"+
"        ��          �� ��                      ��\n"+
"        ��                                     ��\n"+
"                                               ��\n";

}


void init()
{
        add_action("do_move", "move");
        add_action("do_jump", "jump");
        add_action("do_bihua", "bihua");
}

int do_move(string arg)
{
    object me = this_player(), ob_jian, ob_xtj,where = environment(me);
         if((!arg) || (arg != "stone"))
        return notify_fail("��Ҫ��ʲô��\n");
    if ( where->query_temp("temp/ban", 1) || me->query("max_neili")<500)
    {
       message_vision("����ʲôҲû���ˣ�$N����̾�˿�����\n",me);
       return 1;
    }

    where->set_temp("temp/ban", 1);

    message_vision("����$N˫�����䲻ͣ������ʱ��Ὺڣ��ʯ�顣\n", me);
		if (me->query_temp("marks/fengsett"))
		{
				message_vision("$N��ϸһ��������ʯ���ƺ���Щͼ����\n",me);
				me->delete_temp("marks/fengsett");
				me->set_temp("marks/bihua",1);
			}
    ob_jian = new(__DIR__"obj/wuming-jian");
    if(!clonep(ob_jian)){ 
              return 1;
          }  
    ob_jian->move(where);
    ob_xtj = new(__DIR__"obj/xuantie-jian");
    if(!clonep(ob_xtj)){ 
              return 1;
          } 
    ob_xtj->move(where);
    return 1;
}
int do_jump(string arg)
{
	object me = this_player();

	if (me->is_busy()) return notify_fail("����æ���أ�\n");
        
        if (arg != "down")
           return notify_fail("��Ҫ����������\n");
        me->move(__DIR__"qiaobi");
	message_vision("$N����Ծ�����ͱ��ϡ�\n", me);
	
	return 1;
}
int do_bihua(string arg)
{
	object me = this_player();

	if (me->is_busy()) return notify_fail("����æ���أ�\n");
  if (!me->query_temp("marks/bihua")) 
  	return notify_fail("�����ʲô\n");     
        if (arg != "qingshi")
           return notify_fail("���ұȻ�ʲô��\n");
    if (me->query("fengset")) 
    	return notify_fail("����ʯ�ϵ����ݶ�����˵�Ѿ�̫��ǳ�ˣ�\n");
    if (((int)me->query_skill("lonely-sword",1) < 400) || 
    	((int)me->query_skill("dugu-jiujian",1) < 500))
    	{
    		me->receive_damage("qi", 30);
    	 return notify_fail("����¾Ž�������죬�������һ�������\n");
    	}
		if (random(me->query("kar")) > 28 && me->query("kar") >= 30)
			{
				message_vision("$N��������������ʯ������˼��\n", me);
				if(random((int)me->query_skill("literate",1)) > 2000 &&
					(int)me->query_skill("sword",1) > 1500){
						me->add_temp("bihua",1);
						tell_object(me, "�����������һЩ���¾Ž������ţ�\n");
					}else{
						tell_object(me, "����˰��쾢������ʲôҲû��ѧ����\n");
				}
}
		if (me->query_temp("bihua")>100)
			me->set("fengset",1); 		
	me->receive_damage("qi", 30);
	return 1;
}
