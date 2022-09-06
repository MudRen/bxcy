#include <ansi.h>
#include <ansi.h>
inherit ITEM;
object find_player(string target)
{
    int i;
    object *str;
    str=users();
    for (i=0;i<sizeof(str);i++)
        if (str[i]->query("id")==target){
              if (!environment(str[i])) return 0;
              else
            return str[i];
         }
    return 0;
}
void create()
{
    set_name("香炉", ({ "xiang lu", "lu" }) );
    set_weight(300000);
    set_max_encumbrance(5000);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "个");
                set("long", "这是一个常见的香炉，用来让有心加入啸天会的人插香(pushin)入会。\n");
        set("value", 1000);
        set("material", "gold");
        set("no_get",1);
        set("no_drop",1);
        set("amount",30);
    }
    setup();
}
void init()
{
    add_action("do_pushin", "pushin");
    add_action("do_name","kaichu");
}
int do_pushin(string arg)
{
	
    object me, ob,*inv;
    int i;
    me = this_player();
         
    if(!arg&&arg!="baixiang") return notify_fail("你要插什么东西？\n");
 if(me->query("ttt") == 1) return notify_fail("你要干嘛？\n");
    if( me->query_temp("marks/dian_temp") &&  random(2) == 1 )
    {        
           me->delete("party");
           message("vision",HIM"〖啸天会〗"NOR+":"+HIR" 恭喜"HIW+me->short()+NOR HIR"加入我会!\n"NOR,users());
           me->set("party/rank",HIM+"【啸天会】"+NOR);
           me->set("ttt",1);
        tell_object(me, "\n恭喜你成为啸天会的一员！\n");
        inv = all_inventory(me);
        for(i=0; i<sizeof(inv); i++)
        {
                if(inv[i]->query("name") == "入会香")
                        destruct(inv[i]);
        }    
         return 1;
    }
    else
        return notify_fail("你把一柱香插进香炉，拜了两拜。\n");
    return 0;
}

int do_name(string target)
{
    object me, dest, *all,ob;
 
    me = this_player();
    ob = find_player(target);
    all = livings();    
   if( !target || target==" ") 
        return notify_fail(me->name()+"输入开除的人的名字！\n");
    foreach (dest in livings()) 
    {
        if( target == dest->name(1) || dest->id(target) )
                break;
    }
    
    if( !dest || !environment(dest))
        return notify_fail("他现在不在游戏中。\n");
     if(me->query("id")!="jing") 
        return notify_fail("你没有这个权力。\n");  
        if(!(target == dest->name(1) || dest->id(target)) )
        return notify_fail("他现在不在游戏中。\n");
       if( ob->query("ttt")!= 1 )
        return notify_fail("他不是啸天会的成员 \n"); 
      if (dest==me){
             tell_object(this_player(),"你是来找岔的吧？\n");
               return 1;
        }     
     
     if (ob->query("ttt")==1){
                ob->delete("ttt");
                 ob->delete("party");
        message("vision",HIM"〖啸天会〗"NOR+":"+HIR" 由于"HIW+ob->short()+NOR HIR"不适合在我会，被我会开出了，以后此人的一切行为和我会无关特此声明!\n"NOR,users());
        }
       
    return 1;
}
int query_autoload() { return 1; }