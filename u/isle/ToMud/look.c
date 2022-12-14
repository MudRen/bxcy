// look.c
// colored by ReyGod in 1/10/1997 ----- I love colorful world :)

#pragma optimize
// #pragma save_binary

#include <room.h>
#include <ansi.h>
#include <combat.h>
#include <armor.h>
#include <tomud.h>
// flag of func:look_all_inventroy_of_room/ret_str
#define SHOW_IMMEDIATELY	0
#define RETURN_RESULT	   1

inherit F_CLEAN_UP;

int look_room(object me, object env, int brief);
int look_item(object me, object obj);
int look_living(object me, object obj);
int look_room_item(object me, string arg);
string look_equiped(object me, object obj, string pro);
string look_all_inventory_of_room(object me, object env, int ret_str);

mapping df_bkpic=([
"foshan":"xiaozheng",
"village":"xiaozheng",
"heimuya":"heimuya",
"huashan":"huashan",
"guanwai":"guanwai",
"lingjiu":"lingjiu",
"shenlong":"shenlong",
"taohua":"taohua",
"wudang":"wudang",
"xiakedao":"xiakedao",
"quanzhen":"quanzhen",
"beijing":"beijing",
"changan":"changan",
"city":"city",
"city3":"city3",
"dali":"dali",
"emei":"emei",]);

mapping rf_bkpic=([
"_d_beijing_dangpu":"dangpu",
"_d_changan_dangpu":"dangpu",
"_d_city_dangpu":"dangpu",
"_d_xiangyang_dangpu":"dangpu",
"_d_city_shuyuan":"shuyuan",
"_d_city_shuyuan2":"shuyuan",
"_d_suzhou_shuyuan":"shuyuan",
"_d_changan_zahuopu":"zahuopu",
"_d_beijing_huichuntang":"yaopu",
"_d_changan_yaopu":"yaopu",
"_d_suzhou_yaopu":"yaopu",
"_d_dali_yaoshop":"yaopu",
"_d_city_zuixianlou":"jiulou",
"_d_city_shuyuan":"shuyuan",
"_d_city_shuyuan2":"shuyuan",
"_d_suzhou_shuyuan":"shuyuan",
"_d_changan_zahuopu":"zahuopu",
"_d_fuzhou_zahuopu":"zahuopu",
"_d_beijing_huichuntang":"yaopu",
"_d_changan_yaopu":"yaopu",
"_d_dali_yaoshop":"yaopu",
"_d_city_zuixianlou":"jiulou",
"_d_emei_jinding":"jingding",
"_d_death_gate":"guimenguan",
"_d_beijing_qianzhuang":"qianzhuang",
"_d_city_qianzhuang":"qianzhuang",
"_d_changan_bank":"qiangzhuang",
"_d_beijing_qianzhuang":"qianzhuang",
"_d_city_qianzhuang":"qianzhuang",
"_d_beijing_dangpu":"dangpu",
"_d_xiangyang_dangpu":"dangpu",
]);


//add by JackyBoy@XAJH 2001/5/6
string get_bkpic(object env)
{
        string rf,df;
        rf=replace_string(base_name(env),"/","_");
        df=domain_file(rf);
        if(!undefinedp(rf_bkpic[rf]))
                return rf_bkpic[rf];
        if(!undefinedp(df_bkpic[df]))
                return df_bkpic[df];
        return "";
}

