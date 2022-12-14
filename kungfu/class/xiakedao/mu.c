//mu.c

#include <ansi.h>

inherit NPC;
//inherit F_MASTER;

void create()
{
        set_name("木丹凤", ({ "mu", "wood" }));
        set("long", "他就是天下闻之色变的侠客岛岛主，号称“叶上秋露”。\n"
                   +"只见他长须稀稀落落，兀自黑多白少，但一张脸却满是皱纹。\n"
                   +"看不出他的实际年纪。\n"
                   );
        set("title", "侠客岛主");
        set("gender", "男性");
        set("age", 75);
        set("nickname", HIB "叶上秋露" NOR);
        set("shen_type",1);
 
        set("str", 830);
        set("int", 829);
        set("con", 830);
        set("dex", 828);

        set("qi", 900000);
        set("max_qi", 900000);
        set("jing", 90000);
        set("max_jing", 90000);
        set("neili", 1500000);
        set("max_neili", 15000);
        set("jiali", 3000);

        set("combat_exp", 600000000);
        set("score", 200000);
        set_skill("force", 2700);
        set_skill("unarmed", 2400);
        set_skill("dodge", 2900);
        set_skill("parry", 2550);
        set_skill("hand",1700);
        set_skill("staff", 1700);

        set_skill("liumai-shenjian", 2500);
        set_skill("lingxu-bu", 2500);
        set_skill("jiuyang-shengong", 2500);
        map_skill("force", "jiuyang-shengong");
        map_skill("dodge", "lingbo-weibu");
        map_skill("parry", "liumai-shenjian");
        map_skill("unarmed", "liumai-shenjian");

        create_family("侠客岛",1, "岛主");
        set("inquiry",([
           "腊八粥" :   "腊八粥只赠有缘人，不知你是否满足条件。？\n",
           "铜牌"   :   "我这可没有这玩艺，你如想要的话，可找别人问一问。\n",
        ]) );
        setup();
        carry_object("/clone/misc/cloth")->wear();
        add_money("gold",200);
}

void attempt_apprentice(object ob)
{
        message_vision("木岛主拍拍$N的头，微微摇了摇头。\n",ob);
//        command("recruit " + ob->query("id"));
        return;
}

int accept_object(object who, object ob)
{
        object obn;
        object room;
        object key;

        if ( !who || environment(who) != environment() ) return 0;
        if ( !objectp(ob) ) return 0;
        if ( !present(ob, who) ) return notify_fail("你没有这件东西。\n");
             command("smile");
        if( (string)ob->query("name") == "罚恶铜牌" )
        {
            if( (string)ob->query_temp("own") != (string)who->query("name") )
            {
                 message_vision("这不是你的东西。\n",who);
                 return 0;
            }
            command(" say  原来是" + (string)who->query("name") + "大侠" +
                "欢迎光临本岛。");

            obn=new("/d/xiakedao/obj/labazhou");
            obn->move(who);
            command(" say  这是本岛特产腊八粥，外边可不易喝到，其中最主要的一味是<断肠蚀骨腐心草>，"
               + "瞧" +  RANK_D->query_respect(who) + "也是有缘之人，快乘热喝，这样效力方著。");
            message_vision("木岛主给了你一碗腊八粥",who);
            if( who->query_temp("zhou") == 1)
            {
                 command(" say 看来居士福缘深厚，有机会一睹武林绝技，请进吧！");
                 message_vision("只听得一阵隆隆的响声由远及近。\n", this_player());
                 who->set_temp("zhou", 0);
                 message_vision("只见岛主身后的石板缓缓移了开来，露出一条长长的甬道。\n", this_player());
                 environment(who)->set("exits/enter", "/u/noz/test/mishi");

                 room=environment(who);
                 remove_call_out("close");
                 key = new("/d/xiakedao/obj/key");
message_vision("这是我身后石门的钥匙，也是侠客岛上的凭证，希望你妥善保管，不可随意丢弃，" +
                    "更不可交付他人，离岛时应与归还。\n", who);
                 key->move(who);
                 call_out("close", 15, room);
                 return 1;
            }
            who->set_temp("zhou", 2);
            return 1;
        }
        else
        {
            message_vision("我不需要这东西。\n",who);
            return 0;
        }
}

void close(object room)
{
        message("vision","轰隆隆的响声响过之后，石板又合上了。\n", room);
        room->delete("exits/enter");
}

