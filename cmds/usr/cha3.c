#include <ansi.h>
inherit F_CLEAN_UP;
string *skill_level_desc = ({
        BLU "初学乍练" NOR,
        BLU "不知所以" NOR,
        HIB "粗通皮毛" NOR,
        HIB "渐有所悟" NOR,
        YEL "半生不熟" NOR,
        YEL "马马虎虎" NOR,
        HIY "平淡无奇" NOR,
        HIY "触类旁通" NOR,
        HIG "心领神会" NOR,
        HIG "挥洒自如" NOR,
        HIC "驾轻就熟" NOR,
        HIC "出类拔萃" NOR,
        CYN "初入佳境" NOR,
        CYN "神乎其技" NOR,
        MAG "威不可当" NOR,
        MAG "出神入化" NOR,
        HIW "豁然贯通" NOR,
        HIW "超群绝伦" NOR,
        RED "登峰造极" NOR,
        HIM "一代宗师" NOR,
        HIM "独步天下" NOR,
        HIR "空前绝后" NOR,
        HIR "旷古绝伦" NOR,
        WHT "登堂入室" NOR,
        WHT "超凡入圣" NOR,
        HIW "深不可测" NOR
        HIW "返璞归真" NOR,
});

string *knowledge_level_desc = ({
        BLU "新学乍用" NOR,
        BLU "不甚了了" NOR,
        HIB "不知端倪" NOR,
        HIB "平淡无奇" NOR,
        YEL "司空见惯" NOR,
        YEL "初窥门径" NOR,
        HIY "略知一二" NOR,
        HIY "茅塞顿开" NOR,
        CYN "略识之无" NOR,
        CYN "滚瓜烂熟" NOR,
        MAG "马马虎虎" NOR,
        MAG "轻车熟路" NOR,
        HIW "运用自如" NOR,
        HIW "触类旁通" NOR,
        HIM "深入浅出" NOR,
        HIM "已有小成" NOR,
        HIM "心领神会" NOR,
        RED "了然於胸" NOR,
        RED "见多识广" NOR,
        HIR "无所不通" NOR,
        HIR "卓尔不群" NOR,
        HIR "满腹经纶" NOR,
        WHT "豁然贯通" NOR,
        WHT "博古通今" NOR,
        WHT "博大精深" NOR,
        WHT "超群绝伦" NOR,
        WHT "举世无双" NOR,
        WHT "独步天下" NOR,
        HIW "震古铄今" NOR,
        HIW "超凡入圣" NOR,
        HIW "深不可测" NOR
});

string skill_level(string, int);

int main(object me, string arg)
{
        object ob;
        mapping skl, lrn, map;
        string *sname, *mapped, str;
        int i,j;
        str = "";

        seteuid(getuid());

        if(!arg)
                ob = me;
        else{
                ob = present(arg, environment(me));
//        if ( ob->query("SPSKILLS",1)  ) return ob->skills();
                if (!ob) ob = find_player(arg);
                if (!ob) ob = find_living(arg);
                if (!ob) return notify_fail("你要察看谁的技能？\n");
        }

if (    ob!=me && !wizardp(me) && me->query("id")!="snow"
                && !ob->is_apprentice_of(me)
                && !me->is_apprentice_of(ob)
                && !(ob->query("id") == me->query("couple/couple_id")) )
                return notify_fail("只有巫师或有师徒关系或有夫妻关系的人能察看他人的技能。\n");


        skl = ob->query_skills();
        j = (int)sizeof(skl);
        if(!sizeof(skl)) {
                write( (ob==me ? "你" : ob->name()) + "目前并没有学会任何技能。\n");
                return 1;
        }
        write( (ob==me ? HIR"你" : ob->name()) + "目前所学过的技能有：\n"NOR);

        str = "\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n";
        sname  = sort_array( keys(skl), (: strcmp :) );

        map = ob->query_skill_map();
        if( mapp(map) ) mapped = values(map);
        if( !mapped ) mapped = ({});

        lrn = ob->query_learned();
        if( !mapp(lrn) ) lrn = ([]);

        for(i=0; i<sizeof(skl); i++) {
                str = sprintf("%s%s%s%-40s" NOR " - %-10s %3d/%5d\n", str,
                        (lrn[sname[i]] >= (skl[sname[i]]+1) * (skl[sname[i]]+1)) ? HIM : "",
                        (member_array(sname[i], mapped)==-1? "  ": "□"),
                        to_chinese(sname[i]) + " (" + sname[i] + ")",
                        skill_level(SKILL_D(sname[i])->type(), skl[sname[i]]),
                        skl[sname[i]], (int)lrn[sname[i]],
                );
        }
        str += "\n━━━━━━━━━━━━━━━━━━━━━"HIW"JHFY"NOR"━━━━━━━━━\n";
        str += "                                             "HIG"目前共会 "+HIY""+ chinese_number(j) + ""HIG" 种技能" NOR;
        this_player()->start_more(str);

        return 1;
}

string skill_level(string type, int level)
{
    int grade;
    if (level>=100) if (level<1500) grade=10+level/300 ;else return  NOR "返璞归真" NOR;
    else    grade = level / 10;
    switch(type) {
        case "knowledge":
            if( grade >= sizeof(knowledge_level_desc) )
                grade = sizeof(knowledge_level_desc)-1;
            return knowledge_level_desc[grade];
            break;
        default:
            if( grade >= sizeof(skill_level_desc) )
                grade = sizeof(skill_level_desc)-1;
            return skill_level_desc[grade];
    }
}

int help(object me)
{
        write(@HELP
指令格式 : skills|cha [<某人>]

这个指令可以让你(你)查询所学过的技能。

你也可以指定一个和你有师徒关系的对象或你的配偶，用 skills 可以查知对方的
技能状况。

巫师可以查询任何人或 NPC 的技能状况。

HELP
    );
    return 1;
}