int info(object me, object env)
{
	string *dirs,df;
	mapping exits;

	if( mapp(exits = env->query("exits")) )
		dirs = keys(exits);

	if(sizeof(dirs)==1 && sizeof(dirs)!=0)
		write(TMI("bnway "+dirs[0]+";"));
	else if(sizeof(dirs)!=0)
		write(TMI( sprintf("bnway "+"%s;",implode(dirs[0..sizeof(dirs)], ";")) ));
        df=get_bkpic(env);
        if(df=="") return 1;
        if(df!=me->query_temp("bkpic"))
        {
                me->set_temp("bkpic",df);
                write(TMI("bkpic "+df));
        }
        return 1;
}

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	object obj;
	object env;
	int result;
	string objid, where;

	if (! arg) result = look_room(me, environment(me), 0);
	else
	{
		if (sscanf(arg, "%s of %s", objid, where) == 2)
		{
			if (where == "here")
				obj = present(objid, environment(me));
			else
			if (where == "me")
				obj = present(objid, me);
			else
			{
				env = present(where, environment(me));
				if (! objectp(env))
					return notify_fail("??????????????????\n");
				obj = present(objid, env);
				if (env->is_character() && env != me)
				{
					if (! objectp(obj) ||
					    ! obj->query("equipped") &&
					    env->query_temp("handing") != obj)
						return notify_fail("????????????????????????????????????\n");
					message("vision", me->name() + "????????" + obj->name() +
						"????????????????????????????????\n", env);
					message("vision", me->name() + "????" + env->name() + "??" +
						obj->name() + "????????????????????????????????\n",
						environment(me), ({ me, env }));
				}
			}

			if (! obj)
				return notify_fail("??????????????????\n");
		}

		if( obj || (obj = present(arg, environment(me))) || (obj = present(arg, me)) )
		{
			if( obj->is_character() && ! obj->is_corpse()) result = look_living(me, obj);
			else result = look_item(me, obj);
		} else result = look_room_item(me, arg);
	}

	return result;
}

