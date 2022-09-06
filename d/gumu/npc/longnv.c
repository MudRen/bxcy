// longnv.c С��Ů
#include <ansi.h>
inherit NPC;
string ask_yunv();
string ask_me();

void create()
{
        set_name("С��Ů", ({"long nv", "long"}));
        set("gender", "Ů��");
        set("age", 18);
        set("long",
                "��һ���������£���������������ѩ���������֮�������䣬\n"
                "ʵ��������������¡������ݡ�\n");
        set("attitude", "friendly");

        set("per", 30);
        set("str", 30);
        set("int", 37);
        set("con", 36);
        set("dex", 38);

        set("chat_chance_combat", 9);
        set("chat_msg_combat", ({
                (: exert_function, "recover" :),
        }) );
        set("chat_chance", 1);
        set("chat_msg", ({
                "С��Ů���ĵص�������֪����������������п����Ҵ��������ϵ��֣���\n", 
                "С��Ů�૵�������Ů����ȫ�潣�ϱڣ��ǿ������޵С�����...����ȥ����һ�����أ���\n",
                "С��Ů�����̾�˿�����ת��ͷȥ��\n",
                (: perform_action, "sword.he" :),
                (: perform_action, "sword.he" :),
                (: perform_action, "sword.he" :),
                (: perform_action, "sword.suxin" :),
        }));

        set("qi", 35000);
        set("max_qi", 35000);
        set("jing", 16000);
        set("max_jing", 16000);
        set("neili", 140000);
        set("max_neili", 140000);
        set("jiali", 100);
        set("combat_exp", 12000000);

        set_skill("force", 350);
        set_skill("yunv-xinfa", 350);    //��Ů�ķ�
        set_skill("sword", 350);
        set_skill("yunv-jian", 350);     //��Ů��
        set_skill("quanzhen-jianfa",350);  //ȫ�潣
        set_skill("dodge", 350);
        set_skill("yunv-shenfa", 350);   //��Ů��
        set_skill("parry", 350);
        set_skill("hubo", 500);          //˫�ֻ���
        set_skill("unarmed",350);
        set_skill("meinv-quan", 350);    //��Ůȭ��
        set_skill("literate",520);
        set_skill("qufeng",250);         //����֮��

        map_skill("force", "yunv-xinfa");
        map_skill("sword", "yunv-jian");
        map_skill("dodge", "yunv-shenfa");
        map_skill("parry", "quanzhen-jianfa");
        map_skill("unarmed", "meinv-quan");

        create_family("��Ĺ��", 3, "����");
        set("book_count", 1);
        set("count",1);

        set("inquiry", ([
                "����" : (: ask_me :),
                "���" :  "��֪���ҹ��������䣿\n",
                "��Ů����" : "��Ů������ȫ�潣���ϱڣ������޵У�\n",
                "��Ĺ��" : "�ҵ�����ʦүү������������ʦ��һ����ˣ�����...\n",
                "��Ů�ľ�" : (: ask_yunv :),
        ]) );

        set("env/wimpy", 40);
        setup();

        carry_object(__DIR__"obj/shunvjian")->wield();
        carry_object(__DIR__"obj/baipao")->wear();

}

void attempt_apprentice(object ob)
{       
   if (((string)ob->query("gender")!="Ů��") || (ob->query("per") < 20))
	{
        	command("say �ҹ�Ĺ�����������������˴򽻵�,���»�����ذɡ�\n");
	}
	else
	{
	        command("say �ðɣ��Ҿ����������ͽ���ˡ�\n");
        	command("recruit " + ob->query("id"));
	}
}

string ask_yunv()
{
        mapping fam;
        object ob;

        if (!(fam = this_player()->query("family"))
            || fam["family_name"] != "��Ĺ��")
                return RANK_D->query_respect(this_player()) +
                "�뱾�ɺ��޹ϸ𣬺��������ɵ��ľ���";
        if (query("book_count") < 1)
                return "�������ˣ����ɵ���Ů�ľ��Ѿ�����ȡ���ˡ�";
        add("book_count", -1);
        ob = new("/clone/book/yunvjing1");
        ob->move(this_player());
        return "�ðɣ��Ȿ����Ů�ľ������û�ȥ�ú��ж���";
}
string ask_me()
{
        object ob;

        if(query("count") < 1)
                return "��֪�����������䣿";

        add("count", -1);
        ob=new(__DIR__"obj/junzijian");
        ob->move(this_player());
        return "������ӽ��͸��������������������ʱ���뽻������";
}
