// master.c
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void use_poison();
void create()
{
        set_name("碧云", ({ "master dancer", "master", "dancer" }) );
        set("title", MAG "焚静山庄主" NOR);
        set("nickname", HIC "回音仙子" NOR);
        set("gender", "女性");
        set("age", 22);
        set("long",
                
"碧云是一个十分出色的美女，她弹的一手琵琶更是闻名千里，许多\n"
                "王侯子弟，富商豪客都为她天下无双的美貌与琴艺倾倒。\n");
        set("attitude", "peaceful");
        set("class", "dancer");
        set("apprentice_available", 10);
        set("str", 21);
        set("int", 28);
        set("spi", 26);
        set("per", 30);
        set("cps", 30);
        set("force", 7200);
        set("max_force", 6200);
        set("force_factor", 100);
        set("combat_exp", 1500000);
        set("score", 200000);
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                
"碧云嫣然一笑，一个转身迳自舞了起来，对眼前这场恶斗似乎全不放在心上。\n",
                "碧云脚步轻移，翩翩地转了几个圈，回眸一笑。\n",
                "碧云用手扶了扶自己的发簪，像是怕被对手碰歪似地。\n",
                "碧云笑嘻嘻地拾起地上一片从" HIM "魔鞭翩珑" NOR 
"上落下的花瓣。\n",
                (: use_poison :),
                (: exert_function, "chillgaze" :),
        }) );
        set_skill("unarmed", 220);
        set_skill("throwing", 220);
        set_skill("force", 220);
        set_skill("parry", 220);
        set_skill("dodge", 280);
        set_skill("literate", 220);
//        set_skill("perception", 120);
        set_skill("whip", 280);
        set_skill("stormdance", 280);
        set_skill("tenderzhi", 220);
        set_skill("iceforce", 220);
        set_skill("snowwhip", 250);
        map_skill("dodge", "stormdance");
        map_skill("unarmed", "tenderzhi");
        map_skill("force", "iceforce");
        map_skill("whip", "snowwhip");
        create_family("焚静山庄", 1, "庄主");
        set_temp("apply/defense", 100);
        setup();
        carry_object(__DIR__"snake_sandal")->wear();
}
void reset()
{
        delete_temp("learned");
        set("apprentice_available", 10);
}
void attempt_apprentice(object ob)
{
        if( query("apprentice_available") ) {
                if( find_call_out("do_recruit") != -1 )
                        command("say 慢著，一个一个来。");
                else
                        call_out("do_recruit", 2, ob);
        } else {
                command("say 本庄主今天已经收了十个弟子，不想再收徒了。");
        }
}
void do_recruit(object ob)
{
        if( (string)ob->query("gender") != "女性" )
                command("say 男人都不是好东西，滚开！");
        else {
                command("say 很好，只要你对本庄主忠心耿耿，好处是少不了的。");
                if( (int)ob->query("per") > 25 && (int)ob->query("age") < 20 )
                        
message_vision("$N暧昧地抚摸著$n的脸，说道：特别是像你这样的女孩 ....\n", 
this_object(), ob);
                command("recruit " + ob->query("id") );
        }
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "dancer");
        add("apprentice_availavble", -1);
}
void use_poison()
{
        object *enemy, ob;
        string msg;
        enemy = query_enemy();
        if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))];
        if( ob->query_condition("rose_poison") ) return;
        tell_object(ob, 
"你觉得脸上似乎沾上了什麽东西，伸手一摸却什麽也没有。\n");
        if( random(query("combat_exp")) > (int)ob->query("combat_exp") )
                ob->apply_condition("rose_poison", 20);
}
 
