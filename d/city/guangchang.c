// Room: /city/guangchang.c
// YZC 1995/12/04 
inherit ROOM;

string look_notice();

void create()
{
    set("short", "����㳡");
    set("long", @LONG
    �����ǳ��е������ģ�һ���ܿ����Ĺ㳡��������ʯ���档һЩ���ֺ���
���������������������������������ݡ�������һ�ô��������̸����ڣ���
������ǧ������䣬���������е���ʷ��֤�����ɵײ���һ���ܴ�Ķ�(shudong)��
����Կ������������Ը��ص��������������������������У�һ�ɷ������󣬶���
��ʱ�ش������ʵĶ�������������������������ˣ�һƬ�ྲ�������Ϲ�һ�����
��NOTICE����
LONG
    );
        set("no_sleep_room",1);
        set("outdoors", "city");
    set("item_desc", ([
        "shudong" : "����һ���ڲ����еĴ󶴣����治֪����Щʲô�Ź֡�\n",
        "����"  :   "һ��֦Ҷïʢ�Ĵ������������ƺ�������(climb)��ȥ��\n",
        "������":   "һ��֦Ҷïʢ�Ĵ������������ƺ�������(climb)��ȥ��\n",
        "��"    :   "һ��֦Ҷïʢ�Ĵ������������ƺ�������(climb)��ȥ��\n",
        "tree"  :   "һ��֦Ҷïʢ�Ĵ������������ƺ�������(climb)��ȥ��\n",

                "notice" : (: look_notice :),

    ]));
    set("exits", ([
        "east" : __DIR__"dongdajie1",
        "south" : __DIR__"nandajie1",
        "west" : __DIR__"xidajie1",
        "north" : __DIR__"beidajie1",
"northwest" : __DIR__"mianju_r",	
"down" : __DIR__"drop",  	
    ]));
    set("objects", ([
        __DIR__"npc/liumang" : 2,
        __DIR__"npc/liumangtou" : 1,
//      __DIR__"obj/table" : 1,����2003-7-13�޸ģ���������ȥ
"d/city/npc/scavenger":2,
        "/clone/npc/halfgod":1,
        "/d/npc/xunbu":1,
    ]));
    setup();
}
void do_rumor(object me)
{
    if (!me)    return;
   if (!userp(me)) return;
//   CHANNEL_D->do_channel(this_object(),"rumor",me->name()+"�ڽ����㱼ѽ��");
else return;
}
void init()
{
    object me;
    me=this_player();
    if (!me->query_temp("armor/cloth") && me->query("race")=="����" ){
            if (time()-me->query_temp("rumor/nocloth")>10){
                me->set_temp("rumor/nocloth",time());
                call_out("do_rumor",random(5),me);
            }
        }
    if(me->is_ghost()){		
		write(BLU"ͻȻ�������������������һ��ն�������ɭ������:������Ӵ������Ӵ!��\n"NOR);
		write(HIW"һ���������������������ֻص��˹��Ź�\n"NOR);
	
		me->move("/d/death/gate");
		      }    
        
        add_action("do_enter", "enter");
        add_action("do_climb", "climb");
}
int do_enter(string arg)
{
    object me;
    me = this_player();
        if( !arg || arg=="" ) return 0;
        if( arg=="shudong" ) 
    {
        message("vision",
            me->name() + "һ�������������˽�ȥ��\n",
            environment(me), ({me}) );
                me->move("/d/gaibang/inhole");
                message("vision",
            me->name() + "�Ӷ������˽�����\n",
                    environment(me), ({me}) );
        return 1;
    }
}   
int do_climb(string arg)
{
    object me;
    mixed *local;
    local=localtime(time());
    me=this_player();
        if(local[6]==6&&!environment(me)->query("ok"))
    return notify_fail("�����ϲ�������̦,��������û�����ϵ�!\n");
        if( !arg || arg!="up") return notify_fail("��Ҫ���ĸ���������\n");
    if(me->query_condition("killer"))
    {
       message("vision",
        me->name() + "սս���������Ŵ��������̸���ƨ��һŤһŤ����������ͻȻһ���ҽУ��ֵ���������\n",
        environment(me), ({me}) );
        write("��սս���������Ŵ��������̸���������һ��С��ˤ�˸�����ʺ��\n");
        return 1;
     }
    if (me->query("gender")!="Ů��")
    message("vision",
        me->name() + "սս���������Ŵ��������̸���ƨ��һŤһŤ����������\n",
        environment(me), ({me}) );
    else if(me->query("age")<40&&me->query("per")>24)
    message("vision",
        me->name() + "����һ������ȹƮƮ�������Ӱ���ϴ�������\n",
        environment(me), ({me}) );
    else message("vision",
        me->name() + "սս������ץס����������ȥ��\n", environment(me), ({me}) );
                me->move(__DIR__"chatroom");
    if (me->query("gender")!="Ů��")
        message("vision",
        me->name() + "�������������������\n",
                environment(me), ({me}) );
    else if(me->query("age")<40&&me->query("per")>24)
    message("vision","һ������������㶨��һ����"+
        me->name() + "�Ѿ���������������ǰ��\n",
        environment(me), ({me}) );
    else  message("vision", me->name() + "սս�����ش���������������\n", environment(me), ({me}) );   
    return 1;
}   
string look_notice()
{
        object who;
        string *name_list, file;
        int i, j=0, k;
        who=this_player();
        file=read_file("/log/lunjian");
        if(!file)
                return "Ŀǰû���κα����¼��\n";
        name_list = explode(file,"\n");
        for(i=0;i<sizeof(name_list);i++) {
                if(name_list[i] == "seperator" ) {
                        j++;
                        k=0;
                        printf("\n��"+chinese_number(j)+"�컪ɽ�۽������\n");
                        continue;
                }
                k++;
                printf(GRN "��"+chinese_number(k)+"����%-50s\n" NOR, name_list[i]);
        }
        return "\n";
}
