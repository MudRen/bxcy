// updated.c
object creat_weapon(object me);
void create() { seteuid(getuid()); }
void check_user(object ob)
{
        object weapon,marry_ring,thousand_gold,cloth;
object g_ob,c_ob,s_ob;
        mapping my;
        string name,id,or,type,time;
        string mname,mid,mor,mtype,mtime;
        int value,lv,mvalue,mlv;
//   temp
       ob->delete("chblk_rumor");
       ob->delete("chblk_chat");
       ob->delete("chblk_shout");
       ob->delete("chblk_es");
//
			g_ob = present("gold_money", ob);
			c_ob = present("coin_money", ob);
			s_ob = present("silver_money", ob);
			if(g_ob)
			if(g_ob->query_amount()>10000)
				g_ob->set_amount(10000);
			if(c_ob)
			if(c_ob->query_amount()>20000)
				c_ob->set_amount(20000);
			if(s_ob)
			if(	s_ob->query_amount()>10000)
				s_ob->set_amount(10000);
    thousand_gold=present("thousand-gold",ob);
    if (thousand_gold){
       if (thousand_gold->query_amount()>1000)
              thousand_gold->set_amount(1000);
    }
    if (ob->is_ghost() && !wizardp(ob)){
        ob->set("jing", 1);
        ob->set("neili", 0);
        ob->set("jingli", 0);
        ob->set("eff_jing", 1);
        ob->set("qi", 1);
        ob->set("eff_qi", 1);
    }
        my = ob->query_entire_dbase();
    if( !pointerp(my["channels"]) )
          my["channels"]=({ "new" });
    else
        if( member_array("new", my["channels"])==-1 )
          my["channels"]+=({ "new" });


     if (my["more_money"]>100) my["more_money"]=100;
       if (!wizardp(ob))
         ob->delete("env/invisibility");
        if( (ob->query("weapon/make")==1) )
        {
                name = ob->query("weapon/name");
                id = ob->query("weapon/id");
                or = ob->query("weapon/or");
                type=ob->query("weapon/type");
                time=ob->query("weapon/time");
                value=ob->query("weapon/value");
                lv = ob->query("weapon/lv");
                if (type=="��"&&id!= "my sword")
                	id="my sword";
if (id=="my sword")
type="��";
                ob->delete("weapon");
                ob->set("weapon/make",1);
                ob->set("weapon/name",name);
                ob->set("weapon/id",id);
                ob->set("weapon/or",or);
                ob->set("weapon/type",type);
                ob->set("weapon/value",value);
                ob->set("weapon/lv",lv);
                ob->set("weapon/time",time);
        }else ob->delete("weapon");
        if( (ob->query("jia/make")==1) )
        {
                mname = ob->query("jia/name");
                mid = "my jia";
                mor = ob->query("jia/or");
                mtype=ob->query("jia/type");
                mtime=ob->query("jia/time");
                mvalue=ob->query("jia/value");
                mlv = ob->query("jia/lv");
                ob->delete("jia");
                ob->set("jia/make",1);
                ob->set("jia/name",mname);
                ob->set("jia/id",mid);
                ob->set("jia/or",mor);
                ob->set("jia/type",mtype);
                ob->set("jia/value",mvalue);
                ob->set("jia/lv",mlv);
                ob->set("jia/time",mtime);
        }else ob->delete("jia");
        if( (ob->query("diablo/cloth/id")=="jia") )
        	ob->set("diablo/cloth/id",mid);
        if (!ob->over_encumbranced()){
                if (stringp(id = ob->query("weapon/id")))
                        if (!present(id,ob)){
                                weapon = creat_weapon(ob);
                                weapon->move(ob);
                                weapon->wield();
                        }
                if (stringp(id = ob->query("jia/id")))
                        if (!present(id,ob)){
                                cloth = new("/d/npc/m_weapon/npc/jia",1);
                                cloth->move(ob);
                                cloth->wear();
                        }
                if (ob->query("couple/have_couple") && !present("marry ring",ob))
                        if (!present("marry ring",ob)){
                                marry_ring= new("/clone/misc/marry_ring");
                                marry_ring->move(ob);
                                marry_ring->wear();
                        }
        }
        if (wizardp(ob)) return;
        if( undefinedp(my["eff_jing"]) ) my["eff_jing"] = my["max_jing"];
        if( undefinedp(my["eff_qi"]) ) my["eff_qi"] = my["max_qi"];
        if( my["eff_jing"] > my["max_jing"] ) my["eff_jing"] = my["max_jing"];
        if( my["eff_qi"] > my["max_qi"] ) my["eff_qi"] = my["max_qi"];
        if( my["jing"] > my["eff_jing"] ) my["jing"] = my["eff_jing"];
        if( my["qi"] > my["eff_qi"] ) my["qi"] = my["eff_qi"];
if ( userp(ob) && ( (my["int"]+my["dex"]+my["con"]+my["str"]) > 100 ) )	
    log_file("cheat_users",sprintf("%s(%s) int=%d,str=%d,con=%d,dex=%d \n",my["name"],my["id"],my["int"],my["str"],my["con"],my["dex"]));

}
object creat_weapon(object me)
{
        object weapon;
        string mask;    //the verible that record the type of weapon
mask = me->query("weapon/type");	
        switch(mask)    {
                case "��":
                        weapon = new("/d/npc/m_weapon/weapon/m_sword",1);
		        if (me->query("max_neili")<1000){
		             weapon->set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
                	     weapon->set("unwield_msg", "$N�����е�$n��ؽ��ʡ�\n");
			}else if (me->query("max_neili")<10000){
		             weapon->set("wield_msg", HIY "$N��ৡ���һ�����$n"+HIY+"���˸�������������â���£������Ƿɡ� \n" NOR);
		             weapon->set("unwield_msg", HIY "$N��ৡ��ذ�$n"+HIY+"��ؽ��ʡ�\n" NOR);
			}else{
		             weapon->set("wield_msg", HIW "$N����������ֻ��һ����â������$N������������Ϣ�ض���һ��$n"+HIW+"��\n" NOR);
		             weapon->set("unwield_msg", HIW "$n"+HIW+"��$N���з����ڰ����һת����ৡ���Ծ�뽣�ʡ�\n" NOR);
			}
		        return weapon;
                case "��":
                        weapon = new("/d/npc/m_weapon/weapon/m_blade",1);
		        return weapon;
                case "��":
                        weapon = new("/d/npc/m_weapon/weapon/m_club",1);
		        return weapon;
                case "��":
                        weapon = new("/d/npc/m_weapon/weapon/m_staff",1);
		        return weapon;
                case "��":
                        weapon = new("/d/npc/m_weapon/weapon/m_whip",1);
		        return weapon;
        }
        return 0;
}
