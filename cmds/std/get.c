// get.c
#include <ansi.h>
inherit F_CLEAN_UP;
int do_get(object me, object ob,object env,int amount);
void create() { seteuid(getuid()); }
int main(object me, string arg)
{
        string from, item;
        object obj, *inv, env, obj2;
        int i, amount;
        if( !arg ) return notify_fail("你要捡起什麽东西？\n");
        if( me->is_busy() )
                return notify_fail("你上一个动作还没有完成！\n");
        // Check if a container is specified.
        if( sscanf(arg, "%s from %s", arg, from)==2 ) {
                env = present(from, me);
                if(!env) env = present(from, environment(me));
                if(!env) return notify_fail("你找不到 " + from + " 这样东西。\n");
                if (env->query("no_get_from") && !wizardp(me))
                        return notify_fail("你不能从"+env->query("name")+"里拿走任何东西。\n");
                if(living(env) && (wiz_level(me) <= wiz_level(env)))
                        return notify_fail("你的巫师等级必须比对方高，才能搜身。\n");
        } else env = environment(me);
        // Check if a certain amount is specified.
        if(sscanf(arg, "%d %s", amount, item)==2) {
                if( !objectp(obj = present(item, env)) )
                        return notify_fail("这里没有这样东西。\n");
                if( amount < 1 )
                        return notify_fail("东西的个数至少是一个。\n");
                if(obj->query_amount() ){
                        if( amount > obj->query_amount() )
                                return notify_fail("这里没有那麽多的" + obj->name() + "。\n");
                        else if( amount == (int)obj->query_amount() ) {
                                return do_get(me, obj,env,1);
                        } else {
                                i= (int)obj->query_amount();
                                obj->set_amount( amount );
                                obj2 = new(base_name(obj));
                                // Counting precise amount costs more time.
                                do_get(me, obj,env,1);
                                obj2->set_amount( i-amount );
                                obj2->move(env);                        // For containers.
                                return 1;
                        }
                }else   if( amount>1 && me->is_fighting() )
                                return notify_fail("你还在战斗中！只能一次拿一样。\n");
                        else    return do_get(me,obj,env,amount);
        }
        // Check if we are makeing a quick get.
        if(arg=="all") {
                if( me->is_fighting() ) return notify_fail("你还在战斗中！只能一次拿一样。\n");
                if( !env->query_max_encumbrance() )     return notify_fail("那不是容器。\n");
                inv = all_inventory(env);
                if( !sizeof(inv) )
                        return notify_fail("那里面没有任何东西。\n");
           
                for(i=0; i<sizeof(inv); i++) {
                	
                        if( inv[i]->is_character() || inv[i]->query("no_get") ) continue;
                        if (i>7)  break;
                        do_get(me, inv[i],env,1);
                }
                write("Ok。\n");
                return 1;
        }
        if( !objectp(obj = present(arg, env)) )
                return notify_fail("你附近没有这样东西。\n");
        return do_get(me, obj,env,1);
}
        
int do_get(object me, object obj,object env,int amount)
{
        int i,equipped;
        string str,arg1,arg2;
        if( !obj ) return 0;
        if( obj->query("no_get") && !wizardp(me))
                return notify_fail("这个东西拿不起来。\n");
        if( obj->is_character() ){
                if( living(obj) && wizhood(me)!="(admin)")  return notify_fail(obj->query("name")+"不用你背。\n");
        }
        if( me->is_fighting() ) me->start_busy(2);
        str=obj->short(1);
        foreach (object ob in all_inventory(env)){
                if (ob->short(1)!=str)  continue;
                if( ob->query("no_get") && !wizardp(me)){
                      write(ob->name(1)+"拿不起来。\n");
                      continue;
                }
if(obj->query("money_id")&&obj->query_amount()>30000){
write(obj->name()+"对你而言太重了。\n");
continue;}
                if( ob->is_character() && living(ob) && wizhood(me)!="(admin)"){
                      write(ob->name(1)+"不用你背。\n");
                      continue;
                }
                if( ob->move(me) ) {
                        if( ob->is_character() ){
                                message_vision( "$N将$n扶了起来背在背上。\n", me, ob );
                                if (userp(ob))  tell_object(ob,BOLD+"你迷迷糊糊地感到似乎有人把你背了起来。\n"+NOR);
                                return 1;
                        }
                        else{
                        if( ob->query("equipped") ) equipped = 1;
                        arg1= env==environment(me)? "捡起":(env->is_character() ?"从"+env->name()+"身上" + (equipped? "除下" : "搜出"):"从" + env->name() + "中拿出");
                        arg2=ob->query("unit")+ob->name();
                        }
                }       else{   tell_object(me,ob->name()+"对你而言太重了。\n");return 1;}
                i++;
                if(i >= amount)      break;
        }
    if (!i) return 1;
   if ( !me->query("env/invisibility") )
        message_vision( sprintf("$N%s%s%s。\n", arg1,CHINESE_D->chinese_number(i),arg2), me);
        if (! env->is_character() && !sizeof(all_inventory(env)))
        env->set("no_clean_up",0);
        return 1;
}
int help(object me)
{
        write(@HELP
指令格式 : get <物品名称> [from <容器名>]
           get <数量> <物品名称> [from <容器名>]
这个指令可以让你捡起地上或容器内的某样物品.
 
HELP
    );
    return 1;
}

