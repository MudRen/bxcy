// skills.c
// Write By Zman 1999.05.26
#include <ansi.h>

inherit F_CLEAN_UP;
string tribar_graph(int val, int eff, int max, string bcolor, string fcolor, string dcolor);

string *skill_level_desc = ({
        BLU "��ѧէ��" NOR,
        HIB "��ͨƤë" NOR,
        HIB "��������" NOR,
        HIB "������" NOR,
        HIB "�������" NOR,
        CYN "�������" NOR,
        CYN "����似" NOR,
        CYN "�����뻯" NOR,
        HIC "�Ƿ��켫" NOR,
        HIC "һ����ʦ" NOR,
        HIW "��ɲ�" NOR
});

string *knowledge_level_desc = ({
        BLU "��ѧէ��" NOR,
        HIB "�����ž�" NOR,
        HIB "��֪һ��" NOR,
        HIB "������" NOR,
        HIB "����С��" NOR,
        CYN "�������" NOR,
        CYN "��Ȼ���" NOR,
        CYN "��Ȼ��ͨ" NOR,
        HIC "������˫" NOR,
        HIC "������" NOR,
        HIW "��ɲ�" NOR
});

string skill_level(string, int);

int main(object me, string arg)
{
        object ob;
        mapping skl, lrn, map;
        string *sname, *mapped, str, skill1;
        int i;

        seteuid(getuid());

        if(!arg)
                ob = me;
        else
        {
//              if( sscanf(arg, "%s %s", arg, skill1) >= 3 )
//                      return notify_fail("��Ҫ�쿴ʲô��\n");
                ob = present(arg, environment(me));
                if (!ob) ob = find_player(arg);
                if (!ob) ob = find_living(arg);
                if (!ob) return notify_fail("��Ҫ�쿴˭�ļ��ܣ�\n");
        }

        if( ob!=me && !wizardp(me) && !ob->is_apprentice_of(me)
        && !me->is_apprentice_of(ob) )
                return notify_fail("ֻ����ʦ����ʦͽ��ϵ�����ܲ쿴���˵ļ��ܡ�\n");

        skl = ob->query_skills();
        if(!sizeof(skl)) {
                write( (ob==me ? "��" : ob->name()) + "Ŀǰ��û��ѧ���κμ��ܡ�\n");
                return 1;
        }
        write( (ob==me ? "��" : ob->name()) +"Ŀǰ��ѧ���ļ��ܣ�\n\n");
        sname  = sort_array( keys(skl), (: strcmp :) );
        
        map = ob->query_skill_map();
        if( mapp(map) ) mapped = values(map);
        if( !mapped ) mapped = ({});

        lrn = ob->query_learned();
        if( !mapp(lrn) ) lrn = ([]);
        str = "\n";
        str += HIC"��"HIR"��������"HIY" ("HIR"Ӣ������"HIY") ��������["HIR"exp/lv*lv "HIY"]-"HIR"��������"HIY"��"HIR"lv/ exp"HIY"����"HIC"��\n"NOR;
if (!skill1)
{
        for(i=0; i<sizeof(skl); i++)
        {
                str += sprintf("%s"HBBLU"%s""%-28s" NOR, 
                        (lrn[sname[i]] >= (skl[sname[i]]+1) * (skl[sname[i]]+1)) ? HIM : "",
                        (member_array(sname[i], mapped)==-1? "  ": "��"),
                        to_chinese(sname[i]) + " (" + sname[i] + ")",) 
                +       tribar_graph((int)lrn[sname[i]],skl[sname[i]]*skl[sname[i]], skl[sname[i]]*skl[sname[i]], HBBLU, HIY ,HIR)
                +       sprintf(  "-%-10s%4d/%5d\n", 
                        skill_level(SKILL_D(sname[i])->type(), skl[sname[i]]),
                        skl[sname[i]], (int)lrn[sname[i]], );
        }
}
else
{
        for(i=0; i<sizeof(skl); i++)
        {
                if (sname[i] == skill1)
                {
                str += sprintf("%s"HBBLU"%s""%-28s" NOR, 
                        (lrn[sname[i]] >= (skl[sname[i]]+1) * (skl[sname[i]]+1)) ? HIM : "",
                        (member_array(sname[i], mapped)==-1? "  ": "��"),
                        to_chinese(sname[i]) + " (" + sname[i] + ")",) 
                +       tribar_graph((int)lrn[sname[i]],skl[sname[i]]*skl[sname[i]], skl[sname[i]]*skl[sname[i]], HBBLU, HIY ,HIR)
                +       sprintf(  "-%-10s%4d/%5d\n", 
                        skill_level(SKILL_D(sname[i])->type(), skl[sname[i]]),
                        skl[sname[i]], (int)lrn[sname[i]], );
                }
        }
}
        str += HIC"��"HIY"��������������������������������������������������������������"HIC"��\n"NOR;
        str += sprintf("\n");
write(str);
        return 1;
}

string skill_level(string type, int level)
{
        int grade;

    grade = level / 30;

        switch(type) {
                case "knowledge":
                        if( grade >= sizeof(knowledge_level_desc) )
                                grade = sizeof(knowledge_level_desc)-1;
                        return knowledge_level_desc[grade];
                default:
                        if( grade >= sizeof(skill_level_desc) )
                                grade = sizeof(skill_level_desc)-1;
                        return skill_level_desc[grade];
        }
}
string tribar_graph(int val, int eff, int max, string bcolor, string fcolor, string dcolor)
{
        string ret;
        int i, n, eff_n, max_n = 10;

        if( max == 0 ) max = 1;
        n = val * 100 / max / 10;
        eff_n = eff * 100 / max / 5;

        if( n < 0 ) n = 0;
        if( eff_n < 0 ) eff_n = 0;
        if( n > max_n ) n = max_n;
        if( eff_n > max_n ) eff_n = max_n;

        ret = HIC "[" NOR + HIG ;
        for( i = 0 ; i < max_n; i ++ ) {
                if( i > eff_n ) ret += HIG;
                if( i < n )  ret += HBBLU" "NOR;
                else ret += HBRED" "NOR;
        }
        ret += HIG + NOR HIC "]" NOR;
        return ret;
}
int help(object me)
{
        write(@HELP
ָ���ʽ : skills|cha [<ĳ��>] [<������>]

���ָ���������(��)��ѯ��ѧ���ļ��ܡ�

��Ҳ����ָ��һ��������ʦͽ��ϵ�Ķ����� skills ���Բ�֪�Է��ļ���״����

��ʦ���Բ�ѯ�κ��˻� NPC �ļ���״����

HELP
    );
    return 1;
}

