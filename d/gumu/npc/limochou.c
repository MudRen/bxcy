#include <ansi.h>


inherit NPC;

int do_look(string);
int ask_me();

void create()
{
        set_name("李莫愁", ({ "li mochou", "li", "mochou" }));
        set("long", "她生得极为美貌，但冰冷的目光让人不寒而立。\n");
        set("nickname", HIB"赤练仙子"NOR);
        set("gender", "女性");
        set("rank_info/respect", "道姑");
        create_family("古墓派", 3, "弟子");
        set("age", 27); 
        set("per", 28);        set("attitude","heroism");
        set("str", 22);
        set("dex", 23);
        set("con", 20);
        set("int", 23);
        set("shen_type", -1);

        set_skill("parry", 150);
        set_skill("force", 150);
        set_skill("dodge", 150);
        set_skill("sword", 150);
        set_skill("throwing",100);
        set_skill("poison", 50);
        set_skill("meinu-quanfa", 150);
        set_skill("cuff", 150);
        set_skill("meinu-quanfa", 150);       
        set_skill("yunu-shenfa", 150);
        set_skill("yunu-jianfa", 150);
        set_skill("yunu-xinjing", 150);
        map_skill("force", "yunu-xinjing");
        map_skill("dodge", "yunu-shenfa");
        map_skill("cuff", "meinu-quanfa");
        map_skill("sword", "yunu-jianfa");
        prepare_skill("cuff", "meinu-quanfa");
        set("jiali",30);

        set("combat_exp", 1000000);

        set("max_qi", 2500);
        set("max_jing", 1500);
        set("neili", 3000);
        set("max_neili", 3000);

        set("inquiry", ([
            "name" : "站远点！",
            "here" : "我不是本地人，不知道。",
            "情" : "你如何能理解其中相思之苦、惆怅之意？",
            "陆展元" : "你问那个薄情的小畜生做什么？",
            "何沅君" : (: ask_me :),
            "小龙女" : "那是我的师妹。你问她想干什么？",
            "林朝英" : "那是我的师祖，不该你问的你别问，小心我宰了你。",
       ]) );

        setup();
        set("chat_chance", 10);
        set("chat_msg", ({
            "李莫愁纵声而歌，音调凄婉，歌道：「问世间，情是何物，直教生死相许？」\n",
            "李莫愁歌道：「天南地北双飞客，老翅几回寒暑？」\n",
            "李莫愁唱道：「欢乐趣，离别苦，就中更有痴儿女。」\n",
            "李莫愁唱道：「君应有语，渺万里层云，千山暮雪，只影向谁去？」\n",
            "李莫愁词意悲切，声调更是哀怨，唱道：「横汾路，寂寞当年箫鼓。荒烟依旧平楚。」\n",
            "李莫愁歌道：「招魂些何嗟及，山鬼自啼风雨。」\n",
            "李莫愁唱道：「天也妒，未信兴，莺儿燕子俱黄土。」\n",
            "李莫愁唱道：「千秋万古，为留待骚人，狂歌痛饮，来访雁丘处。」\n",
        }) );

        carry_object("/d/gumu/obj/zhen")->wield();
        carry_object("/d/wudang/obj/greenrobe")->wear();

}

void init()
{
        ::init();
        add_action("do_look","look");
        add_action("do_look","hug");
        add_action("do_look","mo");
        add_action("do_look","18mo");
        add_action("do_look","kiss");
        add_action("do_look","lean");
        add_action("do_look","interest");
        add_action("do_look","flirt");
        add_action("do_look","pretty");
        add_action("do_look","love");

}

int ask_me()
{
        object me;
 
        me = this_player();
           message("vision",
   HIR "李莫愁冷笑一声：『我这就送你去见她』！\n"
       "李莫愁决心杀死" + me->name() +"！\n"
   NOR, environment(), this_object() );
                   kill_ob(this_player());
   return 1;
}
  

int do_look(string target)
{
        object me;
 
        me = this_player();
        if (id(target)) 
           if ((string)me->query("gender") == "男性") {
                   message("vision",
   HIR "李莫愁大怒，喝道：我最恨你们这些薄情的臭男人！去死吧！\n"
       "李莫愁决心杀死" + me->name() +"！\n"
   NOR, environment(), this_object() );
        command("throw " + me->query("id"));
                   kill_ob(this_player());
           }
} 

void kill_ob(object me)
{     
      command("haha");
      command("throw " + me->query("id"));            
      ::kill_ob(me);

}
/*
void unconcious()
{
       message_vision("$N轻声一笑，转身射出一枚银针，竟不回头察看，足底加劲，急奔出庙，穿入了桑林。\n",this_object());        
       command("sneer");
       destruct(this_object());
}
*/