int look_room(object me, object env, int brief)
{
	int i;
	mapping exits;
	string str, *dirs;
       object room;
	if( !env ) {
		tell_object(me, "??????????????????????????????????\n");
		return 1;
	}

	if( !brief )
	{
		str = sprintf( HIC + "%s" + NOR + "%s\n    %s%s" + NOR,
			env->short(),
			wizardp(me)? " - " + file_name(env): "",
			env->long(),
			env->query("outdoors") ? NATURE_D->outdoor_room_description() : "");
	} else
	{
		str = sprintf( HIC + "%s" + NOR + "%s\n" + NOR,
			env->short(),
			wizardp(me)? " - " + file_name(env): "");
	}

	if (mapp(exits = env->query("exits")) &&
	    (! brief || (intp(brief) && brief > 2)))
	{
		dirs = keys(exits);
		for(i=0; i<sizeof(dirs); i++)
			if ((int)env->query_door(dirs[i], "status") & DOOR_CLOSED )
				dirs[i] = 0;
		dirs -= ({ 0 });
		if (sizeof(dirs) == 0)
			str += "    ????????????????????????\n";
		else if (sizeof(dirs) == 1)
			str += "    ???????????????? " + HIY +
			       dirs[0] + NOR + "??\n";
		else
			str += sprintf("    ???????????????? " + HIY "%s" + NOR + " ?? " + HIY + "%s" + NOR + "??\n",
				implode(dirs[0..sizeof(dirs)-2], NOR+"??"+HIY), dirs[sizeof(dirs)-1]);
	}

        if (! me->query_temp("tomud")) // by Lonely
                str += look_all_inventory_of_room(me, env, RETURN_RESULT);
        else
	{
	        info(me, env); //By JackyBoy@XAJH 2001/5/6
	        str +=CLEAN0+ look_all_inventory_of_room(me, env, RETURN_RESULT);
        }
	tell_object(me, str);

        // ??????????????????
        if (me->query("env/show_map") && ! me->is_fighting())
        {
                if (mapp(exits = env->query("exits")))
                {
                        dirs = keys(exits);
                        for(i=0; i<sizeof(dirs); i++)
                                if ((int)env->query_door(dirs[i], "status") & DOOR_CLOSED)
                                        dirs[i] = 0;
                        dirs -= ({ 0 });
                        if (sizeof(dirs) != 0)
                        {
                        if ((int)me->query("env/show_map") == 2)
                        write(FRELINE(8, 40));
                        else write(ESC+"[r"+TOBOT(50));
                        write(SAVEC);

                        write(SETDISPLAY(7, 0) + DELLINE);
                        write(SETDISPLAY(1, 0) + DELLINE);
                        write(SETDISPLAY(2, 0) + DELLINE);
                        write(SETDISPLAY(3, 0) + DELLINE);
                        write(SETDISPLAY(4, 0) + DELLINE);
                        write(SETDISPLAY(5, 0) + DELLINE);
                        write(SETDISPLAY(6, 0) + DELLINE);

                        write(SETDISPLAY(4, 70) + HIR + filter_color(env->query("short")) + NOR);
                        for (i=0; i<sizeof(dirs); i++)
                        switch(dirs[i])
                        {
                        case "north":
                                write(SETDISPLAY(3, 72) + "??");
                                room = load_object(exits["north"]);
                                write(SETDISPLAY(2, 70) + filter_color(room->query("short")));
                                break;
                        case "up":
                                write(SETDISPLAY(3, 72) + "??");
                                room = load_object(exits["up"]);
                                write(SETDISPLAY(2, 70) + filter_color(room->query("short")));
                                break;
                        case "down":
                                write(SETDISPLAY(5, 72) + "??");
                                room = load_object(exits["down"]);
                                write(SETDISPLAY(6, 70) + filter_color(room->query("short")));
                                break;
                        case "south":
                                write(SETDISPLAY(5, 72) + "??");
                                room = load_object(exits["south"]);
                                write(SETDISPLAY(6, 70) + filter_color(room->query("short")));
                                break;
                        case "east":
                                room = load_object(exits["east"]);
                                write(SETDISPLAY(4, 80) + filter_color(room->query("short")));
                                write(SETDISPLAY(4, 78) + "??");
                                break;
                        case "west":
                                room = load_object(exits["west"]);
                                write(SETDISPLAY(4, 60) + filter_color(room->query("short")));
                                write(SETDISPLAY(4, 68) + "??");
                                break;
                        case "westup":
                                room = load_object(exits["westup"]);
                                write(SETDISPLAY(4, 60) + filter_color(room->query("short")));
                                write(SETDISPLAY(4, 68) + "??");
                                break;
                        case "eastup":
                                room = load_object(exits["eastup"]);
                                write(SETDISPLAY(4, 80) + filter_color(room->query("short")));
                                write(SETDISPLAY(4, 78) + "??");
                                break;
                        case "northup":
                                write(SETDISPLAY(3, 72) + "??");
                                room = load_object(exits["northup"]);
                                write(SETDISPLAY(2, 70) + filter_color(room->query("short")));
                                break;
                        case "southup":
                                write(SETDISPLAY(5, 72) + "??");
                                room = load_object(exits["southup"]);
                                write(SETDISPLAY(6, 70) + filter_color(room->query("short")));
                                break;
                         case "southdown":
                                write(SETDISPLAY(5, 72) + " ?? ");
                                room = load_object(exits["southdown"]);
                                write(SETDISPLAY(6, 70) + filter_color(room->query("short")));
                                break;
                        case "northdown":
                                write(SETDISPLAY(3, 72) + " ?? ");
                                room = load_object(exits["northdown"]);
                                write(SETDISPLAY(2, 70) + filter_color(room->query("short")));
                                break;
                        case "eastdown":
                                room = load_object(exits["eastdown"]);
                                write(SETDISPLAY(4, 80) + filter_color(room->query("short")));
                                write(SETDISPLAY(4, 78) + "??");
                                break;
                        case "westdown":
                                room = load_object(exits["westdown"]);
                                write(SETDISPLAY(4, 60) + filter_color(room->query("short")));
                                write(SETDISPLAY(4, 68) + "??");
                                break;
                        case "northwest":
                                write(SETDISPLAY(3, 68) + "??");
                                room = load_object(exits["northwest"]);
                                write(SETDISPLAY(2, 60) + filter_color(room->query("short")));
                                break;
                        case "southwest":
                                write(SETDISPLAY(5, 68) + "??");
                                room = load_object(exits["southwest"]);
                                write(SETDISPLAY(6, 60) + filter_color(room->query("short")));
                                break;
                        case "northeast":
                                write(SETDISPLAY(3, 76) + "??");
                                room = load_object(exits["northeast"]);
                                write(SETDISPLAY(2, 80) + filter_color(room->query("short")));
                                break;
                        case "southeast":
                                write(SETDISPLAY(5, 76) + "??");
                                room = load_object(exits["southeast"]);
                                write(SETDISPLAY(6, 80) + filter_color(room->query("short")));
                                break;
                        }

                        write(SETDISPLAY(1, 58) + "????????????????????????????????");
                        write(SETDISPLAY(2, 58) + "??");
                        write(SETDISPLAY(3, 58) + "??");
                        write(SETDISPLAY(4, 58) + "??");
                        write(SETDISPLAY(5, 58) + "??");
                        write(SETDISPLAY(6, 58) + "??");
                        write(SETDISPLAY(7, 58) + "????????????????????????????????");
                        write(SETDISPLAY(2, 88) + "??");
                        write(SETDISPLAY(3, 88) + "??");
                        write(SETDISPLAY(4, 88) + "??");
                        write(SETDISPLAY(5, 88) + "??");
                        write(SETDISPLAY(6, 88) + "??");

                        write(REST);
                        }
                write(TOBOT(50));
                }
        }

	return 1;
}

