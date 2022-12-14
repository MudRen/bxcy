// jingxin.c 静心
// create by host dec,11
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

string ask_for_join();
string ask_for_join();

void create()
{
        set_name("静心", ({ "jing xin","jing","xin"}));
        set("long",
      "她是一位中年出家道姑，道冠高拢，慈眉善目。\n");

        set("gender", "女性");
        set("age", 38);
       set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 20);
        set("int", 20);
        set("con", 20);
        set("dex", 20);
        set("inquiry",([
		"剃度"	: (: ask_for_join :),
		"出家"	: (: ask_for_join :),
	]));

        set("qi", 1000);
        set("max_qi", 1000);
        set("jing", 800);
        set("max_jing", 800);
        set("neili", 800);
        set("max_neili", 800);
        set("jiali", 10);

        set("combat_exp", 2550000);
        set("score", 70000);

        set_skill("force", 190);
        set_skill("dodge", 190);
        set_skill("parry", 190);
        set_skill("sword", 190);
        set_skill("linji-zhuang",190);
        set_skill("zhutian-bu",190);
        set_skill("huifeng-jian", 190);
        set_skill("yugalism", 190);
        set_skill("dushi-jiren", 190);
        set_skill("literate", 190);
        map_skill("dodge","zhutian-bu");
        map_skill("parry", "huifeng-jian");

        map_skill("sword", "huifeng-jian");
        map_skill("force","linji-zhuang");

        create_family("峨嵋派", 4,"弟子");
        set("class","bonze");
        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield();
  }

void init()
{
	add_action("do_kneel", "kneel");
}

string ask_for_join()
{
	object me;

	me = this_player();
 
        if ( (int)me->query("combat_exp") > 100000 && (int)me->query("betrayer") > (int)me->query("K_betrayer"))
        {
         command("heng");
          return "本派要求严谨，象施主这样三心二意的人。善哉！善哉！贫尼不能给你剃度。\n";

        }
	if( (string)me->query("class")=="bonze" )
		return "阿弥陀佛！你我同是出家人，何故跟贫尼开这等玩笑？\n";

	if( (string)me->query("gender") != "女性" )
		return "阿弥陀佛！善哉！善哉！施主若真心皈依我佛，可去少林寺受戒。\n";

	me->set_temp("pending/join_bonze", 1);
    	return "阿弥陀佛！善哉！善哉！施主若真心皈依我佛，请跪下(kneel)受戒。\n";
}

int do_kneel()
{
	object me = this_player();

	string *prename =
	 ({ "文" });

	string name, new_name;

	if( !me->query_temp("pending/join_bonze") )
		return 0;
     
	message_vision(
		"$N双手合十，恭恭敬敬地跪了下来。\n\n"
		"$n伸出手掌，在$N头顶轻轻地摩挲了几下，将$N的头发尽数剃去。\n\n",
		me, this_object() );
	name = me->query("name");
	new_name = prename[random(sizeof(prename))] + name[2..3];
	command("say 从今以后你的法名叫做" + new_name + "。");
        command("say 如果想拜师的话可以找静照师姐。");
        command("smile");
	me->delete_temp("pending/join_bonze");
	me->set("name", new_name);
	me->set("class", "bonze");
	me->set("K_betrayer", (int)me->query("betrayer") );

	return 1;
}
void attempt_apprentice(object ob)
{
     
        command("say 善哉！贫尼只管剃度。");
        command("say 如果想拜师的话可以找静照师姐。");
}
