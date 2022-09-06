//tanchuduan.c  ̷����
#include <ansi.h> 
#include <ansi.h>
inherit NPC;

void create()
{
        set_name("̷����", ({"tan chuduan", "tan", "chudan"}));
        set("nickname", HIC"������"NOR);
        set("gender", "����");
        set("age", 53);
        set("long",
             "�����Ͻ����ᣬŨü��������ο��࣬��˵����ǰ��ɽ����������\n"
                "������ȫ�����ӵĶ�ʦ�֡������ӡ�̷���ˡ�\n");
        set("attitude", "peaceful");
        set("class", "taoist");

        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);

        set("chat_chance", 1);
        set("chat_msg", ({
//                (: random_move :),
        }));

        
        set("inquiry", ([
                "����"  : "������һ�źܸ����ѧ�ʣ������ʲ���ǰ�˲˭Ҫ�����أ�\n",
                "ԭ��"  : "�������ú�˿���񣬺��׽�ĸ��ǧ����ľ��ǧ���������������ҵ����Ҳ��ܰ�����������\n",
        ]) );


        
        set("qi", 1500);
        set("max_qi", 1500);
        set("jing",1350);
        set("max_jing", 1350);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiali", 100);
        
        set("combat_exp", 3000000);
        set("score", 50000);
 
        set_skill("force",290);             // �����ڹ�
        set_skill("tiangang-zhengqi",290);    //�������
        set_skill("unarmed",280);           // ����ȭ��
        set_skill("kongming-quan",280);    //����ȭ 
        set_skill("dodge",280);              // ��������
        set_skill("qixing-huanwei",280 );        //���ǻ�λ
        set_skill("parry",290 );             // �����м�
        set_skill("sword",290 );             // ��������
        set_skill("quanzhen-jianfa",290);        //����� 
        set_skill("taoism",280 );            //��ѧ�ķ�  
        set_skill("literate",280);           //����д��  
  
        map_skill("force", "tiangang-zhengqi");
        map_skill("unarmed", "kongmingquan");
        map_skill("dodge", "qixing-huanwei");
        map_skill("parry", "quanzhen-jianfa");
        map_skill("sword", "quanzhen-jianfa");
        
        create_family("ȫ���", 2, "����");
        
        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: perform_action, "sword.qixing" :),
                (: exert_function, "recover" :),
        }) );


        setup();
        
        carry_object("/d/quanzhen/npc/obj/changjian")->wield();
        carry_object("/d/quanzhen/npc/obj/greyrobe")->wear();

}


void init()
{
        ::init();
        add_action("do_zhu","zhu");
}


int accept_object(object who, object ob)
{       
        
        who->delete_temp("sword");
        who->set_temp("m_sword",1);
        switch ((string)ob->query("name") ) 
        {
                case "ǧ����ľ": 
                        who->add_temp("shenmu",1);
                        break;
                case "���׽�ĸ":
                        who->add_temp("jinmu",1);
                        break;
                case "��˿����": 
                        who->add_temp("hanzhu",1);
                        break;
                default :
                        message("vision","����ʲô��ʦ��˵�ⲻ���������������",who);
                        return 0;
        }
        message("vision","̷���˵�ͷ������һ�����е�"+(string)ob->query("name")+
                        "���˵�ͷ˵��\n", who);
        message("vision","���������������ھͿ�ʼ����\n", who);
        write("����λ"+RANK_D->query_respect(who)+"���������ְɣ�(zhu �������� Ӣ�Ĵ���)\n");
        return 2;
}

