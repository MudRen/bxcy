#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIW "书架" NOR, ({ "shu jia", "jia" }) );         
        set_weight(30000000);
        if( clonep() )
                set_default_object(__FILE__);
        else{
        set("unit", "个");
        set("long", HIY"这是一个专门用来放各种书本的架子。
里面有：
        天罡正气(book)?        
        空明拳谱(quan pu)? 
        全真剑谱(jian pu)

\n"NOR);
        set("material","wood");
        set("no_get",1);
        }
        setup();
}
void init()
{
    add_action("do_get",({"get","na"}));
}

int do_get(string arg)
{
  object me,ob;
  string arg1,arg2;
  me=this_player();
  if(!arg || sscanf(arg, "%s from %s", arg1, arg2)!=2)
   return notify_fail("命令格式: get <书本名称> from jia。\n");
  if (arg2!="jia")
     return notify_fail("命令格式: get <书本名称> from jia。\n");
  if(present(arg1, me) || present(arg1, environment()))
     return notify_fail("已经有这样东西了。\n");
    switch (arg1){
          case "book": ob=new("/d/quanzhen/obj/force_book"); break;             
          case "quan pu": ob=new("/d/quanzhen/obj/unarmed_book"); break;   
          case "jian pu": ob=new("/d/quanzhen/obj/sword_book"); break;         
          default :
                 return notify_fail("没有这本书。\n");
          }
     if(ob) ob->move(me);
       message_vision("$N从书架上拿出一本$n。\n",me, ob);  
       return 1;
}

