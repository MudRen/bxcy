// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// mihoutao.c ⨺���

#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
  if (!wizardp(this_player())) {
//   set("no_get","������һ��"+this_object()->query("name")+"����ָ�们�䣡\n");
    set("no_give","��ô����ҩ�����������ˣ�\n");
    set("no_drop","��ô����ĵ�ҩ�����˶��ϧѽ��\n");
    set("no_sell","��������֪��"+this_object()->query("name")+"�ļ�ֵ�������Լ����Űɡ�\n");
  }                                    
  add_action("do_eat", "eat");
}

void create()
{
  set_name(YEL "⨺���" NOR, ({"mihou tao","mihoutao","tao"}));
  set_weight(20);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("long", "�Ƴȳȵ�һ��⨺��ң�����˴������Ρ�\n");
    set("value", 5000);
    set("drug_type", "��Ʒ");
  }
  
  setup();
}

int do_eat(string arg)
{
  object me = this_player();
  
  if (!id(arg))
    return notify_fail("��Ҫ��ʲô��\n");
  
  me->set("food", (int)me->max_food_capacity());
  if((int)me->query("max_force")<10*(int)me->query_skill("force")){
    me->add("max_force",1);
  }
  if((int)me->query("max_mana")<10*(int)me->query_skill("spells")){
    me->add("max_mana",1);
  }
  message_vision(HIG "$N����һ���ֺ��ң��̲�סץ�����������˵�ֱ�뷭��ͷ�� \n" NOR, me);
  
  destruct(this_object());
  return 1;
}
int query_autoload() { return 1; }