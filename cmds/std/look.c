// look.c
// colored by ReyGod in 1/10/1997 ----- I love colorful world :)

#define C_MAP_S "/inherit/maps.c"
#include <room.h>
#include <ansi.h>
#include <combat.h>

#define TIME_TICK1 ((time()-900000000)*60)

inherit F_CLEAN_UP;

int look_room(object me, object env);
int look_item(object me, object obj);
int look_living(object me, object obj);
int look_room_item(object me, string arg);
string getper(object me, object obj);
string tough_level(int power);
string gettof(object me, object obj);
string getdam(object me, object obj);

int info(object me, object env)
{
	string *dirs;
	mapping exits;

	if( mapp(exits = env->query("exits")) )
		dirs = keys(exits);

	if(sizeof(dirs)==1 && sizeof(dirs)!=0)
                   write(TMI("bnway "+dirs[0]+";"));
	else if(sizeof(dirs)!=0)
                   write(TMI( sprintf("bnway "+"%s;",implode(dirs[0..sizeof(dirs)], ";")) ));
        else write(TMI("bnway "));

        return 1;
}
void create() { seteuid(getuid()); }

int main(object me, string arg)
{
        object obj;
        int result;

        if( !arg ) result = look_room(me, environment(me));
        else if( (obj = present(arg, me)) || (obj = present(arg, environment(me))))
             {
                if( obj->is_character() ) result = look_living(me, obj);
                else result = look_item(me, obj);
             } else result = look_room_item(me, arg);

        return result;
}
void realtime_map(object me,object env)
{
        object room_obj;
        mapping exits;
    int i;
        string map_room, map_room2,jiantou;
     string *dirs;
        mapping alldirs=([      
                        "northwest" : "          ",
                        "north"     : "          ",
                        "northup"   : "          ",
                        "northeast" : "          ",
                        "west"      : "          ",
                        "east"      : "          ",
                        "southeast" : "          ",
                        "south"     : "          ",
                        "southwest" : "          ",
                        "southdown" : "          ",
                        "eastup" : "          ",
                        "southup" : "          ",
                        "northdown" : "          ",
                        "eastdown" : "          ",
                        "westup" : "          ",
                        "westdown" : "          ",
                        "enter" : "          ",
                        "out" : "          ",
                        "up" : "          ",
                        "down" : "          ",
                        "left" : "          ",
                        "right" : "          ",
                        ]);  
       if( mapp(exits = env->query("exits")) ) 
        {                       
                dirs=keys(exits);
                for(i=0;i< sizeof(dirs);i++)
                {
                        if(!room_obj=find_object(exits[dirs[i]]))
                                room_obj=load_object(exits[dirs[i]]);
                        if(room_obj){
                                
                                if (room_obj->query("short"))
                                alldirs[dirs[i]]=room_obj->query("short");                              ;
                                }
        
                }
        
                jiantou="  ";
                map_room2=alldirs["enter"];
                if(alldirs["enter"]!="          "){
                        map_room2=alldirs["enter"];
                        jiantou=HIR+"∧"+NOR;
                        }
                if(alldirs["up"]!="          "){
                        map_room2=alldirs["up"];
                        jiantou=HIC+"〓"+NOR;
                        }
                if(alldirs["northdown"]!="          "){
                        map_room2=alldirs["northdown"];
                        jiantou="↓";
                        }
                if(alldirs["northup"]!="          "){
                        map_room2=alldirs["northup"];
                        jiantou="↑";
                        }
                if(alldirs["north"]!="          "){
                        map_room2=alldirs["north"];
                        jiantou="｜";
                        }
                map_room=map_room2;
                for(i=0;i<(10-strlen(map_room2))/2;i++)
                        {
                                map_room =map_room+" ";
                                map_room =" "+map_room;
                        }
                printf("             %10s  %-10s  %-10s\n",
                alldirs["northwest"],map_room,alldirs["northeast"]);
                
                printf("                        %s   %s   %s\n",
                alldirs["northwest"]=="          " ? "  ":"＼",
                jiantou,
                alldirs["northeast"]=="          " ? "  ":"／");
                
                jiantou="  ";
                map_room2=alldirs["westdown"];
                if(map_room2!="          ")
                                jiantou="→";
                if(alldirs["left"]!="          "){
                        map_room2=alldirs["left"];
                        jiantou="〈";
                        }
                if(alldirs["westup"]!="          "){
                        map_room2=alldirs["westup"];
                        jiantou="←";
                        }
                if(alldirs["west"]!="          "){
                        map_room2=alldirs["west"];
                        jiantou="--";
                        }
                printf("             %10s%s",map_room2,jiantou);        
                map_room2=env->query("short") ? env->query("short"): "----------";
                map_room=HIG+map_room2+NOR;
                for(i=0;i<(10-strlen(map_room2))/2;i++)
                        {
                                if(alldirs["east"]=="          ")
                                map_room =map_room + " ";
                                else map_room=map_room + "-";
                                if(alldirs["west"]=="          ")
                                map_room =" "+ map_room;
                                else map_room ="-"+map_room;
                        }
                printf("%s",map_room);
                
                jiantou="  ";
                map_room2=alldirs["eastup"];
                if(map_room2!="          ")
                                jiantou="→";
                if(alldirs["right"]!="          "){
                        map_room2=alldirs["right"];
                        jiantou="〉";
                        }
                if(alldirs["eastdown"]!="          "){
                        map_room2=alldirs["eastdown"];
                        jiantou="←";
                        }
                if(alldirs["east"]!="          "){
                        map_room2=alldirs["east"];
                        jiantou="--";
                        }
                
                printf("%s%-10s\n",jiantou,map_room2);
                
                jiantou="  ";
                map_room2=alldirs["out"];
                if(alldirs["out"]!="          "){
                        map_room2=alldirs["out"];
                        jiantou=HIR+"∨"+NOR;
                        }
                if(alldirs["down"]!="          "){
                        map_room2=alldirs["down"];
                        jiantou=HIC+"〓"+NOR;
                        }
                
                if(alldirs["southdown"]!="          "){
                                map_room2=alldirs["southdown"];
                                jiantou="↑";
                                }
                if(alldirs["southup"]!="          "){
                        map_room2=alldirs["southup"];
                        jiantou="↓";
                        }
                if(alldirs["south"]!="          "){
                        map_room2=alldirs["south"];
                        jiantou="｜";
                        }
                map_room=map_room2;
                for(i=0;i<(10-strlen(map_room2))/2;i++)
                        {
                                map_room =map_room + " ";
                                map_room =" "+map_room;
                        }
                printf("                        %s   %s   %s\n",
                alldirs["southwest"]=="          " ? "  ":"／",
                jiantou,
                alldirs["southeast"]=="          " ? "  ":"＼");
                printf("             %10s  %-10s  %-10s\n",
                alldirs["southwest"],map_room,alldirs["southeast"]);
                
                        
        }       
        else
        {
                map_room2=env->query("short") ? env->query("short"): "----------";
                map_room=HIG+map_room2+NOR;
                for(i=0;i<(10-strlen(map_room2))/2;i++)
                        {
                                if(alldirs["east"]=="          ")
                                map_room =map_room + " ";
                                else map_room=map_room + "-";
                                if(alldirs["west"]=="          ")
                                map_room =" "+ map_room;
                                else map_room ="-"+map_room;
                        }
                printf("\n                            %s\n",map_room);
                
        }
        return;
}

