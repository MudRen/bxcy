#include <ansi.h>
inherit F_CLEAN_UP;

#define RENWU "/adm/etc/renwu"
nosave mapping wizlevel=([
"(immortal)"    :   "〖寂寞天使〗：",
"(apprentice)"  :   "〖金童玉女〗：",
"(genie)"       :   "〖逍遥神仙〗：",
"(wizard)"      :   "〖天庭侍卫〗：",
"(manager)"   :   CYN"〖"HIG"高级管理人员"NOR CYN+"〗："NOR,
"(angel)"       :   "〖护法天尊〗：",
"(arch)"        :   "〖八部天神〗：",
"(president)"   :   CYN"〖"HIY"管理巫协主席"NOR CYN+"〗："NOR,
"(admin)"       :   "〖天界总管〗：",
"(boss)"        :   "〖天庭波士〗：",
"(ceo)"         :   CYN"〖"HIR"首席执行长官"NOR CYN+"〗："NOR,
]);

int main(object me, string arg)
{
      
        string *list,wiz,quest,msg;
        int i,j;
        mapping quests=([ ]);
        object ob;
        int flag,count;
        
        if (file_size(RENWU))
                foreach (string str in explode(read_file(RENWU),"\n")){
                if( str[0]=='#' || sscanf(str, "%s %s", wiz, quest)!=2 ) continue;
                quests+=([ wiz : quest ]);
            }
        write("【"HIW + MUD_NAME + NOR"】" + "目前的管理人员有：\n");
        
        list = SECURITY_D->query_wizlist();
        count=0;
        for (i=11;i > 0;i--){
            flag=1;
            msg="";
            j=0;
            if(i==10) continue;
            foreach (wiz in list){
                     if (wiz_level(wiz)==i){
                    j++;
                    if (flag){
                        msg+= "\n" + wizlevel[wizhood(wiz)]+"\n";
                        flag=0;
                    }
                 if (objectp(ob=find_player(wiz)) && me->visible(ob) )
                     msg+=(j%3?"":"\n")+"\t("+HIG+wiz+NOR") ";
                    else
                        msg+=(j%3?"":"\n")+"\t("+wiz+") ";
                    if (undefinedp(quests[wiz]))
                        msg+="(暂无任务)";
                    else
                        msg+=quests[wiz];
                    count++;
                }
            }
            write(msg);
        }
        
        write("\n合共有: "HIR+chinese_number(count)+NOR" 位。其中"HIG"亮绿色"NOR"的表示在线管理人员。\n");
   
        return 1;
}

int help(object me)
{
write(@HELP
指令格式 : wizlist

用途 : 列出目前所有的巫师名单。
HELP
     );
     return 1;
}

