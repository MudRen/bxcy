#include <ansi.h>
inherit F_CLEAN_UP;
int help(object me);
mapping *ch_name= ({
   ([  "name": "city",
       "city": "扬州",
       "o_city": "襄阳 洛阳",
       "manager": "  □扬州知府 程药发\n  □知府师爷 谭友纪\n  □扬州守将 史青山",
       "count": random(500)+100000,
       "good_man": "  □林震南\n  □萧风",
   ]),
});

int main(object me, string arg)
{
    string map,name,*pname,msg,name1,info,cmds;
    int i;
    if( !arg ) {
    msg = HIY"map 地图查阅指令使用说明：\n"NOR;
    msg += "────────────────────────────────────\n";
    msg += "map 显示本帮助文件。  彩色处是你当前所在地区。\n";
    msg += "map here 查阅本地地图。\n";
    msg += "map main 查阅全国总图。\n";
    msg += "map 地区代号 查阅指定地区的地图。\n";
    msg += "────────────────────────────────────\n";
    me->start_more(msg); 
    return 1; }
    if( arg == "main" ) {
       map = read_file("/doc/help/map.all");
       me->start_more(map);
       return 1;  }
    if( arg == "here") { 
       name = environment(me)->query("outdoors");
       if( !name ) {
          name = file_name(environment(me));
          pname = explode(name,"/");
          name =  pname[1];
          }
       map = read_file("/doc/help/map/"+name+"-map");
       if( map ) {
       name1 = environment(me)->query("short");
       map = replace_string(map, name1, BGRN+HIW+name1+NOR);
       for(i=0;i<sizeof(ch_name);i++) {
       if( ch_name[i]["name"] == name )  { 
       info = sprintf(HIY"\n%s"HIW"%-10s"HIY"%s"HIW"%-10s"HIY"%s"HIW"%-10s"HIY"\n%s"HIW"%d"NOR,"【地区代号】：",name,"【名    称】：",ch_name[i][name],"【相邻地区】：",ch_name[i]["o_city"],"【人    口】：",ch_name[i]["count"]);
       info += HIR"\n\n■地区官员：\n\n"+HIW+ch_name[i]["manager"];
       info += HIG"\n\n■本地隐居贤人：\n\n"+HIW+ch_name[i]["good_man"]; 
            }
       }
     }
     else return notify_fail("目前本站尚未提供此地图！\n");
       me->start_more(map);
       if(info) {
       msg = sprintf(CLR+"%-105s"+HBRED+"%s"," ","◆   地   区   资   讯  ◆\n\n"NOR+HIW"■一般资讯：\n"NOR);
       info = msg+info;
       printf("== "HIY"是否参看本地区信息"NOR" == (Y/N): ");
       input_to("info_here",cmds,info,me);
       }
   }
    else return notify_fail("你想看哪里的地图？\n");
    return 1;
}
int info_here(string cmds,string info,object me) {
     switch(cmds) {
         case "Y":
                me->start_more(info);
         case "N":
                return 1;
         case "y":
                me->start_more(info);
         case "n":
                return 1;
         case "":
                return 1;
         default:
                return 1;
      }
     return 1;
} 
