// summon command..
inherit F_CLEAN_UP;

mapping places=([
"gc" : "/d/city/guangchang.c",	
"bt" : "/d/baituo/dating.c",
"hm" : "/d/heimuya/road1.c",
"bj" : "/d/city2/wenmiao.c",
"tl" : "/d/tianlongsi/damen.c",
"yz" : "/d/city/kedian.c",
"lj" : "/d/lingjiu/damen.c",
"sl" : "/d/shaolin/guangchang1.c",
"wd" : "/d/wudang/sanqingdian.c",
"xy" : "/d/xiaoyao/qingcaop.c",
"xx" : "/d/xingxiu/xxh2.c",
"hhh" : "/d/honghua/damen.c",	
"hs" : "/d/huashan/square.c",
"new" : "/d/new/lgting.c",
"ssl" : "/d/shashou/enterance.c",	
"lx" : "/d/lingxiao/shanya.c",	
"xs" : "/d/xueshan/dadian.c",
"kl" : "/d/gaochang/room63.c",
"ny" : "/d/nanyang/nanyang.c",
"tm" : "/d/tangmen/damen.c",	
"tz" : "/d/tiezhang/shanmen.c",	
"qc" : "/d/qingcheng/jianfugong.c",	
"qz" : "/d/quanzhou/zhongxin.c",
"cd" : "/d/city3/guangchang.c",
"hh" : "/d/huanhua/podi.c",	
"ca" : "/d/changan/ca.c",
"dl" : "/d/dali/guangchang.c",
"wu": "/d/wudujiao/damen.c",
"em" : "/d/emei/guangchang.c",
"mj" : "/d/mingjiao/guangchang1.c",
"gm" : "/d/gumu/rukou.c",
"hsc": "/d/village/sexit.c",
"qzj": "/d/quanzhen/guangchang.c",
"ss" : "/d/songshan/chanyuan.c",
"ts" : "/d/taishan/daizong.c",
"th" : "/d/taohua/haitan.c",
"mz" : "/d/meizhuang/gate.c", 	
"jq" : "/d/jqg/wx.c",
"sc" : "/d/xiangyang/guangchang.c",	   	
]);

int main(object me,string arg)
{
        object room,ob,*obj;
    string msg;
        int i;

   if( !arg ) return notify_fail("��Ҫȥ���\n");
//     if (!stringp(places[arg]))  return notify_fail("��Ҫȥ���\n");	
if (!stringp(places[arg]) && arg != "home")  return notify_fail("��Ҫȥ���\n");
if (me->is_busy())	
return notify_fail("����һ��������û�����,�޷���Խʱ��֮�ţ�\n");	
  if (me->is_fighting())
         return notify_fail("ս�����޷���Խʱ��֮�ţ�\n");
if (file_name(environment(me))=="/d/city/jianyu")
return notify_fail("�������޷���Խʱ��֮�ţ�\n");
if(me->is_ghost())
return notify_fail("��굽���ҷ�,�������˵ģ�\n");	
if( file_size("d/" + "party/" + me->query("guild/id") + "/dating.c") <= 0 && arg == "home")                      	
return notify_fail("�㻹û�м����κΰ��ɡ�\n");		
           	
  if (present("biao yin",me)) return notify_fail("�����ϴ����������޷���Խʱ��֮�ţ�\n");

   
  obj=deep_inventory(me);
     for (i=0;i<sizeof(obj);i++)
           if (obj[i]->id("illicit salt"))
         return notify_fail("�����ϴ���˽�Σ��޷���Խʱ��֮�ţ�\n");
  
  ob=first_inventory(me);
    while(ob){
        if (ob->is_character() && !ob->is_corpse() )
            return notify_fail(ob->name()+"���ܺ���һ��Խʱ��֮�ţ�\n");
        ob=next_inventory(ob);
    }

    message_vision(MAG+"ֻ��һ��������ᣬ$N����Ӱ�Ѿ������ˡ�\n"+NOR, me);
if(arg=="home")
me->move("d/" + "party/" + me->query("guild/id") + "/dating.c"); 	
else {
if (!room=find_object(places[arg]) )   	
        room=load_object(places[arg]);
    me->move(room);
} 
    message_vision(MAG+"$N����ӰͻȻ������һ������֮�С�\n"+NOR, me);
    me->receive_damage("jing", 10);
    return 1;
}
int help (object me)
{
        write(@HELP
ָ���ʽ: fly <�ص�>

���ָ��������ֱ�ӵ���һЩ���õĵط���
 yz : ����         hsc : ��ɽ��     dl : ����
 bj : ����         hm  : ��ľ��     ca : ����
 lj : ���չ�       sl  : ������     wd : �䵱ɽ
 xy : ��ң��       xx  : ���޺�     xs : ѩɽ��
 hs : ��ɽ         ny  : ����       qz : Ȫ��  
 kl : ����         wu  : �嶾��     cd : �ɶ�     
 tl : ������       bt  : ����ɽ     em : ����  
new : ������       hh  : 佻�����   tz : ���ư�	
 mj : ����         gm  : ��Ĺ       th : �һ���                                     
ss  : ��ɽ         jq  : �����     ts : ̩ɽ	
ssl : ɱ��¥       lx  : ������     qc : �����         	
hhh : �컨��       tm  : ����       mz : ÷ׯ      	
qzj : ȫ���       home: ������   gc : ���ݹ㳡
HELP
        );
        return 1;
}
