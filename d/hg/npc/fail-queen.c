
inherit NPC;

void create()
{
        set_name(HIY "��̫��" NOR, ({ "empress","queen"}));
        set("shen_type", 0);
        set("age",43);
        set("gender", "Ů��");
        set("per",24);
        set("long",
                "�����ð������֣�Ҳ�������겻�����⣬����������ɫ�Եúܲ԰ס�\n");
        set("max_neili",5000);
        set("max_jingli",4000);
        set("jingli",4000);
        set_skill("unarmed",200);
        set_skill("parry",200);
        set_skill("sword",200);
        set_skill("force",200);
        set_skill("throwing",200);
        set_skill("taoism",200);
        set_skill("literate",200);

        set("combat_exp", 800000);
        set("attitude", "friendly");
        set("inquiry", ([
                "�ݺ�" : "��ʲô��˼......��\n",
        ]));
      
  setup();
//        carry_object("/clone/misc/pink_cloth")->wear();
}



