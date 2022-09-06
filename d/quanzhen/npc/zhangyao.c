// zhangyao.c ��ҩ����
// By Lgg,1998.10

#include <ansi.h>
inherit NPC;

void create()
{
        set_name("��ҩ����", ({"zhangyao"}));
        set("gender", "����");
        set("age", 28);
        set("class", "taoist");
        set("long",
                "����ȫ����е��ƹ�����ҩ��ĵ��ˡ�����Ͳ��󣬵�������\n"
                "�Ե������ϳɡ�\n");
        set("attitude", "friendly");
        set("shen_type",1);
        set("str", 21);
        set("int", 22);
        set("con", 23);
        set("dex", 22);

        set("qi", 600);
        set("max_qi", 600);
        set("jing", 400);
        set("max_jing", 400);
        set("neili", 1200);
        set("max_neili", 1200);
        set("jiali", 0);

        set("combat_exp", 30000);
        set("score", 20000);

        set_skill("force", 60);
//        set_skill("xiantian-qigong", 50);    //��������
        set_skill("sword", 60);
        set_skill("quanzhen-jianfa",60);  //ȫ�潣
        set_skill("dodge", 50);
//        set_skill("jinyan-gong", 50);   //���㹦
        set_skill("parry", 60);
        set_skill("unarmed",60);
        set_skill("strike",60);
//        set_skill("haotian-zhang", 50);    //�����
        set_skill("literate",50);
        set_skill("taoism",40);

//        map_skill("force", "xiantian-qigong");
        map_skill("sword", "quanzhen-jianfa");
//        map_skill("dodge", "jinyan-gong");
//        map_skill("parry", "quanzhen-jian");
//        map_skill("strike", "haotian-zhang");
//        prepare_skill("strike", "haotian-zhang");

        create_family("ȫ���", 4, "����");

        set("inquiry", ([
                "���߸�" :  "�����߸���Ҫ��׺�����,���ҵ����������Ұɡ�\n",
        ]) );

        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object(__DIR__"obj/greenrobe")->wear();

}
/*
void attempt_apprentice(object ob)
{
        command("say �ðɣ��Ҿ����������ͽ���ˡ�");
        command("recruit " + ob->query("id"));
}
*/
int accept_object(object who, object ob)
{
        object obj,obj1,obj2;
        object me=this_player();

        if( !who || environment(who) != environment() ) return 0;
        if ( !objectp(ob) ) return 0;
        if ( !present(ob, who) ) return notify_fail("��û�����������\n");

        if (  (string)ob->query("name") != HIB"�ڹ��"NOR
                && ob->query("id") != "fuling" )
                    return notify_fail("��ҩ����ҡͷ�����ⲻ����ҩ�Ĳ��ϡ�\n");

        if  ((string)ob->query("name") == HIB"�ڹ��"NOR)
        {
                if(query_temp("fuling")) {
                        write(MAG"��ҩ������ϲ����׺����߶����ˣ��⸱���߸�������ˡ�\n"NOR);
                        obj=new(__DIR__"obj/gao");
                        obj->move(who);
                        delete_temp("guijia");
                        delete_temp("fuling");
                        if(!(obj2=present("gui jia", this_player())))
                        destruct(obj2);
                        remove_call_out("destroying");
                        call_out("destroying", 1, me, ob);

                        return 1;
                }
                else {
                        if(query_temp("guijia")) {
                                write(YEL"��ҩ����ҡ��ҡͷ������������Ѿ����ˡ���\n"NOR);
                                return 0;
                        }
                        else {
                                set_temp("guijia",1);
                                write(WHT"��ҩ����Ц����������ˣ���ȱ�����ˡ�\n"NOR);
                                if(!(obj2=present("gui jia", this_player())))
                                destruct(obj2);
                                remove_call_out("destroying");
                                call_out("destroying", 1, me, ob);
                                return 1;
                        }
                }
        }
        if (ob->query("id") == "fuling")
        {
                if(query_temp("guijia")) {
                        write(MAG"��ҩ������ϲ����׺����߶����ˣ��⸱���߸�������ˡ�\n"NOR);
                        obj=new(__DIR__"obj/gao");
                        obj->move(who);
                        delete_temp("guijia");
                        delete_temp("fuling");
                        if(!(obj1=present("fuling", this_player())))
                        destruct(obj1);
                        remove_call_out("destroying");
                        call_out("destroying", 1, me, ob);
                        return 1;
                }
                else {
                        if(query_temp("fuling")) {
                                write(YEL"��ҩ����ҡ��ҡͷ�������������Ѿ����ˡ���\n"NOR);
                                return 0;
                        }
                        else {
                                set_temp("fuling",1);
                                write(WHT"��ҩ����Ц�����������ˣ���ȱ����ˡ�\n"NOR);
                                if(!(obj2=present("fuling", this_player())))
                                destruct(obj2);
                                remove_call_out("destroying");
                                call_out("destroying", 1, me, ob);
                                return 1;
                        }
                }
        }

}

void destroying(object me, object obj)
{
        destruct(obj);
        return;
}
