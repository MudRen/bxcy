// qianjinbao.c 钱进宝
// change By zhm@silversand_mud

#include <ansi.h>
inherit NPC;
inherit F_BANKER;
int pieban(object me);
int pieqian(object me);
int piedan(object me);
int pieshuang(object me);
int piesan(object me);
int do_yao();
int do_kai();
int yesorno();
string cstr(int i);

//全程变量
int sumi,summ;
int thecash;
int m1,m2,m3,i1,i2,i3,j1,j2,j3,k1,k2,k3;

void create()
{
        set_name("钱进宝", ({ "qian jinbao", "qian","jinbao" }));
        set("gender", "男性");
        set("long",
                "一个浑身滚圆的胖子，小眼睛里好象计量着什么，嘴角渗出一丝阴笑。\n"
        );
        set("age", 32);
        set("title",HIW"逢赌必胜"NOR);     
        set("nickname",CYN"赌千场"NOR);  
         set("combat_exp", 100000);
        set("immortal",1);

        set("inquiry", ([
                "赌圣"   : "他是我的师傅。\n",  
                "赌" : "要赌就赌，莫说废话。\n",
         ]) );  

        set("book_count",1);

        setup();

        carry_object("/clone/misc/cloth")->wear();
}

void init()
{
       if (base_name(environment())!=this_object()->query("startroom")) return;
        add_action("do_yao","yao");
        add_action("do_kai","kai");
        add_action("do_convert", "convert");
        add_action("do_convert", "huan");
}

int accept_object(object who, object ob)
{
        object obj;
        object me=this_player();

        if (who->query_temp("tmark/押")) {
                        message_vision(HIG"钱进宝诧异地看着$N说：你已经下过注了呀！\n"NOR,who);
                 return 0;   
                }
     if (query("book_count") ) {
        if (ob->query("money_id")) {
                        if (ob->value()<100) {
                        message_vision(HIR"钱进宝不屑一顾地看着$N，说道：要下注至少一两银子！\n"NOR,who);
                        return 0;
                }
                 if (ob->value()>100000) {
                        message_vision(HIR"钱进宝摇了摇头，对$N说道：这里不欢迎孤注一掷，最多下注10两黄金。\n"NOR,who);
                        return 0;
                }
                add("book_count",-1);
                thecash = ob->value();
               who->set_temp("tmark/押",1);
                sumi=summ=0;
                i1=i2=i3=m1=m2=m3=j1=j2=j3=k1=k1=k3=0;
                message_vision(HIY"钱进宝吆喝道：$N下注完成，发牌了。\n"NOR,who);
                i1 = 1+random(13413)%13;
                i2 = 1+random(23413)%13;
            if (random(10)==5)
                i1 = i2 = 13;
            if (random(10)==4)
        { i1=1; i2=random(4)+10; }
               message_vision("\n"+WHT"庄家的牌是:    ？   和   "+cstr(i1)+"\n"NOR,who);
                if (i1>10) j1=10;
                else j1=i1;
                if (i2>10) j2=10;
                else j2=i2;
                sumi = j1 + j2;

                m1 = 1+random(11213)%13;
                m2 = 1+random(23313)%13;
   message_vision(HIC"\n$N的牌是:    "+cstr(m1)+"   和   "+cstr(m2)+"\n"NOR,who);     
                if (m1>10) k1=10;
                else k1=m1;
                if (m2>10) k2=10;
                else k2=m2;
                summ = k1+k2;
                if ((summ == 21) || ((summ==11) && (m1==1 || m2==1)) ) {
                        message_vision(HIR"啊！BLACKJACK，$N真厉害，该赔$N三倍啊！\n"NOR,who);
                        remove_call_out("destroying");
                        call_out("destroying", 0, me, ob);
                        piesan(who);
                        set("book_count",1);
                }
                else {
message("vision",HIW"\n\n小心看清楚你的牌，请要牌(yao),否则请开牌(kai)。\n"NOR,who);
                } 

                remove_call_out("destroying");
                call_out("destroying", 0, me, ob);
                return 1;
        }
        } // if (query("book_count"))
        else {
message_vision("已经有人在与钱进宝对赌了，看来$N得等下波儿了。\n",who);
                return 0;
        }
}

