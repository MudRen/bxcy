// This is a room made by wsl.
inherit ROOM;
void create()
{
    set("short", "�ݵ�");
    set("long",@LONG
����һƬ�տ��Ĳݵأ����ܳ������Ӳݣ��ƺ������Ѿ��ܾ�û��
�������ˣ�������Ұ�ĵط���������в��ɵ�����һ˿���⡣����
���߾���һ������׵ľ����ˡ�
LONG
);
        set("outdoors","changan");
    set("exits", ([
        "west" :__DIR__"boshulin10",
        "east" :__DIR__"jueya",
]));
    set("item_desc", ([
"�ݵ�" : "����Ƭ�ݵص��м䣬���ƺ��е�һЩ������\n",
]));
    setup();
}

void init()
{
    if (interactive(this_player()))
    add_action("do_kill","kill");
}

void check(object me,object ob)
{
    if (!me || !ob)
        return;
    if (!present(me,this_object())
        || !present(ob,this_object()))
        return;
if ( ob->query("jiali") != (ob->query_skill("force")/2)           	
|| me->query("jiali") != (me->query_skill("force")/2))    	
        return;
if (me->query("max_neili")<100000                                 
|| ob->query("max_neili")<100000)                                 
        return;
    if (ob->query("max_neili") < me->query("max_neili")){
        message_vision("$n��$N����һ�����±ߵ�����ȥ��\n",me,ob);
ob->move(__DIR__"qinhuang/gudi.c");	
        ob->set_temp("killer",1);
        ob->unconcious();
    }else{
        message_vision("$N��$n����һ�����±ߵ�����ȥ��\n",me,ob);
me->move(__DIR__"qinhuang/gudi.c");	
me->set_temp("killer",1);	
        me->unconcious();
    }
}

int do_kill(string arg)
{
    object ob,me=this_player();
    
    if (!arg || arg=="")   return 0;
    if (ob=present(arg,this_object())){
message_vision( HIY "$N��$nһ���棬������ɱ��������\n" NOR ,me,ob);
        if (userp(ob))
            if ( ob->query("jiali")==(ob->query_skill("force")/2)
            && me->query("jiali")==(me->query_skill("force")/2)){
                remove_call_out("check");
                call_out("check",random(20)+5,me,ob);
            }
    }
    return 0;
}

