// /d/city/npc/give_clotht.c �������·���npc
#define LAST_PAR "sorry"
#define THIS_PAR "sorrysf"
inherit NPC;
string give_cloth();
string ask_shen();
string ask_du();
int ask_mask(string str);	
void create()
{
set_name(MAG"�������"NOR, ({ "akaigege", "akai gege","akais"}));    	
set("title", HIY"ս����"NOR);	
set("nickname", HIC"����ʹ��"NOR);	
    set("str", 37);
    set("gender", "����");
    set("age", 20);
set("per",10);
    set("long",
        "����ս���õ�������һ�����Ժ���������ˣ���AKAI�����ѣ�\n ���챻AKAIƭ�����ﵱ����ʹ�ߵġ�������Ҫ�Ǹ����ַ������T_T\n");
    set("combat_exp", 1500);
set("no_get",1);
    set("attitude", "friendly");
    set("inquiry", ([
        "�·�" : (: give_cloth :),
//"cloth"  :(: give_cloth :),	
"����":"����(table)�Ͼ���ѽ�����˿�����Ŷ~����\n",      	
"���"  :(: ask_mask :),
"�嶾"  :(: ask_du :),
"����" : (: ask_shen :),
"����˭":"AKAI����һ��Ȼƭ��˵����������кܶ���ü�����ң�����������ȫ�����еģ�\n�ò����׿���һ������Ů�˵ģ�����һ�飬��Ȼ�Ǳ��Ե�����T_T! �����ļһ�����´���������ɱ������\n����ģ�FUCK���ɣ��� do run����ͻȻ�����죬�ָ�AKAI˵�໰�ˡ�Ŷ�����ˣ���ղ�˵ʲô�������ȥ��AKAI������QQ��21787070��������æ�������ش��������\n"
	]));
    
    setup();
carry_object("/clone/misc/changpao")->wear();	
//  carry_object("/d/shaolin/obj/qimeigun")->wield();
}

string give_cloth()
{
    
    object me,obj;
       me = this_player();
if (me->query("gender")=="Ů��") obj=new("/clone/cloth/female1-cloth");
	   else obj=new("/clone/cloth/cloth");
	   obj->move(me);
	   command("xixi");
return "�Ͽ촩�ϰɣ���";
}
int ask_mask(string arg)	
{
object me,obj;	
object zi;	
me = this_player();	
zi=this_object();	
if(present("mian ju", me) || present("mian ju", environment()))   	
{
command("say �Ѿ����˻�����,����ô���̰��������?"); 	
return 1;       	
}
if (me->query("age",1) >=18)
{
command("say �ϴ�С����,��ֻ�᷹���ſ�,��������,��ѧѧ����������!");	
return 1;	
}
else {  	
message_vision(CYN "����΢Ц���ó�����ߣ����˸�$N \n" NOR,me);	
obj=new("/clone/misc/mianju");      	
obj->move(me);	
command("love");  	
return 1;	
}
}
string ask_shen()
 {
        object me = this_player();
if (me->query("age",1) >=18)
{
return "�ϴ�С����,��ֻ�᷹���ſ�,��������,��ѧѧ����������!";	
}else{
               me->set("shen", 0);
   me->start_busy(3);
                return "���񰡣�������������˺����������ɣ�\n"
HIW"ͻȻ�����һ��"HIY"���"HIW"�����ķ���ת˲���ţ�"NOR;
}
}
string ask_du()
 {
        object me = this_player();
if (me->query("age",1) >=18)
{
return "�ϴ�С����,��ֻ�᷹���ſ�,��������,��ѧѧ����������!";	
}else{

               me->clear_condition();
   me->start_busy(3);
                return "���񰡣���������С�����������ɣ�\n"
HIW"ͻȻ�����һ��"HIY"���"HIW"�����ķ���ת˲���ţ�"NOR;
}
}
