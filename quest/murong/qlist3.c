#include <ansi.h>
inherit SKILL;

mapping *quest = ({
        ([      "quest":               "���ܹ�",
                "quest_type":           "Ѱ",
                "time":                 600,
                "score" :               12
        ]),
        ([      "quest":                "��ľ��",
                "quest_type":           "Ѱ",
                "time":                 500,
                "score" :               13
        ]),
         ([      "quest":               "�ۺ����",
                "quest_type":           "Ѱ",
                "time":                 600,
                "score" :               16
        ]),
        ([      "quest":                "������",
                "quest_type":           "Ѱ",
                "time":                 200,
                "score" :               9
        ]),
 	
        ([      "quest":               "ά����峤��",
                "quest_type":           "Ѱ",
                "time":                 600,
                "score" :               16
        ]),
        ([      "quest":                "������",
                "quest_type":           "Ѱ",
                "time":                 200,
                "score" :               13
        ])
 	
        ([      "quest":                "ʴ����",
                "quest_type":           "Ѱ",
                "time":                 200,
                "score" :               13
        ]),
        ([      "quest":                "���",
                "quest_type":           "Ѱ",
                "time":                 200,
                "score" :               13
        ]),       
        ([      "quest":                "�ߵ���",
                "quest_type":           "Ѱ",
                "time":                 200,
                "score" :               13
        ]),                      	
      ([      "quest":                "������",
                "quest_type":           "Ѱ",
                "time":                 350,
                "score" :               18
        ]),
        ([      "quest":                "������",
                "quest_type":           "Ѱ",
                "time":                 450,
                "score" :               9
        ]),       
       ([      "quest":                "�ۻ�",
                "quest_type":           "Ѱ",
                "time":                 450,
                "score" :               19
        ]),  
      ([      "quest":                "������",
                "quest_type":           "Ѱ",
                "time":                 600,
                "score" :               11
        ]),
        ([      "quest":               "����",
                "quest_type":           "Ѱ",
                "time":                 500,
                "score" :               12
        ]),
        ([       "quest":               "ʯ��",
                "quest_type":           "Ѱ",
                "time":                 600,
                "score" :               15
        ]),
        ([       "quest":               "����",
                "quest_type":           "Ѱ",
                "time":                 500,
                "score" :               8
        ]),
        ([       "quest":               "ҩ��",
                "quest_type":           "Ѱ",
                "time":                 500,
                "score" :               10
        ]),
       ([       "quest":               "����",
               "quest_type":           "Ѱ",
                "time":                 200,
                "score" :               16
        ]),
 
});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}