string desc_of_objects(object *obs)
{
	int i;

	string  str;
	mapping count;
	mapping unit;
	string  short_name;
	string  *dk;

	if (obs && sizeof(obs) > 0)
	{
		str = "";
		count   = ([]);
		unit    = ([]);

		for (i = 0; i < sizeof(obs); i++)
		{
			short_name = obs[i]->short();
			if (undefinedp(count[short_name]))
			{
				count += ([ short_name : 1 ]);
				unit += ([ short_name : obs[i]->query("unit") ]);
			}
			else
				count[short_name] += 1;
		}

		dk = sort_array(keys(count), 1);
		for (i = 0; i < sizeof(dk); i++)
		{
			str += "  ";
			if (count[dk[i]] > 1)
				str += chinese_number(count[dk[i]]) + unit[dk[i]];
			str += dk[i] + "\n";
		}
		return str;
	}

	return "";
}

string look_all_inventory_of_room(object me, object env, int ret_str)
{
	object *inv;
	object *obs;
	object ob;
	string  str;

	if (! env || ! me) return "";

	str = "";

	inv = all_inventory(env);
	if (! sizeof(inv)) return str;

	if (me->query_temp("tomud"))
	{
	        foreach(ob in inv)
	        if (ob != me && me->visible(ob))
	                str += ADD0(ob); //By JackyBoy@XAJH 2001/5/6
        }

	if (! me->query("env/brief") || (intp(me->query("env/brief")) &&
	    me->query("env/brief") > 1))
	{
		obs = filter_array(inv, (: $(me) != $1 && userp($1) && $(me)->visible($1) :));
		str += desc_of_objects(obs);

		obs = filter_array(inv, (: $(me) != $1 && ! userp($1) && $1->is_character() &&
					   $(me)->visible($1) :));
		str += desc_of_objects(obs);

		obs = filter_array(inv, (: ! $1->is_character() :), me);
		str += desc_of_objects(obs);
	}
	if (! ret_str)
		tell_object(me, str);

	return str;
}

int look_item(object me, object obj)
{
	object hob;
	mixed *inv;
	mapping count;
	mapping equiped;
	mapping unit;
	string short_name;

	string str;
	string *dk;
	int i;

	count   = ([]);
	unit    = ([]);
	equiped = ([]);

	str = obj->long();
	while (mapp(obj->query_temp("daub")))
	{
		if (! obj->query_temp("daub/poison/remain"))
			// no poison remain now
			break;

		if (obj->query_temp("daub/poison/id") == me->query("id"))
		{
			str += HIG "????????????????????????" +
			       obj->query_temp("daub/poison/name") +
			       HIG "????\n" NOR;
			break;
		}

		if (obj->query_temp("daub/who_id") == me->query("id"))
		{
			str += HIG "??????????????????????" +
			       obj->query_temp("daub/poison/name") +
			       HIG "????\n" NOR;
			break;
		}

		if (random(4) && random((int)me->query_skill("poison", 1)) < 30)
			// nothing was worked out
			break;

		str += HIG "????????????????????????????????????";
		if (me->query_skill("poison", 1) >= 120)
		{
			str += "????????" + obj->query_temp("daub/poison/name");
		}

		str += "??\n" NOR;
		break;
	}

	if (obj->query("consistence"))
		str += sprintf("????????" WHT "%d%%\n" NOR, obj->query("consistence"));

	inv = all_inventory(obj);
	if (! sizeof(inv))
	{
		message("vision", str, me);
		return 1;
	}

	if (obj->is_corpse())
	{
		if (objectp(hob = obj->query_temp("handing")))
		{
			if (hob->query_amount())
				str += "????????????????" + hob->query("base_unit") +
				       hob->name() + "??";
			else
				str += "????????????????" + hob->query("unit") +
				       hob->name() + "??";
			inv -= ({ hob });
			if (! sizeof(inv))
				str += "????????????????????\n";
			else
				str += "??????????????\n";
		} else
			str += "??????????????\n";
	} else
		str += "????????\n";

	for (i = 0; i < sizeof(inv); i++)
	{
		short_name = inv[i]->short();
		if (undefinedp(count[short_name]))
		{
			count += ([ short_name : 1 ]);
			unit += ([ short_name : inv[i]->query("unit") ]);
		}
		else
			count[short_name] += 1;

		if (inv[i]->query("equipped"))
			equiped[short_name] = 1;
	}

	dk = keys(count);
	dk = sort_array(dk, 1);
	for (i = 0; i < sizeof(dk); i++)
	{
	    if (equiped[dk[i]])
		str += HIC "  ??" NOR;
	    else
		str += "    ";

	    if (count[dk[i]] > 1)
		str += chinese_number(count[dk[i]]) + unit[dk[i]];
	    str += dk[i] + "\n";
	}

	if (strlen(str) > 4096)
		me->start_more(str);
	else
		message("vision", str, me);
	return 1;
}

