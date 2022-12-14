// rankd.c
// 1996-02-15 dts ranking related to "shen"

#pragma optimize
// #pragma save_binary

#include <ansi.h>

string query_rank(object ob)
{
        mapping fam;

        int shen;
        int budd;
        int tao;
        int exp;
        int age;
        int eatman;

        if (ob->is_ghost())
                return HIB "【 鬼  魂 】" NOR;

        shen = ob->query("shen");
        exp  = ob->query("exp");
        age  = ob->query("age");
        budd = ob->query_skill("buddhism", 1);
        tao  = ob->query_skill("taoism", 1);
        eatman = ob->query("combat/eatman", 1);

	if (ob->query("rank_info/rank"))
		return HIY "【" + ob->query("rank_info/rank") + "】" NOR;

        switch(ob->query("gender"))
        {
        case "女性":
                switch (wizhood(ob))
                {
                case "(admin)":
                        return HIW "【 女  神 】" NOR;
                case "(arch)":
                        return HIY "【 仙  子 】" NOR;
                case "(wizard)":
                        return HIG "【 巫  婆 】" NOR;
                case "(apprentice)":
                        return HIC "【 小巫女 】" NOR;
                case "(immortal)":
                        return HIC "【 小仙女 】" NOR;
                default:
                        if (shen < 0 && eatman >= 10)
                             return RED "【吃人狂魔】" NOR;
                        else
                        if (shen < 0 && eatman >= 3)
                             return RED "【食人女魔】" NOR;

                        switch(ob->query("class"))
                        {
                        case "bonze":
                             if (budd >= 150)
                                return HIY "【 神  尼 】" NOR;
                             if (budd >= 120)
                                return HIY "【 圣  尼 】" NOR;
                             if (budd >= 90)
                                return HIY "【 德  尼 】" NOR;
                             if (budd >= 60)
                                return HIC "【 贤  尼 】" NOR;
                             if (budd >= 30)
                                return HIG "【 师  太 】" NOR;
                             if (age <= 16)
                                return "【 小尼姑 】";
                             else
                                return "【 尼  姑 】";
                        case "taoist":
                             if (exp > 10000 || shen > 10000 || shen < -10000)
                                break;
                             if (age <= 16)
                                return CYN "【 小道姑 】" NOR;
                             else if (age <= 40)
                                return CYN "【 道  姑 】" NOR;
                             else
                                return CYN "【 老道姑 】" NOR;
                        case "bandit":
                             if (exp > 10000 || shen > 10000 || shen < -10000)
                                break;
                                return HIG "【 女飞贼 】" NOR;
                        case "dancer":
                             if (exp > 10000 || shen > 10000 || shen < -10000)
                                break;
                                return "【 舞  女 】";
                        case "scholar":
                             if (exp > 10000 || shen > 10000 || shen < -10000)
                                break;
                             if (age <= 16)
                                return CYN "【 女学童 】" NOR;
                             else if (age <= 20)
                                return HIM "【 才  女 】" NOR;
                             else
                                return HIC "【 女学士 】" NOR;
                        case "officer":
                             if (exp > 10000 || shen > 10000 || shen < -10000)
                                break;
                                return HIY "【 女  官 】" NOR;
                        case "fighter":
                             if (exp > 10000 || shen > 10000 || shen < -10000)
                                break;
                                return MAG "【 女武者 】" NOR;
                        case "swordsman":
                             if (exp > 10000 || shen > 10000 || shen < -10000)
                                break;
                                return WHT "【 女剑士 】" NOR;
                        case "alchemist":
                             if (exp > 10000 || shen > 10000 || shen < -10000)
                                break;
                                return BLU "【 女方士 】" NOR;
                        case "shaman":
                             if (exp > 10000 || shen > 10000 || shen < -10000)
                                break;
                                return HIB "【 女巫医 】" NOR;
                        case "beggar":
                             if (exp > 10000 || shen > 10000 || shen < -10000)
                                break;
                                return "【 女叫化 】";
                        case "prostitute":
                                return HIR "【青楼女子】" NOR;
                        }
                        if (shen >= 200000)
                                return HIC "【旷世女侠】" NOR;
                        if (shen >= 50000)
                                return HIW "【 女  侠 】" NOR;
                        if (shen >= 10000)
                                return HIM "【 女侠客 】" NOR;
                        if (shen >= 1000)
                                return HIY "【 小侠女 】" NOR;
                        if (shen <= -200000)
                                return HIR "【飞天魔女】" NOR;
                        if (shen <= -50000)
                                return HIC "【 女魔头 】" NOR;
                        if (shen <= -10000)
                                return HIY "【 妖  女 】" NOR;
                        if (shen <= -1000)
                                return HIG "【 小妖女 】" NOR;

                        if (age <= 20)
                            return "【 少  女 】";
                        else
                            return "【 民  妇 】";
                }
        default:
                switch (wizhood(ob))
                {
                case "(admin)":
                        return HIW "【 天  神 】" NOR;
                case "(arch)":
                        return HIY "【 大  神 】" NOR;
                case "(wizard)":
                        return HIG "【 巫  师 】" NOR;
                case "(apprentice)":
                        return HIC "【 小巫师 】" NOR;
                case "(immortal)":
                        return HIC "【 精  灵 】" NOR;
                default:
                        if (shen < 0 && eatman >= 10)
                             return HIR "【吃人狂魔】" NOR;
                        else
                        if (shen < 0 && eatman >= 3)
                             return HIR "【 食人魔 】" NOR;
                        switch(ob->query("class"))
                        {
                        case "bonze":
                                if (budd >= 250)
                                        return HIY "【大德圣僧】" NOR;
                                if (budd >= 150)
                                        return HIY "【 圣  僧 】" NOR;
                                else if (budd >= 120)
                                        return HIY "【 长  老 】" NOR;
                                else if (budd >= 90)
                                        return HIY "【 罗  汉 】" NOR;
                                else if (budd >= 60)
                                        return HIY "【 尊  者 】" NOR;
                                else if (budd >= 40)
                                        return HIY "【 禅  师 】" NOR;
                                else if (budd >= 30)
                                        return HIY "【 比  丘 】" NOR;
                                else if (age <= 16)
                                        return HIY "【 小和尚 】" NOR;
                                else
                                        return "【 僧  人 】";
                        case "taoist":
                                if (tao > 200)
                                        return HIY "【 真  人 】" NOR;
                                if (shen < -200000)
                                        return HIY "【 魔  道 】" NOR;
                                if (shen < -10000)
                                        return HIY "【 妖  道 】" NOR;
                                if (shen < -100)
                                        return HIY "【 邪  道 】" NOR;
                                if (age <= 16)
                                        return CYN "【 小道士 】" NOR;
                                if (age <= 30)
                                        return CYN "【 道  士 】" NOR;

                                return CYN "【 道  长 】" NOR;
                        case "bandit":
                                return HIG "【 盗  贼 】" NOR;
                        case "scholar":
                                if (shen > 10000 || shen < -10000)
                                        break;
                                if (age <= 16)
                                        return CYN "【 学  童 】" NOR;
                                else if (age <= 45)
                                        return HIY "【 书  生 】" NOR;
                                else
                                        return YEL "【 老秀才 】" NOR;
                        case "officer":
                                if (shen > 10000 || shen < -10000)
                                        break;
                                return YEL "【 官  差 】" NOR;
                        case "fighter":
                                if (shen > 10000 || shen < -10000)
                                        break;
                                return MAG "【 武  者 】" NOR;
                        case "swordsman":
                                if (shen > 10000 || shen < -10000)
                                        break;
                                return WHT "【 剑  士 】" NOR;
                        case "alchemist":
                                if (shen > 10000 || shen < -10000)
                                        break;
                                return BLU "【 方  士 】" NOR;
                        case "shaman":
                                if (shen > 10000 || shen < -10000)
                                        break;
                                return HIB "【 巫  医 】" NOR;
                        case "beggar":
                                if (shen > 10000 || shen < -10000)
                                        break;
                                if (age <= 16)
                                    return WHT "【 小叫化 】" NOR;
                                else
                                    return WHT "【 叫化子 】" NOR;
                        case "royal":
                                if (shen > 200000 || shen < -200000)
                                        break;
                                return HIY "【 皇  族 】" NOR;
                        case "prostitute":
                                return HIB "【 龟  公 】" NOR;
                        }
                        if (shen >= 200000)
                                return HIC "【旷世大侠】" NOR;
                        if (shen >= 50000)
                                return HIW "【 大  侠 】" NOR;
                        if (shen >= 10000)
                                return HIM "【 侠  客 】" NOR;
                        if (shen >= 1000)
                                return HIY "【 小  侠 】" NOR;
                        if (shen <= -200000)
                                return HIR "【 魔  王 】" NOR;
                        if (shen <= -50000)
                                return HIC "【 大魔头 】" NOR;
                        if (shen <= -10000)
                                return HIY "【 魔  头 】" NOR;
                        if (shen <= -1000)
                                return HIG "【 小  魔 】" NOR;

                        if (age <= 20)
                            return "【 少  年 】";
                        else
                            return "【 平  民 】";
                }
        }
}

