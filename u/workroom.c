//Room of wizard that haven't modify own workroom.
//Modify by Super 1998.1.2

inherit ROOM;

void create()
{
set("short","��ʦ������");


        set("long",@LONG
����û�н��칤���ҵ���ʦ����ʱס����������豸�ǳ��򵥣�
ֻ��һЩ������Ʒ��
LONG );
        set("exits",([ /* sizeof() == 1 */
                "gc":"/d/city/guangchang",
                "north":"/d/wizard/wizard_room" ]));
        set("valid_startroom", 1);
        set("no_fight", "1");
        set("no_clean_up", 0);
        setup();
}
void init()
 {
      add_action("do_kill","kill");
 }
int do_kill()
    {
       message_vision("$N��ɫһ����ȫ��ɢ����һ��Ũ�ҵ�ɱ����\n",this_player());
       return 0;
    }
int valid_leave(object me, string dir)
{
        if( dir=="north" && !wizardp(me) )
                return notify_fail("����ֻ����ʦ���ܽ�ȥ��\n");
        return ::valid_leave(me, dir);
}