string look_equiped(object me, object obj, string pro)
{
	mixed *inv;
	string str;
	string subs;
	object hob;
	int i;
	int n;

	inv = all_inventory(obj);
	n = 0;

	str = "";
	subs = "";
	for (i = 0; i < sizeof(inv); i++)
	{
		switch (inv[i]->query("equipped"))
		{
		case "wielded":
			n++;
			subs = HIC "  ??" NOR + inv[i]->short() + "\n" + subs;
			break;

		case "worn":
			n++;
			subs += HIC "  ??" NOR + inv[i]->short() + "\n";
			break;

		default:
			break;
		}
	}

	if (n)
		str += pro + "????????\n" + subs;

	if (objectp(hob = obj->query_temp("handing")) &&
	    (me == obj || obj->query_weight() > 200))
	{
		int mad;

		// dress nothing but handing a cloth !
		mad = (! objectp(obj->query_temp("armor/cloth")) &&
		       hob->query("armor_type") == "cloth");

		str = pro + "????" + (mad ? "??" : "" ) + "??????" +
		      (hob->query_amount() ? hob->query("base_unit")
					   : hob->query("unit")) +
		      hob->name() +
		      (mad ? "????????????????????\n" : "??\n") + str;
	}

	/*if (playerp(obj) && ! objectp(obj->query_temp("armor/cloth")))*/
       if (!obj->query_temp("armor/cloth") && obj->query("race")=="????" )
	{
		str = pro + "??????????????????\n" + str;
	}

	return str;
}

string description(object obj)
{
	/*if (playerp(obj))*/ if ( (string)obj->query("race")=="????" )
	{
	    int per;
	    int age;
	    per = obj->query_per();
	    age = obj->query("age");
	    if (obj->query("special_skill/youth")) age = 14;
	    if ((string) obj->query("gender") == "????" || (string) obj->query("gender") == "????")
	    {
		    if (per >= 30) return "????????????????????????????????????????????????????????????????\n";
		    if (per >= 26) return "??????????????????????????????????????????????????\n";
		    if (per >= 22) return "????????????????????????????????????????\n";
		    if (per >= 18) return "??????????\n";
		    if (per >= 15) return "????????????????????????\n";
				   return "????... ????????????????\n";
	    } else
	    {
		    if (per >= 30) return "??????????????????????????????????????????????????\n??????????????????????????????????????????????????????\n";
		    if (per >= 28) return "??????????????????????????????????????????????????\n??????????????????????????????????????????????????????????\n";
		    if (per >= 26) return "????????????????????????????????????????????????????????\n";
		    if (per >= 24) return "??????????????????????????????????????????????????????????\n";
		    if (per >= 21) return "??????????????????????????????????????????????????????\n";
		    if (per >= 18) return "??????????????????????\n";
		    if (per >= 15) return "????????... ????????????\n";
				   return "??????????????????????\n";
	    }
	} else
	if (! obj->query("can_speak") && living(obj))
	{
		if (! obj->query_temp("owner"))
			return "????????????????????????????????????????????\n";
		else
			return "????????" + obj->query_temp("owner_name") +
			       "??????????????????????????????\n";
	}

	return "";
}

