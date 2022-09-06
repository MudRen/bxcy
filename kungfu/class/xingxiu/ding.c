// ding.c ������
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
    set_name("������", ({ "ding chunqiu", "ding" }));
    set("nickname", HIR "�����Ϲ�" NOR);
    set("long", 
        "�����������ɿ�ɽ��ʦ����������ʿ���ʹ���������Ϲֶ����\n"
        "��������������ò���棬�ɷ���ǡ�\n");
    set("gender", "����");
    set("age", 60);
//    set("attitude", "friendly")
    set("shen_type", -1);
    set("str", 60);
    set("int", 70);
    set("con", 60);
    set("dex", 200);
    
    set("max_qi", 4000);
    set("max_jing", 3000);
    set("neili", 15000);
    set("max_neili", 10000);
    set("jiali", 300);
        set("combat_exp", 10380000);
    set("score", 400000);
    set_skill("force", 400);
    set_skill("huagong-dafa", 420);
    set_skill("dodge", 400);
    set_skill("zhaixinggong", 420);
    set_skill("unarmed", 420);
    set_skill("xingxiu-duzhang", 450);
    set_skill("parry", 450);
    set_skill("staff", 470);
    set_skill("tianshan-zhang", 465);
    set_skill("literate", 200);
    map_skill("force", "huagong-dafa");
    map_skill("dodge", "zhaixinggong");
    map_skill("unarmed", "xingxiu-duzhang");
    map_skill("parry", "tianshan-zhang");
    map_skill("staff", "tianshan-zhang");
    create_family("������", 1, "��ɽ��ʦ");
    set("class", "taoist");
    setup();
        carry_object("/clone/weapon/gangzhang")->wield();
    carry_object("/clone/misc/cloth")->wear();
}
void init()
{
        add_action("do_flatter", "flatter");
}
void attempt_apprentice(object me)
{
        if ((int)me->query("betrayer")) {
                command("say ��Խ����Խ�������Ե׵ġ�");
                return;
        }
        if( me->query_temp("pending/flatter") ) {
                command("say ����˲������ɷ�����������������㣿");
                return;
        } else {
                command("say ���������ɱ������������ʥ����ô������");
                message_vision("�����Ϲ�΢��˫�ۣ������룬һ����������(flatter)�����ӡ�\n",
                this_player());
                me->set_temp("pending/flatter", 1);
        }
}
int do_flatter(string arg)
{
        if( !this_player()->query_temp("pending/flatter") )
                return 0;
        if( !arg ) return notify_fail("��˵����ʲô��\n");
        this_player()->set_temp("pending/flatter", 0);
        message_vision("$N����˵����" + arg + "\n", this_player());
        if( strsrch(arg, "��������") >=0 && (strsrch(arg, "�������") >=0
         || strsrch(arg, "�������") >=0 || strsrch(arg, "�Ž��ޱ�") >=0 )) {
                command("smile");
                command("say �⻹��ࡣ\n");
                command("recruit " + this_player()->query("id"));
        } else {
                command("say ����˲������ɷ�����������������㣿");
        }
        return 1;
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                add("apprentice_available", -1);
}
// �������ɣ�������أ��������Ž��ޱ�
