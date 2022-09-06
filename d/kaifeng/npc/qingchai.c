// unix 1998,10
// modified by wind
// modified by snow

#include <ansi.h>
inherit NPC;
inherit F_CLEAN_UP;
void del_gaoed(object me);

void init()
{
add_action("do_gao","gao");
add_action("xiao_li","dangguan");
}
void create()
{
        set_name("�ղ�����ǡ�",
        ({"qin chai", "qin"}));
        set("title", HIY"��ʡ��Ѳ��"NOR);
        set("nick_name", "�ղ����");
        set("gender", "����");
        set("age", 54);
        set("long",
                "���Ǿ��ǻ����������ղ�󳼣������ƹ��ű����Ȩ��\n");
        set("attitude", "peaceful");
        set("str", 27);
        set("int", 25);
        set("neili", 4000);
        set("max_neili", 4000);
        set("jiali", 50);
        set("max_jing", 2000);
        set("eff_jing", 2000);
        set("jing", 2000);
        set("max_qi", 5000);
        set("eff_qi", 5000);
        set("qi", 5000);
        set("combat_exp", 400000);
        set_skill("blade", 70);
        set_skill("force", 80);
        set_skill("parry", 50);
        set_skill("dodge", 60);
        set("chat_chance", 5);
        set("chat_msg", ({
       HIM "�����ǿ�����˵:�����Ҳ��ԩ��?\n" NOR,
       HIM "������Ŀ��ǰ��˵:������Ϊ�����Ϸ�����㶪���Դ�\n" NOR,
        }));

         set("inquiry", ([
        "����": HIC "������������˵:�뵱����Ҫ����������ֲ��ܰ�!\n" NOR,
        "��״": HIC "�����˭,�Ⱥ��ҿ��Ǻ������ĺù�Ŷ!\n" NOR,
        "����": HIC "�����پ�������������(dangguan)\n" NOR,
        ]));

        setup();
        carry_object("/clone/cloth/cloth")->wear();
      carry_object("/clone/weapon/gangjian")->wield();
        }

int accept_object(object who, object ob)
{
if (ob->query("money_id") && ob->value() <10000000000+random((50-who->query("kar")))*10000)        {	
        tell_object(who, HIM "�ղ���˲�Ȼ��ŭ��˵����ʲô?���ҶԱ����лߣ�\n" NOR);
        message_vision(HIY"�����Ǵ�ȵ�:�󵨿�ͽ,�����лߣ����˸�������ȥ��!!\n"+
                        "������ǿ��׳������һӶ����,��$N����һ��,���Ű���\n"+
                        "���������$N����,���$N�޵�����\n"NOR,who);
        message_vision(HIR"ͻȻ$N������,һ������������������߶����˼���\n"+
                        "ֻ��������˵:���յ�ҷŹ����´��ٷ���������,����!!\n"NOR,who);
        who->move("/d/city/jianyu");
        who->unconcious();
        return 0;
       }
        else {
        message_vision(HIY"�����Ƕ�$N�ٺٵ�Ц�˼�����\n"NOR,who);
        who->set_temp("gao_paid",1);
        }
        return 1;
}


void beating(object ob)
{
        message_vision(HIY"�����Ǵ�ȵ�:�󵨿�ͽ,�����ܸ�,����,��������ȥ��!!\n"+
                        "������ǿ��׳������һӶ����,��$N����һ��,���Ű���\n"+
                        "���������$N����,���$N�޵�����\n"NOR,ob);
        message_vision(HIR"ͻȻ$N������,һ������������������߶����˼���\n"+
                        "ֻ��������˵:���յ�ҷŹ����´��ٷ���������,����!!\n"NOR,ob);
        ob->move("/d/city/jianyu");
        ob->unconcious();
}


