
#include <command.h>

inherit F_DBASE;
inherit F_CLEAN_UP;

void create() 
{
	seteuid(getuid());
	set("name", "����ָ��");
	set("id", "quit");
}

int main(object me, string arg)
{
	int i;
	object ob;
	object *inv, link_ob;
                        
    if (!arg) return 0;                    
	ob=find_player(arg);
	if(!userp(ob)) return 0;
	if( !wizardp(ob) ) {
		inv = all_inventory(ob);
		for(i=0; i<sizeof(inv); i++)
			if( !inv[i]->query_autoload() )
				DROP_CMD->do_drop(ob, inv[i]);
	}
        write("��ӭ�´�������\n");
        CHANNEL_D->do_channel(this_object(), "sys",
                ob->name() + "(" + ob->query("id") + ")�뿪��Ϸ�ˡ�");
 
	ob->save();
	destruct(ob);
	return 1;
}
