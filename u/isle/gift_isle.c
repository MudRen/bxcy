#include <ansi.h>
string ask_me();
inherit NPC;
void create()
{
        set_name(HIW"isle"NOR, ({ "isle" }));        
        set("title", YEL"����"NOR);
        set("gender", "����");
        set("age", 25);
        set("str", 30);
        set("per", 30);
        set("dex", 30);
        set("inquiry", ([
      "gift":(:ask_me:),
    ]) );
        set("long", "�������Ǳ�Ѫ��������ʦ֮һ��Ϊ���Ը��񱣬����ò�Ҫ������\n");
        set("combat_exp", 900000000);
        set("attitude", "peaceful");
        set_skill("unarmed", 30000);
        set_skill("force", 30000);
        set_skill("dodge", 30000);
        set_skill("parry", 30000);
        set_skill("taixuan-gong", 30000);
        set_skill("liumai-shenjian", 30000);
        set_skill("pixie-jian", 900);
        set_temp("apply/attack", 6000);
        set_temp("apply/defense", 6000);
        set_temp("apply/armor", 6000);
        set_temp("apply/damage", 6000);
        map_skill("force", "taixuan-gong");
        map_skill("unarmed", "liumai-shenjian");
        map_skill("parry", "liumai-shenjian");
        map_skill("dodge", "pixie-jian");         
        set("qi", 2250000);
        set("max_qi", 2250000);
        set("jiali", 100000); 
        set("neili", 9000000); 
        set("max_neili", 9000000); 
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.liumai" :),
                (: perform_action, "unarmed.liumai" :),
                (: exert_function, "recover" :),
                (: exert_function, "heal" :),
            }) );        
        setup();
        carry_object("/clone/misc/cloth")->wear();
}

string ask_me()
{
    object me,ob;
    ob=this_player();  
    command("say ��ӭ����Ϧ������,ף��������������!ʱֵ��һ,��ʦ��׼����\n");
    command("say һ��С����,ϣ���������ã�ϣ����֧��isle�Ĺ���,лл��\n");
    message_vision(HIY"isle����Ʒ�����ó�һ�����ֵ������˸�$N !\n\n"NOR,ob);
    me=new("/u/isle/gift");
    me->move(ob);
    return "���������Ҫ�������,���⵷�Ҷ��κ��˶�û�кô���\n";
}
