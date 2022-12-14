// who.c

#include <net/dns.h>
#include <net/daemons.h>
#include <net/macros.h>
#include <ansi.h>

inherit F_CLEAN_UP;

int help(object me);
int sort_user(object,object);

void create() { seteuid(getuid()); }

mixed main(object me, string arg, int remote)
{
        mapping mud_list;
        mixed *muds;
        object *list, *ob;
        string str, *option;
        int i, j, ppl_cnt;
        int opt_all = 1, opt_long = 1, opt_id, opt_wiz, opt_bangpai = 1, opt_party,
opt_hs, opt_wd, opt_em, opt_sl, opt_gm, opt_lj, opt_ry, opt_xy, opt_xx, opt_dl, opt_mj;

        if(!arg) opt_long=1;
        if( arg ) {
                option = explode(arg, " ");
                i = sizeof(option);
                while( i-- )
                        switch(option[i]) {
                                case "-h": return help( me );   break;          
                                case "-l": opt_long = 0;        break;
                                case "-i": opt_id = 1;          break;
                                case "-w": opt_wiz = 1;         break;
                                case "-b": opt_bangpai = 0;     break;
                                case "-p": opt_party = 1;       break;
                                case "-all" : opt_all = 0;
                                case "-hs" : opt_hs=1;  break;
                                case "-wd" : opt_wd=1;  break;
                                case "-em" : opt_em=1;  break;
                                case "-sl" : opt_sl=1;  break;
                                case "-gm" : opt_gm=1;  break;
                                case "-lj" : opt_lj=1;  break;
                                case "-ry" : opt_ry=1;  break;
                                case "-xy" : opt_xy=1;  break;
                                case "-xx" : opt_xx=1;  break;
                                case "-dl" : opt_dl=1;  break;                  
                                case "-mj" : opt_mj=1;  break;                  
                                default:
                                        if( wizardp(me)
                                        &&      option[i][0]=='@' ) {
                                                RWHO_Q->send_rwho_q(option[i][1..sizeof(option[i])],
                                                        me, opt_long);
                                                write("????????????????????????\n");
                                                return 1;
                                        }
                                        return notify_fail("??????????who [-h|-l|-i|-w|-b|-p|-hs|-wd|-...]\n");
                        }
        }
        if ( opt_wiz ) str =  HIR + "??" + HIY + MUD_NAME+ NOR + HIR "??"+ HIW +"    ????????????"+HIB+"????"+HIW+"???? " NOR;
        else if ( opt_party ) str =  HIR + "??" + HIY + MUD_NAME+ NOR + HIR "??"+ HIW +"    ??????????"+HIM+"????????"+HIW+"???? " NOR;
        else if ( opt_hs ) str =  HIR + "??" + HIY + MUD_NAME+ NOR + HIR "??"+ HIW +"    ????????????"+HIY+"??????????"+HIW+"???? " NOR;
        else if ( opt_wd ) str =  HIR + "??" + HIY + MUD_NAME+ NOR + HIR "??"+ HIW +"    ????????????"+HIY+"??????????"+HIW+"???? " NOR;
        else if ( opt_em ) str =  HIR + "??" + HIY + MUD_NAME+ NOR + HIR "??"+ HIW +"    ????????????"+HIY+"??????????"+HIW+"???? " NOR;
        else if ( opt_sl ) str =  HIR + "??" + HIY + MUD_NAME+ NOR + HIR "??"+ HIW +"    ????????????"+HIY+"??????????"+HIW+"???? " NOR;
        else if ( opt_gm ) str =  HIR + "??" + HIY + MUD_NAME+ NOR + HIR "??"+ HIW +"    ????????????"+HIY+"??????????"+HIW+"???? " NOR;
        else if ( opt_lj ) str =  HIR + "??" + HIY + MUD_NAME+ NOR + HIR "??"+ HIW +"    ????????????"+HIY+"??????????"+HIW+"???? " NOR;
        else if ( opt_xy ) str =  HIR + "??" + HIY + MUD_NAME+ NOR + HIR "??"+ HIW +"    ????????????"+HIY+"??????????"+HIW+"???? " NOR;
        else if ( opt_xx ) str =  HIR + "??" + HIY + MUD_NAME+ NOR + HIR "??"+ HIW +"    ????????????"+HIY+"??????????"+HIW+"???? " NOR;
        else if ( opt_dl ) str =  HIR + "??" + HIY + MUD_NAME+ NOR + HIR "??"+ HIW +"    ????????????"+HIY+"??????????"+HIW+"???? " NOR;
        else if ( opt_mj ) str =  HIR + "??" + HIY + MUD_NAME+ NOR + HIR "??"+ HIW +"    ????????????"+HIY+"????"+HIW+"???? " NOR;
        else if ( !opt_bangpai ) str =  HIR + "??" + HIY + MUD_NAME+ NOR + HIR "??"+ HIW +"    ??????????"+HIG+"????????????????"+HIW+"???? " NOR;
        else str =  HIR + "??" + HIY + MUD_NAME+ NOR + HIR "??"+ HIW +"    ???????????????????? " NOR;

        str += "\n";
        str +=HIC"??"+HIY"??????????????????????????????????????????????????????????????????????"HIC"??\n"NOR;
        ob = filter_array(objects(), (: userp :));
        list = sort_array(ob, (: sort_user :));
        i = 0;

        if ( !opt_bangpai ) {
                j = sizeof(list);
                while( j-- ) {
                        if( !list[j]) continue;
                        if( !environment(list[j]) ) continue;
                        if( !me->visible(list[j]) ) continue;
                        i++;
                        if ( !list[j]->query("b_title") ) continue;
                        str = sprintf("%s%s %s%s%s(%s)\n", str,
                                RANK_D->query_rank(list[j]),
                                list[j]->query("b_title"),
                                list[j]->query("nickname") ? "??"+list[j]->query("nickname") +"??": "",
                                list[j]->name(),
                                list[j]->query("id")
                        );      
                        }
                }
        else if( !opt_long || opt_wiz || opt_party
 || opt_hs || opt_wd || opt_em || opt_sl || opt_gm || opt_lj || opt_ry || opt_xy || opt_xx || opt_dl || opt_mj ) {
                j = sizeof(list);
                while( j-- ) {
                        // Skip those users in login limbo.
                        if( !list[j]) continue;
                        if( !environment(list[j]) ) continue;
                        if( !me->visible(list[j]) ) continue;
                        // if( !wizardp(me) && wizardp(list[j]) ) continue;
                        if( opt_wiz && !wizardp(list[j]) ) continue;
                        if ( opt_party && me->query("family/family_name") != list[j]->query("family/family_name") ) continue;
                        if ( opt_hs && list[j]->query("family/family_name") != "??????" ) continue;
                        if ( opt_wd && list[j]->query("family/family_name") != "??????" ) continue;
                        if ( opt_em && list[j]->query("family/family_name") != "??????" ) continue;
                        if ( opt_sl && list[j]->query("family/family_name") != "??????" ) continue;
                        if ( opt_gm && list[j]->query("family/family_name") != "??????" ) continue;
                        if ( opt_lj && list[j]->query("family/family_name") != "??????" ) continue;
                        if ( opt_ry && list[j]->query("family/family_name") != "huashan" ) continue;
                        if ( opt_xy && list[j]->query("family/family_name") != "??????" ) continue;
                        if ( opt_xx && list[j]->query("family/family_name") != "??????" ) continue;
                        if ( opt_dl && list[j]->query("family/family_name") != "??????" ) continue;
                        if ( opt_mj && list[j]->query("family/family_name") != "????" ) continue;
                        i++;
                        str = sprintf("%s%12s %s\n", str,
                                RANK_D->query_rank(list[j]),
                                list[j]->short(1)
                        );
                }
        }
        else {
                ppl_cnt = 0;
// ????????????????        
        if ( !find_player("love") ) {
                str = sprintf("%s"WHT"%-18s%s", str,
                        opt_id ? "love" : "????(love)",
                                (ppl_cnt%4==3? "\n": "")
                        );
                ppl_cnt++;
                }

                j = sizeof(list);
                while( j-- ) {
                        // Skip those users in login limbo.
                        if( !list[j]) continue;
                        if( !environment(list[j]) ) continue;
                        if( me && !me->visible(list[j]) ) continue;
                        // if( !wizardp(me) && wizardp(list[j]) ) continue;
                        
                        i++;
                        if ( interactive(list[j]) && wizardp(list[j]) )
                        str = sprintf("%s"HIB"%-18s%s", str,
                                opt_id ? capitalize(list[j]->query("id")):list[j]->name(1) + "(" + list[j]->query("id") + ")",
                                (ppl_cnt%4==3? "\n": "")                        for(i=0;i<sizeof(muds);i++)
                                if(( muds[i] != lower_case(INTERMUD_MUD_NAME))
                                &&      (muds[i] != "dnssvr")) {
                                        RWHO_Q->send_rwho_q(muds[i],me,1);
                                }
                }
                i = j;
        }
                
        str += HIC"??"+HIY"??????????????????????????????????????????????????????TX-MUD??????????"HIC"??\n"NOR;
        str = sprintf("%s???? %d ????????????????????????%s\n"GRN"????"NOR" ????????????"MAG"????"NOR" ????????????", str, i,
                query_load_average());

        if( remote ) return str;

        me->start_more(str);
        return 1;
}

int sort_user(object ob1, object ob2)
{
        if( wizardp(ob1) && !wizardp(ob2) ) return -1;
        
        if( wizardp(ob2) && !wizardp(ob1) ) return 1;

        if( wizardp(ob1) && wizardp(ob2) )
                return (int)SECURITY_D->get_wiz_level(ob2) 
                        - (int)SECURITY_D->get_wiz_level(ob1);
        
        return (int)ob2->query("family/family_name") - (int)ob1->query("family/family_name");
}

int help(object me)
{
        write(@HELP
??????????who [-h|-l|-b|-w|-i|-p|-hs|-wd|-...]

??????????????????????????????????????????

-h  ??????????????
-l  ????????????????????
-b  ????????????????????
-i  ??????????????????????
-w  ??????????????????????
                        )
                        else if ( interactive(list[j]) && query_idle(list[j]) > 120 
                        str = sprintf("%s"GRN"%-18s%s", str
                                opt_id ? capitalize(list[j]->query("id")):list[j]->name(1) + "(" + list[j]->query("id") + ")"
                                (ppl_cnt%4==3? "\n": ""
                        )
                        else if ( list[j]->query_temp("netdead") 
                        str = sprintf("%s"MAG"%-18s%s", str
                                opt_id ? capitalize(list[j]->query("id")):list[j]->name(1) + "(" + list[j]->query("id") + ")"
                                (ppl_cnt%4==3? "\n": ""
                        )
                        els
                        str = sprintf("%s"WHT"%-18s%s", str
                                opt_id ? capitalize(list[j]->query("id")):list[j]->name(1) + "(" + list[j]->query("id") + ")"
                                (ppl_cnt%4==3? "\n": ""
                        )
                        ppl_cnt++
                
                if( ppl_cnt%4 ) str += "\n"
                // here is where we send rwho messag
                // ??????????
                j = i
                if( me && find_object(DNS_MASTER) && !opt_all ) 
                        mud_list=(mapping)DNS_MASTER->query_muds()
                        muds = keys(mud_list)
-p  ?????????????????
-hs ????????????????                    -wd ???????????????
-em ????????????????                    -sl ???????????????
-gm ????????????????                    -lj ???????????????
-xy ????????????????                    -xx ???????????????
-dl ????????????????                    -mj ??????????????                                     
??????????finge
by derondog@JXJ
HEL
        )
       
        return 1
