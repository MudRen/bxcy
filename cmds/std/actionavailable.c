// actionavailable.c
//FIX AKAI 2006
#include <ansi.h>
#include <weapon.h>
#include <login.h>
inherit F_CLEAN_UP;

int room_path(object, object);
int user_path(object, object);

int main(object me, string arg)
{
	object ob, *inv;
	string win,*ids;

        if (sscanf(arg, "%s,%s", arg, win) != 2) 
                return 0;
                
	switch (win)
	{
		case "0" :
			ob=present(arg,environment(me));
			if(!objectp(ob)) {
				inv=all_inventory(environment(me));
				for(int i = 0; i<sizeof(inv); i++) {
					if(inv[i]==me) continue;
					if(ids=inv[i]->query_temp("apply/id"))
					for(int j=0;j<sizeof(ids);j++) {
						if(ids[j]==arg)
						ob=inv[i];
					}
				}
			}
			room_path(me,ob);
			break;
		case "1" :
			ob=present(arg,me);
			user_path(me,ob);
			break;
	}
	return 1;
}

int room_path(object me, object ob)
{
	mapping skills,meskills;
	object *inv;
	string *str,id,*ids,tmp;
	int i,my_skill;

	if(!objectp(ob)) return 1;
	
	if(stringp(tmp=ob->query_menu(me,0)))//如果对象能解释菜单，则直接返回菜单
	{
		write(tmp);
		return 1;
	}
	

	if(!ob->query("apply/id")) id=ob->query("id");
	else {
		ids=ob->query_temp("apply/id");
		id=ids[sizeof(ids)-1];
	}

//	if(ob->query_temp("apply/name")) name=ob->query_temp("apply/name");
	tmp=TMI("mbegin "+ob->name(1)+";"+id)+TMI("mitem 观察$U;look "+id);

	if(living(ob))
	{
		if(interactive(ob))
		{
			tmp+=TMI("mitem 告诉$U...;tell "+id+" ...")+TMI("mitem 对$U耳语...;whisper "+id+" ...");
			if(id==me->query_temp("reply"))
				write(TMI("mitem 回答$U...;reply ..."));
		}

		tmp+=(me->query_leader()==ob)?TMI("mitem 停止跟随$U;follow none"):TMI("mitem 跟随$U;follow "+id);
		if(!environment(me)->query("no_fight"))
		{
			tmp+=TMI("mitem 与$U切磋;fight "+id);
			if ((int)ob->query("age") > 17 || !interactive(ob))
				tmp+=TMI("mitem 攻击$U;hit "+id)+TMI("mitem 杀死$U;kill "+id)+TMI("mitem 偷袭$U;touxi "+id)+TMI("mitem 偷$U的...;steal ... from "+id);
		}

		if(ob->query("inquiry")) {
			str=keys(ob->query("inquiry"));
			for(i=0; i<sizeof(str); i++)
				tmp+=TMI("mitem 向$U打听关于"+str[i]+"的信息;ask "+id+" about "+str[i]+"");
		}
		tmp+=TMI("mitem 给$U...东西;give ... to "+id );
		if(me->query("family/family_name") == "丐帮" ) {
			if ( me->query_skill("checking",1) >= 10 )
				tmp+=TMI("mitem 打探...的技能;check ...");
			if(ob->query("family/family_name") != "丐帮" )
				tmp+=TMI("mitem 乞讨$U的...;beg ... from "+id);
		}
		if(ob->query("vendor_goods")) {
			tmp+=TMI("mitem 查询$U出售的东西;list");
			tmp+=TMI("mitem 向$U买...;buy (物品ID)...");
		}
		/////AKAI这里就是添加商店LIST命令的判断方法，添加物品购买菜单就可以放在这里吧：）
		if(ob->query("dealer")=="pawn") {
			if(!ob->query("vendor_goods")) {
				tmp+=TMI("mitem 查询$U出售的东西;list");
				tmp+=TMI("mitem 向$U买...;buy (物品ID)...");
			}
			tmp+=TMI("mitem 估价...;value ...");
			tmp+=TMI("mitem 卖...给$U;sell ...");
			tmp+=TMI("mitem 典当...给$U;pawn ...");
			if(me->query("pawns"))
				tmp+=TMI("mitem 赎回物品...;redeem ...");
		}
		if(ob->query("dealer")=="bank")
             {
			tmp+=TMI("mitem 兑换货币;convert ...");
			tmp+=TMI("mitem 存钱;deposit ...");
			if(me->query("money")) {
				tmp+=TMI("mitem 查询存款;check");
				tmp+=TMI("mitem 取钱;withdraw ...");
			}

		}
		if(me->query("family/master_name")!=ob->name(1)) {
			if(ob->is_master())
				tmp+=TMI("mitem 拜$U为师;bai "+id);
		} else {
			tmp+=TMI("mitem 向师父$U磕头;bai "+id);
			tmp+=TMI("mitem 查询师父$U技能;skills "+id);
			if(ob->query_skills() && me->query("jing")>=1
				&& (int)me->query("potential")>(int)me->query("learned_points")) {
				skills=ob->query_skills();
				str=keys(skills);
				for(i=0; i<sizeof(str); i++) {
					if(me->query_skills()) {
						meskills=me->query_skills();
						my_skill = me->query_skill(str[i], 1);
						if( (string)SKILL_D(str[i])->type()=="martial"
							&& my_skill*my_skill*my_skill/10>(int)me->query("combat_exp") )
							continue;
						if(skills[str[i]]>my_skill && str[i]!="idle")
							tmp+=TMI("mitem 学习"+to_chinese(str[i])+";learn "+str[i]+" at 1 from "+id+"");
					} else
					tmp+=TMI("mitem 学习"+to_chinese(str[i])+";learn "+str[i]+" at 1 from "+id+"");
				}
			}
		}
	} else {
		if(!ob->query("no_get"))
			tmp+=TMI("mitem 把$U捡起来;get "+id);
		if(ob->is_container()) {
			inv = all_inventory(ob);
			if(sizeof(inv)) {
				tmp+=TMI("mitem 把$U里的东西都拿出来;get all from "+id);
				tmp+=TMI("mitem 从$U里拿出...;get ... from "+id);
			}
			tmp+=TMI("mitem 把...装进$U里;put ... in "+id);
		}
		if(id=="board") {
			tmp+=TMI("mitem 读新的留言;read new");
			tmp+=TMI("mitem 读第...条留言;read ...");
			tmp+=TMI("mitem 写新的留言;post ...");
			tmp+=TMI("mitem 删除留言...;discard ...");
		}
	}
	    //ADD AKAI 2006 人物菜单和地上物品的例子
	    /***********************************************************************************
	    *    if(id=="zhu banxian")/////////id就是TOMUD传来的单击对象的ID，这里是判断ID是否是
	    *                          ////////////////朱半仙的ID；
        *       tmp+=TMI("mitem 朱半仙杀人寻物任务;quest");////tmp为将要返回给TOMUD的字符串变量。
        *      添加一个菜单项的代码放入tmp字符串里，这样就完成了一个基本的特殊菜单添加过程：）
	    *    这里就是单击人物和者到上地上物品的菜单，
	    *    如果是身上物品的就不能放这里 ，应该放下面的函数里///往下看
	    *
	    *
	    *
	    ************************************************************************************/

   ////在这中间添加特殊的新菜单//////////AKAI
     if(id=="zhu banxian")//添加半仙任务
    tmp+=TMI("mitem 朱半仙杀人寻物任务;quest");
    if("post officer"==id) //添加送信任务
     tmp+=TMI("mitem 送信任务;quest");
     if("qian yankai"==id)//钱庄
     {
      tmp+=TMI("mitem 存钱;deposit ...");
      tmp+=TMI("mitem 存N两黄金;deposit ... gold");
      tmp+=TMI("mitem 存N两白银;deposit ... silver");
      tmp+=TMI("mitem 兑换钱币;convert ...");
      tmp+=TMI("mitem 取5两黄金;withdraw 5 gold");
      tmp+=TMI("mitem 取10两黄金;withdraw 10 gold");
      tmp+=TMI("mitem 取50两黄金;withdraw 50 gold");
      tmp+=TMI("mitem 取100两黄金;withdraw 100 gold");
      tmp+=TMI("mitem 取1000两黄金;withdraw 1000 gold");
      tmp+=TMI("mitem 取钱;withdraw ...");
      tmp+=TMI("mitem 查询存款;check");
     }

     if("tang nan"==id)//当铺
     {
      tmp+=TMI("mitem 估价物品;value 物品ID...");
      tmp+=TMI("mitem 卖物品;sell 物品ID...");
      tmp+=TMI("mitem 典当物品;pawn  物品ID...");
      tmp+=TMI("mitem 赎出物品;redeem 物品ID...");
      tmp+=TMI("mitem 买物品;buy 物品ID...");
      tmp+=TMI("mitem 查寻物品价格;list");
     }
     	if(strsrch(id,"bingqi jia",-1)!=-1)//兵器架
	{
	   tmp+=TMI("mitem 拿风雷剑;na fenglei jian from jia");
	   tmp+=TMI("mitem 拿风火棍;na fenghuo gun from jia");
	   tmp+=TMI("mitem 拿风云刀;na fengyun dao from jia");
    }
  		if(strsrch(id,"table",-1)!=-1)  //茶几拿新手礼物
	tmp+=TMI("mitem 拿$U上的新手礼物;pick gift");


  /////////////////////////////////////////////AKAI
    tmp+=TMI("mendd");
	tell_object(me,tmp);
	return 1;
}