int do_yao()
{
        object me=this_player();
        int m3;

        if (!me->query_temp("tmark/押")) {
message_vision(RED"钱进宝不耐烦地推了$N一把：去去去，注还没下呢，要什么牌啊！\n"NOR,me);
                return 1;
        }
        m3 = 1+random(6353)%13;
        message_vision(HIM"\n$N还要一张啊，好吧，给$N这张牌:   "+cstr(m3)+"\n\n"NOR,me);
        if (m3>10) k3=10;
        else k3=m3;
        summ = summ+k3;
        if(m1==1 || m2==1 || m3==1)
                if(summ<12)
                        summ=summ+10;

        if (summ>21) {
                if (random(10)>9){
       message_vision(HIG"钱进宝大叫：“$N的牌涨爆了,看看我的牌如何！”\n"NOR,me);       
message_vision(HIB"钱进宝一看手上的牌，非常无奈地道：唉，我的牌也涨爆了，庄家收$N30%的手续费！\n"NOR,me);
              pieban(me);
               }
           else{  
              message_vision(HIG"钱进宝笑嘻嘻地说：不好意思，$N的牌涨爆了，我又赢了。\n"NOR,me);
      }
      }
        else {
                if (summ==21) {
                        message_vision(HIR"钱进宝面如土色：又是２１点？$N真厉害，该赔$N双倍啊！\n"NOR,me);
                        pieshuang(me);  
      }
//    }
                else {
                        sumi = yesorno();
                        if(i1==1 || i2==1 || i3==1) {
                                if(sumi<12)
                                        sumi=sumi+10;
                                if(sumi>21)
                                        sumi=sumi-10;
                        }
        
                        if (sumi>21 || sumi<summ) {
                                if (sumi>21)
                                        message_vision(HIY"钱进宝丧气地说：我的牌"+cstr(i1)+cstr(i2)+cstr(i3)+"涨爆了，赔$N！\n"NOR,me);
                                else
                                        message_vision(HIY"钱进宝气得一把把牌扔在桌上：我是"+cstr(i1)+cstr(i2)+cstr(i3)+"，没$N点大。\n"NOR,me);
                                pieqian(me);
                        }
                        else {
                        if (sumi == summ) {
//message_vision(HIB"钱进宝非常无奈地道：唉，我是"+cstr(i1)+cstr(i2)+cstr(i3)+"，又是同点，没能赚$N的！\n"NOR,me);
message_vision(HIB"钱进宝阴阴地笑道：太好了，我是"+cstr(i1)+cstr(i2)+cstr(i3)+"又是同点，庄家收$N30%的手续费!\n"NOR,me);
                                pieban(me);
                       // piedan(me);
                    } 
                        else {
                                message_vision(HIG"钱进宝笑嘻嘻地说：我的牌是"+cstr(i1)+cstr(i2)+cstr(i3)+"\n"NOR,me);
                              message_vision(HIG"钱进宝满脸兴奋的表情：大家这么熟的朋友了,又赢$N的钱,真不好意思。\n"NOR,me);
                        }
                        } 
                }
        }

        me->set_temp("tmark/押",0);
        set("book_count",1);
        return 1;
}

