// mudlist.c
// last modify by ken@XAJH at 1998-5-30

#include <ansi.h>
#include <net/daemons.h>
#include <net/macros.h>
#include <net/gchannel.h>


inherit F_CLEAN_UP;
string *big5_mud_list=BIG5_MUD_IP;
int main(object me, string arg)
{
        mapping mud_list;
        mapping mud_svc;
        mixed *muds;
        string output;
        int loop, size, total,count=0;

        if( !find_object(DNS_MASTER) )
                return notify_fail("网路精灵并没有被载入。\n");

        //      Obtain mapping containing mud data
        mud_list = (mapping)DNS_MASTER->query_muds();

        // so we recognise ourselves as a DNS mud
        mud_svc = DNS_MASTER->query_svc() + ([ Mud_name() : 0 ]);

        if(!mud_list)
                return notify_fail( MUD_NAME + "目前并没有跟网路上其他 Mud 取得联系。\n");

        //      Get list of all mud names within name server
        muds = keys( mud_list ) - ({ "DEFAULT" });

        //      Place mudlist into alphabetical format
        muds = sort_array(muds, 1);

        //      If mudname provided, search server's database for a match
        //      and display its cooresponding address
        if( arg ) arg = upper_case(arg);
        if(arg && arg != "" && arg != "ALL" && arg != "ES" ) {
                arg = htonn(arg);
                if(!mapp( mud_list[arg] )) {
                        write(MUD_NAME + "并没有和这个 Mud 取得联系。\n");
                        return 1;
                }
                if( wizardp(me) && !me->query("env/debug") )
                        printf("有关 %s 的资讯：\n%O\n", arg, mud_list[arg]);
                else
                        printf("\n有关 %s 的资讯：\n"
                                "──────────────────\n"
                                "中文名称：  %s\n"
                                "语言：      %s\n"
                                "版本：      %s\n"
                                "MudOS：     %s\n"
                                "Mudlib：    %s\n"
                                "主机：      %s\n"
                                "端口：      %s\n"
                                "状态：      %s\n"
                                "在线玩家：  %s\n"
                                "当地时间：  %s\n"
                                "──────────────────\n\n",
                                mud_list[arg]["NAME"],
                                undefinedp(mud_list[arg]["MUDNAME"])?
                                "不详":mud_list[arg]["MUDNAME"],
                                undefinedp(mud_list[arg]["ENCODING"])?
                                "不详":(mud_list[arg]["ENCODING"]=="GB"?"简体汉字":"繁体汉字"),
                                undefinedp(mud_list[arg]["VERSION"])?
                                "不详":mud_list[arg]["VERSION"],
                                undefinedp(mud_list[arg]["DRIVER"])?
                                "不详":mud_list[arg]["DRIVER"],
                                undefinedp(mud_list[arg]["MUDLIB"])?
                                "不详":mud_list[arg]["MUDLIB"],
                                mud_list[arg]["HOSTADDRESS"],
                                mud_list[arg]["PORT"],
                                mud_list[arg]["_dns_no_contact"]<1?
                                "连线":"断开",
                                undefinedp(mud_list[arg]["USERS"])?
                                "不详":mud_list[arg]["USERS"],
                                undefinedp(mud_list[arg]["TIME"])?
                                "不详":mud_list[arg]["TIME"],
                                );
                return 1;
        }

        output = 
"Mud                    中文名称              国际网络位址     端口  人数\n"+
"────────────────────────────────────\n";
        //      Loop through mud list and store one by one
        for(loop = 0, size = sizeof(muds); loop<size; loop++) {

                if( !arg && mud_list[muds[loop]]["VERSION"] != MUDLIB_VERSION )
                        continue;
                if( arg ) {
                        if( arg =="ES" && mud_list[muds[loop]]["MUDLIB"] != "Eastern Stories" )
                                continue;
                        if( arg!="ALL" && mud_list[muds[loop]]["MUDLIB"] != MUDLIB_NAME )
                                continue;
                }               
                if( mud_list[muds[loop]]["_dns_no_contact"] > 0 ) {
                        if( !wizardp(me) || (wizardp(me) && me->query("env/debug")) )
                                continue;
                }

                count = loop;
                if( htonn(upper_case(muds[loop])) == htonn(upper_case(INTERMUD_MUD_NAME)) )
                        output +=  CYN;
                else
                        output += NOR;

                if( undefinedp(mud_list[muds[loop]]["MUDNAME"]) ) continue;
             
                        output +=  sprintf("%-22s %-21s %-15s  %4s", 
                                upper_case(muds[loop]),
                                undefinedp(mud_list[muds[loop]]["MUDNAME"])?
                                "":(member_array(mud_list[muds[loop]]["HOSTADDRESS"],big5_mud_list)==-1?mud_list[muds[loop]]["MUDNAME"]:LANGUAGE_D->toGB(mud_list[muds[loop]]["MUDNAME"])),
                                mud_list[muds[loop]]["HOSTADDRESS"]?mud_list[muds[loop]]["HOSTADDRESS"]:"202.100.13.145",
                                mud_list[muds[loop]]["PORT"]);
               
                if(!undefinedp(mud_list[muds[loop]]["USERS"]))
                                output+=sprintf("  %-4s"	, chinese_number(atoi(mud_list[muds[loop]]["USERS"])) );
                else
                                output+=sprintf("  未知", mud_list[muds[loop]]["USERS"] );

                output +=NOR"\n";
                total ++;
        }
        //      Display dumped mudlist output through user's more pager
output+="────────────────────────────────────\n";
        output += sprintf("共有 %d 个 Mud 与"+MUD_NAME+"连线。\n",total==0?0:total-1);
        this_player()->start_more( output );

        return 1;
}

int help()
{
        write("\n指令格式：mudlist            列出连线中的"MUD_NAME"站点。\n"
                "          mudlist <MudName>  列出指定 Mud 的信息。\n"
                "          mudlist es         列出目前所有连线中使用东方故事 Mudlib 的 Mud。\n"
                "          mudlist all        列出目前所有连线中的 Mud。\n\n"
        );
        return 1;
}

