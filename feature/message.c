// message.c

// #pragma save_binary
#include <dbase.h>

#define MAX_MSG_BUFFER 500

nosave string *msg_buffer = ({});

void receive_message(string msgclass, string msg)
{
	string subclass, *ch;
        int len;
        object user= this_object();
        if(!msg || (len=strlen(msg))<1) return;
        if(len>8000)
        msg=msg[0..8000]+"\n\n������\n";
	if( !interactive(this_object()) ) {
		this_object()->relay_message(msgclass, msg);
		return;
	}

	if( sscanf(msgclass, "%s:%s", subclass, msgclass)==2 ) {
		switch(subclass) {
			case "channel":
				if( !pointerp(ch = query("channels"))
				||	member_array(msgclass, ch)==-1 )
					return;
                               if(!query("chann/"+msgclass) && user->query_temp("tomud"))
                               msg=TMI("ptext "+(msg));
                          break;
			case "outdoor":
				if( !environment() || !environment()->query("outdoors") )
					return;
				break;
			case "room":
                                if( !environment() || environment()->query("outdoors") )
                                       return;
                                break;
			default:
				error("Message: Invalid Subclass " + subclass + ".\n");
		}
	}

	if( query_temp("block_msg/all") || query_temp("block_msg/" + msgclass) )
		return;

	if( in_input(this_object()) || in_edit(this_object()) ) {
		if( sizeof(msg_buffer) < MAX_MSG_BUFFER )
			msg_buffer += ({ msg });
	} else
		receive( msg );
}

void write_prompt()

{
	if( sizeof(msg_buffer) ) {
		receive(BOLD +"[����ʱ�ݴ�ѶϢ]\n" + NOR);
		for(int i=0; i<sizeof(msg_buffer); i++)
			receive(msg_buffer[i]);
		msg_buffer = ({});
	}
        write(HIM"��"NOR);
}


void receive_snoop(string msg)
{
	receive("%" + msg);
}