int look_room(object me, object env)
{
        int i;
        object *inv,obn;
        mapping exits;
        string str, *dirs;

        if( !env ) {
                write("你的四周灰蒙蒙地一片，什么也没有。\n");
                return 1;
        }
// 天气颜色
        switch (NATURE_D->outdoor_room_outcolor())
        {
              case "BLK":
        str = sprintf( HIC + "%s" + NOR + " - %s\n    %s" + BLK + "%s" + NOR,
                env->query("short"),
                wizardp(me)? file_name(env): "",
                env->query("long"),
                env->query("outdoors")? NATURE_D->outdoor_room_description():"");
                   break;
              case "RED":
        str = sprintf( HIC + "%s" + NOR + " - %s\n    %s" + RED + "%s" + NOR,
                env->query("short"),
                wizardp(me)? file_name(env): "",
                env->query("long"),
                env->query("outdoors")? NATURE_D->outdoor_room_description():"");
                   break;
              case "HIR":
        str = sprintf( HIC + "%s" + NOR + " - %s\n    %s" + HIR + "%s" + NOR,
                env->query("short"),
                wizardp(me)? file_name(env): "",
                env->query("long"),
                env->query("outdoors")? NATURE_D->outdoor_room_description():"");
                   break;
              case "GRN":
        str = sprintf( HIC + "%s" + NOR + " - %s\n    %s" + GRN + "%s" + NOR,
                env->query("short"),
                wizardp(me)? file_name(env): "",
                env->query("long"),
                env->query("outdoors")? NATURE_D->outdoor_room_description():"");
                   break;
              case "HIG":
        str = sprintf( HIC + "%s" + NOR + " - %s\n    %s" + HIG + "%s" + NOR,
                env->query("short"),
                wizardp(me)? file_name(env): "",
                env->query("long"),
                env->query("outdoors")? NATURE_D->outdoor_room_description():"");
                   break;
              case "YEL":
        str = sprintf( HIC + "%s" + NOR + " - %s\n    %s" + YEL + "%s" + NOR,
                env->query("short"),
                wizardp(me)? file_name(env): "",
                env->query("long"),
                env->query("outdoors")? NATURE_D->outdoor_room_description():"");
                   break;
              case "HIY":
        str = sprintf( HIC + "%s" + NOR + " - %s\n    %s" + HIY + "%s" + NOR,
                env->query("short"),
                wizardp(me)? file_name(env): "",
                env->query("long"),
                env->query("outdoors")? NATURE_D->outdoor_room_description():"");
                   break;
              case "BLU":
        str = sprintf( HIC + "%s" + NOR + " - %s\n    %s" + BLU + "%s" + NOR,
                env->query("short"),
                wizardp(me)? file_name(env): "",
                env->query("long"),
                env->query("outdoors")? NATURE_D->outdoor_room_description():"");
                   break;
              case "HIB":
        str = sprintf( HIC + "%s" + NOR + " - %s\n    %s" + HIB + "%s" + NOR,
                env->query("short"),
                wizardp(me)? file_name(env): "",
                env->query("long"),
                env->query("outdoors")? NATURE_D->outdoor_room_description():"");
                   break;
              case "MAG":
        str = sprintf( HIC + "%s" + NOR + " - %s\n    %s" + MAG + "%s" + NOR,
                env->query("short"),
                wizardp(me)? file_name(env): "",
                env->query("long"),
                env->query("outdoors")? NATURE_D->outdoor_room_description():"");
                   break;
              case "HIM":
        str = sprintf( HIC + "%s" + NOR + " - %s\n    %s" + HIM + "%s" + NOR,
                env->query("short"),
                wizardp(me)? file_name(env): "",
                env->query("long"),
                env->query("outdoors")? NATURE_D->outdoor_room_description():"");
                   break;
              case "CYN":
        str = sprintf( HIC + "%s" + NOR + " - %s\n    %s" + CYN + "%s" + NOR,
                env->query("short"),
                wizardp(me)? file_name(env): "",
                env->query("long"),
                env->query("outdoors")? NATURE_D->outdoor_room_description():"");
                   break;
              case "HIC":
        str = sprintf( HIC + "%s" + NOR + " - %s\n    %s" + HIC + "%s" + NOR,
                env->query("short"),
                wizardp(me)? file_name(env): "",
                env->query("long"),
                env->query("outdoors")? NATURE_D->outdoor_room_description():"");
                   break;
              case "WHT":
        str = sprintf( HIC + "%s" + NOR + " - %s\n    %s" + WHT + "%s" + NOR,
                env->query("short"),
                wizardp(me)? file_name(env): "",
                env->query("long"),
                env->query("outdoors")? NATURE_D->outdoor_room_description():"");
                   break;
              case "HIW":
        str = sprintf( HIC + "%s" + NOR + " - %s\n    %s" + HIW + "%s" + NOR,
                env->query("short"),
                wizardp(me)? file_name(env): "",
                env->query("long"),
                env->query("outdoors")? NATURE_D->outdoor_room_description():"");
                   break;
              default:
        str = sprintf( HIC + "%s" + NOR + " - %s\n    %s" + HIG + "%s" + NOR,
                env->query("short"),
                wizardp(me)? file_name(env): "",
                env->query("long"),
                env->query("outdoors")? NATURE_D->outdoor_room_description():"");
                   break;
	}
// 天气到此结束
//        str = sprintf( HIC + "%s" + NOR + " - %s\n    %s" + HIY + "%s" + NOR,
//                env->query("short"),
//                wizardp(me)? file_name(env): "",
//                env->query("long"),
//                env->query("outdoors")? NATURE_D->outdoor_room_description():"");

        if( mapp(exits = env->query("exits")) ) {
                dirs = keys(exits);
                for(i=0; i<sizeof(dirs); i++)
                        if( (int)env->query_door(dirs[i], "status") & DOOR_CLOSED )
                                dirs[i] = 0;
                dirs -= ({ 0 });
                if ( env->query("outdoors") &&
                    !present("fire", this_player()) &&
                    !wizardp(this_player()) &&
                    ((strsrch(CHINESE_D->chinese_date(TIME_TICK1), "子时") >= 0) ||
                     (strsrch(CHINESE_D->chinese_date(TIME_TICK1), "丑时") >= 0) ||
                     (strsrch(CHINESE_D->chinese_date(TIME_TICK1), "寅时") >= 0) ||
                     (strsrch(CHINESE_D->chinese_date(TIME_TICK1), "亥时") >= 0)))
                        str += "    天色太黑了，你看不清明显的出路。\n";
                else if( sizeof(dirs)==0 )
                        str += "    这里没有任何明显的出路。\n";
                else if( sizeof(dirs)==1 )
                        str += "    这里唯一的出口是 " + BOLD + dirs[0] + NOR + "。\n";
                else
                        str += sprintf("    这里明显的出口是 " + BOLD + "%s" + NOR + " 和 " + BOLD + "%s" + NOR + "。\n",
                                implode(dirs[0..sizeof(dirs)-2], "、"), dirs[sizeof(dirs)-1]);
        }
//      str += env->door_description();

        inv = all_inventory(env);
        for(i=0; i<sizeof(inv); i++) {
                if( inv[i]==me ) continue;
                if(inv[i]->query_temp("apply/yinshen")) continue;
                if( !me->visible(inv[i]) ) continue;
                str += "  " + inv[i]->short() + "\n";
        }

//                  C_MAP_S->map_visible(me);
        realtime_map(me,env);
if (me->query_temp("tomud"))
	{
		info(me, env);
		str += CLEAN0;
	        foreach(obn in inv)
	        if (obn != me && me->visible(obn)) 
	                str += ADD0(obn);
	 }
        write(str);  
        return 1;
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
			str += HIG "你发现这上面还有你炼制的" +
			       obj->query_temp("daub/poison/name") +
			       HIG "呢。\n" NOR;
			break;
		}

		if (obj->query_temp("daub/who_id") == me->query("id"))
		{
			str += HIG "这上面还有你亲手布下的" +
			       obj->query_temp("daub/poison/name") +
			       HIG "呢。\n" NOR;
			break;
		}

		if (random(4) && random((int)me->query_skill("poison", 1)) < 30)
			// nothing was worked out
			break;

		str += HIG "忽然间你发现上面似乎泛着一些奇异荧光";
		if (me->query_skill("poison", 1) >= 120)
		{
			str += "，可能是" + obj->query_temp("daub/poison/name");
		}

		str += "。\n" NOR;
		break;
	}

	if (obj->query("consistence"))
		str += sprintf("耐久度：" WHT "%d%%\n" NOR, obj->query("consistence"));

 if (obj->query("base_value"))
		str += sprintf(NOR"         数量：" HIG "+ " NOR"%d\n" NOR, obj->query("(value%10000)/100"));

