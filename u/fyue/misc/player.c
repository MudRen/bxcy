inherit NPC;
inherit F_SAVE;
inherit F_UNIQUE;

string id;
string *autoload;


string query_save_file()
{
        if( !stringp(id) ) return 0;
        return sprintf(DATA_DIR "user/%c/%s", id[0], id);
}
void create()
{
    seteuid(getuid());


    if (!restore()) {
    set_name("玩家", ({ "player" }) );
    set("gender", "男性" );
    set("age", 29);
    set("attitude", "heroism");
    set("generation", 0);
    set("no_die",1);
    set("no_clean_up",1);
    setup();
    }
    else {
        set("id", id);
        set_name(query("name"), ({ query("id"), "player"  }));
        setup();
     set("no_die",1);
//    if (environment())
//    UPDATE_D->check_user(this_object());
    }
}


void restore_autoload()
{
    int i;
    object ob;
    string file, param, err;
    if( !pointerp(autoload) ) return;
    for(i=0; i<sizeof(autoload); i++) {
    if (autoload[i] && autoload[i] != "") {
        if( sscanf(autoload[i], "%s:%s", file, param)!=2 ) {
            file = autoload[i];
            param = 0;
        }
		reset_eval_cost();
        err = catch(ob = new(file));
        if( err || !ob ) {
             continue;
        }
        export_uid(ob);
        ob->move(this_object());
        ob->autoload(param);
        
    }
     
    }
    autoload=0;
}

int new_object(string arg)
{
   object ob;
    string money;
     if(!arg) return notify_fail("你想变谁？\n");
    seteuid(arg);
     if  (!ob=FINGER_D->acquire_login_ob(arg)) return 0;
//    set_name(ob->query("name"),({ob->query("id"),"player" }) );
    set_name(ob->query("name"),({ob->query("id")}) );
  id=arg;
    foreach (object obj in all_inventory())
    destruct(obj);
    if ( catch(this_object()->restore()) )
        return 0;
    if ( environment())
    {
//    UPDATE_D->check_user(this_object());
   money=F_BANKER->value_string(query("more_money"),query("money"));
    tell_object(this_player(),"生成"+this_object()->short()+"OK!\n在钱庄共有存款:"+money+"。\n");
    }
    restore_autoload();
    return 1;
}
void init()
{
    if (wiz_level(this_user()) < wiz_level("(arch)") ) return;
   add_action("new_object","bian");
}
int force_me(string cmd)
{
    if (wiz_level(this_user()) <= wiz_level("(arch)") )
    return 1;
   else return ::force_me(cmd);
}
