#include <ansi.h>
inherit SKILL;

mapping *quest = ({
        ([      "quest":               "π˛√‹πœ",
                "quest_type":           "—∞",
                "time":                 600,
                "score" :               12
        ]),
        ([      "quest":                "Ã“ƒæΩ£",
                "quest_type":           "—∞",
                "time":                 500,
                "score" :               13
        ]),
         ([      "quest":               "∑€∫Ï≥Ò…¿",
                "quest_type":           "—∞",
                "time":                 600,
                "score" :               16
        ]),
        ([      "quest":                "ΩœÓ¡¥",
                "quest_type":           "—∞",
                "time":                 200,
                "score" :               9
        ]),
 	
        ([      "quest":               "Œ¨Œ·∂˚◊Â≥§≈€",
                "quest_type":           "—∞",
                "time":                 600,
                "score" :               16
        ]),
        ([      "quest":                "π‚√˜µ∂",
                "quest_type":           "—∞",
                "time":                 200,
                "score" :               13
        ])
 	
        ([      "quest":                " ¥ªÍ–«",
                "quest_type":           "—∞",
                "time":                 200,
                "score" :               13
        ]),
        ([      "quest":                "”Òµ—",
                "quest_type":           "—∞",
                "time":                 200,
                "score" :               13
        ]),       
        ([      "quest":                "…ﬂµ®∏‡",
                "quest_type":           "—∞",
                "time":                 200,
                "score" :               13
        ]),                      	
      ([      "quest":                "“¡¿Á¬Ì",
                "quest_type":           "—∞",
                "time":                 350,
                "score" :               18
        ]),
        ([      "quest":                "”Ò÷Ò’»",
                "quest_type":           "—∞",
                "time":                 450,
                "score" :               9
        ]),       
       ([      "quest":                "–€ª∆",
                "quest_type":           "—∞",
                "time":                 450,
                "score" :               19
        ]),  
      ([      "quest":                "”Œ¡˙Ω£",
                "quest_type":           "—∞",
                "time":                 600,
                "score" :               11
        ]),
        ([      "quest":               "∆Â∆◊",
                "quest_type":           "—∞",
                "time":                 500,
                "score" :               12
        ]),
        ([       "quest":               " Ø∞Â",
                "quest_type":           "—∞",
                "time":                 600,
                "score" :               15
        ]),
        ([       "quest":               "ª’€",
                "quest_type":           "—∞",
                "time":                 500,
                "score" :               8
        ]),
        ([       "quest":               "“©≥˙",
                "quest_type":           "—∞",
                "time":                 500,
                "score" :               10
        ]),
       ([       "quest":               "∑˜≥æ",
               "quest_type":           "—∞",
                "time":                 200,
                "score" :               16
        ]),
 
});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}

