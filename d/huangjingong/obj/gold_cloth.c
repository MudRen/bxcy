// by happ@YSZZ

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
   set_name(HIY"�ƽ�ʥ��"NOR, ({ "huangjin shengyi" }) );
   set_weight(10000);
   if( clonep() )
   set_default_object(__FILE__);
   else {
     set("unit", "��");
      set("no_sell",1);
      set("no_give",1);
      set("no_drop",1);
      set("no_get",1);
       set("value",10);
     set("material", "steel");
   set("armor_prop/armor",150);
  }
   setup();
}
int query_autoload() { return 1; }
