
#pragma save_binary

#include <dbase.h>
#include <room.h>

nosave int weight = 0;
nosave int encumb = 0, max_encumb = 0;

// ��ѯЯ����Ʒ������
nomask int query_encumbrance()
{
    return encumb;
}

// ����
nomask int over_encumbranced()
{
    return encumb > max_encumb;
}

// ��ѯ��Я����Ʒ���������
nomask int query_max_encumbrance()
{
    return max_encumb;
}

// ��¼��Я����Ʒ���������
nomask void set_max_encumbrance(int e)
{
    max_encumb = e;
}

// ��������
nomask void add_encumbrance(int w)
{
    encumb += w;

    if (encumb < 0)
        log_file("move.bug", sprintf("%O encumbrance underflow.\n", this_object()));

    if (encumb > max_encumb)
        this_object()->over_encumbrance();

    if (environment())
        environment()->add_encumbrance(w);
}

void over_encumbrance()
{
    if (! interactive(this_object()))
        return;

    tell_object(this_object(), "��ĸ��ɹ����ˣ�\n");
}

nomask int query_weight()
{
    return weight;
}

nomask void set_weight(int w)
{
    if (! environment())
    {
        weight = w;
        return;
    }

    if (w != weight)
        environment()->add_encumbrance(w - weight);

    weight = w;
}

// This is the "current" weight of an object, which is used on weight
// checking in move().
nomask int weight()
{
    return weight + encumb;
}

varargs int move(mixed dest, int silently)
{
    mapping exits, my;
    object  ob, env, obj;
    string  str, *dirs;
    int     i;
    object user,*users;

    // If we are equipped, unequip first.
    if (query("equipped") && ! this_object()->unequip())
        return notify_fail("��û�а취ȡ������������\n");

    // Find the destination ob for moving.
    if (objectp(dest))
        ob = dest;
    else
    if (stringp(dest))
    {
//        call_other(dest, "???");
        ob = load_object(dest);
        if (! objectp(ob))
            return notify_fail("move: destination unavailable.\n");
    } else
        return notify_fail(sprintf("move: invalid destination %O.\n", dest));

    // Check if the destination ob can hold this object.
    // Beforce checking it, we check if the destination is environment of
    // this_object() (or environment of its environment). If it is, then
    // this could be like get something from a bag carried by the player.
    // Since the player can carry the bag, we assume he can carry the this
    // object in the bag and encumbrance checking is unessessary.
    env = this_object();

    while(env = environment(env))
        if (env == ob)
            break;

    if (! env && sizeof(all_inventory(ob)) > 50 && userp(ob))
    {
        if (ob == this_player())
        {
            tell_object(ob, "�����ϵĶ���̫���ˣ�\n");
            return notify_fail(this_object()->name() + "�������̫���ˡ�\n");
        }
        else
            return notify_fail(this_object()->name() + "��" + ob->name() + "����̫���ˡ�\n");
    }

    if (! env &&
        (int) ob->query_encumbrance() + weight()  > (int) ob->query_max_encumbrance())
    {
    	if (silently && environment(ob))
    	{
    		message_vision("����$n����$N����ʵ��"
    		"��̫���ˣ�ֻ��������һ�ԡ�\n",
    		ob, this_object());
    		ob = environment(ob);
    		} else {
        if (ob == this_player())
            return notify_fail(this_object()->name() + "�������̫���ˡ�\n");
        else
            return notify_fail(this_object()->name() + "��" + ob->name() + "����̫���ˡ�\n");
          }
    }
env = environment();
 if(!wizardp(this_object())||!query("env/invisibility"))
        {
                if (env)
                {
                        env->add_encumbrance(-weight());
                        if (userp(env) && env->query_temp("tomud")) 
                                tell_object(env, REM1(this_object())); //................REM1
                        else 
                        if (! living(env))
                        {
                                users = filter_array(all_inventory(env),  
                                                     (: (userp($1) && $1->query_temp("tomud")) :)) - 
                                                     ({ this_object() });  
                                if (sizeof(users) > 0) 
                                foreach (user in users)  
                                        tell_object(user, REM0(this_object()));                          
                                
                              //  tell_room(env,REM0(this_object()),this_object() );
                                // ...............REM0
                        }
                        // else log_file("move.log",ctime(time())+"........REM..---"+base_name(env)+"\n");
                }
                if (ob)
                {
                        ob->add_encumbrance(weight());
                        if ((userp(ob)|| interactive(ob)) && ob->query_temp("tomud")) 
                                tell_object(ob, ADD1(this_object()) ); 
                                // ...............ADD1
                        else 
                        if (! ob->is_character()) 
                        {
                                users = filter_array(all_inventory(ob),  
                                                     (: (userp($1) && $1->query_temp("tomud")) :)) - 
                                                     ({ this_object() });  
                                if (sizeof(users) > 0) 
                                foreach (user in users)  
                                        tell_object(user, ADD0(this_object()));    
                               // tell_room(ob, ADD0(this_object()),this_object() );
                                // ..............ADD0         
                        }  
                }
        }

    move_object(ob);

    // If we are players, try look where we are.
    if (interactive(this_object())          // are we linkdead?
        && living(this_object())            // are we still concious?
        && objectp(env = environment())
        && ! silently)
    {
        ob = this_object();

        if (! intp(query("env/brief")))
            set("env/brief", 0);

        if ((int) query("env/brief") == 1)
            tell_object(ob, HIW + environment()->query("short") + NOR + "\n");
        else
        if ((int) query("env/brief") > 1)
        {
            str = NOR + "\n";
            exits = environment()->query("exits");
            if (! sizeof(exits))
                str += "    ����û���κ����Եĳ�·��\n";
            else
            {
                dirs = keys(exits);
                for (i = 0; i < sizeof(dirs); i++)
                    if ((int) environment()->query_door(dirs[i], "status") & DOOR_CLOSED)
                        dirs[i] = 0;

                dirs -= ({ 0 });

                if (! sizeof(dirs))
                    str += "    ����û���κ����Եĳ�·��\n";
                else
                if (sizeof(dirs) == 1)
                    str += "    ����Ψһ�ĳ����� " + BOLD + dirs[0] + NOR + "��\n";
                else
                    str += sprintf("    �������Եĳ����� " + BOLD + "%s" + NOR +
                           " �� " + BOLD + "%s" + NOR + "��\n",

                implode(dirs[0..sizeof(dirs)-2], "��"), dirs[sizeof(dirs)-1]);
            }

            if ((int) query("env/brief") == 2)
            {
                tell_object(ob, HIW + environment()->query("short") + str + NOR + "\n");
            } else
            {
                obj = first_inventory(env);
                while (obj)
                {
                    reset_eval_cost();
                    if (obj == this_object() || ! this_object()->visible(obj))
                    {
                        obj = next_inventory(obj);
                        continue;
                    }

                    if (obj->query("money_id") ||
                        ! obj->query("unit") ||
                        obj->is_character())
                    {
                        str += sprintf("    %s\n", obj->short());
                        obj = next_inventory(obj);
                        continue;
                    }

                    if (! mapp(my))
                        my = ([ obj->query("unit") + obj->short() : 1 ]);
                    else
                    {
                        i = my[obj->query("unit") + obj->short()];
                        my[ obj->query("unit") + obj->short() ] = i + 1;
                    }

                    obj = next_inventory(obj);
                }

                if (mapp(my))
                {
                    dirs = keys(my);
                    for (i = 0; i < sizeof(my); i++)
                            str += sprintf("    %s%s\n",
                            my[ dirs[i]] == 1 ? "" : CHINESE_D->chinese_number(my[dirs[i]]),
                            my[ dirs[i]] == 1 ? dirs[i][2..] : dirs[i]);
                }

                tell_object(ob, HIW + environment()->query("short") + str + NOR + "\n");
            }
        } else
            command("look");
    }
    return 1;
}

