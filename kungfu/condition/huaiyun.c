// huaiyun.c
// 采自前任某巫师的测试程序，不过很多错误，程序不可执行
// 现已完全修改成功 
// 怀孕配合makelove.c
// 设置玩家baby属性,父母以属性寻找baby
// modify By snow@jhfyii 2001

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

void shengle(object me);
int birth1(object me);
void birth2(object me);

int update_condition(object me, int duration)
{
        if ( duration == 12 ){
                tell_object(me, HIY "你觉得周围的人好象都在偷偷看你，心里好不自在！\n" NOR );
                message("vision", me->name() + HIY "羞涩的低着头，摆弄着自己的衣角。\n" NOR,
                environment(me), me);
        }
        else if (duration == 10 ){
                        tell_object(me, HIY "你觉得周围的人都好奇怪，对你指指点点，真是讨厌！\n" NOR );
                        message("vision", me->name() + HIY "瞪着你，好象你欠了她什么似的……\n" NOR,
                        environment(me), me);
        }
        else if (duration == 8 ){
                        tell_object(me, HIY "你觉得周围的人都在笑嘻嘻的看着你，可能他们已经看出来了你……。\n" NOR );
                        message("vision", me->name() + HIY "用一种异常慈祥的目光，反复打量着自己的肚子。\n" NOR,
                        environment(me), me);
        }
        else if (duration == 6 ){
                        tell_object(me, HIY "你觉得周围的人与世界都是那麽的美好，心情无比的舒畅！\n" NOR );
                        message("vision", me->name() + HIY "一身充满了安详的气息，那积聚着母爱的目光不时扫视着周围！\n" NOR,
                        environment(me), me);
        }
        else if (duration == 3 ){
                        tell_object(me, HIY "你觉得周围的人都用着极其关切的目光注视着你，难道是……快了？\n" NOR );
                        message("vision", me->name() + HIY "已经行动十分的迟缓了，不时的停下来喘气。\n" NOR,
                        environment(me), me);
        }

        else if (duration == 1 ){
                        tell_object(me, HIY "周围的人都惊讶的合不上了嘴巴，一定是见到了什么奇怪事情！\n
                        看来你是马上就要生了，请赶紧和孩子的父亲去扬州药铺的二楼产房，否则会有生命危险的！" NOR );
                        message("vision", me->name() + HIY "捂着大大的肚子，蹲在了地上，脸上一副极其痛苦的神情！\n" NOR,
                        environment(me), me);
//                        me->clear_condition("huaiyun");
                         call_out("shengle",3,me);
                     }
        me->apply_condition("huaiyun", duration - 1);
        return 1;
}

void shengle(object me)
{
        object obj = find_player(me->query("fuqi/father"));
        if((int)(me->query("age")) < 18 )
        {
                message_vision(HIY "\n$N似乎觉得腹中一阵巨痛，大叫一声，由于$N年龄太小，不适合生育，\n所以$N的孩子流产了，好可怜啊！\n"NOR, me);
                me->set("qi",1);
                me->set("jing",1);
                me->set("neili", me->query("neili")/2);
                me->unconcious();
        }

        else if( base_name(environment(this_player())) != "/d/city/chanfang" )
        {
                message_vision(HIY "\n$N似乎觉得腹中一阵巨痛，大叫一声，由于这里的环境实在是太恶劣了，\n所以$N的孩子流产了，好可怜啊！\n"NOR, me);
                me->set("qi",1);
                me->set("jing",1);
                me->set("neili", me->query("neili")/2);
//              me->clear_condition("huaiyun");
                me->unconcious();
         }
//         else if (!obj || !userp(obj) || !find_player(obj->query("id")))
        else if( base_name(environment(obj)) != "/d/city/chanfang" )
         {
                message_vision(HIY "\n$N似乎觉得腹中一阵巨痛，大叫一声，由于关键时刻你的男人没有守侯在身边，\n所以$N的孩子流产了，好可怜啊！\n"NOR, me);
                me->set("qi",1);
                me->set("jing",1);
                me->set("neili", me->query("neili")/2);
                me->unconcious();
         }

         else if (userp(present(obj, environment(me)))&& base_name(environment(this_player())) == "/d/city/chanfang" )
         {
                me->set_temp("is_bearing",1);
                me->start(1);
                obj->start(1);
                message_vision(HIY "\n$N忽觉腹中一阵颤动，赶紧拉住$n的手，柔声说道：要生了! \n" NOR, me,obj);
                call_out("birth1",15,me,obj);
         }
         me->clear_condition("huaiyun");
         return ;
}
int birth1(object me)
{        object obj = find_player(me->query("fuqi/father"));
         message_vision(HIY "\n$N已是大汗淋漓，一直都在呼天抢地，双手紧紧扣住$n的手不放。\n"+
                 "\n婴儿已经探出了头．．．\n"NOR,me,obj);
         call_out("birth2",15,me,obj);
         return 1;
}

void birth2(object me)
{
        object obj = find_player(me->query("fuqi/father"));
        object baby;
        int number;
        message_vision(HIY "\n「哇」．．．，婴儿出世了！\n"+
                "\n$N面色苍白，斜倚在床头，看看孩子满意地露出一丝微笑。\n"NOR, me);
        me->set("long", HIY "\n"+ me->query("name") +""NOR"看起来已经是一个成熟的少妇了哦。\n"NOR);
        me->start_busy(1);
        obj->start_busy(1);
        me->set("neili",0);
        me->set("qi",0);
        me->set("jing",0);
        baby = new("/d/city/npc/baby");
        if (random(2)>1)
        {
                baby->set("gender","男性");
                baby->set_name("小"+obj->query("name"),({"xiao "+obj->query("id"),"baby"}));
        baby->set("long", baby->query("long")+"这是"+obj->query("name")+"和"+me->query("name")+"的孩子。长的好象"+obj->query("name")+"啊！\n");
        message("shout", HIR "【家有喜事】："HIM"恭喜 "HIY""+ me->query("name") +"(" + me->query("id") +")"HIM"给"HIY""+ obj->query("name") +"(" + obj->query("id") +")"HIM"添了一个"HIW"大胖小子。\n" NOR,users());
        }
        else
        {
                baby->set("gender","女性");
                baby->set_name("小"+me->query("name"),({"xiao "+me->query("id"),"baby"}));
        baby->set("long", baby->query("long")+"这是"+obj->query("name")+"和"+me->query("name")+"的孩子。长的好象"+me->query("name")+"啊！\n");
        message("shout", HIR "【家有喜事】："HIM"恭喜 "HIY""+ me->query("name") +"(" + me->query("id") +")"HIM"给"HIY""+ obj->query("name") +"(" + obj->query("id") +")"HIM"添了一个"HIW"千金小宝贝。\n" NOR,users());
        }
        me->add("child",1);
        obj->add("child",1);
        baby->set("per",(random(38)));
        baby->set("parents",({me->query("id"),obj->query("id")}));
        number = me->query("child");
        me->set("child_"+number+"/per",baby->query("per"));
        me->set("child_"+number+"/gender",baby->query("gender"));
        me->set("child_"+number+"/long",baby->query("long"));
        me->set("child_"+number+"/name",baby->query("name"));
        me->set("child_"+number+"/id",({baby->query("id"),"baby"}));
        me->set("child_"+number+"/parents",baby->query("parents"));
        number = obj->query("child");
        obj->set("child_"+number+"/per",baby->query("per"));
        obj->set("child_"+number+"/gender",baby->query("gender"));
        obj->set("child_"+number+"/long",baby->query("long"));
        obj->set("child_"+number+"/name",baby->query("name"));
        obj->set("child_"+number+"/id",({baby->query("id"),"baby"}));
        obj->set("child_"+number+"/parents",baby->query("parents"));
        me->delete_temp("is_bearing");
        me->save();
        obj->save();
//this needs to be put at the last since
//can only move the baby after it's parameters are set.
        if(!baby->move(environment(me)))
        baby->move(environment(environment(me)));
}


