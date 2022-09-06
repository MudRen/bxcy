#include <ansi.h>
#define LAST_PAR "sorry"
#define THIS_PAR "sorrysf"
string ask_me();
string ask_rename();
inherit NPC;
void create()
{
        set_name(HIW"����"NOR, ({ "a fei" }));        
        set("title", YEL"����"NOR);
        set("gender", "����");
        set("age", 25);
        set("str", 30);
        set("per", 30);
        set("dex", 30);
        set("inquiry", ([
      "����":(:ask_me:),
      	"�ı���":(:ask_rename:),
    ]) );
        set("long", "�������Ǳ�Ѫ��������ʦ֮һ��Ϊ���Ը��񱣬����ò�Ҫ������\n");
        set("combat_exp", 900000000);
        set("attitude", "peaceful");
        set_skill("unarmed", 3000);
        set_skill("force", 3000);
        set_skill("dodge", 3000);
        set_skill("parry", 3000);
        set_skill("taixuan-gong", 3000);
        set_skill("liumai-shenjian", 3000);
        set_skill("pixie-jian", 2000);
        set_temp("apply/attack", 6000);
        set_temp("apply/defense", 6000);
        set_temp("apply/armor", 6000);
        set_temp("apply/damage", 6000);
        map_skill("force", "taixuan-gong");
        map_skill("unarmed", "liumai-shenjian");
        map_skill("parry", "liumai-shenjian");
        map_skill("dodge", "pixie-jian");         
        set("qi", 2250000);
        set("max_qi", 2250000);
        set("jiali", 100000); 
        set("neili", 9000000); 
        set("max_neili", 9000000); 
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.liumai" :),
                (: perform_action, "unarmed.liumai" :),
                (: exert_function, "recover" :),
                (: exert_function, "heal" :),
            }) );        
        setup();
        carry_object("/clone/misc/cloth")->wear();
}
int accept_object(object who, object ob)
{
	int time;
    if (ob->query("money_id") && ob->value() >= 300000000)
	{
        message_vision("���ɶ�$N˵���ã���λ" + RANK_D->query_respect(who) + "��Ȼ��ô���ģ��Ҿ͸�����ɡ�\n" , who);
				who->set_temp("shengri",1);
       	return 1;
	}
    else  
		message_vision("������ü��$N˵����ĳ��ⲻ����������ذɣ�\n", who);
	return 0;
}
string ask_me()
{
		int i,j;
    object me,ob;
    ob=this_player();
    me=this_object();
    if(!ob->query_temp("shengri")){
 		message_vision("$N˵��������ǵ��ﶫ��MM��ð���յ��¶������µġ����⡱�ƺ������ɡ�����\n",me);
 	}else{
		j=ob->query("birthday");
		i=j%90+10;
		message_vision("$N���˵�������$n��ͷ��"+CHINESE_D->chinese_number(i)+"��ɵüǺ��ˡ�\n",me,ob);
		ob->delete_temp("shengri");
	}
	return "�������¿�ǧ�����߶���MM��\n";
}
string ask_rename()
{
	object ob=this_player();
    write("��������Դ������±�����\n"+
          "     ��(jian)\n"+
          "     ��(dao)\n"+
          "     ��(gun)\n"+
          "     ��(staff)\n"+
          "     ��(whip)\n");       
    return "��λ"+RANK_D->query_respect(ob)+"Ҫ��ʲô�����������˸�����(rename)��\n";
}
/* void init()
{
        ::init();
        add_action("do_zhu","rename");
}
int do_zhu(string arg)
{
		string id,name;
		object me;
		me = this_player();
		if(!me->query("weapon/make") )
			return notify_fail("�㶼û����������Ҹ�ʲô��\n");
		if (me->query("rename"))
			return notify_fail("�Բ������Ѿ��Ĺ�һ���ˡ�\n");
		if( !arg )
			return notify_fail("���������˵��������������Ƽ����ź��ڶ���˵��\n");
		message("vision",me->name()+"�԰�������˵�˼��䡣\n",environment(me), ({me}) );
    switch (arg) {
      case "jian" :
        me->set("weapon/type","��");
        me->set("weapon/id","my sword");
        me->set("rename",1);
        message("vision","������������˰ɣ�"+me->name()+"!\n",me);
        break;
      case "dao" :
        me->set("weapon/type","��");
        me->set("weapon/id","my blade");
        me->set("rename",1);
        message("vision","������������˰ɣ�"+me->name()+"!\n",me);
        break;
      case "gun" :
        me->set("weapon/type","��");
        me->set("weapon/id","my club");
        me->set("rename",1);
        message("vision","������������˰ɣ�"+me->name()+"!\n",me);
        break;
      case "staff" :
        me->set("weapon/type","��");
        me->set("weapon/id","my staff");
        me->set("rename",1);
        message("vision","������������˰ɣ�"+me->name()+"!\n",me);
        break;
      case "whip" :
        me->set("weapon/type","��");
        me->set("weapon/id","my whip");
				me->set("rename",1);
        message("vision","������������˰ɣ�"+me->name()+"!\n",me);
        break;
      default :
        message_vision(HIC "����һ�����ɣ�ʲô������\n" NOR,me);
        return notify_fail("������ϸ��˵�����²��ɶ�Ϸ��������!!\n");
    }
    me->save();
    return 1;
} */