// setfrd.c
 
#define MAX_FRIENDS     6
 
inherit F_CLEAN_UP;
 
int help();
 
int main(object me, string arg)
{
    int i;
    string *terms;
        mapping friends;
 
 
        friends = me->query("friends");
 
        if( !arg || arg=="" ) {
                write("��Ŀǰ�趨�ĺ����������£�\n");
                if( !mapp(friends) || !sizeof(friends) )
                        write("\tû���趨�κκ��ѡ�\n");
                else {
                        terms = keys(friends);
                        for(i=0; i<sizeof(terms); i++)
                                printf("%s  ", terms[i]); 
                        printf("\n");
                }
                return 1;
        }
        if( arg && arg!="" ) {
            if( mapp(friends) && undefinedp(friends[arg]) && sizeof(friends) >= MAX_FRIENDS )
                return notify_fail("����ĺ���̫���ˣ������� unsetfrd ɾ�������ɡ�\n");
            me->set("friends/" + arg, 1);
            printf("���Ӻ��ѣ�%s  \n", arg);
            return 1;
        }
        return 0;
}