string query_respect(object ob)
{
        int age;
        string str;

        if (stringp(str = ob->query("rank_info/respect")))
                return str;

        age = ob->query("age");
        switch (ob->query("gender"))
        {
        case "女性":
                switch(ob->query("class"))
                {
                case "bonze":
                        if (age < 18) return "小师太";
                        else return "师太";
                        break;
                case "taoist":
                        if (age < 18) return "小仙姑";
                        else return "仙姑";
                        break;
                default:
                        if (age < 18) return "小姑娘";
                        else if (age < 30) return "姑娘";
                        else if (age < 40) return "大婶";
                        else return "婆婆";
                        break;
                }
        case "男性":
        default:
                switch(ob->query("class"))
                {
                case "bonze":
                        if (age < 18) return "小师父";
                        else return "大师";
                        break;
                case "taoist":
                        if (age < 18) return "道兄";
                        else return "道长";
                        break;
                case "scholar":
                        if (age < 18) return "小相公";
                        else if (age < 50) return "相公";
                        else return "老先生";
                        break;
                case "fighter":
                case "swordsman":
                        if (age < 18) return "小老弟";
                        else if (age < 50) return "壮士";
                        else return "老前辈";
                        break;
                default:
                        if (age < 20) return "小兄弟";
                        else if (age < 50) return "壮士";
                        else return "老爷子";
                        break;
                }
        }
}

