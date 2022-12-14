// fighter-c.c - 大游侠
#include <ansi.h>
inherit NPC;
#define SET_SKILL   100         // 定义基本武功的值，自动生成经验
#define SPE_SKILL   80          // 定义特殊武功的值
#define SET_SEN     100         // 定义正气的值
string *first_name = ({ "赵","钱","孙","李","周","吴","郑","王","张","陈",
        "刘","林" });
string *name_words = ({ "文","武","斌","彦","良","志","忠","良","志","忠",
        "孝","雄","龙","明","勇","元","华","宏","胜","进","铭","彬","东","伟" });
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
        set("title", "大游侠");
        set("long", @LONG
一个游侠，从他的脸上可以看出他的江湖经验非常丰富。
LONG
    );
        set("attitude", "heroism");
        set("gender", "男性" );
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
                "大游侠叹道：我在江湖中这么多年，还没遇到过对手。\n",
                "大游侠说道：我在江湖中行侠仗义，专为人打抱不平。\n",
                "大游侠转动关节，把骨头弄得格格响。\n",
                (: random_move :)
        }) );
        setup();
        
        carry_object("/clone/misc/king_cloth")->wear(); // 装备
        carry_object("/d/city/npc/obj/changjian")->wield();
}
int accept_fight(object me)
{
        command("say " + RANK_D->query_respect(me) + "跟你打？你还不是我的对手。\n");
        return 0;
}
