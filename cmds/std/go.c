// go.c
// #pragma save_binary
inherit F_CLEAN_UP;

mapping default_dirs = ([
	"north":	"北方",
	"south":	"南方",
	"east":		"东方",
	"west":		"西方",
	"northup":	"北边",
	"southup":	"南边",
	"eastup":	"东边",
	"westup":	"西边",
	"northdown":	"北边",
	"southdown":	"南边",
	"eastdown":	"东边",
	"westdown":	"西边",
	"northeast":	"东北",
	"northwest":	"西北",
	"southeast":	"东南",
	"southwest":	"西南",
	"up":		"上面",
	"down":		"下面",
	"enter":	"里面",
	"out":		"外面",
	"leitai":	"擂台上面",
]);

void create() { seteuid(getuid()); }
int jing,m_jing,eq,mq;
int main(object me, string arg)
{
	string dest, mout, min, dir, face, thing_msg;
	object env, obj,obj1, thing;


	mapping exit;


        eq = me->query("eff_qi");
	mq = me->query("max_qi");
	jing = me->query("jing");
	m_jing = me->query("max_jing");
	reset_eval_cost();
	if( !arg ) return notify_fail("你要往哪个方向走？\n");

	if(me->is_ghost()&&domain_file(base_name(environment(me)))!="death")
		{
			tell_object( me,RED "\n\n侮天鬼王突然在一阵烟雾中出现。\n\n"
			"\n\n侮天鬼王喝道：鬼魂也乱跑!!! 连我也看不惯了，滚吧!!!\n\n" NOR);
			destruct(me);
			return 1;
		}

	if( me->over_encumbranced() )
		return notify_fail("你的负荷过重，动弹不得。\n");

	if( me->is_busy() )
		return notify_fail("你的动作还没有完成，不能移动。\n");

	env = environment(me);
	if(!env) return notify_fail("你哪里也去不了。\n");


	if( !mapp(exit = env->query("exits")) || undefinedp(exit[arg]) ) {
        if( query_verb()=="go"){
		    if(!environment(me)->query("outdoors")&&(int)me->query("qi")>10&&(int)me->query("jing")>10){if((int)me->query("qi") > (int)me->query("max_qi")/2)
		       {
		       	me->add("jing",-1);
		       	me->add("qi",-3);
          write( "哎哟， 你一不小心撞到了墙壁!\n" );
			return 1;
		}
		       else { me->add("qi",-3);
          write("哎哟， 你一不小心撞到了墙壁!\n" );
		              return 1;
		        }}
		      else  return notify_fail("这个方向没有出路。\n");}
		else
			return 0;
	}


	dest = exit[ arg ];

	if( !(obj = load_object(dest)) )
	{
	   if(file_size(file_name(environment(me))+".c")>0)
	   {
	   message("channel:wiz",HIG"\n〖地图精灵〗 区域："+environment(me)->query("short")+"("+file_name(environment(me))+")"+"连接有错，请速更正。\n\n"NOR,users());
	   log_file("map_error","区域："+environment(me)->query("short")+"("+file_name(environment(me))+")"+"连接有错，请速更正。\n");
	   }
           write( "你要去的区域还没有连通,请通知管理人员。\n");
           return 1;
        }
           if ( !(obj = find_object(dest)) )
	    	return notify_fail( sprintf( "无法向 %s 移动。\n", dest ) );
	obj1 = find_object(dest);

	if(obj1->query("wiz_only")&&!wizardp(me))
	   return notify_fail("那里只有管理人员才能进去！\n");
	if(obj1->query("building"))
	   return notify_fail("那里还在施工，请以后再来。\n");


	if( !env->valid_leave(me, arg) ) return 0;
	if( !undefinedp(default_dirs[arg]) )
		dir = default_dirs[arg];
	else
		dir = arg;

	if( me->is_fighting() ) {
		mout = me->name() + "往" + dir + "落荒而逃了。\n";
		min = me->name() + "跌跌撞撞地跑了过来，模样有些狼狈。\n";
	}
	 else if( wizardp(me) && me->query("env/invisibility") && me->query("env/msg_off"))
            {
             mout = "";
             min = "";
              }
// end of part
         else {
		face="的";
                if( me->query("gender") == "女性") {
//			mout = "一条倩影往" + dir + "离开。\n";
//			min = "一条倩影走了过来。\n";
			if (me->query("per") >= 35) face ="娇艳绝伦" + face;
			if ((me->query("per") >= 32) && (me->query("per") < 30)) face= "清丽绝俗" + face;
			if ((me->query("per") >= 26) && (me->query("per") < 28)) face= "风情万种" + face;
			if ((me->query("per") >= 24) && (me->query("per") < 26)) face= "容色秀丽" + face;
			if ((me->query("per") >= 21) && (me->query("per") < 24)) face= "面目姣好" + face;
			if ( me->query("per") < 21)
			{
			if (me->query("str") <= 16) face = "亭亭玉立" + face;
			if ((me->query("str") <= 20) && (me->query("str") > 16)) face= "体态轻盈"+ face;
			if ((me->query("per")<21) && (me->query("str")>20) || !userp(me)) face = "";
			}
		}
                else {
//			mout = "一条人影往" + dir + "离开。\n";
//			min = "一条人影走了过来。\n";
			if (me->query("per") >= 30) face= "玉树临风般" + face;
			if ((me->query("per") >= 26) && (me->query("per") < 30)) face="英俊潇洒" + face;
			if ((me->query("per") >= 22) && (me->query("per") < 26)) face="仪表堂堂" + face;
			if (me->query("per") < 22)
			{
			if (me->query("str") >=23) face = "膀大腰圆" + face;
			if ((me->query("str") >= 15) && (me->query("str") < 23)) face= "身材壮硕"+ face;
			if ((me->query("per") < 22) && (me->query("str") < 15) || !userp(me)) face = "";
			}
		}
	        if (objectp(thing = me->query_temp("armor/cloth")))
			thing_msg = "身着" + thing->query("name");
		else
			thing_msg = "全身清洁溜溜";
	        if (objectp(thing = me->query_temp("weapon")))
			thing_msg += "手执" + thing->query("name");
		if ( me->query("race") == "野兽")
		{
			mout = me->name() + "呼地往" + dir + "一窜就消失了。\n";
			min = me->name() + "呼地窜了出来，警惕地四周张望着。\n";
		}
		else
		{
			if ( me->query_temp("is_riding"))
			{
				mout = me->name()+"骑着"+me->query_temp("is_riding")+"向" + dir + "疾驰而去。\n";
				min = face + me->name() + thing_msg + "骑着"+me->query_temp("is_riding")+"一路疾驰而来。\n";
			}

			else if(100*jing/m_jing<=20)
			{
				mout = me->name()+"摇摇晃晃的向"+dir+"走去，眼看就要倒下。\n";
				min = me->name()+"摇摇晃晃的走了过来，就快累得趴下了。\n";
			}
			else if(100*jing/m_jing<=40)
			{
				mout = me->name()+"拖着疲惫的脚步往"+dir+"离开。\n";
				min = face+me->name()+"疲惫不堪的走了过来。\n";
			}
			else if(100*jing/m_jing<=70)
			{
				mout = face +me->name()+"迈着沉重的脚步往"+dir+"离开。\n";
				min = me->name()+thing_msg+"疲惫的走了过来。\n";
			}
			else if(100*eq/mq<=30 )
			{
                                mout = me->name()+"不住地呻吟，拖着遍体鳞伤的残体向" + dir + "爬去。地上赫然留下一道道斑斑的"+HIR"血迹"NOR+"。\n";
                                min =me->name()+ "不住地呻吟，拖着遍体鳞伤的残体爬了过来。\n";
                        }
                        else if(100*eq/mq<=50 )
                        {
                                mout = me->name()+"撑起满是"+HIR"鲜血"NOR+"的躯体，一瘸一拐地朝" + dir + "挪去。\n";
                                 min =me->name()+"撑着满是"+HIR"鲜血"NOR+"的躯体，一瘸一拐地挪了过来。\n";
                         }
                         else if(100*eq/mq<=70)
                         {
                                mout = me->name()+"一边擦着嘴角的"+HIR"鲜血"NOR+"，一边朝" +dir+"走去。\n";
                                min = me->name()+"一边擦着嘴角的"+HIR"鲜血"NOR+"，一边走了过来，龇牙咧嘴的。\n";
                         }
                         else if(100*eq/mq<=90 )
                         {
                                mout = face+me->name()+"灰头土脸、狼狈不堪地向"+dir+"离去。\n";
                                 min = me->name()+thing_msg+"灰头土脸、狼狈不堪地走了过来。\n";
                          }
                          else if(100*eq/mq<=95)
                          {
                                mout = me->name()+"一声不吭的转身朝"+dir+"走去，脸色好像有些难看。\n";
                                min = me->name()+"像斗败了的公鸡，垂头丧气地走了过来。\n";
                           }
                           else if ( arg == "leitai")
			{
				mout = me->name()+"双腿力蹬，纵起身形，轻轻跃上擂台。\n";
				min = me->name()+"从擂台下一跃而起，稳稳地落在台上。\n";
			}
			else
			{
				mout = me->name() + "往" + dir + "离开。\n";
				min = face + me->name() + thing_msg + "走了过来。\n";
			}
		}
	}

	message( "vision", mout, environment(me), ({me}) );
	if( me->move(obj) ) {
		me->remove_all_enemy();
		message( "vision", min, environment(me), ({me}) );
		me->set_temp("pending", 0);
		all_inventory(env)->follow_me(me, arg);
		return 1;
	}

	return 0;
}

void do_flee(object me)
{
	mapping exits;
	string *directions;

	if( !environment(me) || !living(me) ) return;
	exits = environment(me)->query("exits");
	if( !mapp(exits) || !sizeof(exits) ) return;
	directions = keys(exits);
	tell_object(me, "看来该找机会逃跑了...\n");
	main(me, directions[random(sizeof(directions))]);
}

int help(object me)
{
	write(@HELP
指令格式 : go <方向>

让你往指定的方向移动。

HELP
    );
    return 1;
}
