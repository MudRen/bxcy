//bye enter 

#include <ansi.h>

inherit NPC;
inherit F_DEALER;

int redeem(string arg);

void create()
{
        set_name("����", ({ "yan liu", "yan" }));
        set("title", "��Ǯ��ʹ����ĥ");
        set("shen_type", 0);

        set("gender", "����");
        set_max_encumbrance(100000000);
        set("age", 35);
        set("long",
                "���Ǹ����������ļһ\n");
        set("no_get_from", 1);
set("no_put", 1);    	
set("no_get", 1);	
        set_skill("unarmed", 60);
        set_skill("dodge", 60);
        set_temp("apply/attack", 30);
        set_temp("apply/attack", 30);
        set_temp("apply/damage", 15);

        set("combat_exp", 50000);
        set("attitude", "friendly");
        
        setup();
        carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
        add_action("do_sell", "sell");
        add_action("do_value", "value");
        add_action("do_redeem", "redeem");
}

void die()
{
        message_vision("\n$N���ˡ�\n", this_object());
        destruct(this_object());
}
/*
int do_redeem(string target)
{
        object dest, *all;
int i;

        all = users();

        if (!target)
                return notify_fail("������˭�� 1\n");

        for(i=0; i<sizeof(all); i++) 
        {
                if( target == (string)all[i]->id() || target == all[i]->name() )
                        dest = all[i];
        }
        if( !dest )
                return notify_fail("����˵���������ڲ�����Ϸ�У����������ɡ�\n");
        else if( !dest->query_temp("selled"))
                return notify_fail("������������ɱ����ݺ��ˣ�����ô��Ƿ���Ѻ����أ�\n");

        if (query_temp("busy"))
                return notify_fail("Ӵ����Ǹ�����������æ���ء��������Ժ�\n");

        switch (MONEY_D->player_pay(this_player(), dest->query("per") * 700))
        {
        case 0:
                return notify_fail("��⵰��һ�ߴ���ȥ��\n");
        case 2:
                return notify_fail("������Ǯ�����ˣ���Ʊ��û���ҵÿ���\n");
        default:
                set_temp("busy", 1);
                message_vision("$N��$n���������һ" + dest->query("unit") + 
                        dest->query("name") + "��\n", this_player(), this_object());
                dest->move("/d/city3/kedian");
                dest->set("startroom",__DIR__"kedian");
                dest->delete_temp("selled");
                message("vision",
                        HIY "ֻ����ವ�һ����һ���������˵ļһ���컨���ϵ���������\n" NOR,
                        environment(dest), dest);
                tell_object(dest, "�㱻" + this_player()->query("name") + "���˳�����\n");
        }
        remove_call_out("enough_rest");
        call_out("enough_rest", 1);

        return 1;
}       

*/