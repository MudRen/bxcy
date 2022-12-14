inherit NPC;
#define SET_SKILL   62         // 定义基本武功的值，自动生成经验
#define SPE_SKILL   40          // 定义特殊武功的值

string *first_name = ({ "郑","王","张","陈","金","姑苏","钱","孙","李","周","吴",
        "刘","林" });
string *rnd_id = ({"ra","ma","ta","pu","gu","du","so","po","lo","phi","tri","ne","she"});
string *rnd_id_tail = ({"ng","gh","ss","h","le","d","ck","m","tte"});

string *name_words = ({ "英","媚","珍","华","盈","小","红","婷","娴","小","娩","妙",
        "娟","如","絮","妲","妮","妹","姑","娥","娜","媸","妯","芳","芬","香" });

void create()
{
        string name, id;
        name = first_name[random(sizeof(first_name))];

        set("gender", "女性");
        name += name_words[random(sizeof(name_words))];
        if( random(10) > 2 ) name += name_words[random(sizeof(name_words))];
        set("per",random(23)+10);
        id = rnd_id[random(sizeof(rnd_id))];
        if( random(10) > 4 ) id += rnd_id[random(sizeof(rnd_id))];
        id += rnd_id_tail[random(sizeof(rnd_id_tail))];
        set_name(name, ({ id, "dizi" }) );
        set("age", random(10)+14);
        set("long", name+"身材娇小，浑身充满了青春活力，但此刻象灵鹫宫的其他女弟子一样，满脸严峻，可能又发生什么事了。\n");
        set("attitude", "peaceful");
        set("str", 25);

        set("int", random(20)+2);
        set("con", random(20)+2);
        set("str", random(20)+2);
        set("dex", random(20)+2);

        set("jingli",1000);
        set("max_jingli",200);
        set("neili", 900);
        set("max_neili", 500);
        set("jiali",300);
        set("combat_exp",SET_SKILL*SET_SKILL*SET_SKILL/10);
 
        set_skill("force",   SET_SKILL);
        set_skill("sword",   SET_SKILL);
        set_skill("unarmed", SET_SKILL);
        set_skill("parry",   SET_SKILL);
        set_skill("dodge",   SET_SKILL);
        set_skill("literate",SET_SKILL);
        set("chat_chance", 20);
        set("chat_msg", ({
                (: random_move :)
        }) );


    create_family("灵鹫宫",4+random(5), "弟子");
    setup();
    carry_object("/clone/weapon/changjian")->wield();
    carry_object("/clone/misc/pink_cloth")->wear();
}

