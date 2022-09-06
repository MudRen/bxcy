#include <ansi.h>
#include <build_gold.h>
inherit ITEM;

void build_armor(object ob,object base);
void create()
{
        set_name(BLINK""HIR"�챦ʯ"NOR, ({"bao shi", "baoshi","shi"}));
	set_weight(500);
	set("no_sell",1);
		set("unit","��");
                set("color","r");  //HIB
                set("no_put",1);
                set("no_sell",1);
		set("long",HIB"һ�鷢���������ı�ʯ����˵��Ů洲���ʯ�����,Ҳ��֪��ʲôʱ�����뷲��ġ�\n"NOR);
	
	setup();
}

void init()
{
    
    add_action("do_enchase", "enchase");
    add_action("do_enchase", "inset");
    seteuid(getuid());
}

int do_enchase(string arg)
{
   object in_obj;
   string item;
   string mats;
   int rd,inset_num ;
   object me = this_player();
   object ob = this_object();
   
   if(!arg) return notify_fail("��Ҫ��ʲô��\n");
   if(sscanf(arg, "%s", item)!=1) return notify_fail("��Ҫ�ѱ�ʯ��Ƕ��ʲô�ϣ�\n");
   if(!objectp(in_obj = present(item, me))) return notify_fail("������û������������\n");
   if( in_obj->query("equipped") )
      return notify_fail("����������������������Ƕ��ʯ��\n");
   if( in_obj->query("no_zm")||in_obj->query_unique())
      return notify_fail("���װ��������Ƕ��ʯ��\n");

   if(((int)me->query("potential")- (int)me->query("learned_points")) < 1000) notify_fail("Ǳ�ܲ���!\n");
   mats = in_obj->query("material");       //װ��������
   inset_num = in_obj->query("inset_num");  // Ƕ�˼�����
   if(!inset_num) inset_num = 1;
   else inset_num = inset_num + 1;
   if(inset_num > 5) return notify_fail(in_obj->query("name")+"���Ѿ���Ƕ��̫��ı�ʯ��!\n");
   
   if(!in_obj->query("weapon_prop/damage"))   //����
  {
       
       message_vision(CYN"$N��$n"+CYN"��Ƕ��"+in_obj->query("name")+CYN"�� \n"NOR,me,ob);
       tell_room(environment(me),HIR"ֻ��"+ob->name()+HIR"����һ��Ѫ˿,������"+in_obj->query("name")+HIR"����,������! \n"NOR);
     
        rd = random(3);
       if (rd==0)
       {
       	 in_obj->add("armor_prop/dodge",1+random(10)); 
         
       }
       if (rd==1) 
       {
       	 in_obj->add("armor_prop/spells",1+random(10)); 
        
       }
       if (rd==2)
       {
       	 in_obj->add("armor_prop/armor",1+random(10)); 
       	
       	 
       }
       message_vision(CYN""+in_obj->query("name")+CYN",ͻȻ����һ���������в���ӿ��һ��ɱ����\n"NOR,me);
       me->add("bellicosity",1000);  
       me->add("potential", -1000);
       in_obj->set_weight(in_obj->query_weight()+1000);
       in_obj->set("inset_num",inset_num);
       in_obj->set("no_sell",1);
       in_obj->add("inset_r",inset_num);  //װ��b
       in_obj->set("name",HIR+in_obj->query("name")+NOR);
       if(!in_obj->query("old_long")) in_obj->set("old_long",in_obj->query("long"));
       in_obj->set("long",in_obj->query("old_long")+"����Ƕ����"HIW+chinese_number(inset_num)+"�ű�ʯ\n"NOR);
       in_obj->save();
       if(check_baoshi(in_obj)==1) build_armor(me,in_obj);
       destruct(ob);
       return 1;
}else{
//����
       me->add("bellicosity",1000);  
       message_vision(CYN"$N��$n"+CYN"��Ƕ��"+in_obj->query("name")+CYN"�� \n"NOR,me,ob);
       tell_room(environment(me),HIR"ֻ��"+ob->name()+HIR"����һ��Ѫ˿,������"+in_obj->query("name")+HIR"����,������! \n"NOR);
       message_vision(CYN""+in_obj->query("name")+CYN"ͻȻ����һ���������в���ӿ��һ��ɱ����\n"NOR,me);
       in_obj->add("weapon_prop/damage",10 + random(30));
       in_obj->add("weapon_prop/intelligence",10+random(30));
       me->add("potential", -1000);
       in_obj->set_weight(in_obj->query_weight()+1000);
       in_obj->set("no_sell",1);       
       in_obj->set("inset_num",inset_num);
       in_obj->add("inset_r",inset_num);  //װ��R
       in_obj->set("name",HIR+in_obj->query("name")+NOR);
       if(!in_obj->query("old_long")) in_obj->set("old_long",in_obj->query("long"));
       in_obj->set("long",in_obj->query("old_long")+"����Ƕ����"HIW+chinese_number(inset_num)+"�ű�ʯ\n"NOR);
       in_obj->save();
       if(check_baoshi(in_obj)==1) build_weapon(me,in_obj);
       destruct(ob);
       return 1;
}


 
  return notify_fail("����Ƕ��ʯʧ���ˣ�\n");
}

int query_autoload() { return 1; }
