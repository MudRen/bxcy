// zhangduo.c ���ƶ�

#include <ansi.h>

inherit NPC;

#define IN_ROOM "/d/quanzhen/mengjin/mengjin-dukou1"

void goto_matou1(object ob);
void create()
{
        set_name("���ƶ�", ({ "lao zhangduo","zhangduo" }));
        set("gender", "����");
        set("age", 56);
        set("long",
                "����һ���ϴ��򡣱�����˪������ʲôҲ����������\n",
        );
        set("combat_exp", 1000000);
        set("str",800);
        set("max_neili", 100);
        set("neili", 100);
        set("jiali", 500);
        set_skill("force", 100);
        set_skill("unarmed", 300);
        set_skill("dodge", 100);
        set_skill("parry", 100);
        setup();
        carry_object("/clone/misc/scloth")->wear();
}
int accept_object(object who, object ob)
{
        object room=environment();
        if (base_name(room)!=IN_ROOM){
                message_vision("$N��$nҡ��ҡͷ���ҵĶɴ������Ͻ�ɿڣ�Ҫ��ɽ������ǵ��һ�ȥ��˵�ա�\n",this_object(),who);
                return 0;
        }
        if (NATURE_D->outdoor_room()){
                message_vision("$Ņͷ���˿�����$nҡ��ҡͷ��������ɫ������λ" + RANK_D->query_respect(who) + "����������ɡ�\n",this_object(),who);
                return 0;
        }
        if (ob->query("money_id") && ob->value() >= 4000) {
            who->set_temp("rent_paid",1);
            if (room->check_trigger()){
                    message_vision("$N��$n˵���ã���λ" + RANK_D->query_respect(who) + "���ϴ��ɡ�\n" ,this_object(), who);
                    return 1;
            }else{
                    message_vision("$N��$n˵����λ" + RANK_D->query_respect(who) + "��ȵȣ������ڶ԰��ء�\n" ,this_object(), who);
                    return 0;
            }
                
        } else  
                message_vision("$N��ü��$n˵��������Ҳ̫���˰ɣ�\n", this_object(),who);
        return 0;
}

