
inherit F_CLEAN_UP;

int main(object me)
{
    object *user = users();
    for (int i=0;i<sizeof(user);i++)
    {
    	"/adm/daemons/toptend"->topten_checkplayer(user[i]);
    	reset_eval_cost();
    }
    write("���а�������!\n");
    return 1;
 }
 
 
