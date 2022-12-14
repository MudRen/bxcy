// mingjiaodizi.c 
#include <ansi.h>
inherit NPC;

void create()
{
       set_name("明教弟子", ({ "mingjiao dizi", "dizi" }) );
       set("long","一个明教的弟子，背上斜插长剑，满脸英武之气。");
        set("gender", "男性");
        set("age", 20);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 23);
        set("int", 22);
        set("con", 22);
        set("dex", 23);

        set("max_qi", 300);
        set("max_jing", 140);
        set("neili", 200);
        set("max_neili", 200);
        set("jiali", 10);
        set("combat_exp", 6000);
        set("shen",500);
        set("score", 100);

        set_skill("force", 30);
        set_skill("sword", 30);
        set_skill("dodge", 30);
        set_skill("unarmed", 30);
        set_skill("parry", 30);
        set_skill("sword", 30);
        
        
        create_family("明教", 36, "弟子");

        setup();

        set("chat_chance", 1);
        set("chat_msg", ({
        "明教弟子说：我们明教的教主张无忌是当今武林数一数二的人物耶\n",
        "明教弟子大叫到：如果找到残害我们教主父母的那些坏人...嘿嘿。\n",
        "明教弟子对着你大笑起来，你觉得莫名其妙。\n",
         }));

       carry_object("/clone/weapon/changjian")->wield();
       carry_object("/clone/misc/cloth")->wear();
}

