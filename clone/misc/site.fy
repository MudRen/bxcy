// transite.c   
// modified by wind

inherit ITEM;

mapping where_map=([
"gc":"/d/city/guangchang",
"sl":"/d/shaolin/guangchang1",
"bt":"/d/baituo/dating",
"tam":"/d/city2/tian_anm",
"hmy":"/d/heimuya/xuanya",
"hs":"/d/huashan/zhenyue",
"wd":"/d/wudang/guangchang",
"ts":"/d/taishan/nantian",
"xy":"/d/xiaoyao/qingcaop",
"xx":"/d/xingxiu/xxh1",
"xk":"/d/xiakedao/dating",
"xs":"/d/xueshan/dadian",
"sld":"/d/shenlong/dating",
"qz":"/d/quanzhou/zhongxin",
"lj":"/d/lingjiu/dating",
"tl": "/d/tianlongsi/damen", 
"td":"/d/city2/dating",
"em" : "/d/emei/zengdian",
"yz" : "/d/yanziwu/yimen",
"th" : "/d/taohua/mudi",
"gm" : "/d/gumu/mumen",
"quanz" : "/d/quanzhen/ximen",
"cd" : "/d/city3/chunxilu1",
"wjg" : "/d/wanjiegu/entrance",
]);

void init(){
add_action("do_trans","trans");
}

void create()
{
set_name("ħ��������",({"trans site","site"}));
set_weight(100); 
set_max_encumbrance(8000);
set("value", 100000);
set("used_count", 0);
set("can_use_count",50+random(10));
set("no_drop", "�������������뿪�㡣\n");

if( clonep() )   set_default_object(__FILE__);
else {     set("long", "һ��ħ����������������ħ���������ܵ���(trans)�ĵط����¡�\n
\t����㳡(gc)    ������(sl)    ����ɽ(bt)    �찲��(tam) \n
\t��ľ��(hmy)     ��ɽ(hs)      �䵱ɽ(wd)    ̩ɽ(ts)    \n
\t��ң��(xy)      ���޺�(xx)    ѩɽ��(xs)    ������(sld) \n
\tȪ��(qz)        ���չ�(lj)    ������(tl)    ��ػ�(td)  \n
\t���͵�(xk)      ������(em)    ������(yz)    �һ���(th)  \n
\t��Ĺ��(gm)      ȫ���(quanz)  �ɶ� (cd)    ��ٹ�(wjg)  \n");
set("unit","��");
}
}

int do_trans(string arg)
{
int result;
        object me,obj;string msg,str;str=where_map[arg];
        if( !arg||!stringp(str)) return notify_fail("��Ҫȥ���\n");
        me=this_player();
        if (! environment(me)->query("outdoors"))
         return notify_fail("���ⷿ�����޷�ʹ��ħ�����͡�\n");
        if (me->is_fighting())
	return notify_fail("ս�����޷�ʹ��ħ�����ͣ�");
	if (me->is_busy())
		return notify_fail("����æ���أ�\n");
	if( me->query("sleeped"))
		return notify_fail("����˯���зɰ��ɣ�\n");

        if (this_object()->query("used_count")>this_object()->query("can_use_count"))
        {
        this_object()->set("value", 20000);
        this_object()->delete("no_put");
        this_object()->delete("no_drop");
        this_object()->set_name("���ϵ�ħ��������",({"trans site","site"}));
	return notify_fail("����ħ���������õ�̫�ã��Ѿ������ˣ�\n");
        }

	str+=".c";
          if((result=file_size(str))<0) 
          return notify_fail("û������ط���\n");
	if( stringp(msg = me->query("env/msg_mout")) )      
        {if (msg!="") message_vision(msg+"\n", me);} 
	 else message_vision("ֻ��һ��������ᣬ$N����Ӱ�Ѿ������ˡ�\n", me);
	me->move(str);
	if( stringp(msg = me->query("env/msg_min")) )
	       {if (msg!="") message_vision(msg+"\n", me);}
        else  message_vision("$N����ӰͻȻ������һ������֮�С�\n", me);        
        this_object()->add("used_count",1);
	return 1;
}
