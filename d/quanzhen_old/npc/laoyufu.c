// yufu.c �����
#include <ansi.h>
inherit NPC;
inherit F_DEALER;
void goto_matou2(object ob);
void create()
{
        set_name("�����", ({ "lao yufu","yufu" }));
        set("gender", "����");
        set("age", 56);
        set("long",
                "����һ������򡣱�����˪������ʲôҲ����������\n",
        );
        set("combat_exp", 10000000);
        set("str",800);
        set("max_neili", 10000);
        set("neili", 1000000);
        set("jiali", 500);
        set("jing", 5000);
        set("max_jing", 5000);
        set("max_jingli", 20000);
        set("jingli", 20000);
        set_skill("force", 1000);
        set_skill("unarmed", 1000);
        set_skill("dodge", 1000);
        set_skill("parry", 1000);
        set_skill("whip", 1000);
        set_skill("yunlong-bian", 1000);
        set_skill("yunlong-shenfa", 1000);
        set_skill("yunlong-shengong", 1000);
        set_skill("houquan", 1000);
        map_skill("parry", "yunlong-bian");
        map_skill("whip", "yunlong-bian");
        map_skill("force", "yunlong-shengong");
        map_skill("dodge", "yunlong-shenfa");
        map_skill("unarmed", "houquan");

        set("chat_chance_combat", 60);
        set("inquiry", ([
        "����" : "�԰���Σ�յģ��������㣬���л�����̫Σ���ˡ�\n",
        "����" : "�����Ľ�������ɻ����ޡ�������˵��Ҫ���������ſ������ɡ�\n",
      "������" : "���ϼ���������˵�������޵ı���ǧ�꺮�񣬱����ɻ������ѩ��˿�ʳɵġ�\n"+
                 "�������ţ������Ҳ���������˵�ڴ����и��˻�����\n",
        ]));
        set("chat_msg_combat", ({
           (: perform_action, "whip.chan" :),
           (: exert_function, "powerup" :),
        }) );
        set("vendor_goods", ({
                __DIR__"obj/liyu",
                __DIR__"obj/changyu",
        }));



        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object(__DIR__"obj/yugang")->wield();
}
void init()
{       
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_list", "list");
        add_action("do_buy", "buy");

}
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
                        say( "�����Ц�����˵������λ" + RANK_D->query_respect(ob)
                                + "�������㻹�����������\n");
}
int accept_object(object who, object ob)
{
        int time;
    if (ob->query("money_id") && ob->value() >= 20000)
        {
        time = ob->value() / 100;
        time = 5000 / time;
        if(time < 6)
                time = 6;
        message_vision("������$N˵���ã���λ" + RANK_D->query_respect(who) + "���ϴ��ɡ�\n" , who);
        who->move ("/d/quanzhen/yangpifa");
                call_out("goto_matou2", time, who) ;
        return 1;
        }
    else  
                message_vision("�������ü��$N˵��������Ҳ̫���˰ɣ�\n", who);
        return 0;
}
void goto_matou2(object ob)
{
        if (!ob)        return;
        tell_object(ob, "��Ƥ�������ڵ����ˡ�������������\n" ) ;
   ob->move ("/d/heimuya/zhaoze/huozhao.c") ;
}

