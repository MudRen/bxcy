#define OTHER_ROOM __DIR__"mengjin-dukou1.c"
#define DUCHUAN __DIR__"duchuan.c"

inherit ROOM;
int check_trigger();
void on_board();
void arrive();
void close_passage();
void reset();
void create()
{
    set("short", "�Ͻ򱱶ɿ�");
    set("long", @LONG
һ����ӿ���ȵĴ󽭺��������ǰ��ˮ���ϵ����д���˷���
�����Ĵ�����ʯ��ɵ���ͷ�ϡ�ʮ�����������ô����Ĵ��͹��Ŷ�
�������������������ȣ�������첱�ֵģ�С�ƶ��������ߺ����
���ɵĿ����ϴ���
LONG
    );
        set("exits", ([ 
  "north" : __DIR__"guandao3",
]));

    set("objects",([
        __DIR__"npc/zhangduo2":1,
]));
    set("outdoors", "mengjin");
    setup();
}

int check_trigger()
{
    object room;
    if(!query("exits/enter") ) {
        if( !(room = find_object(DUCHUAN)) )
            room = load_object(DUCHUAN);
        if( room = find_object(DUCHUAN) ) {
            if((int)room->do_check() && !room->query("yell") ) {
                set("exits/enter", DUCHUAN);
                room->set("exits/out", __FILE__);
                room->set("yell",1);
                message("vision", "һ�Ҷɴ�������ʻ�˹���������һ��̤��"
                    "����ϵ̰����Ա�˿����¡�\n", this_object() );
                message("vision", "����һ��̤�Ű���ϵ̰����γ�һ������"
                    "�Ľ��ݡ�\n", room);
                remove_call_out("on_board");
                call_out("on_board", 15);
            }else       return 0;       // ���ڶ԰�
        }else{
            message("vision", "ERROR: boat not found\n", this_object() );
            return 0;
        }
    }
    return 1;
}
void on_board()
{
    object room;
    if( !query("exits/enter") ) return;
    if ( NATURE_D->outdoor_room()){
        message("vision", "������˸���Ƿ����������ɫ���������ٹ����ɡ���\n",this_object() );
        return;
    }
    message("vision", "�����̤�Ű��������������һ�㣬�ɴ�����ʻȥ��\n",
        this_object() );
    delete("exits/enter");
    if( room = find_object(DUCHUAN) )
    {
        room->delete("exits/out");
    room->delete("yell");
        message("vision", "�����̤�Ű���������˵��һ��������ඡ���"
            "���һ�㣬�ɴ�����ʻȥ��\n", room );
    if (!(int)room->do_check()){
        remove_call_out("arrive");
        call_out("arrive", 20);
    }
    }
}
void arrive()
{
    object room;
    if( room = find_object(DUCHUAN) )
    {
        room->set("exits/out", OTHER_ROOM);
    room->set("yell",1);
        message("vision", "����˵���������ϰ��ɡ����漴��һ��̤�Ű���ϵ̰���\n",room );
    if( !room = find_object(OTHER_ROOM) )
    room = load_object(OTHER_ROOM);
    room->set("exits/enter", DUCHUAN);
    message("vision", "һ�Ҷɴ�������ʻ�˹���������һ��̤�Ű���ϵ̰����Ա�˿����¡�\n", room );
    remove_call_out("close_passage");
    call_out("close_passage", 10);
   }
}
void close_passage()
{
    object room;
    if( room = find_object(OTHER_ROOM) )
    room->on_board();
}
/* int valid_leave(object who,string dir)
{
        object ob=present("xiao zhangduo",this_object());
        if (dir=="enter"){
          if (!ob)      return notify_fail("���ϼ�λ��������µ���С�ƶ治�ڣ�"+RANK_D->query_respect(who)+"�Ȼ����ϴ��ա�\n");
          if (!living(ob))      return notify_fail("���ϼ�λ��������µ�����λ"+RANK_D->query_respect(who)+"��С�ƶ��������ߣ��Ƚ������ա�\n");
          if ( NATURE_D->outdoor_room())
             return notify_fail("С�ƶ�һ�µ��ڴ�ǰ���Բ������Ϲ���̫Σ���ˣ�\n");
          if ( !who->query_temp("rent_paid"))
             return notify_fail("С�ƶ�һ�µ��ڴ�ǰ������һ�����ٺ٣�����Ǯ�������\n");
        }
        who->delete_temp("rent_paid");
        return 1;
}
*/
