// wenwu 2003.9.12
// pishui zhu
inherit ITEM;	
void create()	
{	
set_name(CYN BLINK "避水珠" NOR, ({ "pishui zhu" ,"zhu", }) );	
set_weight(210000);     	
if( clonep() )	
set_default_object(__FILE__);	
else {	
set("unit", "颗");	
set("long","一颗神奇的珠子。\n");	
set("value", 0);  	
set("material", "dainomd");	
}	
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
if(arg=="pishui zhu"){                  			
if(ob->move(me))		
message("channel:rumor",HIW"\n〖江湖传闻〗：听说"+me->query("name")+"在"+place+"弄到了一颗"CYN"避水珠.\n\n"NOR,users());        		
return 1;		
}		
return 0;		
}		