//显示武器属性
 if (obj->query("flag"))
		str += sprintf(NOR"         使用类型：" HIG "+ " NOR"%s\n" NOR, "双手");
       if (obj->query("weapon_prop/damage"))
		str += sprintf(NOR"         物理攻击：" HIG "+ " NOR"%d\n" NOR, obj->query("weapon_prop/damage"));
       if (obj->query("weapon_prop/armor"))
		str += sprintf(NOR"         物理防御：" HIG "+ " NOR"%d\n" NOR, obj->query("weapon_prop/armor"));
       if (obj->query("weapon_prop/armor_vs_force"))
		str += sprintf(HIY"         内功抵御：" HIG "+ " NOR"%d\n" NOR, obj->query("weapon_prop/armor_vs_force"));
       if (obj->query("weapon_prop/strength"))
		str += sprintf(HIB"         臂力增幅：" HIG "+ " NOR"%d\n" NOR, obj->query("weapon_prop/strength"));
       if (obj->query("weapon_prop/intelligence"))
		str += sprintf(HIM"         悟性增幅：" HIG "+ " NOR"%d\n" NOR, obj->query("weapon_prop/intelligence"));
       if (obj->query("weapon_prop/constitution"))
		str += sprintf(HIY"         根骨增幅：" HIG "+ " NOR"%d\n" NOR, obj->query("weapon_prop/constitution"));
       if (obj->query("weapon_prop/dexerity"))
		str += sprintf(HIG"         身法增幅：" HIG "+ " NOR"%d\n" NOR, obj->query("weapon_prop/dexerity"));
       if (obj->query("weapon_prop/karma"))
		str += sprintf(YEL"         福缘增幅：" HIG "+ " NOR"%d\n" NOR, obj->query("weapon_prop/karma"));
       if (obj->query("weapon_prop/personality"))
		str += sprintf(YEL"         容貌增幅：" HIG "+ " NOR"%d\n" NOR, obj->query("weapon_prop/personality"));
       if (obj->query("weapon_prop/force"))
		str += sprintf(YEL"         内功提升：" HIG "+ " NOR"%d\n" NOR, obj->query("weapon_prop/force"));
       if (obj->query("weapon_prop/dodge"))
		str += sprintf(HIG"         轻功提升：" HIG "+ " NOR"%d\n" NOR, obj->query("weapon_prop/dodge"));
       if (obj->query("weapon_prop/parry"))
		str += sprintf(HIB"         招架提升：" HIG "+ " NOR"%d\n" NOR, obj->query("weapon_prop/parry"));
       if (obj->query("weapon_prop/unarmed"))
		str += sprintf(HIY"         拳脚提升：" HIG "+ " NOR"%d\n" NOR, obj->query("weapon_prop/unarmed"));

       if (obj->query("weapon_prop/sword"))
		str += sprintf(NOR"         剑法提升：" HIG "+ " NOR"%d\n" NOR, obj->query("weapon_prop/sword"));
       if (obj->query("weapon_prop/blade"))
		str += sprintf(HIY"         刀法提升：" HIG "+ " NOR"%d\n" NOR, obj->query("weapon_prop/blade"));
       if (obj->query("weapon_prop/axe"))
		str += sprintf(HIB"         斧法提升：" HIG "+ " NOR"%d\n" NOR, obj->query("weapon_prop/axe"));
       if (obj->query("weapon_prop/throwing"))
		str += sprintf(HIR"         暗器提升：" HIG "+ " NOR"%d\n" NOR, obj->query("weapon_prop/throwing"));
       if (obj->query("weapon_prop/stick"))
		str += sprintf(HIM"         棒法提升：" HIG "+ " NOR"%d\n" NOR, obj->query("weapon_prop/stick"));
       if (obj->query("weapon_prop/staff"))
		str += sprintf(HIM"         杖法提升：" HIG "+ " NOR"%d\n" NOR, obj->query("weapon_prop/staff"));
       if (obj->query("weapon_prop/spear"))
		str += sprintf(HIB"         枪法提升：" HIG "+ " NOR"%d\n" NOR, obj->query("weapon_prop/spear"));
       if (obj->query("weapon_prop/fork"))
		str += sprintf(HIM"         叉法提升：" HIG "+ " NOR"%d\n" NOR, obj->query("weapon_prop/fork"));
       if (obj->query("weapon_prop/club"))
		str += sprintf(BLU"         棍法提升：" HIG "+ " NOR"%d\n" NOR, obj->query("weapon_prop/club"));
       if (obj->query("weapon_prop/hammer"))
		str += sprintf(GRN"         锤法提升：" HIG "+ " NOR"%d\n" NOR, obj->query("weapon_prop/hammer"));
       if (obj->query("weapon_prop/magic"))
		str += sprintf(HIM"         法术提升：" HIG "+ " NOR"%d\n" NOR, obj->query("weapon_prop/magic"));
       if (obj->query("weapon_prop/spells"))
		str += sprintf(HIM"         咒文提升：" HIG "+ " NOR"%d\n" NOR, obj->query("weapon_prop/spells"));
       if (obj->query("weapon_prop/whip"))
		str += sprintf(HIR"         鞭法提升：" HIG "+ " NOR"%d\n" NOR, obj->query("weapon_prop/whip"));
       if (obj->query("weapon_prop/poison"))
		str += sprintf(GRN"         毒功提升：" HIG "+ " NOR"%d\n" NOR, obj->query("weapon_prop/poison"));
       if (obj->query("weapon_prop/finger"))
		str += sprintf(HIG"         指法提升：" HIG "+ " NOR"%d\n" NOR, obj->query("weapon_prop/finger"));
       if (obj->query("weapon_prop/hand"))
		str += sprintf(HIY"         手法提升：" HIG "+ " NOR"%d\n" NOR, obj->query("weapon_prop/hand"));
       if (obj->query("weapon_prop/cuff"))
		str += sprintf(HIY"         杖法提升：" HIG "+ " NOR"%d\n" NOR, obj->query("weapon_prop/cuff"));
       if (obj->query("weapon_prop/claw"))
		str += sprintf(NOR"         爪法提升：" HIG "+ " NOR"%d\n" NOR, obj->query("weapon_prop/claw"));
       if (obj->query("weapon_prop/strike"))
		str += sprintf(HIM"         掌法提升：" HIG "+ " NOR"%d\n" NOR, obj->query("weapon_prop/strike"));
       if (obj->query("weapon_prop/taoism"))
		str += sprintf(HIM"         道学心法：" HIG "+ " NOR"%d\n" NOR, obj->query("weapon_prop/taoism"));