void beating2(object ob)
{
        message_vision(HIY"�����Ǵ�ȵ�:�󵨿�ͽ, �����㷸�˰��ɣ�����,��������ȥ��!!\n"+
                        "������ǿ��׳������һӶ����,��$N����һ��,���Ű���\n"+
                        "���������$N����,���$N�޵�����\n"NOR,ob);
        message_vision(HIR"ͻȻ$N������,һ������������������߶����˼���\n"+
                        "ֻ��������˵:���յ�ҷŹ����´��ٷ���������,����!!\n"NOR,ob);
        ob->move("/d/city/jianyu");
        ob->unconcious();
}

void dzj(object ob)
{
int j;
message_vision(HIY"�������۸ߺ�:��~~��~~~!!\n"NOR,ob);
j=random(3);
if (j == 0){remove_call_out("beating");
call_out("beating", 3, ob);
return ;
}
call_out("dzj",j--, ob);
}

void dzj2(object ob)
{
int j;
message_vision(HIY"�������۸ߺ�:��~~��~~~!!\n"NOR,ob);
j=random(3);
if (j == 0)
{
remove_call_out("beating2");
call_out("beating2", 3, ob);
return ;
}
call_out("dzj2",j--, ob);
}

void del_gaoed(object me)
{
        if (objectp(me) &&  me->query("gaoed"))
           me->delete("gaoed");
}

int do_gao(string str)
{
        object ob,me;
      
          me=this_player();
       if (!me->query_temp("gao_paid")) return notify_fail(HIY"����ôҲ�ý����������\n" NOR);
       if (!str) return notify_fail("<Syntax>: gao <player id>\n");
                   ob=find_player(str);
       if (!ob) ob= find_living(str);
      if (!ob) return notify_fail(HIM "�Ҳ�����Ҫ���ɷ���\n" NOR);
         me->set("gaoed",1);
      if (me->query("pks")>random(10)||me->query("combat_exp")<random(1000)||random(10)>7)
        {call_out("dzj", 5, me);}
             else {
        call_out("del_gaoed", 3000, me);
        me->delete_temp("gao_paid");
        tell_room(environment(ob),"һȺ����һӵ���ϣ���"+
        (string)ob->query("name")+"ץ������, Ȼ�������.\n", ob);
        tell_object(ob,"һȺ����һӵ���ϣ�����˵�����˸����ˣ���������һ��\n");
        ob->move(environment(me));
        tell_object(me, (string)ob->query("name")+"��ץ��������.\n");
        tell_object(ob,"�㷢����"+(string)me->query("name")+
                "�����.\n");
        tell_room(environment(ob),(string)ob->query("name")+"ͻȻ��ץ"+
        "����������\n",({me,ob}));
          message_vision("\n$N����$nվ�ڴ����ϰ�Ц��ֹ,�����Ļ�����"
                +(string)me->query("name")+ "���ǵ�����!\n",ob,me);
        if (random(10)<7) call_out("dzj2", 5, ob);

        else
        message_vision(HIY"�����Ǵ����ȵ�: ����������ˣ���Ȼû�з������Ϳ����!\n" NOR,ob);
         }
       return 1;
}

