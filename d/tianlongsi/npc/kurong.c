inherit NPC;
int ask_me();
int accept_fight(object ob);
int checking(object me, object ob);
void create()
{
    set_name("枯荣", ({ "ku rong","ku"}) );
    set("gender", "男性" );
    set("class", "bonze");
    set("age", 100);
    set("str", 40);
    set("int", 40);
    set("con", 40);
    set("dex", 40);
    set("qi", 3000);
    set("max_qi", 3000);
    set("jing", 1000);
    set("max_jing", 1000);
    set("neili", 5000);
    set("max_neili", 5000);
    set("jiali", 50);
    set("combat_exp", 2000000);
    set_skill("force", 250);
    set_skill("kumu-shengong", 150);
    set_skill("dodge", 200);
    set_skill("parry", 200);
    set_skill("unarmed", 205);
    set_skill("yiyang-zhi", 200);
    set_skill("buddhism", 200);
    set_skill("literate", 180);
    map_skill("force", "kumu-shengong");
    map_skill("unarmed", "yiyang-zhi");
    
    set("inquiry" ,([
    "六脉神剑" : (: ask_me :),
    "六脉神剑谱" : (: ask_me :),
    "六脉神剑剑谱" : (: ask_me :),
    ]));
    setup();
    carry_object(__DIR__"obj/p-jiasha")->wear();
    carry_object(__DIR__"obj/sengmao")->wear();
}
int ask_me()
{
        if ((int)this_player()->query_temp("marks/find_temp")&&this_player()->query_temp("marks/ask_temp3")) 
        {
            say(
"枯荣看了" + this_player()->name() + "一眼，说道：\n"
"这位施主果然聪明，施主若能胜过老衲就可得到六脉神剑谱。\n");
 this_player()->set_temp("marks/ask_temp4", 1);
        }
    else  message_vision("$N看了$n一眼，说道：老衲可不知道什么是六脉神剑谱。\n",this_object(),this_player());
    return 1;
}
int accept_fight(object ob)
{
        object me;
        me = this_object();
      
        if ((int)this_player()->query_temp("marks/find_temp")&&this_player()->query_temp("marks/ask_temp3")&&ob->query_temp("marks/ask_temp4")) {
           message_vision("$N对$p说：好吧，那" 
             "我就同你切搓几招吧，点到为止。\n",me,ob);
             command("exert powerup");
          remove_call_out("checking");
          call_out("checking", 1, me, ob);
          return 1;
        }
        else
            return 0;
}
int checking(object me, object ob)
{
        object obj;
        int my_max_qi, his_max_qi;
        my_max_qi  = (int)me->query("max_qi");
        his_max_qi = (int)ob->query("max_qi");
        if (me->is_fighting()) 
        {
                call_out("checking",2, me, ob);
                return 1;
        }
        if ( !present(ob, environment()) ) return 1; 
        if (!living(me))
            me->revive();
        if (( (int)me->query("qi")*100 / my_max_qi) <= 50 ) 
        {
                say(
                  "枯荣说：施主身手果然不凡，老衲佩服。\n"
                  "这本六脉神剑谱你拿去吧。\n"
                );
                obj= new("/d/tianlongsi/obj/liumai-jianpu"); 
                obj->move(ob);
                message_vision("$N交给$n一本书。\n", me, ob);
        ob->delete_temp("marks");
                return 1;
        }
        if (( (int)ob->query("qi")*100 / his_max_qi) < 50 ) 
        {
                say(
                   "枯荣双手合十道：尘缘一切自心起，施主请回吧。\n"
                );
                message_vision("$N对枯荣大师恭恭敬敬地磕了一个头，离开牟尼堂。\n", ob);
                ob->move("/d/tianlongsi/banruotai");
                return 1;
        }
        return 1;
}
