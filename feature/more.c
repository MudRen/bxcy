// more.c
#include <ansi.h>
void more(string cmd, string *text, int line)
{
    int i;
    switch(cmd) {
    case "b":
        line = line - 46;
        if(line<0) line=0;
        write("\n"+ESC+"[1A"+ESC+"[100D"+ESC+"[K\n"+repeat_string("-",100)+"\n");
        for(i=line; line<sizeof(text) && line<i+23; line++)
        write(text[line]+"\n");
        break;
    case "q":
        write(ESC+"[1A"+ESC+"[100D"+ESC+"[K\n");
        return;
    default:
        write(ESC+"[1A"+ESC+"[100D"+ESC+"[K");
        for(i=line + 23; line<sizeof(text) && line<i; line++)
            write(text[line] + "\n");
        if( line>=sizeof(text) ) return;
        break;
    }
    printf("== δ����� " HIY "%d%%" NOR " == ("+HIC+"q"+NOR+" �뿪��"+HIC+"b"+NOR+" ǰһҳ������������һҳ)",
        (line*100/sizeof(text)) );
    input_to("more", text, line);
}
void start_more(string msg)
{
    write("\n");
    more("", explode(msg, "\n"), 0);
}