int xiao_li()
 {
  object ob;
  string old_title;
   ob=this_player();
   old_title = this_player()->query("title");
        if(ob->query("combat_exp")<3000||ob->query("meili")<50){
        command(HIY "say ��������,��Ҫ��������֮��,����ʲô������\n" NOR);
        return 1;
   }
   else if(ob->query("class")=="bonze")
   {command("say ����Ҳ�뵱�٣�������ȥ���װɣ�\n");
    command("sigh2");
    return 1;} else {
           command("smile");
        command(BLU "say �ܺ�,��ͥ��������֮����" + ob->query("name") +
        "������Ϊ��ͥЧ����������֮���ã�\n" NOR);
ob->set("class", "guanfu");	
        ob->set("weiwang", 0);
       if ((ob->query("combat_exp")<5000)&&(ob->query("combat_exp")>=3000)) ob->set("title", "����Ժ����");
 else if (ob->query("combat_exp")<6000) ob->set("title","������ʦү");
else if (ob->query("combat_exp")<7000) ob->set("title","��������");
else if (ob->query("combat_exp")<8000) ob->set("title","ѩͤ������");
 else if (ob->query("combat_exp")<9000) ob->set("title", "ƽ������");
else if (ob->query("combat_exp")<10000) ob->set("title", "��ͬ����");
else if (ob->query("combat_exp")<11000) ob->set("title", "��������");
else if (ob->query("combat_exp")<12000) ob->set("title", "��������");
else if (ob->query("combat_exp")<13000) ob->set("title", "ͩ������");
else if (ob->query("combat_exp")<14000) ob->set("title", "������");
else if (ob->query("combat_exp")<15000) ob->set("title", "����֪��");
else if (ob->query("combat_exp")<18000) ob->set("title", "����֪��");
else if (ob->query("combat_exp")<20000) ob->set("title", "����֪��");
else if (ob->query("combat_exp")<25000) ob->set("title", "�Ͼ�֪��");
else if (ob->query("combat_exp")<30000) ob->set("title", "�����ᶽ");
else if (ob->query("combat_exp")<40000) ob->set("title", "�ƹ��ܶ�");
else if (ob->query("combat_exp")<60000) ob->set("title", "�����ܶ�");
else if (ob->query("combat_exp")<80000) ob->set("title", "�����ܶ�");
else if (ob->query("combat_exp")<100000) ob->set("title", "������Ա����");
else if (ob->query("combat_exp")<200000) ob->set("title", "������");
else if (ob->query("combat_exp")<400000) ob->set("title", "��������");
else if (ob->query("combat_exp")<600000) ob->set("title", "�մ���ͼ���ѧʿ");
else if (ob->query("combat_exp")<800000) ob->set("title", "��ة��");
else if (ob->query("combat_exp")<1000000) ob->set("title", "��ة��");
else if (ob->query("combat_exp")<1500000) ob->set("title", "�մ�һ��ǧ�ﲮ");
else if (ob->query("combat_exp")<2000000) ob->set("title", "�մͶ����򻧺�");
else if (ob->query("combat_exp")<3000000) ob->set("title", "�մ�һ�ȶ�����");
else if (ob->query("combat_exp")<5000000) ob->set("title", "�մͶ��Ȼ�����");
else if (ob->query("combat_exp")<8000000) ob->set("title", "�մ�һ��¹����");
else if (ob->query("combat_exp")<10000000) ob->set("title", "�մ��ص�ƽ����");
else if (ob->query("combat_exp")<30000000) ob->set("title", "�մ�������");
else if (ob->query("combat_exp")<50000000) ob->set("title", "�մ������󽫾�");
else if (ob->query("combat_exp")<80000000) ob->set("title", "�մ�������");
else if (ob->query("combat_exp")<100000000) ob->set("title", "�մͻ�������");
else if (ob->query("combat_exp")<200000000) ob->set("title", "�մͱ�������");
else if (ob->query("combat_exp")<300000000) ob->set("title", "�մͳ�͢����");
else ob->set("title", "�������");
if (old_title==(string)ob->query("title")) 
command("say "+RANK_D->query_respect(ob)+"����ܹ�����Ŭ���Ļ�������һ����ӹٽ�����Ǯ;��������!\n");
else if((string)ob->query("title") == "��ͨ����") 
write("�������ɻ�Ŀ��˿��㣬˵�����ţ��㻹�Ǽ����������ͨ���հɣ�\n");
else {
tell_object(ob,"�����ڵĹ�����[["+ob->query("title")+"]]\n");
message("system", HIY"ʥּ��
����"+ob->query("name")+"ִ���з�����Ϊ�ν��Ӽ���������Ϊ��"+ob->query("title")+"����
��"+ob->query("name")+"�ܼ���Ϊ��ͥЧ�ң�
            �մ�\n"NOR,users());
        }
       return 1;
       }
}
