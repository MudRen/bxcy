//Aip@The.Never.Been.Place 6/16/1997
#include "ansi2.h"
inherit NPC;
#define MJ_DATA "/data/obj/mj_data.o"
#define END 286
#define START 0
void check_flower(mapping who);
int to_say_play();
int to_say_rule();
int do_check_Mj(string datastr,string str);
int do_check_eat(string num1,string num2,string LastDump);
int delete_last_dump(string whoId);
int do_check_win(string str);
int check_hu(string strW);
int set_mjdata(object me,int *winner);
int *get_mjdata(string id);
int get_tc(mapping who);
varargs int do_dump(string str,object me);
varargs int do_touch(string str,object me);
varargs int wash_mj(int amount);
varargs int do_win(string str,object me);
varargs int do_gon(string str,object me);
varargs int do_pon(string str,object me);
string check_id(string str,string kind);
string do_delete_Mj(string datastr,string str,int amount);
string show_mj(string str,int flag);
string sort_data(string str);
mixed do_check_num(string str,int flag);
//??ֻ????
string MjE= "1w2w3w4w5w6w7w8w9w1t2t3t4t5t6t7t8t9t1s2s3s4s5s6s7s8s9seasowenojofabaf1f2f3f4f5f6f7f8";
string *MjC = ({"",
                "һ??","????","????","????","????","????","????","????","????",
                "һͲ","??Ͳ","??Ͳ","??Ͳ","??Ͳ","??Ͳ","??Ͳ","??Ͳ","??Ͳ",
                "һ??","????","????","????","????","????","????","????","????",
                "????","?Ϸ?","????","????","????","?෢","?װ?",
                "1 ??","2 ??","3 ??","4 ??","1 ÷","2 ??","3 ??","4 ??","??  "
              });
int K;
string Tc = "";
//????
int Auto;
int Auto_Tin;
int Auto_Gon;
int Auto_Pon;
int Count;
int count;
int end;
int Goned;
int HU_F;
int NO_HU;
int NO_GON;
int Playing;
int Play;
int Times;
int Touched;
int NowPlayer;
string List ="";
string LookP ="";
string *NowPlayerId = ({ "","","","" });
string LastDumpId="";
string LastDump="";
 
mapping P1Data = ([
"Show": "color","Id": "","Name": "","Mj": "","Out": "","OutGon": "","OutPon": "",
"OutFlower": "","Auto": "","AutoTin": "","AutoGon": "","AutoPon": "","Dump": ""
               ]);
mapping P2Data = ([
"Show": "color","Id": "","Name": "","Mj": "","Out": "","OutGon": "","OutPon": "",
"OutFlower": "","Auto": "","AutoTin": "","AutoGon": "","AutoPon": "","Dump": ""
               ]);
mapping P3Data = ([
"Show": "color","Id": "","Name": "","Mj": "","Out": "","OutGon": "","OutPon": "",
"OutFlower": "","Auto": "","AutoTin": "","AutoGon": "","AutoPon": "","Dump": ""
               ]);
mapping P4Data = ([
"Show": "color","Id": "","Name": "","Mj": "","Out": "","OutGon": "","OutPon": "",
"OutFlower": "","Auto": "","AutoTin": "","AutoGon": "","AutoPon": "","Dump": ""
               ]);
