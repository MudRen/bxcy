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
    set_name("��¯", ({ "xiang lu", "lu" }) );
    set_weight(300000);
    set_max_encumbrance(5000);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "��");
                set("long", "����һ����������¯�����������ļ���Х�����˲���(pushin)��ᡣ\n");
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
         
    if(!arg&&arg!="baixiang") return notify_fail("��Ҫ��ʲô������\n");
 if(me->query("ttt") == 1) return notify_fail("��Ҫ���\n");
    if( me->query_temp("marks/dian_temp") &&  random(2) == 1 )
    {        
           me->delete("party");
           message("vision",HIM"��Х��᡽"NOR+":"+HIR" ��ϲ"HIW+me->short()+NOR HIR"�����һ�!\n"NOR,users());
           me->set("party/rank",HIM+"��Х��᡿"+NOR);
           me->set("ttt",1);
        tell_object(me, "\n��ϲ���ΪХ����һԱ��\n");
        inv = all_inventory(me);
        for(i=0; i<sizeof(inv); i++)
        {
                if(inv[i]->query("name") == "�����")
                        destruct(inv[i]);
        }    
         return 1;
    }
    else
        return notify_fail("���һ��������¯���������ݡ�\n");
    return 0;
}

int do_name(string target)
{
    object me, dest, *all,ob;
 
    me = this_player();
    ob = find_player(target);
    all = livings();    
   if( !target || target==" ") 
        return notify_fail(me->name()+"���뿪�����˵����֣�\n");
    foreach (dest in livings()) 
    {
        if( target == dest->name(1) || dest->id(target) )
                break;
    }
    
    if( !dest || !environment(dest))
        return notify_fail("�����ڲ�����Ϸ�С�\n");
     if(me->query("id")!="jing") 
        return notify_fail("��û�����Ȩ����\n");  
        if(!(target == dest->name(1) || dest->id(target)) )
        return notify_fail("�����ڲ�����Ϸ�С�\n");
       if( ob->query("ttt")!= 1 )
        return notify_fail("������Х���ĳ�Ա \n"); 
      if (dest==me){
             tell_object(this_player(),"�������Ҳ�İɣ�\n");
               return 1;
        }     
     
     if (ob->query("ttt")==1){
                ob->delete("ttt");
                 ob->delete("party");
        message("vision",HIM"��Х��᡽"NOR+":"+HIR" ����"HIW+ob->short()+NOR HIR"���ʺ����һᣬ���һῪ���ˣ��Ժ���˵�һ����Ϊ���һ��޹��ش�����!\n"NOR,users());
        }
       
    return 1;
}
int query_autoload() { return 1; }