int do_zhu(string arg)
{
        string o_name,id,w_name;
        object sword,make_time;   //���ɵ��������
        object me;
        me = this_player();
        if(!(me->query_temp("m_sword")) ) 
                return notify_fail("ʲô?\n");
        me->delete_temp("m_sword");
        me->delete_temp("get_orc");
        me->delete_temp("or");

        if((me->query("weapon/make")) ){
                say("̷����һ��ãȻ�����Ѿ���һ������������ˣ�������ʲô���ѵ�������ô��\n");
                return 1;
        }
        if( !arg )
                return notify_fail("̷���������˵����ý������Ƽ����ź��ڶ���˵��\n");

        sscanf(arg ,"%s %s" ,w_name ,id);
        if(!w_name||!id)
                return notify_fail("ʲô?(ʹ��zhu �������� Ӣ�Ĵ���\n)");
        if(me->query_temp("shenmu") ) o_name="ǧ����ľ";
        if(me->query_temp("jinmu") )   o_name="���׽�ĸ";
        if(me->query_temp("hanzhu") )   o_name="��˿����";
        make_time=NATURE_D->game_time();
        message_vision(me->name()+"������һ�ᣬ��̷��������˵�˼��仰��̷���˵��˵�ͷ��˵���ðɣ�\n",me );
        message_vision("\n̷���˻ع���ת������һ���޴�Ļ�¯���Ķ�����ȼ�������ܵĴ��˵����ʼ��\n",me );
        message_vision(BLU "$N˫����סһ���޴���������͵���¯�н�������������"+o_name+"��ȥ��\n" NOR,me);
        message_vision(RED "ֻ�������һ�����죬��ͷ��"+o_name+"ճ����һ��\n" NOR,me );
        message_vision(YEL "$Nֻ��������һ�ȣ������ѪҺ�ƺ���������������\n" NOR,me);
        message_vision(HIM "һ��Ѫ�����������������ԴԴ���ϵ���¯�е�"+o_name+"ӿȥ��\n" NOR,me );
        if( (me->query("qi"))<(me->query("max_qi")) || (me->query("jing"))<(me->query("max_jing")) || (me->query("neili"))<(me->query("max_neili")) )
        {
                message_vision(HIR "ͻȻ$n������Ѫһ��ӿ��һ�������Ӳ������������� \n" NOR, me);
                me->set("neili",0);
                me->unconcious();
                return 1;
        }
        message_vision(HIR "ֻ������һ�����죬һ���޽���¯��ٿȻԾ�𡣻���һ������͵���$N��ǰ�ش�������\n" NOR,me );
        say("̷���˼�״��У��񽣳��ɣ���Ѫ�Լ�����������\n");
        message_vision("$Nֻ������ǰһ����һ����ӰѸ���ޱȵĵ�����$N����ǰ��\n",me );   
        message_vision("�޽�͸�ش�����̷���˲Һ�һ������Ѫ�������������ǣ�\n",me );
        message_vision(RED "̷���˽���һ�����ȣ������˵��ϡ�̷�����Ѿ�����һϢ�ˡ�\n" NOR,me);
        this_object()->set("max_qi",10);
        message_vision("�޽��ַ����������ɵ���գ�����һ����ص����ϡ�\n¯�еĻ����ˡ�һ�ҵľ����������Σ�һ���ֹ��ڳ��š�\n",me );
        
        me->set("qi",10);
        me->set("jing",10);
        me->set("neili",0);

        me->set("weapon/make",1);               //����������ֹ����ı�־              
        me->set("weapon/name",w_name);  //����������
        me->set("weapon/id",id);                //�����Ĵ���
        me->set("weapon/lv",1);         //�����ȼ�
        me->set("weapon/or",o_name);    //��¼����ԭ��
        me->set("weapon/value",0);              //��¼�����������еĵ���        
        me->set("weapon/type","��");
        me->set("weapon/time",make_time);

        sword=new("/d/quanzhen/npc/obj/m_sword",1);     //�����½�
        sword->move(this_player());
        message_vision("̷����������ϣ����Ű߰�Ѫ������Щ���ֵľ޽���˵��\n�������ѡ����ɡ������̽������񡣡���Ҳ������ˡ�������\n",me );
        say("̷���˼��ѵ�˵���������������պã���ס��\n���ڡ������ڡ���������������������ˡ�����\n");
//      message_vision("$Nֻ����ǰһ���������Ѿ���������ˡ�\n",me);
//      message_vision("$Nֻ����ǰһ����$n�Ѳ�������Ӱ��\n",me);
//      message_vision("$Nֻ����ǰһ����$nͻȻ�����������ǰ��\n",me);
        this_player()->move("/d/quanzhen/sanqingdian");
        return 1;
}

