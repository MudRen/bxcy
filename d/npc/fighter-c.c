// fighter-c.c - ������
#include <ansi.h>
inherit NPC;
#define SET_SKILL   100         // ��������书��ֵ���Զ����ɾ���
#define SPE_SKILL   80          // ���������书��ֵ
#define SET_SEN     100         // ����������ֵ
string *first_name = ({ "��","Ǯ","��","��","��","��","֣","��","��","��",
        "��","��" });
string *name_words = ({ "��","��","��","��","��","־","��","��","־","��",
        "Т","��","��","��","��","Ԫ","��","��","ʤ","��","��","��","��","ΰ" });
string *rnd_id = ({"ra","ma","ta","pu","gu","du","so","po","lo","phi","tri","ne","she"});
string *rnd_id_tail = ({"ng","gh","ss","h","le","d","ck","m","tte"});
void create()
{
        string name, id;
        name = first_name[random(sizeof(first_name))];
        name += name_words[random(sizeof(name_words))];
        if( random(10) > 2 ) name += name_words[random(sizeof(name_words))];
        id = rnd_id[random(sizeof(rnd_id))];
        if( random(10) > 4 ) id += rnd_id[random(sizeof(rnd_id))];
        id += rnd_id_tail[random(sizeof(rnd_id_tail))];
        set_name(name, ({ id, "youxia" }) );
        set("title", "������");
        set("long", @LONG
һ�����������������Ͽ��Կ������Ľ�������ǳ��ḻ��
LONG
    );
        set("attitude", "heroism");
        set("gender", "����" );
        set("age", 26+random(15));
        
        set("str", 20+random(10));
        set("int", 20+random(10));
        set("dex", 20+random(10));
        set("per", 20+random(10));
        set("con", 20+random(10));
        set("combat_exp", SET_SKILL * SET_SKILL * SET_SKILL / 10 * ( 10 + random( 10 ) ) / 10);
        set("shen", SET_SEN);
        set("env/wimpy", 10);           //
        set("max_neili", 1000);     set("neili", 1000); set("jiali", 10);
        set("chat_chance_combat", 40);
    set("chat_msg_combat", ({
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :),
    }) );
        set_skill("force",   SET_SKILL);  set_skill("hunyuan-yiqi", SPE_SKILL);
        set_skill("sword",   SET_SKILL);  set_skill("fumo-jian",    SPE_SKILL);
        set_skill("unarmed", SET_SKILL);  set_skill("luohan-quan",   SPE_SKILL);
        set_skill("parry",   SET_SKILL);
        set_skill("shaolin-shenfa",   SPE_SKILL);
        set_skill("dodge",   SET_SKILL);
        set_skill("literate",SET_SKILL);
        map_skill("force",  "hunyuan-yiqi");
        map_skill("sword",  "fumo-jian");
        map_skill("unarmed","luohan-quan");
        map_skill("parry",  "fumo-jian");
        map_skill("dodge",  "shaolin-shenfa");
    
        set("chat_chance", 20);
        set("chat_msg", ({
                "������̾�������ڽ�������ô���꣬��û���������֡�\n",
                "������˵�������ڽ������������壬רΪ�˴򱧲�ƽ��\n",
                "������ת���ؽڣ��ѹ�ͷŪ�ø���졣\n",
                (: random_move :)
        }) );
        setup();
        
        carry_object("/clone/misc/king_cloth")->wear(); // װ��
        carry_object("/d/city/npc/obj/changjian")->wield();
}
int accept_fight(object me)
{
        command("say " + RANK_D->query_respect(me) + "������㻹�����ҵĶ��֡�\n");
        return 0;
}
