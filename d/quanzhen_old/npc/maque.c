// maque.c
inherit NPC;
void create()
{
        set_name("��ȸ", ({ "ma que", "que" }) );
        set("race", "Ұ��");
        set("age", 3);
        set("long", "һֻʮ�ֿɶ����ȸ��\n");
        set("attitude", "peaceful");
        set("limbs", ({ "ͷ��", "����", "���", "צ��", "β��" }) );
        set("verbs", ({ "bite", "claw" }) );
        set("combat_exp", 300);
        set_temp("apply/attack", 3);
        set_temp("apply/defense", 5);
        set_temp("apply/armor", 1);
        set("chat_chance", 10);
        set("chat_msg", ({
        "��ȸ֨֨�����ؽ��˼�����\n",
        }) );
        setup();
}
void init()
{       
        object ob;
        ::init();
        if( interactive(ob = this_player()) ) {
           message_vision(this_object()->name()+"һ��$N���ŵ����ĳ�򣬷����ˡ�\n",ob);
           this_object()->random_move();
        }
}

