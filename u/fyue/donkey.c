// donkey.c Сë¿
inherit ITEM;

mapping default_dirs = ([ 
        "north":       "��",
        "south":       "��",
        "east":        "��",
        "west":        "��",
        "northup":     "����",
        "southup":     "�ϱ�",
        "eastup":      "����",
        "westup":      "����",
        "northdown":   "����",
        "southdown":   "�ϱ�",
        "eastdown":    "����",
        "westdown":    "����",
        "northeast":   "����",
        "northwest":   "����",
        "southeast":   "����",
        "southwest":   "����",
        "up":          "��",
        "down":        "��",
        "enter":       "��",
        "out":         "��",
]);

mapping ride_dirs = ([ 
        "north":       "��",
        "south":       "��",
        "east":        "��",
        "west":        "��",
        "northup":     "�ϱ�",
        "southup":     "����",
        "eastup":      "����",
        "westup":      "����",
        "northdown":   "�ϱ�",
        "southdown":   "����",
        "eastdown":    "����",
        "westdown":    "����",
        "northeast":   "����",
        "northwest":   "����",
        "southeast":   "����",
        "southwest":   "����",
        "up":          "��",
        "down":        "��",
        "enter":       "��",
        "out":         "��",
]);

void setup()
{}

void init()
{
    add_action("do_go","go");
    add_action("do_ride","ride");
    add_action("do_unride","unride");
}

void create()
{
    set_name("Сë¿", ({"donkey", "maolu", "lu"}));
    set_weight(15000);
    set_max_encumbrance(20000);
    if (clonep())
        set_default_object(__FILE__);
    else
    {
        set("unit", "ƥ");
        set("long", "һƥ��ɫ��Сë¿�������Ҳ�����Զ�����\n");
        set("value", 400);
    }
}

int do_ride(string arg)
{
	object me = this_player();
    if (!id(arg))
        return notify_fail("��Ҫ��ʲô��\n");
    if (this_player()->query_temp("marks/ride") )
    {
       write("���Ѿ����������ˡ���������¿?!\n");
       return 1;
    }
    else
    {
    	if(this_player()->query_skill("dodge",1) < 60 )
		{
    		message("vision",this_player()->name() + "������¿��ë¿һ�����ӣ�"
               "�ְ�"+this_player()->name() + "����¿����\n",environment(me), ({me}) );
    		write("������ë¿�������������\n");
    		return 1;
    	}
    	else
    	{
    		message("vision",this_player()->name() + "����ץסë¿��һƫ��������ȥ��"
               "ë¿�ܲ����˵ع��˹�����\n",environment(me), ({me}) );
            this_player()->set_temp("marks/ride",1);
    		return 1;
    	}
    }
}

int do_go(string arg)
{
    string dest, mout, min, dir,ride_dir;
    mapping exit;
	object me,env,obj,*f_obs, *ob;
    int count = 0, my_dex, i;

	me = this_player();
    env = environment(me);
    exit = env->query("exits");

    if(!me->query_temp("marks/ride")) return 0;
    if(!env)
    {
        write("������Ҳȥ���ˡ�\n");
        return 1;
    }
    switch(arg)
    {
        case "north":     arg="south";break;
        case "south":     arg="north";break;
        case "east":      arg="west";break;
        case "west":      arg="east";break;
        case "northup":   arg="southdown";break;
        case "southup":   arg="northdown";break;
        case "eastup":    arg="westdown";break;
        case "westup":    arg="eastdown";break;
        case "northdown": arg="southup";break;
        case "southdown": arg="northup";break;
        case "eastdown":  arg="westup";break;
        case "westdown":  arg="eastup";break;
        case "northeast": arg="southwest";break;
        case "northwest": arg="southeast";break;
        case "southeast": arg="northwest";break;
        case "southwest": arg="northeast";break;
        case "up":        arg="down";break;
        case "down":      arg="up";break;
        case "enter":     arg="out";break;
        case "out":       arg="enter";break;
        default:          arg="none";break;
    }
    if( !mapp(exit) || undefinedp(exit[arg]) )
    {
        write("Сë¿ƴ������һ��ûȥ·�ķ��򼷡�\n");
        return 1;
    }
    if( me->over_encumbranced() )
    {
        write("��ĸ��ɹ��أ�Сë¿һ��Ҳ�߲�����\n");
        return 1;
    }
    if( me->is_busy() )
    {
        write("��Ķ�����û����ɣ�û����¿��\n");
        return 1;
    }
    if (me->is_fighting())
    {
        f_obs = me->query_enemy();
        if (objectp(f_obs[0]))
        if (5 + random((int)me->query("dex")) <=  random((int)f_obs[0]->query("dex")))
        {
            me->start_busy(1);
            message_vision("$N���Ʋ��ã���ת¿ͷҪ�ߣ���$nһ������ǰ�档���ߣ�û��ô���ף�\n", me, f_obs[0]);
            write("������ʧ�ܡ�\n");
            return 1;
        }
    }
    dest = exit[arg];
    if( !(obj = find_object(dest)) )
        call_other(dest, "???");
    if( !(obj = find_object(dest)) )
    {
        write("�޷��ƶ���\n");
        return 1;
    }
    if(!obj->query("long") || !obj->query("short") || !obj->query("exits"))
    {
        destruct(obj);
        call_other(dest,"???");
        if( !(obj = find_object(dest)) )
        {
            write("�޷��ƶ���\n");
            return 1;
        }
    }
    if( !env->valid_leave(me, arg) ) return 1;
    if( !undefinedp(default_dirs[arg]) )
    {
        dir = default_dirs[arg];
        ride_dir = ride_dirs[arg];
    }
    else
        dir = arg;

    if( me->is_fighting() )
    {
        mout = me->name() + "��¿��"+ride_dir+"һ����ë¿�͵���" + dir + "��Ķ����ˡ�\n";
        min = me->name() + "����¿��һ��һ�ߵ��Ǳ������˹�����\n";
    }
    else
    {
        mout = "һ���˰�¿��"+ride_dir+"һ����ë¿ȴ��ͷ��" + dir + "�뿪��\n";
        min  = "һ��������¿�����ˡ�\n";
    }
    message( "vision", mout, environment(me), ({me}) );
    if( me->move(obj) )
    {
        me->remove_all_enemy();
        message( "vision", min, environment(me), ({me}) );
        me->set_temp("pending", 0);
        all_inventory(env)->follow_me(me, arg);
        return 1;
    }
    return 0;
}