void create()
{
set_name("???﹧??",({"eeman"}));
        set_weight(1);
        set("unit","??");
        set("inquiry",([
           "mj": (: to_say_play :),
           "?齫": (: to_say_play :),
           "?淨": (: to_say_play :),
           "play": (: to_say_play :),
           "????": (: to_say_rule :),
           "rule": (: to_say_rule :),
           ]));
        setup();
        seteuid(getuid());
}
void init()
{
   add_action("do_addin","addin");
   add_action("do_dump","dump");
   add_action("do_eat","eat");
   add_action("do_gon","gon");
   add_action("do_win","hu");
   add_action("do_help","help");
   add_action("do_look","look");
   add_action("do_look",".");
   add_action("do_look",".1");
   add_action("do_look",".2");
   add_action("do_look",".3");
   add_action("do_look",".4");
   add_action("do_look","..");
   add_action("do_touch","mo");
   add_action("do_touch","0");
   add_action("do_pon","pon");
   add_action("do_pon","p");
   add_action("do_restart","restart");
   add_action("wash_mj","start");
   add_action("do_setmj","setmj");
   add_action("show_top","top");
   add_action("ch","ch");
}
int do_addin()
{
        object me=this_player();
        if (me->query("id")==P1Data["Id"]
        ||  me->query("id")==P2Data["Id"]
        ||  me->query("id")==P3Data["Id"]
        ||  me->query("id")==P4Data["Id"]){
            if (!Playing) message_vision("$N????Ƿ?Ű???????ͣ?Ŀ޿?????.....??\n",me);
            else message_vision("$N???Ŵ???˵????????"+(random(12)+1)+"?ξͺá?\n",me);
            return 1;
        }
       if (Playing){
                if (random(1))
                message_vision(this_object()->name()+
                "????"+me->name()+"˵?????ƾ????ڽ??????뵽?Ա???һ??...??\n",me);
                else  message_vision("$N??????ҲҪ??????????ͣ?Ŀ޿?????.....??\n",me);
                return 1;
        }
        if (!P1Data["Id"] || P1Data["Id"]==""){
           P1Data["Id"]=me->query("id");
           NowPlayerId[Play]=me->query("id");
           message_vision("$N???????ⳡ?ƾ֡?\n",me);
           Play++;
           Times=0;
           LookP+="??ǰ????"+me->name()+"??";
           return 1;
        }else if (!P2Data["Id"] || P2Data["Id"]==""){
                 P2Data["Id"]=me->query("id");
                 message_vision("$N???????ⳡ?ƾ֡?\n",me);
                 NowPlayerId[Play]=me->query("id");
                 Play++;
                 Times=0;
                 LookP+=me->name()+"??";
                 return 1;
        }else if (!P3Data["Id"] || P3Data["Id"]==""){
                 P3Data["Id"]=me->query("id");
                 message_vision("$N???????ⳡ?ƾ֡?\n",me);
                 NowPlayerId[Play]=me->query("id");
                 Play++;
                 Times=0;
                 LookP+=me->name()+"??";
                 return 1;
        }else if (!P4Data["Id"] || P4Data["Id"]==""){
                 P4Data["Id"]=me->query("id");
                 message_vision("$N???????ⳡ?ƾ֡?\n",me);
                 NowPlayerId[Play]=me->query("id");
                 Play++;
                 Times=0;
                 LookP+=me->name();
                 return wash_mj(Play);
        }
        return notify_fail("???????㡣\n");
}
int do_dump(string str,object me)
{
        int check,i;
        int *winner=({0,0,0,0});
        string ponid;
        mapping who;
        object met;
 
        if (!me) me=this_player();
        if (check_id(me->query("id"),"player")!="");
        else {
           command("stare "+me->query("id"));
           command("say ???ƾָ???û??ϵ??");
           return 1;
        }
        if (!Playing){
           command("kick "+me->query("id"));
           command("say ?ƾֻ?û??ʼ???????Ҷ?!!");
           return 1;
        }
        tell_object(me,"??˭????:"+NowPlayerId[NowPlayer]+"\n");
        if (!str) return notify_fail("ָ??:dump <????>\n");
        if (me->query("id")!=NowPlayerId[NowPlayer]){
           command("hammer "+me->query("id"));
           command("say ??͵????!!???ר??");
           return 1;
        }
        if (!Touched){
           command("faint "+me->query("id"));
           command("say ?㻹û????!!");
           return 1;
        }
        if (Goned==5){
           message_vision("$N˵?????˾???"+HIR+"??  ????"+NOR+"???????¿?ʼ start ??\n",this_object());
           Playing=0;
           Count++;
           if (Play==4){
              for (i=0;i<Play;i++){
                  met=present(NowPlayerId[i], environment(this_object()));
                  if (!met) met=find_player(NowPlayerId[i]);
                  if (!met);
                  else{
                     if (!winner=get_mjdata(NowPlayerId[i])) winner=({0,0,0,0});
                     winner[0]++;
                     set_mjdata(met,winner);
                  }
              }
           }
           return 1;
        }
        NO_HU=0;
        HU_F=0;
        NO_GON=0;
        if (me->query("id")==P1Data["Id"]) who=P1Data;
        else if (me->query("id")==P2Data["Id"]) who=P2Data;
        else if (me->query("id")==P3Data["Id"]) who=P3Data;
        else if (me->query("id")==P4Data["Id"]) who=P4Data;
        check=do_check_Mj(MjE,str);
        if (check==0) return notify_fail("û??["+str+"]???ִ??롣\n");
        check=do_check_Mj(who["Mj"],str);
        if (check==0) return notify_fail("??û"+do_check_num(str,0)+"?????ơ?\n");
        tell_object(me,"??˵????"+do_check_num(str,0)+"\n");
        tell_room(environment(this_object()),me->name()+"˵????"+do_check_num(str,0)+"\n",me);
        command("say "+me->name()+"??????һ??"+do_check_num(str,0));
        who["Mj"]=do_delete_Mj(who["Mj"],str,1);
        LastDump=str;
        who["Dump"]+=str;
        LastDumpId=who["Id"];
        Touched=0;
        NowPlayer++;
        NowPlayer%=Play;
        message_vision("$N˵?????????ֵ?"+HIY+NowPlayerId[NowPlayer]+NOR+"???ơ?\n",this_object());
        if (Auto_Tin){
           ponid=check_id(str,"tin");
           if (ponid!=""){
              me=present(ponid, environment(this_object()));
              if (!me) me=find_player(ponid);
              if (!me) return 1;
              return do_win(str,me);
           }
        }
        if (Auto_Gon){
           ponid=check_id(str,"gon");
           if (ponid!=""){
              me=present(ponid, environment(this_object()));
              if (!me) me=find_player(ponid);
              if (!me) return 1;
              do_gon(str,me);
           }
        }
        if (Auto_Pon){
           ponid=check_id(str,"pon");
           if (ponid!=""){
              me=present(ponid, environment(this_object()));
              if (!me) me=find_player(ponid);
              if (!me) return 1;
              do_pon(str,me);
           }
        }
        if (count==(end-16-Goned)){
           Playing=0;
           Count++;
           message_vision("$N˵?????˾?"+HIY+"????"+NOR+"???????¿?ʼ "+HIR+"start"+NOR+" ??\n",this_object());
           str="??ʣ?µ???ֻ??:"+show_mj(List[count..end],2)+"\n";
           tell_room(environment(this_object()),str);
           if (Play==4){
              for (i=0;i<Play;i++){
                  met=present(NowPlayerId[i], environment(this_object()));
                  if (!met) met=find_player(NowPlayerId[i]);
                  if (!met);
                  else{
                     if (!winner=get_mjdata(NowPlayerId[i])) winner=({0,0,0,0});
                     winner[0]++;
                     set_mjdata(met,winner);
                  }
              }
           }
           return 1;
        }
        if (Auto){
           if (NowPlayerId[NowPlayer]==P1Data["Id"]) who=P1Data;
           else if (NowPlayerId[NowPlayer]==P2Data["Id"]) who=P2Data;
           else if (NowPlayerId[NowPlayer]==P3Data["Id"]) who=P3Data;
           else if (NowPlayerId[NowPlayer]==P4Data["Id"]) who=P4Data;
           if (who["Auto"]=="auto"){
              me=present(NowPlayerId[NowPlayer], environment(this_object()));
              if (!me) me=find_player(NowPlayerId[NowPlayer]);
              if (!me) return 1;
              call_out("do_touch",1,"AUTO",me);
           }
        }
        return 1;
}
int do_eat(string str)
{
        int LastDumpMan,i;
        string num1,num2;
        object me=this_player();
        mapping who;
 
        if (!str || sscanf(str,"%s %s",num1,num2)!=2) return 0;
        if (check_id(me->query("id"),"player")!="");
        else {
           command("stare "+me->query("id"));
           command("say ???ƾָ???û??ϵ??");
           return 1;
        }
        if (!Playing){
           command("say ?ƾֻ?û??ʼ??");
           return 1;
        }
        tell_object(me,"??˭????:"+NowPlayerId[NowPlayer]+"\n");
        if (me->query("id")!=NowPlayerId[NowPlayer]){
           command("hammer "+me->query("id"));
           command("say ??û?ֵ??㡣");
           return 1;
        }
        if (!LastDump || LastDump==""){
           command("hammer "+me->query("id"));
           command("say ???ưɡ?");
           return 1;
        }
        if (Touched){
           command("flop "+me->query("id"));
           command("say ??????!!");
           return 1;
        }
        if (do_check_eat(num1,num2,LastDump)==0){
           command("flop "+me->name());
           command("say ???۾????˨?!!????Ҳ?ܳԡ?");
           return 1;
        }
        if (num1==num2){
           command("flop "+me->name());
           command("say ??ͬ???Ʋ??ܳԡ?");
           return 1;
        }
        if (me->query("id")==P1Data["Id"]) who=P1Data;
        else if (me->query("id")==P2Data["Id"]) who=P2Data;
        else if (me->query("id")==P3Data["Id"]) who=P3Data;
        else if (me->query("id")==P4Data["Id"]) who=P4Data;
        LastDumpMan=do_check_Mj(MjE,num1);
        if (LastDumpMan==0) return notify_fail("û??["+num1+"]???ִ??롣\n");
        LastDumpMan=do_check_Mj(MjE,num2);
        if (LastDumpMan==0) return notify_fail("û??["+num2+"]???ִ??롣\n");
        LastDumpMan=do_check_Mj(who["Mj"],num1);
        if (LastDumpMan==0) return notify_fail("??û"+do_check_num(num1,0)+"?????ơ?\n");
        LastDumpMan=do_check_Mj(who["Mj"],num2);
        if (LastDumpMan==0) return notify_fail("??û"+do_check_num(num2,0)+"?????ơ?\n");
 message_vision("\n$N?ó???һ??"+HIG+do_check_num(num1,0)+NOR+
                      "??һ??"+HIY+do_check_num(num2,0)+NOR+
                      "??????"+HIR+do_check_num(LastDump,0)+NOR+"??\n\n",me);
        who["Out"]+=num2;
        who["Out"]+=LastDump;
        who["Out"]+=num1;
        who["Mj"]=do_delete_Mj(who["Mj"],num1,1);
        who["Mj"]=do_delete_Mj(who["Mj"],num2,1);
        Touched=1;
        NO_HU=1;
        NO_GON=1;
        i=0;
        if (who["Show"]=="????") i=3;
        if (who["Show"]=="color") i=5;
        tell_object(me,show_mj(who["Mj"],i));
        return delete_last_dump(who["Id"]);
}
int do_gon(string str,object me)
{
        int i;
        mapping who;
 
        if (!me) me=this_player();
        if (check_id(me->query("id"),"player")!="");
        else {
           command("stare "+me->query("id"));
           command("say ???ƾָ???û??ϵ??");
           return 1;
        }
        if (!Playing){
           command("say ?ƾֻ?û??ʼ!!");
           return 1;
        }
        if (LastDumpId==me->query("id")){
           command("stare "+me->query("id"));
           command("say ???????????Լ?????!??");
           return 1;
        }
        if (Touched && NowPlayerId[NowPlayer]!=me->query("id")){
           command("hammer "+me->query("id"));
           command("say ????û??????????  ??");
           return 1;
        }
        if (!str) str=LastDump;
 
        if (me->query("id")==P1Data["Id"]) who=P1Data;
        else if (me->query("id")==P2Data["Id"]) who=P2Data;
        else if (me->query("id")==P3Data["Id"]) who=P3Data;
        else if (me->query("id")==P4Data["Id"]) who=P4Data;
        if (who["Auto"]=="auto") return 1;
        i=do_check_Mj(who["Mj"],str);
        if (i==1){
           if (!Touched) return notify_fail("?㻹û???ơ?\n");
           i=do_check_Mj(who["OutPon"],str);
           if (!i) return notify_fail("??ֻ??һ?Ų???  ??\n");
           if (NO_GON) return notify_fail("?????޷?  ?ơ?\n");
              message_vision("\n$N˵????"+HIB+"ľ??"+NOR+"??????\n\n",me);
              who["Mj"]=do_delete_Mj(who["Mj"],str,1);
              sort_data(who["OutPon"]+=str);
              str=List[end..end+1];
              end-=2;
              Goned++;
              message_vision("\n$N?????油??һ???ơ?\n\n",me);
              printf("?㲹??һ??%s\n",do_check_num(str,0));
              i=0;
              if (who["Show"]=="????") i=3;
              if (who["Show"]=="color") i=5;
              who["Mj"]+=str;
              check_flower(who);
              tell_object(me,show_mj(who["Mj"],i));
              Touched=1;
              return 1;
        }
        if (i < 3) return notify_fail("??????Ҫ??????"+do_check_num(str,0)+"????  ??\n");
        if (!Touched){
           if (str!=LastDump) return notify_fail("?????޷?  ??\n");
        }
        else if (i < 4) return notify_fail("??????Ҫ??????"+do_check_num(str,0)+"???ܰ?  ??\n");
        for (i=0;i<Play;i++) {
            if (NowPlayerId[NowPlayer]==me->query("id")) break;
            NowPlayer++;
            NowPlayer%=Play;
        }
        who["Mj"]=do_delete_Mj(who["Mj"],str,3);
        if (Touched && NowPlayerId[NowPlayer]==me->query("id")){
           NO_HU=0;
           message_vision("\n$N????¶??а????Ц??˵??????  hehe.....\n\n",me);
           who["Mj"]=do_delete_Mj(who["Mj"],str,1);
           for (i=0;i<4;i++) who["Out"]+="xx";
           for (i=0;i<4;i++) who["OutGon"]+=str;
        }else{
           NO_HU=1;
           message_vision("\n$N???У?"+do_check_num(str,0)+"??"+HIW+"ľ????????"+NOR+"\n\n",me);
           for (i=0;i<4;i++) who["Out"]+=str;
        }
        str=List[end..end+1];
        end-=2;
        Goned++;
        message_vision("$N?????油??һ???ơ?\n",me);
        tell_object(me,"?㲹??һ??"+do_check_num(str,0)+"\n");
        who["Mj"]+=str;
        check_flower(who);
        i=0;
        if (who["Show"]=="????") i=3;
        if (who["Show"]=="color") i=5;
        tell_object(me,show_mj(who["Mj"],i));
        if (Touched) return 1;
        Touched=1;
        return delete_last_dump(who["Id"]);
}
varargs int do_win(string str,object me)
{
        int i,j;
        int *winner=({0,0,0,0});
        string Mj="";
        mapping who;
        object met;
 
        if (!me) me=this_player();
        if (check_id(me->query("id"),"player")!="");
        else {
           command("stare "+me->query("id"));
           command("say ???ƾָ???û??ϵ??");
           return 1;
        }
        if (!Playing){
           command("say ?ƾֻ?û??ʼ...");
           return 1;
        }
        if (NO_HU || LastDumpId==me->query("id")) return notify_fail("???????ܺ??ơ?\n");
        if (LastDump==""&&Touched) message_vision("\n$N???У?"+HIW+"?졫????????????"+NOR+"\n\n",me);
        else{
             tell_room(environment(this_object()),"\n"+me->name()+"???У?"+HIW+"?ҡ?????????"+NOR+"\n\n",me);
             tell_object(me,"\n?????У?"+HIW+"?ҡ?????????"+NOR+"\n\n");
        }
        if (Touched&&NowPlayerId[NowPlayer]==me->query("id"))
           message_vision("$N˵????????"+me->name()+HIG+"????"+NOR+"??????????????"+HIR+"?Ժ?"+NOR+"??????????\n",this_object());
        else command("say "+me->name()+"????");
        if (me->query("id")==P1Data["Id"]) who=P1Data;
        else if (me->query("id")==P2Data["Id"]) who=P2Data;
        else if (me->query("id")==P3Data["Id"]) who=P3Data;
        else if (me->query("id")==P4Data["Id"]) who=P4Data;
        if (sizeof(who["OutFlower"]) ==16) i=1;
        else if (sizeof(who["OutFlower"]) ==14&&sizeof(P1Data["OutFlower"]+P2Data["OutFlower"]+P3Data["OutFlower"]+P4Data["OutFlower"])==16) i=1;
        if (!HU_F) i=0;
        if (i){
           Mj+="???ҵĻ?????:\n";
           Mj+=show_mj(who["OutFlower"],1);
           if (NowPlayerId[NowPlayer]==who["Id"]) Mj+="???һ???????\n";
           else{
             if (sizeof(P1Data["OutFlower"])==2) LastDumpId=P1Data["Id"];
             else if (sizeof(P2Data["OutFlower"])==2) LastDumpId=P2Data["Id"];
             else if (sizeof(P3Data["OutFlower"])==2) LastDumpId=P3Data["Id"];
             else if (sizeof(P4Data["OutFlower"])==2) LastDumpId=P4Data["Id"];
             Mj+="\n???Ʒ?ǹ??:"+HIB+LastDumpId+NOR+"\n";
           }
        }else{
          Mj+="???ҵ?????:\n";
          if (who["OutGon"]!=""){
             Mj+="??  ????:\n";
             Mj+=show_mj(who["OutGon"],0);
          }
          Mj+=who["Id"]+":???е?????:\n";
          if (!Touched){
             who["Mj"]+=LastDump;
             who["Mj"]=sort_data(who["Mj"]);
             Mj+=show_mj(who["Mj"],0);
             Mj+="??????????:"+HIR+do_check_num(LastDump,0)+NOR;
             Mj+="\n??ǹ??:"+HIB+LastDumpId+NOR+"\n";
          }else{
             Mj+=show_mj(who["Mj"],0);
             if (str) Mj+="????????????:"+HIR+do_check_num(str,0)+NOR+"\n";
          }
        }
        Playing=0;
        tell_room(environment(this_object()),Mj);
        Tc="";
        if (do_check_win(who["Mj"])==1||i==1){
//??̨///////////////////////////////////
        mixed MjT = ([
"@1" : ({ "ׯ??", 1 }),"@2" : ({ "????", 1 }),"@3" : ({ "????", 1 }),"@4" : ({ "????", 1 }),
"@5" : ({ "????", 1 }),"@6" : ({ "?Ϸ?", 1 }),"@7" : ({ "????", 1 }),"@8" : ({ "????", 1 }),
"@9" : ({ "????", 1 }),"@0" : ({ "?෢", 1 }),"@a" : ({ "?װ?", 1 }),"@G" : ({ "һ  ??", 1 }),
"@b" : ({ "????????", 1 }),"@c" : ({ "????????", 1 }),"@d" : ({ "ƽ??", 2 }),"@e" : ({ "???綫", 2 }),
"@f" : ({ "?Ϸ???", 2 }),"@g" : ({ "??????", 2 }),"@h" : ({ "???籱", 2 }),"@i" : ({ "ȫ????", 2 }),
"@j" : ({ "??????", 2 }),"@H" : ({ "??  ??", 2 }),"@k" : ({ "??  ??", 2 }),"@B" : ({ "?????ﶬ", 2 }),
"@C" : ({ "÷??????", 2 }),"@l" : ({ "????????", 3 }),"@m" : ({ "??????", 4 }),"@n" : ({ "??һɫ", 4 }),
"@o" : ({ "С??Ԫ", 4 }),"@p" : ({ "?İ???", 6 }),"@q" : ({ "??һɫ", 8 }),"@r" : ({ "??һɫ", 8 }),
"@s" : ({ "?߶???", 8 }),"@t" : ({ "????Ԫ", 8 }),"@u" : ({ "?尵??", 8 }),"@F" : ({ "С??ϲ", 8 }),
"@D" : ({ "????һ", 8 }),"@E" : ({ "??һɫ", 16 }),"@v" : ({ "????ϲ", 16 }),"@w" : ({ "????", 16 }),
"@x" : ({ "?غ?", 16 }),"@y" : ({ "?˺?", 16 }),"@z" : ({ "??ʿ??˫", 16 }),"@A" : ({ "???ɹ???", 16 }),
"@J" : ({ "????ͷ", 8 }),"@I" : ({ "????ͷ", 4 }),
]);//H
           get_tc(who);
////////////////
           str="\t\t\t?ԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡ?\n";
           for (i=0;i<sizeof(Tc);i+=2){
              str+=sprintf("\t\t\t%-12s%8s ̨\n",MjT[Tc[i..i+1]][0],chinese_number(MjT[Tc[i..i+1]][1]));
              j+=MjT[Tc[i..i+1]][1];
           }
           if (Count){
              str+=sprintf("\t\t\t%-12s%8s ̨\n","??"+chinese_number(Count)+"??"+chinese_number(Count),chinese_number(Count*2));
              j+=Count*2;
           }
           str+=sprintf("\t\t\t%20s\n","??̨??:"+chinese_number(j+5)+" ̨");
           str+="\t\t\t?ԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡ?\n";
           tell_room(environment(this_player()),str);
/////////////
           if (!Touched){
              if (Play==4){
                 if (!winner=get_mjdata(me->query("id"))) winner=({0,0,0,0});
                 winner[1]+=j;
                 set_mjdata(me,winner);
                 met=present(LastDumpId, environment(this_object()));
                 if (!met) met=find_player(LastDumpId);
                 if (!met);
                 else{
                    if (!winner=get_mjdata(LastDumpId)) winner=({0,0,0,0});
                    winner[1]-=j; //ս??
                    winner[3]++; //??ǹ
                    set_mjdata(met,winner);
                 }
                 for (i=0;i<Play;i++){
                     met=present(NowPlayerId[i], environment(this_object()));
                     if (!met) met=find_player(NowPlayerId[i]);
                     if (!met);
                     else{
                        if (!winner=get_mjdata(NowPlayerId[i])) winner=({0,0,0,0});
                        winner[0]++; //????
                        set_mjdata(met,winner);
                     }
                 }
              }
           }else{
              if (Play==4){
                 if (!winner=get_mjdata(me->query("id"))) winner=({0,0,0,0});
                 winner[0]++;
                 winner[1]+=(j*3);
                 winner[2]++;
                 set_mjdata(me,winner);
                 for (i=0;i<Play;i++){
                     if (NowPlayerId[i]==me->query("id")) continue;
                     met=present(NowPlayerId[i], environment(this_object()));
                     if (!met) met=find_player(NowPlayerId[i]);
                     if (!met);
                     else{
                        if (!winner=get_mjdata(NowPlayerId[i])) winner=({0,0,0,0});
                        winner[0]++;
                        winner[1]-=j;
                        set_mjdata(met,winner);
                     }
                 }
              }
           }
         if (NowPlayerId[0]==who["Id"]) Count++;
         else{
           Times++;
           Count=0;
         }
        }else{
           command("sigh "+who["Id"]);
           message_vision("$N˵???????? ["+HIR+who["Id"]+HIG+"] ??է?? ???¡?????"+NOR+"??\n",this_object());
           Times++;
           Count=0;
           if (Play==4){
              if (!winner=get_mjdata(me->query("id"))) winner=({0,0,0,0});
              if (NowPlayerId[NowPlayer]==who["Id"]&&Touched){
                 if (who["Out"]==""&&who["OutPon"]==""){
                    winner[1]-=24;
                    j=-24;
                 }else {
                    winner[1]-=18;
                    j=-18;
                 }
              }else{
                 if (who["Out"]==""&&who["OutPon"]==""){
                    winner[1]-=6;
                    j=-6;
                 }else{
                    winner[1]-=5;
                    j=-5;
                 }
              }
////////////////
              str="\t\t\t?ԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡ?\n";
              str+=sprintf("\t\t\t%-12s%8s ̨\n","??է????",chinese_number(j));
              str+=sprintf("\t\t\t%20s\n","??̨??:"+chinese_number(j+5)+" ̨");
              str+="\t\t\t?ԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡ?\n";
              tell_room(environment(this_player()),str);
/////////////
              set_mjdata(me,winner);
              for (i=0;i<Play;i++){
                  met=present(NowPlayerId[i], environment(this_object()));
                  if (!met) met=find_player(NowPlayerId[i]);
                  if (!met);
                  else{
                     if (!winner=get_mjdata(NowPlayerId[i])) winner=({0,0,0,0});
                     winner[0]++;
                     set_mjdata(met,winner);
                  }
              }
           }
        }
        Mj="\n[0;1;36;46m  ";
        for (i=0; i<26; i++) Mj+="  ";
        Mj+="[1;36;46m  [0m\n";
        Mj+="[1;36;46m  [0;36m??    "+HIW+"??[0m??????  [1m??[0m??????  [1m??[0mս??  [1m??[0m??????  [1m??[0mǹ????[1;36;46m??[0m\n";
        for (i=0;i<Play;i++){
            if (Play==4) winner=get_mjdata(NowPlayerId[i]);
            Mj+=sprintf("[1;36;46m  [0;36m??[1;37m%12s  [33m%8d  [35m%6d  [32m%8d  [34m%8d[1;36;46m??[0m\n",
                         NowPlayerId[i],winner[0],winner[1],winner[2],winner[3]);
        }
        Mj+="[1;36;46m  ";
        for (i=0; i<26; i++) Mj+="  ";
        Mj+="[46m??[0m\n";
        if (Play==4) tell_room(environment(this_object()),Mj);
        return wash_mj(Play);
}
int do_check_win(string str)
{
        int size=strlen(str),i,check;
        int t,k,W,T,S,Sp;
        string tempW="",tempT="",tempS="",tempB="";
        string Special="1w9w1s9s1t9teasowenojofaba";
 
        K=0;
        if (size > 33){
           if (do_check_Mj(str,"ea")&&do_check_Mj(str,"so")&&do_check_Mj(str,"we")&&do_check_Mj(str,"no")&&
               do_check_Mj(str,"jo")&&do_check_Mj(str,"fa")&&do_check_Mj(str,"ba")&&
               do_check_Mj(str,"1w")&&do_check_Mj(str,"9w")&&do_check_Mj(str,"1s")&&
               do_check_Mj(str,"9s")&&do_check_Mj(str,"1t")&&do_check_Mj(str,"9t")){
                  //??ɾ??13ֻ
                  for (i=0;i<sizeof(Special);i+=2) {
                      if (do_check_Mj(str,Special[i..i+1])){
                         str=do_delete_Mj(str,Special[i..i+1],1);
                      }
                  }
                  //?黹??û13ô?е???ֻ
                  for (i=0;i<sizeof(Special);i+=2) {
                      if (do_check_Mj(str,Special[i..i+1])){
                         Sp++;
                      }
                  }
                  if (Sp==1){
                     for (i=0;i<sizeof(Special);i+=2) {
                         if (do_check_Mj(str,Special[i..i+1])){
                            str=do_delete_Mj(str,Special[i..i+1],1);
                            t++;
                          Tc+="@z";//13ô
                         }
                     }
                  }
                  else if (Sp==2){
                    for (i=0;i<sizeof(str);i+=2){
                         if (do_check_Mj(str,str[i..i+1])==2){
                            str=do_delete_Mj(str,str[i..i+1],1);
                            Sp=0;
                            t++;
                         }
                    }
                    if (Sp!=0){
                       if (str[0..1]+1==str[2..3]){
                          str=do_delete_Mj(str,str[6..7],1);
                          t++;
                       }else{
                          str=do_delete_Mj(str,str[0..1],1);
                          t++;
                       }
                    }
                  }
           }else{
              for (i=0;i<sizeof(str);i+=2){
                   if (do_check_Mj(str,str[i..i+1])==2) Sp++;
                   else if (do_check_Mj(str,str[i..i+1])==3) check++;
                   else if (do_check_Mj(str,str[i..i+1])==4) Sp++;
              }
              if (Sp==14&&check==3){
                  for (i=0;i<sizeof(str);i+=2){
                      if (do_check_Mj(str,str[i..i+1])==2){
                         str=do_delete_Mj(str,str[i..i+1],2);
                         i=-2;
                      }
                      else if (do_check_Mj(str,str[i..i+1])==4){
                              str=do_delete_Mj(str,str[i..i+1],4);
                              i=-2;
                      }
                      else if (do_check_Mj(str,str[i..i+1])==3) t++;
                  }
                  t=1;
                  Tc+="@s";//7????
              }
           }
        }
        while(size--){
              size--;
          if (do_check_num(str[size..size+1],1) < 10) tempW+=str[size..size+1];
          else if (do_check_num(str[size..size+1],1) < 19) tempT+=str[size..size+1];
          else if (do_check_num(str[size..size+1],1) < 28) tempS+=str[size..size+1];
          else tempB+=str[size..size+1];
        }
        if (tempB!=""){
           for (i=0;i<strlen(tempB);i+=2){//
               check=do_check_Mj(tempB,tempB[i..i+1]);
               if (check==1) return 0;
               else if (check==2){
                       tempB=do_delete_Mj(tempB,tempB[i..i+1],2);
                       t++;
                       i=-2;
               }else if (check==3){
                        tempB=do_delete_Mj(tempB,tempB[i..i+1],3);
                        K++;
                        i=-2;
               }
           }//
        }
        if (tempW!="") W=check_hu(tempW);
        if (tempT!="") T=check_hu(tempT);
        if (tempS!="") S=check_hu(tempS);
        if (K==3) Tc+="@j";//??????
        else if (K==4) Tc+="@p";//?İ???
        else if (K==5) Tc+="@u";//?尵??
        if (W+T+S+t==1) return 1;
        return 0;
}
int check_hu(string strW)
{
        int i,j,check;
        int k,t;
        int A,B,C,D,E,F;
        for (i=0;i<sizeof(strW);i+=2) {//?ٰ?˳??ɾ??
        A=do_check_num(strW[i..i+1],2);
        B=do_check_num(strW[i+2..i+3],2);
        C=do_check_num(strW[i+4..i+5],2);
        D=do_check_num(strW[i+6..i+7],2);
        E=do_check_num(strW[i+8..i+9],2);
        F=do_check_num(strW[i+10..i+11],2);
        if (sizeof(strW) > 11 &&do_check_num(strW[i-2..i-1],2)!=A&&A+1==B&&B==C&&C+1==D&&D==E&&E+1==F
           ||do_check_num(strW[i-2..i-1],2)!=A&&A==B&&B+1==C&&C==D&&D+1==E&&E==F){
              if (A==B&&B+1==C&&C==D&&D+1==E&&E==F){
                 if (do_check_Mj(Tc,"@G")==1){
                    Tc=do_delete_Mj(Tc,"@H",1);
                    Tc+="@H";
                 }else        Tc+="@G";
              }
              for (j=0;j<6;j++) {  //ɾ??˳??1 22 33 4 && 22 33 44
                  strW=do_delete_Mj(strW,strW[i..i+1],1);
              }
           i=-2;
        }
        else if (A+1==B&&B==C&&C==D&&D==E&&E+1==F){
              for (j=0;j<2;j++) {  //ɾ??˳??1 2 2 2 2 3
                  strW=do_delete_Mj(strW,strW[i..i+1],1);
              }
              strW=do_delete_Mj(strW,strW[i+6..i+7],1);
           i=-2;
           }
        else if (sizeof(strW) > 9 && A+1==B&&B==C&&C==D&&D+1==E){
              //ɾ??˳??12223?е?1 2 3
                  strW=do_delete_Mj(strW,strW[i..i+1],1);
                  strW=do_delete_Mj(strW,strW[i..i+1],1);
                  strW=do_delete_Mj(strW,strW[i+4..i+5],1);
           i=-2;
        }
        else if (sizeof(strW) > 9 && A==B&&B+1==C&&C+1==D&&D+1==E){
             for (j=0;j<3;j++) {   //ɾ??˳??11234?е?2 3 4
                 strW=do_delete_Mj(strW,strW[i+4..i+5],1);
             }
           i=-2;
        }
        else if (sizeof(strW) > 5 && A+1==B&&B+1==C){
             for (j=0;j<3;j++) {   //ɾ??˳??123?е?1 2 3
                 strW=do_delete_Mj(strW,strW[i..i+1],1);
             }
           i=-2;
        }
        }
 
        if (sizeof(strW) > 5){
           for (i=0;i<sizeof(strW);i+=2) {//?ٰѿ?ɾ??
               check=do_check_Mj(strW,strW[i..i+1]);
               if (check==3){
                  K++;
                  strW=do_delete_Mj(strW,strW[i..i+1],3);
                  i=-2;
                  }
              }
           }
           for (i=0;i<sizeof(strW);i+=2) {//?ٰѶ?ɾ??
               check=do_check_Mj(strW,strW[i..i+1]);
               if (check==2){
                  t++;
                  strW=do_delete_Mj(strW,strW[i..i+1],2);
                  i=-2;
               }
           }
           if (strW!="") return 99;
           return t;
}
int do_touch(string str,object me)
{
        int i,check;
        mapping who;
 
        if (!me) me=this_player();
        if (check_id(me->query("id"),"player")!="");
        else {
           command("stare "+me->query("id"));
           command("say ???ƾָ???û??ϵ??");
           return 1;
        }
        if (!Playing){
           command("say ?ƾֻ?û??ʼ??Ҫ????ȥ????????~~");
           return 1;
        }
        tell_object(me,"??˭????:"+NowPlayerId[NowPlayer]+"\n");
        if (me->query("id")!=NowPlayerId[NowPlayer]){
           command("hammer "+me->query("id"));
           command("say ??͵??!!û????????~~");
           return 1;
        }
        if (Touched){
           command("flop "+me->query("id"));
           command("say ??????!!");
           return 1;
        }
        NO_HU=0;
        NO_GON=0;
        if (me->query("id")==P1Data["Id"]) who=P1Data;
        else if (me->query("id")==P2Data["Id"]) who=P2Data;
        else if (me->query("id")==P3Data["Id"]) who=P3Data;
        else if (me->query("id")==P4Data["Id"]) who=P4Data;
        if (who["Auto"]=="auto"){
           if (str=="AUTO");
           else{
             write("?趨?Զ??????ᡢ?????Լ????ơ?\n");
              return 1;
            }
        }
        Touched=1;
        str=List[count..count+1];
        count+=2;
        tell_room(environment(this_object()),me->name()+"????һ???ơ?\n",me);
        tell_object(me,"??????һ???ơ?\n");
        tell_object(me,"??????һ??"+do_check_num(str,0)+"\n");
        if (who["Auto"]=="auto"){
           if (do_check_num(str,1) > 34){
              for (i=0;i<1;i++){
                   who["OutFlower"]+=str;
                   HU_F=1;
                   tell_room(environment(this_object()),me->name()+"˵????"+HIB+"????"+NOR+"????!!??\n\n"+me->name()+"?????油??һ???ơ?\n",me);
                   tell_object(me,"??˵????"+HIB+"????"+NOR+"????!!??\n\n???????油??һ???ơ?\n");
                   str=List[end..end+1];
                   end-=2;
                   tell_object(me,"????????һ??"+do_check_num(str,0)+"\n");
                   if (do_check_num(str,1) > 34) i--;
              }
           }
           check=do_check_Mj(who["AutoTin"],str);
           if (check!=0){
              who["Mj"]+=str;
              who["Mj"]=sort_data(who["Mj"]);
              return do_win(str,me);
           }
           call_out("do_dump",0,str,me);
        }
        who["Mj"]+=str;
        check_flower(who);
        i=0;
        if (who["Show"]=="????") i=3;
        if (who["Show"]=="color") i=5;
        tell_object(me,show_mj(who["Mj"],i));
        return 1;
}
int do_pon(string str,object me)
{
        int i;
        mapping who;
 
        if (!me) me=this_player();
        if (check_id(me->query("id"),"player")!="");
        else {
           command("stare "+me->query("id"));
           command("say ???ƾָ???û??ϵ??");
           return 1;
        }
        if (!Playing){
           command("die "+me->query("id"));
           command("say ?ƾֻ?û??ʼ!!??????ͷ??!!");
           return 1;
        }
        if (Touched){
           command("hammer "+me->query("id"));
           command("say ????û??????????????");
           return 1;
        }
        if (LastDumpId==me->query("id")){
           command("stare "+me->query("id"));
           command("say ???????????Լ?????!??");
           return 1;
        }
        if (!str) str=LastDump;
        else if (str!=LastDump) return notify_fail("????"+do_check_num(str,0)+"?Ѿ??????ˡ?\n");
        if (me->query("id")==P1Data["Id"]) who=P1Data;
        else if (me->query("id")==P2Data["Id"]) who=P2Data;
        else if (me->query("id")==P3Data["Id"]) who=P3Data;
        else if (me->query("id")==P4Data["Id"]) who=P4Data;
        if (who["Auto"]=="auto") return 1;
        i=do_check_Mj(who["Mj"],str);
        if (i==0) return notify_fail("??û"+do_check_num(str,0)+"??????Ҫ????????\n");
        if (i < 2) return notify_fail("??????Ҫ??????"+do_check_num(str,0)+"????????\n");
        message_vision("\n$N???У?"+do_check_num(str,0)+"??"+HIW+"ʯ????????"+NOR+"\n\n",me);
        for (i=0;i<Play;i++) {
            if (NowPlayerId[NowPlayer]==me->query("id")) break;
            NowPlayer++;
            NowPlayer%=Play;
        }
        for (i=0;i<3;i++) who["OutPon"]+=str;
        who["Mj"]=do_delete_Mj(who["Mj"],str,2);
        who["AutoPon"]=do_delete_Mj(who["AutoPon"],str,1);
        NO_HU=1;
        NO_GON=1;
        Touched=1;
        i=0;
        if (who["Show"]=="????") i=3;
        if (who["Show"]=="color") i=5;
        tell_object(me,show_mj(who["Mj"],i));
        return delete_last_dump(who["Id"]);
}
int do_restart(string str)
{
        object me=this_player();
        if (me->query("id")=="guest") return 0;
        if (str!="mj"){
           if (check_id(me->query("id"),"player")!="");
           else {
              command("stare "+me->query("id"));
              command("say ???ƾָ???û??ϵ??");
              return 1;
           }
        }
        message_vision("$N???ƾ??????趨??\n",me);
        message_vision("$N˵?????ƾ??????趨????"+HIR+" addin "+NOR+"?????ƾ֡?\n",this_object());
        NowPlayerId[0]="";
        NowPlayerId[1]="";
        NowPlayerId[2]="";
        NowPlayerId[3]="";
        P1Data["Id"]="";
        P2Data["Id"]="";
        P3Data["Id"]="";
        P4Data["Id"]="";
        Count=0;
        LookP ="";
        Play=START;
        Times=START;
        end=END;
        count=START;
        Playing=START;
        return 1;
}
int wash_mj(int amount)
{
        int i,x;
        string str,countstr="";
        mixed *X,MjE_Data = ([
"1w" : 0,"2w" : 0,"3w" : 0,"4w" : 0,"5w" : 0,"6w" : 0,"7w" : 0,"8w" : 0,"9w" : 0,
"1s" : 0,"2s" : 0,"3s" : 0,"4s" : 0,"5s" : 0,"6s" : 0,"7s" : 0,"8s" : 0,"9s" : 0,
"1t" : 0,"2t" : 0,"3t" : 0,"4t" : 0,"5t" : 0,"6t" : 0,"7t" : 0,"8t" : 0,"9t" : 0,
"ea" : 0,"so" : 0,"we" : 0,"no" : 0,"jo" : 0,"fa" : 0,"ba" : 0,
"f1" : 0,"f2" : 0,"f3" : 0,"f4" : 0,"f5" : 0,"f6" : 0,"f7" : 0,"f8" : 0
                            ]);
        if (!Play){
           command("say û??????Ҫ?Ұ?ϴ??!!?Ŷ?û?С?");
           return 1;
        }
        if (Playing){
           command("say ?ƾ????ڽ????С?");
           return 1;
        }
        command("say ?Ұ?æϴ?ƣ??ȵ?˭??Ҫ?Ժ???..:)");
        if (Play<4) command("say ???Ҳ??????????Բ??Ʒ֡?");
        P1Data["Mj"]="";
        P1Data["OutGon"]="";
        P1Data["Out"]="";
        P1Data["OutPon"]="";
        P1Data["OutFlower"]="";
        P1Data["Auto"]="";
        P1Data["AutoTin"]="";
        P1Data["AutoGon"]="";
        P1Data["AutoPon"]="";
        P1Data["Dump"]="";
 
        P2Data["Mj"]="";
        P2Data["OutGon"]="";
        P2Data["Out"]="";
        P2Data["OutPon"]="";
        P2Data["OutFlower"]="";
        P2Data["Auto"]="";
        P2Data["AutoTin"]="";
        P2Data["AutoGon"]="";
        P2Data["AutoPon"]="";
        P2Data["Dump"]="";
 
        P3Data["Mj"]="";
        P3Data["OutGon"]="";
        P3Data["Out"]="";
        P3Data["OutPon"]="";
        P3Data["OutFlower"]="";
        P3Data["Auto"]="";
        P3Data["AutoTin"]="";
        P3Data["AutoGon"]="";
        P3Data["AutoPon"]="";
        P3Data["Dump"]="";
 
        P4Data["Mj"]="";
        P4Data["OutGon"]="";
        P4Data["Out"]="";
        P4Data["OutPon"]="";
        P4Data["OutFlower"]="";
        P4Data["Auto"]="";
        P4Data["AutoTin"]="";
        P4Data["AutoGon"]="";
        P4Data["AutoPon"]="";
        P4Data["Dump"]="";
 
        end=END;
        NO_HU=START;
        NO_GON=START;
        count=START;
        Playing=START;
        List="";
        NowPlayer=START;
        Touched=START;
        Auto=START;
        Auto_Tin=START;
        Auto_Gon=START;
        Auto_Pon=START;
        Goned=START;
        LastDump="";
        LastDumpId="";
        X = keys(MjE_Data);
        for (i=0;i<144;i++){
            x = random(sizeof(X));
            if (X[x]=="f1"||X[x]=="f2"||X[x]=="f3"||X[x]=="f4"||
                X[x]=="f5"||X[x]=="f6"||X[x]=="f7"||X[x]=="f8"){
                if (MjE_Data[X[x]] < 1){
                   MjE_Data[X[x]] = MjE_Data[X[x]] + 1;
                   List += X[x];
                } else i--;
            }else{
               if (MjE_Data[X[x]] < 4){
                  MjE_Data[X[x]] = MjE_Data[X[x]] + 1;
                  List += X[x];
               } else i--;
           }
        }
 
//        for (i=0;i<sizeof(X);i++) printf("%s=%d ",X[i],MjE_Data[X[i]]);
        command("say ??!!???˿??Կ?ʼ??????!!");
        if (Count) countstr="[??ׯ"+chinese_number(Count)+"]";
        if (!Times);
        else{
          if (Count);
          else {
            str=NowPlayerId[0];
            if (Play>1) NowPlayerId[0]=NowPlayerId[1];
            if (Play>2) NowPlayerId[1]=NowPlayerId[2];
            if (Play>3) NowPlayerId[2]=NowPlayerId[3];
            NowPlayerId[Play-1]=str;
          }
        }
        if (Times/Play == 4) Times=0;
        if (Times/Play == 3) str=HIW+"????"+NOR;
        if (Times/Play == 2) str=HIY+"????"+NOR;
        if (Times/Play == 1) str=HIR+"?Ϸ?"+NOR;
        if (Times/Play == 0) str=HIG+"????"+NOR;
        i=Times;
        i%=Play;
        i++;
        message_vision("["+str+chinese_number(i)+"]?ƾֿ?ʼ:ׯ??"+HIY+NowPlayerId[0]+HIR+countstr+NOR+"????????"+
                       "["+HIG+chinese_number(i=3+random(16))+NOR+ "]?㡣\n",this_object());
        //????ȡ??һ??ȡ16ֻ:Q
        if (Play>0) P1Data["Mj"]=List[0..31];
        if (Play>1) P2Data["Mj"]=List[32..63];
        if (Play>2) P3Data["Mj"]=List[64..95];
        if (Play>3) P4Data["Mj"]=List[96..127];
        count=(Play*2*16);
        if (Play>0) check_flower(P1Data);
        if (Play>1) check_flower(P2Data);
        if (Play>2) check_flower(P3Data);
        if (Play>3) check_flower(P4Data);
        Playing=1;
        message_vision("$N˵????ׯ??"+HIY+NowPlayerId[0]+NOR+"?뿪???ơ?\n",this_object());
        return 1;
}
int do_setmj(string str)
{
        int check;
        string numstr;
        mapping who;
        object me=this_player();
 
        if (me->query("id")==P1Data["Id"]) who=P1Data;
        else if (me->query("id")==P2Data["Id"]) who=P2Data;
        else if (me->query("id")==P3Data["Id"]) who=P3Data;
        else if (me->query("id")==P4Data["Id"]) who=P4Data;
        else return 1;
        if (!str){
           numstr=this_object()->name()+"??????˵???趨????:\n";
          if (who["AutoTin"]!="") numstr+="????"+HIB+show_mj(who["AutoTin"],2)+NOR+"???Զ?"+HIB+"[????]"+NOR+"??\n";
          if (who["AutoGon"]!="") numstr+="????"+HIY+show_mj(who["AutoGon"],2)+NOR+"???Զ?"+HIY+"[  ??]"+NOR+"??\n";
          if (who["AutoPon"]!="") numstr+="????"+HIG+show_mj(who["AutoPon"],2)+NOR+"???Զ?"+HIG+"[????]"+NOR+"??\n";
          if (who["Show"]=="????")    numstr+="??ʾ??ʽΪ"+HIY+"[????]"+NOR+"??ʽ??\n";
          if (who["Show"]=="color")   numstr+="??ʾ??ʽΪ"+HIG+"[??ɫ]"+NOR+"??\n";
          if (who["Auto"]=="auto")    numstr+="???趨"+HIR+"[?Զ?????]"+NOR+"??\n";
          if (who["AutoTin"]==""&&who["AutoGon"]==""&&who["AutoPon"]==""&&who["Show"]==""&&who["Auto"]=="") numstr+="??û???κ??趨??\n";
           tell_room(environment(me),this_object()->name()+"??"+me->name()+"????˵??һЩ????\n",me);
           tell_object(me,numstr);
           return 1;
        }
        if (sscanf(str,"%s %s",str,numstr)!=2) return notify_fail("ָ??:setmj <tin>&<gon>&<pon> <????>\n");
        if (str=="tin"){
           if (numstr=="none"){
              who["AutoTin"]="";
              return notify_fail("??ȡ???Զ??????趨??\n");
           }
           check=do_check_Mj(MjE,numstr);
           if (check!=1) return notify_fail("û??["+numstr+"]?????ơ?\n");
           check=do_check_Mj(who["AutoTin"],numstr);
           if (check){
              who["AutoTin"]=do_delete_Mj(who["AutoTin"],numstr,1);
              return notify_fail("??"+HIR+"ɾ????"+NOR+"????"+do_check_num(numstr,0)+"???Զ????Ƶ??趨??\n");
           }
           who["AutoTin"]+=numstr;
           Auto_Tin=1;
           write("???趨????"+do_check_num(numstr,0)+"ʱ???Զ????ơ?\n");
           return 1;
        }
        else if (str=="gon"){
           if (numstr=="none"){
              who["AutoGon"]="";
              return notify_fail("??ȡ???Զ?  ???趨??\n");
           }
           check=do_check_Mj(who["Mj"],numstr);
           if (check==0) return notify_fail("??û"+do_check_num(numstr,0)+"?????ơ?\n");
           if (check < 3) return notify_fail("??????Ҫ??????"+do_check_num(numstr,0)+"?????趨  ???ơ?\n");
           check=do_check_Mj(who["AutoGon"],numstr);
           if (check){
              who["AutoGon"]=do_delete_Mj(who["AutoGon"],numstr,1);
              return notify_fail("??"+HIR+"ɾ????"+NOR+"????"+do_check_num(numstr,0)+"???Զ?  ?Ƶ??趨??\n");
           }
           who["AutoGon"]+=numstr;
           Auto_Gon=1;
           write("???趨????"+do_check_num(numstr,0)+"ʱ???Զ?  ?ơ?\n");
           return 1;
        }
        else if (str=="pon"){
           if (numstr=="none"){
              who["AutoPon"]="";
              return notify_fail("??ȡ???Զ??????趨??\n");
           }
           check=do_check_Mj(who["Mj"],numstr);
           if (check==0) return notify_fail("??û"+do_check_num(numstr,0)+"?????ơ?\n");
           if (check < 2) return notify_fail("??????Ҫ??????"+do_check_num(numstr,0)+"?????趨?????ơ?\n");
           check=do_check_Mj(who["AutoPon"],numstr);
           if (check){
              who["AutoPon"]=do_delete_Mj(who["AutoPon"],numstr,1);
              return notify_fail("??"+HIR+"ɾ????"+NOR+"????"+do_check_num(numstr,0)+"???Զ????Ƶ??趨??\n");
           }
           who["AutoPon"]+=numstr;
           Auto_Pon=1;
           write("???趨????"+do_check_num(numstr,0)+"ʱ???Զ????ơ?\n");
           return 1;
        }
        else if (str=="show"){
           if (numstr=="none"||numstr=="1"){
              who["Show"]="";
              return notify_fail("??ȡ????ʾ?趨??\n");
           }
 
           if (numstr=="????"||numstr=="3"){
              numstr="????";
              write("???趨ֻ??ʾ???롣\n");
           }
           else if (numstr=="color"||numstr=="2"){
                numstr="color";
                 write("???趨??ɫ??ʾ??\n");
           }
           else return 1;
           who["Show"]=numstr;
           return 1;
        }
        else if (str=="auto"){
           if (numstr=="none"){
              return notify_fail("????ȡ???Զ????ƣ?Ҫ???趨????????թ????!!:>??\n");
           }
           if (who["AutoTin"]=="") return notify_fail("?????趨Ҫ?????ơ?\n");
           if (!Touched) return notify_fail("???????????????趨??\n");
           if (numstr=="tin") write("???趨?Զ????ơ?\n");
           else return 1;
           message_vision("\n$N????һ????"+HIW+"????????????"+NOR+"\n\n",me);
           Auto=1;
           who["Auto"]="auto";
           return 1;
        }
        else return notify_fail("û???????趨??\n");
}
int do_check_eat(string num1,string num2,string LastDump)
{
        int A,B,C;
        A=do_check_num(num1,1);
        B=do_check_num(num2,1);
        C=do_check_num(LastDump,1);
        if (A<10){
           if (B>10||C>10) return 0;
        }
        else if (A<19&&A>10){
                if (B>19||C>19&&B<10||C<10) return 0;
        }
        else if (A<28&&A>19){
                if (B<19||C<19) return 0;
        }
        A=do_check_num(num1,2);
        B=do_check_num(num2,2);
        C=do_check_num(LastDump,2);
 
        if (A > 9 || B > 9 || C > 9) return 0;
        if ((A+B)%2!=0){
           if (A > B){
               if (C==(A+1) || C==(A-2)) return 1;
           }else{
               if (C==(B+1) || C==(B-2)) return 1;
           }
           return 0;
        }else{
            if (A > B){
              if (C==(A-1) || C==(B+1)) return 1;
             }else{
              if (C==(B-1) || C==(A+1)) return 1;
             }
            return 0;
        }
}
string show_mj(string str,int flag)
{
        string Mj="",Mj1="";
        int size=strlen(str)+2,a,b;
        if (!str||str=="") return "";
        if (flag!=3){
           while(size--){
              size--;
             Mj+=do_check_num(str[size..size+1],0);
           }
           if (flag==2) Mj1=Mj;
           else{
 
             size=strlen(Mj);
             Mj1="??";
             for (a=0;a<(size/2)-1;a++){
                 if (a%2==0) Mj1+="??";
                 else Mj1+="??";
             }
             Mj1+="??\n??";
 
             for (a=0;a<size-1;a++){
                 if (flag==5 || flag==6){
                    if (Mj[a+2..a+3]=="??") Mj1+=HIR;
                    else if (Mj[a+2..a+3]=="Ͳ") Mj1+=HIC;
                    else if (Mj[a+2..a+3]=="??") Mj1+=HIG;
                    else if (Mj[a+2..a+3]=="??") Mj1+=HIM;
                    else if (Mj[a+2..a+3]=="??") Mj1+=HIR;
                    else if (Mj[a+2..a+3]=="??") Mj1+=HIG;
                    else if (Mj[a+2..a+3]=="??") Mj1+=HIW;
                    else if (Mj[a+2..a+3]=="??"
                         ||  Mj[a+2..a+3]=="??"
                         ||  Mj[a+2..a+3]=="??"
                         ||  Mj[a+2..a+3]=="??") Mj1+=HIR;
                    else if (Mj[a+2..a+3]=="÷"
                         ||  Mj[a+2..a+3]=="??"
                         ||  Mj[a+2..a+3]=="??"
                         ||  Mj[a+2..a+3]=="??") Mj1+="[1;30m";
                 }
                 Mj1+=Mj[a..a+1];
                 a++;a++;a++;
                 Mj1+=NOR+"??";
             }
             Mj1+="\n??";
             for (a=2;a<size;a++){
                 if (flag==5 || flag==6){
                         if (Mj[a..a+1]=="??") Mj1+=RED;
                    else if (Mj[a..a+1]=="??") Mj1+=GRN;
                    else if (Mj[a..a+1]=="Ͳ") Mj1+=CYN;
                    else if (Mj[a..a+1]=="??") Mj1+=MAG;
                    else if (Mj[a..a+1]=="??") Mj1+=HIR;
                    else if (Mj[a..a+1]=="??") Mj1+=HIG;
                    else if (Mj[a..a+1]=="??") Mj1+=HIW;
                    else if (Mj[a..a+1]=="??") Mj1+=HIG;
                    else if (Mj[a..a+1]=="??") Mj1+=HIB;
                    else if (Mj[a..a+1]=="??") Mj1+=HIY;
                    else if (Mj[a..a+1]=="??") Mj1+=HIW;
                    else if (Mj[a..a+1]=="÷") Mj1+=HIW;
                    else if (Mj[a..a+1]=="??") Mj1+=HIR;
                    else if (Mj[a..a+1]=="??") Mj1+=HIG;
                    else if (Mj[a..a+1]=="??") Mj1+=HIY;
                 }
                 Mj1+=Mj[a..a+1];
                 a++;a++;a++;
                 Mj1+=NOR+"??";
             }
             Mj1+="\n??";
             for (a=(size/2)-1;a>0;a--){
                 if (a%2!=0){
                    if (flag==0 || flag==5) Mj1+=str[a-1..a];
                    else Mj1+="??";
                 }
                 else Mj1+="??";
             }
             Mj1+="??\n";
           }
           return Mj1;
        }else{
            size*=2;
            for (a=(size/2)-1;a>0;a--){
                if (a%2!=0) Mj1+=str[a-1..a];
                else Mj1+=" ";
           }
           Mj1+="\n";
        }
        return Mj1;
}
string check_id(string str,string kind)
{
        int check,i;
        if (!str) return "";
        if (kind=="tin"){
           check=NowPlayer;
           for (i=0;i<Play-1;i++) {
           if (NowPlayerId[check]==P1Data["Id"] && do_check_Mj(P1Data["AutoTin"],str)!=0) return P1Data["Id"];
           if (NowPlayerId[check]==P2Data["Id"] && do_check_Mj(P2Data["AutoTin"],str)!=0) return P2Data["Id"];
           if (NowPlayerId[check]==P3Data["Id"] && do_check_Mj(P3Data["AutoTin"],str)!=0) return P3Data["Id"];
           if (NowPlayerId[check]==P4Data["Id"] && do_check_Mj(P4Data["AutoTin"],str)!=0) return P4Data["Id"];
               check++;
               check%=Play;
           }
           return "";
        }
        if (kind=="gon"){
           check=do_check_Mj(P1Data["AutoGon"],str);
           if (check!=0){
              check=do_check_Mj(P1Data["Mj"],str);
              if (check < 3) return "";
              else return P1Data["Id"];
           }
           check=do_check_Mj(P2Data["AutoGon"],str);
           if (check!=0){
              check=do_check_Mj(P2Data["Mj"],str);
              if (check < 3) return "";
              else return P2Data["Id"];
           }
           check=do_check_Mj(P3Data["AutoGon"],str);
           if (check!=0){
              check=do_check_Mj(P3Data["Mj"],str);
              if (check < 3) return "";
              else return P3Data["Id"];
           }
           check=do_check_Mj(P4Data["AutoGon"],str);
           if (check!=0){
              check=do_check_Mj(P4Data["Mj"],str);
              if (check < 3) return "";
              else return P4Data["Id"];
           }
           return "";
        }
        if (kind=="pon"){
           check=do_check_Mj(P1Data["AutoPon"],str);
           if (check!=0){
              check=do_check_Mj(P1Data["Mj"],str);
              if (check < 2) return "";
              else return P1Data["Id"];
           }
           check=do_check_Mj(P2Data["AutoPon"],str);
           if (check!=0){
              check=do_check_Mj(P2Data["Mj"],str);
              if (check < 2) return "";
              else return P2Data["Id"];
           }
           check=do_check_Mj(P3Data["AutoPon"],str);
           if (check!=0){
              check=do_check_Mj(P3Data["Mj"],str);
              if (check < 2) return "";
              else return P3Data["Id"];
           }
           check=do_check_Mj(P4Data["AutoPon"],str);
           if (check!=0){
              check=do_check_Mj(P4Data["Mj"],str);
              if (check < 2) return "";
              else return P4Data["Id"];
           }
           return "";
        }
        if (kind=="player"){
           for (i=0;i<Play;i++) {
               if (NowPlayerId[i]==str) check=1;
           }
        if (check) return "Y";
        return "";
        }
}
int delete_last_dump(string whoId)
{
        mapping who;
        if (LastDumpId==P1Data["Id"]) who=P1Data;
        else if (LastDumpId==P2Data["Id"]) who=P2Data;
        else if (LastDumpId==P3Data["Id"]) who=P3Data;
        else if (LastDumpId==P4Data["Id"]) who=P4Data;
        if (who["Dump"]!="") who["Dump"]=do_delete_Mj(who["Dump"],LastDump,1);
        return 1;
}
//??Ӣ????תΪ???? or ???? flag 1 ????תΪ???? flag 2 תΪ1..9
mixed do_check_num(string str,int flag)
{
        int number;
 
        if (!str) return MjC[0];
        sscanf(str,"%d%s",number,str);
        if (number == 0){
        if (str=="ea") number=28;
        else if (str=="so") number=29;
        else if (str=="we") number=30;
        else if (str=="no") number=31;
        else if (str=="jo") number=32;
        else if (str=="fa") number=33;
        else if (str=="ba") number=34;
        else if (str=="f1") number=35;
        else if (str=="f2") number=36;
        else if (str=="f3") number=37;
        else if (str=="f4") number=38;
        else if (str=="f5") number=39;
        else if (str=="f6") number=40;
        else if (str=="f7") number=41;
        else if (str=="f8") number=42;
        else if (str=="xx") number=43;
        }else{
          if (str=="w") number=0+number;
          else if (str=="t") number=9+number;
          else if (str=="s") number=18+number;
          if (flag==2){
             number%=9;
             if (number==0) number=9;
          }
        }
        if (!flag) return MjC[number];
        else return number;
}
void check_flower(mapping who)
{
        string newstr = "",str=who["Mj"],temp,temp1;
        int i = strlen(str),j;
 
        while(i--){
              i--;
           temp=str[i..i+1];
           if (temp=="f1"||temp=="f2"||temp=="f3"||temp=="f4"||
               temp=="f5"||temp=="f6"||temp=="f7"||temp=="f8"){
              if (Playing){
                 tell_room(environment(this_object()),this_player()->name()+"˵????"+HIB+"????"+NOR+"????!!??\n\n"+this_player()->name()+"?????油??һ???ơ?\n",this_player());
                 tell_object(this_player(),"??˵????"+HIB+"????"+NOR+"????!!??\n\n???????油??һ???ơ?\n");
                 tell_object(this_player(),"????????һ??"+do_check_num(List[end..end+1],0)+"\n");
              }
              HU_F=1;
              who["OutFlower"]+=temp;
              str[i..i+1]=List[end..end+1];
              end-=2;
              i+=2;
              continue;
           }
           else newstr+=temp;
        }
        who["Mj"]=sort_data(newstr);
}
int do_check_Mj(string datastr,string str)
{
        int size=strlen(datastr),check=0;
 
        while(size--){
              size--;
          if (datastr[size..size+1]==str) check++;
        }
        return check;
}
string do_delete_Mj(string datastr,string str,int amount)//??ĳ??ȥ??
{
        int size=strlen(datastr),check;
        string temp="";
 
        while(size--){
              size--;
          if (datastr[size..size+1]==str && amount!=0) amount--;
          else temp+=datastr[size..size+1];
        }
        size=strlen(temp);
        datastr=temp;
        temp="";
        while(size--){
              size--;
              temp+=datastr[size..size+1];
        }
        return temp;
}
string sort_data(string str)
{
        int i = strlen(str),a,b,c,d;
 
        string newstr="",temp="";
        for (a=-1;a<i;a++){
            a++;
            for (b=a+2;b<i;b++){
                b++;
                c=do_check_num(str[a..a+1],1);
                d=do_check_num(str[b-1..b],1);
                if (c < d){
                   temp=str[a..a+1];
                   str[a..a+1]=str[b-1..b];
                   str[b-1..b]=temp;
                }
            }
        }
        return str;
}
int do_look(string arg)
{
        int i,l;
        object me=this_player();
        string Mj="",p1o="",p2o="",p3o="",p4o="";
        mapping who;
 
        if (query_verb()==".")        arg="mj";
        if (query_verb()=="..") arg="chicken";
        if (query_verb()==".1") arg="1p";
        if (query_verb()==".2") arg="2p";
        if (query_verb()==".3") arg="3p";
        if (query_verb()==".4") arg="4p";
        if (query_verb()==".0") arg="all";
        if (me->query("id")==P1Data["Id"]) who=P1Data;
        else if (me->query("id")==P2Data["Id"]) who=P2Data;
        else if (me->query("id")==P3Data["Id"]) who=P3Data;
        else if (me->query("id")==P4Data["Id"]) who=P4Data;
        else return 0;
        if (who["Auto"]=="auto") l=1;
        if (arg=="1p"||arg=="2p"||arg=="3p"||arg=="4p"||arg=="all"||arg=="chicken"||arg=="end"||arg=="dump"||arg=="mj");
        else return 0;
        if (arg=="1p") who=P1Data;
        if (arg=="2p") who=P2Data;
        if (arg=="3p") who=P3Data;
        if (arg=="4p") who=P4Data;
        if (arg=="1p"||arg=="2p"||arg=="3p"||arg=="4p"){
           i=0;
           if (who["Show"]=="????") i=3;
           if (who["Show"]=="color") i=5;
           if (!Playing||check_id(me->query("id"),"player")==""||l==1){
              if (who["OutGon"]!=""){
                 Mj+=who["Id"]+":??  ??????:\n";
                 Mj+=show_mj(who["OutGon"],i+1);
              }
              Mj+=who["Id"]+":???е?????:\n";
              Mj+=show_mj(who["Mj"],i);
           }
           Mj+=who["Id"]+":??\????????????:\n";
           Mj+=show_mj(who["Out"]+who["OutPon"]+who["OutFlower"],i+1);
           Mj+=who["Id"]+":????????:\n";
           Mj+=show_mj(who["Dump"],2);
        }
        else if (arg=="mj") {
           if (!Playing) return 0;
           if (who["OutGon"]!=""){
              Mj+="???İ?  ??????:\n";
              Mj+=show_mj(who["OutGon"],1);
           }
           if (who["Show"]=="????") i=3;
           if (who["Show"]=="color") i=5;
           Mj+="????\????????????:\n";
           Mj+=show_mj(who["Out"]+who["OutPon"]+who["OutFlower"],i+1);
           Mj+="?????е?????:\n";
           Mj+=show_mj(who["Mj"],i);
           Mj+="?????趨??:";
        }else if (arg=="all") {
              i=0;
              if (who["Show"]=="????") i=3;
              if (who["Show"]=="color") i=5;
              Mj+=P1Data["Id"]+":??\????????????:\n";
              Mj+=show_mj(P1Data["Out"]+P1Data["OutPon"]+P1Data["OutFlower"],i+1);
              Mj+=P1Data["Id"]+":??????????:\n";
              Mj+=show_mj(P1Data["Dump"],2)+"\n";
              Mj+=P2Data["Id"]+":??\????????????:\n";
              Mj+=show_mj(P2Data["Out"]+P2Data["OutPon"]+P2Data["OutFlower"],i+1);
              Mj+=P2Data["Id"]+":??????????:\n";
              Mj+=show_mj(P2Data["Dump"],2)+"\n";
              Mj+=P3Data["Id"]+":??\????????????:\n";
              Mj+=show_mj(P3Data["Out"]+P3Data["OutPon"]+P3Data["OutFlower"],i+1);
              Mj+=P3Data["Id"]+":??????????:\n";
              Mj+=show_mj(P3Data["Dump"],2)+"\n";
              Mj+=P4Data["Id"]+":??\????????????:\n";
              Mj+=show_mj(P4Data["Out"]+P4Data["OutPon"]+P4Data["OutFlower"],i+1);
              Mj+=P4Data["Id"]+":??????????:\n";
              Mj+=show_mj(P4Data["Dump"],2)+"\n";
        }else if (arg=="chicken"){
                 if (Playing){
                    Mj=LookP+"?????????ڴ???\n";
                    Mj+="??ʣ??"+sprintf("%d",(end-count-16-Goned)/2)+"ֻ?ƾ??????ˡ?\n";
                    if (LastDump!="") Mj+=LastDumpId+"?ոմ?????"+show_mj(LastDump,2)+"\n";
                    if (Count) Mj+=NowPlayerId[0]+":??ׯ"+chinese_number(Count)+"\n";
                    if (P1Data["Out"]=="" && P1Data["OutPon"]=="") p1o=HIY+"????"+NOR;
                    if (P2Data["Out"]=="" && P2Data["OutPon"]=="") p2o=HIY+"????"+NOR;
                    if (P3Data["Out"]=="" && P3Data["OutPon"]=="") p3o=HIY+"????"+NOR;
                    if (P4Data["Out"]=="" && P4Data["OutPon"]=="") p4o=HIY+"????"+NOR;
                    Mj+="1.??????:"+NowPlayerId[0]+p1o+"\n2.?ϼ???:"+NowPlayerId[1]+p2o+"\n";
                    Mj+="3.??????:"+NowPlayerId[2]+p3o+"\n4.??????:"+NowPlayerId[3]+p4o+"\n";
                 }
                 else if (NowPlayerId[0]!="") Mj=LookP+"???ڵ??˴???";
                 else Mj=LookP+"һֻ?齫???????˼???(addin)?ƾ֡?";
        }else if (arg=="end"){
           Mj+="????"+chinese_number((end-count-16-Goned)/2)+"ֻ?ƾ???????\n";
        }else if (arg=="dump"){
           Mj+=LastDumpId+"?ոմ?????"+show_mj(LastDump,2)+"\n";
        }
        else return 0;
        if (arg=="mj"){
          if (who["AutoTin"]!="") Mj+="????"+show_mj(who["AutoTin"],2)+"???Զ????ơ?";
          if (who["AutoGon"]!="") Mj+="????"+show_mj(who["AutoGon"],2)+"???Զ?  ?ơ?";
          if (who["AutoPon"]!="") Mj+="????"+show_mj(who["AutoPon"],2)+"???Զ????ơ?";
          if (who["Show"]=="????")    Mj+="??ʾ??ʽΪ???뷽ʽ??";
          if (who["Show"]=="color")   Mj+="??ʾ??ʽΪ??ɫ??";
          if (who["Auto"]=="auto")    Mj+="???趨?Զ????ơ?";
          if (who["AutoTin"]==""&&who["AutoGon"]==""&&who["AutoPon"]==""&&who["Show"]==""&&who["Auto"]=="") Mj+="??û???κ??趨??\n";
        }
        printf("%s\n",Mj);
        return 1;
}
int do_help(string str)
{
        if (str=="setmj"){
write(@HELP
                       ??  ??  ??  ??
            setmj ???õ????Զ?????  ????????????ʽ??????
--------------------------------------------------------------------
????1: setmj pon 1w        ?趨???Զ???1w ?????˴???һ??ʱ???Զ???һ????
       setmj gon 1w                                         ?Զ?  һ????
       setmj tin 1w                                         ?Զ???һ????
????2: setmj show ????        ?趨Ϊֻ??ʾ???롣
       setmj show color ?趨Ϊ??ɫ??ʾ??
????3: setmj tin none        ȡ?????Զ??????趨??
       setmj gon none
       setmj pon none
????4: setmj auto tin        ?趨?Զ????ơ?
--------------------------------------------------------------------
HELP);
        return 1;
        }
        return 0;
}
int to_say_play()
{
write(@HELP
        ָ  ??          ??          ??                               ˵    ??
    ??????????????????????????????????????????????????????????????
    ??        addin          ----------                               ?????ž? ??
    ??        look          l mj??.???Լ???,l 1p??.1??????1????                ??
    ??                  l all??..??ȫ??,l end??????l dump??  ????        ??
    ??        mo          ----------                               ????        ??
    ??        dump          dump <????>??                        ????        ??
    ??        eat          eat <????1> <????2>??                ????        ??
    ??        pon          ----------                               ????        ??
    ??        gon          gon ?? gon <????>(??  ??)??                 ??        ??
    ??        hu                                               ????        ??
    ??        setmj          help setmj??                               ?趨???? ??
    ??        start          ----------                               ?ƾֿ?ʼ ??
    ??        restart   restart ?? restart mj??               ???¿?ʼ ??
    ??        top          top aip,top -p,top -w,top -h,top -d                ??
    ??                  top -l??ȫ??,-lw,-lh,-ld??               ??????        ??
    ??????????????????????????????????????????????????????????????
HELP);
        return 1;
}
int to_say_rule()
{
write(@HELP
 
????ÿ?????е?̨?????ڼ??????õ?̨??????̨??Ҫ???????ͣ??????൱????һ???㷨??
??ǹ??????ս???ǿ۵???ʧ??̨??????????????ȥ??
 
HELP);
        return 1;
}
int show_top(string str)
{
        int i,check,a,b,c,d,e;
        string *temp=({"","","","","",""});
        string show="";
        mixed *MjData;
 
        if (!str) str=this_player()->query("id");
        else if (str=="-lp"||str=="-pl"||str=="-l") str="all1";
        else if (str=="-lw"||str=="-wl") str="all2";
        else if (str=="-lh"||str=="-hl") str="all3";
        else if (str=="-ld"||str=="-dl") str="all4";
        if (file_size(MJ_DATA)==-1)
           return notify_fail("???ϵ?ûû???ҵ???\n");
        MjData=explode(read_file(MJ_DATA),",");
        if (str=="all1") e=2;
        else if (str=="all2") e=3;
        else if (str=="all3") e=4;
        else if (str=="all4") e=5;
        if (str=="all1"||str=="all2"||str=="all3"||str=="all4") str="all";
        if (str=="-p") e=2;
        else if (str=="-w") e=3;
        else if (str=="-h") e=4;
        else if (str=="-d") e=5;
        if (str=="all"||str=="-p"||str=="-w"||str=="-h"||str=="-d"){
          for (a=0;a<sizeof(MjData);a+=6){
              for (b=a+6;b<sizeof(MjData);b+=6){
                  sscanf(MjData[a+e],"%d",c);
                  sscanf(MjData[b+e],"%d",d);
                  if (d > c){
                     for (i=0;i<6;i++)temp[i]=MjData[a+i];
                     for (i=0;i<6;i++) MjData[a+i]=MjData[b+i];
                     for (i=0;i<6;i++) MjData[b+i]=temp[i];
                  }
              }
          }
        }
        show=HBWHT+"\n  ";
        for (i=0; i<34; i++) show+="[47m??";
        show+=HBWHT+"  \n";
        show+="  "+HBRED+"?? Ӣ?????? ??  ????????  ???????????? ??ս?? ??????????????ǹ????  "+HBWHT+"  \n";
        if (str=="all"){
           for (i=0; i<sizeof(MjData); i+=6){///
               show+="  "+HBRED;
               show+=sprintf("??%10s??%12s??%8s??%8s??%8s??%8s  ",
                             MjData[i],MjData[i+1],MjData[i+2],MjData[i+3],MjData[i+4],MjData[i+5]);
               show+=HBWHT+"  \n";
           }
        }else if (str=="-p"||str=="-w"||str=="-h"||str=="-d"){
           if (sizeof(MjData) < 60) d=sizeof(MjData);
           else d=60;
           for (i=0; i<d; i+=6){///
               show+="  "+HBRED;
               show+=sprintf("??%10s??%12s??%8s??%8s??%8s??%8s  ",
                             MjData[i],MjData[i+1],MjData[i+2],MjData[i+3],MjData[i+4],MjData[i+5]);
               show+=HBWHT+"  \n";
           }
        }else{
           for (i=0; i<sizeof(MjData); i+=6){
               if (MjData[i]==str){
                  check=1;
                  break;
               }
           }
           if (check==1){
              show+="  "+HBRED;
              show+=sprintf("??%10s??%12s??%8s??%8s??%8s??%8s  ",
                            MjData[i],MjData[i+1],MjData[i+2],MjData[i+3],MjData[i+4],MjData[i+5]);
              show+=HBWHT+"  \n";
           }else return notify_fail("û???????˵????ϡ?\n");
        }
        show+=HBWHT+"  ";
        for (i=0; i<34; i++) show+="[47m??";
        show+=HBWHT+"  "+NOR+"\n";
        printf("%s\n",show);
        return 1;
}
int set_mjdata(object me,int *winner)
{
        int i,check;
        string str="";
        mixed *MjData;
 
        if (!me||!winner) return 0;
        if (file_size(MJ_DATA)==-1);
        else {
          MjData=explode(read_file(MJ_DATA),",");
          for (i=0; i<sizeof(MjData); i+=6){
              if (MjData[i]==me->query("id")){
                 check=1;
                 break;
              }
          }
        }
        if (check==1){
           MjData[i+2]=sprintf("%d",winner[0]);
           MjData[i+3]=sprintf("%d",winner[1]);
           MjData[i+4]=sprintf("%d",winner[2]);
           MjData[i+5]=sprintf("%d",winner[3]);
           for (i=0; i<sizeof(MjData); i++) str+=MjData[i]+",";
             write_file(MJ_DATA,str,1);
        }else{
           str=me->query("id")+",";
           str+=me->name()+",";
           str+=winner[0]+",";
           str+=winner[1]+",";
           str+=winner[2]+",";
           str+=winner[3]+",";
           write_file(MJ_DATA,str,0);
        }
        return 1;
}
int *get_mjdata(string Id)
{
        int i,check,*winner=({0,0,0,0});
        string str="";
        mixed *MjData;
 
        if (!Id) return 0;
        if (file_size(MJ_DATA)==-1) return 0;
        MjData=explode(read_file(MJ_DATA),",");
        for (i=0; i<sizeof(MjData); i+=6){
            if (MjData[i]==Id){
               check=1;
               break;
            }
        }
        if (check==1){
           sscanf(MjData[i+2],"%d",winner[0]);
           sscanf(MjData[i+3],"%d",winner[1]);
           sscanf(MjData[i+4],"%d",winner[2]);
           sscanf(MjData[i+5],"%d",winner[3]);
        }
        return winner;
}
int get_tc(mapping who)
{
        int size,i,check;
        string str,tempW="",tempT="",tempS="",tempB="";
        str=who["Mj"]+who["Out"]+who["OutPon"]+who["OutGon"];
        //ׯ??
        if (NowPlayerId[0]==who["Id"]) Tc+="@1";
        //????&????
        if (who["Out"]==""&&who["OutPon"]==""&&Touched) Tc+="@l";
        else if (who["Out"]==""&&who["OutPon"]=="") Tc+="@4";
        else if (Touched) Tc+="@2";
        //ȫ????
        if (strlen(who["Mj"]) < 5) Tc+="@i";
        size=strlen(str);
        while(size--){
              size--;
          if (do_check_num(str[size..size+1],1) < 10) tempW+=str[size..size+1];
          else if (do_check_num(str[size..size+1],1) < 19) tempT+=str[size..size+1];
          else if (do_check_num(str[size..size+1],1) < 28) tempS+=str[size..size+1];
          else tempB+=str[size..size+1];
        }
        //????
        if (Times/Play == 0 && NowPlayerId[0]==who["Id"]&&do_check_Mj(tempB,"ea")>2) Tc+="@e";
        else if (Times/Play == 0 && do_check_Mj(tempB,"ea") > 2
             ||  NowPlayerId[0]==who["Id"]&&do_check_Mj(tempB,"ea")>2) Tc+="@5";
        if (Times/Play == 1 &&NowPlayerId[1]==who["Id"]&&do_check_Mj(tempB,"so")>2) Tc+="@f";
        else if (Times/Play == 1 && do_check_Mj(tempB,"so") > 2
             ||  NowPlayerId[1]==who["Id"]&&do_check_Mj(tempB,"so")>2) Tc+="@6";
        if (Times/Play == 2 &&NowPlayerId[2]==who["Id"]&&do_check_Mj(tempB,"we")>2) Tc+="@g";
        else if (Times/Play == 2 && do_check_Mj(tempB,"we") > 2
             ||  NowPlayerId[2]==who["Id"]&&do_check_Mj(tempB,"we")>2) Tc+="@7";
        if (Times/Play == 3 && NowPlayerId[3]==who["Id"]&&do_check_Mj(tempB,"no")>2) Tc+="@h";
        else if (Times/Play == 3 && do_check_Mj(tempB,"no") > 2
             ||  NowPlayerId[3]==who["Id"]&&do_check_Mj(tempB,"no")>2) Tc+="@8";
        //????
        if (sizeof(who["OutFlower"]) ==16) Tc+="@A";//???ɹ???
        else if (sizeof(who["OutFlower"]) ==14&&sizeof(P1Data["OutFlower"]+P2Data["OutFlower"]+P3Data["OutFlower"]+P4Data["OutFlower"])==16) Tc+="@D";//????һ
        else if (do_check_Mj(who["OutFlower"],"f1")==1&&do_check_Mj(who["OutFlower"],"f2")==1
        &&  do_check_Mj(who["OutFlower"],"f3")==1&&do_check_Mj(who["OutFlower"],"f4")==1) Tc+="@B";//?????ﶬ
        else if (do_check_Mj(who["OutFlower"],"f5")==1&&do_check_Mj(who["OutFlower"],"f6")==1
        &&  do_check_Mj(who["OutFlower"],"f7")==1&&do_check_Mj(who["OutFlower"],"f8")==1) Tc+="@C";//÷??????
        else if (NowPlayerId[0]==who["Id"]&&do_check_Mj(who["OutFlower"],"f1")==1
        ||  NowPlayerId[0]==who["Id"]&&do_check_Mj(who["OutFlower"],"f5")==1
        ||  NowPlayerId[1]==who["Id"]&&do_check_Mj(who["OutFlower"],"f2")==1
        ||  NowPlayerId[1]==who["Id"]&&do_check_Mj(who["OutFlower"],"f6")==1
        ||  NowPlayerId[2]==who["Id"]&&do_check_Mj(who["OutFlower"],"f3")==1
        ||  NowPlayerId[2]==who["Id"]&&do_check_Mj(who["OutFlower"],"f7")==1
        ||  NowPlayerId[3]==who["Id"]&&do_check_Mj(who["OutFlower"],"f4")==1
        ||  NowPlayerId[3]==who["Id"]&&do_check_Mj(who["OutFlower"],"f8")==1) Tc+="@3";
        //??һɫ????һɫ
        if (tempW!=""&&tempT==""&&tempS==""&&tempB=="") Tc+="@q";
        else if (tempW==""&&tempT!=""&&tempS==""&&tempB=="") Tc+="@q";
        else if (tempW==""&&tempT==""&&tempS!=""&&tempB=="") Tc+="@q";
        else if (tempW==""&&tempT==""&&tempS==""&&tempB!="") Tc+="@r";
        //??һɫ
        if (tempW!=""&&tempT==""&&tempS==""&&tempB!="") Tc+="@n";
        else if (tempW==""&&tempT!=""&&tempS==""&&tempB!="") Tc+="@n";
        //??һɫ
        else if (tempW==""&&tempT==""&&tempS!=""&&tempB!=""){
             if (do_check_Mj(tempB,"fa")==3&&sizeof(tempB)==6
             ||  do_check_Mj(tempB,"fa")==2&&sizeof(tempB)==4
             && do_check_Mj(tempS,"1s")==0&& do_check_Mj(tempS,"5s")==0
             && do_check_Mj(tempS,"7s")==0&& do_check_Mj(tempS,"9s")==0) Tc+="@E";
             else Tc+="@n";
        }
        //????Ԫ
        if (do_check_Mj(tempB,"jo") > 2
        &&  do_check_Mj(tempB,"fa") > 2
        &&  do_check_Mj(tempB,"ba") > 2) Tc+="@t";
        //С??Ԫ
        else if (do_check_Mj(tempB,"jo") > 1
        &&  do_check_Mj(tempB,"fa") > 1
        &&  do_check_Mj(tempB,"ba") > 1) Tc+="@o";
        else if (do_check_Mj(tempB,"jo") > 2) Tc+="@9";
        else if (do_check_Mj(tempB,"fa") > 2) Tc+="@0";
        else if (do_check_Mj(tempB,"ba") > 2) Tc+="@a";
        //????ϲ
        if (do_check_Mj(tempB,"ea") > 2
        &&  do_check_Mj(tempB,"so") > 2
        &&  do_check_Mj(tempB,"we") > 2
        &&  do_check_Mj(tempB,"no") > 2) Tc+="@v";
        //С??ϲ
        else if (do_check_Mj(tempB,"ea") > 1
        &&  do_check_Mj(tempB,"so") > 1
        &&  do_check_Mj(tempB,"we") > 1
        &&  do_check_Mj(tempB,"no") > 1) Tc+="@F";
 
        for (i=0;i<sizeof(str);i+=2){
            if (str[i..i+1]=="xx") continue;
            if (do_check_Mj(str,str[i..i+1])==3) check++;
            else if (do_check_Mj(str,str[i..i+1])==4) check++;
        }
        //??????
        if (check>14){
           if (who["Out"]==""&&who["OutPon"]==""&&do_check_Mj(Tc,"@u")==0) Tc+="@m@u";
           else  Tc+="@m";
        }
        check=0;
        for (i=0;i<sizeof(str);i+=2){
            if (do_check_num(str[i..i+1],1)!=1&&do_check_num(str[i..i+1],1)>8) check++;

        }
        if (check=0&&tempB!="") Tc+="@I";//????ͷ
        else if (check=0&&tempB="") Tc+="@J";//????ͷ
        //ƽ??
        if (tempB==""&&who["OutFlower"]==""&&check==0&&sizeof(who["AutoTin"])>3) Tc+="@d";
        //?ӵ?????
        if (count==((end-16-(Goned*2))-2)&&Touched) Tc+="@b";
        //????
        if (count==((end-16-(Goned*2))-2)&&!Touched) Tc+="@c";
        //????
        if (LastDump==""&&count==(Play*2*16)+2) Tc+="@w";
        //?غ?&?˺?
        printf("%d > %d\n",count,((Play*2*16)+(Play*2)));
        if (count < ((Play*2*16)+(Play*2))
        &&P1Data["Out"]==""&&P1Data["PonOut"]==""
        &&P2Data["Out"]==""&&P2Data["PonOut"]==""
        &&P3Data["Out"]==""&&P3Data["PonOut"]==""
        &&P4Data["Out"]==""&&P4Data["PonOut"]==""){
           if (Touched) Tc+="@x";
           else Tc+="@y";
        }
        return 1;
}
int ch(string str)
{
        object me=this_player();
        mapping who;
        if (me->query("id")==P1Data["Id"]) who=P1Data;
        else if (me->query("id")==P2Data["Id"]) who=P2Data;
        else if (me->query("id")==P3Data["Id"]) who=P3Data;
        else if (me->query("id")==P4Data["Id"]) who=P4Data;
        if (!str) return 0;
        write("??????"+who["Mj"]+"????"+str+" ok.\n");
        str=sort_data(str);
        who["Mj"]=str;
        return 1;
}