int look_living(object me, object obj)
{
	int per;
	int age;
	string str="", pro, desc,icon;
	mapping my_fam, fam;
	int me_shen, obj_shen;
	mixed tmp;

	if( (tmp = obj->query("icon")))
	{
		if( intp(tmp) )
		{
			icon = sprintf("%d",tmp);
			str=L_ICON(icon);
		}
		else if( stringp(tmp) )
		{
			icon = tmp;
			str=L_ICON(icon);
		}
	}
	obj_shen = (int)obj->query("shen");
	per = obj->query_per();
	age = obj->query("age");
	pro = (obj==me) ? gender_self(obj->query("gender")) : gender_pronoun(obj->query("gender"));
       /*
	if (playerp(obj) && ! (obj->query("born")))
	{
		tell_object(me, pro + "??????????????????????????????????????????\n");
		return 1;
	}
        */
	me_shen = (int)me->query("shen");
	if (me != obj)
	{
		message("vision", me->name() + "????????????????????????????????\n", obj);
		message("vision", me->name() + "????" + obj->name() +
			"????????????????????????????????\n",
			environment(me), ({ me, obj }));
	}

	str += obj->long();
	if (me != obj && objectp(obj->query_temp("is_riding")))
		str += sprintf("%s??????%s????????????????\n", pro, obj->query_temp("is_riding")->name());

	if (obj->is_character() &&
	    obj->query("can_speak"))
	{
		// ??????????
		if (age >= 25 && obj->query("special_skill/youth"))
			str += pro + "????????????????????????????????????\n";
		else
		{
			if (age >= 200)
				str += pro + "????????????????????????????\n";
			else
			if (age < 10)
				str += pro + "????????????????\n";
			else
				str += pro + "????????" + chinese_number(age / 10 * 10) +
				       "??????\n";
		}
	}

	desc = description(obj);
	if (desc && desc != "")
		str += pro + desc;

	//check about wife and husband
	if (obj->query("id")== me->query("couple/id"))
	{
		// ????????
		if ((string)me->query("gender") == "????")
			str += sprintf("%s??????????????\n", pro);
		else
			str += sprintf("%s??????????????\n", pro);
	} else
	if (obj->is_brother(me))
	{
		// ????
		if (obj->query("gender") == "????")
		{
			if (obj->query("mud_age") > me->query("mud_age"))
				str += sprintf("%s????????????\n", pro);
			else
				str += sprintf("%s????????????????\n", pro);
		} else
		{
			if (obj->query("mud_age") > me->query("mud_age"))
				str += sprintf("%s????????????????\n", pro);
			else
				str += sprintf("%s????????????\n", pro);
		}
	} else
	if (obj != me && obj->query("league") &&
	    obj->query("league/league_name") == me->query("league/league_name"))
	{
		str += sprintf("%s????????%s????????????\n", pro,
			       obj->query("league/league_name"));
	}

        if (obj != me && obj->query("bunch") && stringp(obj->query("bunch/bunch_name")) &&
            obj->query("bunch/bunch_name") == me->query("bunch/bunch_name"))
        {
                str += sprintf("%s????????%s????????%s??????????????%s??", pro,
                               obj->query("bunch/bunch_name"), pro,
                               stringp(obj->query("bunch/title")) ? obj->query("bunch/title") : "????");
                if (obj->query("bunch/level") > me->query("bunch/level"))
                        str += "????????????\n";
                else
                if (obj->query("bunch/level") == me->query("bunch/level"))
                        str += "??????????????\n";
                else
                        str += "????????????\n";
        } else
        if (obj != me && obj->query("bunch") && stringp(obj->query("bunch/bunch_name")) &&
            obj->query("bunch/bunch_name") != me->query("bunch/bunch_name"))
        {
                str += sprintf("%s????????%s??%s??\n", pro,
                               obj->query("bunch/bunch_name"),
                               stringp(obj->query("bunch/title")) ? obj->query("bunch/title") : "????");
        }

	// If we both has family, check if we have any relations.
	if (obj != me &&
	    mapp(fam = obj->query("family")) &&
	    mapp(my_fam = me->query("family")) &&
	    fam["family_name"] == my_fam["family_name"])
	{

		if (fam["generation"] == my_fam["generation"])
		{

			if ((string)obj->query("gender") == "????" ||
				(string)obj->query("gender") == "????")
				str += sprintf( pro + "??????%s%s??\n",
					my_fam["master_id"] == fam["master_id"]? "": "????",
					my_fam["enter_time"] > fam["enter_time"] ? "????": "????");
			else
				str += sprintf( pro + "??????%s%s??\n",
					my_fam["master_id"] == fam["master_id"]? "": "????",
					my_fam["enter_time"] > fam["enter_time"] ? "????": "????");
		} else
		if (fam["generation"] < my_fam["generation"])
		{
			if (my_fam["master_id"] == obj->query("id"))
				str += pro + "????????????\n";
			else
			if (my_fam["generation"] - fam["generation"] > 1)
				str += pro + "????????????????\n";
			else
			if (fam["enter_time"] < my_fam["enter_time"])
				str += pro + "????????????\n";
			else
				str += pro + "????????????\n";
		} else
		{
			if (fam["generation"] - my_fam["generation"] > 1)
				str += pro + "????????????????\n";
			else
			if (fam["master_id"] == me->query("id"))
				str += pro + "????????????\n";
			else
				str += pro + "????????????\n";
		}
	}

	if (obj->is_chatter())
	{
		message("vision", str, me);
		return 1;
	}

	if (stringp(obj->query_temp("eff_status_msg")))
	{
		str += obj->query_temp("eff_status_msg") + "\n";
	} else
	if (obj->query("max_qi"))
		str += pro + COMBAT_D->eff_status_msg((int)obj->query("eff_qi")* 100 / (int)obj->query("max_qi")) + "\n";

	if (obj->query_temp("daub/poison/remain") &&
	    (me == obj || random((int)me->query_skill("poison", 1)) > 80))
	{
		str += pro + HIG "????????" + (me == obj ? "" : "????") +
		       "????" + (me == obj ? obj->query_temp("daub/poison/name") : "??") +
		       NOR "??\n";
	}

	str += look_equiped(me, obj, pro);
	message("vision", str, me);

	if (obj != me && living(obj) &&
	    ! me->is_brother(obj) &&
	    me->query("couple/id") != obj->query("id") &&
	    (((me_shen < 0) && (obj_shen > 0)) ||
	     ((me_shen > 0) && (obj_shen < 0))) &&
	    (((me_shen - obj_shen) > ((int)obj->query("max_neili") * 20)) ||
	     ((obj_shen - me_shen) > ((int)obj->query("max_neili") * 20))))
	{
		tell_object(me, obj->name() + "??????????????????????\n");
		if (obj->query("age") > 15 && me->query("age") > 15)
		   if (! wizardp(obj) && ! wizardp(me))
			COMBAT_D->auto_fight(obj, me, "berserk");
	}

	return 1;
}

int look_room_item(object me, string arg)
{
	object env;
	mapping item, exits;

	if (! objectp(env = environment(me)))
		return notify_fail("??????????????????????????????????\n");
	if (mapp(item = env->query("item_desc")) && !undefinedp(item[arg]))
	{
		if (stringp(item[arg]))
			tell_object(me, item[arg]);
		else
		if(functionp(item[arg]))
			tell_object(me, (string)(*item[arg])(me));

		return 1;
	}
	if (mapp(exits = env->query("exits")) && ! undefinedp(exits[arg]))
	{
		if (objectp(env = find_object(exits[arg])))
			look_room(me, env, 0);
		else
		{
			call_other(exits[arg], "???");
			look_room(me, find_object(exits[arg]), 0);
		}
		return 1;
	}
	return notify_fail("????????????\n");
}

int help(object me)
{
	write(@HELP
????????: look [<????>|<????>|<????>]

????????????????????????????????????????????????????????????
??look??????????????????????????????????????????????????????
????????????????????????????????????????????????????????????
????????ID??????????????????????look ??? of me/here ????????
????????????????????????????????????????????????????????????
?? look ??? of <id> ??????????????????????????????????

HELP
);
	return 1;
}
