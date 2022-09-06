//#pragma optimize all

#include <globals.h>
void create()
{
    seteuid( ROOT_UID );
    write("simul_efun �ɹ�����.\n");
}

#include "/adm/simul_efun/atoi.c"
#include "/adm/simul_efun/chinese.c"
#include "/adm/simul_efun/gender.c"
#include "/adm/simul_efun/object.c"
#include "/adm/simul_efun/path.c"
#include "/adm/simul_efun/wizard.c"
// This must be after gender.c
#include "/adm/simul_efun/message.c"
#include "/adm/simul_efun/file.c"
#include "/adm/simul_efun/precision.c"
varargs object snoop(object who, object target) 
{
    if(!target) return efun::snoop(who);
    if(!wizardp(who)) return 0;
    log_file("snoop", who->name() + " snoops " + target->name() +
        " at " + ctime(time()) );
    return efun::snoop(who, target);
}

void shutdown(int etc)
{
    if( base_name(previous_object())!=NATURE_D) return 0;
    else efun::shutdown(etc);
}
void destruct(object ob)
{
    string err;

    if ( ob )
    {
        if ( previous_object() )
            err = catch(ob->remove( geteuid(previous_object()) ));
        else
            err = catch(ob->remove(0));
        if ( err )
        {
            if ( userp(ob) && geteuid(previous_object())!=ROOT_UID )
               return;
        }
        efun::destruct(ob);
    }
}

