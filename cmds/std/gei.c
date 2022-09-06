#include <ansi.h>

inherit F_CLEAN_UP;
int potential_lv(int exp);

int main(object me, string arg)
{
        object ob,*inv;
        int i, exp, max_pots, pots, bonus;
        mapping quest ;

        exp = (int)me->query("combat_exp");
        max_pots = (int)me->query("max_pot");
        pots = (int)me->query("potential") - (int)me->query("learned_points");
        if (me->is_busy())
                return notify_fail("��������æ���ء�\n");

        if( !arg )
              return notify_fail("ָ���ʽ��gei <����>\n");

        if( !objectp(ob = present(arg, environment(me))))
                return notify_fail("�������Ÿ�˭��\n");

        ob = present(arg, environment(me));
        quest = me->query("quest");

//         if((quest["quest_type"] != "�����͸�"))
//              return notify_fail("�����ڵ����������š�\n");

        if(ob == me)
                return notify_fail("�Լ����Ÿ��Լ������Ǹ������⣮����\n");

        if(!(ob->query("name") == quest["quest"]))
                return notify_fail("�Է�����������ż������ʹ����ˡ�\n");

        if(userp(ob))
                return notify_fail("��ͦ��������ϧ�����ã�������\n");

        if((int)time() > (int)me->query("task_time"))
                return notify_fail("��û�а�ʱ�͵��������н����ˡ�\n");

        message_vision("$N��$n˵������л����л��������ĳ��͡��ҽ���������Ǯׯ���ʺ��ˡ�\n",ob,me);
        me->add("balance",500);
        me->add("combat_exp",(int)quest["exp_bonus"]);
         me->add("potential",(int)quest["pot_bonus"]);
        bonus = (int)me->query("potential");
        bonus = bonus - (int)me->query("learned_points");
        bonus = bonus + (int)quest["pot_bonus"];
        if ( bonus > potential_lv((int)me->query("combat_exp")) )
        bonus = potential_lv((int)me->query("combat_exp"));
        bonus += (int)me->query("learned_points");
        me->set("potential", bonus );

        tell_object(me, HIW "�㱻�����ˣ�\n" +
        chinese_number((int)quest["exp_bonus"]) + "��ʵս����\n"+
        chinese_number((int)quest["pot_bonus"]) + "��Ǳ��\n" NOR);

        inv = all_inventory(me);
        for(i=0; i<sizeof(inv); i++)
        {
                if(inv[i]->query("name") == "�ż�")
                        destruct(inv[i]);
        }
        me->set("quest", 0 );
        return 1;
}

int potential_lv(int exp)
{
        int grade;
        grade = 100 + exp /500;
        return grade;
}


