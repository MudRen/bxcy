// /clone/misc/gift.c	
#include <ansi.h>
#define GIFT_NAME "�����"	
inherit ITEM;
void create()
{
    set_name(HIR + GIFT_NAME + NOR, ({"gift","liwu"}));
    set_weight(200);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "��");
set("long",
HIG"����������" + HIC" ��ʦ��һ��С���⣬���(chai)��������ʲô��\n"NOR	
);
    set("value", 0);
    set("no_give",1);
    set("no_get",1);
    set("no_put",1);
    set("no_drop",1);
  }
    setup();
}
void init()
{
    add_action("do_chai", "chai");
}
int do_chai(string arg)
{
     object me = this_player();
     object cloth,weapon,leather;
		 cloth = new("/clone/cloth/zixuan");
		 leather=new("/clone/cloth/lingyun");
		 weapon=new("/d/binghuodao/npc/obj/killdragon");

  if (!id(arg))  return notify_fail("��Ҫ��ʲô��\n");
if (me->query("��һ",1))
	{
	  destruct(this_object());
	  return notify_fail("һ��Ư������ӰͻȻ��һ�������г���,һ��ץ�������е����,����ͷ���˰��죺��ѽ~����Ѿ��ù��˰�~����͵��Ŷ~!!��˵��ת������.\n");
		
		
	}
  
//          me->add("max_neili", 5000);	
//           me->add("max_jingli",500);	
me->add("potential",600000);
//if(me->query("combat_exp",1) < 10000000)
//{
me->add("combat_exp",600000) ;
//}
/*
cloth->move(me);
weapon->move(me);
leather->move(me);
*/
tell_object(me,HIC "��С������Ĳ��������ֻ��һ�����������پ���ԡ����,�ƺ��ֱ�������Щ��\n" NOR);     	

//ɾ���ϴ����������ɵĲ��������ӱ��β�����ȷ��ÿλ���ֻ����һ�Ρ�
me->delete("Ԫ��",1);              	
me->delete("�����",1);  
me->delete("�´�",1);
me->set("��һ",1);
     destruct(this_object());
	 return 1;
}
void owner_is_killed() { destruct(this_object()); }
int query_autoload() { return 1; }
