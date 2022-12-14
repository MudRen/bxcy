// skills.c
// Write By Zman 1999.05.26
#include <ansi.h>

inherit F_CLEAN_UP;
string tribar_graph(int val, int eff, int max, string bcolor, string fcolor, string dcolor);

string *skill_level_desc = ({
        BLU "初学乍练" NOR,
        HIB "粗通皮毛" NOR,
        HIB "半生不熟" NOR,
        HIB "马马虎虎" NOR,
        HIB "驾轻就熟" NOR,
        CYN "出类拔萃" NOR,
        CYN "神乎其技" NOR,
        CYN "出神入化" NOR,
        HIC "登峰造极" NOR,
        HIC "一代宗师" NOR,
        HIW "深不可测" NOR
});

string *knowledge_level_desc = ({
        BLU "新学乍用" NOR,
        HIB "初窥门径" NOR,
        HIB "略知一二" NOR,
        HIB "马马虎虎" NOR,
        HIB "已有小成" NOR,
        CYN "心领神会" NOR,
        CYN "了然於胸" NOR,
        CYN "豁然贯通" NOR,
        HIC "举世无双" NOR,
        HIC "震古铄今" NOR,
        HIW "深不可测" NOR
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
//                      return notify_fail("你要察看什么？\n");
                ob = present(arg, environment(me));
                if (!ob) ob = find_player(arg);
                if (!ob) ob = find_living(arg);
                if (!ob) return notify_fail("你要察看谁的技能？\n");
        }

        if( ob!=me && !wizardp(me) && !ob->is_apprentice_of(me)
        && !me->is_apprentice_of(ob) )
                return notify_fail("只有巫师或有师徒关系的人能察看他人的技能。\n");

        skl = ob->query_skills();
        if(!sizeof(skl)) {
                write( (ob==me ? "你" : ob->name()) + "目前并没有学会任何技能。\n");
                return 1;
        }
        write( (ob==me ? "你" : ob->name()) +"目前所学过的技能：\n\n");
        sname  = sort_array( keys(skl), (: strcmp :) );
        
        map = ob->query_skill_map();
        if( mapp(map) ) mapped = values(map);
        if( !mapped ) mapped = ({});

        lrn = ob->query_learned();
        if( !mapp(lrn) ) lrn = ([]);
        str = "\n";
        str += HIC"≡"HIR"技能名称"HIY" ("HIR"英文名称"HIY") ────["HIR"exp/lv*lv "HIY"]-"HIR"技能评价"HIY"─"HIR"lv/ exp"HIY"──"HIC"≡\n"NOR;
if (!skill1)
{
        for(i=0; i<sizeof(skl); i++)
        {
                str += sprintf("%s"HBBLU"%s""%-28s" NOR, 
                        (lrn[sname[i]] >= (skl[sname[i]]+1) * (skl[sname[i]]+1)) ? HIM : "",
                        (member_array(sname[i], mapped)==-1? "  ": "☆"),
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
                        (member_array(sname[i], mapped)==-1? "  ": "☆"),
                        to_chinese(sname[i]) + " (" + sname[i] + ")",) 
                +       tribar_graph((int)lrn[sname[i]],skl[sname[i]]*skl[sname[i]], skl[sname[i]]*skl[sname[i]], HBBLU, HIY ,HIR)
                +       sprintf(  "-%-10s%4d/%5d\n", 
                        skill_level(SKILL_D(sname[i])->type(), skl[sname[i]]),
                        skl[sname[i]], (int)lrn[sname[i]], );
                }
        }
}
        str += HIC"≡"HIY"───────────────────────────────"HIC"≡\n"NOR;
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
指令格式 : skills|cha [<某人>] [<技能名>]

这个指令可以让你(你)查询所学过的技能。

你也可以指定一个和你有师徒关系的对象，用 skills 可以查知对方的技能状况。

巫师可以查询任何人或 NPC 的技能状况。

HELP
    );
    return 1;
}

