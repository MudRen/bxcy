inherit NPC;
string inquiry_yu();
void accept_object(object me, object ob);

void create()
{
        set_name("渔夫", ({ "yu fu" }) );
        set("gender", "男性" );
        set("age", 22);
        create_family("侠客岛", 2, "弟子");
       set("inquiry",([
          "侠客岛" : (: inquiry_yu :),
          ]) );
        setup();
        
}
/*int accept_object(object me, object ob)
{
        object ling1;
        object ling2;

        return 1;

        ling1=new("/d/xiakedao/obj/tongpai1");
        ling1->set_temp("own", (string)me->query("name"));
        ling1->move(me);
        message_vision("渔夫给$N一块铜铸令牌。\n", me);

        ling2=new("/d/xiakedao/obj/tongpai2");
        ling2->set_temp("own", (string)me->query("name"));
        ling2->move(me);
        message_vision("渔夫给$N一块铜铸令牌。\n", me);

        return 1;
}
*/
string inquiry_yu()
{
 object me=this_player();
 object obn;
 object ling1;
 object ling2;
 message_vision("渔夫说道：这位"+ RANK_D->query_respect(me)+"，想去侠客岛，\n"
         +"可不容易呀，千万不要带负神去!唉￣\n"
         , me );
 if(me->query("combat_exp") > 500000)
 {  message_vision("渔夫又说道：这位"+ RANK_D->query_respect(me)+"，我看你"
       +"在江湖中也是个成了名的英雄，我就成全了你的心愿吧!。\n",me);
       
        ling1=new("/d/xiakedao/obj/tongpai1");
        ling1->set_temp("own", (string)me->query("id"));
        ling1->move(me);
        message_vision("渔夫给$N一块铜铸令牌。\n", me);

        ling2=new("/d/xiakedao/obj/tongpai2");
        ling2->set_temp("own", (string)me->query("id"));
        ling2->move(me);
        message_vision("渔夫给$N一块铜铸令牌。\n", me);
        return "祝你一路顺风。\n";
 } 
  else   
  {     return "这位"+ RANK_D->query_respect(me)+"，想上岛？"
      +"我看你还是再努力努力吧\n";
  }
  
  }