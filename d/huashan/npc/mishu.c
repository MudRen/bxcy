// mishu.c

inherit NPC;
#include <ansi.h>;

int do_bihua(string arg);
string ask_me();
int do_halt();
int do_no();

void create()
{
set_name("【豪侠晚歌】--女秘书", ({ "gaoshi mishu", "mishu", "mishu" }) );	
        set("gender", "女性");
        set("age", 25);
        set("no_get", 1);
        set("long",
                "这是一位貌若天仙的小姐，她是豪侠晚歌的秘书，一切的业务都是有她打理。\n");
        set("combat_exp",60000);
        set("shen_type", 1);
        set("attitude", "friendly");

        set("apply/attack", 50);
        set("apply/defense", 50);

        set("max_qi", 800);
        set("max_jing", 800);
        set("max_neili", 800);

        set_skill("force", 80);
        set_skill("unarmed", 80);
        set_skill("sword",80);
        set_skill("parry",80);
        set_skill("dodge", 80);

        set("inquiry", ([
"华山论剑"       : (: ask_me :),	
        ]));

        setup();

        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield();
}

string ask_me()
{
        object* ob;
        int i;
        ob = users();

if ( !wizardp(this_player()) ) return "你无权召开华山论剑！\n";	

        for ( i=sizeof(ob); i>0; i-- ) {
if (environment(ob[i-1]) && ob[i-1]->query("combat_exp")>=10000000)	
                {
ob[i-1]->move("/d/huashan/houzhiwangyu");                	

                }
        }

return "好，华山论剑正式开幕！\n";	
}






