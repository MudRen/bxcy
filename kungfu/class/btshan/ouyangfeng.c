///ouyangfeng.c
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
    set_name("ŷ����", ({ "ouyang feng", "ouyang", "feng" }));
    set("long", "���ǰ���ɽׯ�����ųơ���������ŷ���档\n"
           +"����ϰ���������澭���߻���ħ���ѱ�þ�\n"
           +"����ң�������ͷɢ����\n");
    set("title", "�϶���");
    set("gender", "����");
    set("age", 53);
    set("nickname", HIR "����" NOR);
    set("shen_type",-4);
    set("attitude", "peaceful");
    set("str", 100);
    set("int", 70);
    set("con", 50);
    set("dex", 100);
    set("qi", random(10000));
    set("max_qi", 10000);
    set("jing", 5000);
    set("max_jing",8000);
     set("neili",random(2000000));
    set("max_neili", 30000);
    set("jiali", 300);
    set("combat_exp", 70000000);
//    set("score", 200000);
    set_skill("force", 750);
    set_skill("unarmed", 900);
     set_skill("dodge", 800);
      set_skill("parry", 940);
     set_skill("staff", 1000);
     set_skill("hamagong", 980);
     set_skill("chanchu-bufa",870);
      set_skill("shexing-diaoshou",800);
      set_skill("lingshe-zhangfa",1000);
     map_skill("force", "hamagong");
    map_skill("dodge", "chanchu-bufa");
    map_skill("unarmed", "shexing-diaoshou");
    map_skill("parry", "lingshe-zhangfa");
    map_skill("staff", "lingshe-zhangfa");
    create_family("����ɽ��",1, "��ɽ��ʦ");
        set("chat_chance",2);
        set("chat_msg",({
         "ŷ������������������հ���ɽ�ɲ����ذԽ����ء�\n",
         "ŷ��������Ҷ�ŷ���˱��ܹ��������ɽ���۷磡\n",
         "ŷ������������ն����������ģ�\n",
        }));
    setup();
    carry_object("/clone/weapon/gangzhang")->wield();
    carry_object("/clone/misc/cloth")->wear();
    add_money("silver",50);
}
void attempt_apprentice(object ob)
{
  if((int)ob->query("combat_exp")<500000)
        {
          message_vision("ŷ�����$NЦ������ľ���̫����,�һ��������㣡\n",ob);
    return ;
         }
   message_vision("ŷ��������$N��ͷ��΢΢���˵�ͷ��\n",ob);
   command("recruit " + ob->query("id"));
   return;
}