//显示装备属性
       if (obj->query("armor_prop/damage"))
		str += sprintf(NOR"         物理攻击：" HIG "+ " NOR"%d\n" NOR, obj->query("armor_prop/damage"));
       if (obj->query("armor_prop/armor"))
		str += sprintf(NOR"         物理防御：" HIG "+ " NOR"%d\n" NOR, obj->query("armor_prop/armor"));
       if (obj->query("armor_prop/armor_vs_force"))
		str += sprintf(HIY"         内功抵御：" HIG "+ " NOR"%d\n" NOR, obj->query("armor_prop/armor_vs_force"));
       if (obj->query("armor_prop/strength"))
		str += sprintf(HIB"         臂力增幅：" HIG "+ " NOR"%d\n" NOR, obj->query("armor_prop/strength"));
       if (obj->query("armor_prop/intelligence"))
		str += sprintf(HIM"         悟性增幅：" HIG "+ " NOR"%d\n" NOR, obj->query("armor_prop/intelligence"));
       if (obj->query("armor_prop/constitution"))
		str += sprintf(HIY"         根骨增幅：" HIG "+ " NOR"%d\n" NOR, obj->query("armor_prop/constitution"));
       if (obj->query("armor_prop/dexerity"))
		str += sprintf(HIG"         身法增幅：" HIG "+ " NOR"%d\n" NOR, obj->query("armor_prop/dexerity"));
       if (obj->query("armor_prop/karma"))
		str += sprintf(YEL"         福缘增幅：" HIG "+ " NOR"%d\n" NOR, obj->query("armor_prop/karma"));
       if (obj->query("armor_prop/personality"))
		str += sprintf(YEL"         容貌增幅：" HIG "+ " NOR"%d\n" NOR, obj->query("armor_prop/personality"));
       if (obj->query("armor_prop/force"))
		str += sprintf(YEL"         内功提升：" HIG "+ " NOR"%d\n" NOR, obj->query("armor_prop/force"));
       if (obj->query("armor_prop/dodge"))
		str += sprintf(HIG"         轻功提升：" HIG "+ " NOR"%d\n" NOR, obj->query("armor_prop/dodge"));
       if (obj->query("armor_prop/parry"))
		str += sprintf(HIB"         招架提升：" HIG "+ " NOR"%d\n" NOR, obj->query("armor_prop/parry"));
       if (obj->query("armor_prop/unarmed"))
		str += sprintf(HIY"         拳脚提升：" HIG "+ " NOR"%d\n" NOR, obj->query("armor_prop/unarmed"));
       if (obj->query("armor_prop/sword"))
		str += sprintf(NOR"         剑法提升：" HIG "+ " NOR"%d\n" NOR, obj->query("armor_prop/sword"));

       if (obj->query("armor_prop/blade"))
		str += sprintf(HIY"         刀法提升：" HIG "+ " NOR"%d\n" NOR, obj->query("armor_prop/blade"));
       if (obj->query("armor_prop/axe"))
		str += sprintf(HIB"         斧法提升：" HIG "+ " NOR"%d\n" NOR, obj->query("armor_prop/axe"));
       if (obj->query("armor_prop/throwing"))
		str += sprintf(HIR"         暗器提升：" HIG "+ " NOR"%d\n" NOR, obj->query("armor_prop/throwing"));
       if (obj->query("armor_prop/stick"))
		str += sprintf(HIM"         棒法提升：" HIG "+ " NOR"%d\n" NOR, obj->query("armor_prop/stick"));
       if (obj->query("armor_prop/staff"))
		str += sprintf(HIM"         杖法提升：" HIG "+ " NOR"%d\n" NOR, obj->query("armor_prop/staff"));
       if (obj->query("armor_prop/spear"))
		str += sprintf(HIB"         枪法提升：" HIG "+ " NOR"%d\n" NOR, obj->query("armor_prop/spear"));
       if (obj->query("armor_prop/fork"))
		str += sprintf(HIM"         叉法提升：" HIG "+ " NOR"%d\n" NOR, obj->query("armor_prop/fork"));
       if (obj->query("armor_prop/club"))
		str += sprintf(HIB"         棍法提升：" HIG "+ " NOR"%d\n" NOR, obj->query("armor_prop/club"));
       if (obj->query("armor_prop/hammer"))
		str += sprintf(GRN"         锤法提升：" HIG "+ " NOR"%d\n" NOR, obj->query("armor_prop/hammer"));
       if (obj->query("armor_prop/magic"))
		str += sprintf(HIM"         法术提升：" HIG "+ " NOR"%d\n" NOR, obj->query("armor_prop/magic"));
       if (obj->query("armor_prop/spells"))
		str += sprintf(HIM"         咒文提升：" HIG "+ " NOR"%d\n" NOR, obj->query("armor_prop/spells"));
       if (obj->query("armor_prop/whip"))
		str += sprintf(HIR"         鞭法提升：" HIG "+ " NOR"%d\n" NOR, obj->query("armor_prop/whip"));
       if (obj->query("armor_prop/poison"))
		str += sprintf(GRN"         毒功提升：" HIG "+ " NOR"%d\n" NOR, obj->query("armor_prop/poison"));
       if (obj->query("armor_prop/finger"))
		str += sprintf(HIG"         指法提升：" HIG "+ " NOR"%d\n" NOR, obj->query("armor_prop/finger"));
       if (obj->query("armor_prop/hand"))
		str += sprintf(HIY"         手法提升：" HIG "+ " NOR"%d\n" NOR, obj->query("armor_prop/hand"));
       if (obj->query("armor_prop/cuff"))
		str += sprintf(HIY"         杖法提升：" HIG "+ " NOR"%d\n" NOR, obj->query("armor_prop/cuff"));
       if (obj->query("armor_prop/claw"))
		str += sprintf(NOR"         爪法提升：" HIG "+ " NOR"%d\n" NOR, obj->query("armor_prop/claw"));
       if (obj->query("armor_prop/strike"))
		str += sprintf(HIM"         掌法提升：" HIG "+ " NOR"%d\n" NOR, obj->query("armor_prop/strike"));
       if (obj->query("armor_prop/taoism"))
		str += sprintf(HIM"         道学心法：" HIG "+ " NOR"%d\n" NOR, obj->query("armor_prop/taoism"));


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
				str += "手中还死死握着一" + hob->query("base_unit") +
				       hob->name() + "，";
			else
				str += "手中还死死握着一" + hob->query("unit") +
				       hob->name() + "，";
			inv -= ({ hob });
			if (! sizeof(inv))
				str += "没有什么其他遗物了。\n";
			else
				str += "里面的遗物有：\n";
		} else
			str += "里面的遗物有：\n";
	} else
		str += "里面有：\n";

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
		str += HIC "  □" NOR;
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


