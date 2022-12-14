// blade-book.c

inherit ITEM;

void create()
{
	set_name( "胡家刀谱残篇",({ "blade book","book"}));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
                set("long","这是一本胡家刀谱的几页残篇。\n");
		set("value", 500);
		set("material", "paper");
		set("skill", ([
"name":         "hujia-dao",      //name of the skill	
                        "exp_required": 1000 ,        //minimum combat experience required
			"jing_cost":    20+random(20),// jing cost every time study this
			"difficulty":	20,           // the base int to learn this skill
			"min_skill":	30,           // the minimum level you can learn
"max_skill":    101            // the maximum level you can learn	
		]) );
	}
}
int query_autoload() { return 1; }
void init()
{
if( this_player() == environment() )
{
add_action("do_study", "study");
add_action("do_study", "du");
}
}

int do_study(string arg)
{
int skill_level;
object me=this_player(); 	
skill_level=me->query_skill("hujia-dao",1);
if ( me->is_fighter())
{
tell_object(me,"战斗中无法阅读新知！\n");
return 1;
}
if (me->is_busy()){
tell_object(me,"你现在正忙着呢。\n");
return 1;}

if(skill_level >= 101) {	
tell_object(me,"你仔细的研究了这本书，发现其中所述对你而言太浅了。\n");
return 1;}

if (me->query_skill("blade",1) < 350){
tell_object(me,"你的基本刀法基础不够，还无法领悟胡家刀的精髓。\n");
return 1;}



if( (int)me->query("combat_exp") < (int)skill_level*skill_level*skill_level/10 ) {
write("你的实战经验不足，再怎么读也没用。\n");
return 1;}

if (me->query("jing") < 20) {
tell_object(me,"你太累了，还是休息一下吧！\n");
return 1;}
me->receive_damage("jing", 20);
me->improve_skill("hujia-dao", (me->query_skill("hujia-dao")+me->query_int()));
message_vision("$N正在专心研读胡家刀法。\n", me);
return 1;
}