string query_rude(object ob)
{
        int age;
        string str;

        if (stringp(str = ob->query("rank_info/rude")))
                return str;

        age = ob->query("age");
        switch (ob->query("gender"))
        {
        case "女性":
                switch(ob->query("class"))
                {
                case "bonze":
                        if( age < 18 ) return "小贼尼";
                        if( age < 30 ) return "贼尼";
                        else return "老贼尼";
                        break;
                case "taoist":
                        if( age < 18 ) return "小妖女";
                        if( age < 30 ) return "妖女";
                        else return "老妖婆";
                        break;
                default:
                        if( age < 18 ) return "小娘皮";
                        if( age < 25 ) return "小贱人";
                        if( age < 40 ) return "贼婆娘";
                        else return "死老太婆";
                        break;
                }
        case "男性":
        default:
                switch(ob->query("class"))
                {
                case "bonze":
                        if( age < 18 ) return "小贼秃";
                        if( age < 50 ) return "死秃驴";
                        else return "老秃驴";
                        break;
                case "taoist":
                        if( age < 18 ) return "小杂毛";
                        if( age < 30 ) return "死牛鼻子";
                        else return "老杂毛";
                        break;
                case "scholar":
                        if( age < 18 ) return "小书呆子";
                        else if( age < 50 ) return "臭书呆子";
                        else return "老童生";
                        break;
                default:
                        if( age < 20 ) return "小王八蛋";
                        if( age < 30 ) return "直娘贼";
                        if( age < 50 ) return "臭贼";
                        if( age < 80 ) return "老匹夫";
                        else return "老不死";
                        break;
                }
        }
}