int look_living(object me, object obj)
{
        int per,i;
        int age;
        string str, pro,*skills_name;
        mixed *inv;
        mapping my_fam, fam,skills;
        int me_shen, obj_shen;
        int equip, wearornot;

        me_shen = (int)me->query("shen");
        obj_shen = (int)obj->query("shen");
        per = obj->query_per();
        age = obj->query("age");

        if( me!=obj )
                message("vision", me->name() + "正盯著你看，不知道打些什么主意。\n", obj);


        str = obj->long();
        pro = (obj==me) ? gender_self(obj->query("gender")) : gender_pronoun(obj->query("gender"));
	if (obj->query_temp("is_riding"))
                str += sprintf("%s正骑在%s上，低头看着你。\n", pro, obj->query_temp("is_riding"));

        if( (string)obj->query("race")=="人类"
        &&      intp(obj->query("age")) )
        {
                str += sprintf("%s看起来约%s多岁。\n", pro, chinese_number(obj->query("age") / 10 * 10));
   skills=obj->query_skills();
    if (!sizeof(skills))
        str+=sprintf("%s看起来似乎不会任何武功。\n", pro);
    else{
        skills_name=sort_array( keys(skills), (: strcmp :) );
        i=random(sizeof(skills_name));
                if (SKILL_D(skills_name[i])->type()=="knowledge")
            str+=sprintf("%s看起来似乎不会任何武功。\n", pro);
        else
            str+=sprintf("%s的武功看起来似乎%s。\n", pro,"/cmds/usr/skills"->skill_level(SKILL_D(skills_name[i])->type(), skills[skills_name[i]]));
    }

        }
        if (obj->query("guild")){
        	if((int)obj->query("guild/generation")==3)
str += pro+"是"+obj->query("guild/name")+"的帮众。\n";
        	if(obj->query("guild/generation")==2)
        		str += pro+"是"+obj->query("guild/name")+"的长老。\n";
        	if(obj->query("guild/generation")==1)
        		str += pro+"是"+obj->query("guild/name")+"的帮主。\n";
        	}
        if(age > 70 ) per = per/4;
        if(age > 60 ) per = per/3;
        if(age > 50 ) per = per/2;
        if ((string) obj->query("gender") == "男性" || (string) obj->query("gender") == "无性")
        {
                if (per >= 30) str +=pro+ "长得宛如玉树临风，风流倜傥，顾盼之间，神采飞扬。真正是人中龙凤！\n";
                if ((per >= 26) && (per < 30))
                        str += pro+"英俊潇洒，气宇轩昂，风度翩翩，面目俊朗，貌似潘安。\n";
                if ((per >= 22) && (per < 26))
                        str += pro+"相貌英俊，仪表堂堂。骨格清奇，丰姿非俗。\n";
                if ((per >= 18) && (per < 22))
                        str += pro+"五官端正。\n";
                if ((per >= 15) && (per < 18))
                        str += pro+"相貌平平。没什么好看的。\n\n";
                if (per < 15)
                        str += pro+"长得...有点对不住别人。\n";
        }
        else
        {
            if ((string) obj->query("gender") == "女性")
            {
                if (per >= 40)
                {
                if(obj->query("describe"))
                {
             str += pro+"有倾国倾城之貌，容色丽都，娇艳绝伦，堪称人间仙子！\n"+(string)obj->query("describe")+"\n";
                }
            else
                        str += pro+"有倾国倾城之貌，容色丽都，娇艳绝伦，堪称人间仙子！\n长发如云，肌肤胜雪，风华绝代，不知倾倒了多少英雄豪杰。\n";
                }
                if ((per >= 30) && (per < 40))
                        str += pro+"有倾国倾城之貌，容色丽都，娇艳绝伦，堪称人间仙子！\n长发如云，肌肤胜雪，风华绝代，不知倾倒了多少英雄豪杰。\n";
                if ((per >= 28) && (per < 30))
                        str += pro+"清丽绝俗，风姿动人。有沉鱼落雁之容，避月羞花之貌！\n俏脸生春，妙目含情，顾盼神飞，轻轻一笑，不觉让人怦然心动。\n";
                if ((per >= 26) && (per < 28))
                        str += pro+"肤如凝脂，眉目如画，风情万种，楚楚动人。当真是我见犹怜！\n";
                if ((per >= 24) && (per < 26))
                        str += pro+"容色秀丽，面带晕红，眼含秋波。举手投足之间，确有一番风韵。\n";
// 玉面娇容花含露，纤足细腰柳带烟。
                if ((per >= 21) && (per < 24))
                        str += pro+"气质高雅，面目姣好，虽算不上绝世佳人，也颇有几份姿色。\n";
                if ((per >= 18) && (per < 21))
                        str += pro+"相貌平平，还看得过去。\n";
                if ((per >= 15) && (per <18))
                        str += pro+"的相貌嘛...马马虎虎吧。\n";
                if (per < 15)
                        str += "咦，"+pro+"长得和无盐有点相似耶。\n";
            }
            else
            {
                if (living(obj))
		{
                if (!obj->query_temp("owner"))
                   str += pro+"是一只未被驯服的畜生，眼光里满是戒心和敌意。\n";
                else
                   str += pro+"是一只被"+obj->query_temp("ownername")+"驯服的畜生，一副很温驯的样子。\n";
		}
            }
        }
        wearornot = 0;
        inv = all_inventory(obj);
        for(equip=0; equip<sizeof(inv); equip++)
        {
                if( inv[equip]->query("equipped") ) wearornot = 1;
        }
        //check about wife and husband
        if((obj->parse_command_id_list())[0]==me->query("couple/couple_id") )
        {
              if( (string)me->query("gender")=="女性" )
              {
                    str += sprintf("%s是你的丈夫。\n", pro);
              }
              else{
                    str += sprintf("%s是你的妻子。\n", pro);
              }
        }

        if (me->query("jiebai"))
        if (strsrch(me->query("jiebai"), obj->query("id")+">") >= 0)
        {
              if( obj->query("gender")=="女性" )
              {
                    if (obj->query("mud_age") > me->query("mud_age"))
                        str += sprintf("%s是你的义姐。\n", pro);
                    else
                        str += sprintf("%s是你的结义妹子。\n", pro);
              }
              else{
                    if (obj->query("mud_age") > me->query("mud_age"))
                        str += sprintf("%s是你的结义兄长。\n", pro);
                    else
                        str += sprintf("%s是你的义弟。\n", pro);
              }
        }
        if((wearornot == 0 ) && userp(obj) && !wizardp(obj) )
            str += pro+"身上居然什么都没穿耶！\n";
        // If we both has family, check if we have any relations.
        if( obj!=me
        &&      mapp(fam = obj->query("family"))
        &&      mapp(my_fam = me->query("family"))
        &&      fam["family_name"] == my_fam["family_name"] ) {

                if( fam["generation"]==my_fam["generation"] ) {

                        if( (string)obj->query("gender") == "男性" ||
                                (string)obj->query("gender") == "无性")
                                str += sprintf( pro + "是你的%s%s。\n",
                                        my_fam["master_id"] == fam["master_id"]? "": "同门",
                                        my_fam["enter_time"] > fam["enter_time"] ? "师兄": "师弟");
                        else
                                str += sprintf( pro + "是你的%s%s。\n",
                                        my_fam["master_id"] == fam["master_id"]? "": "同门",
                                        my_fam["enter_time"] > fam["enter_time"] ? "师姐": "师妹");
                } else if( fam["generation"] < my_fam["generation"] ) {
                        if( my_fam["master_id"] == obj->query("id") )
                                str += pro + "是你的师父。\n";
                        else if( my_fam["generation"] - fam["generation"] > 1 )
                                str += pro + "是你的同门长辈。\n";
                        else if( fam["enter_time"] < my_fam["enter_time"] )
                                str += pro + "是你的师伯。\n";
                        else
                                str += pro + "是你的师叔。\n";
                } else {
                        if( fam["generation"] - my_fam["generation"] > 1 )
                                str += pro + "是你的同门晚辈。\n";
                        else if( fam["master_id"] == me->query("id") )
                                str += pro + "是你的弟子。\n";
                        else
                                str += pro + "是你的师侄。\n";
                }
        }

        if( obj->query("max_qi") )
                str += pro + COMBAT_D->eff_status_msg((int)obj->query("eff_qi")* 100 / (int)obj->query("max_qi")) + "\n";

	if(obj->is_corpse() && obj->query("kantou") == 1) str += sprintf("%s连头都被割走了。\n", pro);

        inv = all_inventory(obj);
        if( sizeof(inv) ) {
                inv = map_array(inv, "inventory_look", this_object(), obj->is_corpse()? 0 : 1 );
                inv -= ({ 0 });
                if( sizeof(inv) )
                        str += sprintf( obj->is_corpse() ? "%s的遗物有：\n%s\n": "%s身上带著：\n%s\n",
                                pro, implode(inv, "\n") );
        }

        message("vision", str, me);

        if( obj!=me && living(obj)
        && (((me_shen < 0) && (obj_shen > 0)) || ((me_shen > 0) && (obj_shen < 0)))
        && (((me_shen - obj_shen) > ((int)obj->query("neili") * 20))
        || ((obj_shen - me_shen) > ((int)obj->query("neili") * 20))))
        {
                write( obj->name() + "突然转过头来瞪你一眼。\n");
                if(obj->query("age") > 15 && me->query("age") > 15)
                   if(!wizardp(obj) && !wizardp(me))
                        COMBAT_D->auto_fight(obj, me, "berserk");
        }

        return 1;
}

