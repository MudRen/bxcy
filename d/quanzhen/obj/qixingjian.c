#include <weapon.h>

inherit SWORD;
#include <ansi.h>

void create()
{
   set_name(HIC"七星剑"NOR, ({ "qixing sword", "jian", "sword" }) );
   set_weight(8000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "把");
     set("value", 10000);
     set("material", "steel");
     set("long", "这是一把锋利的钨金剑，上面画着天罡北斗七星，因此名曰“七星剑”，是重阳真人的佩剑。\n");
     set("wield_msg", "一道青光闪过，$N手中已多了把$n。\n");
     set("unequip_msg", "$N放下手中的$n。\n");
   }
init_sword(400,2);	
   setup();
}
void init()
{
if(this_player()!=environment())
add_action("do_get","get");
}
int do_get(string arg)
{
object me=this_player();
object ob=this_object();
string place;
if(environment(ob)->query("short"))
place = environment(ob)->query("short");
else place = "一个不为人知的地方";
if(arg=="qixing sword"){                  	
if(ob->move(me))
message("channel:rumor",HIW"\n〖江湖传闻〗：听说"+me->name()+"在"+place+"弄到了一把"HIC"七星剑\n\n"NOR,users());
me->add("jing",-(me->query("max_jing")/3));
me->set("neili",0);
return 1;
}
return 0;
}
int query_autoload() { return 1; }	
