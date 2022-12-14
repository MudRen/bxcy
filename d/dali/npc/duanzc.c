// duanzc.c 段正淳

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("段正淳", ({ "duan zhengchun", "duan" }));
        set("title",  "大理镇南王" );
        set("long", "他就是大理国的镇南王，当今皇太弟，是有名的爱情圣手。\n");
        set("gender", "男性");
        set("age", 45);
        set("class", "officer");
        set("attitude", "friendly");
        set("shen_type", 1);
        set("str", 30);
        set("int", 30);
        set("con", 35);
        set("dex", 30);
        
        set("max_qi", 5200);
        set("max_jing", 600);
        set("neili", 62000);
        set("max_neili", 2000);
        set("jiali", 2000);
        set("combat_exp", 7000000);

        set_skill("force", 600);             // 基本内功
        set_skill("kumu-shengong", 600);
        set_skill("shaolin-shenfa", 1000);
        set_skill("yiyang-zhi", 600);
        set_skill("unarmed", 600);           // 基本拳脚
        set_skill("dodge", 1000);             // 基本躲闪
        set_skill("parry", 600);             // 基本招架
        set_skill("literate",550);           // 读书识字
    
        map_skill("force"  , "kumu-shengong");
        map_skill("unarmed", "yiyang-zhi");
        map_skill("dodge"  , "shaolin-shenfa");
        map_skill("parry"  , "yiyang-zhi");

        setup();
        carry_object("/clone/misc/cloth")->wear();
        add_money("silver", 50);

        create_family("大理段家",18,"镇南王");
}

void init()
{
        ::init();
/*        
        if( this_player()->query_temp("dalikill") )
        {
                 kill_ob(this_player());
        }
*/        
        if((string) this_player()->query("class") == "officer" ) {
             call_out("on_shengguan", 1);
        }
        add_action("do_kill","kill");
}

void attempt_apprentice(object ob)
{
        string oldtitle;
        oldtitle = ob->query("title");
        if ((int)ob->query("shen") < 10000  ) {
                command("say 我大理段氏向来行侠仗义，您请回吧！");
                return;
        }
        if ((int)ob->query_skill("kumu-shengong",1) < 150 ) {
           command("say 你的本门内功心法太低了,还是努努力先提高一下吧!");
        return;
        }

        else
        {
                command("nod");
                command("say " + RANK_D->query_respect(ob) + "日后必成大器 ！\n");
                command("recruit " + ob->query("id") );
        }
}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "officer");
}

void on_shengguan()
{
        int exp;
        exp = (int) this_player()->query("combat_exp");
        if( exp <= 32000 ) {
                this_player()->set("title","大理国七品芝麻官");
                return ;
        } else if ( exp <= 64000 ) {
                this_player()->set("title","大理国六品官");
                return ;
        } else if ( exp <= 128000 ) {
                this_player()->set("title","大理国五品官");
                return ;
        } else if ( exp <= 256000 ) {
                this_player()->set("title","大理国四品官");
                return ;
        } else if ( exp <= 512000 ) {
                this_player()->set("title","大理国三品官");
                return ;
        } else if ( exp <= 1024000 ) {
                this_player()->set("title","大理国二品官");
                return ;
        } else if ( exp <= 1536000 ) {
                this_player()->set("title","大理国一品官");
                return ;
        } else if ( exp <= 2304000 ) {
                this_player()->set("title","大理国钦差大臣");
                return ;
        } else if ( exp <= 3456000 ) {
                this_player()->set("title","大理国兵马统领");
                return ;
        } else if ( exp <= 5187000 ) {
                this_player()->set("title","大理国兵马总统领");
                return ;
        } else if ( exp <= 26244000 ) {
                this_player()->set("title","大理国镇远将军");
                return ;
} else if ( exp <= 56244000 ) {	
this_player()->set("title","大理国定国大将军");	
return ;	
} else if ( exp <= 100000000 ) {	
this_player()->set("title","大理国宁波大统领");	
return ;	
} else if ( exp <= 300000000 ) {	
this_player()->set("title","大理国御令贴身侍卫");	
return ;	
        } else
this_player()->set("title","大理国御令大丞相");	
                return ;
}

int do_kill(string arg)
{
    if (this_object()->id(arg))
        this_player()->set_temp("dalikill", 1);
    return 0;
}