string inventory_look(object obj, int flag)
{
        string str;

        str = obj->short();
        if( obj->query("equipped") )
                str = HIC "  □" NOR + str;
        else if( !flag )
                str = "    " + str;
        else
                return 0;

        return str;
}

int look_room_item(object me, string arg)
{
        object env;
        mapping item, exits;

        if( !objectp(env = environment(me)) )
                return notify_fail("这里只有灰蒙蒙地一片，什么也没有。\n");
        if( mapp(item = env->query("item_desc")) && !undefinedp(item[arg]) ) {
                if( stringp(item[arg]) )
                        write(item[arg]);
                else if( functionp(item[arg]) )
                        write((string)(*item[arg])(me));

                return 1;
        }
        if( mapp(exits = env->query("exits")) && !undefinedp(exits[arg]) ) {
                if( objectp(env = find_object(exits[arg])) )
                        look_room(me, env);
                else {
                        call_other(exits[arg], "???");
                        look_room(me, find_object(exits[arg]));
                }
                return 1;
        }
        return notify_fail("你要看什么？\n");
}


int help (object me)
{
        write(@HELP
指令格式: look [<物品>|<生物>|<方向>]

这个指令让你查看你所在的环境、某件物品、生物、或是方向。

HELP
);
        return 1;
}

