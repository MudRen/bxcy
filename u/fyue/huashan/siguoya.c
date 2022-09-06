// siguoya.c
// By Hop, 97.04.30
inherit ROOM;
void create()
{
    set("short", "˼����");
    set("long", @LONG
������ǻ�ɽ�ɵ����ܷ�˼���ĵط���λ����Ů�嶥��������һС��
ƽ�أ�һ������ɲ��ɽ�ȡ�һ���Ƕ��͵�����(bi)������������м�
��ɽʯ��
LONG
    );
    set("exits", ([ /* sizeof() == 2 */
        "northdown" : __DIR__"xiaojing",
    ]));
    set("outdoors", "huashan" );
    set("objects",([
    __DIR__"npc/laodenuo"   :   1,
    ]));
    set("item_desc", ([
        "bi" : "�㿴�ſ��ź�Ȼ������һ��ʯ���ϵ���̦�ȱ��ٵöࡣ������....\n",
    ]) );
    setup();
}
void init()
{
    add_action("do_break", "break");
}
int do_break(string arg)
{
    int n;
    object me = this_player();
    if( !arg || arg!="bi" )
    {
        write("��Ҫ��������˵Ķ�����\n");
        return 1;
    }
    message_vision("$N�ߵ�ʯ��ǰ���γ����������������˾���ʯ�ڴ��˹�ȥ��\n", this_player());
    if ((me->query("family/family_name") == "��ɽ��") && (me->query("family/master_id") == "feng qingyang"))
    {
        me->move(__DIR__"houshan");
        return 1;
    }
    n = (int)me->query("neili");
    if (n >= 2000)
    {
        message_vision(
        "$Nֻ��һ�����죬ʯ�ڱ�ͱ���ˣ�ԭ��������һ���󶴡���\n", this_player());
        set("exits/enter", __DIR__"houshan");
        this_player()->set("neili",n-2000);
        remove_call_out("close");
        call_out("close", 5, this_object());
    }
    else
    {
        message_vision(
        "���ֻ��һ���ƺߣ�$N��ʯ�ڵķ����������ǰһ��....\n", this_player());
        this_player()->set("neili",0);
        this_player()->unconcious();
    }
    return 1;
}
void close(object room)
{
    message("vision","���Ϻ�Ȼ������һ���ʯ�������ڷ��˸�����ʵʵ��\n", room);
    room->delete("exits/enter");
}