int do_kai()
{
        object me = this_player();
        if (!me->query_temp("tmark/押")) {
message_vision(RED"钱进宝不耐烦地推了$N一把：去去去，注还没下呢，亮什么牌啊！\n"NOR,me);
                return 1;
        }
        message_vision(HIM"\n$N想了一会，把牌往桌上一扔：“好吧，我就开这牌了！”\n\n"NOR,me);  

        summ = summ+k3;
        if(m1==1 || m2==1 || m3==1)
                if(summ<12)
                        summ=summ+10;

        sumi = yesorno();
        if(i1==1 || i2==1 || i3==1) {
                if(sumi<12)
                        sumi=sumi+10;
                if(sumi>21)
                        sumi=sumi-10;
        }
        
        if (sumi>21 || sumi<summ) {
                if (sumi>21)
                        message_vision(HIY"钱进宝丧气地说：我的牌"+cstr(i1)+cstr(i2)+cstr(i3)+"涨爆了，赔$N！\n"NOR,me);
                else
                        message_vision(HIY"钱进宝气得一把把牌扔在桌上：我是"+cstr(i1)+cstr(i2)+cstr(i3)+"，没$N点大。\n"NOR,me);
                pieqian(me);
                }
        else {
                if (sumi == summ) {
               // message_vision(HIB"钱进宝非常无奈地道：唉，我是"+cstr(i1)+cstr(i2)+cstr(i3)+"，又是同点，没能赚$N的！\n"NOR,me);
               // piedan(me);
message_vision(HIB"钱进宝阴阴地笑道：太好了，我是"+cstr(i1)+cstr(i2)+cstr(i3)+"又是同点，庄家收$N30%的手续费!\n"NOR,me);
                           pieban(me);

                }
                else {
                        message_vision(HIG"钱进宝笑嘻嘻地说：我的牌是"+cstr(i1)+cstr(i2)+cstr(i3)+"\n"NOR,me);
                        message_vision(HIG"钱进宝满脸兴奋的表情：大家这么熟的朋友了,又赢$N的钱,真不好意思。\n"NOR,me);
                }
        } 

        me->set_temp("tmark/押",0);
        set("book_count",1);
        return 1;
}
int pay_player(object who,int amount)
{
    object ob;
    int total;
    if( amount < 1 ) amount = 1;
        if( amount/10000 ) {
        if (!ob=present("gold_money", who)){
                    ob = new(GOLD_OB);
            if (!ob->move(who)) ob->move(environment(who));
        }else total=ob->query_amount();
                ob->set_amount(amount/10000+total);
                amount %= 10000;
    }
    if( amount/100 ) {
        if (!ob=present("silver_money", who)){
                    ob = new(SILVER_OB);
            if (!ob->move(who)) ob->move(environment(who));
        }else total=ob->query_amount();
                ob->set_amount(amount/100+total);
        amount %= 100;
    }
    if( amount ) {
        if (!ob=present("coin_money", who)){
            ob = new(COIN_OB);
            if (!ob->move(who)) ob->move(environment(who));
        }else total=ob->query_amount();
                ob->set_amount(amount+total);
    }
    who->set_temp("tmark/押",0);
    return 1;
}


int piedan(object me)
{
        pay_player(me,thecash);
        return 1;
}

int pieban(object me)
{
       pay_player(me,thecash*7/10); 
        return 1;
}

int pieqian(object me)
{

        pay_player(me,thecash*2);
        return 1;
}

int pieshuang(object me)
{

        pay_player(me,thecash*3);
        return 1;
}

int piesan(object me)
{

        pay_player(me,thecash*4);
        return 1;
}


int yesorno()
{
        object me=this_player();

        if (i1==1 || i2==1)
                if(sumi<12) 
                        sumi=sumi+10;

        if (sumi>17) return sumi;
        else {
                if (sumi<14) {
                        i3 = 1+random(13);
                        if (i3>10) j3=10;
                        else j3=i3;
                        return sumi+j3;
                }
                else {
                        if(random(21)>10) {
                                i3 = 1+random(13);
                                if (i3>10) j3=10;
                                else j3=i3;
                                return sumi+j3;
                        }
                        else return sumi;
                }
        }
}

void destroying(object me, object obj)
{
        destruct(obj);
        return;
}

string cstr(int i)
{
        switch(i) {
                case 1:
                        return "Ａ";
                case 2:
                        return "２";
                case 3:
                        return "３";
                case 4: 
                        return "４";
                case 5:
                        return "５";
                case 6:
                        return "６";
                case 7:
                        return "７";
                case 8:
                        return "８";
                case 9:
                        return "９";
                case 10:
                        return "10";
                case 11:
                        return "Ｊ";
                case 12:
                        return "Ｑ";
                case 13:
                        return "Ｋ";
                default:
                        return "";
        }
}

