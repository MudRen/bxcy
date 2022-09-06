// ping.c ƽһָ
#include <ansi.h>;
inherit NPC;
int ask_me();
int ask_over();
int ask_working();
string ask_me1();

#include <ansi.h>
void create()
{
    set_name("ƽһָ", ({ "ping yizhi", "ping", "yizhi" }));
    set("title", "ҩ���ϰ�");
    set("gender", "����");
    set("long", "������ҽ���߳��ġ�ɱ����ҽ��ƽһָ���������Ը�Ź֣�����ʲô�˶�ҽ�ġ�\n");
    set("age", 65);
    set("int", 30);
    
    set("qi", 1000);
    set("max_qi", 1000);
    set("jing", 1000);
    set("max_jing", 1000);
    set("shen_type", 0);
    set("combat_exp", 500000);
    set("attitude", "heroism");
    set_skill("unarmed", 80);
    set_skill("dodge", 80);
    set_skill("parry", 60);
    set_temp("apply/attack", 70);
    set_temp("apply/defense", 70);
    set_temp("apply/damage", 50);
        set("inquiry", ([
    "�β�":(:ask_me:),
    "��ҩ": (: ask_me1 :),
"Ǳ�ܵ�": (: ask_me1 :),
    "work" : (: ask_working :),
     "����" : (: ask_over :),
     "����" : (: ask_over :),   
        ]) );
    setup();
    add_money("gold", 1);
    carry_object("/clone/misc/changpao")->wear();
}
string value_string(int value)
{
    if( value < 1 ) value = 1;
    else    if( value < 100 )
        return chinese_number(value) + "��Ǯ";
    else    if( value < 10000 )
        return chinese_number(value/100) + "������"
            + (value%100? "��" + chinese_number(value%100) + "��Ǯ": "");
    else
        return chinese_number(value/10000) + "���ƽ�"
            +( (value%10000)/100 ? chinese_number((value%10000)/100) + "������" : "")
            +( (value%10000)%100 ? "��" + chinese_number((value%10000)%100) + "��Ǯ": "");
}
int ask_me()
{
        object ob;
    mapping inv;
    string str,*cond;
    int i;
        ob=this_player(); 
    inv=ob->query_conditions();
       if (((int)this_player()->query("eff_qi") == (int)this_player()->query("max_qi"))
         && ((int)this_player()->query("eff_jing") == (int)this_player()->query("max_jing"))
    && !sizeof(inv)){
                command("say �Ҹ����������,��,�����ڲ���Ҫ�β�!");
        return 1;
    }
        tell_object(ob, "\nƽһָ̧ͷ�����㼸�ۡ�\n");
    str="";
    if (sizeof(inv)){
        cond=keys(inv);
        for (i=0;i<sizeof(inv);i++){
            if (cond[i]=="drunk")
            str+="���������ģ�һ���Ǻ����ˣ�";
            if (cond[i]=="killer"){
                command("say �ٸ���ͨ�����أ��㻹�ǿ��߰ɣ�");
                return 1;
            }
    }
    if (str==""){
        command("say ����ʲô���ɣ��ҿɲ����Σ�");
                return 1;
    }
    ob->set_temp("count",sizeof(inv)*10);
    }
        if ( (int)this_player()->query("eff_qi") < (int)this_player()->query("max_qi") )
        {
             ob->add_temp("count",5); 
             str+="��,���������˵�����! \n";
         }
    if ( (int)this_player()->query("eff_jing") < (int)this_player()->query("max_jing") )
        {
                 ob->add_temp("count",5);
                 str+="��,�㾫Ԫ���˵�����! \n";
        }            
        str+="��"+value_string(1000* ob->query_temp("count"))+"���ȸ�Ǯ�����β��� \n";
        command("say "+str);
                return 1;
}
int ask_over()
{
 object me,mon;
 int bonus,exp,pot,tempp,kar;
 me = this_player();
 kar = me->query("kar");
  if (!me->query_temp("fengyaoover")) {
    message_vision("ƽһָ���ȵĶ�$N˵������Ŷ�� ���ٿ�ʲô��Ц�����ⲻ������Ժ����\n",me);
    return 1;
    }
    me->delete_temp("fengyaoover");
  if (me->query_temp("fengyaow")) {
  	if(random(kar)>=11)
  	
 {
    message_vision("ƽһָ����һ������$N˵����������ô��ģ��ҷ�ҩ���������ҵ�������\n           �����㻹Ŭ���ķ��ϻ��������Ǯ�ɡ���\n",me);
     exp = 10 + random(20);
    mon = new("/clone/money/silver");
    mon->set_amount(exp);
    tell_object(me,HIW"ƽһָ������" + chinese_number(exp) + "�������� \n"NOR);
    mon->move(me);
    me->delete_temp("fengyaow");
    return 1;
 }
 	   
        message_vision(" ƽһָ����һ������$N˵��������ô��ģ��ҷ�ҩ���������ҵ�������\n",me);
        return 1;

    }
   message_vision("ƽһָЦ�Ŷ�$N˵����С�ֵܻ���������Կ��ԣ�������Ӧ�õõġ���\n",me);
     exp = 10 + random(80);
    pot = 10 + random(10);
    bonus = (int) me->query("combat_exp");
    tempp = bonus;
    bonus += exp;
    me->set("combat_exp", bonus);
    bonus = (int) me->query("potential");
    bonus += pot;
    me->set("potential", bonus);
   mon = new("/clone/money/silver");
    mon->set_amount(exp)*2;
  mon->move(me);
    me->start_busy(3);
   tell_object(me,HIW"�㱻�����ˣ�" + chinese_number(exp) + "�㾭�飬"+ chinese_number(pot) + "��Ǳ�ܺ�������"+chinese_number(exp*2) + "�������� \n"NOR);
    bonus=(int) me->query("potential");
    return 1;
}
int ask_working()
{
   object me;
   me = this_player();
   if((int)(me->query("combat_exp")) > 500000)
      { message_vision("ƽһָ��$N˵����������һ�����֣�С���ͷ����𡣺ǡ������ǡ�������\n",me);
        return 1;
     }
   if (me->query_temp("fengyaobegin"))
      { message_vision("ƽһָ��$N˵�������㲻���Ѿ�Ҫ�˹����ˣ�����ȥ�ɣ���\n",me);
        return 1;
     }
  if ((int)(me->query("qi")) < random(30))        
         { message_vision("ƽһָ��$N˵���������˰��㣬�������˻��빤������ҩ�ִ��˻�������ġ���\n",me);
        return 1;
     }
   if (me->query_temp("fengyaoover"))
       { message_vision("ƽһָ��$N˵������Ŷ�� �����Լ��Ĺ���Ҳ��Ҫ����\n",me);
         message_vision("ƽһָ��$N˵�������ðɣ���Ȼ������Ҳ�Ͳ���ǿ���ˡ���\n",me);
         message_vision("ƽһָ��$N˵����������͵�����ȥ�����ٷִ�ҩ�ɡ���\n",me);
         me->delete_temp("fengyaow");
         me->delete_temp("fengyaoover");
         me->set_temp("fengyaobegin",1);
         return 1;
     }
   
   message_vision("ƽһָ��$N˵�������ðɣ�����͵�����ȥ���ҷַ�ҩ�ɡ���\n",me);
   me->set_temp("fengyaobegin",1);
   return 1;
}
int accept_object(object who, object ob)
{
    if (who->query_temp("count"))
        if (ob->query("money_id") && ob->value() >= who->query_temp("count")*1000){ 
                who->set("eff_qi",who->query("max_qi"));
                who->set("eff_jing",who->query("max_jing"));
                who->set("eff_gin",who->query("max_gin"));
                who->apply_condition("drunk",0);
                tell_object(who, "ƽһָ�ó�Щҩ�������£���һ�ᣬ�����ɫ�������ö��ˡ�\n");
            who->set_temp("count",0);
                return 1;
            }  else
                tell_object(who, "ƽһָ����һЦ����ĳ��ⲻ����������ذɣ�\n");
    return 0;
}
string ask_me1()
{
    return "��...�Ҳ�֪����";
}