void remove(string euid)
{
    object me, ob, default_ob;
	object user;
	object *users;

	ob = environment();
	me = this_object();

    if (! previous_object() ||
        base_name(previous_object()) != SIMUL_EFUN_OB)
        error("move: remove() can only be called by destruct() simul efun.\n");

    if (userp(this_object()))
        this_object()->save();

    if (this_object()->query("equipped"))
    {
        if (!this_object()->unequip())
            log_file("destruct", sprintf("Failed to unequip %s when destructed.\n",
                    file_name(this_object())));
    }

    // We only care about our own weight here, since remove() is called once
    // on each destruct(), so our inventory (encumbrance) will be counted as
    // well.
    if (ob)
    {
		if (userp(ob) && ob->query_temp("tomud"))
			tell_object(ob, REM1(me) ); //����Ǵ���������ƶ��ߣ���Ӧ����REM1
		else 
		if (! living(ob) && ! ob->is_character())
	        {
                        users = filter_array(all_inventory(ob),  
                                            (: (userp($1) && $1->query_temp("tomud")) :)) - 
                                            ({ me });  
                        if (sizeof(users) > 0) 
                        foreach (user in users)  
                                tell_object(user, REM0(me)); 
                      //   tell_room(ob, REM0(me), me );//����Ǵӷ������ƶ��ߣ���Ӧ����REM0                         			     
	        }
		}
	if (environment())
	    environment()->add_encumbrance(-weight);

    if (default_ob = this_object()->query_default_object())
        default_ob->add("no_clean_up", -1);

}

int move_or_destruct(object dest)
{
    if (userp(this_object()))
    {
        tell_object(this_object(), "һ��ʱ�յ�Ť�����㴫�͵���һ���ط�....\n");
        move(VOID_OB);
    }
}
