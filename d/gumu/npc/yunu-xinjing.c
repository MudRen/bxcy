// yunu-xinjing.c ��Ů�ľ�
// Modify By csy 98/12
inherit FORCE;
#include <ansi.h>
int valid_enable(string usage) { return usage == "force"; }

#include "force.h"

int valid_learn(object me)
{
        int lvl = (int)me->query_skill("yunu-xinjing", 1);
        if ( me->query("gender") == "����" && lvl > 49)
                return notify_fail("���޸����ԣ������������������������Ů�ľ��񹦡�\n");
        return valid_public(me);
}

int practice_skill(object me)
{
        return notify_fail("��Ů�ľ�ֻ�ܿ��������ϰ��\n");
}

string exert_function_file(string func)
{
        return __DIR__"yunu-xinjing/" + func;
}

mapping exercise_msg(object me)
{
  return ([
    "status_msg" : HIB + me->name()+"��̬���ţ���̬���䡣"NOR,
    "start_my_msg" : "���������һ�����������۾���������Ů�ľ�����Ϣ�������п�ʼ��ת��\n",
    "start_other_msg" :HIB + me->name()+"��̬ͻȻ��ʼ��������ޱȣ����������ֱ�������쳣��\n"NOR,
    "halt_msg" : HIB"$N��Ϣһת��Ѹ��������ֹͣ����Ϣ����ת��\n"NOR,
    "end_my_msg" : "���������������뵤������۾������������һ������\n",
    "end_other_msg" : HIB "ֻ��"+me->name()+"�����۾���������³���һ��������̬�ָ���Ȼ��\n"NOR
     ]);
}

