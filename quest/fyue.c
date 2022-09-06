inherit NPC;
#include "/quest/name.h";
#include "/quest/location.h";
#include <ansi.h>;

mapping userskills;
string username;

int give_quests();
int accountguaiexp(int turn,object who);
int guaif(int turn,object who);
int guaim(int turn,object who);
int set_guai_qi_jing(int turn,object guai);
int getexp(int turn,int level,object who);
string setguaititle(int number,object guaiob);
string randomlocation(int i1);

void create()
{
  set_temp("username","fyue");
  set_temp("level",200);
  set_name("����¥", ({ "wu zhonglou", "wu","lou" }));
  set("title", HIR"ɱ��¥��"NOR);
  set("long", "����ɱ��¥������¥����˵һ����Ϊ�Ѿ��ﵽ����ľ���,�㿴��
����տȻ���� ������������Ȼ�Ѿ����˺�һ�����ӹ����ˡ�\n");
  set("gender", "����");
  set("age", 800);
  set("attitude", "friendly");
    set("no_suck",1);
  set("per", 100);
  set("str", 3000);
  set("int", 40);
  set("dex",500);
  set("con",500);
    set("max_qi", 300000);
  set("max_jing", 30000);
  set("neili", 88888);
  set("max_neili", 4000);
  set("max_jingli", 4000);
  set("jingli", 8000);
  set("combat_exp", 50000000);
    set_skill("unarmed", 1000);
    set_skill("dodge", 1000);
  set_skill("sword", 300);
  set_skill("blade", 300);
  set_skill("parry", 300);
  set_skill("force", 300);
  set_skill("zixia-shengong", 450);
   set_skill("fyue-quan", 1000);
  set_skill("fanliangyi-dao", 480);
  set_skill("huashan-jianfa", 400);
  set_skill("xianglong-zhang", 470);
  set_skill("dugu-jiujian", 400);
  set_skill("huashan-shenfa",460);
  set_skill("literate", 200);
  map_skill("force", "zixia-shengong");
  map_skill("dodge", "huashan-shenfa");
  map_skill("parry", "dugu-jiujian");
  map_skill("sword", "dugu-jiujian");
  map_skill("blade", "fanliangyi-dao");
     map_skill("unarmed", "fyue-quan");
  set("inquiry",([   "kill":(:give_quests():),]));
  set("chat_chance", 10);
	set("chat_msg", ({
		"����¥̧ͷ������һ�ۣ�¶��һ������Ī�������\n",
		"����¥��̾һ����������Ҳ�������˼ǵ����ˣ���\n",
	       (: command("'") :),
             //  (: random_move :),
               (: command("unwield dao"):),
               (: command("unwield jian"):),
               (: command("wield dao"):),
               (: command("wield jian"):),
               (: command("exercise 100"):),
	}) );
  set("chat_chance_combat", 60);
  set("chat_msg_combat", ({
        (: perform_action, "sword.poqi" :),
        (: perform_action, "sword.pozhang" :),
        (: perform_action, "sword.pojian" :),
        (: exert_function, "recover" :),
        (: exert_function, "refresh" :),
    }) );
  setup();
    new("/d/city/obj/changjian")->move(this_object());
  carry_object("/d/gaochang/obj/feituoarmor")->wear();
}
void init()
{
	object who;
add_action("do_press", "press");
	::init();

	if( interactive(who = this_player()) && !who->is_fighting() ) 
       {
		remove_call_out("greeting");
		call_out("greeting", 1, who);
	}
}
void greeting(object who)
{
	if( !who || environment(who) != environment() ) return;
	if ((int)who->query("combat_exp")<1000)
	{
	   switch(random(3))
	   {
		case 0:command("hi "+(string)who->query("id"));break;
	  	case 1:command("welcome "+(string)who->query("id"));break;
	   	case 2:command("bow "+(string)who->query("id"));break;
                case 3:command("whisper "+(string)who->query("id")+" Ҫ������? ���Ҵ���kill����Ϣ�Ϳ�����!");break;
	   }
     
	}
	else
           say("����¥��"+who->query("name")+"˵��:��λ"+RANK_D->query_respect(who)+
               ",����������\n");
           if(random(40)>20)
           command("heihei "+(string)who->query("id"));
	return;
}
int max_skill_level(object ob)
{  

   int s,i=0,maxlevel=1;
   string *str;
   userskills=ob->query_skills();
   if (!mapp(userskills)) {maxlevel=3;return maxlevel;}
   str=keys(userskills);
 //  if(!str) return notify_fail("�㻹����ȥѧϰѧϰ��\n");
   s=sizeof(str);
   if (s<2) return userskills[str[0]]; 
   while (s>0)
     {
       s-=1;
       i=userskills[str[s]];
       if (i>maxlevel) maxlevel=i;
     }
   return maxlevel;
}

int accountlevel(int turn,object ob)
{
   int level;
   level=max_skill_level(ob);
       level=(int)level*(70+turn*4)/120;
   return level;
}

string randomlocation(int i1)
{
   string *str1,*str2,loca;
   int i2,temp;
   str1=keys(allloca);
   str2=allloca[str1[i1]];
   i2=sizeof(str2);
   temp=random(i2);
   if (temp==0 || temp==i2) temp=1;
   loca=str2[0]+str2[temp];
   return loca;
}
      
int give_quests()
{
   object guaiob,userob;
   object me,who,tempob;
   int chooseguai,rewardpot,rewardexp,maxqi,turn;
   int questbusytime,giveuptime,guailevel;
   int temp,i1;
   string *strtemp,locastr,jiangli,sjiangli;
   me=this_object();
   who=this_player();

if((int)this_player()->query("combat_exp")>1000000000){
message_vision ("$N˵��������С������������ݣ�\n",me);
return 1;}
   giveuptime=who->query_temp("questtime2");
   questbusytime=who->query_temp("questtime1");
   turn=who->query_temp("turn");
   if (who->query_temp("kill"))
     {
       if (time()<giveuptime)
        {      
         message_vision ("$N��$n˵������λ"+RANK_D->query_respect(who)
          +"���Ϸ�������ȥɱ��"+who->query_temp("guainame")+"��\n",me,who);
          return 1;
        }
        else turn-=2;
     }
   else
     {
/*
       if (time()<questbusytime) 
        {
        message_vision ("$N���˿���,���΢Ц�Ķ�$n˵����\n"
        +"��λ"+RANK_D->query_respect(who)+",�����Ѿ�������������ȥЪϢ��\n"
        ,me,who);
        return 1;
        }
*/
      }
     
//ÿʮ������һ�֣���turn ������
   if (!turn || turn>9) 
      {
      	who->set_temp("turn",0);
        turn=0;
      }
   turn=turn+1;
   guailevel=accountlevel(turn,who);
     guaiob=new("/quest/questguai"); 
   
   guaiob->set_heart_beat(1);
   guaiob->set_temp("killername",(string)who->query("id"));
   

//���ùֵ�jingli,neili,exp,

   set_guai_qi_jing(turn,who);
   guaiob->set("max_neili",guaif(turn,who));
   guaiob->set("neili",(int)(guaif(turn,who)*6/5));
       guaiob->set("jiali",(int)(guaif(turn,who)/800));
    guaiob->set("max_jingli",guaim(turn,who)*3);
     guaiob->set("jingli",(int)(guaim(turn,who)*3));
      guaiob->set("combat_exp",accountguaiexp(turn,who));
   guaiob->set("neili_factor",(int)(guailevel/2));
   guaiob->set("jingli_factor",(int)(guailevel/2));
   set_guai_qi_jing(turn,guaiob);

//set guai's "long" and "title" 
   switch (random(3))
    {
     case 1 :
      guaiob->set("long","��������"+guaiob->query("name")
                +",��˵�������ɵĸ��֣�����Щ���졣\n");break;
     case 2 :
      guaiob->set("long","�ڵ�����"+guaiob->query("name")
              +"��ȫ��ɢ����һ˿а����\n");break;
     default :
      guaiob->set("long","�䵱��ͽ"+guaiob->query("name")
              +"������������ɱ�����ˡ�\n");
    }
   chooseguai=random(7);
   setguaititle(chooseguai,guaiob);   

//rewardexp and rewardpot ��ɱ�ֺ�õ���qn and exp
   
   rewardexp=getexp(turn,guailevel,who);
   rewardpot=rewardexp/6;
//   this_player()->add("shenhuadaoxing",rewardexp/15);              	
   guaiob->set_temp("killrewardpot",rewardpot);
   guaiob->set_temp("killrewardexp",rewardexp);
   guaiob->set_temp("player",who);
   guaiob->setguaiskill(chooseguai,guailevel,guaiob);
   guaiob->check_time();  

//ȷ���ֵ�λ�� 
   strtemp=keys(allloca);
   i1=sizeof(strtemp);
   temp=random(i1);
   if (temp==i1) temp=0;
   locastr=randomlocation(temp);  
   tempob=load_object(locastr);

//if we get a wrong path,these can help us 
   if (!tempob) 
     {
      message_vision(HIR"$N���ֺ�����ʲô�ط����Ծ��ˣ�����"
      +"��˵��������\nwrong room :"+locastr+"\n"NOR,who);
      return 1;
     }
   guaiob->move(tempob);
switch (random(10))
{
	case 0:jiangli="0";sjiangli="��"; break;
	case 1:jiangli="1";sjiangli="��"; break;
	case 2:jiangli="2";sjiangli="��"; break;
	case 3:jiangli="3";sjiangli="��"; break;
	case 4:jiangli="4";sjiangli="��"; break;
	case 5:jiangli="5";sjiangli="��"; break;
	case 6:jiangli="6";sjiangli="��"; break;
	case 7:jiangli="7";sjiangli="��"; break;
	case 8:jiangli="8";sjiangli="��"; break;
	default:jiangli="9";sjiangli="��";
}
switch (random(24))
{
	case 0:jiangli +="a";sjiangli +="��"; break;
	case 1:jiangli +="b";sjiangli +="��"; break;
	case 2:jiangli +="c";sjiangli +="��"; break;
	case 3:jiangli +="d";sjiangli +="��"; break;
	case 4:jiangli +="e";sjiangli +="��"; break;
	case 5:jiangli +="f";sjiangli +="��"; break;
	case 6:jiangli +="g";sjiangli +="��"; break;
	case 7:jiangli +="h";sjiangli +="��"; break;
	case 8:jiangli +="i";sjiangli +="��"; break;
	case 9:jiangli +="j";sjiangli +="��"; break;
	case 10:jiangli +="k";sjiangli +="��"; break;
	case 11:jiangli +="l";sjiangli +="��"; break;
	case 12:jiangli +="m";sjiangli +="��"; break;
	case 13:jiangli +="n";sjiangli +="��"; break;
	case 14:jiangli +="o";sjiangli +="��"; break;
	case 15:jiangli +="p";sjiangli +="��"; break;
	case 16:jiangli +="q";sjiangli +="��"; break;
	case 17:jiangli +="r";sjiangli +="��"; break;
	case 18:jiangli +="s";sjiangli +="��"; break;
	case 19:jiangli +="t";sjiangli +="��"; break;
	case 20:jiangli +="u";sjiangli +="��"; break;
	case 21:jiangli +="v";sjiangli +="��"; break;
	case 22:jiangli +="w";sjiangli +="��"; break;
	case 23:jiangli +="x";sjiangli +="��"; break;
	case 24:jiangli +="y";sjiangli +="��"; break;
	default:jiangli +="z";sjiangli +="��";
}
switch (random(10))
{
	case 0:jiangli +="0";sjiangli +="��"; break;
	case 1:jiangli +="1";sjiangli +="��"; break;
	case 2:jiangli +="2";sjiangli +="��"; break;
	case 3:jiangli +="3";sjiangli +="��"; break;
	case 4:jiangli +="4";sjiangli +="��"; break;
	case 5:jiangli +="5";sjiangli +="��"; break;
	case 6:jiangli +="6";sjiangli +="��"; break;
	case 7:jiangli +="7";sjiangli +="��"; break;
	case 8:jiangli +="8";sjiangli +="��"; break;
	default:jiangli +="9";sjiangli +="��";
}
switch (random(24))
{
	case 0:jiangli +="a";sjiangli +="��"; break;
	case 1:jiangli +="b";sjiangli +="��"; break;
	case 2:jiangli +="c";sjiangli +="��"; break;
	case 3:jiangli +="d";sjiangli +="��"; break;
	case 4:jiangli +="e";sjiangli +="��"; break;
	case 5:jiangli +="f";sjiangli +="��"; break;
	case 6:jiangli +="g";sjiangli +="��"; break;
	case 7:jiangli +="h";sjiangli +="��"; break;
	case 8:jiangli +="i";sjiangli +="��"; break;
	case 9:jiangli +="j";sjiangli +="��"; break;
	case 10:jiangli +="k";sjiangli +="��"; break;
	case 11:jiangli +="l";sjiangli +="��"; break;
	case 12:jiangli +="m";sjiangli +="��"; break;
	case 13:jiangli +="n";sjiangli +="��"; break;
	case 14:jiangli +="o";sjiangli +="��"; break;
	case 15:jiangli +="p";sjiangli +="��"; break;
	case 16:jiangli +="q";sjiangli +="��"; break;
	case 17:jiangli +="r";sjiangli +="��"; break;
	case 18:jiangli +="s";sjiangli +="��"; break;
	case 19:jiangli +="t";sjiangli +="��"; break;
	case 20:jiangli +="u";sjiangli +="��"; break;
	case 21:jiangli +="v";sjiangli +="��"; break;
	case 22:jiangli +="w";sjiangli +="��"; break;
	case 23:jiangli +="x";sjiangli +="��"; break;
	case 24:jiangli +="y";sjiangli +="��"; break;
	default:jiangli +="z";sjiangli +="��";
}
if(random(10)<5)
sjiangli +="��";
else sjiangli +="��";
who->set_temp("jiangli",jiangli);
//������ҵ���ʱ����
   who->set_temp("questtime1",time()+120);
   who->set_temp("questtime2",time()+300);
   who->set_temp("guainame",guaiob->query("name"));
   who->set_temp("turn",turn);
   who->set_temp("kill",1);
   message_vision("$N������Ц�˼�������$n˵����"+RANK_D->query_respect(who)+"����ͬ�����ˣ�����һ��������ȥ���\n",me,who);
   message_vision("$N��$n˵��������"+HIY+""+guaiob->query("name")+"("
        +guaiob->query("id")+")"+NOR+"��"+HIG+""
        +strtemp[temp]+""+NOR+"����¥���ԣ���׳ʿȥɱ������\n",me,who); 
/*
if(random(10)<5)
tell_object(who,sprintf("%sǧ�ﴫ���㣺������һ�����ܣ�press ��"+HIY+""+sjiangli+""+NOR+" �������⾪ϲ��\n"NOR,me->name(1)));
else
   tell_object(who,sprintf("%sǧ�ﴫ���㣺������һ�����ܣ�press "+HIY+""+sjiangli+""+NOR+" �������⾪ϲ��\n"NOR,me->name(1)));
*/
   remove_call_out("destrory");
   call_out("destrory",20,who);
   return 1;
}
// accountguaiexp ����ֵľ���ֵ
int accountguaiexp(int turn,object who)
{ 
   int userexp,guaiexp;
   userexp=who->query("combat_exp");
   guaiexp=userexp;
   return guaiexp;
}
// guaif ����ֵ�����
int guaif(int turn,object who)
{
   int userneili,guaineili;
   userneili=who->query("max_neili");
   guaineili=userneili*(70+turn*5)/80;
   return guaineili;
}
int guaim(int turn,object who)
{
   int userjingli,guaijingli; 
   userjingli=who->query("max_jingli");
   guaijingli=userjingli*(70+turn*5)/80;
   return guaijingli;
}
int set_guai_qi_jing(int turn,object guai)           	
{
int maxqi,maxjing;      	
maxqi=200+(int)guai->query("max_neili")*(100+turn*20)/200;
maxjing=200+(int)guai->query("max_jingli")*(100+turn*8)*4/1000; 	
//   guai->set_temp("maxqi",maxqi);          	
//   guai->set("max_qi",maxqi);	
guai->set("max_qi",this_player()->query("max_qi")); 	
//   guai->set("eff_qi",maxqi);	
guai->set("eff_qi",this_player()->query("max_qi"));        	
guai->set("jiali",this_player()->query("jiali"));             	
//   guai->set("qi",maxqi);	
guai->set("qi",this_player()->query("max_qi")); 	
//  guai->set("max_jing",maxjing);	
guai->set("max_jing",this_player()->query("max_jing"));	
//   guai->set("eff_jing",maxjing);	
guai->set("eff_jing",this_player()->query("max_jing"));      
//   guai->set("jing",maxjing);	
guai->set("jing",this_player()->query("max_jing"));         	
   return 1;
}
//ɱ�ֵõ���exp,����ҵ�skills ,exp,turn �й�
int getexp(int turn,int level,object who)
{
   int exp,userexp;
   userexp=who->query("combat_exp");
exp=((int)who->query_skill("literate",1)*2)+random(4000)+(userexp)/60000;
   return exp;
}

string setguaititle(int number,object guaiob)
{
   if (random(10)>7)
      {
       if (guaiob->query("combat_exp")>2000000)
             guaiob->set("title","ɱ�˿�ħ");
       else if (guaiob->query("combat_exp")>1000000)
             guaiob->set("title","�����ӯ");
       else if (guaiob->query("combat_exp")>500000)
             guaiob->set("title","������");
       else if (guaiob->query("combat_exp")>100000)
             guaiob->set("title","���");
        else if (guaiob->query("combat_exp")>50000)
             guaiob->set("title","�ɻ���");     
         else if (guaiob->query("combat_exp")>10000)
             guaiob->set("title","��åͷ");  
        else if (guaiob->query("combat_exp")>5000)
             guaiob->set("title","��å");
       else  guaiob->set("title","С��å");
      }
   else 
      {
        switch (number)
        {
         case 1 :guaiob->set("title","ħŮ");break;
         case 2 :guaiob->set("title","���");break;
        case 3 :guaiob->set("title","��ɮ");break;
         case 4 :guaiob->set("title","��Ʀ");break;
         case 5 :guaiob->set("title","����");break;
         case 6 :guaiob->set("title","��ħ");break;
         default :guaiob->set("title","С��");break;
}
}
}
int do_press(string arg)
{
	object player=this_player();
	if(!arg)
		return notify_fail("������ʲô��\n");
	if(!player->query_temp("jiangli"))
		return notify_fail("û��������ʲô��\n");
	if(arg!=player->query_temp("jiangli"))
		write("�ܱ�Ǹ����֤����\n");
		else{
		player->set_temp("baoshi",1);
		write("ף����ˣ�\n");
		}
		remove_call_out("destrory");
		player->delete_temp("jiangli");
		return 1;
}
int accept_object(object me, object obj)
{
if (obj->query("money_id") && obj->value() >= 100000 ){
command("say �ðɣ�"+me->name()+"���ϴε���������ˣ�");
me->delete_temp("kill");
return 1;
}
}
void destrory(object ob)
{
        ob->delete_temp("jiangli");
        return;
}