string query_self(object ob)
{
        int age;
        string str;

        if (stringp(str = ob->query("rank_info/self")))
                return str;

        age = ob->query("age");
        switch (ob->query("gender"))
        {
        case "女性":
                switch(ob->query("class"))
                {
                case "bonze":
                        if( age < 50 ) return "贫尼";
                        else return "老尼";
                        break;
                case "taoist":
                        return "贫道";
                        break;
                default:
                        if( age < 20 ) return "小女子";
                        if( age > 50 ) return "老身";
                        else return "妾身";
                        break;
                }
        case "男性":
        default:
                switch(ob->query("class"))
                {
                case "bonze":
                        if( age < 18 ) return "小衲";
                        if( age < 40 ) return "贫僧";
                        else return "老衲";
                        break;
                case "taoist":
                        if( age < 18 ) return "小道";
                        if( age < 30 ) return "贫道";
                        else return "老道";
                        break;
                case "scholar":
                        if( age < 30 ) return "晚生";
                        else return "不才";
                        break;
                default:
                        if( age < 50 ) return "在下";
                        else return "老头子";
                        break;
                }
        }
}

string query_self_rude(object ob)
{
        int age;
        string str;

        if (stringp(str = ob->query("rank_info/self_rude")))
                return str;

        age = ob->query("age");
        switch(ob->query("gender"))
        {
        case "女性":
                switch(ob->query("class"))
                {
                case "bonze":
                        if( age < 50 ) return "贫尼";
                        else return "老尼";
                        break;
                case "taoist":
                        return "本仙姑";
                        break;
                default:
                        if( age < 20 ) return "本姑娘";
                        if( age < 30 ) return "本姑奶奶";
                        else return "老娘";
                        break;
                }
        case "男性":
        default:
                switch(ob->query("class"))
                {
                case "bonze":
                        if( age < 50 ) return "大和尚我";
                        else return "老和尚我";
                        break;
                case "taoist":
                        if( age < 30 ) return "本山人";
                        return "老道我";
                        break;
                case "scholar":
                        if( age < 50 ) return "本相公";
                        else return "老夫子我";
                        break;
                default:
                        if( age < 20 ) return "本少爷我";
                        if( age < 40 ) return "大爷我";
                        else return "老子";
                        break;
                }
        }
}

varargs string query_close(mixed ob, int a1, int a2)
{
        if (! a1 && this_player())
                a1 = this_player()->query("age");

        if (! a2 && objectp(ob))
                a2 = ob->query("age");

        switch (objectp(ob) ? ob->query("gender") : ob)
        {
        case "女性":
                if (a1 >= a2)
                        return "妹妹";
                else
                        return "姐姐";
                break;

        default:
                if (a1 >= a2)
                        return "弟弟";
                else
                        return "哥哥";
        }
}

varargs string query_self_close(mixed ob, mixed me, int a1, int a2)
{
        if (! a1 && this_player())
                a1 = this_player()->query("age");

        if (! a2 && objectp(ob))
                a2 = ob->query("age");

        switch (objectp(me) ? me->query("gender") :
                this_player() ? this_player()->query("gender") : me)
        {
        case "女性" :
                if (a1 >= a2)
                        return "姐姐我";
                else
                        return "小妹我";
                break;

        default :
                if (a1 >= a2)
                        return "愚兄我";
                else
                        return "小弟我";
        }
}

varargs string new_short( object ob ,int withshort)
{
        mixed tmp;
        string icon="", str;
        if(!objectp(ob))
        {
                CHANNEL_D->do_channel(this_player(),"chat","object参数错误！");
                return "";
        }
        if(!ob->query_temp("apply/id")||!ob->query_temp("apply/name")||!ob->query_temp("apply/short"))
                str = ob->query("name") + "(" +ob->query("id") + ")" +(!withshort?"":ob->short());
        else
                str = ob->query_temp("apply/name")[0] + "(" +ob->query_temp("apply/id")[0] + ")" +(!withshort?"":ob->query_temp("apply/short")[0]);
        if( (tmp = ob->query("icon")))
        {
                if( intp(tmp) )
                        icon = sprintf("%d",tmp);
                else if( stringp(tmp) )
                        icon = tmp;
                else
                        icon = "00901";
        }
        else
        {
                if(userp(ob)) icon=( ob->query("gender") == "男性" )?"1174":"1173";
                else if(living(ob)) icon = "00901";
                else icon = "00961";
        }
        while( sizeof(icon)<5 )
                icon = "0" + icon;

        return str + icon;
}
