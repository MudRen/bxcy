// work.c modified by snow

inherit ROOM;

int cot;
void create()
{
        set("short", "����ӹ���");
        set("long", @LONG
����һ�����ӹ����������ǹ����ѿǳ��׵ĵط����׳��ϰ���һ
��һ����֪����ʮ�־����ĸ��ݵ������ˣ����Ǵ���һ����Ц�������
�������������ææµµ�Ĺ����ţ��ſڹ���һ������(sign)��
LONG
        );
        set("no_sleep_room",1);
        set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"dongmen",
]));
        set("item_desc", ([
                "sign": @TEXT
��������ȱ���֣������Ӷһ���̹����ɻ
work     ��ʼ������
TEXT
        ]) );
    set("no_magic", 1);
        setup();
}
void init()
{
        add_action("do_work", "work");
        if (!wizardp(this_user()))
        add_action("discmds",({"duanlian","ansuan","touxi","persuade","teach","exert","exercise","study","learn","sleep","kill","steal","cast","conjure","expell","fight","hit","perform","prcatice","scribe","surrender"}));
}
 int discmds()
{
    tell_object(this_player(),"��������ʵʵ�����ɣ���\n");
    return 1;
}
int do_work(string arg)
{
        int time;
        object me;
        me = this_player();
        time = 300/(int)me->query("str");
        if (time <15) time = 15;
        if ((int)me->query("jing")<random(30) || (int)me->query("qi")<random(30))
        {
        	message_vision("$N��ʼ����ع���......\n", me);
        	write("��ͻȻ�е�ͷ���ۻ�������������\n");
        	tell_room(environment(me), RED+me->name() +"��ɫ�����������ͷ������ĺ�������ϻ���������\n��,����һ��ҪǮ��Ҫ����..!\n"NOR, ({me}));
                me->unconcious();
                return 1;
         }
        if ((int)me->query("jing")<30 || (int)me->query("qi")<30) return notify_fail("��������ˣ�ҪǮ��Ҫ������\n");
        if (me->query_temp("working")) return notify_fail("����ѽ��˭������ѽ��\n");
         if ((cot>2)||me->query("combat_exp")>3000000) {
        	write("�ϰ�ٺ�һЦ�������������Ѿ����ˣ����幤��û��Ǯ��Ӵ��\n");
        	me->start_busy(5);
        	return 1;
        	}
        message_vision("$N��ʼ����ع���......\n", me);
       cot++;
        me->set_temp("working",1);
        me->add_temp("work_times",1);
        call_out("working",10+random(time),me);
        return 1;
}
int working(object me)
{
        object ob;
        if (!me)        return 1;
        
        me->add("jing",-30);
        me->add("qi",-30);
        if((string)environment(me)->query("short")!="����ӹ���"||me->query_temp("work_out"))
        {
        write("�㹤����ʱ��С�������˰���ʲô��û�õ�!\n");
        me->set_temp("working",0);
        me->delete_temp("work_out");
        cot--;
        return 1;
}
        if(random((int)me->query_temp("work_times"))>60+random(100))
        {
        	if((int)me->query("kar")>20)
      message("vision",HIY"������ӹ�����"NOR+":"+YEL" ����"HIW+me->name()+NOR YEL"�������ͣ�������ϰ�ļν�!\n"NOR,users());
        	else message_vision("�ϰ��$N˵���ţ����Ĳ������Ǹ���Ľ�����\n",me);
        	ob = new("/clone/money/gold");
        	
               ob->set_amount(1);
               ob->move(me);
               me->add("potential",30);
               me->delete_temp("work_times");
               me->set_temp("working",0);
                cot--;
               return 1;
        }
        message_vision("$N����Ĺ������ڽ����ˣ�����Ҳ�۵İ�����\n", me);
        ob = new("/clone/money/silver");
          ob->set_amount(10+random(20));
            me->add("combat_exp",random(10));
             me->add("potential",random(10));
        ob->move(me);
        message_vision("�ϰ�����ض�$N˵��������Ĺ�Ǯ��\n", me);
        me->set_temp("working",0);
       cot--;
        return 1;
}
int valid_leave(object me, string dir)
{
       if(dir=="north")
       me->set_temp("work_out",1);
        
        return ::valid_leave(me, dir);
}
void reset()
{
        cot=0;
        ::reset();
}

