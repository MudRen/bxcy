// lwshizhe.c ����ʹ��
inherit NPC;
inherit F_MASTER;
int ask_gift(string str);	
void create()
{
set_name(HIC"С���"NOR, ({ "gift shizhe", "shizhe","teshi"}));      	
set("title", HIM"С��ʹ"NOR);     	
set("nickname", HIM"������Ů"NOR);      	
    set("str", 37);
    set("gender", "Ů��");
    set("age", 14);
set("per",30);
    set("long",
"����һ���������˵�С��������۾����������޵����顣\n ��������ר�Ÿ���ҷ��ͽ������\n");	
set("combat_exp", 15000000);   	
set("max_qi", 3000000);   	
set("max_jing", 3000000);   	
set("neili", 15000000);   	
set("jiali", 50000);   	
set("no_get", 1);	
    set("attitude", "friendly");
    set("inquiry", ([
"����": (: ask_gift :),
	]));
    
    setup();
carry_object("/clone/cloth/female1-cloth")->wear();	
//  carry_object("/d/shaolin/obj/qimeigun")->wield();
}

int ask_gift(string arg)	
{
    
object me;
object shizhe;	
object gift;
       me = this_player();
shizhe=this_object(); 	
if ( !wizardp(me) )	
return notify_fail("�������ûʲô�ر������Ŷ!");
if (me->query("60501_gift",1))	
{
command("say �Բ���Ŷ�����Ѿ��ù������˲����ٸ����ˡ�");
return 1;
}
else {
message_vision(CYN "������ʹ�ó�һ��������͸���$N \n" NOR,me);
gift=new(__DIR__"obj/gift");
gift->move(me);	
me->delete("60128_gift");
me->delete("60101_gift");
me->set("60501_gift",1);
return 1;
}
}