int user_path(object me, object ob)
{
	mapping prop;
	string id,tmp;

	if(!objectp(ob)) return 1;
	
	if(stringp(tmp=ob->query_menu(me,1)))//如果对象能解释菜单，则直接返回菜单
	{
		write(tmp);
		return 1;
	}
	
	id=ob->query("id");
	tmp=TMI("mbegin "+ob->name(1)+";"+id)+TMI("mitem 观察$U;look "+id);

	if(!ob->query("no_drop"))
		tmp+=TMI("mitem 丢弃$U;drop "+id);

	if(!ob->query("no_give"))
		tmp+=TMI("mitem 把$U给...;give "+id+" to ...");

	if(ob->query("liquid")) {
		if(ob->query("liquid/remaining"))
			tmp+=TMI("mitem 喝$U;drink "+id);
		if(environment(me)->query("resource/water"))
			tmp+=TMI("mitem 把$U装满水;fill "+id);
	}
	
	if(ob->query("food_remaining"))
		tmp+=TMI("mitem 吃$U;eat "+id);
		
	if(ob->is_container()) {
		tmp+=TMI("mitem 把$U里的东西都拿出来;get all from "+id);
		tmp+=TMI("mitem 从$U里拿出...;get ... from "+id);
		tmp+=TMI("mitem 把...装进$U里;put ... in "+id);
	}
	if(mapp(prop=ob->query("armor_prop"))&& stringp(ob->query("armor_type")) ) {
		if(!ob->query("equipped"))
			tmp+=TMI("mitem 穿上$U;wear "+id);
		else
			tmp+=TMI("mitem 脱下$U;remove "+id);
	}

	if(mapp(prop=ob->query("weapon_prop")) && stringp(ob->query("skill_type"))) {
		if(!ob->query("equipped"))
			tmp+=TMI("mitem 装备$U;wield "+id);
		else
			tmp+=TMI("mitem 解除装备$U;unwield "+id);
	}
	//物品add akai 2006  添加身上物品使用菜单的地方 ////////
	/*****************************************************************************
	*    if(strsrch(id,"sleepbag",-1)!=-1)  //睡带上添加睡觉的菜单
	*         tmp+=TMI("mitem 钻进$U睡觉;sleep");
	*
	*
	*
	*
	*
	*
	*
	*
	*
	*****************************************************************************/
	//////////////////////////////////////在这中间添加身上特殊物品的菜单代码////BEGIN
    if(strsrch(id,"sleepbag",-1)!=-1)  //睡觉
	tmp+=TMI("mitem 钻进$U睡觉;sleep");
	if(strsrch(id,"mian ju",-1)!=-1)//变身
	tmp+=TMI("mitem 带上面具变成某人;pretend 人物ID...");
	
	
	

	
    /////////////////////////////////////////////AKAI//////////////////////END
	if(ob->query("skill"))
		tmp+=TMI("mitem 读$U;study "+id);
	if(objectp(ob)){
	tmp+=TMI("mitem 拍卖$U;auction "+id+" for ... gold");
	tmp+=TMI("mitem 竟标拍卖物品;auction 1 add ... gold");
}
	tmp+=TMI("mendd");
	tell_object(me,tmp);
	return 1;
}

