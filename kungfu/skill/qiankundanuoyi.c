// qiankundanuoyi.c Ç¬À¤´óÅ²ÒÆ

inherit SKILL;

string *parry_msg = ({
        "$NÒ»ÕÐ»÷ÔÚ$nÉíÉÏ£¬È´±»$n°µÔËÇ¬À¤´óÅ²ÒÆ£¬½«ÄÚÁ¦¾¡ÊýÒÆÈëµØÏÂ¡£\n",
        "$nÇáÇáÒ»´ø£¬$N·¢ÏÖ×Ô¼ºÕÐÊý»Ø»÷¹ýÀ´£¬ÏÅµÃÍùºóµ¹ÍË¼¸²½¡£\n",
        "$nÊÖ±Û»Ø×ª£¬ÔÚ$NÊÖÖâÏÂÇáÇáÒ»ÍÆ£¬$NÕÐÊýÂä¿Õ¡£\n",
        "$nÓÒÊÖÉì³ö£¬ÔÚ$NÊÖÍóÉÏÇáÇáÒ»À­£¬$NÊÕÊÆ²»×¡£¬Ö±ÍùÇ°ÆËÈ¥¡£\n",
        "$nÉíÐÎ²»¶¯£¬$NÒ»ÕÐ»÷ÏÂ£¬ÓÐÈçÊ¯³Á´óº££¬²»¾õ´ô×¡ÁË¡£\n",
        "$n×óÇ£ÓÒÒý£¬$NÈçÉí´¦äöÁ÷£¬Á¬Ðø×ªÁËºÃ¼¸¸öÈ¦¡£\n",
        "$nË«ÊÖ»ØÈ¦£¬$NÖ»¾õµÃÇ°ÃæºÃÏóÓÐÒ»¶ÂÇ½£¬ÔÙÒ²¹¥²»½øÈ¥¡£\n",
        "$nÇáÇáÒ»×ª£¬$NÒ»ÕÐ»÷ÔÚµØÉÏ£¬Ö»´òµÃ³¾ÍÁ·ÉÑï¡£\n",
});

string *dodge_msg = ({
        "$NÒ»ÕÐ»÷ÔÚ$nÉíÉÏ£¬È´±»$n°µÔËÇ¬À¤´óÅ²ÒÆ£¬½«ÄÚÁ¦¾¡ÊýÒÆÈëµØÏÂ¡£\n",
        "$nÇáÇáÒ»´ø£¬$N·¢ÏÖ×Ô¼ºÕÐÊý»Ø»÷¹ýÀ´£¬ÏÅµÃÍùºóµ¹ÍË¼¸²½¡£\n",
        "$nÊÖ±Û»Ø×ª£¬ÔÚ$NÊÖÖâÏÂÇáÇáÒ»ÍÆ£¬$NÕÐÊýÂä¿Õ¡£\n",
        "$nÓÒÊÖÉì³ö£¬ÔÚ$NÊÖÍóÉÏÇáÇáÒ»À­£¬$NÊÕÊÆ²»×¡£¬Ö±ÍùÇ°ÆËÈ¥¡£\n",
        "$nÉíÐÎ²»¶¯£¬$NÒ»ÕÐ»÷ÏÂ£¬ÓÐÈçÊ¯³Á´óº££¬²»¾õ´ô×¡ÁË¡£\n",
        "$n×óÇ£ÓÒÒý£¬$NÈçÉí´¦äöÁ÷£¬Á¬Ðø×ªÁËºÃ¼¸¸öÈ¦¡£\n",
        "$nË«ÊÖ»ØÈ¦£¬$NÖ»¾õµÃÇ°ÃæºÃÏóÓÐÒ»¶ÂÇ½£¬ÔÙÒ²¹¥²»½øÈ¥¡£\n",
        "$nÇáÇáÒ»×ª£¬$NÒ»ÕÐ»÷ÔÚµØÉÏ£¬Ö»´òµÃ³¾ÍÁ·ÉÑï¡£\n",
});

int valid_enable(string usage) 
{ 
    return (usage == "parry") || (usage == "dodge");
}

string query_parry_msg(string limb)
{
       return parry_msg[random(sizeof(parry_msg))];
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}
/*
int valid_learn(object me)
{
        int lvl = (int)me->query_skill("qiankundanuoyi", 1);

        if ( me->query("gender") == "ÎÞÐÔ" && lvl > 99)
                return notify_fail("ÄãÏÈÌì²»×ã£¬ÔÙÑ§ÏÂÈ¥ÄÑÃâ×ß»ðÈëÄ§¡£\n");

        if ((int)me->query_skill("force", 1) < 100)
                return notify_fail("¾ÍÕâÃ´µã»ù±¾ÄÚ¹¦»¹ÏëÑ§Ç¬À¤´óÅ²ÒÆ£¿\n");

        if ((int)me->query("max_neili", 1) < 1500)
                return notify_fail("¾ÍÕâÃ´µãÄÚÁ¦»¹ÏëÑ§Ç¬À¤´óÅ²ÒÆ£¿\n");

        if ((int)me->query_skill("force", 1) < lvl)
                return notify_fail("ÄãµÄ»ù±¾ÄÚ¹¦»ðºò»¹²»¹»£¬Ð¡ÐÄ×ß»ðÈëÄ§£¡\n");

        if ((int)(me->query("max_neili", 1)/15) < lvl)
                return notify_fail("ÄãµÄÄÚÁ¦»ðºò»¹²»¹»£¬Ð¡ÐÄ×ß»ðÈëÄ§£¡\n");

        return 1;
}
*/
int valid_learn(object me)
{
        return notify_fail("Ç¬À¤´óÅ²ÒÆÖ»ÄÜÍ¨¹ý¶Á [0;1m¡ [1mù [0mÇ¬À¤´óÅ²ÒÆÐÄ·¨ [0;1m¡ [1mù [0mÌá¸ß¡£\n");
}

int practice_skill(object me)
{
int lvl;
lvl=me->query_skill("qiankundanuoyi",1);
if(lvl<251)
        return notify_fail("Ç¬À¤´óÅ²ÒÆÖ»ÄÜÍ¨¹ý¶Á<<Ç¬À¤´óÅ²ÒÆ>>ÐÄ·¨Ìá¸ß¡£\n");
else return 1;
}

string perform_function_file(string func)
{
        return __DIR__"qiankundanuoyi/" + func;
}

